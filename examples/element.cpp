#include <iostream>
#include "../lib/dom/element.h"

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element = new DOMElement("pokemon");
    element->setAttribute("style", "width: 234px; height: 23px;");

    try {
        cout << "nodeName:  " << element->nodeName()  << endl;
        cout << "nodeValue: " << element->nodeValue() << endl;
    }
    catch (Exception e) {
        cerr << e.getMessage();
    }

    cout << endl << "Attributes-." << endl;
    cout << "Name:  " << element->getAttribute("style").name()  << endl;
    cout << "Value: " << element->getAttribute("style").value() << endl;
    cout << "Plain: " << element->getAttribute("style").plain() << endl << endl;

    cout << "Type: " << element->nodeType() << endl;

    return 0;
}

