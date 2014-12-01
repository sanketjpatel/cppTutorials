#include <iostream>

using namespace std;

class shape{
protected:
	double x, y;
public:
	/*
	 * When a method is made virtual,
	 * the pointer will invoke the method in the derived class.
	 */
	virtual void get_data(){};

	// Function overloading
	void get_data(double primary, double secondary){
		x = primary;
		y = secondary;
	}
	virtual void display_area(){};

	// Destructor is made virtual so that destructor in the derived class is invoked
	virtual ~shape(){
		cout << "Destroying shape with dimensions: " << x << ", " << y << endl;
	}
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

	~triangle(){
		cout << "\nDeleted triangle" << endl;
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

	~rectangle(){
		cout << "\nDeleted rectangle" << endl;
	}
};

void VirtualFunctions(){
	int n;
	cout << "Number of shapes: ";
	cin >> n;

	shape* shapes[n];

	int shapetype;

	for(int i=0; i<n; i++){
		cout << "\nEnter shape type (1=triangle; 2=rectangle): ";
		cin >> shapetype;

		if (shapetype == 1) shapes[i] = new triangle;
		else shapes[i] = new rectangle;

		shapes[i] -> get_data();
	}

	for (int i = 0; i<n; i++){
		cout << "\n******* Shape " << i << ": " << shapes[i] <<" *******" << endl;
		shapes[i] -> display_area();
	}

	for (int i=n-1; i>=0; i--){
		/* This invokes the destructor of the derived class followed by the destructor of the base class,
		 * since the destructor in the base class has been defined as virtual.
		 * If the destructor in the base class is not virtual, then the derived class destructor is not invoked.
		 */
		delete shapes[i];
	}

}
