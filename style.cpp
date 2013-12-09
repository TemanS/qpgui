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
#include "style.h"

static QString appStyle =
    "QPushButton {"
        "color: black; "
        "background-color: "
            "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop: 0 #eaebfe, stop: 1 #76878a); "
        "border-style:outset;border-width:1px;"
        "border-radius4px;border-color:gray; }"

    "QPushButton:pressed{"
        "color: white; "
        "background-color: "
            "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop: 0 #08080a, stop: 1 #66777a); "
        "border:6pxsolidwhite; "
        "border-style:inset;border-width:1px;"
        "border-radius6px;border-color:white;}"

    "QLineEdit {"
        "color: aqua; "
        "background-color: black; "
        "font-size:16px; "
        "border-style:inset;border-width:2px;"
        "border-radius4px;border-color:gray; }"

    "QComboBox {"
        "color: aqua; "
        "background-color: black; "
        "border-style:inset;border-width:2px;"
        "border-radius4px;border-color:gray; }"

    "QTextEdit {"
        "color: aqua; "
        "background-color: black; "
        "border-style:inset;border-width:2px;"
        "border-radius4px;border-color:gray; }"

    /*"QCheckBox {"
        "border-style:outset;border-width:2px;"
        "border-radius4px;border-color:gray; }"*/
#if 0
    "QGroupBox {"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0 #E0E0E0, stop: 1 #FFFFFF);"
        "border: 2px solid gray;"
        "border-radius: 2px;"
        "margin-top: 1ex; /* leave space at the top for the title */}"

    "QGroupBox::title {"
        "subcontrol-origin: margin;"
        "subcontrol-position: top center; /* position at the top center */"
        "padding: 0 3px;"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0 #FFOECE, stop: 1 #FFFFFF);} "
#endif
        ;

QpAppStyle::QpAppStyle()
{
    pAppStyle = &appStyle;
}

QString* QpAppStyle::getAppStyle()
{
    return pAppStyle;
}
