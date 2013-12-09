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

#ifndef QPFILE_H
#define QPFILE_H

#include <QFile>

class Msg;

namespace qpfile
{
    enum fret_t {fOpened, fCreated, fFailed, fBoundary};
};

class QpFile : public QFile
{
    Q_OBJECT
public:
    QpFile();
    QpFile(Msg* pMsg);
    QpFile(const QString& name);
    QpFile(const QString &name, Msg* pMsg);
    ~QpFile();
    bool exists(bool silent=false);
    bool open(FILE *f, OpenMode flags, bool silent=false);
    bool open(OpenMode flags, bool silent=false);
    int  get(const QString& name, OpenMode flags, bool silent=false);
    int  get(OpenMode flags, bool silent=false);
    void setFileName(const QString &name);
    void setQuietOnSuccess(bool state) {m_quietOnSuccess = state;}

private:
    void init();
    void sendNoOpenMsg();
    void sendNoExistMsg();
    void sendError(OpenMode flags);
    int  openOrCreate(OpenMode flags, bool silent=false);
    bool openCommon(OpenMode flags, bool silent);

    bool m_userMsg;
    bool m_quietOnSuccess;
    Msg *m_pMsg;
    QFile *m_pFile;
    QString m_name;
    QString m_noOpenMsg;
    QString m_noCreateMsg;
    QString m_noExistMsg;
    QString m_noFlagsMsg;
    QString m_opening;
    QString m_creating;
};

#endif // QPFILE_H
