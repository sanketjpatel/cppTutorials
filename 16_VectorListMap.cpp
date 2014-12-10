#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

void display( vector<int> &v){
	for (int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void display( list<int> &lst){
	list <int> :: iterator p;
	for (p = lst.begin(); p!=lst.end(); ++p){
		cout << *p << ", ";
	}
	cout << endl;
}

void VectorListMap(){
	vector <int> v;
	cout << "Initial size = " << v.size() << endl;

	// Putting values into the vector
	int x;
	cout << "Enter five integer values: ";
	for (int i=0; i<5; i++){
		cin >> x;
		v.push_back(x);
	}
	cout << "Size of vector after adding values: " << v.size() << endl;

	// Display the contents
	cout << "Current contents: " << endl;
	display(v);

	// Add one more value
	v.push_back(6.6);

	// Display size and contents
	cout << "\nSize = " << v.size() << endl;
	cout << "Contents now: \n";
	display(v);

	// Inserting elements
	vector <int> :: iterator itr = v.begin();
	itr += 3;
	v.insert(itr, 9);

	cout << "\nContents after inserting: \n";
	display(v);

	// Removing 4th and 5th elements
	v.erase(v.begin()+3, v.begin()+5);
	cout << "\n Contents after deletion: " << endl;
	display(v);
}
