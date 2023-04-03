// Оголошення директиви препроцесора для запобігання подвійного включення файлу
#pragma once
// Підключення заголовочного файлу для вводу/виводу на консоль
#include <iostream>
// Підключення заголовочного файлу для роботи з рядками
#include <string>
// Підключення заголовочного файлу для роботи з мовою Windows
#include <Windows.h>
// Підключення заголовочного файлу, що містить оголошення класу Reading
#include "Reading.h"
// Підключення заголовочного файлу, що містить оголошення класу Writing
#include "Writing.h"

using namespace std;

// Клас меню, що містить методи та поля для взаємодії з користувачем та обробки файлів
class Menu {
public:
	// Конструктор з двома параметрами - шлях до вхідного файлу та шлях до вихідного файлу
	Menu(string inputfile, string outputfile) { file_input = inputfile; file_output = outputfile; }
	// Конструктор за замовчуванням, який встановлює стандартні назви файлів
	Menu() { file_input = "file_input.txt"; file_output = "file_output.txt"; }

	// Метод, що повертає шлях до вхідного файлу
	string getFileInput();
	// Метод, що повертає шлях до вихідного файлу
	string getFileOutput();
	// Головне меню програми
	void mainMenu();

private:
	// Змінні, що містять шляхи до вхідного та вихідного файлів
	string file_input = "file_input.txt";
	string file_output = "file_output.txt";
	// Об'єкти класів Reading та Writing для роботи з файлами
	Reading read_file;
	Writing write_file;
};


// Реалізація методу головного меню
void Menu::mainMenu() {
	// Встановлення кодування вводу/виводу на кирилицю
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	// Змінна для збереження вибору користувача
	int choice = 0;
	// Виведення на екран пунктів меню
	cout << " -------------------------------------------------------- " << endl;
	cout << "¦     1. [~] Записати інформацію у файл              [~] ¦" << endl;
	cout << "¦     2. [~] Підрахувати кількість слів              [~] ¦" << endl;
	cout << "¦     3. [~] Виділити слов з найб кіл голосних літер [~] ¦" << endl;
	cout << "¦     4. [~] Видалити непотрібні пробіли             [~] ¦" << endl;
	cout << "¦     5. [~] Вихід                                   [~] ¦" << endl;
	cout << " -------------------------------------------------------- " << endl;

	cout << "	• Виберіть пункт із списку: ";
	// Запит у користувача на вибір пункту меню
	cout << "	• Виберіть пункт із списку: ";
	cin >> choice;
	// Очищення екрану консолі
	system("cls");
	// Обробка вибору користувача
	if (choice == 1) {
		// Запис порожнього рядка у вихідний файл
		write_file.writeNothing(getFileOutput());
		// Зчитування тексту з вхідного файлу
		read_file.normalLines(getFileInput());
		// Запис обробленого тексту у вихідний файл
		write_file.fileWriting(getFileOutput(), read_file);
	}
	if (choice == 2) {
		// Підрахунок кількості слів у вхідному файлі
		read_file.countOfWords(getFileInput());
		// Виведення результату на екран
		cout << "[->] Кількість слів у файлі: " << read_file.getCountOfWords() << endl;
		// Запис результату у вихідний файл
		write_file.wordsCounter(getFileOutput(), read_file);
	}
	if (choice == 3) {
		// Знаходження слова з найбільшою кількістю голосних літер
		cout << "Слово з найбільшою кількістю голосних: ";
		cout << read_file.findWordWithMostVowels(getFileInput());
		// Запис результату у вихідний файл
		write_file.writeMaxVowelsWord(getFileOutput(), read_file);
	}
	if (choice == 4) {
		// Обробка рядка з вхідного файлу
		read_file.modifyString(getFileInput());
		// Виведення модифікованого рядка на екран
		cout << "[->] Модифікований текст без зайвих пробілів: \n" << endl;
		cout << read_file.getModifyString();
		// Запис модифікованого рядка у вихідний файл
		write_file.writeModifyText(getFileOutput(), read_file);
	}

}


// Реалізація методу, що повертає шлях до вхідного файлу
string Menu::getFileInput() {
	return file_input;
}

// Реалізація методу, що повертає шлях до вихідного файлу
string Menu::getFileOutput() {
	return file_output;
}
