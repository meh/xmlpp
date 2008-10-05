/// @file dom/DOMNode.h
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

namespace dom {

/// @brief DOMNode class, the base class for everything.
class DOMNode 
{
  public:
   const static DOMNodeType  ELEMENT_NODE                 = 1;
   const static DOMNodeType  ATTRIBUTE_NODE               = 2;
   const static DOMNodeType  TEXT_NODE                    = 3;
   const static DOMNodeType  CDATA_SECTION_NODE           = 4;
   const static DOMNodeType  ENTITY_REFERENCE_NODE        = 5;
   const static DOMNodeType  ENTITY_NODE                  = 6;
   const static DOMNodeType  PROCESSING_INSTRUCTION_NODE  = 7;
   const static DOMNodeType  COMMENT_NODE                 = 8;
   const static DOMNodeType  DOCUMENT_NODE                = 9;
   const static DOMNodeType  DOCUMENT_TYPE_NODE           = 10;
   const static DOMNodeType  DOCUMENT_FRAGMENT_NODE       = 11;
   const static DOMNodeType  NOTATION_NODE                = 12;

   const static DOMDocumentPosition  DOCUMENT_POSITION_DISCONNECTED = 0x01;
   const static DOMDocumentPosition  DOCUMENT_POSITION_PRECEDING    = 0x02;
   const static DOMDocumentPosition  DOCUMENT_POSITION_FOLLOWING    = 0x04;
   const static DOMDocumentPosition  DOCUMENT_POSITION_CONTAINS     = 0x08;
   const static DOMDocumentPosition  DOCUMENT_POSITION_IS_CONTAINED = 0x10;
   const static DOMDocumentPosition  DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20;

  public:
    typedef std::vector<DOMNode*> DOMNodeList;

    /// @brief  Get plain text of the element.
    ///
    /// @return  The plain text version of the element.
    virtual std::string plain (void) = 0;

    /// @brief  Get the node's name.
    ///
    /// @return  The node's name if it's a DOMElement or "#text" if it's a DOMText.
    virtual std::string nodeName (void);

    /// @brief  Get the node's value (text)
    ///
    /// @return  The node's value if it's a DOMText or nothing if it's a DOMElement.
    virtual std::string nodeValue (void) throw();

    /// @brief  Get the node's type.
    ///
    /// @return  The type. document | element | text
    DOMNodeType nodeType (void);

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
    virtual DOMNodeList childNodes (void) = 0;

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
    virtual DOMNodeList getElementsByTagName (std::string tagName) = 0;

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    virtual DOMNodeList getElementsByTagName (const char* tagName) = 0;

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

  protected:
    DOMString _name;

    DOMString _value;

    /// @brief The node's type: document | element | text
    DOMNodeType _type;

    /// @brief  The previous sibling.
    DOMNode* _pSibling;

    /// @brief  The next sibling.
    DOMNode* _nSibling;

    /// @brief  The child's parent.
    DOMNode* _parent;
};

/// @brief A vector of pointers to DOMNode.
typedef std::vector<DOMNode*> DOMNodeList;

};

};

#include "element.h"
#include "text.h"

#endif

