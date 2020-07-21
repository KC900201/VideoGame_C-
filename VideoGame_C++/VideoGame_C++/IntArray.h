#pragma once

class IntArray {
private:
	int *data; // pointer named data that points to int n of constructor
	size_t size;
	bool safetyCheck(int index);

public:
	IntArray(); // Default constructor, no return value
	IntArray(int n);
	~IntArray(); // Destructor definition
	IntArray(const IntArray &arr); // copy constructor definition
	int get(int index);
	void set(int index, int value);
};