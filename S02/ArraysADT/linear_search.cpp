#include <iostream>
#include <stdlib.h>

// LINEAR SEARCH FOR UNIQUE ELEMENTS

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

void display(struct Array arr) {            // equivalente a push_back
    std::cout << "Elements are:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;
}

int linearSearch(struct Array arr, int key) {

    for (int i = 0; i < arr.length; i++) {
        if (key==arr.A[i])
            return i;
    }
    return -1;
}

void swap( int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int enhancedLinearSearch (struct Array *arr, int key) { // receives a reference, since it will modify array

    for (int i = 0; i < arr->length; i++) {
        if (key==arr->A[i] && i > 0) {
            swap (&arr->A[i], &arr->A[i-1]);
            return i;
        } else if (key==arr->A[i] && i == 0)
            return i;            
    }
    return -1;
}

int enhancedMovetoHead (struct Array *arr, int key) { // receives a reference, since it will modify array

    for (int i = 0; i < arr->length; i++) {
        if (key==arr->A[i] && i > 0) {
            swap (&arr->A[i], &arr->A[0]);
            return i;
        } else if (key==arr->A[i] && i == 0)
            return i;            
    }
    return -1;
}

int main() {

    struct Array arr = {{2,3,4,5,6}, 10, 5};

    std::cout << "linear search element '4' is in index " << linearSearch(arr,4) << std::endl;
    display(arr);

    std::cout << "enhanced linear search element '5' is in index " << enhancedLinearSearch(&arr,5) << std::endl;
    display(arr);

    std::cout << "enhanced linear search element '4' is in index " << enhancedMovetoHead(&arr,4) << std::endl;
    display(arr);

    return 0;
}