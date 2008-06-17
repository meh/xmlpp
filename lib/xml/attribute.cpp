/// @file xml/attribute.cpp
/// @brief This file includes the XML attribute implementations.

/****************************************************************************
* XML++ is a library to work with XML files.                                *
* Copyright (C) 2008  Paolo D. Galli                                        *
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

XMLAttribute::XMLAttribute (void)
{
    this->initialized = false;
}

XMLAttribute::XMLAttribute (std::string attributeName, std::string attributeValue)
{
    this->initialized = true;
    this->setName(attributeName);
    this->setValue(attributeValue);
    this->updatePlain();
}

XMLAttribute::XMLAttribute (const char* attributeName, const char* attributeValue)
{
    this->initialized = true;
    this->setName((std::string) attributeName);
    this->setValue((std::string) attributeValue);
    this->updatePlain();
}

// Setters.
void XMLAttribute::setName (std::string attributeName)
{
    this->name = attributeName;
}

void XMLAttribute::setName (const char* attributeName)
{
    this->name = attributeName;
}

void XMLAttribute::setValue (std::string attributeValue)
{
    this->value = attributeValue;
}

void XMLAttribute::setValue (const char* attributeValue)
{
    this->value = attributeValue;
}

// Getters.
std::string XMLAttribute::getName (void)
{
    return this->name;
}

std::string XMLAttribute::getValue (void)
{
    return this->value;
}

bool XMLAttribute::isInitialized (void)
{
    return this->initialized;
}

// Misc.
void XMLAttribute::updatePlain (void)
{
    if (!this->name.empty() && !this->value.empty()) {
        this->plain = this->name + "=\"" + this->value + "\"";
    }
}

// Operators.
std::string XMLAttribute::operator [] (const char* mode) const throw()
{
    if (strcmp("name", mode) == 0) {
        return this->name;
    }
    else if (strcmp("value", mode) == 0) {
        return this->value;
    }
    else if (strcmp("plain", mode) == 0) {
        return this->plain;
    }
    else {
        throw XMLException(ATTRIBUTE_MODE_NOT_EXISTENT);
    }
}

};

