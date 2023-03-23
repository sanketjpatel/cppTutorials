#ifndef Singleton_HPP
#define Singleton_HPP


class SingletonRectangle{
private:
    static SingletonRectangle *instance;				// instance should be a pointer to the object
    SingletonRectangle();         					// private constructor

    // Add your members
    int membervalue;
    void draw();
public:
    static SingletonRectangle* getInstance();        // Method returns the pointer to the object

    // Add your methods
    void displayVal();
    void setVal(int n);
};

void Singleton();

#endif