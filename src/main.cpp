#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
#include "bigint.hpp"
#include <string>
#include <iostream>
#include "mycode.h"
#include "form.h"
#include "../src/mycode.h"
#include "../../lect4/hellowidget.h"
#include "../../lect4/recordsfacade.h"

// 0. Положить проект в git, дописать код в form.cpp,
//       оформить в виде отдельного коммита
// 1. Написать модульные тесты к коду (код переписать)
//       (решение создавать в отдельной ветке git)
// 2. В другой ветке написать UI тесты к коду
// 3. В коде из предыдущей работы написать тесты к фасаду
//      (код из предыдущей работы поместить в еще одну ветку)
// { в качестве ответа на задание крепим ссылку на публичный
//   git-репозиторий }

using namespace std;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);


  //hello(cin, cout);

  HelloWidget hello;
  hello.show();

  Form f;
  f.show();



  return app.exec();
}
