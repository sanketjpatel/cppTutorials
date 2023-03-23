#ifndef ClassesAndObjects_HPP
#define ClassesAndObjects_HPP

// Declare a class
class Major
{
	// private members
	int x, y;
	static int counter; // static members are common to all objects of the class
	//	static void check(void);
public:
	void testcheck(void);
	void setMajor(int, int);
	void changeMajor(Major, int, int);
};

void ClassesAndObjects();
#endif