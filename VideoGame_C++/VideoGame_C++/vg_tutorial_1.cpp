#include <stdio.h>
#include "vertex.h"
#include "IntArray.h"
#include "Array.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <functional> // 08202020
#include <thread> // 08202020
#include <atomic> // 08202020

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
08062020	  New & delete (memory alllocation)
08092020	  Template (c++ syntax)
08142020	  Data Structures example (C++)
08192020	  Smart Pointers in C++ (C++ 11 standard)
08202020      Lambda Delegation (C++ 11 standard)
			  Threads for Game Programming - Intro
***/

// 08092020
template <typename NumberType>
NumberType power2(NumberType i) {
	return i * i;
}

Array<float> *createArray() {
	Array<float> a(100), b(200);

	for (int i = 0; i < 50; i++) {
		a.set(i, i * 2);
	}

	for (int i = 0; i < 50; i++) {
		b.set(i, i * 4);
	}

	printf("Running create array\n");

	Array<float> *c = new Array<float>(a + b); // copy constructor, using new to dynamic mem alloc cast
//	c[30] = 51; // syntax will probably cause memory crash
	c->set(30, 99.9f); // set notation, set 30th index to 50, less likely to crash

	return c;

}

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

/*
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
*/
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

// 08062020 memory allocation concept
int tryMemAlloc() {
	unsigned char *ptr = (unsigned char *)malloc(1024);
	/* new and delete cmd as a new way of memory allocation */
	ptr = new unsigned char[1024];

	delete ptr;

	return 0;
}
/*
IntArray *createArray() {
	IntArray a(100), b(200);

	for (int i = 0; i < 50; i++) {
		a.set(i, i * 2);
	}

	for (int i = 0; i < 50; i++) {
		b.set(i, i * 4);
	}

	printf("Running create array\n");

	IntArray *c = new IntArray(a + b); // copy constructor, using new to dynamic mem alloc cast
//	c[30] = 51; // syntax will probably cause memory crash
	c->set(30, 999); // set notation, set 30th index to 50, less likely to crash

	return c;
}
*/

void testDataStruct() {
//	vector<int> v;
	list<int> v;

	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(6);
	v.push_front(10023);

	printf("Printing iterator list \n");
	/*
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl; // deferencing
	}
	*/

	auto it = ++v.begin();
	v.insert(it, 189);

	for (auto &i : v) { // use auto in complex type, iterate by referencing
		cout << i << endl;
	}

}

// 08202020
static void gLambdaFunc(function<void ()> aFunction) {
	aFunction();
}

// 08192020
class Banana {
public:
	typedef std::shared_ptr<Banana> Pointer;
	typedef std::weak_ptr<Banana> WeakPointer;

	~Banana()
	{
		std::cout << "Test Pointer!\n" << std::endl;
	}

	// 08202020
	void testLambdaDel() { // Lambda delegation function
		auto x = 10; // Auto variable - infer variable type based on assigned value

		auto func = []() {
			cout << "Hellow Lambda" << endl;
		};
	}

private:
};

Banana::Pointer gBanana = nullptr;
Banana::WeakPointer wBanana;

static void testBanPointer(Banana::Pointer ban) {
//	gBanana = ban;
	wBanana = ban;

	cout << "Weak Pointer Function\n" << endl;
}

int main() {
	Vertex v;
//	Big j;
//	j.x = 0;

// 07262020
	/*
	EncapsulatedInt a, b(100);
	auto c = a + b + a;
	int i = c;

	testImplicit(c);

	cout << numberofAdd << endl;
	*/

// 08142020
//	testDataStruct();

// 08192020
	Banana::Pointer b = make_shared<Banana>();
	testBanPointer(b);
	b = nullptr;

	if (gBanana) {
		cout << "Lol!" << endl;
	}
	else if (wBanana.lock()) {
		cout << "weak Lol!" << endl;
	}

// 08092020
//	cout << power2(2) << endl;
//	cout << power2(0.5f) << endl;
//	Array<float> *result = createArray();

//	cout << result->get(30) << endl;
//	delete result;
 
	// 08062020
//	IntArray* result = createArray();

//	cout << result->get(30) << endl;

//	delete result; // de-allocate memory of result variable

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