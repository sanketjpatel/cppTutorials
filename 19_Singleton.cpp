/*
 * Author: Sanket Patel
 *
 * The following is the code for the singleton pattern.
 */

#include <iostream>

using namespace std;

class Rectangle{
private:
    static Rectangle *instance;				// instance should be a pointer to the object
    Rectangle(){} 							// private constructor
    int membervalue = 1;
public:
    static Rectangle* getInstance();        // Method returns the pointer to the object

    // Add your methods
    void draw(){ cout << "Rectangle is drawn" << endl;}
    void setVal(int n){
    	membervalue = n;
    	cout << "Value set to " << membervalue << endl;
    }
};

Rectangle* Rectangle::instance = NULL;

Rectangle* Rectangle::getInstance(){
    if(instance == NULL){
    	instance = new Rectangle();
    }
    return instance;
}

void Singleton(){

	// Rectangle r11; 						// Cannot use this expression, as you cannot use the constructor.
    Rectangle *r1, *r2;
    r1 = Rectangle::getInstance();
    r2 = Rectangle::getInstance();			// Both r1 and r2 point to the same object. More objects cannot be created.

    r1->draw();
    r2->draw();

    r1->setVal(85);
    r2->setVal(34);
}
