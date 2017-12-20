#include <iostream>

using namespace std;

#include "Bin.h"
#include "Parser.h"


int main() {

    Parser parser;
    parser.readFile("exemples/exemple100.txt");
    Bin bin(parser.getBinSize(),1);
    bin.addAnObject(50);
    bin.print();
    return 0;
}