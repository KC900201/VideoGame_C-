#include <stdio.h>
#include "vertex.h"
#include "IntArray.h"
#include <string>
#include <iostream>

using namespace std;

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
07252020	  Operator Overloading (Most important chapter and most difficult to understand); cout
07262020	  Conversion Operators (implicit conversion)
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

//	IntArray c(a); // copy constructor, ugly
	IntArray c = a; // copy constructor, more standardized writing

	// 07252020
	IntArray d(1);
	d = b;
	d = 5;
	printf("Operator overloading 1\n", d.get(0));
	printf("%d\n", d.get(0));

	for (int i = 0; i < 100; i++) {
		a.set(i, i * 2);
	}

	for (int i = 0; i < 400; i++) {
		b.set(i, i * 4);
	}

	// + operator overloading - 07252020
	IntArray e = a + b;
	e[101] = 550;
	printf("Operator overloading 2\n", d.get(0));
//	printf("%d\n", e.get(101));
	printf("%d\n", e[101]);

}
// End 07212020

// run cout 
void trycout() {
	cout << "First sentence" << endl;
	cout << "2nd sentence" << endl;
	cout << 34543535 << endl;

}

// 07262020
static int numberofAdd = 0;

class EncapsulatedInt {

public:
	// default constructor
	EncapsulatedInt() {

	}

	EncapsulatedInt(int someInt) {
		i = someInt;
	}

	// operators
	EncapsulatedInt operator +(const EncapsulatedInt &rhs) {
		numberofAdd++;
		return EncapsulatedInt(i + rhs.i);
	}

	// Implicit conversion
	operator int() {
		return i;
	}

private:
	int i = 0;
};

void testImplicit(int i) {
	cout << "value returns " << i << endl;
}

int main() {
	Vertex v;
//	Big j;
//	j.x = 0;

// 07262020
	EncapsulatedInt a, b(100);
	auto c = a + b + a;
	int i = c;

	testImplicit(c);

	cout << numberofAdd << endl;

//	test();

//	trycout();

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