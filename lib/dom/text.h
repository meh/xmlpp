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

    /// @brief  Get plain text of the element.
    ///
    /// @return  The plain text version of the element.
    std::string plain (void);

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
    std::string tagName (void) { return (std::string) ""; };
    std::string id (void) { return (std::string) "" ; };
    void id (std::string) {};
    void id (const char*) {};
    std::string title (void) { return (std::string) ""; };
    void title (std::string title) {};
    void title (const char* title) {};

    void setAttribute (std::string, std::string) {};
    void setAttribute (const char*, const char*) {};
    std::string getAttribute (std::string) { return (std::string) ""; };
    std::string getAttribute (const char*) { return (std::string) ""; };
    void removeAttribute (std::string) {};
    void removeAttribute (const char*) {};

    void appendChild (DOMChildNode*) {};
    void insertBefore (DOMChildNode*, DOMChildNode*) {};
    void replaceChild (DOMChildNode*, DOMChildNode*) {};
    void removeChild (int) {};
    void removeChild (DOMChildNode*) {};
    DOMChildNode* childNodes (int);
    DOMChildNode* firstChild (void);
    DOMChildNode* lastChild (void);
    #endif

    /// @brief Clonde the text node.
    ///
    /// @return  The pointer to the cloned DOMText.
    DOMChildNode* cloneNode (bool cloneChildren = true);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    DOMChildNode* __getElementById (std::string id) { return NULL; };
    DOMChildNode* __getElementById (const char* id) { return NULL; };
    DOMChildNodes getElementsByTagName (std::string tagName);
    DOMChildNodes getElementsByTagName (const char* tagName);
    bool hasChildNodes (void);
    #endif
};

};

#endif
