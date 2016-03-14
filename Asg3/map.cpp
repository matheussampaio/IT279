/*
 * map.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Chung-Chih Li
 */
/*
 * Students should not modify this file
 */

template<typename T>
class map {
    public:
        virtual void insert(int key, T data)=0;     // insert data with key
        virtual T *remove(int key)=0;               // Remove data with key and return it
        virtual T *get(int key)=0;                  // Get the data with key
        virtual int size()=0;                       // Return the number of items (data) in the map
        virtual T *max()=0;                         // Get the data with biggest key
        virtual T *min()=0;                         // Get the data with the least key
        virtual T *toArray()=0;                     // Return an array of T that contains all data
                                                    // in ascending order according to key
        virtual ~map() {};
};
