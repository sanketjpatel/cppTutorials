#include <iostream>
#include <iomanip>

using namespace std;

// User-defined manipulators
ostream & currency(ostream & output){
	output << "$";
	return output;
}

ostream & form(ostream & output){
	output.setf(ios::showpoint);
	output.fill('*');
	output.precision(2);
	output << setiosflags(ios::fixed) << setw(15);
	return output;
}

void IOManip(){
	float amount;
	cout << "Enter amount: ";
	cin >> amount;
	cout << currency << form << amount;
}
