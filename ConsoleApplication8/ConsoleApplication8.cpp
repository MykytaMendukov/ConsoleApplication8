#include <iostream>
#include <string>

using namespace std;

class String {

	string str;

public:

	static int count;

	String(string str_) : str{ str_ } {
		count++;
	}
	String() {
		cout << "Enter your string: ";
		cin >> str;
		count++;
	}
	String(char str_) : str(80, str_) {
		count++;
	}

	~String() {
		str = "";
		count--;
	}


	void printStr() {
		cout << "String: " << str << endl;
	}

	static void printCount() {
		cout << "Number of entries: " << count << endl;
	}

};

int String::count = 0;

int main()
{

	String string1("123");
	string1.printStr();
	String string2;
	string2.printStr();
	String string3("12345678901234567890123456789012345678901234567890123456789012345678901234567890");
	string3.printStr();

	String::printCount();
}

