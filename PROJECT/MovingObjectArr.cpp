#include "MovingObjectArr.h"



MovingObjectArr::MovingObjectArr() {
	capacity = 300;
	size = 0;
	arr = new MovingObject * [capacity];
}

MovingObjectArr::~MovingObjectArr() {

	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete[] arr;

}

MovingObjectArr::MovingObjectArr(const MovingObjectArr& other) {
	capacity = other.capacity;
	size = other.size;
	arr = new MovingObject * [capacity];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
}

MovingObjectArr& MovingObjectArr::operator=(const MovingObjectArr& other) {
	if (this != &other) {
		delete[] arr;
		capacity = other.capacity;
		size = other.size;
		arr = new MovingObject * [capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	return *this;
}

void MovingObjectArr::push_back(MovingObject* obj) {
	if (size == capacity) {
		resize();
	}
	arr[size] = obj;
	size++;

	
}

void MovingObjectArr::pop_back() {
	if (size > 0) {
		delete arr[size - 1];
		size--;
	}
}

int MovingObjectArr::getSize() const {
	return size;
}

bool MovingObjectArr::empty() const {
	return size == 0;
}

void MovingObjectArr::clear() {
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	size = 0;
}

void MovingObjectArr::resize() {
	capacity *= 2;
	MovingObject** temp = new MovingObject * [capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
	arr = temp;
}

MovingObject* MovingObjectArr::at(int index) const {
	if (index >= 0 && index < size) {
		return arr[index];
	}
	return nullptr;
}

void MovingObjectArr::insert(MovingObject* obj, int index) {
	if (index >= 0 && index <= size) {
		if (size == capacity) {
			resize();
		}
		for (int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = obj;
		size++;
	}
}

void MovingObjectArr::erase(int index) {
	if (index >= 0 && index < size) {
		delete arr[index];
		for (int i = index ; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
}