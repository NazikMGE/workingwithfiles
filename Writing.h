#pragma once
#include <iostream>

using namespace std;

class Writing {
public:
	void fileWriting(string file, Reading& content);
	void wordsCounter(string file, Reading& content);
	void writeModifyText(string file, Reading& content);
	void writeMaxVowelsWord(string file, Reading& content);
	void writeNothing(string file);

private:
	string nothing = "";
};


void Writing::fileWriting(string file, Reading& content) {
	ofstream MyFile(file);
	MyFile << content.getNormalLines();
	MyFile.close();
	
}

void Writing::wordsCounter(string file, Reading& content) {
	ofstream MyFile(file, std::ios::app);
	MyFile << "[->] ʳ������ ��� � ����: " << content.getCountOfWords() << endl;
	MyFile << content.getNormalLines() << endl;
	MyFile.close();
}

void Writing::writeModifyText(string file, Reading& content) {
	ofstream MyFile(file, std::ios::app);
	MyFile << "[->] ������������� ����� ��� ������ ������: " << endl;
	MyFile << content.getModifyString() << endl;
	MyFile.close();
}

void Writing::writeMaxVowelsWord(string file, Reading& content) {
	ofstream MyFile(file, std::ios::app);
	MyFile << "[->] C���� � ��������� ������� �������� ����: " << endl;
	MyFile << content.findWordWithMostVowels(file)  << endl;
	MyFile.close();
}

void Writing::writeNothing(string file) {

	ofstream MyFile(file);
	MyFile << nothing;
	MyFile.close();

}