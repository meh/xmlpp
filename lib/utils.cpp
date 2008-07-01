/// @file utils.cpp
/// @brief This file includes the utils implementations.

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

#include "utils.h"

#if !defined XMLPP_UTILS_SOURCE
#define XMLPP_UTILS_SOURCE TRUE

namespace xmlpp {

namespace utils {
    std::string escapeSlashes (std::string text)
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

    std::string addSlashes (std::string text)
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

    std::string unescapeChar (std::string text)
    {
        std::string nText = "&";
        size_t      i = 0;
        while (text[i] != ';') {
            i++;
            nText += text[i];
        }

        std::map<std::string, std::string> specialChars = getSpecialChars();

        std::map<std::string, std::string>::iterator esc;
        for (esc = specialChars.begin(); esc != specialChars.end(); esc++) {
            if ((*esc).first == nText) {
                return (*esc).second;
            }
        }

        return (std::string) "";
    }

    bool isSpace (const char text)
    {
        if (text == ' ' || text == '\n' || text == '\r' || text == '\t') {
            return true;
        }
        else {
            return false;
        }
    }

    std::map<std::string, std::string> getSpecialChars (void)
    {
        static std::map<std::string, std::string> specialChars;

        if (specialChars.empty()) {
            specialChars["&lsquo;"]  = "‘";
            specialChars["&rsquo;"]  = "’";
            specialChars["&sbquo;"]  = "‚";
            specialChars["&ldquo;"]  = "“";
            specialChars["&rdquo;"]  = "”";
            specialChars["&bdquo;"]  = "„";
            specialChars["&dagger;"] = "†";
            specialChars["&Dagger;"] = "‡";
            specialChars["&permil;"] = "‰";
            specialChars["&lsaquo;"] = "‹";
            specialChars["&rsaquo;"] = "›";
            specialChars["&spades;"] = "♠";
            specialChars["&clubs;"]  = "♣";
            specialChars["&hearts;"] = "♥";
            specialChars["&diams;"]  = "♦";
            specialChars["&oline;"]  = "‾";
            specialChars["&larr;"]   = "←";
            specialChars["&uarr;"]   = "↑";
            specialChars["&rarr;"]   = "→";
            specialChars["&darr;"]   = "↓";
            specialChars["&trade;"]  = "™";

            specialChars["&#33;"] = "!";
            specialChars["&#34;"] = specialChars["&quot;"] = "\"";
            specialChars["&#35;"] = "#";
            specialChars["&#36;"] = "$";
            specialChars["&#37;"] = "%";
            specialChars["&#38;"] = specialChars["&amp;"] = "&";
            specialChars["&#39;"] = "'";
            specialChars["&#40;"] = "(";
            specialChars["&#41;"] = "(";
            specialChars["&#42;"] = "*";
            specialChars["&#43;"] = "+";
            specialChars["&#44;"] = ",";
            specialChars["&#45;"] = "-";
            specialChars["&#46;"] = ".";
            specialChars["&#47;"] = specialChars["&frasl;"] = "/";
            specialChars["&#48;"] = "0";
            specialChars["&#49;"] = "1";
            specialChars["&#50;"] = "2";
            specialChars["&#51;"] = "3";
            specialChars["&#52;"] = "4";
            specialChars["&#53;"] = "5";
            specialChars["&#54;"] = "6";
            specialChars["&#55;"] = "7";
            specialChars["&#56;"] = "8";
            specialChars["&#57;"] = "9";
            specialChars["&#58;"] = ":";
            specialChars["&#59;"] = ";";
            specialChars["&#60;"] = specialChars["&lt;"] = "<";
            specialChars["&#61;"] = "=";
            specialChars["&#62;"] = specialChars["&gt;"] = ">";
            specialChars["&#63;"] = "?";
            specialChars["&#64;"] = "@";
            specialChars["&#65;"] = "A";
            specialChars["&ndash;"]  = "–";
            specialChars["&mdash;"]  = "—";
            specialChars["&nbsp;"]   = " ";
            specialChars["&iexcl;"]  = "¡";
            specialChars["&cent;"]   = "¢";
            specialChars["&pound;"]  = "£";
            specialChars["&curren;"] = "¤";
            specialChars["&yen;"]    = "¥";
            specialChars["&brvbar;"] = "¦";
            specialChars["&brkbar;"] = "¦";
            specialChars["&sect;"]   = "§";
            specialChars["&uml;"]    = "¨";
            specialChars["&die;"]    = "¨";
            specialChars["&copy;"]   = "©";
            specialChars["&ordf;"]   = "ª";
            specialChars["&laquo;"]  = "«";
            specialChars["&not;"]    = "¬";
            specialChars["&shy;"]    = "­";
            specialChars["&reg;"]    = "®";
            specialChars["&hibar;"]  = "¯";
            specialChars["&macr;"]   = "¯";
            specialChars["&deg;"]    = "°";
            specialChars["&plusmn;"] = "±";
            specialChars["&sup2;"]   = "²";
            specialChars["&sup3;"]   = "³";
            specialChars["&acute;"]  = "´";
            specialChars["&micro;"]  = "µ";
            specialChars["&para;"]   = "¶";
            specialChars["&middot;"] = "·";
            specialChars["&cedil;"]  = "¸";


            specialChars["&#x2122;"] = "™";
        }

        return specialChars;
    }

    std::string toUppercase (std::string text)
    {
        std::string upper;

        size_t i;
        for (i = 0; i < text.length(); i++) {
            upper += toupper(text.at(i));
        }

        return upper;
    }

    std::string strip (const char* chars, std::string string)
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

#endif

