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
/*
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
} */

struct Array* set_union(struct Array *arr1, struct Array *arr2) {
    int i{0}, j{0}, k{0};
    struct Array *arr3 = new Array{};

    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];   // Fuerte! se usa y luego Post-Increment! 
        } else if (arr2->A[j] < arr1->A[i]){
            arr3->A[k++] = arr2->A[j++];
        } else {    // meaning they're equal
            arr3->A[k++] = arr1->A[i++];    // copies any of the elements. In this case first
            j++;                            // dont forget to increment j!
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr1->A[j];
    arr3->length = k;
    arr3->size = (arr1->size + arr2->size);

    return arr3;
}

struct Array* set_intersection(struct Array *arr1, struct Array *arr2) {
    int i{0}, j{0}, k{0};
    struct Array *arr3 = new Array{};

    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] < arr2->A[j]) {
            i++;   // si son diferentes se mueve indice
        } else if (arr2->A[j] < arr1->A[i]){
            j++;
        } else {    // meaning they're equal
            arr3->A[k++] = arr1->A[i++];    // copies any of the elements. In this case first
            j++;                            // dont forget to increment j!
        }
    }
    
    arr3->length = k;
    arr3->size = (arr1->size + arr2->size);

    return arr3;
}

struct Array* set_difference(struct Array *arr1, struct Array *arr2) {
    int i{0}, j{0}, k{0};
    struct Array *arr3 = new Array{};

    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];   
        } else if (arr2->A[j] < arr1->A[i]){
            j++;            // no nos interesa copiar elemento de segundo array
        } else {    // meaning they're equal
            i++;    // copies any of the elements. In this case first
            j++;                            // dont forget to increment j!
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    // no se copia elementos restantes de 2do array
    arr3->length = k;
    arr3->size = (arr1->size + arr2->size);

    return arr3;
}



int main () {

    struct Array arr1 = {{2,6,10,15,25}, 10, 5};
    struct Array arr2 = {{3,6,7,15,20}, 10, 5};
    struct Array *arr3;
    struct Array *arr4;
    struct Array *arr5;
    arr3 = set_union(&arr1, &arr2);
    display(*arr3);
    arr4 = set_intersection(&arr1, &arr2);
    display(*arr4);
    arr5 = set_difference(&arr1, &arr2);
    display(*arr5);

    return 0;
}