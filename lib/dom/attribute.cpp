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

DOMAttribute::DOMAttribute (std::string attributeName, std::string attributeValue)
{
    this->attributeName  = attributeName;
    this->attributeValue = attributeValue;
    this->updatePlain();
}

DOMAttribute::DOMAttribute (const char* attributeName, const char* attributeValue)
{
    this->attributeName  = attributeName;
    this->attributeValue = attributeValue;
    this->updatePlain();
}

std::string DOMAttribute::nodeName (void)
{
    return this->attributeName;
}

void DOMAttribute::nodeName (std::string attributeName)
{
    this->attributeName = attributeName;
    this->updatePlain();
}

void DOMAttribute::nodeName (const char* attributeName)
{
    this->attributeName = attributeName;
    this->updatePlain();
}

std::string DOMAttribute::nodeValue (void)
{
    return this->attributeValue;
}

void DOMAttribute::nodeValue (std::string attributeValue)
{
    this->attributeValue = attributeValue;
    this->updatePlain();
}

void DOMAttribute::nodeValue (const char* attributeValue)
{
    this->attributeValue = attributeValue;
    this->updatePlain();
}

void DOMAttribute::updatePlain (void)
{
    if (!this->attributeName.empty() && !this->attributeValue.empty()) {
        this->plainText = this->attributeName + "=\"" + this->attributeValue + "\"";
    }
}

// Operators.
std::string DOMAttribute::operator [] (const char* mode) const throw()
{
    if (strcmp("name", mode) == 0) {
        return this->attributeName;
    }
    else if (strcmp("value", mode) == 0) {
        return this->attributeValue;
    }
    else if (strcmp("plain", mode) == 0) {
        return this->plainText;
    }
    else {
        throw DOMException(EX_ATTRIBUTE_MODE_NOT_EXISTENT);
    }
}

};

