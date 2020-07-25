#pragma once
/***
Created on Sun July 19 2020

@author : KwongCheongNg
@filename : vg_tutoial_1.cpp
@coding : utf - 8
@description : C++ programming tutorial for learning Video Game programming
@URL: https://www.youtube.com/playlist?list=PLT6WFYYZE6uKFATgSrIn-_JzKpmr-qQMq
========================
Date          Comment
========================
07192020      First revision
07212020	  Referencing; Constructors Destructors
07252020	  Operator Overloading (Most important chapter and most difficult to understand)
***/

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
	void operator = (const IntArray &arr);
	void operator = (int i);
	//concatenation
	IntArray operator +(const IntArray& arr); //string concantenation
	int &operator[](int i);
};