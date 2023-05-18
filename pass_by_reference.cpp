#include <iostream>
#include <stdio.h>

using namespace std;

// Pass by reference is not present in C, only in C++


/*This is a much easier syntax:
    since x and y are references (&) they're alias created in the scope 
    of the function, but these references point to the same address, so
    changing one will automatically change the other, even though the
    variables are destroyed after the execution of the function.

    It's shouldn't be used on complex code...
*/
void swap(int &x, int &y) { // x becomes an alias of a, and y an alias of b
    
    int temp;   
    temp = x;  
    x = y;    
    y = temp;  // this may become an inline function or be translated to pointers in compiler...

}

int main() {

    int a, b;
    a = 10;
    b = 20;

    swap(a, b);   // args passed actual variable values.

    printf("%d %d", a, b);

}