/// @file xml/element.h
/// @brief This file includes the XML element definitions.

/****************************************************************************
* XML++ is a library to work with XML files.
* Copyright (C) 2008  Paolo D. Galli
*
* This file is part of XML++
*
* XML++ is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#if !defined(XMLPP_XML_ELEMENT)
#define XMLPP_XML_ELEMENT TRUE

#include "../common.h"
#include "attribute.h"

namespace xmlpp {

/// @brief  The XMLElement class contains the element name, attributes and childs.
class XMLElement
{
  private:
    /// @brief  True if the element is initialized (eg. created with the full constructor)
    bool initialized;

    /// @brief  The element name.
    std::string name;

    /// @brief  Plain text view of the element.
    std::string plainText;

    /// @brief  Map with the attributes.
    XMLAttributes attributes;

  public:
    /// @brief  Create the element without initalizing it.
    XMLElement (void);

    /// @brief  Create the element with initialization.
    ///
    /// @param  elementName  The element's name (aka tag name)
    XMLElement (std::string elementName);

    /// @brief  Create the element with initialization.
    ///
    /// @param  elementName  The element's name (aka tag name)
    XMLElement (const char* elementName);

    // Setters.

    /// @brief  Set the element's name.
    ///
    /// @param  elementName  The element's name.
    void setName (std::string elementName);

    /// @brief  Set the element's name.
    ///
    /// @param  elementName  The element's name.
    void setName (const char* elementName);

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

    /// @brief  Get the element's name.
    ///
    /// @return  The element's name
    std::string getName (void);

    /// @brief  Get an attribute.
    ///
    /// @param  attributeName  The attribute's name.
    ///
    /// @return  The attribute object.
    XMLAttribute getAttribute (std::string attributeName);

    /// @brief  Get an attribute.
    ///
    /// @param  attributeName  The attribute's name.
    ///
    /// @return  The attribute object.
    XMLAttribute getAttribute (const char* attributeName);

    /// @brief  Get if the element is initialized or not.
    ///
    /// @return  True if the element is initialized.
    bool isInitialized (void);

    // Misc.
    bool hasAttribute (std::string attributeName);
    bool hasAttribute (const char* attributeName);
};

};

#endif
