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
    this->_element = new DOMElement("#document");
}

DOMDocument::~DOMDocument (void)
{
    delete this->_element;
}

DOMNodeType DOMDocument::nodeType (void)
{
    return document;
}

std::string DOMDocument::documentElement (void)
{
    std::string document;

    document += "<?xml version=\"" + this->version() + "\"?>";
    
    size_t i;
    for (i = 0; i < this->_element->childNodesNumber(); i++) {
        document += this->_element->childNodes(i)->plain();
    }

    return document;
}

void DOMDocument::appendChild (DOMNode* childNode)
{
    this->_element->appendChild(childNode);
}

void DOMDocument::insertBefore (DOMNode* childNode, DOMNode* nodeAfter)
{
    this->_element->insertBefore(childNode, nodeAfter);
}

void DOMDocument::replaceChild (DOMNode* newChild, DOMNode* oldChild)
{
    this->_element->replaceChild(newChild, oldChild);
}

void DOMDocument::removeChild (int childNode)
{
    this->_element->removeChild(childNode);
}

void DOMDocument::removeChild (DOMNode* childNode)
{
    this->_element->removeChild(childNode);
}

DOMNode* DOMDocument::childNodes (int childNode)
{
    return this->_element->childNodes(childNode);
}

DOMNode* DOMDocument::firstChild (void)
{
    return this->_element->firstChild();
}

DOMNode* DOMDocument::lastChild (void)
{
    return this->_element->lastChild();
}

DOMNode* DOMDocument::getElementById (std::string id)
{
    return this->_element->__getElementById(id);
}

DOMNode* DOMDocument::getElementById (const char* id)
{
    return this->_element->__getElementById(id);
}

DOMNodes DOMDocument::getElementsByTagName (std::string tagName)
{
    return this->_element->getElementsByTagName(tagName);
}

DOMNodes DOMDocument::getElementsByTagName (const char* tagName)
{
    return this->_element->getElementsByTagName(tagName);
}

void DOMDocument::setVersion (std::string version)
{
    this->_xmlVersion = version;
}

void DOMDocument::setVersion (const char* version)
{
    this->_xmlVersion = version;
}

std::string DOMDocument::version (void)
{
    return this->_xmlVersion;
}

};

