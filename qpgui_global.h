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

#ifndef QPGUI_GLOBAL_H
#define QPGUI_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtGlobal>

#if defined(QPGUI_LIBRARY)
#  define QPGUISHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPGUISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPGUI_GLOBAL_H
