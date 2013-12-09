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

#include <QStringBuilder>   // uses % to build strings, rather than overload '+'
#include <QTextStream>
#include "msg.h"

Msg::Msg()
{
    m_haveMsgBox = false;
    init();
}

Msg::Msg(QTextEdit* userMsgBox)
{
    msgBox = userMsgBox;
    qtCursor = userMsgBox->textCursor();
    m_haveMsgBox = true;
    init();
}

void Msg::init()
{
    alertHtml = "<font color=\"DeepPink\">";
    notifyHtml = "<font color=\"Lime\">";
    infoHtml = "<font color=\"Aqua\">";
    endHtml = "</font>";
}

void Msg::setMsgBox(QTextEdit *userMsgBox)
{
    msgBox = userMsgBox;
    qtCursor = userMsgBox->textCursor();
    m_haveMsgBox = true;
}

void Msg::setStdOut()
{
    m_haveMsgBox = false;
}

void Msg::sendInfo(const char *line, eol_t eol)
{
    QString msg = line;
    sendMessage(msg, msg_info, eol);
}

void Msg::sendInfo(QString& msg, eol_t eol)
{
    sendMessage(msg, msg_info, eol);
}

void Msg::sendNotify(const char *line, eol_t eol)
{
    QString msg = line;
    sendMessage(msg, msg_notify, eol);
}

void Msg::sendNotify(QString& msg, eol_t eol)
{
    sendMessage(msg, msg_notify, eol);
}

void Msg::sendAlert(const char *line, eol_t eol)
{
    QString msg = line;
    sendMessage(msg, msg_alert, eol);
}

void Msg::sendAlert(QString& msg, eol_t eol)
{
    sendMessage(msg, msg_alert, eol);
}

void Msg::sendMessage(QString& line, msg_t level, eol_t eol)
{
    if(m_haveMsgBox) {

        switch(level) {
            case msg_alert: line = alertHtml % line; break;
            case msg_notify: line = notifyHtml % line; break;
            case msg_info: line = infoHtml % line; break;
            default: line = infoHtml % line; break;
        }

        line = line % endHtml;
        if (eol == crlf)
            line.append("<br>");

        msgBox->insertHtml(line);
        qtCursor.movePosition(QTextCursor::EndOfLine);
        msgBox->setTextCursor(qtCursor);
    }
    else {
        QTextStream out(stdout);
        out << line << endl;
    }
}

