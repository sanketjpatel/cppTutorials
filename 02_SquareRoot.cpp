//Calculates squareroot of a positive number.

#include <iostream>

using namespace std;

//Function declaration and definition
long double squareroot(long double z){
	long double a = z;
	long double error = (z*1E-12)/2; //Defining an error margin
	while( !(((a*a - z)<=error) && ((a*a - z)>=-error)) ) {
//		cout << a << endl; //In case you wanted to see the value at each iteration
		a = (a + (z/a))/2; //Newton Raphson
	}
	return a;
}

int main(){

	cout << "Enter a non-negative number: ";
	int x;
	cin >> x;

	cout << "Square Root = " << squareroot(x) << endl;

	return 0;
}
