#ifndef ComplexPolarRectangular_HPP
#define ComplexPolarRectangular_HPP

//class Rectangular;
class Rectangular{
	float x, y;
public:
	Rectangular();

	Rectangular(float xcoord, float ycoord);

	float getx();
	float gety();

	void display();

	//Declaring and defining an overloaded unary operator
	Rectangular operator-();
	Rectangular operator*(int);
	Rectangular operator-(Rectangular);

    friend Rectangular operator+(Rectangular, Rectangular);
	friend Rectangular operator*(Rectangular, Rectangular);
	friend Rectangular operator*(int, Rectangular);
};

class Polar{
	float r, a;
public:
	Polar();

	Polar(float radius, float angle);

	//Constructor to convert Rectangular to Polar.
	//In a way, all constructors are type-converters.
	Polar(Rectangular rect);

//	float getr(){ return r;}
//	float geta(){ return a;}

	void display();

	friend Polar operator+(Polar, Polar);
	friend Polar operator*(Polar, Polar);
	Polar operator-();
	friend Polar operator-(Polar, Polar);

	operator Rectangular();
};

void ComplexPolarRectangular();

#endif