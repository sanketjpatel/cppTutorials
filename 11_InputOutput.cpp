#include <iostream>;

using namespace std;

void InputOutput(){

	int counter = 0;
	char c;

	cout << "Type in a line:\n";
	cin.get(c);  //get method with an argument returns the argument with the character
	//get method will accept characters, spaces and newlines

	while(c != '\n'){
		cout.put(c);
		counter++;
		c = cin.get();  //get method with void argument returns a char, which needs to be assigned
	}

	cout << "\nNumber of characters = " << counter << endl;
}
