/// @file   dom/text.h
/// @brief  This file includes the DOM text definitions.

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

#if !defined(XMLPP_XML_TEXT)
#define XMLPP_XML_TEXT TRUE

#include "../common.h"
#include "child.h"

namespace xmlpp {

/// @brief DOMText child node.
class DOMText : public DOMChildNode
{
  public:
    /// @brief  Create the text node with the given value.
    ///
    /// @param  text  The node's value.
    DOMText (std::string text);

    /// @brief  Create the text node with the given value.
    ///
    /// @param  text  The node's value.
    DOMText (const char* text);

    /// @brief  Get the node's name.
    ///
    /// @return "#text"
    std::string nodeName (void);

    /// @brief  Get the node's value. 
    ///
    /// @return  The node's value.
    std::string nodeValue (void);

    /// @brief  Set the node value.
    ///
    /// @param  value  The text to set.
    void nodeValue (std::string value);

    /// @brief  Set the node value.
    ///
    /// @param  value  The text to set.
    void nodeValue (const char* value);

    /// @brief  Another name for the nodeValue method.
    ///
    /// @return  The text from the node.
    std::string data (void);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    void setAttribute (std::string attributeName, std::string attributeValue) {};
    void setAttribute (const char* attributeName, const char* attributeValue) {};
    std::string getAttribute (std::string attributeName) {};
    std::string getAttribute (const char* attributeName) {};
    void removeAttribute (std::string attributeName) {};
    void removeAttribute (const char* attrbuteName) {};

    void appendChild (DOMChildNode* childNode) {};
    void insertBefore (DOMChildNode* childNode, DOMChildNode* nodeAfter) {};
    void replaceChild (DOMChildNode* newChild, DOMChildNode* oldChild) {};
    void removeChild (int childNode) {};
    void removeChild (DOMChildNode* childNode) {};
    DOMChildNode* childNodes (int childNode) {};
    DOMChildNode* firstChild (void) {};
    DOMChildNode* lastChild (void) {};
    #endif

    /// @brief Clonde the text node.
    ///
    /// @return  The pointer to the cloned DOMText.
    DOMChildNode* cloneNode (bool cloneChildren = true);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    DOMChildNode* __getElementById (std::string id);
    DOMChildNode* __getElementById (const char* id);
    DOMChildNodes getElementsByTagName (std::string tagName);
    DOMChildNodes getElementsByTagName (const char* tagName);
    bool hasChildNodes (void) {};
    #endif
};

};

#endif
