#include <iostream>
#include <math.h>
#include "06_ComplexPolarRectangular.hpp"

using namespace std;

//Complex Numbers in Rectangular and Polar coordinates
Rectangular::Rectangular(){ x = y = 0; } //Construct a point at origin
Rectangular::Rectangular(float x_coordinate, float y_coordinate){
	x = x_coordinate;
	y = y_coordinate;
}
float Rectangular::getx(){ return x; }
float Rectangular::gety(){ return y; }
void Rectangular::display(){
	cout << x << " + " << y << "j" << endl;
}

//Definition
Rectangular operator+(Rectangular point1, Rectangular point2){
	float x = point1.x + point2.x;
	float y = point1.y + point2.y;
	return Rectangular(x,y);
}

Rectangular operator*(Rectangular point1, Rectangular point2){
	float x = (point1.x*point2.x) - (point1.y*point2.y);
	float y = (point1.x*point2.y) + (point1.y*point2.x);
	return Rectangular(x,y);
}

Rectangular operator*(int m, Rectangular point){
	return Rectangular(m*point.x, m*point.y);
}

Rectangular Rectangular :: operator*(int m){
	return Rectangular(m*x, m*y);
}

Rectangular Rectangular :: operator-(Rectangular z){
	Rectangular temp;
	temp.x = x - z.x;
	temp.y = y - z.y;
	return temp;
}
Rectangular Rectangular :: operator-(){ return Rectangular(-x, -y); }

Polar::Polar(){ r = a = 0; } //Construct a point at origin
Polar::Polar(float radius, float angle){ //Construct a point given its radius and angle
	r = radius;
	a = angle;
}
Polar::Polar(Rectangular rect){
	float x = rect.getx();
	float y = rect.gety();
	r = sqrt(x*x + y*y);
	a = atan(y/x);

	//Return angle in a range of [-Pi,Pi)
	if (x<0){
		if (y>0) a += M_PI;
		else a -= M_PI;
	}
}

void Polar::display(){	cout << r << " * exp[" << a << "j]" << endl; }

//Defining overloaded operator outside the class
Polar Polar :: operator-(){
	Polar temp(r, a);
	if (a >= 0) temp.a -= M_PI;
	else temp.a += M_PI;
	return temp;
}

Polar operator-(Polar point1, Polar point2){
	return Rectangular(point1) - Rectangular(point2);
}

// Rectangular is returned as Polar due to type-casting
Polar operator+(Polar point1, Polar point2){
	return Rectangular(point1) + Rectangular(point2);
}

Polar operator*(Polar point1, Polar point2){
	return Polar(point1.r*point2.r, point1.a+point2.a);
}

Polar::operator Rectangular(){	return Rectangular(r*cos(a),r*sin(a)); }

void ComplexPolarRectangular(){
	Polar point1 = Polar(Rectangular(-1, 0));
	cout << "Point 1" << endl;
	point1.display();

	Polar point2 = Polar(Rectangular(1, 1));
	cout << "\nPoint 2" << endl;
	cout << "Rectangular Coordinates: \t";
	Rectangular(point2).display();
	cout << "Polar Coordinates: \t\t";
	point2.display();

	Rectangular point3 = Rectangular(point2) - Rectangular(point1);
	cout << "\nPoint 3" << endl;
	cout << "Rectangular Coordinates: \t";
	(-point3).display();
	cout << "Polar Coordinates: \t\t";
	(-Polar(point3)).display();

	Polar point4 = point1-point2;
	cout << "\nPoint 4" << endl;
	cout << "Rectangular Coordinates: \t";
	(Rectangular(point4)).display();
	cout << "Polar Coordinates: \t\t";
	point4.display();

	cout << "\nPoint 5" << endl;
	Rectangular point5 = point3*3;
	point5.display();
}
