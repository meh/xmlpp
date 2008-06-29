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

/// @brief  I don't remember lol.
const int EX_ATTRIBUTE_MODE_NOT_EXISTENT = 1;

/// @brief  Exception raised if the node used is an element node and
///         it doesn't have that method.
const int EX_NODE_IS_ELEMENT = 2;

/// @brief  Exception raised if the node used is a text node and it
///         doesnt' have that method.
const int EX_NODE_IS_TEXT = 3;

/// @brief  Exception raised if the child node requested doesn't exist.
const int EX_OUT_OF_RANGE = 4;

class DOMException : public Exception
{
  public:
    DOMException (int code);
};

};

#endif
