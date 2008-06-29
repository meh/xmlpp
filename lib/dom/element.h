/// @file dom/element.h
/// @brief This file includes the XML element definitions.

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
* WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
****************************************************************************/

#if !defined(XMLPP_XML_ELEMENT)
#define XMLPP_XML_ELEMENT TRUE

#include "../common.h"
#include "child.h"
#include "text.h"
#include "attribute.h"

namespace xmlpp {

/// @brief  The DOMElement class, childnodes, attributes etc.
class DOMElement : public DOMChildNode
{
  private:
    /// @brief  Map with the attributes.
    DOMAttributes attributes;
    
    /// @brief  Child nodes vector (aka childNodes)
    DOMChildNodes children;

  public:
    /// @brief  Create the element with initialization.
    ///
    /// @param  elementName  The element's name (aka tag name)
    DOMElement (std::string elementName);

    /// @brief  Create the element with initialization.
    ///
    /// @param  elementName  The element's name (aka tag name)
    DOMElement (const char* elementName);

    /// @brief  Destroys every children in the node.
    ~DOMElement (void);

    /// @brief  Get plain text of the element.
    ///
    /// @return  The plain text version of the element.
    std::string plain (void);

    /// @brief  Get plain text attributes.
    ///
    /// @return  Plain text attributes.
    std::string plainAttributes (void);

    /// @brief  Get the node's name.
    ///
    /// @return  The node's name.
    std::string nodeName (void);

    /// @brief  Uppercase version of the nodeName if it's an element node.
    ///
    /// @return  The uppercase version of the nodeName.
    std::string tagName (void);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    std::string nodeValue (void) { return (std::string) ""; };
    void nodeValue (const char*) {};
    void nodeValue (std::string) {};
    std::string data (void) { return (std::string) ""; };
    #endif

    /// @brief  Get the element's id.
    ///
    /// @return  The element's id.
    std::string id (void);

    /// @brief  Set the element's id.
    ///
    /// @param  id  The new id.
    void id (std::string newId);

    /// @brief  Set the element's id.
    ///
    /// @param  id  The new id.
    void id (const char* newId);

    /// @brief  Get the element's title.
    ///
    /// @return  The element's title.
    std::string title (void);

    /// @brief  Set the element's title.
    ///
    /// @param  title  The new title.
    void title (std::string title);

    /// @brief  Set the element's title.
    ///
    /// @param  title  The new title.
    void title (const char* title);

    /// @brief  Set an attribute to the element.
    ///
    /// @param  attributeName   The attribute's name.
    /// @param  attributeValue  The attribute's value.
    void setAttribute (std::string attributeName, std::string attributeValue);

    /// @brief  Set an attribute to the element.
    ///
    /// @param  attributeName   The attribute's name.
    /// @param  attributeValue  The attribute's value.
    void setAttribute (const char* attributeName, const char* attributeValue);

    /// @brief  Get an attribute.
    ///
    /// @param  attributeName  The attribute's name.
    ///
    /// @return  The attribute value.
    std::string getAttribute (std::string attributeName);

    /// @brief  Get an attribute.
    ///
    /// @param  attributeName  The attribute's name.
    ///
    /// @return  The attribute value.
    std::string getAttribute (const char* attributeName);

    /// @brief  Remove an attribute from the node.
    ///
    /// @param  attributeName  The attribute's name to remove.
    void removeAttribute (std::string attributeName);

    /// @brief  Remove an attribute from the node.
    ///
    /// @param  attributeName  The attribute's name to remove.
    void removeAttribute (const char* attributeName);

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

    /// @brief  Say if a node has children or not.
    ///
    /// @return True if the node has children.
    ///         False if not.
    bool hasChildNodes (void);

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

    /// @brief  Clone a node with or without the children.
    ///
    /// @param  cloneChildren  True if you want to clone the children too.
    ///                        False if you want to clone only the node.
    DOMChildNode* cloneNode (bool cloneChildren = true);

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
    DOMChildNode* __getElementById (std::string id);
    DOMChildNode* __getElementById (const char* id);
    #endif
};

};

#endif
