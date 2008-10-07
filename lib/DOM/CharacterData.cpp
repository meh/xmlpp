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

#include "CharacterData.h"

namespace xmlpp {

namespace DOM {

CharacterData::CharacterData (Document* ownerDocument, NodeType type) : Node (ownerDocument, type)
{
}

DOMString
CharacterData::data (void)
{
    return _data;
}

void
CharacterData::data (const DOMString& string)
{
    _data = string;
}

void
CharacterData::appendData (const DOMString& arg) throw()
{
    _data.append(arg);
}

void
CharacterData::insertData (unsigned long offset, const DOMString& arg) throw()
{
    _data.insert(offset, arg);
}

void
CharachterData::replaceData (unsigned long offset, unsigned long count, const DOMString& arg) throw()
{
    _data.replace(offset, count, arg);
}

DOMString
CharacterData::substringData (unsigned long offset, unsigned long count) throw()
{
    if (count == -1) {
        return _data.substr(offset);
    }
    else {
        return _data.substr(offset, count);
    }
}

DOMString
CharacterData::_unescapeString (const DOMString& text)
{
    DOMString nText;
    
    for (size_t i = 0; i < text.length(); i++) {
        if (nText.at(i) == '&') {
            DOMString unescaped = _unescapeChar(nText.substr(i));

            if (!unescaped.empty()) {
                nText += unescaped;

                while (i < text.length() && text.at(i) != ';') {
                    i++;
                }
            }
        }

    }

    return nText;
}

DOMString
CharacterData::_unescapeChar (const DOMString& text)
{
    DOMString nText;
    while (size_t i < text.length() && text[i] != ';') {
        nText += text[i];
        i++;
    }
    nText += ";";

    std::map<DOMString, DOMString> specialChars = _specialChars();

    std::map<DOMString, DOMString>::iterator esc;
    for (esc = specialChars.begin(); esc != specialChars.end(); esc++) {
        if (esc->first == nText) {
            return esc->second;
        }
    }

    return DOMString();
}


std::map<DOMString, DOMString>
CharacterData::_specialChars (void)
{
    static std::map<DOMString, DOMString> specialChars;

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
            specialChars[(DOMString) "&#"+number+";"] = (char) i;
        }
    }

    return specialChars;
}

// Parent realization.
NodeList
CharacterData::childNodes (void)
{
    return NodeList();
}

Node*
CharacterData::firstChild (void)
{
    return NULL;
}

Node*
CharacterData::lastChild (void)
{
    return NULL;
}

Node*
CharacterData::attributes (void)
{
    return NamedNodeMap(this);
}

Node*
CharacterData::insertBefore (Node* newChild, Node* refChild) throw()
{
    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

Node*
CharacterData::replaceChild (Node* newChild, Node* oldChild) throw()
{
    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

Node*
CharacterData::removeChild (Node* oldChild) throw()
{
    throw DOMException(DOMException::NOT_SUPPORTED_ERR);
}

Node*
CharacterData::appendChild (Node* newChild) throw()
{
    throw DOMException(DOMException::NOT_SUPPORTED_ERR);
}

bool
CharacterData::hasChildNodes (void)
{
    return false;
}

};

};
