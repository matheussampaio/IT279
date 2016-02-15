/*
 *  Programmer: Matheus Sampaio - msanto2@gmail.com
 *  ULID: msanto2
 *  Class: IT279
 *  License: MIT
 */

#include <stdlib.h>

#include "myArray.h"

/**
 * Default Constructor
 */
myArray::myArray() {
    size = 10;
    A = new int[size];
}

/**
 * Constructor an array with size `s` and default value `iv`.
 *
 * @param s Size of the array.
 * @param iv Initial value.
 */
myArray::myArray(int s, int iv) {
    size = s;
    A = new int[size];

    for (int i = 0; i < size; i++) {
        A[i] = iv;
    }
}

/**
 * Copy Constructor
 */
myArray::myArray(const myArray & a) {
    size = a.size;
    A = new int[size];

    for (int i = 0; i < size; i++) {
        *(A + i) = *(a.A + i);
    }
}

/**
 * Overload '=' operator
 */
myArray & myArray::operator = (const myArray & a) {
    if (size != a.size) {
        delete [] A;
        A = new int[a.size];
    }

    size = a.size;

    for (int i = 0; i < size; i++) {
        *(A + i) = a.A[i];
    }

    return *this;
}

/**
 * Destructor
 */
myArray::~myArray() {
    delete [] A;
}

/**
 * Overload '[]' operator to return ith element of the array.
 */
int & myArray::operator [] (int i) {
    return A[i];
}

/**
 * Return the Biggest Number's index in the array.
 *
 * @reeturn Biggest Number's index.
 */
int myArray::max() {
    int result = 0;

    for (int i = 0; i < getSize(); i++) {
        if (A[i] > A[result]) {
            result = i;
        }
    }

    return result;
}

/**
 * Return the Smallest Number's index in the array.
 *
 * @return Smallest Number's index.
 */
int myArray::min() {
    int result = 0;

    for (int i = 0; i < getSize(); i++) {
        if (A[i] < A[result]) {
            result = i;
        }
    }
    return result;
}

/**
 * The average of the numbers on the array.
 *
 * @return The average of the array.
 */
double myArray::average() {
    double sumValue = 0;

    for (int i = 0; i < getSize(); i++) {
        sumValue += A[i];
    }

    return sumValue / getSize();
}

/**
 * Get the size of the array.
 *
 * @return The size of the array.
 */
int myArray::getSize() {
    return size;
}

/**
 * Create an array with fibonacci elements.
 *
 * @param n The size of the array.
 * @return The myArray with fibonacci elements.
 */
myArray fibonacci(int n) {
    myArray f(n, 0);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f;
}

/**
 * Populate the `ma` myArray with random numbers from 0 to ma length.
 */
void rand(myArray *ma) {
    for (int i = 0; i < ma->getSize(); i++) {
        (*ma)[i] = rand() % (ma->getSize());
    }
}
