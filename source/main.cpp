#include <iostream>
#include "Bin.h"

using namespace std;



int main() {

    cout<<"Hello World"<<endl;
    Bin bin(100,1);
    bin.addAnObject(50);
    bin.print();
    return 0;
}