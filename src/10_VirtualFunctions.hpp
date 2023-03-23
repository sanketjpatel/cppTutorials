#ifndef VirtualFunctions_HPP
#define VirtualFunctions_HPP



class Shape {
protected:
	double x, y;
public:
	/*
	 * When a method is made virtual,
	 * the pointer will invoke the method in the derived class.
	 */
	virtual void getData();

	// Function overloading
	void getData(double primary, double secondary);

	virtual void displayArea();

	// This is a pure virtual function. As a result, the class is abstract
	virtual void displayPerimeter() = 0;

	// Destructor is made virtual so that destructor in the derived class is invoked
	virtual ~Shape();
};

class Triangle : public Shape{
public:
	void getData();
	void displayArea();
	void displayPerimeter();
	~Triangle();
};

class Rectangle : public Shape{
public:
	void getData();
	void displayArea();
	void displayPerimeter();
	~Rectangle();
};

class Circle : public Shape{
public:
	void getData();
	void displayPerimeter();
	void displayArea();
	~Circle();
};

void VirtualFunctions();

#endif