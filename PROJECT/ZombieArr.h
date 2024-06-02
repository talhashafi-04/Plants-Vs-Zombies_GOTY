#pragma once
#include "Zombie.h"
#include <iostream>
using namespace std;


class ZombieArr {
private:
    Zombie** arr;
    int capacity;
    int size;

public:
    // Constructor
    ZombieArr();

    // Destructor
    ~ZombieArr();

    // Copy constructor
    ZombieArr(const ZombieArr& other);

    // Assignment operator
    ZombieArr& operator=(const ZombieArr& other);

    // Push back element
    void push_back(Zombie* obj);

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

    Zombie* at(int index) const;

    // Insert element at index
    void insert(Zombie* obj, int index);

    // Erase element at index
    void erase(int index);
};


