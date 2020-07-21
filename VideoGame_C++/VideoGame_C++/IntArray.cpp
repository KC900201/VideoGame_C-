#include "IntArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

IntArray::IntArray() {
	printf("New int array %p\n", this);
}

IntArray::IntArray(int n) {
	size = n;
	data = (int*)malloc(sizeof(int) * n); // points data to the memory allocation of integer n
	printf("New int array of size %d: Memory allocation %p\n", n, this);
}

IntArray::~IntArray() {
	printf("Deallocation of %p\n", this);
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
	printf("copy constructor from %p to %p\n", &arr, this);
	memcpy(data, arr.data, sizeof(int) * size);
}

