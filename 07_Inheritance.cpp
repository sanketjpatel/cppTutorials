#include <iostream>
#include <string>

using namespace std;

class person{
	int code;
	string name;
protected:
	person(int givenCode, string givenName){
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
	account(int code, string name, float givenPay):
	person(code, name){ pay = givenPay; }
	void display(){ cout << "Pay: " << pay << endl; }
};

class admin : virtual public person{
	int experience;

public:
	admin(int code, string name, int givenExp):
	person(code, name){ experience = givenExp; }
	void display(){ cout << "Experience: " << experience << " years" << endl; }
};

class master : public account, public admin{
public:
	master(string name, int code, int experience, float pay):
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
	string name;
	getline(cin, name);

	cout << "Enter the amount of experience in years: ";
	int experience;
	cin >> experience;

	cout << "Enter the pay: ";
	float pay;
	cin >> pay;

	master sanket(name, code, experience, pay);
	sanket.display();
}
