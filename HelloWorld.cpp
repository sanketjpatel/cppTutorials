//============================================================================
// Name        : HelloWorld.cpp
// Author      : Sanket Patel
// Version     : 0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

/*
 long double squareroot(long double z){
 long double a = z;
 long double error = z*1E-6;
 while( !(((a*a - z)<=error) && ((a*a - z)>=-error)) ) {
 a = (a + (z/a))/2; //Newton Raphson
 }
 return a;
 }
 */

class tester {
	int number;
	static int count;
public:
	void getdata(int a) {
		number = a;
		count++;
	}
	void display(void) {
		cout << "Number = " << number << endl;
		cout << "Count = " << count << endl;
	}
};

int tester::count;

//int main() {
//	tester a, b, c;
//	a.display();
//	a.getdata(100);
//	a.display();
//	b.getdata(220);
//	b.display();
//	a.display();
//	c.getdata(450);
//	c.display();
//	cout << "Check all counts now!" << endl;
//	a.display();
//	b.display();
//	c.display();
//	cout << "Program terminating" << endl;
//	return 0;
//}
