/// @file xml_exception.h
/// @brief This file includes the xml exception definitions.

/****************************************************************************
* XML++ is a library for working with XML files.                                *
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

#if !defined(XMLPP_XML_EXCEPTION)
#define XMLPP_XML_EXCEPTION TRUE

#include "exception.h"

namespace xmlpp {

/// @brief  Exception raised if there's an error in read the xml file.
const int EX_PARSER_FILE_READ_ERROR = 1;

/// @brief  Exception raised if the XML file has some errors.
const int EX_XML_NOT_STANDARD = 2;

/// @brief  Exception raised if there's an error in a node.
const int EX_XML_BAD_NODE = 3;

/// @brief  Exception raised if a tag isn't closed.
const int EX_XML_TAG_NOT_CLOSED = 4;

class XMLException : public Exception
{
  public:
    XMLException (int code);
};

};

#endif

