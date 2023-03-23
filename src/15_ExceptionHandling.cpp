#include <iostream>
#include "15_ExceptionHandling.hpp"

using namespace std;

void testThrows(int x) {
	if (x==0) throw 'x';
	else if (x==1) throw x;
	else if (x==-1) throw 1.0;
	cout << "End of function block \n\n";
}

void tryCatchWithTestThrows(int x) {
	try{
		cout << "testing Throw Restrictions \n\n";
		cout << "x == " << x << endl;
		testThrows(x);
		cout << "ENDING TRY\n";
	}
	catch(char c){
		cout << "Caught a character: "<< c << endl;
	}
	catch (int m){
		cout << "Caught an integer: " << m << endl;
	}
	catch (double d){
		cout << "Caught a double: " << d << endl;
	}
	cout << "\nEnd of try-catch system \n\n";
}

/*
 * On encountering a throw statement, the program leaves the try block
 * and looks for the corresponding catch block.
 * When a throw is not caught by any of the catch statements,
 * the program terminates indicating so.
 */

void ExceptionHandling() {
	tryCatchWithTestThrows(2);
	tryCatchWithTestThrows(0);
	tryCatchWithTestThrows(1);
	tryCatchWithTestThrows(-1);
}
