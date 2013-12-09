/******************************************************************************
**
**  qpgui - a library of classes and templates originally devised to
**          accomodate a dialog-based suite of math exercises.
**
**  Tony Camuso
**  December, 2011
**
**  Version 0.1
**
**    mathtest is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**  GNU General Public License http://www.gnu.org/licenses/gpl.html
**
**  Copyright 2011 by Tony Camuso.
**
******************************************************************************/

#include <QString>
#include <QTextStream>
#include <QStringBuilder>

#include "msg.h"
#include "qpfile.h"

using namespace qpfile;

QpFile::QpFile() : QFile()
{
    m_userMsg = false;
    m_pMsg = new Msg;
    init();
}

QpFile::QpFile(const QString& name) : QFile(name)
{
    m_name = name;
    m_userMsg = false;
    m_pMsg = new Msg;
    init();
}

QpFile::QpFile(Msg* pMsg) : QFile()
{
    m_pMsg = pMsg;
    m_userMsg = true;
    init();
}

QpFile::QpFile(const QString& name, Msg* pMsg) : QFile(name)
{
    m_name = name;
    m_pMsg = pMsg;
    m_userMsg = true;
    init();
}

QpFile::~QpFile()
{
    if(! m_userMsg)
        delete m_pMsg;
}

void QpFile::init()
{
    m_noOpenMsg = "Cannot open file: %1 "
                  "\nYou may not have permission to access this file.";
    m_noCreateMsg = "Cannot create file: %1"
            "\nYou may not have permission to create files in this directory.";
    m_noExistMsg = "File: %1 does not exist.";
    m_noFlagsMsg = "There were no flags in the call to open File: %1";
    m_creating = "Creating file: ";
    m_opening = "Opening file: ";
}

void QpFile::sendError(OpenMode flags)
{
    QString msgText;

    if(flags == 0)
        msgText = QString(m_noFlagsMsg).arg((m_name));
    else if(exists(true))
        msgText = QString(m_noOpenMsg).arg(m_name);
    else
        msgText = QString(m_noCreateMsg).arg(m_name);

    if(m_userMsg)
        m_pMsg->sendNotify(msgText);
    else {
        QTextStream out(stdout);
        out << msgText << endl;
    }
}

bool QpFile::open(FILE *f, OpenMode flags, bool silent)
{
    bool status;
    if((status = openCommon(flags, silent)) == true) {
        status = QFile::open(f, flags);
        if((status == false) && (silent == false))
            sendError(flags);
    }
    return status;
}

bool QpFile::open(OpenMode flags, bool silent)
{
    bool status;
    if((status = openCommon(flags, silent)) == true) {
        bool status = QFile::open(flags);
        if((status == false) && (silent == false))
            sendError(flags);
    }
    return status;
}

bool QpFile::openCommon(OpenMode flags, bool silent)
{
    if(flags == 0) {
        sendError(flags);
        return false;
    }

    if((silent == false) && (m_quietOnSuccess == false)){
        QString text = exists(true) ? m_opening : m_creating;
        text.append(m_name);
        m_pMsg->sendInfo(text);
    }
    return true;
}

bool QpFile::exists(bool silent)
{
    bool status = QFile::exists();
    if((status == false) && (silent == false)) {
        QString msg = QString(m_noExistMsg).arg(m_name);
        m_pMsg->sendNotify(msg);
    }
    return status;
}

void QpFile::setFileName(const QString &name)
{
    m_name = name;
    QFile::setFileName(name);
}

int QpFile::get(OpenMode flags, bool silent)
{
    return openOrCreate(flags, silent);
}

int QpFile::get(const QString &name, OpenMode flags, bool silent)
{
    setFileName(name);
    return openOrCreate(flags, silent);
}

int QpFile::openOrCreate(OpenMode flags, bool silent)
{
    if((exists(true)) && (open(flags, silent)))
        return fOpened;

    if(open(flags, silent))
        return fCreated;

    return fFailed;
}
