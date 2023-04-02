#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Reading.h"
#include "Writing.h"

using namespace std;

class Menu {
public:
	Menu(string inputfile, string outputfile) { file_input = inputfile; file_output = outputfile; }
	Menu() { file_input = "file_input.txt";  file_output = "file_output.txt"; }

	string getFileInput();
	string getFileOutput();
	void mainMenu();

private:
	string file_input = "file_input.txt";
	string file_output = "file_output.txt";
	Reading read_file;
	Writing write_file;
};


void Menu::mainMenu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	


	int choice = 0;
	cout << " -------------------------------------------------------- " << endl;
	cout << "�     1. [~] �������� ���������� � ����              [~] �" << endl;
	cout << "�     2. [~] ϳ��������� ������� ���              [~] �" << endl;
	cout << "�     3. [~] �������� ���� � ���� �� �������� ���� [~] �" << endl;
	cout << "�     4. [~] �������� �������� ������             [~] �" << endl;
	cout << "�     5. [~] �����                                   [~] �" << endl;
	cout << " -------------------------------------------------------- " << endl;

	cout << "	� ������� ����� �� ������: ";
	cin >> choice;
	system("cls");
	if (choice == 1) {
		write_file.writeNothing(getFileOutput());
		read_file.normalLines(getFileInput());
		write_file.fileWriting(getFileOutput(), read_file);
	}
	if (choice == 2) {
		read_file.countOfWords(getFileInput());
		cout << "[->] ʳ������ ��� � ����: " << read_file.getCountOfWords() << endl;
		write_file.wordsCounter(getFileOutput(), read_file);
	}
	if (choice == 3) {
		cout << "����� � ��������� ������� ��������: ";
		cout << read_file.findWordWithMostVowels(getFileInput());
		write_file.writeMaxVowelsWord(getFileOutput(), read_file);
	}
	if (choice == 4) {
		read_file.modifyString(getFileInput());
		cout << "[->] ������������� ����� ��� ������ ������: \n" << endl;
		cout << read_file.getModifyString();
		write_file.writeModifyText(getFileOutput(), read_file);
	}
}




string Menu::getFileInput() {
	return file_input;
}

string Menu::getFileOutput() {
	return file_output;
}