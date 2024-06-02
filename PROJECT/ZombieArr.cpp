#include "ZombieArr.h"



ZombieArr::ZombieArr() {
	capacity = 45;
	size = 0;
	arr = new Zombie * [capacity];
}

ZombieArr::~ZombieArr() {

	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete[] arr;

}

ZombieArr::ZombieArr(const ZombieArr& other) {
	capacity = other.capacity;
	size = other.size;
	arr = new Zombie * [capacity];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
}

ZombieArr& ZombieArr::operator=(const ZombieArr& other) {
	if (this != &other) {
		delete[] arr;
		capacity = other.capacity;
		size = other.size;
		arr = new Zombie * [capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	return *this;
}

void ZombieArr::push_back(Zombie* obj) {
	if (size == capacity) {
		resize();
	}
	arr[size] = obj;
	size++;

	

}

void ZombieArr::pop_back() {
	if (size > 0) {
		delete arr[size - 1];
		size--;
	}
}

int ZombieArr::getSize() const {
	return size;
}

bool ZombieArr::empty() const {
	return size == 0;
}

void ZombieArr::clear() {
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	size = 0;
}

void ZombieArr::resize() {
	capacity *= 2;
	Zombie** temp = new Zombie * [capacity];
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

Zombie* ZombieArr::at(int index) const {
	if (index >= 0 && index < size) {
		return arr[index];
	}
	return nullptr;
}

void ZombieArr::insert(Zombie* obj, int index) {
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

void ZombieArr::erase(int index) {
	if (index >= 0 && index < size) {
		delete arr[index];
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
}