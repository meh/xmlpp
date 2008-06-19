/// @file dom_exception.h
/// @brief This file includes the dom exception definitions.

/****************************************************************************
* XML++ is a library to work with XML files.                                *
* Copyright (C) 2008  cHoBi                                                 *
*                                                                           *
* This file is part of XML++                                                *
*                                                                           *
* XML++ is free software: you can redistribute it and/or modify             *
* it under the terms of the GNU Affero General Public License as            *
* published by the Free Software Foundation, either version 3 of the        *
* License, or (at your option) any later version.                           *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
****************************************************************************/

#if !defined (XMLPP_DOM_EXCEPTION)
#define XMLPP_DOM_EXCEPTION TRUE

#include "exception.h"

namespace xmlpp {

#define EX_ATTRIBUTE_MODE_NOT_EXISTENT  1
#define EX_NODE_IS_ELEMENT              2
#define EX_NODE_IS_TEXT                 3

class DOMException : public Exception
{
  public:
    DOMException (int code);
};

};

#endif
