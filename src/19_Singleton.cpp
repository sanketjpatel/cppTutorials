#include <iostream>
#include "19_Singleton.hpp"

using namespace std;

SingletonRectangle* SingletonRectangle::instance = NULL;

SingletonRectangle::SingletonRectangle() {
    draw();
}
void SingletonRectangle::draw() {
    cout << "SingletonRectangle is drawn" << endl;
}
void SingletonRectangle::displayVal() {
    cout << "Value is " << membervalue << endl;
}
void SingletonRectangle::setVal(int n) {
    membervalue = n;
}

SingletonRectangle* SingletonRectangle::getInstance(){
    if (instance == NULL) {
    	instance = new SingletonRectangle();
        instance->setVal(1);
    }
    return instance;
}

void Singleton(){

	// SingletonRectangle r11; 						// Cannot use this expression, as you cannot use the constructor.
    SingletonRectangle *r1, *r2;
    r1 = SingletonRectangle::getInstance();
    r2 = SingletonRectangle::getInstance();			// Both r1 and r2 point to the same object. More objects cannot be created.

    r1->displayVal();
    r2->displayVal();
    r1->setVal(85);
    r2->displayVal();
    r2->setVal(34);
    r1->displayVal();
}
