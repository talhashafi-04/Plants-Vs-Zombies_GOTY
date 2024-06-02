#pragma once
#ifndef MovingObjectArr_h
#define MovingObjectArr_h

#include "MovingObject.h"
#include <iostream>
using namespace std;


class MovingObjectArr {
private:
    MovingObject** arr;
    int capacity;
    int size;

public:
    // Constructor
    MovingObjectArr();

    // Destructor
    ~MovingObjectArr();

    // Copy constructor
    MovingObjectArr(const MovingObjectArr& other);

    // Assignment operator
    MovingObjectArr& operator=(const MovingObjectArr& other);

    // Push back element
    void push_back(MovingObject* obj);

    // Pop back element
    void pop_back();

    // Get size
    int getSize() const;

    // Check if empty
    bool empty() const;

    // Clear all elements
    void clear();

    // Resize the array
    void resize();

    // Access element at index

    MovingObject* at(int index) const;

    // Insert element at index
    void insert(MovingObject* obj, int index);

    // Erase element at index
    void erase(int index);
};


#endif 


