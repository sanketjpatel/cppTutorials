#include <iostream>
#include <cmath>
#include "10_VirtualFunctions.hpp"

using namespace std;

void Shape::getData(){};

// Function overloading
void Shape::getData(double primary, double secondary){
	x = primary;
	y = secondary;
}

void Shape::displayArea(){};

// Destructor is made virtual so that destructor in the derived class is invoked
Shape::~Shape(){
	cout << "Destroying Shape with dimensions: " << x << ", " << y << endl;
}

void Triangle::getData(){
	double base, height;
	cout << "Enter base: ";
	cin >> base;
	cout << "Enter height: ";
	cin >> height;
	Shape::getData(base, height);
}

void Triangle::displayArea(){
	cout << "Area of Triangle = " << x*y/2 << endl;
}

void Triangle::displayPerimeter(){
	cout << "Insufficient information\n";
}

Triangle::~Triangle(){ cout << "\nDeleted Triangle" << endl; }

void Rectangle::getData(){
	double length, width;
	cout << "Enter length: ";
	cin >> length;
	cout << "Enter width: ";
	cin >> width;
	Shape::getData(length, width);
}

void Rectangle::displayArea(){
	cout << "Area of Rectangle = " << x*y << endl;
}

void Rectangle::displayPerimeter(){
	cout << "Perimeter = " << 2*(x+y) << endl;
}

Rectangle::~Rectangle(){ cout << "\nDeleted Rectangle" << endl; }

void Circle::getData(){
	double radius;
	cout << "Enter radius: ";
	cin >> radius;
	Shape::getData(radius, 0);
}

void Circle::displayPerimeter(){
	cout << "Circumference = " << 2*x*M_PI << endl;
}

void Circle::displayArea(){
	cout << "Area of Circle = " << M_PI*x*x << endl;
}

Circle::~Circle(){	cout << "\nDeleted Circle" << endl; }

void VirtualFunctions(){
	int n;
	cout << "Number of Shapes: ";
	cin >> n;

	Shape* Shapes[n];
	int Shapetype;

	for(int i=0; i<n; i++){
		cout << "\nEnter Shape type (1=Triangle; 2=Rectangle; 3=Circle; default=Triangle): ";
		cin >> Shapetype;

		switch(Shapetype){
		case 1:
			Shapes[i] = new Triangle;
			break;
		case 2:
			Shapes[i] = new Rectangle;
			break;
		case 3:
			Shapes[i] = new Circle;
			break;
		default:
			Shapes[i] = new Rectangle;
		}

		Shapes[i] -> getData();
	}

	for (int i = 0; i<n; i++){
		cout << "\n***** Shape " << i+1 << " address: " << Shapes[i] <<" *****" << endl;
		Shapes[i] -> displayArea();
		Shapes[i] -> displayPerimeter();
	}

	for (int i=n-1; i>=0; i--){
		/*
		 * This invokes the destructor of the derived class followed by the destructor of the base class,
		 * since the destructor in the base class has been defined as virtual.
		 * If the destructor in the base class is not virtual, then the derived class destructor is not invoked.
		 */
		delete Shapes[i];
	}
}
