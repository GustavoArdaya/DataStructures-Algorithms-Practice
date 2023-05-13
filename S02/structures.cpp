#include <stdio.h>
#include <iostream>
using namespace std;

//structures are similar to dictionaries or javascript objects

struct Rectangle {
    int length;
    int breadth;
    char x;     //even though character should be 1 byte only, its easier form compiler to read bytes in intervals of 4
                // so it creates 4 bytes but uses only 1
};

int main() {
    struct Rectangle r1 = {10, 5};

    printf("%lu", sizeof(r1)); // this is a C method : %lu gives proper format to prevent warning from compiler if using %d

    r1.length=15;
    r1.breadth=7;
    
    cout << r1.length << endl;
    cout << r1.breadth << endl;
    return 0;
}