///*
// * ClassesAndObjects.cpp
// *
// *  Created on: Nov 22, 2014
// *      Author: sanket
// */
//
//#include <iostream>;
//
//using namespace std;
//
////Declare a class
//class Major{
//	//private members
//	int x,y;
//	static int counter; //static members are common to all objects of the class
////	static void check(void);
//public:
//	void testcheck(void);
//	void setMajor(int, int);
//	void changeMajor(Major, int, int);
//};
//
//int Major :: counter = 10;
//
//void Major :: setMajor(int xin, int yin){
//	x = xin;
//	y = yin;
//	counter++;
//	cout << "Counter = " << counter << endl;
//}
//
//void Major :: changeMajor(Major a, int b, int c){
//	a.x = b;
//	a.y = c;
//	counter--;
//	cout << "Counter = " << counter << endl;
//}
//
//int main(){
//	Major a;
//	a.setMajor(300, 400);
//	a.changeMajor(a, 4, 7);
//	return 0;
//}
//
//
