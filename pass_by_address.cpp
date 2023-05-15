#include <iostream>
#include <stdio.h>

using namespace std;

// Both pass by value and pass by address are pressent in C

void swap(int *x, int *y) { // this function, since it returns void, should recieve addresses (pointers)
    
    int temp;   //   an integer variable,
    temp = *x;  //   which is assigned the derreferenced value of x
    *x = *y;    //   whose value (derref) is then assigned the derref value of y.
    *y = temp;  //   Finally the address of y's value is asigned to the int stored in temp. No return, but values in memory have been modified 

}

int main() {

    int a, b;
    a = 10;
    b = 20;

    swap(&a, &b);   // args passed are not the values a=10, nor b=20, but their addresses using ampersand (&)

    printf("%d %d", a, b);

}