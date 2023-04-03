// Оголошення директиви препроцесора для запобігання подвійного включення файлу
#pragma once
// Підключення заголовочного файлу, що містить оголошення класу Menu
#include "Menu.h"
// Підключення заголовочного файлу для вводу/виводу в консоль
#include <iostream>
// Підключення заголовочного файлу для роботи з файлами
#include <fstream>
// Підключення заголовочного файлу для роботи з рядками
#include <string>
// Підключення заголовочного файлу для роботи з рядками з потоків
#include <sstream>

using namespace std;

// Клас для читання та обробки файлу
class Reading {
public:
    // Конструктор за замовчуванням
    Reading() { };
    // Метод для зчитування файлу рядок за рядком та збереження його у внутрішній змінній
    void normalLines(string file);
    // Метод для зчитування файлу та підрахунку кількості слів
    void countOfWords(string file);
    // Метод для обробки рядка з файлу та видалення зайвих пробілів
    void modifyString(string file);
    // Метод для пошуку слова з найбільшою кількістю голосних літер у файлі
    string findWordWithMostVowels(string file);
    // Метод, що повертає рядок з відформатованим текстом з файлу
    string getNormalLines();
    // Метод, що повертає рядок із всіма словами з файлу
    string getJustLine();
    // Метод, що повертає модифікований рядок без зайвих пробілів
    string getModifyString();
    // Метод, що повертає кількість слів у файлі
    int getCountOfWords();
    // Метод для підрахунку кількості голосних літер у слові
    int countVowels(string word);

private:
    // Рядок з відформатованим текстом з файлу
    string NormalLines = "";
    // Рядок із всіма словами з файлу
    string justLine = "";
    // Рядок із модифікованим текстом без зайвих пробілів
    string modify = "";
    // Кількість слів у файлі
    int countOfWordsInt = 0;
};


// Реалізація методу зчитування рядків з файлу
void Reading::normalLines(string file) {
    NormalLines = "";
    // Відкриття файлу
    string buffer;
    ifstream myfile(file);
    if (myfile.is_open())
    {
        // Зчитування файлу рядок за рядком та збереження у внутрішній змінній
        while (getline(myfile, buffer))
        {
            NormalLines += buffer + '\n';
        }
        myfile.close();
    }
    // Обробка винятку у випадку, якщо файл не відкрито
    else {
        cout << "Unable to open file";
    }
}

// Реалізація методу підрахунку кількості слів у файлі
void Reading::countOfWords(string file) {
    // Відкриття файлу
    std::ifstream myfile(file);
    if (myfile.is_open()) {
        string buffer;
        // Зчитування файлу слово за словом
        while (myfile >> buffer) {
            // Збереження слова у внутрішній змінній та збільшення лічильника слів
            justLine += buffer + ' ';
            ++countOfWordsInt;
        }
        myfile.close();
        // Зчитування файлу знову для збереження рядків у внутрішній змінній
        normalLines(file);
    }
    // Обробка винятку у випадку, якщо файл не відкрито
    else {
        cout << "Unable to open file";
    }

}

// Реалізація методу модифікації рядка з файлу та видалення зайвих пробілів
void Reading::modifyString(string file) {
    // Зчитування файлу та збереження рядків у внутрішній змінній
    normalLines(file);

    // Копіювання рядків у змінну для модифікації
        string withoutSpace = getNormalLines();

    // Заміна табуляцій на пробіли
    for (int i = 0; i < withoutSpace.length(); i++) {
        if (withoutSpace[i] == '\t') {
            withoutSpace[i] = ' ';
        }
    }

    // Видалення зайвих пробілів
    for (int i = 0; i < withoutSpace.length(); i++)
    {
        if (withoutSpace[i] == ' ' && withoutSpace[i + 1] == ' ')
        {
            withoutSpace.erase(withoutSpace.begin() + i);
            i--;
        }
        if (withoutSpace[i] == '\n' && withoutSpace[i + 1] == ' ')
        {
            withoutSpace.erase(withoutSpace.begin() + i + 1);
            i--;
        }
    }
    // Збереження модифікованого рядка у внутрішній змінній
    modify = withoutSpace;
}

// Реалізація методу пошуку слова з найбільшою кількістю голосних літер у файлі
string Reading::findWordWithMostVowels(string file) {
    // Підрахунок кількості слів у файлі та збереження рядків у внутрішній змінній
    countOfWords(file);
    string mystring = getJustLine();
    // Створення потоку для зчитування слів з рядка
    istringstream isstream(mystring);
    string word;
    string max_vowel_word;
    int max_vowel_count = 0;
    
    // Перебір слів та пошук слова з найбільшою кількістю голосних літер
    while (isstream >> word) {
        int vowelCount = countVowels(word);
        if (vowelCount > max_vowel_count) {
            max_vowel_word = word;
            max_vowel_count = vowelCount;
        }
    }
    // Повернення знайденого слова
    return max_vowel_word;
}

// Реалізація методу підрахунку кількості голосних літер у слові
int Reading::countVowels(string word) {
    int count = 0;
    // Перебір символів слова та підрахунок голосних літер
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')  {
            count++;
        }
    }
    // Повернення кількості голосних літер у слові
    return count;
}

// Реалізація методу отримання модифікованого рядка з файлу
string Reading::getModifyString() {
    return modify;
}

// Реалізація методу отримання нормального рядка з файлу
string Reading::getNormalLines() {
    return NormalLines;
}

// Реалізація методу отримання одного рядка з файлу без зайвих символів
string Reading::getJustLine() {
    return justLine;
}

// Реалізація методу отримання кількості слів у файлі
int Reading::getCountOfWords() {
    return countOfWordsInt;
}
