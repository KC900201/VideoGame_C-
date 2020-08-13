#pragma once

/* This is mostly created to lecture on templates in C++*/

#include "Array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int dummy = 0;

/*
Array::Array() {
	printf("New int array %p\n", this);
}
*/
template <typename T>
Array<T>::Array(int n) {
	size = n;
	//	data = (int*)malloc(sizeof(int) * n); // points data to the memory allocation of integer n
	data = new T[n]; // same as syntax above
//	printf("New int array of size %d: Memory allocation %p\n", n, this);
}

template <typename T>
Array<T>::~Array() {
	//	printf("Deallocation of %p\n", this);
	//	free(data);
	delete []data; // have to use delete when creating element using "new" syntax
}

template <typename T>
void Array<T>::set(int index, T value) {
	if (safetyCheck(index)) {
		data[index] = value;
	}
}

template <typename T>
T Array<T>::get(int index) {
	if (!safetyCheck(index))
		return 0;

	return data[index];
}

template <typename T>
bool Array<T>::safetyCheck(int index) { // safe check if memory is too large
	return (index >= 0 && index < size);

}

// copy constructor initialization
template <typename T>
Array<T>::Array(const Array& arr) {
	size = arr.size;
	data = (T*)malloc(sizeof(T) * size); // points data to the memory allocation of integer n
//	printf("copy constructor from %p to %p\n", &arr, this);
	memcpy(data, arr.data, sizeof(int) * size);
}

// operator overloading
template <typename T>
void Array<T>::operator =(const Array& arr) {
	if (data)
		delete data;
	//		free(data);

	size = arr.size;
	//	data = (int*)malloc(sizeof(int) * size); // points data to the memory allocation of integer n
	data = new int[size]; // points data to the memory allocation of integer n

//	printf("assignment op from %p to %p\n", &arr, this);
	memcpy(data, arr.data, sizeof(int) * size);
}

template <typename T>
void Array<T>::operator =(T i) {
	Array tmp(1);
	tmp.set(0, i);
	*this = tmp;
}

template <typename T>
Array<T> Array<T>::operator +(const Array& arr) {
	Array ret(size + arr.size);

	memcpy(ret.data, data, size * sizeof(int));
	memcpy(ret.data + size, arr.data, size * sizeof(int));

	return ret;
}

template <typename T>
T &Array<T>::operator[](int index) {
	if (!safetyCheck(index)) {
		return dummy; // No-op; cannot return a reference which does not have memory
	}
}