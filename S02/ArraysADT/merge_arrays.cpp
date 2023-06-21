#include <iostream>

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

void display(struct Array arr) {
    std::cout << "Elements are:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i] << " ";
    }
}

struct Array* merge(struct Array *arr1, struct Array *arr2) {
    int i{0}, j{0}, k{0};
    struct Array *arr3 = new Array{};

    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];   // Fuerte! se usa y luego Post-Increment! 
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr1->A[j];
    arr3->length = (arr1->length + arr2->length);
    arr3->size = (arr1->size + arr2->size);

    return arr3;
}

int main () {

    struct Array arr1 = {{2,6,10,15,25}, 10, 5};
    struct Array arr2 = {{3,4,7,18,20}, 10, 5};
    display(arr1);
    std::cout << std::endl;
    display(arr2);
    std::cout << std::endl;
    struct Array arr3;
    arr3 = *merge(&arr1, &arr2); 
    display(arr3);

    return 0;
}