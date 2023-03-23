#ifndef Inheritance_HPP
#define Inheritance_HPP

class BasePerson {
	int code;
	std::string name;
protected:
	BasePerson(int givenCode, std::string givenName);
	int getCode();
	std::string getName();
public:
	void display();
};

class Account : virtual public BasePerson {
	float pay;

public:
	Account(int code, std::string name, float givenPay);
	void display();
};

class Admin : virtual public BasePerson {
	int experience;

public:
	Admin(int code, std::string name, int givenExp);
	void display();
};

class Master : public Account, public Admin{
public:
	Master(std::string name, int code, int experience, float pay);
	void display();
};

void Inheritance();

#endif