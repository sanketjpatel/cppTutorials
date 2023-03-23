#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

void display( vector<int> &v){
	for (unsigned int i=0; i<v.size(); i++){
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
	cout << "Enter five integer values: \n";
	for (int i=0; i<5; i++){
		cin >> x;
		v.push_back(x);
	}
	cout << "Size of vector after adding values: " << v.size() << endl;

	// Display the contents
	cout << "Current contents: " << endl;
	display(v);

	// Add one more value
	v.push_back(6);

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
	cout << "\nContents after deletion: " << endl;
	display(v);

	cout << "\nPress Enter to proceed to Lists";
	char c;
	cin.get(c);
	cin.get(c);

	list <int> list1;
	list <int> list2(5);

	for (int i=0; i<3; i++){
		cout << rand() << endl;
		list1.push_back(rand()%100);
	}

	list <int> :: iterator p;
	for (p=list2.begin(); p!=list2.end(); ++p){
		*p = rand()%100;
	}

	cout << "List1 \n";
	display(list1);
	cout << "List2 \n";
	display(list2);

	// Add two elements at the ends of list1
	list1.push_front(100);
	list1.push_back(200);

	// Remove an element from list2
	list2.pop_front();

	cout << "Now list1: \n";
	display(list1);
	cout << "Now list2: \n";
	display(list2);

	list <int> listA, listB;
	listA = list1;
	listB = list2;

	// Merging two lists (unsorted)
	list1.merge(list2);
	cout << "Merged unsorted lists \n";
	display(list1);

	// Sorting and merging
	listA.sort();
	listB.sort();
	listA.merge(listB);
	cout << "Merged sorted lists \n";
	display(listA);

	// Reversing a list
	listA.reverse();
	cout << "Reversed merged list \n";
	display(listA);

	cout << "\n Press Enter to go to maps";
	cin.get(c);

	typedef map<string, int> phoneMap;
	string name;
	int number;
	phoneMap phone;

	cout << "Enter three sets of name and number \n";

	for (int i=0; i<3; i++){
		cout << "Name: ";
		cin >> name;
		cout << "Number: ";
		cin >> number;
		phone[name] = number;
	}

	phone["Sanket"] = 123456;

	phone.insert(pair<string, int> ("Pankaj", 14357));
	int n = phone.size();
	cout << "\nSize of Map = " << n << endl << endl;

	cout << "List of telephone numbers \n";
	phoneMap :: iterator pMap;
	for (pMap=phone.begin(); pMap!=phone.end(); pMap++){
		cout << (*pMap).first << "\t\t\t" << (*pMap).second << "\n";
	}

	cout << "\nEnter name: ";
	cin >> name;
	number = phone[name];
	cout << "Number: " << number << endl;

	cout << "\nPress Enter to see how Functional Objects work\n";
	cin.get(c);

	int l[] = {10, 50, 30, 40, 20};
	int m[] = {70, 90, 60, 80};

	sort(l, l+5, greater<int>());
	sort(m, m+4);

	for (int i=0; i<5; i++){
		cout << l[i] << " ";
	}
	cout << endl;

	for (int i=0; i<4; i++){
		cout << m[i] << " ";
	}

	cout << endl;

}
