#include <iostream>
#include <stdio.h>  // C lib
#include <stdlib.h> // C lib

using namespace std;

int main () {

    //integer:
    int a = 10;
    int *p;
    p = &a;

    // Array in stack
    int A[5] = {2,4,6,8,10}; //created inside stack
    int *pA;
    pA=A;   // initializing pointer to an array doesnt use & ampersand.

    // Array in heap

    int *pB;
    pB=(int *) malloc(5*sizeof(int)); //C way: allocates the space of 5 integers in heap
    pB[0] = 10; pB[1] = 15; pB[2] = 14; pB[3] = 21; pB[4] = 31; // This array's values are in heap!

    // C++ way: int *p; p = new int[5];
    cout << "This array is is heap: " << endl;
    for (int i=0; i<5;i++) 
        cout<<pB[i]<<endl;

    cout <<a << endl;
    printf("using pointer %d \n", *p);
    printf("using pointer %d \n", *pA);

    for (int i = 0; i<5;i++) {
        cout << pA[i]<< endl; //doesn't need &!
    }

    //delete array in heap to prevent memory leak:

    delete [] pB; 
    // in C: free(pB);

    return 0; //heap memory is automatically deleted when program ends
}