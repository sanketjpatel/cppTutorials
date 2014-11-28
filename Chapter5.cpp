/*
 * Chapter5.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: sanket
 */

#include <iostream>;

using namespace std;

class Major{
	int x,y;
	static int counter;
//	static void check(void);
public:
	void testcheck(void);
	void setMajor(int, int);
	void checkMajor(Major, int);
};

int Major :: counter = 10;

void Major :: setMajor(int xin, int yin){
	x = xin;
	y = yin;
	counter++;
}

void Major :: checkMajor(Major a, int b){
	cout << "This works!"<<endl;
	cout << "Counter = "<< counter << endl;
}

int main(){
	Major a;
	a.setMajor(300, 400);
	a.checkMajor(a, 4);
	return 0;
}


