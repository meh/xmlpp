#include <iostream>
#include "../lib/xml/element.h"

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    XMLElement *element = new XMLElement("pokemon");

    if (element->setAttribute("lol", "win")) {
        cout << element->getAttribute("lol")["value"] << endl;
    }
    else {
        cout << "Error while adding the attribute." << endl;
    }

    return 0;
}

