#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element  = new DOMElement("lol");
    DOMElement *element2 = new DOMElement("omg");
    DOMElement *element3 = new DOMElement("fail");

    element->appendChild(element2);
    element->appendChild(element3);

    element->removeChild(1);

    cout << element->firstChild()->nodeName() << endl << endl;

    DOMElement *element4 = new DOMElement("lol");
    DOMElement *element5 = new DOMElement("omg");
    DOMElement *element6 = new DOMElement("fail");
    DOMElement *element7 = new DOMElement("win");

    element4->appendChild(element5);
    element4->appendChild(element6);
    element4->appendChild(element7);

    element4->removeChild(element6);

    try {
        cout << element4->childNode(1)->nodeName() << endl;
    }
    catch (Exception e) {
        cerr << e.getMessage() << endl;
    }

    cout << "=^_^=" << endl;

    return 0;
}

