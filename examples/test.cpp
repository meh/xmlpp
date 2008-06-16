#include <iostream>
#include "../lib/xml++.h"

using namespace std;
using namespace xmlpp;

int main(int argc, char *argv[]) {
    DOMParser *parser = new DOMParser("lol.xml");

    cout << parser->document() << endl;

    return 0;
}

