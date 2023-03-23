#include <iostream>
#include "09_PointersToDerived.hpp"

using namespace std;


BaseClass::BaseClass(int x) { b = x; }
void BaseClass::show(){
	cout << "b = " << b << endl;
}

DerivedClass::DerivedClass(int y):
BaseClass(4){
	d = y;
}
void DerivedClass::show(){
	cout << "d = " << d << endl;
}

void PointersToDerived(){
	BaseClass b(45);
	DerivedClass d(132);

	BaseClass *bptr = &b;
	bptr->show();
	bptr = &d;  //The pointer can point to an object of a DerivedClass class
	bptr->show();  //The pointer will however be able to access members of only the BaseClass class in the DerivedClass object

	((DerivedClass *)bptr)->show();  //Type cast the pointer to access members of the DerivedClass class in the object
	((DerivedClass *)bptr)->BaseClass::show();  //The type cast pointer can access members belonging to both the classes
	((DerivedClass *)bptr)->b = 78;
	((DerivedClass *)bptr)->BaseClass::show();
}
