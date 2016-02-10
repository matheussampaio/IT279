/*
 *  Programmer: Matheus Sampaio - msanto2@gmail.com
 *  ULID: msanto2
 *  Class: IT279
 *  License: MIT
 */

#include <iostream>
#include "myArray.h"

using namespace std;

int main() {

    myArray array(10, 5);

    cout << "size: " << array.getSize() << endl;

    for (int i = 0; i < array.getSize(); i++) {
        cout << i << " - " << array[i] << endl;
    }


    return 0;
}
