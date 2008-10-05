/// @file dom/text.cpp
/// @brief This file includes the DOM text implementations.

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

#include "text.h"

namespace xmlpp {

DOMText::DOMText (std::string value) : DOMNode (text)
{
    this->_value = value;
}

DOMText::DOMText (const char* value) : DOMNode (text)
{
    this->_value = value;
}

std::string DOMText::plain (void)
{
    return this->_value;
}

// Getters.
std::string DOMText::nodeName (void)
{
    return "#text";
}

std::string DOMText::nodeValue (void)
{
    return this->_value;
}

void DOMText::nodeValue (const char* value)
{
    this->_value = value;
}

void DOMText::nodeValue (std::string value)
{
    this->_value = value;
}

std::string DOMText::data (void)
{
    return this->_value;
}

DOMNodes DOMText::childNodes (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

DOMNode* DOMText::childNodes (int)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

DOMNode* DOMText::firstChild (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

DOMNode* DOMText::lastChild (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

DOMNode* DOMText::cloneNode (bool cloneChildren)
{
    DOMText* copy = new DOMText(this->nodeValue());
    return copy;
}

std::vector<DOMNode*> DOMText::getElementsByTagName (std::string tagName)
{
    std::vector<DOMNode*> elements;

    return elements;
}

std::vector<DOMNode*> DOMText::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}

bool DOMText::hasChildNodes (void)
{
    return false;
}

};

