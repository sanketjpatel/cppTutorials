#include <iostream>

using namespace std;

class base{
public:
	int b;
	base(int x) { b = x; }
	void show(){
		cout << "b = " << b << endl;
	}
};

class derived: public base{
public:
	int d;
	derived(int y):
	base(4){
//		base(x);
		d = y;
	}
	void show(){
		cout << "d = " << d << endl;
	}
};

void PointersToDerived(){
	base b(45);
	derived d(132);

	base *bptr = &b;
	bptr->show();
	bptr = &d;  //The pointer can point to an object of a derived class
	bptr->show();  //The pointer will however be able to access members of only the base class in the derived object

	((derived *)bptr)->show();  //Type cast the pointer to access members of the derived class in the derived object
	((derived *)bptr)->base::show();  //The type cast pointer can access members belonging to both the classes
	((derived *)bptr)->b = 78;
	((derived *)bptr)->base::show();
}
