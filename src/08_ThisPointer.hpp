#ifndef ThisPointer_HPP
#define ThisPointer_HPP

class ThisPerson{
	float age;
	std::string name;
public:
	ThisPerson(std::string s, float a);
	void setAge(float a);
	ThisPerson & greater(ThisPerson & x);
	void display();
};

void ThisPointer();

#endif