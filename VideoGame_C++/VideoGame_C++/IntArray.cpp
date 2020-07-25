#include "IntArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int dummy = 0;

IntArray::IntArray() {
	printf("New int array %p\n", this);
}

IntArray::IntArray(int n) {
	size = n;
	data = (int*)malloc(sizeof(int) * n); // points data to the memory allocation of integer n
//	printf("New int array of size %d: Memory allocation %p\n", n, this);
}

IntArray::~IntArray() {
//	printf("Deallocation of %p\n", this);
	free(data);
}

void IntArray::set(int index, int value) {
	if (safetyCheck(index)) {
		data[index] = value;
	}
}

int IntArray::get(int index) {
	if (!safetyCheck(index))
		return 0;

	return data[index];
}

bool IntArray::safetyCheck(int index) { // safe check if memory is too large
	return (index >= 0 && index < size);
	
}

// copy constructor initialization
IntArray::IntArray(const IntArray &arr) {
	size = arr.size;
	data = (int*)malloc(sizeof(int) *size); // points data to the memory allocation of integer n
//	printf("copy constructor from %p to %p\n", &arr, this);
	memcpy(data, arr.data, sizeof(int) * size);
}

// operator overloading
void IntArray::operator =(const IntArray& arr) {
	if(data)
		free(data);

	size = arr.size;
	data = (int*)malloc(sizeof(int) * size); // points data to the memory allocation of integer n

//	printf("assignment op from %p to %p\n", &arr, this);
	memcpy(data, arr.data, sizeof(int) * size);
}

void IntArray::operator =(int i) {
	IntArray tmp(1);
	tmp.set(0, i);
	*this = tmp;
}

IntArray IntArray::operator +(const IntArray& arr) {
	IntArray ret(size + arr.size);
	
	memcpy(ret.data, data, size * sizeof(int));
	memcpy(ret.data + size, arr.data, size * sizeof(int));

	return ret;
}

int &IntArray::operator[](int index) {
	if (!safetyCheck(index)) {
		return dummy; // No-op; cannot return a reference which does not have memory
	}
}