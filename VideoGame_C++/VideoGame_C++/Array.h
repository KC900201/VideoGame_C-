#pragma once
/***
Created on Sun July 19 2020

@author : KwongCheongNg
@filename : Array.h
@coding : utf - 8
@description : C++ programming tutorial for learning Video Game programming
@URL: https://www.youtube.com/playlist?list=PLT6WFYYZE6uKFATgSrIn-_JzKpmr-qQMq
========================
Date          Comment
========================
07192020      First revision
07212020	  Referencing; Constructors Destructors
07252020	  Operator Overloading (Most important chapter and most difficult to understand)
08092020      Template
***/

// 08092020
template <typename T>

class Array {
private:
	T *data = nullptr; // pointer named data that points to int n of constructor
	size_t size;
	bool safetyCheck(int index);

public:
//	Array(); // Default constructor, no return value
	Array(int n);
	Array(const Array &arr); // copy constructor definition
	~Array(); // Destructor definition

	T get(int index);
	void set(int index, T value);
	void operator = (const Array &arr);
	void operator = (T i);
	//concatenation
	Array operator +(const Array& arr); //string concantenation
	T &operator[](int i);
};

#include "ArrayImpl.h"