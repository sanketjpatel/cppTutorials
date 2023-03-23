#include <iostream>
#include "05_DereferencingOperators.hpp"

using namespace std;


Person::Person(){ 
	age = 0; 
	weight = 0;
}

//Constructor with args
Person::Person(int a, int b){ 
	age = a; 
	weight = b; 
}

//Method
void Person::setDetails(int a, int b){
	age = a; weight = b;
}

//Member function definition, uses scope resolution operator because defined outside the class
void Person::getDetails(){
	cout << "Age = " << age << endl;
	cout << "Weight = " << weight << endl;
}

//Member function pointer declaration and definition
void (Person :: *pSetDetails)(int, int) = &Person::setDetails;

//Friend function definition, notice how it does not use scope resolution operator. It is just like a normal function definition.
//Summary of Dereferencing operators in the expressions used inside this function
int sum(Person x){
	int Person ::* page = &Person :: age;
	int Person ::* pweight = &Person :: weight;
	Person *px = &x;
	int S = x.*page + px->*pweight;
	return S;
}

int sumPointer(Person* px){
	int Person ::* page = &Person :: age;
	int Person ::* pweight = &Person :: weight;
	int S = px->*page + px->*pweight;
	return S;
}

void DereferencingOperators(){
	Person person;

	// Calling the function pointer
	(person.*pSetDetails)(14,45);
	cout << "Sum = " << sum(person) << endl;

	Person *pperson = &person;
	(pperson ->* pSetDetails)(23,34);
	cout << "Sum = " << sum(*pperson) << endl;

	Person newperson(28,56);
	newperson.getDetails();
	newperson.setDetails(12, 13);
	newperson.getDetails();

	Person *pnewperson = &newperson;
	(pnewperson ->* pSetDetails)(123,23);
	pnewperson -> getDetails();
	cout << "Sum = " << sum(*(&newperson)) << endl;
}
