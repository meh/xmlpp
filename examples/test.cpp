#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;
using namespace xmlpp::DOM;

int main(int argc, char *argv[]) {
    Parser parser(new XML::Parser);
    Document *doc = parser.load("lol.xml");
    doc->normalizeDocument();

    cerr << doc->firstChild()->firstChild()->nodeName() << endl;

    return 0;
}

