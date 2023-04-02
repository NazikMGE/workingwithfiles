#pragma once
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Reading {
public:

    Reading() { };
    void normalLines(string file);
    void modifyString(string file);
    void countOfWords(string file);
    string findWordWithMostVowels(string file);
    string getNormalLines();
    string getJustLine();
    string getModifyString();
    int getCountOfWords();
    int countVowels(string word);


private:
    string NormalLines = "";
    string justLine = "";
    string modify = "";
    int countOfWordsInt = 0;

};


void Reading::normalLines(string file) {
    NormalLines = "";
    string buffer;
    ifstream myfile(file);
    if (myfile.is_open())
    {
        while (getline(myfile, buffer))
        {
            NormalLines += buffer + '\n';
        }
        myfile.close();
    }
    
    else {
        cout << "Unable to open file";
    }
}

void Reading::countOfWords(string file) {
    std::ifstream myfile(file);
    if (myfile.is_open()) {
        string buffer;
        while (myfile >> buffer) {
            justLine += buffer + ' ';
            ++countOfWordsInt;
        }
         myfile.close();
         normalLines(file);

    }
    else {
        cout << "Unable to open file";
    }
}

void Reading::modifyString(string file) {

    normalLines(file);

    string withoutSpace = getNormalLines();

    for (int i = 0; i < withoutSpace.length(); i++) {
        if (withoutSpace[i] == '\t') {
            withoutSpace[i] = ' ';
        }
    }

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
    modify = withoutSpace;
}

string Reading::findWordWithMostVowels(string file) {
    countOfWords(file);
    string mystring = getJustLine();
    istringstream isstream(mystring);
    string word;
    string max_vowel_word;
    int max_vowel_count = 0;
    
    while (isstream >> word) {
        int vowelCount = countVowels(word);
        if (vowelCount > max_vowel_count) {
            max_vowel_word = word;
            max_vowel_count = vowelCount;
        }
    }
    return max_vowel_word;
}

int Reading::countVowels(string word) {
    int count = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            count++;
        }
    }
    return count;
}

string Reading::getModifyString() {
    return modify;
}

string Reading::getNormalLines() {
    return NormalLines;
}

string Reading::getJustLine() {
    return justLine;
}

int Reading::getCountOfWords() {
    return countOfWordsInt;
}

