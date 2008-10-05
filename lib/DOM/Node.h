/// @file dom/Node.h
/// @brief This file includes the DOM child definitions.

/****************************************************************************
* XML++ is a library for working with XML files.                            *
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
#include "DOMNamedNodeMap.h"

namespace xmlpp {

namespace DOM {

/// @brief Node class, the base class for everything.
class Node 
{
  public:
   static const NodeType  ELEMENT_NODE                 = 1;
   static const NodeType  ATTRIBUTE_NODE               = 2;
   static const NodeType  TEXT_NODE                    = 3;
   static const NodeType  CDATA_SECTION_NODE           = 4;
   static const NodeType  ENTITY_REFERENCE_NODE        = 5;
   static const NodeType  ENTITY_NODE                  = 6;
   static const NodeType  PROCESSING_INSTRUCTION_NODE  = 7;
   static const NodeType  COMMENT_NODE                 = 8;
   static const NodeType  DOCUMENT_NODE                = 9;
   static const NodeType  DOCUMENT_TYPE_NODE           = 10;
   static const NodeType  DOCUMENT_FRAGMENT_NODE       = 11;
   static const NodeType  NOTATION_NODE                = 12;

   static const DOMDocumentPosition  DOCUMENT_POSITION_DISCONNECTED = 0x01;
   static const DOMDocumentPosition  DOCUMENT_POSITION_PRECEDING    = 0x02;
   static const DOMDocumentPosition  DOCUMENT_POSITION_FOLLOWING    = 0x04;
   static const DOMDocumentPosition  DOCUMENT_POSITION_CONTAINS     = 0x08;
   static const DOMDocumentPosition  DOCUMENT_POSITION_IS_CONTAINED = 0x10;
   static const DOMDocumentPosition  DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20;

  public:
    /// @brief  Get the node's name.
    ///
    /// @return  The node's name.
    virtual std::string nodeName (void);

    /// @brief  Get the node's value (text)
    ///
    /// @return  The node's value if it's a DOMText or nothing if it's a DOMElement.
    virtual std::string nodeValue (void) throw();
    virtual void nodeValue (const char* value) throw();
    virtual void nodeValue (const std::string& value) throw();

    /// @brief  Get the node's type.
    ///
    /// @return  The type. document | element | text
    NodeType nodeType (void);

    /// @brief  Get the vector.
    ///
    /// @return  The vector with the child nodes.
    virtual NodeList childNodes (void) = 0;

    /// @brief  Get the attributes. 
    ///
    /// @return  The attributes map
    virtual DOMNamedNodeMap attributes (void);
    
    /// @brief  Remove an attribute from the node.
    ///
    /// @param  attributeName  The attribute's name to remove.
    virtual void removeAttribute (DOMString attributeName) = 0;

    /// @brief  Remove an attribute from the node.
    ///
    /// @param  attributeName  The attribute's name to remove.
    virtual void removeAttribute (const char* attributeName) = 0;

    /// @brief  Append a child to a DOMElement.
    ///
    /// @param  childNode  The pointer to the child to append.
    virtual void appendChild (Node* childNode) = 0;

    /// @brief  Insert a child before another child.
    ///
    /// @param  childNode  The pointer to the child to insert.
    /// @param  nodeAfter  The pointer to the child that you want to insert the child before.
    virtual void insertBefore (Node* childNode, Node* nodeAfter) = 0;

    /// @brief  Replace a child with another.
    ///
    /// @param  newChild  The pointer to the child to put in the node.
    /// @param  oldChild  The pointer to the child to replace.
    virtual void replaceChild (Node* newChild, Node* oldChild) = 0;

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The node number.
    virtual void removeChild (int childNode) = 0;

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The pointer to the node that you want to delete.
    virtual void removeChild (Node* childNode) = 0;

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
    virtual Node* childNodes (int childNode) = 0;

    /// @brief  Get the first child of the node.
    ///
    /// @return  The pointer to the first child.
    virtual Node* firstChild (void) = 0;

    /// @brief  Get the last child of the node.
    ///
    /// @return  The pointer to the last child.
    virtual Node* lastChild (void) = 0;

    /// @brief  Clone a node with or without the children.
    ///
    /// @param  cloneChildren  True if you want to clone the children too.
    ///                        False if you want to clone only the node.
    virtual Node* cloneNode (bool cloneChildren = true) = 0;

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    virtual NodeList getElementsByTagName (std::string tagName) = 0;

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    virtual NodeList getElementsByTagName (const char* tagName) = 0;

    /// @brief  Get the node's parent.
    ///
    /// @return  The pointer to the parent.
    Node* parentNode (void);

    /// @brief  Get the next sibling.
    ///
    /// @return  The pointer to the next sibling if it exists, NULL if it doesn't.
    Node* nextSibling (void);

    /// @brief  Get the previous sibling.
    ///
    /// @return  The pointer to the previous sibling if it exists, NULL if it doesn't.
    Node* previousSibling (void);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    virtual Node* __getElementById (std::string id) = 0;
    virtual Node* __getElementById (const char* id) = 0;
    void __setParent (Node* parent);
    void __setNextSibling (Node* sibling);
    void __setPreviousSibling (Node* sibling);
    double __getID (void);
    #endif

    /// @brief  Get if a node is exactly the same as another (checks the unique id of the node).
    ///
    /// @return  True if it's the same.
    bool operator == (Node* element);

    /// @brief  Get if a node is exactly the same as another (checks the unique id of the node).
    ///
    /// @return  True if it's not the same
    bool operator != (Node* element);

    /// @brief  Get if the node is of a certain type.
    ///
    /// @return  True if it's of the passed type.
    bool operator == (NodeType type);

    /// @brief  Get if the node is of a certain type.
    ///
    /// @return  True if it's not of the passed type.  
    bool operator != (NodeType type);

  protected:
    DOMString _name;

    DOMString _value;

    /// @brief The node's type: document | element | text
    NodeType _type;

    /// @brief  The previous sibling.
    Node* _pSibling;

    /// @brief  The next sibling.
    Node* _nSibling;

    /// @brief  The child's parent.
    Node* _parent;
};

/// @brief A vector of pointers to Node.
typedef std::vector<Node*> NodeList;

};

};

#include "element.h"
#include "text.h"

#endif

