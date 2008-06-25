/// @file dom/child.h
/// @brief This file includes the DOM child definitions.

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

#if !defined(XMLPP_DOM_CHILD)
#define XMLPP_DOM_CHILD TRUE

#include "../common.h"
#include "dom.h"

#define DOM_NODE_ELEMENT  1
#define DOM_NODE_TEXT     3

namespace xmlpp {

/// @brief DOMChildNode class, the base abstract class for DOMText and DOMElement.
class DOMChildNode : public DOM
{
  protected:
    /// @brief The node's type: DOM_ELEMENT_NODE or DOM_TEXT_NODE
    DOMNodeType type;

    /// @brief  Node's name.
    std::string name;

    /// @brief  Node's value.
    std::string value;

    /// @brief  Plain text view of the node.
    std::string plainText;

    /// @brief  The previous sibling.
    DOMChildNode* pSibling;

    /// @brief  The next sibling.
    DOMChildNode* nSibling;

    /// @brief  The child's parent.
    DOM* parent;

  public:
    typedef std::vector<DOMChildNode*> DOMChildNodes;

    /// @brief  Create the node.
    ///
    /// @param  type  The node's type. DOM_ELEMENT_NODE and DOM_TEXT_NODE
    DOMChildNode (DOMNodeType type);

    // Getters.

    /// @brief  Get the node's type.
    ///
    /// @return  The type. DOM_ELEMENT_NODE or DOM_TEXT_NODE
    DOMNodeType nodeType (void);

    /// @brief  Get the node's name.
    ///
    /// @return  The node's name if it's a DOMElement or "#text" if it's a DOMText.
    virtual std::string nodeName (void) = 0;

    /// @brief  Get the node's value (text)
    ///
    /// @return  The node's value if it's a DOMText or nothing if it's a DOMElement.
    virtual std::string nodeValue (void) = 0;

    /// @brief  Set the node value.
    ///
    /// @param  value  The text for the DOMText node.
    virtual void nodeValue (std::string value) = 0;

    /// @brief  Set the node value.
    ///
    /// @param  value  The text for the DOMText node.
    virtual void nodeValue (const char* value) = 0;

    /// @brief  Another name for the nodeValue method.
    ///
    /// @return  The node's value if it's a DOMText or nothing if it's a DOMElement.
    virtual std::string data (void) = 0;

    /// @brief  Get the element's id.
    ///
    /// @return  The element's id.
    virtual std::string id (void) = 0;

    /// @brief  Set the element's id.
    ///
    /// @param  id  The new id.
    virtual void id (std::string id) = 0;

    /// @brief  Set the element's id.
    ///
    /// @param  id  The new id.
    virtual void id (const char* id) = 0;

    /// @brief  Add an attribute to a DOMElement.
    ///
    /// @param  attributeName   The attribute name.
    /// @param  attributeValue  The attribute value.
    virtual void setAttribute (std::string attributeName, std::string attributeValue) = 0;

    /// @brief  Add an attribute to a DOMElement.
    ///
    /// @param  attributeName   The attribute name.
    /// @param  attributeValue  The attribute value.
    virtual void setAttribute (const char* attributeName, const char* attributeValue) = 0;

    /// @brief  Get an attribute from the DOMElement.
    ///
    /// @param  attributeName  The attribute name.
    ///
    /// @return  The attribute value.
    virtual std::string getAttribute (std::string attributeName) = 0;

    /// @brief  Get an attribute from the DOMElement.
    ///
    /// @param  attributeName  The attribute name.
    ///
    /// @return  The attribute value.
    virtual std::string getAttribute (const char* attributeName) = 0;
    
    /// @brief  Remove an attribute from the node.
    ///
    /// @param  attributeName  The attribute's name to remove.
    virtual void removeAttribute (std::string attributeName) = 0;

    /// @brief  Remove an attribute from the node.
    ///
    /// @param  attributeName  The attribute's name to remove.
    virtual void removeAttribute (const char* attributeName) = 0;

    /// @brief  Append a child to a DOMElement.
    ///
    /// @param  childNode  The pointer to the child to append.
    virtual void appendChild (DOMChildNode* childNode) = 0;

    /// @brief  Insert a child before another child.
    ///
    /// @param  childNode  The pointer to the child to insert.
    /// @param  nodeAfter  The pointer to the child that you want to insert the child before.
    virtual void insertBefore (DOMChildNode* childNode, DOMChildNode* nodeAfter) = 0;

    /// @brief  Replace a child with another.
    ///
    /// @param  newChild  The pointer to the child to put in the node.
    /// @param  oldChild  The pointer to the child to replace.
    virtual void replaceChild (DOMChildNode* newChild, DOMChildNode* oldChild) = 0;

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The node number.
    virtual void removeChild (int childNode) = 0;

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The pointer to the node that you want to delete.
    virtual void removeChild (DOMChildNode* childNode) = 0;

    /// @brief  Say if a node has children or not.
    ///
    /// @return True if the node has children.
    ///         False if not.
    virtual bool hasChildNodes (void) = 0;

    /// @brief  Get a child node.
    ///
    /// @param  childNode  The child number in the vector.
    /// 
    /// @return  The pointer to the child.
    virtual DOMChildNode* childNodes (int childNode) = 0;

    /// @brief  Get the first child of the node.
    ///
    /// @return  The pointer to the first child.
    virtual DOMChildNode* firstChild (void) = 0;

    /// @brief  Get the last child of the node.
    ///
    /// @return  The pointer to the last child.
    virtual DOMChildNode* lastChild (void) = 0;

    /// @brief  Clone a node with or without the children.
    ///
    /// @param  cloneChildren  True if you want to clone the children too.
    ///                        False if you want to clone only the node.
    virtual DOMChildNode* cloneNode (bool cloneChildren = true) = 0;

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    virtual DOMChildNodes getElementsByTagName (std::string tagName) = 0;

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    virtual DOMChildNodes getElementsByTagName (const char* tagName) = 0;

    /// @brief  Get the node's parent.
    ///
    /// @return  The pointer to the parent.
    DOM* parentNode (void);

    /// @brief  Get the next sibling.
    ///
    /// @return  The pointer to the next sibling if it exists, NULL if it doesn't.
    DOMChildNode* nextSibling (void);

    /// @brief  Get the previous sibling.
    ///
    /// @return  The pointer to the previous sibling if it exists, NULL if it doesn't.
    DOMChildNode* previousSibling (void);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    virtual DOMChildNode* __getElementById (std::string id) = 0;
    virtual DOMChildNode* __getElementById (const char* id) = 0;
    void __setParent (DOM* parent);
    void __setNextSibling (DOMChildNode* sibling);
    void __setPreviousSibling (DOMChildNode* sibling);
    #endif
};

/// @brief A vector of pointers to DOMChildNode.
typedef std::vector<DOMChildNode*> DOMChildNodes;

};

#endif

