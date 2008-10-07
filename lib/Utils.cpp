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

#include "Utils.h"

namespace xmlpp {

namespace Utils {
    std::string escapeSlashes (std::string& text)
    {
        std::string escaped = "";

        for (size_t i = 0; i < text.length(); i++) {
            if (text[i] == '\\') {
                escaped.append(1, '\\');
            }

            escaped.append(1, text[i]);
        }

        return escaped;
    }

    std::string addSlashes (std::string& text)
    {
        std::string slashed = "";

        for (size_t i = 0; i < text.length(); i++) {
            if (text[i] == '"' || text[i] == '\'' || text[i] == '\\') {
                slashed.append(1, '\\');
            }
        
            slashed.append(1, text[i]);
        }

        return slashed;
    }

    std::string toUppercase (std::string& text)
    {
        std::string upper;

        size_t i;
        for (i = 0; i < text.length(); i++) {
            upper += toupper(text.at(i));
        }

        return upper;
    }

    std::string strip (const char* chars, std::string& string)
    {
        std::string stripped;

        size_t i;
        for (i = 0; i < string.length(); i++) {
            bool write = true;
            size_t h;
            for (h = 0; h < strlen(chars); h++) {
                if (chars[h] == string.at(i)) {
                    write = false;
                    break;
                }
            }

            if (write) {
                stripped += string.at(i);
            }
        }

        return stripped;
    }
};

};

