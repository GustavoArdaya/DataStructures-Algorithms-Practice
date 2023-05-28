#include <iostream>


int main() {

    // in stack (order is rows - columns)
    int A [3][4] = {{1,2,3,4}, {2,4,6,8}, {3,5,7,9}};

    // in stack and heap 

    int *B[3];  // this creates an array of pointers in stack that point to arrays in heap
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    // "completelly" in heap

    int **C;  // this creates a pointer in stack that points to two arrays in heap
    C = new int *[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];


    // to access these 2D arrays you need nested loops

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 4; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 4; j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 4; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }




    return 0;
}