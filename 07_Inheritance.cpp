#include <iostream>

using namespace std;

class person{
	int code;
	char* name;
protected:
	void setCode(int x){ code = x; }
	void setName(char* givenName){ name = givenName; }
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
protected:
	void setPay(float givenPay){ pay = givenPay; }
public:
	void display(){ cout << "Pay: " << pay << endl; }
};

class admin : virtual public person{
	int experience;
protected:
	void setExperience(int givenExp){ experience = givenExp; }
public:
	void display(){ cout << "Experience: " << experience << " years" << endl; }
};

class master : public account, public admin{
public:
	master(char* name, int code, int experience, float pay){
		setName(name);
		setCode(code);
		setExperience(experience);
		setPay(pay);
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
