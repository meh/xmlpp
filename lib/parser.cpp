#include "common.h"
#include "parser.h"

Parser::Parser(const char* xmlString, int mode = XML_FILE) {
    this->xmlDoc = this->getXmlDoc((string) xmlString, mode);
}

Parser::Parser(string xmlDoc, int mode = XML_FILE) {
    this->xmlDoc = this->getXmlDoc(xmlDoc, mode);
}

Parser::Parser(ifstream xmlFile) {
    xmlFile.seekg(0, ios::beg);

    string line;
    while (!xmlFile.eof()) {
        getline(xmlFile, line);
        this->xmlDoc += line + "\n";
    }
}

Parser::getXmlDoc(string xmlString, int mode) {
    string xmlDoc;
    string line;

    switch (mode) {
        case XML_FILE:
        ifstream xmlFile(xmlString);

        if (xmlFile.is_open()) {
            while (!xmlFile.eof()) {
                getline(xmlFile, line);
                xmlDoc += line + "\n";
            }
        }
        else {
            throw xmlException(XML_FILE_READ_ERROR);
        }
        break;

        case XML_STRING:
        xmlDoc = xmlString;
        break;

        default:
        throw xmlException(XML_PARSE_MODE_ERROR);
        break;
    }

    return xmlDoc;
}

