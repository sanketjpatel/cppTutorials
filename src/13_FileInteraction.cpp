#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Inventory{										// size 20 bytes
	char name[10];  									// size 10
	int code;											// size 4, which is absurd
	float cost;											// size 4
public:													// 1 pointer per function is stored in the object
	void getdata(){										// size 1
		cout << "Enter name: "; cin >> name;
		cout << "Enter code: "; cin >> code;
		cout << "Enter cost: "; cin >> cost;
	}
	void printdata(){									// size 1
		cout << setw(10) << name
			 << setw(10) << code
			 << setprecision(3) << setw(10) << cost << endl;
	}
};

void FileInteraction(){
	cout.setf(ios::showpoint);							// To display trailing zeros

	Inventory item;
	char const * filepath = "src/SupportFiles/Inventory.DAT";		// use const to avoid deprecation warnings


	// The following statement does not create a new file, because the file exists in a different directory
	// Use if statement as a workaround
	fstream filestream(filepath, ios::ate | ios::binary | ios::in | ios::out);

	if(!filestream)
	{
		cout << "File does not exist, creating new file" << endl;
	    filestream.open(filepath, ios::binary | ios::trunc | ios::out);
	    filestream.close();
	    // re-open with original flags
	    filestream.open(filepath, ios::binary | ios::in | ios::out);
	}

	// Go to the beginning of the file
	filestream.seekg(0, ios::beg);
	cout << "CURRENT CONTENTS OF STOCK" << endl;

	// Read (sizeof item) number of bytes into the address of the object
	// You could use any number of bytes here and read it into an object
	while(filestream.read((char *) & item, sizeof item))
		item.printdata();

	// Whenever the end of file is reached, the .eof() is set to true
	// You need to clear this flag if you want to perform any other operation
	filestream.clear();

	cout << "\nADD AN ITEM\n";
	item.getdata();
	filestream.seekg(0, ios::end);
	filestream.write((char *) & item, sizeof item);		// write is similar to read

	// Display the appended file
	filestream.seekg(0, ios::beg);
	while(filestream.read((char *) & item, sizeof item))
		item.printdata();

	// Find number of objects in the file
	// It is necessary to have all the objects of same size inside the file,
	// or you should know the structure of the file to extract information out of it
	filestream.seekg(0, ios::end);
	filestream.clear(); // tellg() returns -1, if you don't use clear()
	int sizeBytes = filestream.tellg();  // Tells you the position of the pointer
	int n = sizeBytes/sizeof(item);
	cout << "\nNumber of objects in the file: " << n << endl;
	cout << "Size of file: " << sizeBytes << endl;

	// Modify an object
	int k;
	cout << "Enter the object number that you want to modify (Enter -1 to skip): ";
	cin >> k;
	if (k != -1){
		int location = (k - 1)*sizeof(item);

		if(filestream.eof()) filestream.clear();
		filestream.seekg(location, ios::beg);

		cout << "\nEnter new object details: " << endl;
		item.getdata();
		filestream.write((char *) & item, sizeof item) << flush;
	}

	// Show updated file
	filestream.seekg(0, ios::beg);
	while(filestream.read((char *) & item, sizeof item))
		item.printdata();

	// Always close the stream as soon as you are done with file I/O
	filestream.close();
}
