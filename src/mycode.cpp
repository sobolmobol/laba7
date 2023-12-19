#include "mycode.h"
#include <map>
#include <vector>
#include <QString>

void hello(istream &ist, ostream& ost) {
    std::string name;

    ist >> name;

    ost << "hello " << name;
}
/*void FindStr(istream &ist1, istream &ist2, ostream &ost){
    std::string text;
    std::string pattern;
    ist1 >> text;
    ist2 >> pattern;

    int t = 0;
    int last = pattern.length() - 1;
    int textLength = text.length();
    int result = -1;
    while(t < textLength - last){
        int p = 0;
        while (p <= last && text[ t + p ] == pattern[p]) {
            p++;
        }
        if (p == pattern.length()){
            result = t;
            break;
        }
        else{
            t++;
        }
    }
    ost << result;
}*/
// Функция для создания таблицы смещений
void createShiftTable(const string& pattern, map<char, int>& shiftTable) {
    int patternLength = pattern.length();
    // Заполняем таблицу смещений значением по умолчанию, равным длине образца
    for (int i = 0; i < 256; i++) {
        shiftTable[char(i)] = patternLength;
    }

    // Заполняем таблицу смещений для символов образца
    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable[pattern[i]] = patternLength - 1 - i;
    }

    /*for(int i = 0; i < patternLength - 1; i++){
        if(shiftTable.find(pattern[i]) == shiftTable.end()){
            shiftTable[pattern[i]] = patternLength- i - 1;
        }
        else {
            shiftTable[pattern[i]] = shiftTable.find(pattern[i])->second;
        }
    }
    if(shiftTable.find(pattern[patternLength - 1]) == shiftTable.end()){
        shiftTable[pattern[patternLength - 1]] = patternLength;
    }
    else {
        shiftTable[pattern[patternLength - 1]] = shiftTable.find(pattern[patternLength - 1])->second;
    }*/
    //shiftTable[pattern[patternLength - 1]] = patternLength;
}

// Функция для поиска образца с использованием алгоритма Бойера-Мура
void FindStr(istream &ist1, istream &ist2, ostream &ost) {
    vector<int> indexes;
    std::string text;
    std::string pattern;
    ist1 >> text;
    ist2 >> pattern;
    int textLength = text.length();
    int patternLength = pattern.length();
    map<char, int> shiftTable;
    createShiftTable(pattern, shiftTable);

    int p = patternLength - 1; // инд паттерна
    int t = patternLength - 1; // инд текста

    while (t < textLength) {
        if (pattern[p] == text[t]) {
            if (p == 0) {
                // Найдено полное совпадение образца, добавляем позицию в вектор вхождений
                indexes.push_back(t);
                t += patternLength;
            }
            else {
                // Продолжаем сравнивать предыдущие символы образца и текста
                t--;
                p--;
            }
        }
        else {
            // Символы не совпадают, смещаем индексы в соответствии с таблицей смещений
            t += max(shiftTable[text[t]] - patternLength + 1 + p, 1);
            p = patternLength - 1;
        }
    }

    if(indexes.empty()){
        ost << -1;
    }
    else{
        //std::stringstream ss;
        for(size_t i = 0; i < indexes.size(); ++i)
        {
          if(i != 0){
              ost << " ";
          }
          ost << std::to_string(indexes[i]);
        }
    }
}

