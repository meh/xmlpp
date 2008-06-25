#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    try {
        XMLParser *parser = new XMLParser();
        DOM *document     = parser->parseFromFile("lol.xml");

        cout << document->firstChild()->firstChild()->firstChild()->nodeValue() << endl;
    }
    catch (Exception e) {
        cerr << e.getMessage() << endl;
    }

    return 0;
}

