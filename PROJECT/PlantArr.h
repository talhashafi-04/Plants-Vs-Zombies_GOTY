#ifndef PlantArr_h
#define PlantArr_h


#pragma once
#include "Plant.h"
#include <iostream>
using namespace std;


class PlantArr {
private:
    Plant** arr;
    int capacity;
    int size;

public:
    // Constructor
    PlantArr();

    // Destructor
    ~PlantArr();

    // Copy constructor
    PlantArr(const PlantArr& other);

    // Assignment operator
    PlantArr& operator=(const PlantArr& other);

    // Push back element
    void push_back(Plant* obj);

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

    Plant* at(int index) const;

    // Insert element at index
    void insert(Plant* obj, int index);

    // Erase element at index
    void erase(int index);
};


#endif 
