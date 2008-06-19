#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main(int argc, char *argv[]) {
    DOMParser *parser = new DOMParser("lol.xml");

    cout << parser->plain() << endl;

    return 0;
}

