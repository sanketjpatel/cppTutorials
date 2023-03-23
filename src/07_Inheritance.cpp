#include <iostream>
#include <string>
#include "07_Inheritance.hpp"

using namespace std;

BasePerson::BasePerson(int givenCode, string givenName){
	code = givenCode;
	name = givenName;
}
int BasePerson::getCode(){ return code; }
string BasePerson::getName(){ return name; }
void BasePerson::display(){
	cout << "Code: " << getCode() << endl;
	cout << "Name: " << getName() << endl;
}

Account::Account(int code, string name, float givenPay):BasePerson(code, name){ pay = givenPay; }
void Account::display(){ cout << "Pay: " << pay << endl; }



Admin::Admin(int code, string name, int givenExp):BasePerson(code, name){ experience = givenExp; }
void Admin::display(){ cout << "Experience: " << experience << " years" << endl; }


Master::Master(string name, int code, int experience, float pay):
	BasePerson(code, name), 
	Account(code, name, pay), 
	Admin(code, name, experience){
}
void Master::display(){
	cout << "\n";
	BasePerson::display();
	Account::display();
	Admin::display();
}

void Inheritance(){

	cout << "Enter code: ";
	int code;
	cin >> code;

	cout << "Enter name: ";
	string name;
	cin >> name;

	cout << "Enter the amount of experience in years: ";
	int experience;
	cin >> experience;

	cout << "Enter the pay: ";
	float pay;
	cin >> pay;

	Master sanket(name, code, experience, pay);
	sanket.display();
}
