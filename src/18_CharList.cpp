#include <iostream>
#include <string>
#include "18_CharList.hpp"

using namespace std;

void CharList(){
	for (int i=0; i<128; i++){
		cout << i << "\t" << (char)i << endl;
	}
}
