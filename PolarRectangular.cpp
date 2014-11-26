#include <iostream>
#include <math.h>

using namespace std;

//class Polar;

//Complex Numbers in Rectangular and Polar coordinates

//class Rectangular;
class Rectangular{
	float x, y;
public:
	Rectangular(){ x = y = 0; } //Construct a point at origin

	Rectangular(float xcoord, float ycoord){
		x = xcoord;
		y = ycoord;
	}

	float getx(){ return x;	}
	float gety(){ return y;	}

	void display(){
		cout << x << " + " << y << "j" << endl;
	}

	//Declarations, operator overloading
	friend Rectangular operator+(Rectangular, Rectangular);
	friend Rectangular operator*(Rectangular, Rectangular);
	Rectangular operator-(Rectangular);

	//Declaring and defining an overloaded unary operator
	Rectangular operator-(){ return Rectangular(-x, -y); }
};

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

Rectangular Rectangular :: operator-(Rectangular z){
	Rectangular temp;
	temp.x = x - z.x;
	temp.y = y - z.y;
	return(temp);
}

class Polar{
	float r, a;
public:
	Polar(){ r = a = 0;	} //Construct a point at origin

	Polar(float radius, float angle){ //Construct a point given its radius and angle
		r = radius;
		a = angle;
	}

	//Constructor to convert Rectangular to Polar.
	//In a way, all constructors are type-converters.
	Polar(Rectangular rect){
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

//	float getr(){ return r;}
//	float geta(){ return a;}

	void display(){	cout << r << " * exp[" << a << "j]" << endl; }

	friend Polar operator+(Polar, Polar);
	friend Polar operator*(Polar, Polar);
	Polar operator-();
	friend Polar operator-(Polar, Polar);

	operator Rectangular(){	return Rectangular(r*cos(a),r*sin(a)); }
};

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

int main(){
	Polar point1 = Polar(Rectangular(-1, 0));
	Polar point2 = Polar(Rectangular(1, 1));
	Rectangular point3 = Rectangular(point2) - Rectangular(point1);
	Polar point4 = point1-point2;

	cout << "Point 1" << endl;
	point1.display();

	cout << "\nPoint 2" << endl;
	cout << "Rectangular Coordinates: \t";
	Rectangular(point2).display();
	cout << "Polar Coordinates: \t\t";
	point2.display();

	cout << "\nPoint 3" << endl;
	cout << "Rectangular Coordinates: \t";
	(-point3).display();
	cout << "Polar Coordinates: \t\t";
	(-Polar(point3)).display();

	cout << "\nPoint 4" << endl;
	cout << "Rectangular Coordinates: \t";
	(Rectangular(point4)).display();
	cout << "Polar Coordinates: \t\t";
	point4.display();

	return 0;
}
