#include <iostream>
#include <stdlib.h>

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

void display(struct Array arr) {            // equivalente a push_back
    std::cout << "\nElements are:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i] << " ";
    }
}

void append(struct Array *arr, int x) {

    if(arr->length < arr->size) {
        arr->A[arr->length++]=x;
    }
}

void insert(struct Array *arr, int index, int x) {
    if (index > 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i-- ) {
            arr->A[i] = arr-> A[i-1];   // copies value to the right (since it goes from right to left)
        }
        arr->A[index] = x;              // assigns new value to liberated index
        arr->length++;                  // length is incremented
    }
}

int main () {
    
    struct Array arr={{2,3,4,5,6}, 10, 5};
    display(arr);
    append(&arr, 10);
    display(arr);
    insert(&arr, 3, 1);
    display(arr);

    return 0;
}