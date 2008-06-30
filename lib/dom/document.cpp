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

DOMDocument::DOMDocument (void)
{
    this->setVersion("1.0");
    this->element = new DOMElement();
}

std::string DOMDocument::documentElement (void)
{
    std::string document;

    document += "<?xml version=\"" + this->version() + "\"?>";
    document += this->element->plain();

    return document;
}

void DOMDocument::appendChild (DOMNode* childNode)
{
    this->element->appendChild(childNode);
}

void DOMDocument::insertBefore (DOMNode* childNode, DOMNode* nodeAfter)
{
    this->element->insertBefore(childNode, nodeAfter);
}

void DOMDocument::replaceChild (DOMNode* newChild, DOMNode* oldChild)
{
    this->element->replaceChild(newChild, oldChild);
}

void DOMDocument::removeChild (int childNode)
{
    this->element->removeChild(childNode);
}

void DOMDocument::removeChild (DOMNode* childNode)
{
    this->element->removeChild(childNode);
}

DOMNode* DOMDocument::childNodes (int childNode)
{
    return this->element->childNodes(childNode);
}

DOMNode* DOMDocument::firstChild (void)
{
    return this->element->firstChild();
}

DOMNode* DOMDocument::lastChild (void)
{
    return this->element->lastChild();
}

DOMNode* DOMDocument::getElementById (std::string id)
{
    return this->element->__getElementById(id);
}

DOMNode* DOMDocument::getElementById (const char* id)
{
    return this->element->__getElementById(id);
}

DOMNodes DOMDocument::getElementsByTagName (std::string tagName)
{
    return this->element->getElementsByTagName(tagName);
}

DOMNodes DOMDocument::getElementsByTagName (const char* tagName)
{
    return this->element->getElementsByTagName(tagName);
}

void DOMDocument::setVersion (std::string version)
{
    this->xmlVersion = version;
}

void DOMDocument::setVersion (const char* version)
{
    this->xmlVersion = version;
}

std::string DOMDocument::version (void)
{
    return this->xmlVersion;
}

};

