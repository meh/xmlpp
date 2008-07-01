/// @file dom/attribute.h
/// @brief This file includes the XML attribute definitions.

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

#if !defined(XMLPP_DOM_ATTRIBUTE)
#define XMLPP_DOM_ATTRIBUTE TRUE

#include "../common.h"

namespace xmlpp {

/// @brief  Class for the attributes of an element.
class DOMAttribute
{
  private:
    /// @brief  The attribute name.
    std::string _name;

    /// @brief  The attribute value.
    std::string _value;

  public:
    /// @brief  Create the attribute with initialization.
    ///
    /// @param  attributeName   The attribute's name.
    /// @param  attributeValue  The attribute's value. 
    DOMAttribute (std::string attributeName, std::string attributeValue);

    /// @brief  Create the attribute with initialization.
    ///
    /// @param  attributeName  The attribute's name (aka tag name)
    /// @param  attributeValue  The attribute's value.
    DOMAttribute (const char* attributeName, const char* attributeValue);

    /// @brief  Get the attribute name.
    ///
    /// @return  The attribute's name.
    std::string nodeName (void);

    /// @brief  Set the attribute's name.
    ///
    /// @param  attributeName  The attribute's name.
    void nodeName (std::string attributeName);

    /// @brief  Set the attribute's name.
    ///
    /// @param  attributeName  The attribute's name.
    void nodeName (const char* attributeName);

    /// @brief  Get the attribute value.
    ///
    /// @return  The attribute's value.
    std::string nodeValue (void);

    /// @brief  Set the attribute's value.
    ///
    /// @param  attributeValue  The attribute's value.
    void nodeValue (std::string attributeValue);

    /// @brief  Set the attribute's value.
    ///
    /// @param  attributeValue  The attribute's value.
    void nodeValue (const char* attributeValue);
    
    /// @brief  Updates the plain text version of the attribute.
    std::string plain (void);

    // Operators.
    std::string operator [] (const char* mode) throw();
};

typedef std::map<std::string, DOMAttribute*> DOMAttributes;

};

#endif
