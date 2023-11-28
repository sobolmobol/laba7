#include <QCoreApplication>
#include <QDebug>
#include "bigint.hpp"

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  BigInt a(2), b("00000009999999999999999999999999999999");

  qDebug() << (a + b).to_string().c_str();

  return app.exec();
}
