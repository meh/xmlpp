/// @file xml/element.cpp
/// @brief This file includes the XML element implementations.

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

#include "element.h"

namespace xmlpp {

XMLElement::XMLElement (void)
{
    this->initialized = false;
}

XMLElement::XMLElement (std::string elementName)
{
    this->initialized = true;
    this->setName(elementName);
}

XMLElement::XMLElement (const char* elementName)
{
    this->initialized = true;
    this->setName((std::string) elementName);
}

// Setters.
void XMLElement::setName (std::string elementName)
{
    this->name = elementName;
}

void XMLElement::setName (const char* elementName)
{
    this->name = (std::string) elementName;
}

bool XMLElement::setAttribute (std::string attributeName, std::string attributeValue)
{
    if (!this->hasAttribute(attributeName)) {
        this->attributes[attributeName] = new XMLAttribute(attributeName, attributeValue);
        return true;
    }
    else {
        return false;
    }
}

bool XMLElement::setAttribute (const char* attributeName, const char* attributeValue)
{
    return this->setAttribute((std::string) attributeName, (std::string) attributeValue);
}

// Getters.
std::string XMLElement::getName (void)
{
    return this->name;
}

XMLAttribute XMLElement::getAttribute (std::string attributeName)
{
    if (this->hasAttribute(attributeName)) {
        return *this->attributes[attributeName];
    }
    else {
        return XMLAttribute();
    }
}

XMLAttribute XMLElement::getAttribute (const char* attributeName)
{
    return this->getAttribute((std::string) attributeName);
}

// Misc.
bool XMLElement::hasAttribute (std::string attributeName)
{
    XMLAttributes::iterator attribute = this->attributes.find(attributeName);

    if (attribute == this->attributes.end()) {
        return false;
    }
    else {
        return true;
    }
}

bool XMLElement::hasAttribute (const char* attributeName)
{
    return this->hasAttribute((std::string) attributeName);
}

// Operators.


};

