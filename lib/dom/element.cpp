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

DOMElement::DOMElement (void) : DOMNode(document)
{
    this->_name = "#document";
}

DOMElement::DOMElement (std::string elementName) : DOMNode(element)
{
    this->_name = elementName;
}

DOMElement::DOMElement (const char* elementName) : DOMNode(element)
{
    this->_name = elementName;
}

DOMElement::~DOMElement (void)
{
    DOMAttributes::iterator attr;
    for (attr = this->_attributes.begin(); attr != this->_attributes.end(); attr++) {
        delete attr->second;
    }

    for (size_t i = 0; i < this->_children.size(); i++) {
        switch (this->_children[i]->nodeType()) {
            case element: 
            delete (DOMElement*) this->_children[i];
            break;

            case text:
            delete (DOMText*) this->_children[i];
            break;
        }
    }
}

std::string DOMElement::plain (void)
{
    std::string plain;

    plain += "<" + this->_name;
    
    std::string _attributes = this->_plainAttributes();

    if (!_attributes.empty()) {
        plain += " " + _attributes;
    }

    if (this->hasChildNodes()) {
        plain += ">";

        size_t i;
        for (i = 0; i < this->_children.size(); i++) {
            plain += this->childNodes(i)->plain();
        }
        
        plain += "</" + this->_name + ">";
    }
    else {
        plain += "/>";
    }

    return plain;
}

std::string DOMElement::nodeName (void)
{
    return this->_name;
}

std::string DOMElement::tagName (void)
{
    return utils::toUppercase (this->_name);
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
    DOMAttributes::iterator attr = this->_attributes.find(attributeName);

    if (attr != this->_attributes.end()) {
        attr->second->nodeValue(attributeValue);
    }
    else {
        this->_attributes[attributeName] = new DOMAttribute(attributeName, attributeValue);
    }
}

void DOMElement::setAttribute (const char* attributeName, const char* attributeValue)
{
    return this->setAttribute((std::string) attributeName, (std::string) attributeValue);
}

// Getters.
std::string DOMElement::getAttribute (std::string attributeName)
{
    DOMAttributes::iterator attr = this->_attributes.find(attributeName);

    if (attr != this->_attributes.end()) {
        return this->_attributes[attributeName]->nodeValue();
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
    DOMAttributes::iterator attr = this->_attributes.find(attributeName);

    if (attr != this->_attributes.end()) {
        delete attr->second;
        this->_attributes.erase(attr);
    }
}

void DOMElement::removeAttribute (const char* attributeName)
{
    this->removeAttribute ((std::string) attributeName);
}

void DOMElement::appendChild (DOMNode* childNode)
{
    childNode->__setParent(this);

    if (this->_children.size() > 0) {
        childNode->__setPreviousSibling(this->_children.back());
        this->_children.back()->__setNextSibling(childNode);
    }
    else {
        childNode->__setPreviousSibling(NULL);
    }

    childNode->__setNextSibling(NULL);

    this->_children.push_back(childNode);
}

void DOMElement::insertBefore (DOMNode* childNode, DOMNode* nodeAfter)
{
    DOMNodes::iterator node;

    if (this == nodeAfter->parentNode()) {
        for (node = this->_children.begin(); node < this->_children.end(); node++) {
            if (*node == nodeAfter) {
                this->_children.insert(node, childNode);
                break;
            }
        }
    }
}

void DOMElement::replaceChild (DOMNode* newChild, DOMNode* oldChild)
{
    DOMNode *parent = oldChild->parentNode();
    
    if (parent == this) {
        for (size_t i = 0; i < this->_children.size(); i++) {
            if (this->_children[i] == oldChild) {
                delete this->_children[i];
                this->_children[i] = newChild;

                if (i == 0) {
                    this->_children[i]->__setPreviousSibling(NULL);
                }
                else {
                    this->_children[i]->__setPreviousSibling(this->_children[i-1]);
                    this->_children[i-1]->__setNextSibling(this->_children[i]);
                }

                if (i < this->_children.size()-2) {
                    this->_children[i]->__setNextSibling(this->_children[i+1]);
                    this->_children[i+1]->__setPreviousSibling(this->_children[i]);
                }
                else {
                    this->_children[i]->__setNextSibling(NULL);
                }
                break;
            }
        }
    }
}

void DOMElement::removeChild (int childNode)
{
    if (childNode < this->_children.size()) {
        DOMNodes::iterator element = this->_children.begin()+childNode;
        delete *element;

        if (childNode == 0 && this->_children.size() > 1)  {
           (*(element+1))->__setPreviousSibling(NULL);
        }
        else if (childNode != 0 && childNode == this->_children.size()-1) {
            (*(element-1))->__setNextSibling(NULL);
        }
        else if (childNode > 0 && this->_children.size() > 1){
            (*(element+1))->__setPreviousSibling(*(element-1));
            (*(element-1))->__setNextSibling(*(element+1));
        }

        this->_children.erase(element);
    }
}

void DOMElement::removeChild (DOMNode* childNode)
{
    for (size_t i = 0; i < this->_children.size(); i++) {
        if (this->childNodes(i) == childNode) {
            DOMNodes::iterator element = this->_children.begin()+i;
            delete *element;

            if (i == 0 && this->_children.size() > 1) {
               (*(element+1))->__setPreviousSibling(NULL);
            }
            else if (i == this->_children.size()-1) {
                (*(element-1))->__setNextSibling(NULL);
            }
            else {
                (*(element+1))->__setPreviousSibling(*(element-1));
                (*(element-1))->__setNextSibling(*(element+1));
            }

            this->_children.erase(element);
            break;
        }
    }
}

bool DOMElement::hasChildNodes (void)
{
    if (this->_children.size() > 0) {
        return true;
    }
    else {
        return false;
    }
}

DOMNode* DOMElement::childNodes (int childNode)
{
    if (this->_children.size() <= childNode) {
        throw DOMException (EX_OUT_OF_RANGE);
    }
    else {
        return this->_children.at(childNode);
    }
}

DOMNode* DOMElement::firstChild (void)
{
    return this->_children.front();
}

DOMNode* DOMElement::lastChild (void)
{
    return this->_children.back();
}

DOMNode* DOMElement::cloneNode (bool cloneChildren)
{
    DOMElement *copy = new DOMElement(this->nodeName());

    DOMAttributes::iterator attr;
    for (attr = this->_attributes.begin(); attr != this->_attributes.end(); attr++) {
        copy->setAttribute(attr->second->nodeName(), attr->second->nodeValue());
    }
    
    if (cloneChildren) {
        for (size_t i = 0; i < this->_children.size(); i++) {
            copy->appendChild(this->childNodes(i)->cloneNode());
        }
    }

    return copy;
}

std::string DOMElement::_plainAttributes (void)
{
    if (!this->_attributes.empty()) {
        std::string plain;
        DOMAttributes::iterator attr;

        for (attr = this->_attributes.begin(); attr != this->_attributes.end(); attr++) {
            plain += attr->second->plain() + " ";
        }

        plain.resize(plain.length()-1);

        return plain;
    }
    else {
        return (std::string) "";
    }
}

DOMNode* DOMElement::__getElementById (std::string id)
{
    DOMNode *found = NULL;

    for (size_t i = 0; i < this->_children.size(); i++) {
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

DOMNode* DOMElement::__getElementById (const char* id)
{
    return this->__getElementById((std::string) id);
}

DOMNodes DOMElement::getElementsByTagName (std::string tagName)
{
    DOMNodes elements;

    for (size_t i = 0; i < this->_children.size(); i++) {
        if (this->childNodes(i)->nodeName() == tagName) {
            elements.push_back(this->childNodes(i));
        }

        DOMNodes subElements = this->childNodes(i)->getElementsByTagName(tagName);
        for (size_t i = 0; i < subElements.size(); i++) {
            elements.push_back(subElements[i]);
        }
    }

    return elements;
}

DOMNodes DOMElement::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}

};

