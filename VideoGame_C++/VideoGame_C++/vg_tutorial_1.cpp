#include <stdio.h>
#include "vertex.h"
#include "IntArray.h"

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
***/

// 07212020
struct Big {
	int x, y, z;
	int data[4096];
};

void func2(Big &big) {
//	big->x = 100;
	big.x = 100;
}

void func(int *one) {
	*one = 33; // dereferencing variable when accessing value
}

void test() {
	IntArray a(100), b(123);

	IntArray c(a); // copy constructor
}
// End 07212020

int main() {
	Vertex v;
	int i = 23;
//	Big j;
//	j.x = 0;

	test();

//	v.setToZero();
//	v.set(9, 10, 12);

//	func(&i); // Passing address of a variable
//	func2(&j);
//	func2(j);

//	printf("%d\n", i);
//	printf("Memory reference j: %d\n", j);

//	float f = 6.0f;
//	float &fr = f;

//	fr = 100.0f;
//	printf("%f\n", f); // F value will change 100 due to referencing from pointer fr

//	printf("Using vertex header: %d\n", int(v.getY()));

	return 0;
}