#include "PlantArr.h"



PlantArr::PlantArr() {
	capacity = 45;
	size = 0;
	arr = new Plant * [capacity];
}

PlantArr::~PlantArr() {

	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete[] arr;

}

PlantArr::PlantArr(const PlantArr& other) {
	capacity = other.capacity;
	size = other.size;
	arr = new Plant * [capacity];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
}

PlantArr& PlantArr::operator=(const PlantArr& other) {
	if (this != &other) {
		delete[] arr;
		capacity = other.capacity;
		size = other.size;
		arr = new Plant * [capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	return *this;
}

void PlantArr::push_back(Plant* obj) {
	if (size   == capacity) {
		resize();
	}
	arr[size] = obj;
	size++;


}

void PlantArr::pop_back() {
	if (size > 0) {
		delete arr[size - 1];
		size--;
	}
}

int PlantArr::getSize() const {
	return size;
}

bool PlantArr::empty() const {
	return size == 0;
}

void PlantArr::clear() {
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	size = 0;
}

void PlantArr::resize() {
	capacity *= 2 ;
	Plant** temp = new Plant * [capacity];
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

Plant* PlantArr::at(int index) const {
	if (index >= 0 && index < size) {
		return arr[index];
	}
	return nullptr;
}

void PlantArr::insert(Plant* obj, int index) {
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

void PlantArr::erase(int index) {
	if (index >= 0 && index < size) {
		delete arr[index];
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
}