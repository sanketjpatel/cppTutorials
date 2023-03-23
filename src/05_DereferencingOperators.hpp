#ifndef DereferencingOperators_HPP
#define DereferencingOperators_HPP


// Class declaration
class Person{
	//Private members
	int age;
	int weight;
//Public members
public:
	//Constructor with no args
	Person();

	//Constructor with args
	Person(int a, int b);

	//Method
	void setDetails(int a, int b);

	//Method
	void getDetails(void);

	//Friend function declaration
	friend int sum(Person);

    //Friend function declaration
	friend int sumPointer(Person *);
};

void DereferencingOperators();

#endif