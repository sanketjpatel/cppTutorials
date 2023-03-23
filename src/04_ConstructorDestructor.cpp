#include <iostream>
#include "04_ConstructorDestructor.hpp"

using namespace std;

	tester::tester(){
		count++;
		cout << "No. of objects created = " << count << endl;
	}
	tester::~tester(){
		count--;
		cout << "No. of objects left = " << count << endl;
	}


int tester::count;

void ConstructorDestructor() {
	cout << "\n\nENTER MAIN\n";
	tester a, b, c, d;
	{
		cout << "\n\nENTER BLOCK1\n";
		tester e;
	}

	{
		cout << "\n\nENTER BLOCK2\n";
		tester f;
	}

	cout << "\n\nRE-ENTER MAIN\n";
}
