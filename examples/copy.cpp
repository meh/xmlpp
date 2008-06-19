#include <iostream>
#include "../lib/xml++.h"

using namespace std;
using namespace xmlpp;

int main(int argc, char *argv[])
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

    DOMElement *newPokemon = (DOMElement*) pokemon->cloneNode();

    cout << newPokemon->firstChild()->childNode(1)->firstChild()->nodeValue() << endl;

    return 0;
}

