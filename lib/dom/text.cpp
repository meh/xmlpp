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

DOMText::DOMText (std::string text) : DOMChildNode (DOM_NODE_TEXT)
{
    this->value = text;
}

DOMText::DOMText (const char* text) : DOMChildNode (DOM_NODE_TEXT)
{
    this->value = text;
}

std::string DOMText::plain (void)
{
    return this->value;
}

// Getters.
std::string DOMText::nodeName (void)
{
    return "#text";
}

std::string DOMText::nodeValue (void)
{
    return this->value;
}

void DOMText::nodeValue (const char* value)
{
    this->value = value;
}

void DOMText::nodeValue (std::string value)
{
    this->value = value;
}

std::string DOMText::data (void)
{
    return this->value;
}

DOMChildNode* DOMText::childNodes (int)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::firstChild (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::lastChild (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::cloneNode (bool cloneChildren)
{
    DOMText *copy = new DOMText(this->nodeValue());
    return copy;
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

