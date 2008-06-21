/// @file   dom/document.cpp
/// @brief  This file includes the XML object implementation.

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

#include "document.h"

namespace xmlpp {

bool DOM::empty (void)
{
    if (this->children.empty()) {
        return true;
    }
    else {
        return false;
    }
}

std::string DOM::documentElement (void)
{
    return this->document;
}

DOMChildNode* DOM::childNodes (int childNode)
{
    if (this->children.size() <= childNode) {
        throw DOMException (EX_OUT_OF_RANGE);
    }
    else {
        return this->children.at(childNode);
    }
}

DOMChildNode* DOM::getElementById (std::string id)
{
    DOMChildNode *found = NULL;

    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNodes(i)->getAttribute("id") == id) {
            found = this->childNodes(i);
            break;
        }
        else {
            found = this->childNodes(i)->__getElementById(id);

            if (found != NULL) {
                break;
            }
        }
    }

    return found;
}

DOMChildNode* DOM::getElementById (const char* id)
{
    return this->getElementById((std::string) id);
}

DOMChildNodes DOM::getElementsByTagName (std::string tagName)
{
    DOMChildNodes elements;

    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNodes(i)->nodeName() == tagName) {
            elements.push_back(this->childNodes(i));
        }

        DOMChildNodes subElements = this->childNodes(i)->getElementsByTagName(tagName);
        for (size_t i = 0; i < subElements.size(); i++) {
            elements.push_back(subElements[i]);
        }
    }

    return elements;
}

DOMChildNodes DOM::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}

};

