/* 
Juan Buena
January 29, 2019
DNA Project
For this task I assumed A == 00, T == 01, G = 10, C = 11. 

On objective 1: I asked the user to input a string like the examples in the document, from there I determined the lenght of the string.
As I did a for loop for each character, I read it and converted it to an integer value based on the ASCII table numbers. After completing that I 
converted the integers to binary numbers and stored those numbers into a string. When the numbers did not match the desired 8 characters I added a 0 in the front
assuming the binary numbers would not reach 8 digits. I was having trouble to parse the string in pairs of 2s, so I decided to append them in a different string.
This time I separated the characters in 2 and added a (,) to parse by delimeter and store them in a vector. Once they were stored I outputed them 2 characters at
a time and checked them with the info each letter contained. When the string was equal it would output the DNA.

On objective 2: I created an if else to replace Ts with Us

On objective 3: I was not sure of what it was asking

On objective 4: I modified the program to ask the user what it wanted to input and the output it wanted to received. So I created functions to
record the user input (assuming they entered valid positive numbers only(1-2)). I created another function to determine DNA of the complementary strand. The function gave me 
the original DNA after appending it to a different string strand2 and from there I tried to change the letters into binary numbers. I did not get to finish, but my approach would have been
to seperate the binary numbers into groups of 8 and get a whole integer in order to convert to a string using the ASCII table for the characters.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string A = "00";
string T = "01";
string G = "10";
string C = "11";
char buffer[33];
string text = "";
string binary = "";
string binary2 = "";
string delimiter = ",";
string strand = "";
string strand2 = "";
int choice = 0;
int option = 0;

void appendNum(string binary) {
	if (binary.length() < 8) {
		binary2.append("0");
		binary2.append(binary,0,1);
		binary2.append(",");
		binary2.append(binary,1,2);
		binary2.append(",");
		binary2.append(binary,3,2);
		binary2.append(",");
		binary2.append(binary,5,2);
		binary2.append(",");

		//cout << binary2 << endl;
	}
}
void string_to_ASCII_to_Binary(string input) {
	for (int i = 0; i < input.length(); i++)
	{
		char l = input.at(i);
		
		//cout << int(l) << endl;

		int j = int(l);
		_itoa_s(j, buffer, 2);
		binary = buffer;
		//cout << buffer << endl;
		appendNum(binary);
	}
}
void strand_to_ASCII(string strand) {
	for (int x = 0; x < strand.length(); x++)
	{
		char k = strand.at(x);
		if (k == 'A') {
			strand2.append("T");
		}
		else if (k == 'G') {
			strand2.append("C");
		}
		else if(k == 'T') {
			strand2.append("A");
		}
		else if (k == 'C') {
			strand2.append("G");
		}
	}
	cout << strand2 << endl;
}
vector<string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}
void DNA_RNA(int choice) {
	if (choice == 1) {
		cout << "Output: ";
		vector<string> v = split(binary2, delimiter);
		for (auto i : v)
			if (i == A)
				cout << "A";
			else if (i == T)
				cout << "T";
			else if (i == G)
				cout << "G";
			else if (i == C)
				cout << "C";
		cout << endl;
	}
	else if (choice == 2) {
		cout << "Output: ";
		vector<string> v = split(binary2, delimiter);
		for (auto i : v)
			if (i == A)
				cout << "A";
			else if (i == T)
				cout << "U";
			else if (i == G)
				cout << "G";
			else if (i == C)
				cout << "C";
		cout << endl;
	}
	else
	{
		cout << "Invalid choice entered! Thank you for using the program! Come back soon!\n";
		system("pause");
		exit(0);
	}
}
void ASCII_DNA(char option) {
	if (option == 1) {
		cout << "\n\t\tWould you like receive your result in DNA or RNA?\n"
			<< "\n\t\tPlease enter your (1) for DNA or (2) for RNA:";
		cin >> choice;

		cout << "\n\tEnter text to convert: ";
		cin >> text;

		string_to_ASCII_to_Binary(text);
	}
	else if (option ==2) {
		cout << "\n\t\tPlease enter your complementary DNA strand:";
		cin >> strand;

		strand_to_ASCII(strand);
	}
	else
	{
		cout << "Invalid choice entered! Thank you for using the program! Come back soon!\n";
		system("pause");
		exit(0);
	}
}

int main() {

	cout << "Welcome to the Program encoder for DNA or RNA!\n"
		<< "\n\tWhat is your input?\n"
		<< "\n\tPlease enter (1) for ASCII text or (2) for DNA:";
	cin >> option;

	ASCII_DNA(option);
	DNA_RNA(choice);

	system("pause");
	return 0;
}
