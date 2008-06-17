/// @file xml/attribute.h
/// @brief This file includes the XML attribute definitions.

/****************************************************************************
* XML++ is a library to work with XML files.                                *
* Copyright (C) 2008  Paolo D. Galli                                        *
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
    /// @brief  True if the attribute is initialized (eg. created with the full constructor)
    bool initialized;

    /// @brief  The attribute name.
    std::string attributeName;

    /// @brief  The attribute value.
    std::string attributeValue;

    /// @brief  Plain text of the attribute.
    std::string plainText;

  public:
    /// @brief  Create the attribute without initalizing it.
    DOMAttribute ();

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

    // Setters.

    /// @brief  Set the attribute's name.
    ///
    /// @param  attributeName  The attribute's name.
    void setName (std::string attributeName);

    /// @brief  Set the attribute's name.
    ///
    /// @param  attributeName  The attribute's name.
    void setName (const char* attributeName);

    /// @brief  Set the attribute's value.
    ///
    /// @param  attributeValue  The attribute's value.
    void setValue (std::string attributeValue);

    /// @brief  Set the attribute's value.
    ///
    /// @param  attributeValue  The attribute's value.
    void setValue (const char* attributeValue);

    // Getters.
    
    /// @brief  Get the attribute's name.
    ///
    /// @return  The attribute's name.
    std::string name (void);

    /// @brief  Get the attribute's value.
    ///
    /// @return  The attribute's value.
    std::string value (void);

    /// @brief  Get the plain text version of the attribute.
    ///
    /// @return  The plain text of the attribute.
    std::string plain (void);

    /// @brief  Get if the attribute is initialized or not.
    ///
    /// @return  True if the attribute is initialized.
    bool isInitialized (void);

    // Misc.
    
    /// @brief  Updates the plain text version of the attribute.
    void updatePlain (void);

    // Operators.
    std::string operator [] (const char* mode) const throw();
};

typedef std::map<std::string, DOMAttribute*> DOMAttributes;

};

#endif
