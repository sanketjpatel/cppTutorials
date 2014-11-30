#include <iostream>
#include <cstring>

using namespace std;

class person{
	float age;
	char name[32];
public:
	person(char *s, float a){
		strcpy(name, s);
		age = a;
	}

	void setAge(float a){
		age = a;
	}

	person & greater(person & x){
		if(x.age >= age) return x;
		else return *this;
	}

	void display(){
		cout << "Name: " << name << endl
				<< "Age: " << age << endl;
	}
};

void ThisPointer(){
	person P1("Sanket", 23);
	person P2("Tejas", 22);
	person P3("Pankaj", 24);

	cout << "\nObject P1" << endl;
	P1.display();

	P1.greater(P2).setAge(1);  //greater returns P1 and setAge changes its value
	person P = P2.greater(P3); //assignment operator copies the contents stored in the address on the right to a new address which is assigned to the identifier on the left.

	cout << "\nP: " << &P << endl;
	cout << "P1: " << &P1 << endl;
	cout << "P2: " << &P2 << endl;
	cout << "P3: " << &P3 << endl;
	cout << "P3: " << &(P3.greater(P2)) << endl;

	cout << "\nObject P" << endl;
	P.display();

	cout << "\nObject P" << endl;
	P.setAge(1);
	P.display();

	cout << "\nObject P1" << endl;
	person *p = &P1;
	p->display();
	cout << "\nObject P2" << endl;
	P2.display();
}
