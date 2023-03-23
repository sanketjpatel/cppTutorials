#ifndef PointersToDerivedClass_HPP
#define PointersToDerivedClass_HPP

class BaseClass{
public:
	int b;
	BaseClass(int x);
	void show();
};

class DerivedClass: public BaseClass{
public:
	int d;
	DerivedClass(int y);
	void show();
};

void PointersToDerived();
#endif