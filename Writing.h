// Оголошення класу Writing
#pragma once
#include <iostream>

using namespace std;

class Writing {
public:
	// Методи запису до файлу
	void fileWriting(string file, Reading& content);
	void wordsCounter(string file, Reading& content);
	void writeModifyText(string file, Reading& content);
	void writeMaxVowelsWord(string file, Reading& content);
	void writeNothing(string file);

private:
	// Змінна-приватний член класу для запису порожнього рядка
	string nothing = "";
};


// Реалізація методу запису вмісту файлу
void Writing::fileWriting(string file, Reading& content) {
	ofstream MyFile(file);
	MyFile << content.getNormalLines();
	MyFile.close();

}

// Реалізація методу запису кількості слів та вмісту файлу
void Writing::wordsCounter(string file, Reading& content) {
	ofstream MyFile(file, std::ios::app);
	MyFile << "[->] Кількість слів у файлі: " << content.getCountOfWords() << endl;
	MyFile << content.getNormalLines() << endl;
	MyFile.close();
}

// Реалізація методу запису модифікованого тексту
void Writing::writeModifyText(string file, Reading& content) {
	ofstream MyFile(file, std::ios::app);
	MyFile << "[->] Модифікований текст без зайвих пробілів: " << endl;
	MyFile << content.getModifyString() << endl;
	MyFile.close();
}

// Реалізація методу запису слова з найбільшою кількістю голосних літер
void Writing::writeMaxVowelsWord(string file, Reading& content) {
	ofstream MyFile(file, std::ios::app);
	MyFile << "[->] Cлово з найбільшою кількість голосних літер: " << endl;
	MyFile << content.findWordWithMostVowels(file) << endl;
	MyFile.close();
}

// Реалізація методу запису нічого у файл
void Writing::writeNothing(string file) {
	ofstream MyFile(file);
	MyFile << nothing;
	MyFile.close();
}
