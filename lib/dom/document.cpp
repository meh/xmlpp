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


DOMDocument::DOMDocument (void) : DOM (DOM_DOCUMENT)
{
}

bool DOMDocument::empty (void)
{
    if (this->children.empty()) {
        return true;
    }
    else {
        return false;
    }
}

std::string DOMDocument::documentElement (void)
{
    return this->document;
}

void DOMDocument::appendChild (DOMChildNode* childNode)
{
    childNode->__setParent((DOM*) this);

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

void DOMDocument::insertBefore (DOMChildNode* childNode, DOMChildNode* nodeAfter)
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

void DOMDocument::replaceChild (DOMChildNode* newChild, DOMChildNode* oldChild)
{
    DOM *parent = oldChild->parentNode();

    if (parent->getType() == DOM_DOCUMENT && (DOMDocument*) parent == this) {
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

void DOMDocument::removeChild (int childNode)
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

void DOMDocument::removeChild (DOMChildNode* childNode)
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

DOMChildNode* DOMDocument::childNodes (int childNode)
{
    if (this->children.size() <= childNode) {
        throw DOMException (EX_OUT_OF_RANGE);
    }
    else {
        return this->children.at(childNode);
    }
}

DOMChildNode* DOMDocument::firstChild (void)
{
    return this->children.front();
}

DOMChildNode* DOMDocument::lastChild (void)
{
    return this->children.back();
}

DOMChildNode* DOMDocument::getElementById (std::string id)
{
    DOMChildNode *found = NULL;

    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNodes(i)->id() == id) {
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

DOMChildNode* DOMDocument::getElementById (const char* id)
{
    return this->getElementById((std::string) id);
}

DOMChildNodes DOMDocument::getElementsByTagName (std::string tagName)
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

DOMChildNodes DOMDocument::getElementsByTagName (const char* tagName)
{
    return this->getElementsByTagName((std::string) tagName);
}

};

