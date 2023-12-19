#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testIvan();
    void testWorld();
    void testVika();
    void testVikax();
    void testSymbol();
};

void TestMyCode::testIvan() {
    std::stringstream sstr;
    stringstream isst;
    isst << "Ivan";

    hello(isst, sstr);

    string str;
    getline(sstr, str);

    QCOMPARE(str == "hello Ivan", true);
}
void TestMyCode::testWorld() {
    std::stringstream sstr;
    stringstream isst1;
    stringstream isst2;
    isst1 << "Hello world";
    isst2 << "llo";
    FindStr(isst1, isst2, sstr);

    std::string res;
    getline(sstr, res);

    QCOMPARE(res == "2", true);
}
void TestMyCode::testVika() {
    std::stringstream sstr;
    stringstream isst1;
    stringstream isst2;
    isst1 << "vikavivika";
    isst2 << "vi";
    FindStr(isst1, isst2, sstr);

    std::string res;
    getline(sstr, res);

    QCOMPARE(res == "0 4 6", true);
}
void TestMyCode::testVikax() {
    std::stringstream sstr;
    stringstream isst1;
    stringstream isst2;
    isst1 << "vikavivika";
    isst2 << "x";
    FindStr(isst1, isst2, sstr);

    std::string res;
    getline(sstr, res);

    QCOMPARE(res == "-1", true);
}
void TestMyCode::testSymbol() {
    std::stringstream sstr;
    stringstream isst1;
    stringstream isst2;
    isst1 << "cda!jcec!evw";
    isst2 << "!";
    FindStr(isst1, isst2, sstr);

    std::string res;
    getline(sstr, res);

    QCOMPARE(res == "3 8", true);
}
QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
