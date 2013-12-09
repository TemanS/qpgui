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

#ifndef MSG_H
#define MSG_H

#include <QTextEdit>

namespace msg
{
    enum msg_t {msg_alert, msg_notify, msg_info, msg_boundary};
    enum eol_t {crlf, nocrlf};
}

using namespace msg;

class Msg
{
public:
    Msg();
    Msg(QTextEdit* msgBox);
    void setMsgBox(QTextEdit* userMsgBox);

    void sendInfo(const char *line, eol_t eol=crlf);
    void sendInfo(QString& str, eol_t eol=crlf);
    void sendNotify(const char *line, eol_t eol=crlf);
    void sendNotify(QString& str, eol_t eol=crlf);
    void sendAlert(const char *line, eol_t eol=crlf);
    void sendAlert(QString& str, eol_t eol=crlf);
    void sendMessage(QString& line, msg_t level, eol_t eol=crlf);

    void setStdOut();

private:
    bool m_haveMsgBox;
    QTextEdit* msgBox;
    QTextCursor qtCursor;
    QString alertHtml;
    QString notifyHtml;
    QString infoHtml;
    QString endHtml;

    void init();
};

#endif // MSG_H
