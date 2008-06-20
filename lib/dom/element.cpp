/// @file dom/element.cpp
/// @brief This file includes the DOM element implementations.

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

DOMElement::~DOMElement (void)
{
    DOMAttributes::iterator attr;
    for (attr = this->attributes.begin(); attr != this->attributes.end(); attr++) {
        delete (*attr).second;
    }
    delete &this->attributes;

    for (size_t i = 0; i < this->children.size(); i++) {
        switch (this->children[i]->nodeType()) {
            case DOM_ELEMENT_NODE: 
            delete (DOMElement*) this->children[i];
            break;

            case DOM_TEXT_NODE:
            delete (DOMText*) this->children[i];
            break;
        }
    }
    delete &this->children;
}

// Getters.
std::string DOMElement::nodeName (void)
{
    return this->name;
}

std::string DOMElement::nodeValue (const char* value)
{
    throw DOMException(EX_NODE_IS_ELEMENT);
}

std::string DOMElement::data (void)
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
std::string DOMElement::getAttribute (std::string attributeName)
{
    if (this->hasAttribute(attributeName)) {
        return this->attributes[attributeName]->value();
    }
    else {
        return NULL;
    }
}

std::string DOMElement::getAttribute (const char* attributeName)
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
    childNode->__setParent(this);

    if (this->children.size() > 0) {
        childNode->__setPreviousSibling(this->children.back());
        this->children.back()->__setNextSibling(childNode);
    }
    else {
        childNode->__setPreviousSibling(NULL);
    }

    childNode->__setNextSibling(NULL);

    this->children.push_back(childNode);
}

DOMChildNodes DOMElement::childNodes (void)
{
    return this->children;
}

DOMChildNode* DOMElement::childNode (int childNode)
{
    if (this->children.size() <= childNode) {
        throw DOMException (EX_OUT_OF_RANGE);
    }
    else {
        return this->children.at(childNode);
    }
}

DOMChildNode* DOMElement::cloneNode (bool cloneChildren)
{
    DOMElement *copy = new DOMElement(this->nodeName());

    DOMAttributes::iterator attr;
    for (attr = this->attributes.begin(); attr != this->attributes.end(); attr++) {
        copy->setAttribute((*attr).first, (*attr).second->value());
    }
    
    if (cloneChildren) {
        for (size_t i = 0; i < this->children.size(); i++) {
            copy->appendChild(this->childNode(i)->cloneNode());
        }
    }

    return copy;
}

void DOMElement::removeChild (int childNode)
{
    if (this->children.size() > childNode) {
        DOMChildNodes::iterator element = this->children.begin()+(childNode-1);
        delete *element;

        this->children.erase(element);
    }
}

void DOMElement::removeChild (DOMChildNode* childNode)
{
    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNode(i) == childNode) {
            DOMChildNodes::iterator element = this->children.begin()+i-1;
            delete *element;

            this->children.erase(element);
            break;
        }
    }
}

DOMChildNode* DOMElement::firstChild (void)
{
    return this->children.front();
}

DOMChildNode* DOMElement::lastChild (void)
{
    return this->children.back();
}

DOMChildNode* DOMElement::__getElementById (std::string id)
{
    DOMChildNode *found = NULL;

    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNode(i)->getAttribute("id") == id) {
            found = this->childNode(i);
            break;
        }
        else {
            found = this->childNode(i)->__getElementById(id);

            if (found != NULL) {
                break;
            }
        }
    }

    return found;
}

DOMChildNode* DOMElement::__getElementById (const char* id)
{
    return this->__getElementById((std::string) id);
}

std::vector<DOMChildNode*> DOMElement::getElementsByTagName (std::string tagName)
{
    DOMChildNodes elements;

    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNode(i)->nodeName() == tagName) {
            elements.push_back(this->childNode(i));
        }

        DOMChildNodes subElements = this->childNode(i)->getElementsByTagName(tagName);
        for (size_t i = 0; i < subElements.size(); i++) {
            elements.push_back(subElements[i]);
        }
    }

    return elements;
}

std::vector<DOMChildNode*> DOMElement::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}


bool DOMElement::hasChildNodes (void)
{
    if (this->children.size() > 0) {
        return true;
    }
    else {
        return false;
    }
}

// Operators.


};

