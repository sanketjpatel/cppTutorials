#include <iostream>
#include "14_Templates.hpp"

using namespace std;

void Templates(){
	int x[] = {35, 48, 67, 55, 70, -400};
	int y[] = {12, 242, 34, 123, 23, 50};

	cout << endl << "x: " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "Size of &x = " << sizeof(&x) << endl;
	cout << "Size of x: " << sizeof(x) << endl;
	cout << x[0] << endl;
	cout << x[1] << endl;
	cout << x[2] << endl;
	cout << x[3] << endl;
	cout << x[4] << endl;
	cout << x[5] << endl;

	MyVector<int> v1(x, sizeof(x)/sizeof(x[0]));
	MyVector<int> v2(y, sizeof(y)/sizeof(y[0]));

	cout << "\nv1.print()" << endl;
	v1.print();
	cout << "\nv2.print()" << endl;
	v2.print();

	cout << "\n\nv1*v2: " << endl;
	cout << v1*v2 << endl;
}
