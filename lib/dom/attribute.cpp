/// @file dom/attribute.cpp
/// @brief This file includes the XML attribute implementations.

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

#include "attribute.h"

namespace xmlpp {

DOMAttribute::DOMAttribute (std::string name, std::string value)
{
    this->_name  = name;
    this->_value = value;
}

DOMAttribute::DOMAttribute (const char* name, const char* value)
{
    this->_name  = name;
    this->_value = value;
}

std::string DOMAttribute::nodeName (void)
{
    return this->_name;
}

void DOMAttribute::nodeName (std::string name)
{
    this->_name = name;
}

void DOMAttribute::nodeName (const char* name)
{
    this->_name = name;
}

std::string DOMAttribute::nodeValue (void)
{
    return this->_value;
}

void DOMAttribute::nodeValue (std::string value)
{
    this->_value = value;
}

void DOMAttribute::nodeValue (const char* value)
{
    this->_value = value;
}

std::string DOMAttribute::plain (void)
{
    if (!this->_name.empty() && !this->_value.empty()) {
        return this->_name + "=\"" + this->_value + "\"";
    }
    else {
        return (std::string) "";
    }
}

// Operators.
std::string DOMAttribute::operator [] (const char* mode) throw()
{
    if (strcmp("name", mode) == 0) {
        return this->_name;
    }
    else if (strcmp("value", mode) == 0) {
        return this->_value;
    }
    else if (strcmp("plain", mode) == 0) {
        return this->plain();
    }
    else {
        throw DOMException(EX_ATTRIBUTE_MODE_NOT_EXISTENT);
    }
}

};

