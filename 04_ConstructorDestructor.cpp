#include <iostream>

using namespace std;

class tester {
	static int count;
public:
	tester(){
		count++;
		cout << "\nNo. of objects created = " << count;
	}
	~tester(){
		count--;
		cout << "\nNo. of objects left = " << count;
	}
};

int tester::count;

int main() {
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

	return 0;
}
