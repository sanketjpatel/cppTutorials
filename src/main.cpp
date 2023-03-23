#include <iostream>
#include "01_HelloWorld.hpp"
#include "02_FunctionSquareRoot.hpp"
#include "03_ClassesAndObjects.hpp"
#include "04_ConstructorDestructor.hpp"
#include "05_DereferencingOperators.hpp"
#include "06_ComplexPolarRectangular.hpp"
#include "07_Inheritance.hpp"
#include "08_ThisPointer.hpp"
#include "09_PointersToDerived.hpp"
#include "10_VirtualFunctions.hpp"
#include "11_InputOutput.hpp"
#include "12_IOManip.hpp"
#include "13_FileInteraction.hpp"
#include "14_Templates.hpp"
#include "15_ExceptionHandling.hpp"
#include "16_VectorListMap.hpp"
#include "17_Strings.hpp"
#include "18_CharList.hpp"
#include "19_Singleton.hpp"

void prompt() {
	std::cout << "Press ENTER to continue..." << std::endl;
	system("read");
}

//main method returns an int value to the operating system. Receiving a 0 means the method executed correctly.
int main(){
	HelloWorld();
	prompt();

	// FunctionSquareRoot();
	// prompt();

	// ClassesAndObjects();
	// prompt();

	// ConstructorDestructor();
	// prompt();

	// DereferencingOperators();
	// prompt();

	// ComplexPolarRectangular();
	// prompt();

	// Inheritance();
	// prompt();

	// ThisPointer();
	// prompt();

	// PointersToDerived();
	// prompt();

	// VirtualFunctions();
	// prompt();

	// InputOutput();
	// prompt();

	// IOManip();
	// prompt();
	
	// FileInteraction();
	// prompt();

	// Templates();
	// prompt();

	// ExceptionHandling();
	// prompt();
	
	// VectorListMap();
	// prompt();

	// Strings();
	// prompt();
	CharList();
	prompt();

	Singleton();
	prompt();
	return 0;
}
