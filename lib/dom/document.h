/// @file   dom/document.h
/// @brief  This file includes the XML object definitions.

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

#if !defined(XMLPP_DOM_DOCUMENT)
#define XMLPP_DOM_DOCUMENT TRUE

#include "../common.h"
#include "child.h"
#include "element.h"
#include "text.h"

namespace xmlpp {

/// @brief DOM document class.
class DOM : public DOMChildNode
{
  private:
    /// @brief  The plain text version of the document.
    std::string document;

    /// @brief Vector with the child nodes.
    DOMChildNodes children;

  public:
    DOM () : DOMChildNode (DOM_DOCUMENT) {};
    /// @brief  Says if the document is empty or not.
    ///
    /// @return  True if it's empty.
    ///          False if it isn't.
    bool empty (void);

    /// @brief  Get the plain text version of the document.
    /// 
    /// @return  The plain text document.
    std::string documentElement (void);

    /// @brief  Append a child to a DOMElement.
    ///
    /// @param  childNode  The pointer to the child to append.
    void appendChild (DOMChildNode* childNode);

    /// @brief  Insert a child before another child.
    ///
    /// @param  childNode  The pointer to the child to insert.
    /// @param  nodeAfter  The pointer to the child that you want to insert the child before.
    void insertBefore (DOMChildNode* childNode, DOMChildNode* nodeAfter);

    /// @brief  Replace a child with another.
    ///
    /// @param  newChild  The pointer to the child to put in the node.
    /// @param  oldChild  The pointer to the child to replace.
    void replaceChild (DOMChildNode* newChild, DOMChildNode* oldChild);

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The node number.
    void removeChild (int childNode);

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The pointer to the node that you want to delete.
    void removeChild (DOMChildNode* childNode);

    /// @brief  Get a child node.
    ///
    /// @param  childNode  The child number in the vector.
    /// 
    /// @return  The pointer to the child.
    DOMChildNode* childNodes (int childNode);

    /// @brief  Get the first child of the node.
    ///
    /// @return  The pointer to the first child.
    DOMChildNode* firstChild (void);

    /// @brief  Get the last child of the node.
    ///
    /// @return  The pointer to the last child.
    DOMChildNode* lastChild (void);

    /// @brief  Get the element with that id.
    ///
    /// @param  id  The id to look for.
    ///
    /// @return  The DOMElement object with that nick.
    DOMChildNode* getElementById (std::string id);

    /// @brief  Get the element with that id.
    ///
    /// @param  id  The id to look for.
    ///
    /// @return  The DOMElement object with that nick.
    DOMChildNode* getElementById (const char* id);

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    DOMChildNodes getElementsByTagName (std::string tagName);

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    DOMChildNodes getElementsByTagName (const char* tagName);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    std::string nodeName (void) {};
    std::string nodeValue (void) {};
    void nodeValue (std::string) {};
    void nodeValue (const char*) {};
    std::string data (void) {};
    void setAttribute (std::string, std::string) {};
    void setAttribute (const char*, const char*) {};
    std::string getAttribute (std::string) {};
    std::string getAttribute (const char*) {};
    void removeAttribute (std::string) {};
    void removeAttribute (const char*) {};
    bool hasChildNodes (void) {};
    DOMChildNode* __getElementById (std::string) {};
    DOMChildNode* __getElementById (const char*) {};
    DOMChildNode* cloneNode (bool) {};
    #endif
};

};

#endif
