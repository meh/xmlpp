/// @file   xml.h
/// @brief  This file includes the DOM parser definitions.

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
 ***************************************************************************/

#include "common.h"

#if !defined(XMLPP_XML)
#include "xml.h"
#endif

namespace xmlpp {

/// @brief  The DOMParser class parses a xml file or string and prepares the DOM
///         object.
class DOMParser
{
  private:
    /// @brief  Plain text of the string to parse.
    std::string plainText;

    /// @brief  The XML object.
    XML* xmlDocument;

    /// @brief  Gets the DOMParser file.
    ///
    /// @param  xmlString  The filename or the string.
    /// @param  parseMode  The parse modes:
    ///                    DOMParser_FILE to parse from file.
    ///                    DOMParser_STRING to parse from string.
    ///
    /// @return  The plain text.
    std::string fetch (std::string xmlString);

    /// @brief  Parses the text passed.
    ///
    /// @param  The text to parse.
    ///
    /// @return  The XML object.
    XML* parse (std::string xmlText);

  public:
    /// @brief  Creates the DOMParser object.
    DOMParser (void);

    /// @brief  Creates the DOMParser object and parse the given file.
    /// 
    /// @param  xmlFile  The filename.
    DOMParser (std::string xmlFile);

    /// @brief  Creates the DOMParser object and parse the given file.
    /// 
    /// @param  xmlFile  The filename.
    DOMParser (const char* xmlFile);

    XML* parseFromFile (std::string xmlText);
    XML* parseFromFile (const char* xmlText);

    /// @brief  Parses the text passed.
    ///
    /// @param  The text to parse.
    ///
    /// @return  The XML object.
    XML* parseFromString (std::string xmlText);

    /// @brief  Parses the text passed.
    ///
    /// @param  The text to parse.
    ///
    /// @return  The XML object.
    XML* parseFromString (const char* xmlText);

    /// @brief Gets the last parsed plain text.
    ///
    /// @return The last plain text document.
    std::string plain (void);

    /// @brief  Gets the last parsed XML document.
    ///
    /// @return  The last XML object.
    XML* document (void);
};

};

