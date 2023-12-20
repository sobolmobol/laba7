#include "mycode.h"
#include <map>
#include <vector>
#include <QString>

void hello(istream &ist, ostream& ost) {
    std::string name;

    ist >> name;

    ost << "hello " << name;
}

void createShiftTable(const string& pattern, map<char, int>& shiftTable) {
    int patternLength = pattern.length();
    for (int i = 0; i < 256; i++) {
        shiftTable[char(i)] = patternLength;
    }

    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable[pattern[i]] = patternLength - 1 - i;
    }
}

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
                indexes.push_back(t);
                t += patternLength;
            }
            else {
                t--;
                p--;
            }
        }
        else {
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

