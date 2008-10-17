#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;
using namespace xmlpp::DOM;

int main(int argc, char *argv[]) {
    XML::Parser parser;

    Document* doc = parser.load("easy.xml");
    doc->normalizeDocument();

    std::cout << doc->firstChild()->firstChild()->nodeValue() << std::endl;

    doc = parser.load("hard.xml");
    std::cout << ((Element*)doc->getElementsByTagName("document").item(0))->getAttribute("path") << std::endl;

    return 0;
}

