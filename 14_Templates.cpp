#include <iostream>

using namespace std;

template <class T>
class vector{
	T* v;

public:
	int size;
	vector(){
		size = 0;
		cout << "Size: " << size << endl;
		v = new T[size];
		for (int i=0; i<size; i++){
			v[i] = 0;
		}
	}

	vector(vector &a){
		size = a.size;
		// length(a) works only for strings. For other objects, sizeof should be used.
        // In that case, you should know the type of members in the object, and assign values accordingly
		cout << "Size: " << size << endl;
		v = new T[size];
		for (int i=0; i<size; i++){
			v[i] = a[i];
		}
	}

	vector(T* a, int n){
		size = n;  // Most of the times you will use this pattern for dealing with arrays
		cout << "Size: " << size << endl;
		v = new T[size];
		for (int i=0; i<size; i++){
			v[i] = a[i];
		}
	}

	void print(){
		cout << "Size = " << size << endl;
		for (int i=0; i<size; i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}

	T operator*(vector &y){
		T sum = 0;
		for(int i=0; i<size; i++){
			sum += (this -> v[i] )*(y.v[i]);
		}
		return sum;
	}
};

void Templates(){
	int x[] = {35, 48, 67, 55, 70, -400};
	int y[] = {12, 242, 34, 123, 23, 50};

	cout << endl << "x: " << x << endl;
	cout << "&x = " << sizeof(&x) << endl;
	cout << "Size of x: " << sizeof(x) << endl;
	cout << x[0] << endl;
	cout << x[1] << endl;
	cout << x[2] << endl;
	cout << x[3] << endl;
	cout << x[4] << endl;
	cout << x[5] << endl;

	vector<int> v1(x, sizeof(x)/sizeof(x[0]));
	vector<int> v2(y, sizeof(y)/sizeof(y[0]));

	cout << "\nv1.print()" << endl;
	v1.print();
	cout << "\nv2.print()" << endl;
	v2.print();

	cout << "\n\nv1*v2: " << endl;
	cout << v1*v2 << endl;
}
