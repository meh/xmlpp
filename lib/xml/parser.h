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
#include "../dom/document.h"
#include "../dom/element.h"
#include "../dom/text.h"

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
    /// @brief  Line number being parsed.
    int _line;

    /// @brief  Gets the XMLParser file.
    ///
    /// @param  xmlString  The filename or the string.
    /// @param  parseMode  The parse modes:
    ///                    XMLParser_FILE to parse from file.
    ///                    XMLParser_STRING to parse from string.
    ///
    /// @return  The plain text.
    std::string _fetch (const char* fileName);

    /// @brief  Parses the text passed.
    ///
    /// @param  xml  The text to parse.
    ///
    /// @return  The DOM object.
    DOMDocument* _parseDocument (std::string xml);

    /// @brief  Parse the node.
    ///
    /// @param  xml  The fetched node.
    ///
    /// @return  The child node.
    DOMNode* _parseNode (std::string xml);

    /// @brief  Fetch the node.
    ///
    /// @param  start  The position in the xml file.
    /// @param  xml    The xml text from the start point.
    ///
    /// @return  The fetched node.
    FetchedNode _fetchNode (size_t start, std::string xml);

    /// @brief  Parse an element and get name and attributes.
    ///
    /// @param  xml  The xml element.
    ///
    /// @return  The element.
    DOMElement* _parseElement (std::string xml);

    /// @brief  Clean the element node (remove spaces etc)
    std::string _cleanElement (std::string element);

    /// @brief  Parse a text node removing spaces and substituting special chars.
    ///
    /// @param  text  The xml text node.
    ///
    /// @return  The text node.
    DOMText* _parseText (std::string text);

    /// @brief  Get the name of the tag that's being closed.
    ///
    /// @param  tag  The raw tag.
    ///
    /// @return  The tag name if it's a valid closing tag or NULL if it's not a tag.
    std::string _closingTag (std::string tag);

    /// @brief  Get the xml version.
    ///
    /// @param  The xml element with the version.
    ///
    /// @return  The version string.
    std::string _getVersion (std::string xml);

  public:
    /// @brief  Parse an xml file.
    /// 
    /// @param  xmlFile  The xml file.
    ///
    /// @return  The DOM document.
    DOMDocument* parseFromFile (std::string xmlFile);

    /// @brief  Parse an xml file.
    /// 
    /// @param  xmlFile  The xml file.
    ///
    /// @return  The DOM document.
    DOMDocument* parseFromFile (const char* xmlFile);

    /// @brief  Parses the text passed.
    ///
    /// @param  xmlText  The text to parse.
    ///
    /// @return  The DOM object.
    DOMDocument* parseFromString (std::string xmlText);

    /// @brief  Parses the text passed.
    ///
    /// @param  xmlText  The text to parse.
    ///
    /// @return  The DOM object.
    DOMDocument* parseFromString (const char* xmlText);

    /// @brief  Gets the last parsed XML document.
    ///
    /// @return  The last DOM object.
    DOMDocument* document (void);

    /// @brief Gets the last parsed plain text.
    ///
    /// @return The last plain text document.
    std::string plain (void);
};

};

