//============================================================================
// Name        : HelloWorld.cpp
// Author      : Sanket Patel
// Version     : 0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//The bare basic structure of a C++ Program

#include <iostream>//To include the header file
//#include is the directive which causes the preprocessor to add the contents of the iostream file to the program
//iostream contains declarations for the identifier "cout and the operator "<<"
//Must include iostream whenever input/output statements are used in the program

using namespace std;
//Namespace defines a scope for the identifiers that are used in the program. std is the namespace where standard class libraries are defined.
//This will bring all the identifiers defined in the std to the current global scope.

//main method returns an int value to the operating system. Receiving a 0 means the method executed correctly.
void HelloWorld(){
	cout << "Hello World!" << endl;
}
