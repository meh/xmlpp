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
        std::string nText;
        size_t      i = 0;
        while (i < text.length() && text[i] != ';') {
            nText += text[i];
            i++;
        }
        nText += ";";

        std::map<std::string, std::string> specialChars = getSpecialChars();

        std::map<std::string, std::string>::iterator esc;
        for (esc = specialChars.begin(); esc != specialChars.end(); esc++) {
            if (esc->first == nText) {
                return esc->second;
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
            specialChars["&lsquo;"]   = "‘";
            specialChars["&rsquo;"]   = "’";
            specialChars["&sbquo;"]   = "‚";
            specialChars["&ldquo;"]   = "“";
            specialChars["&rdquo;"]   = "”";
            specialChars["&bdquo;"]   = "„";
            specialChars["&dagger;"]  = "†";
            specialChars["&Dagger;"]  = "‡";
            specialChars["&permil;"]  = "‰";
            specialChars["&lsaquo;"]  = "‹";
            specialChars["&rsaquo;"]  = "›";
            specialChars["&spades;"]  = "♠";
            specialChars["&clubs;"]   = "♣";
            specialChars["&hearts;"]  = "♥";
            specialChars["&diams;"]   = "♦";
            specialChars["&oline;"]   = "‾";
            specialChars["&larr;"]    = "←";
            specialChars["&uarr;"]    = "↑";
            specialChars["&rarr;"]    = "→";
            specialChars["&darr;"]    = "↓";
            specialChars["&trade;"]   = "™";
            specialChars["&quot;"]    = "\"";
            specialChars["&amp;"]     = "&";
            specialChars["&frasl;"]   = "/";
            specialChars["&lt;"]      = "<";
            specialChars["&gt;"]      = ">";
            specialChars["&ndash;"]   = "–";
            specialChars["&mdash;"]   = "—";
            specialChars["&nbsp;"]    = " ";
            specialChars["&iexcl;"]   = "¡";
            specialChars["&cent;"]    = "¢";
            specialChars["&pound;"]   = "£";
            specialChars["&curren;"]  = "¤";
            specialChars["&yen;"]     = "¥";
            specialChars["&brvbar;"]  = "¦";
            specialChars["&brkbar;"]  = "¦";
            specialChars["&sect;"]    = "§";
            specialChars["&uml;"]     = "¨";
            specialChars["&die;"]     = "¨";
            specialChars["&copy;"]    = "©";
            specialChars["&ordf;"]    = "ª";
            specialChars["&laquo;"]   = "«";
            specialChars["&not;"]     = "¬";
            specialChars["&shy;"]     = "­";
            specialChars["&reg;"]     = "®";
            specialChars["&hibar;"]   = "¯";
            specialChars["&macr;"]    = "¯";
            specialChars["&deg;"]     = "°";
            specialChars["&plusmn;"]  = "±";
            specialChars["&sup2;"]    = "²";
            specialChars["&sup3;"]    = "³";
            specialChars["&acute;"]   = "´";
            specialChars["&micro;"]   = "µ";
            specialChars["&para;"]    = "¶";
            specialChars["&middot;"]  = "·";
            specialChars["&cedil;"]   = "¸";
            specialChars["&sup1;"]    = "¹";
            specialChars["&ordm;"]    = "º";
            specialChars["&raquo;"]   = "»";
            specialChars["&frac14;"]  = "¼";
            specialChars["&frac12;"]  = "½";
            specialChars["&frac34;"]  = "¾";
            specialChars["&iquest;"]  = "¿";
            specialChars["&Agrave;"]  = "À";
            specialChars["&Aacute;"]  = "Á";
            specialChars["&Acirc;"]   = "Â";
            specialChars["&Atilde;"]  = "Ã";
            specialChars["&Auml;"]    = "Ä";
            specialChars["&Aring;"]   = "Å";
            specialChars["&AElig;"]   = "Æ";
            specialChars["&Ccedil;"]  = "Ç";
            specialChars["&Egrave;"]  = "È";
            specialChars["&Eacute;"]  = "É";
            specialChars["&Ecirc;"]   = "Ê";
            specialChars["&Euml;"]    = "Ë";
            specialChars["&Igrave;"]  = "Ì";
            specialChars["&Iacute;"]  = "Í";
            specialChars["&Icirc;"]   = "Î";
            specialChars["&Iuml;"]    = "Ï";
            specialChars["&ETH;"]     = "Ð";
            specialChars["&Ntilde;"]  = "Ñ";
            specialChars["&Ograve;"]  = "Ò";
            specialChars["&Oacute;"]  = "Ó";
            specialChars["&Ocirc;"]   = "Ô";
            specialChars["&Otilde;"]  = "Õ";
            specialChars["&Ouml;"]    = "Ö";
            specialChars["&times;"]   = "×";
            specialChars["&Oslash;"]  = "Ø";
            specialChars["&Ugrave;"]  = "Ù";
            specialChars["&Uacute;"]  = "Ú";
            specialChars["&Ucirc;"]   = "Û";
            specialChars["&Uuml;"]    = "Ü";
            specialChars["&Yacute;"]  = "Ý";
            specialChars["&THORN;"]   = "Þ";
            specialChars["&szlig;"]   = "ß";
            specialChars["&agrave;"]  = "à";
            specialChars["&aacute;"]  = "á";
            specialChars["&acirc;"]   = "â";
            specialChars["&atilde;"]  = "ã";
            specialChars["&auml;"]    = "ä";
            specialChars["&aring;"]   = "å";
            specialChars["&aelig;"]   = "æ";
            specialChars["&ccedil;"]  = "ç";
            specialChars["&egrave;"]  = "è";
            specialChars["&eacute;"]  = "é";
            specialChars["&ecirc;"]   = "ê";
            specialChars["&euml;"]    = "ë";
            specialChars["&igrave;"]  = "ì";
            specialChars["&iacute;"]  = "í";
            specialChars["&icirc;"]   = "î";
            specialChars["&iuml;"]    = "ï";
            specialChars["&eth;"]     = "ð";
            specialChars["&ntilde;"]  = "ñ";
            specialChars["&ograve;"]  = "ò";
            specialChars["&oacute;"]  = "ó";
            specialChars["&ocirc;"]   = "ô";
            specialChars["&otilde;"]  = "õ";
            specialChars["&ouml;"]    = "ö";
            specialChars["&divide;"]  = "÷";
            specialChars["&oslash;"]  = "ø";
            specialChars["&ugrave;"]  = "ù";
            specialChars["&uacute;"]  = "ú";
            specialChars["&ucirc;"]   = "û";
            specialChars["&uuml;"]    = "ü";
            specialChars["&yacute;"]  = "ý";
            specialChars["&thorn;"]   = "þ";
            specialChars["&yuml;"]    = "ÿ";
            specialChars["&Alpha;"]   = "Α";
            specialChars["&alpha;"]   = "α";
            specialChars["&Beta;"]    = "Β";
            specialChars["&beta;"]    = "β";
            specialChars["&Gamma;"]   = "Γ";
            specialChars["&gamma;"]   = "γ";
            specialChars["&Delta;"]   = "Δ";
            specialChars["&delta;"]   = "δ";
            specialChars["&Epsilon;"] = "Ε";
            specialChars["&epsilon;"] = "ε";
            specialChars["&Zeta;"]    = "Ζ";
            specialChars["&zeta;"]    = "ζ";
            specialChars["&Eta;"]     = "Η";
            specialChars["&eta;"]     = "η";
            specialChars["&Iota;"]    = "Ι";
            specialChars["&iota;"]    = "ι";
            specialChars["&Kappa;"]   = "K"; 
            specialChars["&kappa;"]   = "κ";
            specialChars["&Lambda;"]  = "Λ"; 
            specialChars["&lambda;"]  = "λ";
            specialChars["&Mu;"]      = "Μ";
            specialChars["&mu;"]      = "μ";
            specialChars["&Nu;"]      = "Ν";
            specialChars["&nu;"]      = "ν";
            specialChars["&Xi;"]      = "Ξ";
            specialChars["&xi;"]      = "ξ";
            specialChars["&Omicron;"] = "Ο";
            specialChars["&omicron;"] = "ο";
            specialChars["&Pi;"]      = "Π";
            specialChars["&pi;"]      = "π";
            specialChars["&Rho;"]     = "Ρ";
            specialChars["&rho;"]     = "ρ";
            specialChars["&Sigma;"]   = "Σ";
            specialChars["&sigma;"]   = "σ";
            specialChars["&Tau;"]     = "Τ";
            specialChars["&tau;"]     = "τ";
            specialChars["&Upsilon;"] = "Υ";
            specialChars["&upsilon;"] = "υ";
            specialChars["&Phi;"]     = "Φ";
            specialChars["&phi;"]     = "φ";
            specialChars["&Chi;"]     = "Χ";
            specialChars["&chi;"]     = "χ";
            specialChars["&Psi;"]     = "Ψ";
            specialChars["&psi;"]     = "ψ";
            specialChars["&Omega;"]   = "Ω";
            specialChars["&omega;"]   = "ω";

            specialChars["&#x2122;"] = "™";

            int i;
            for (i = 9; i <= 255; i++) {
                char number[4];
                sprintf(number, "%d", i);
                specialChars[(std::string) "&#"+number+";"] = (char) i;
            }
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

