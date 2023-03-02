#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string toUPC(string);
string toEAN(string);
int loop(void);

int main(int argc, char* argv[])
{
	string test1 = "123456789012";
	string test2 = "G123456789012";
	string at;


	if (argc == 1) {
		cout << "no args found entering loop mode" << endl;

		loop();
		exit(0);
	}

	if (argc == 2) {
		cout << "args found" << endl;
		cout << argv[1] << endl;
		fstream f;
		f.open(argv[1]);
		f.close();
		//convert to EAN or UPC
	}

	/*cout << "Should print out 123456789012= " << toUPC(test1) << endl;

	cout << "Should print out 123456789012= " << toUPC(test2) << endl;

	cout << "Should print out F123456789012= " << toEAN(test1) << endl;

	cout << "Should print out F123456789012= "  << toEAN(test2) << endl;

	cout << argv[0] << endl;

	cout << "Hello" << endl;

	cin >> at;*/
	return 0;
}


int loop(void) {

	string mode;
	string code;

	do {
		cout << "0. to exit" << endl;
		cout << "1. Convert to UPC" << endl;
		cout << "2. Convert to EAN" << endl;
		cin >> mode;
		if (mode == "1") {
			cout << "1. Convert to UPC selected. Enter 0 to exit. Enter code: " << endl;
			do {
				cin >> code;
				cout << toUPC(code) << endl;
			} while (code != "0");
		}
		if (mode == "2") {
			cout << "2. Convert to EAN selected. Enter 0 to exit. Enter code: " << endl;
			do {
				cin >> code;
				cout << toEAN(code) << endl;
			} while (code != "0");
		}
	} while (mode != "0");
	
	
	cout << "exiting program" << endl;
	return 0;
}


string toUPC(string arg) {

	string newArg;

	if (arg.length() == 13)
	{
		for (int i = 1; i < 13; i++)
			newArg += arg[i];
	}
	else {
		return arg;
	}

	return newArg;

}

string toEAN(string arg) {

	string newArg;

	if (arg.length() != 13) {

		newArg = "F" + arg;

	}
	else {

		newArg = "F";
		for (int i = 1; i < 13; i++)
			newArg += arg[i];
		
	}

	return newArg;
}