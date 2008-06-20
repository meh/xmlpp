/// @file dom/text.cpp
/// @brief This file includes the DOM text implementations.

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

#include "text.h"

namespace xmlpp {

DOMText::DOMText (std::string text) : DOMChildNode (DOM_TEXT_NODE)
{
    this->value = text;
}

DOMText::DOMText (const char* text) : DOMChildNode (DOM_TEXT_NODE)
{
    this->value = text;
}

// Getters.
std::string DOMText::nodeName (void)
{
    return "#text";
}

std::string DOMText::nodeValue (const char* value)
{
    if (value == NULL) {
        return this->value;
    }
    else {
        this->value = value;
    }
}

std::string DOMText::data (void)
{
    return this->value;
}

bool DOMText::setAttribute (std::string attributeName, std::string attributeValue)
{
    return false;
}

bool DOMText::setAttribute (const char* attributeName, const char* attributeValue)
{
    return false;
}

std::string DOMText::getAttribute (std::string attributeName)
{
    return NULL;
}

std::string DOMText::getAttribute (const char* attributeName)
{
    return NULL;
}

void DOMText::appendChild (DOMChildNode* childNode)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNodes DOMText::childNodes (void)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::childNode (int childNode)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::cloneNode (bool cloneChildren)
{
    DOMText *copy = new DOMText(this->nodeValue());
    return copy;
}

DOMChildNode* DOMText::firstChild (void)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::lastChild (void)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::__getElementById (std::string id)
{
    return NULL;
}

DOMChildNode* DOMText::__getElementById (const char* id)
{
    return NULL;
}

std::vector<DOMChildNode*> DOMText::getElementsByTagName (std::string tagName)
{
    std::vector<DOMChildNode*> elements;

    return elements;
}

std::vector<DOMChildNode*> DOMText::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}

bool DOMText::hasChildNodes (void)
{
    return false;
}

};

