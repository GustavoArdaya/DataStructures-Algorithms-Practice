#include <iostream>
#include "arraycpp.cpp"

int findMissingOrdered(Array *array) {
    int n = array->get(array->getLength()-1);
    int expected = (n * (n + 1))/2;
    int actual = array->sum();

    return (expected - actual);    
}

void printMissing(Array *array) {
    int diff = array->get(0);
    int n = array->getLength();

    for (int i = 0; i < n; i++ ) {
        if (array->get(i) - i != diff) {
            
            while (diff < array->get(i) - i) { // la diferencia entre el indice del array y el elemento comparado a la diferencia inicial orienta respecto a elemento faltante
                std::cout << (i + diff) << " is missing in array" << std::endl;
                diff++;
                }
        }
    }
}

void printMissingUnordered(Array *array) {    
    int n = array->max() + 1;
    int h[n] = {0}; 
   
    for (int i = 0; i < array->getLength(); i++) {
        h[array->get(i)]++;
    }

    for (int j = 1; j < n; j++) {
        
        if (h[j] == 0) {
            std::cout << j << " is missing in unordered array" << std::endl;
        }
    }
    
}



int main() {

    Array *arr = new Array(12);
    Array *unordered = new Array(10);
    {
        unordered->append(3);
        unordered->append(7);
        unordered->append(4);
        unordered->append(9);
        unordered->append(12);
        unordered->append(6);
        unordered->append(1);
        unordered->append(11);
        unordered->append(2);
        unordered->append(10);
    }

    for (int i = 1; i <= arr->getSize(); i++) {
        std::cout << i << " ";
        arr->append(i);
    }
    arr->del(6);

    arr->display();

    std::cout << "missing element in ordered array is " << findMissingOrdered(arr) << std::endl;

    arr->del(7);
    arr->del(7);
    
    arr->display();

    printMissing(arr);

    unordered->display();

    printMissingUnordered(unordered);

    return 0;
}