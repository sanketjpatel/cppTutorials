#include <iostream>
#include "03_ClassesAndObjects.hpp"

using namespace std;

int Major ::counter = 10;

void Major ::setMajor(int xin, int yin) {
	x = xin;
	y = yin;
	counter++;
	cout << "Counter = " << counter << endl;
}

void Major ::changeMajor(Major a, int b, int c) {
	a.x = b;
	a.y = c;
	counter--;
	cout << "Counter = " << counter << endl;
}

void ClassesAndObjects() {
	Major a;
	a.setMajor(300, 400);
	a.changeMajor(a, 4, 7);
	Major b;
	b.setMajor(50, 690);
	a.changeMajor(b, 40, 30);
}
