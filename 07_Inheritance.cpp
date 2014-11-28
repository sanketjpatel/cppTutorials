#include <iostream>

using namespace std;

class person{
	int code;
	char* name;
protected:
	person(int givenCode, char* givenName){
		code = givenCode;
		name = givenName;
	}
	void getCode(){ cout << "Code: " << code << endl; }
	void getName(){	cout << "Name: " << name << endl; }
public:
	void display(){
		getCode();
		getName();
	}
};

class account : virtual public person{
	float pay;

public:
	account(int code, char* name, float givenPay):
	person(code, name){	pay = givenPay;	}
	void display(){ cout << "Pay: " << pay << endl; }
};

class admin : virtual public person{
	int experience;

public:
	admin(int code, char* name, int givenExp):
	person(code, name){ experience = givenExp; }
	void display(){ cout << "Experience: " << experience << " years" << endl; }
};

class master : public account, public admin{
public:
	master(char* name, int code, int experience, float pay):
		person(code, name), account(code, name, pay), admin(code, name, experience)
	{
	}
	void display(){
		cout << "\n";
		person::display();
		account::display();
		admin::display();
	}
};

void Inheritance(){


	cout << "Enter code: ";
	int code;
	cin >> code;

	cout << "Enter name: ";
	char* name;
	cin >> name;

	cout << "Enter the amount of experience in years: ";
	int experience;
	cin >> experience;

	cout << "Enter the pay: ";
	float pay;
	cin >> pay;

	master sanket(name, code, experience, pay);
	sanket.display();
}
