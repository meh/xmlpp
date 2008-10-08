#include <iostream>
#include <xml++/DOM.h>

using namespace std;
using namespace xmlpp::DOM;

int main(int argc, char *argv[]) {
    Document *doc = new Document;

    doc->appendChild(doc->createElement("lulz"));

    cout << doc->documentElement()->nodeName() << endl;

    return 0;
}

