#include <iostream>

using namespace std;

template <class T>
class vector{
	T* v;
	int size;
public:
	vector(){
		size = 0;
		v = new T[size];
		for (int i=0; i<size; i++){
			v[i] = 0;
		}
	}

	vector(vector &a){
		size = length(a);
		v = new T[size];
		for (int i=0; i<size; i++){
			v[i] = a[i];
		}
	}

	vector(T* a){
		size = sizeof(a);
		v = new T[size];
		for (int i=0; i<size; i++){
			v[i] = a[i];
		}
	}

	void print(){
		for (int i=0; i<size; i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}

	T operator*(vector &y){
		T sum = 0;
		for(int i=0; i<size; i++){
			sum += (this -> v[i] )*(y.v[i]);
			cout << this -> v[i] << " " << y.v[i] << " " << sum << endl;
		}
		return sum;
	}
};

void Templates(){
	char x[3] = {"a"};
	char y[3] = {4, 5, 6};
	vector <char> v1;
	vector <char> v2;
	cout << "Size of x: " << sizeof(x) << endl;
	cout << "x: " << x << endl;
	cout << "x[0]: " << x[0] << endl;
	cout << "x[1]: " << x[1] << endl;
	cout << "x[2]: " << x[2] << endl;
	v1 = x;
	v2 = y;
	cout << "\nv1.print()" << endl;
	v1.print();
	cout << "\nv2.print()" << endl;
	v2.print();
	cout << "\n\nv1*v2" << v1*v2 << endl;
}
