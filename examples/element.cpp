#include <iostream>
#include "../lib/dom/element.h"
#include "../lib/dom/text.h"

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element = new DOMElement("pokemon");
    element->setAttribute("style", "width: 234px; height: 23px;");

    DOMText *text = new DOMText("lolwin");

    if (element->nodeType() == DOM_ELEMENT_NODE) {
        cout << "nodeName:  " << element->nodeName() << endl;
    }
    else {
        cout << "nodeValue: " << text->nodeValue() << endl;
    }

    cout << endl << "Attributes-." << endl;
    cout << "Name:  " << element->getAttribute("style").name()  << endl;
    cout << "Value: " << element->getAttribute("style").value() << endl;
    cout << "Plain: " << element->getAttribute("style").plain() << endl << endl;

    return 0;
}

