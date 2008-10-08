/****************************************************************************
* XML++ is a library for working with XML files.                            *
* Copyleft meh.                                                             *
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

#if !defined (XMLPP_DOMEXCEPTION_H)
#define XMLPP_DOMEXCEPTION_H 

#include "../common.h"

namespace xmlpp {

namespace DOM {

class DOMException : public std::exception
{
  public:
    /// @brief  If index or size is negative, or greater than the allowed value.
    static const unsigned short INDEX_SIZE_ERR = 1;

    /// @brief  If the specified range of text does not fit into a DOMString.
    static const unsigned short DOMSTRING_SIZE_ERR = 2;

    /// @brief  If any node is inserted somewhere it doesn't belong.
    static const unsigned short HIERARCHY_REQUEST_ERR = 3;

    /// @brief  If a node is used in a different document than the one that
    ///         created it (that doesn't support it).
    static const unsigned short WRONG_DOCUMENT_ERR = 4;

    /// @brief  If an invalid or illegal character is specified, such as in a name.
    static const unsigned short INVALID_CHARACTER_ERR = 5;

    /// @brief  If data is specified for a node which does not support data.
    static const unsigned short NO_DATA_ALLOWED_ERR = 6;

    /// @brief  If an attempt is made to modify an object where modifications
    ///         are not allowed.
    static const unsigned short NO_MODIFICATION_ALLOWED_ERR = 7;

    /// @brief  If an attempt is made to reference a node in a context where it
    ///         does not exist.
    static const unsigned short NOT_FOUND_ERR = 8;

    /// @brief  If the implementation does not support the requested type of
    ///         object or operation.
    static const unsigned short NOT_SUPPORTED_ERR = 9;

    /// @brief  If an attempt is made to add an attribute that is already in use
    ///         elsewhere.
    static const unsigned short INUSE_ATTRIBUTE_ERR = 10;

    /// @brief  If an attempt is made to use an object that is not, or is no
    ///         longer, usable.
    static const unsigned short INVALID_STATE_ERR = 11;

    /// @brief  If an invalid or illegal string is specified.
    static const unsigned short SYNTAX_ERR = 12;

    /// @brief  If an attempt is made to modify the type of the underlying object.
    static const unsigned short INVALID_MODIFICATION_ERR = 13;

    /// @brief  If an attempt is made to create or change an object in a way which
    ///         is incorrect with regard to namespaces.
    static const unsigned short NAMESPACE_ERR = 14;

    /// @brief  If a parameter or an operation is not supported by the underlying
    ///         object.
    static const unsigned short INVALID_ACCESS_ERR = 15;

    /// @brief  If a call to a method such as insertBefore or removeChild would
    ///         make the Node invalid.
    static const unsigned short VALIDATION_ERR = 16;

  public:
    DOMException (int code);
    ~DOMException (void) throw() {};
    
    virtual const char* what() const throw();
    
  private:
    std::string _description;
};

};

};

#endif
