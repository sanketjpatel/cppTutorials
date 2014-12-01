#include <iostream>

using namespace std;

class shape{
protected:
	double x, y;
public:
	virtual void get_data(){};
	void get_data(double primary, double secondary){
		x = primary;
		y = secondary;
	}
	virtual void display_area(){};
};

class triangle : public shape{
public:
	void get_data(){
		double base, height;
		cout << "Enter base: ";
		cin >> base;
		cout << "Enter height: ";
		cin >> height;
		shape::get_data(base, height);
	}

	void display_area(){
		cout << "Area of triangle = " << x*y/2 << endl;
	}
};

class rectangle : public shape{
public:
	void get_data(){
		double length, width;
		cout << "Enter length: ";
		cin >> length;
		cout << "Enter width: ";
		cin >> width;
		shape::get_data(length, width);
	}

	void display_area(){
		cout << "Area of rectangle = " << x*y << endl;
	}
};

void VirtualFunctions(){
	int n;
	cout << "Number of shapes: ";
	cin >> n;

	shape* shapes[n];
//	double primary, secondary;

	int shapetype;

	for(int i=0; i<n; i++){
		cout << "\nEnter shape type (1=triangle; 2=rectangle): ";
		cin >> shapetype;

		if (shapetype == 1) shapes[i] = new triangle;
		else shapes[i] = new rectangle;

//		cout << "Enter primary dimension: ";
//		cin >> primary;
//		cout << "Enter secondary dimension: ";
//		cin >> secondary;
		shapes[i] -> get_data();
//		shapes[i] -> display_area();
	}

	for (int i = 0; i<n; i++){
		cout << "\n******* Shape " << i << " *******" << endl;
		shapes[i] -> display_area();
	}

}
