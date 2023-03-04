#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string toUPC(string);
string toEAN(string);
void loop(void);

int main(int argc, char* argv[])
{


	if (argc == 1) {

		loop();
		exit(0);
	}
	else if (argc == 2) {

		vector<string> container;

		fstream f;
		f.open(argv[1]);

		string e;
		f >> e;

		while ( f.eof() == false) {
			//add to container
			f >> e;
			container.push_back(e);
		}

		vector<string>::iterator p;
		for (p = container.begin(); p != container.end(); p++) {
			//convert to EAN or UPC
			int len = p[0].length();
			if ( len == 12) {

				cout << toEAN(p[0]) << endl;
			}
			else if (len ==13)
			{
				cout << toUPC(p[0]) << endl;
			}

		}

		f.close();
	}
	else {
		cout << "Incorrect format detected.\nRun program with no arguments to enter mode select. " <<
			"\nRun program with single argument file_name.txt to convert detected codes to UPC or EAN, vice versa." << endl;
	}

	return 0;
}


void loop(void) {

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