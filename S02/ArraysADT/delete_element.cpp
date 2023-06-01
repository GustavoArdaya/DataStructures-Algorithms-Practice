#include <iostream>
#include <stdlib.h>

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

int delete_element(struct Array *arr, int index) {

    int x {0};
    if (index >= 0 && index < arr->length) {
        x = arr->A [index];
        for (int i = index; i < arr->length - 1; i++) {
            arr -> A[i] = arr -> A[i + 1];
        }
        arr -> length--;
        return x;
    }

    return 0;
}

int main () {
    
    struct Array arr={{2,3,4,5,6}, 10, 5};
    display(arr);    
    std::cout << "deleted element: " << delete_element(&arr, 2) << std::endl;
    display(arr);    

    return 0;
}