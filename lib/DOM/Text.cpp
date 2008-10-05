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

namespace DOM {

Text::Text (std::string value) : Node (text)
{
    this->_value = value;
}

Text::Text (const char* value) : Node (text)
{
    this->_value = value;
}

std::string Text::plain (void)
{
    return this->_value;
}

// Getters.
std::string Text::nodeName (void)
{
    return "#text";
}

std::string Text::nodeValue (void)
{
    return this->_value;
}

void Text::nodeValue (const char* value)
{
    this->_value = value;
}

void Text::nodeValue (std::string value)
{
    this->_value = value;
}

std::string Text::data (void)
{
    return this->_value;
}

Nodes Text::childNodes (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

Node* Text::childNodes (int)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

Node* Text::firstChild (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

Node* Text::lastChild (void)
{
    throw DOMException(EX_NODE_IS_TEXT);
}

Node* Text::cloneNode (bool cloneChildren)
{
    Text* copy = new Text(this->nodeValue());
    return copy;
}

std::vector<Node*> Text::getElementsByTagName (std::string tagName)
{
    std::vector<Node*> elements;

    return elements;
}

std::vector<Node*> Text::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}

bool Text::hasChildNodes (void)
{
    return false;
}

};

};

