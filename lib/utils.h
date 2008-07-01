/// @file utils.h
/// @brief This file includes the utils definitions.

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

#include "common.h"

#if !defined XMLPP_UTILS_HEADER
#define XMLPP_UTILS_HEADER TRUE

namespace xmlpp {
    namespace utils {
        /// @brief  Escape all the slashes in a string.
        ///
        /// @param  text  The string to add slashes to.
        ///
        /// @return  The fully escaped string.
        std::string escapeSlashes (std::string text);

        /// @brief  PHP-like addslashes()
        ///
        /// @param  text  The text to escape.
        ///
        /// @return  The slashed string.
        std::string addSlashes (std::string text);

        /// @brief  Unescapes html special chars.
        ///
        /// @param  text  The string with the beginning of the special char.
        ///
        /// @return  The unescaped char.
        std::string unescapeChar (std::string text);

        /// @brief Check if the char is a 'space' (space, \n, \r, \t).
        ///
        /// @param  text  The char to check.
        ///
        /// @return  True if it's a space.
        ///          False if it's not.
        bool isSpace (const char text);

        /// @brief  Get the special chars associative array.
        ///
        /// @return  The map with all the special chars.
        std::map<std::string, std::string> getSpecialChars (void);

        /// @brief  Get the uppercase string.
        ///
        /// @param  text  The string that will be uppercased.
        ///
        /// @return  The uppercase string.
        std::string toUppercase (std::string text);

        /// @brief  Strip the passed chars from the string.
        ///
        /// @param  chars   The chars to strip.
        /// @param  string  The string to strip from.
        ///
        /// @return  The stripped string.
        std::string strip (const char* chars, std::string string);
    };
};

#endif

