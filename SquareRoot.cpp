#include <iostream>

using namespace std;

long double squareroot(long double z){
	long double a = z;
	long double error = z*1E-6;
	while( !(((a*a - z)<=error) && ((a*a - z)>=-error)) ) {
		a = (a + (z/a))/2; //Newton Raphson
	}
	return a;
}

int main(){

	int x = 65536;
	cout << "Square Root of " << x << " is =";
	cout << squareroot(x) << endl;

	return 0;
}
