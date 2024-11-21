#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void pressEnterToContinue();
bool isCap(char c);

int main() {
	string datafile;
	cout << "input file: ";
	getline(cin, datafile);
	ifstream inputFile;
	string word;
	int wordCount = 0;
	int charCount = 0;
	inputFile.open(datafile);
	if (!inputFile) {
		cout << "Error opening file\n";
		return 1;
	}
	while (inputFile >> word) {
		wordCount++;
		for (int i = 0; i < word.length(); i++) { // loops through each character
			if (word[i] != ' ' && word[i] != '\n' && word[i] != '\t') { // if doesnt equal space, or tab it is a character
				charCount++;
			}
		}
	}
	cout << "Words: " << wordCount << endl;
	cout << "Characters: " << charCount << endl;

	pressEnterToContinue();

	return 0;
}
void pressEnterToContinue() {
	cout << "\npress enter to continue...\n";
	cin.clear();
	while (cin.get() != '\n') continue;
}
bool isCap(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}