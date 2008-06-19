#include <iostream>
#include <xml++/dom/element.h>
#include <xml++/dom/text.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *pokemon = new DOMElement("pokemon");
    pokemon->setAttribute("id", "1");

    DOMElement *general = new DOMElement("general");

    DOMElement *number = new DOMElement("number");
    number->appendChild(new DOMText("001"));

    DOMElement *name = new DOMElement("name");
    name->appendChild(new DOMText("Bulbasaur"));

    general->appendChild(number);
    general->appendChild(name);

    pokemon->appendChild(general);

    // Bulbasaur
    try {
        DOMChildNode *gen = pokemon->childNode(0)->firstChild()->nextSibling();

        if (gen != NULL) {
            switch (gen->nodeType()) {
                case DOM_ELEMENT_NODE:
                cout << gen->firstChild()->text() << endl;
                break;

                case DOM_TEXT_NODE:
                cout << gen->nodeValue() << endl;
                break;
            }
        }
        else {
            cout << "LOL NO SIBLING" << endl;
        }
    }
    catch (DOMException e) {
        cerr << e.getMessage();
    }

    return 0;
}

