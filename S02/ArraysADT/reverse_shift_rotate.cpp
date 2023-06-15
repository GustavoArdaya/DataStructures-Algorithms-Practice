#include <iostream>

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

void reverse_twoloops(struct Array *arr) {           // uses reference

    int *tempArr = new int[arr->size];

    for (int i = arr->length-1, j = 0; i >= 0; i--, j++) {
        tempArr[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++) {
        arr->A[i] = tempArr[i];
    }    
}

void reverse_oneloop(struct Array *arr) {

    for (int i = 0, j = arr->length-1; i < j; i++, j--) {
        int temp;
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void left_shift(struct Array *arr) {

    for (int i = 0; i < arr->length; i++) {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
}

void right_shift(struct Array *arr) {

    for (int i = arr->length - 1; i > 0; i--) {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
}

void left_rotate(struct Array *arr) {

    int temp = arr->A[0];
    for (int i = 0; i < arr->length; i++) {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}

void right_rotate(struct Array *arr) {

    int temp = arr->A[arr->length-1];
    for (int i = arr->length - 1; i > 0; i--) {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}

void display(struct Array arr) {
    std::cout << "Elements are:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i];
    }
}

int main () {

    struct Array arr = {{2,3,4,5,6}, 10, 5};

    reverse_twoloops(&arr);
    display(arr);
    std::cout << std::endl;
    reverse_oneloop(&arr);
    display(arr);
    std::cout << std::endl;
    left_shift(&arr);
    display(arr);
    std::cout << std::endl;
    right_shift(&arr);
    display(arr);
    std::cout << std::endl;
    arr.A[0] = 2;
    display(arr);
    std::cout << std::endl;
    std::cout << std::endl;
    left_rotate(&arr);
    display(arr);
    std::cout << std::endl;
    right_rotate(&arr);
    display(arr);
    std::cout << std::endl;

    

    return 0;
}