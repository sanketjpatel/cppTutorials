#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void display(string & str){
	cout << setw(15) << "Size = " << str.size() << endl;
	cout << setw(15) << "Length = " << str.length() << endl;
	cout << setw(15) << "Capacity = " << str.capacity() << endl;
	cout << setw(15) << "Maximum size = " << str.max_size() << endl;
	cout << setw(15) << "Empty: " << (str.empty() ? "Yes" : "No") << endl << endl;
}

void Strings(){
	string s1("Road");
	string s2("Read");
	string s3("Red");
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl << endl;

	int x = s1.compare(s2);		// Compares strings lexicographically
	if (x == 0)	cout << "s1 == s2" << endl;
	else if (x > 0) cout << "s1 > s2" << endl;
	else cout << "s1 < s2" << endl;

	int a = s1.compare(0, 2, s2, 0, 2);
	int b = s2.compare(0, 2, s1, 0, 2);
	int c = s2.compare(0, 2, s3, 0, 2);
	int d = s2.compare(s2.size()-1, 1, s3, s3.size()-1, 1);

	cout << "\na = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << "\nBefore swap: \n";
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	s1.swap(s2);
	cout << "\nAfter swap: \n";
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl << endl;

	display(s2);
}
