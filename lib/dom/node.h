/// @file dom/node.h
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

#if !defined(XMLPP_DOM_NODE)
#define XMLPP_DOM_NODE TRUE

#include "../common.h"

namespace xmlpp {

/// @brief  Enum for node types.
enum DOMNodeType {
    document,
    element,
    text
};

/// @brief DOMNode class, the base abstract class for DOMText and DOMElement.
class DOMNode 
{
  private:
    /// @brief  The unique id to recognize if a node is the same as another.
    double _uniqueID;

  protected:
    /// @brief The node's type: document | element | text
    DOMNodeType _type;

    /// @brief  The previous sibling.
    DOMNode* _pSibling;

    /// @brief  The next sibling.
    DOMNode* _nSibling;

    /// @brief  The child's parent.
    DOMNode* _parent;

  public:
    typedef std::vector<DOMNode*> DOMNodes;

    /// @brief  Create the node.
    ///
    /// @param  type  The node's type. DOM_ELEMENT_NODE and DOM_TEXT_NODE
    DOMNode (DOMNodeType type);

    /// @brief  Get plain text of the element.
    ///
    /// @return  The plain text version of the element.
    virtual std::string plain (void) = 0;

    /// @brief  Get the node's type.
    ///
    /// @return  The type. document | element | text
    DOMNodeType nodeType (void);

    /// @brief  Get the node's name.
    ///
    /// @return  The node's name if it's a DOMElement or "#text" if it's a DOMText.
    virtual std::string nodeName (void) = 0;

    /// @brief  Uppercase version of the nodeName if it's an element node.
    ///
    /// @return  The uppercase version of the nodeName.
    virtual std::string tagName (void) = 0;

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

    /// @brief  Get the element's title.
    ///
    /// @return  The element's title.
    virtual std::string title (void) = 0;

    /// @brief  Set the element's title.
    ///
    /// @param  title  The new title.
    virtual void title (std::string title) = 0;

    /// @brief  Set the element's title.
    ///
    /// @param  title  The new title.
    virtual void title (const char* title) = 0;

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
    virtual void appendChild (DOMNode* childNode) = 0;

    /// @brief  Insert a child before another child.
    ///
    /// @param  childNode  The pointer to the child to insert.
    /// @param  nodeAfter  The pointer to the child that you want to insert the child before.
    virtual void insertBefore (DOMNode* childNode, DOMNode* nodeAfter) = 0;

    /// @brief  Replace a child with another.
    ///
    /// @param  newChild  The pointer to the child to put in the node.
    /// @param  oldChild  The pointer to the child to replace.
    virtual void replaceChild (DOMNode* newChild, DOMNode* oldChild) = 0;

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The node number.
    virtual void removeChild (int childNode) = 0;

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The pointer to the node that you want to delete.
    virtual void removeChild (DOMNode* childNode) = 0;

    /// @brief  Say if a node has children or not.
    ///
    /// @return True if the node has children.
    ///         False if not.
    virtual bool hasChildNodes (void) = 0;

    /// @brief  Get the vector.
    ///
    /// @return  The vector with the child nodes.
    virtual DOMNodes childNodes (void) = 0;

    /// @brief  Get a child node.
    ///
    /// @param  childNode  The child number in the vector.
    /// 
    /// @return  The pointer to the child.
    virtual DOMNode* childNodes (int childNode) = 0;

    /// @brief  Get the first child of the node.
    ///
    /// @return  The pointer to the first child.
    virtual DOMNode* firstChild (void) = 0;

    /// @brief  Get the last child of the node.
    ///
    /// @return  The pointer to the last child.
    virtual DOMNode* lastChild (void) = 0;

    /// @brief  Clone a node with or without the children.
    ///
    /// @param  cloneChildren  True if you want to clone the children too.
    ///                        False if you want to clone only the node.
    virtual DOMNode* cloneNode (bool cloneChildren = true) = 0;

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    virtual DOMNodes getElementsByTagName (std::string tagName) = 0;

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    virtual DOMNodes getElementsByTagName (const char* tagName) = 0;

    /// @brief  Get the node's parent.
    ///
    /// @return  The pointer to the parent.
    DOMNode* parentNode (void);

    /// @brief  Get the next sibling.
    ///
    /// @return  The pointer to the next sibling if it exists, NULL if it doesn't.
    DOMNode* nextSibling (void);

    /// @brief  Get the previous sibling.
    ///
    /// @return  The pointer to the previous sibling if it exists, NULL if it doesn't.
    DOMNode* previousSibling (void);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    virtual DOMNode* __getElementById (std::string id) = 0;
    virtual DOMNode* __getElementById (const char* id) = 0;
    void __setParent (DOMNode* parent);
    void __setNextSibling (DOMNode* sibling);
    void __setPreviousSibling (DOMNode* sibling);
    double __getID (void);
    #endif

    /// @brief  Get if a node is exactly the same as another (checks the unique id of the node).
    ///
    /// @return  True if it's the same.
    bool operator == (DOMNode* element);

    /// @brief  Get if a node is exactly the same as another (checks the unique id of the node).
    ///
    /// @return  True if it's not the same
    bool operator != (DOMNode* element);

    /// @brief  Get if the node is of a certain type.
    ///
    /// @return  True if it's of the passed type.
    bool operator == (DOMNodeType type);

    /// @brief  Get if the node is of a certain type.
    ///
    /// @return  True if it's not of the passed type.  
    bool operator != (DOMNodeType type);
};

/// @brief A vector of pointers to DOMNode.
typedef std::vector<DOMNode*> DOMNodes;

};

#include "element.h"
#include "text.h"

#endif

