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

DOMElement::DOMElement (std::string elementName) : DOMChildNode(DOM_NODE_ELEMENT)
{
    this->name = elementName;
}

DOMElement::DOMElement (const char* elementName) : DOMChildNode(DOM_NODE_ELEMENT)
{
    this->name = elementName;
}

DOMElement::~DOMElement (void)
{
    DOMAttributes::iterator attr;
    for (attr = this->attributes.begin(); attr != this->attributes.end(); attr++) {
        delete attr->second;
    }
    delete &this->attributes;

    for (size_t i = 0; i < this->children.size(); i++) {
        switch (this->children[i]->nodeType()) {
            case DOM_NODE_ELEMENT: 
            delete (DOMElement*) this->children[i];
            break;

            case DOM_NODE_TEXT:
            delete (DOMText*) this->children[i];
            break;
        }
    }
    delete &this->children;
}

std::string DOMElement::plain (void)
{
    std::string plain;

    plain += "<" + this->name;
    
    std::string attributes = this->plainAttributes();

    if (!attributes.empty()) {
        plain += " " + attributes;
    }

    if (this->hasChildNodes()) {
        plain += ">";

        size_t i;
        for (i = 0; i < this->children.size(); i++) {
            plain += this->childNodes(i)->plain();
        }
        
        plain += "</" + this->name + ">";
    }
    else {
        plain += "/>";
    }

    return plain;
}

std::string DOMElement::plainAttributes (void)
{
    std::string plain;
    DOMAttributes::iterator attr;

    for (attr = this->attributes.begin(); attr != this->attributes.end(); attr++) {
        plain += attr->first + "=";
        plain += "\"" + attr->second->nodeValue() + "\" ";
    }

    return plain;
}

std::string DOMElement::nodeName (void)
{
    return this->name;
}

std::string DOMElement::tagName (void)
{
    return utils::toUppercase (this->name);
}

std::string DOMElement::id (void)
{
    return this->getAttribute("id");
}

void DOMElement::id (std::string newId)
{
    this->setAttribute("id", newId);
}

void DOMElement::id (const char* newId)
{
    this->setAttribute("id", newId);
}

std::string DOMElement::title (void)
{
    return this->getAttribute("title");
}

void DOMElement::title (std::string title)
{
    this->setAttribute("title", title);
}

void DOMElement::title (const char* title)
{
    this->setAttribute("title", title);
}

void DOMElement::setAttribute (std::string attributeName, std::string attributeValue)
{
    DOMAttributes::iterator attr = this->attributes.find(attributeName);

    if (attr != this->attributes.end()) {
        attr->second->nodeValue(attributeValue);
    }
    else {
        this->attributes[attributeName] = new DOMAttribute(attributeName, attributeValue);
    }
}

void DOMElement::setAttribute (const char* attributeName, const char* attributeValue)
{
    return this->setAttribute((std::string) attributeName, (std::string) attributeValue);
}

// Getters.
std::string DOMElement::getAttribute (std::string attributeName)
{
    DOMAttributes::iterator attr = this->attributes.find(attributeName);

    if (attr != this->attributes.end()) {
        return this->attributes[attributeName]->nodeValue();
    }
    else {
        return NULL;
    }
}

std::string DOMElement::getAttribute (const char* attributeName)
{
    return this->getAttribute((std::string) attributeName);
}

void DOMElement::removeAttribute (std::string attributeName)
{
    DOMAttributes::iterator attr = this->attributes.find(attributeName);

    if (attr != this->attributes.end()) {
        delete attr->second;
        this->attributes.erase(attr);
    }
}

void DOMElement::removeAttribute (const char* attributeName)
{
    this->removeAttribute ((std::string) attributeName);
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

void DOMElement::insertBefore (DOMChildNode* childNode, DOMChildNode* nodeAfter)
{
    DOMChildNodes::iterator node;

    if (this == nodeAfter->parentNode()) {
        for (node = this->children.begin(); node < this->children.end(); node++) {
            if (*node == nodeAfter) {
                this->children.insert(node, childNode);
                break;
            }
        }
    }
}

void DOMElement::replaceChild (DOMChildNode* newChild, DOMChildNode* oldChild)
{
    DOM *parent = oldChild->parentNode();
    
    if (parent == this) {
        for (size_t i = 0; i < this->children.size(); i++) {
            if (this->children[i] == oldChild) {
                delete this->children[i];
                this->children[i] = newChild;

                if (i == 0) {
                    this->children[i]->__setPreviousSibling(NULL);
                }
                else {
                    this->children[i]->__setPreviousSibling(this->children[i-1]);
                    this->children[i-1]->__setNextSibling(this->children[i]);
                }

                if (i < this->children.size()-2) {
                    this->children[i]->__setNextSibling(this->children[i+1]);
                    this->children[i+1]->__setPreviousSibling(this->children[i]);
                }
                else {
                    this->children[i]->__setNextSibling(NULL);
                }
                break;
            }
        }
    }
}

void DOMElement::removeChild (int childNode)
{
    if (childNode < this->children.size()) {
        DOMChildNodes::iterator element = this->children.begin()+childNode;
        delete *element;

        if (childNode == 0 && this->children.size() > 1)  {
           (*(element+1))->__setPreviousSibling(NULL);
        }
        else if (childNode != 0 && childNode == this->children.size()-1) {
            (*(element-1))->__setNextSibling(NULL);
        }
        else if (childNode > 0 && this->children.size() > 1){
            (*(element+1))->__setPreviousSibling(*(element-1));
            (*(element-1))->__setNextSibling(*(element+1));
        }

        this->children.erase(element);
    }
}

void DOMElement::removeChild (DOMChildNode* childNode)
{
    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNodes(i) == childNode) {
            DOMChildNodes::iterator element = this->children.begin()+i;
            delete *element;

            if (i == 0 && this->children.size() > 1) {
               (*(element+1))->__setPreviousSibling(NULL);
            }
            else if (i == this->children.size()-1) {
                (*(element-1))->__setNextSibling(NULL);
            }
            else {
                (*(element+1))->__setPreviousSibling(*(element-1));
                (*(element-1))->__setNextSibling(*(element+1));
            }

            this->children.erase(element);
            break;
        }
    }
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

DOMChildNode* DOMElement::childNodes (int childNode)
{
    if (this->children.size() <= childNode) {
        throw DOMException (EX_OUT_OF_RANGE);
    }
    else {
        return this->children.at(childNode);
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

DOMChildNode* DOMElement::cloneNode (bool cloneChildren)
{
    DOMElement *copy = new DOMElement(this->nodeName());

    DOMAttributes::iterator attr;
    for (attr = this->attributes.begin(); attr != this->attributes.end(); attr++) {
        copy->setAttribute(attr->second->nodeName(), attr->second->nodeValue());
    }
    
    if (cloneChildren) {
        for (size_t i = 0; i < this->children.size(); i++) {
            copy->appendChild(this->childNodes(i)->cloneNode());
        }
    }

    return copy;
}

DOMChildNode* DOMElement::__getElementById (std::string id)
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

DOMChildNode* DOMElement::__getElementById (const char* id)
{
    return this->__getElementById((std::string) id);
}

DOMChildNodes DOMElement::getElementsByTagName (std::string tagName)
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

DOMChildNodes DOMElement::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}

};

