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
		size = sizeof(a)-1;
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
	int x[3] = {1, 2, 3};
	int y[3] = {4, 5, 6};
	vector <int> v1;
	vector <int> v2;
	cout << sizeof(x) << endl;
	cout << x << endl;
	v1 = x;
	v2 = y;
	v1.print();
	v2.print();
	cout << v1*v2 << endl;
}
