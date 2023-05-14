#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Rectangle {
    int length;
    int breadth;    
};

int main () {

    Rectangle r = {10,5}; // C must include "struct" before object
    cout << r.length<<endl;
    cout << r.breadth<<endl;

    Rectangle *p = &r; //a pointer to a structure

    cout << p->length<<endl;        // since pointer 'points' to an address, it needs to be derreferenced before using dot operator
    cout << (*p).breadth<<endl;     // this arrow operator "->" does the same that the previous example


    // Creating a structure in heap

    Rectangle *p1 = (struct Rectangle *)malloc(sizeof(struct Rectangle)); 

    // Rectangle *p2 = new Rectangle; // this creates object in heap using c++ syntax
    p1->length=15;
    p1->breadth=7;

    cout << (*p1).length << endl;
    cout << p1->breadth << endl;

    return 0;
}