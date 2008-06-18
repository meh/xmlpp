/// @file dom/text.cpp
/// @brief This file includes the DOM text implementations.

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
    throw DOMException(EX_NODE_IS_TEXT);
}

std::string DOMText::nodeValue (void)
{
    return this->value;
}

void DOMText::appendChild (DOMChildNode* childNode)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::childNodes (int childNode)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::firstChild (void)
{
    throw DOMException (EX_NODE_IS_TEXT);
}

DOMChildNode* DOMText::lastChild (void)
{
    throw DOMException (EX_NODE_IS_TEXT);
}


};

