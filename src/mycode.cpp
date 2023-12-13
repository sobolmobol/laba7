#include "mycode.h"

void hello(istream &ist, ostream& ost) {
    std::string name;

    ist >> name;

    ost << "hello " << name;
}
void FindStr(istream &ist1, istream &ist2, ostream &ost){
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
}
