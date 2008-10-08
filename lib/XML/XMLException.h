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

#if !defined(XMLPP_XML_EXCEPTION_H)
#define XMLPP_XML_EXCEPTION_H

#include <string>

namespace xmlpp {

namespace XML {

class XMLException : public std::exception
{
  public:
    /// @brief  Exception raised if there's an error in read the xml file.
    static const int PARSER_FILE_READ_ERROR = 1;

    /// @brief  Exception raised if the XML file has some errors.
    static const int NOT_STANDARD = 2;

    /// @brief  Exception raised if there's an error in a node.
    static const int BAD_NODE = 3;

    /// @brief  Exception raised if a tag isn't closed.
    static const int TAG_NOT_CLOSED = 4;    

  public:
    XMLException (int code);
    ~XMLException (void) throw();
    
    virtual const char* what() const throw();
    
  private:
    std::string _description;
};

};

}

#endif

