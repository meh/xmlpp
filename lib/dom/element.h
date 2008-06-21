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

/// @brief  The DOMElement class contains the element name, attributes and childs.
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

    ~DOMElement (void);

    /// @brief  Get the node's name.
    ///
    /// @return  The node's name
    std::string nodeName (void);

    /// @brief  Get the node's value.
    ///
    /// @return  The node's value.
    std::string nodeValue (void);
    void nodeValue (const char* value);
    void nodeValue (std::string value);
    
    std::string data (void);

    // Setters.

    /// @brief  Set an attribute to the element.
    ///
    /// @param  attributeName   The attribute's name.
    /// @param  attributeValue  The attribute's value.
    ///
    /// @return  True if the attribute is added.
    bool setAttribute (std::string attributeName, std::string attributeValue);

    /// @brief  Set an attribute to the element.
    ///
    /// @param  attributeName   The attribute's name.
    /// @param  attributeValue  The attribute's value.
    ///
    /// @return  True if the attribute is added.
    bool setAttribute (const char* attributeName, const char* attributeValue);

    // Getters.
    
    /// @brief  Get an attribute.
    ///
    /// @param  attributeName  The attribute's name.
    ///
    /// @return  The attribute object.
    std::string getAttribute (std::string attributeName);

    /// @brief  Get an attribute.
    ///
    /// @param  attributeName  The attribute's name.
    ///
    /// @return  The attribute object.
    std::string getAttribute (const char* attributeName);

    /// @brief  Get if the element is initialized or not.
    ///
    /// @return  True if the element is initialized.
    bool isInitialized (void);

    // Misc.
    bool hasAttribute (std::string attributeName);
    bool hasAttribute (const char* attributeName);

    void appendChild (DOMChildNode* childNode);
    void insertBefore (DOMChildNode* childNode, DOMChildNode* nodeAfter);

    DOMChildNodes childNodes (void);
    DOMChildNode* childNode (int childNode);

    DOMChildNode* cloneNode (bool cloneChildren = true);

    void replaceChild (DOMChildNode* newChild, DOMChildNode* oldChild);

    void removeChild (int childNode);
    void removeChild (DOMChildNode* childNode);

    DOMChildNode* firstChild (void);
    DOMChildNode* lastChild (void);

    /// @ignore
    DOMChildNode* __getElementById (std::string id);
    /// @ignore
    DOMChildNode* __getElementById (const char* id);

    std::vector<DOMChildNode*> getElementsByTagName (std::string tagName);
    std::vector<DOMChildNode*> getElementsByTagName (const char* tagName);

    bool hasChildNodes (void);
};

};

#endif
