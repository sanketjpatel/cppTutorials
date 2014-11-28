#include <iostream>

using namespace std;

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

int main() {
	tester a, b, c;
	a.display();
	a.getdata(100);
	a.display();
	b.getdata(220);
	b.display();
	a.display();
	c.getdata(450);
	c.display();
	cout << "Check all counts now!" << endl;
	a.display();
	b.display();
	c.display();
	cout << "Program terminating" << endl;
	return 0;
}
