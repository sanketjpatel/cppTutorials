#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Inventory{
	char name[10];
	int code;
	float cost;
public:
	void getdata(){
		cout << "Enter name: "; cin >> name;
		cout << "Enter code: "; cin >> code;
		cout << "Enter cost: "; cin >> cost;
	}
	void printdata(){
		cout << setw(10) << name
			 << setw(10) << code
			 << setprecision(2) << setw(10) << cost << endl;
	}
};

void FileInteraction(){
	Inventory item;
//	ofstream createFile("/SupportFiles/Inventory.DAT");
//	createFile.close();
	fstream filestream("src/SupportFiles/Inventory.DAT", ios::ate | ios::in | ios::out | ios::binary);
	filestream.seekg(0, ios::beg);

	cout << "CURRENT CONTENTS OF STOCK" << endl;

	while(filestream.read((char *) & item, sizeof item))
		item.printdata();

	filestream.clear();

	cout << "\nADD AN ITEM\n";
	item.getdata();
	filestream.seekg(0, ios::end);
	filestream.write((char *) & item, sizeof item);

	// Display the appended file
	filestream.seekg(0, ios::beg);
	while(filestream.read((char *) & item, sizeof item))
		item.printdata();

	// Find number of objects in the file
	int sizeBytes = filestream.tellg();
	int n = sizeBytes/sizeof(item);
	cout << "Number of objects in the file: " << n << endl;
	cout << "Size of file: " << sizeBytes << endl;

	// Modify an object
	int k;
	cout << "Enter the object number that you want to modify: ";
	cin >> k;
	int location = (k - 1)*sizeof(item);

	if(filestream.eof()) filestream.clear();
	filestream.seekg(location, ios::beg);

	cout << "\nEnter new object details: " << endl;
	item.getdata();
	filestream.write((char *) & item, sizeof item) << flush;

	// Show updated file
	filestream.seekg(0, ios::beg);
	while(filestream.read((char *) & item, sizeof item))
		item.printdata();
	filestream.close();
}
