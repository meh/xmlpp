/// @file dom/element.cpp
/// @brief This file includes the DOM element implementations.

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

DOMElement::DOMElement (std::string elementName) : DOMChildNode(DOM_ELEMENT_NODE)
{
    this->name = elementName;
}

DOMElement::DOMElement (const char* elementName) : DOMChildNode(DOM_ELEMENT_NODE)
{
    this->name = elementName;
}

// Getters.
std::string DOMElement::nodeName (void)
{
    return this->name;
}

std::string DOMElement::nodeValue (void)
{
    throw DOMException(EX_NODE_IS_ELEMENT);
}

// Setters.
bool DOMElement::setAttribute (std::string attributeName, std::string attributeValue)
{
    if (!this->hasAttribute(attributeName)) {
        this->attributes[attributeName] = new DOMAttribute(attributeName, attributeValue);
        return true;
    }
    else {
        return false;
    }
}

bool DOMElement::setAttribute (const char* attributeName, const char* attributeValue)
{
    return this->setAttribute((std::string) attributeName, (std::string) attributeValue);
}

// Getters.
DOMAttribute DOMElement::getAttribute (std::string attributeName)
{
    if (this->hasAttribute(attributeName)) {
        return *this->attributes[attributeName];
    }
    else {
        return DOMAttribute();
    }
}

DOMAttribute DOMElement::getAttribute (const char* attributeName)
{
    return this->getAttribute((std::string) attributeName);
}

// Misc.
bool DOMElement::hasAttribute (std::string attributeName)
{
    DOMAttributes::iterator attribute = this->attributes.find(attributeName);

    if (attribute == this->attributes.end()) {
        return false;
    }
    else {
        return true;
    }
}

bool DOMElement::hasAttribute (const char* attributeName)
{
    return this->hasAttribute((std::string) attributeName);
}

void DOMElement::appendChild (DOMChildNode* childNode)
{
    this->children.push_back(childNode);

    size_t position = this->children.size()-1;

    childNode->__setParent(this);

    if (position > 0) {
        childNode->__setPreviousSibling(this->children.at(position-1));
        this->children.at(position-1)->__setNextSibling(childNode);
    }
}

DOMChildNode* DOMElement::childNodes (int childNode)
{
    return this->children.at(childNode);
}

DOMChildNode* DOMElement::firstChild (void)
{
    return this->children.front();
}

DOMChildNode* DOMElement::lastChild (void)
{
    return this->children.back();
}

// Operators.


};

