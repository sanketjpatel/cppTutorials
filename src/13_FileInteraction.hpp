#ifndef FileInteraction_HPP
#define FileInteraction_HPP

class Inventory{										// size 20 bytes
	char name[10];  									// size 10
	int code;											// size 4
	float cost;											// size 4
public:													// 1 pointer per function is stored in the object
	void getdata();                                     // size 1
	void printdata();                                   // size 1
};

void FileInteraction();

#endif