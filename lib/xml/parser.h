/// @file   xml/parser.h
/// @brief  This file includes the XML parser definitions.

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

#include "../common.h"
#include "../dom.h"

namespace xmlpp {

struct FetchedNode
{
    size_t point;
    std::string text;
};

/// @brief  The XMLParser class parses a xml file or string and prepares the XML
///         object.
class XMLParser
{
  private:
    /// @brief  Plain text of the string to parse.
    std::string plainText;

    /// @brief  The DOM object.
    DOM* documentObj;

    /// @brief  Gets the XMLParser file.
    ///
    /// @param  xmlString  The filename or the string.
    /// @param  parseMode  The parse modes:
    ///                    XMLParser_FILE to parse from file.
    ///                    XMLParser_STRING to parse from string.
    ///
    /// @return  The plain text.
    std::string fetch (std::string xmlString);

    /// @brief  Parses the text passed.
    ///
    /// @param  xml  The text to parse.
    ///
    /// @return  The DOM object.
    DOM* parseDocument (std::string xml);
    DOMChildNode* parseNode (std::string xml);
    FetchedNode* fetchNode (size_t start, std::string xml);

    DOMElement* parseElement (std::string xml);
    std::string cleanElement (std::string element);

    std::string closingTag (std::string tag);

  public:
    /// @brief  Creates the XMLParser object.
    XMLParser (void);

    /// @brief  Creates the XMLParser object and parse the given file.
    /// 
    /// @param  xmlFile  The filename.
    XMLParser (std::string xmlFile);

    /// @brief  Creates the XMLParser object and parse the given file.
    /// 
    /// @param  xmlFile  The filename.
    XMLParser (const char* xmlFile);

    /// @brief  Parse an xml file.
    /// 
    /// @param  xmlFile  The xml file.
    ///
    /// @return  The DOM document.
    DOM* parseFromFile (std::string xmlFile);

    /// @brief  Parse an xml file.
    /// 
    /// @param  xmlFile  The xml file.
    ///
    /// @return  The DOM document.
    DOM* parseFromFile (const char* xmlFile);

    /// @brief  Parses the text passed.
    ///
    /// @param  xmlText  The text to parse.
    ///
    /// @return  The DOM object.
    DOM* parseFromString (std::string xmlText);

    /// @brief  Parses the text passed.
    ///
    /// @param  xmlText  The text to parse.
    ///
    /// @return  The DOM object.
    DOM* parseFromString (const char* xmlText);

    /// @brief  Gets the last parsed XML document.
    ///
    /// @return  The last DOM object.
    DOM* document (void);

    /// @brief Gets the last parsed plain text.
    ///
    /// @return The last plain text document.
    std::string plain (void);
};

};

