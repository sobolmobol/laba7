#include <QtTest/QtTest>
#include "../src/mycode.h"
#include "../../lect4/recordsfacade.h"

#include <sstream>
#include <fstream>
#include <QDebug>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testIvan();
    void testWorld();
    void testVika();
    void testVikax();
    void testSymbol();
    void testFacade();
    void testFacadeNotNumber();
    void testFacadeNameEmpty();
    void testFacadeScoreEmpty();
    void testFacadeScoreZero();
    void testFacadeScoreUnderZero();
    void testFacadeScoreAbove100();
    void testFacadeScore100();
    void testFacadeScoreUnder100();
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

void TestMyCode::testFacade(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "6";
    isst2 << "oleg";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);

    QCOMPARE(res == "oleg:6", true);
}
void TestMyCode::testFacadeNotNumber(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "vevr";
    isst2 << "oleg";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);

    QCOMPARE(res == "", true);
}

void TestMyCode::testFacadeNameEmpty(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "5";
    isst2 << "";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);

    QCOMPARE(res == "", true);
}

void TestMyCode::testFacadeScoreEmpty(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "";
    isst2 << "hehe";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);
    qDebug() << QString::fromStdString(res);
    QCOMPARE(res == "", true);
}

void TestMyCode::testFacadeScoreZero(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "0";
    isst2 << "hehe";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);
    qDebug() << QString::fromStdString(res);
    QCOMPARE(res == "", true);
}
void TestMyCode::testFacadeScoreUnderZero(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "-1";
    isst2 << "hehe";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);
    qDebug() << QString::fromStdString(res);
    QCOMPARE(res == "", true);
}
void TestMyCode::testFacadeScoreAbove100(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "101";
    isst2 << "hehe";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);
    qDebug() << QString::fromStdString(res);
    QCOMPARE(res == "", true);
}
void TestMyCode::testFacadeScore100(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "100";
    isst2 << "hehe";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);
    qDebug() << QString::fromStdString(res);
    QCOMPARE(res == "hehe:100", true);
}
void TestMyCode::testFacadeScoreUnder100(){
    std::stringstream s;

    stringstream isst1;
    stringstream isst2;

    isst1 << "53";
    isst2 << "hehe";


    RecordsFacade rf;
    rf.get_str(isst1, isst2, s);

    std::string res;
    getline(s, res);
    qDebug() << QString::fromStdString(res);
    QCOMPARE(res == "hehe:53", true);
}

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
