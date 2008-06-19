/// @file exception.h
/// @brief This file includes the XML attribute implementations.

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


namespace xmlpp {

class Exception {
  protected:
    std::string description;

  public:
    Exception (void) { };

    Exception(std::string description) {
        this->description = description;
    }

    Exception(const char* description) {
        this->description = description;
    }

    std::string getMessage() {
        return this->description;
    }

};

// XMLException codes.
#define EX_PARSER_FILE_READ_ERROR 1

class XMLException : public Exception
{
  public:
    XMLException (int code) : Exception()
    {
        switch (code) {
            case EX_PARSER_FILE_READ_ERROR:
            this->description = "Error while reading the text file, maybe it doesn't exist.";
            break;
        }
    }
};

// DOMException codes.
#define EX_ATTRIBUTE_MODE_NOT_EXISTENT  1
#define EX_NODE_IS_ELEMENT              2
#define EX_NODE_IS_TEXT                 3

class DOMException : public Exception
{
  public:
    DOMException (int code) : Exception()
    {
        switch (code) {
            case EX_ATTRIBUTE_MODE_NOT_EXISTENT:
            this->description = "The modes are only 'name' or 'value'.";
            break;

            case EX_NODE_IS_ELEMENT:
            this->description = "The node is an element, that method isn't supported.";
            break;

            case EX_NODE_IS_TEXT:
            this->description = "The node is an element, that method isn't supported.";
            break;
        }
    }
};

};

