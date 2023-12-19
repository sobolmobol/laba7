#include "form.h"
#include "ui_form.h"
#include "mycode.h"
#include <sstream>
#include <QDebug>
#include <vector>
#include <QDebug>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();
    std::string res;
    std::stringstream resul;
    std::stringstream isst1;
    std::stringstream isst2;
    isst1 << str.toStdString();
    isst2 << sub_str.toStdString();
    FindStr(isst1, isst2, resul);
    getline(resul, res);
    ui->result->setText(get_result(res));
}
QString Form::get_result(std::string res){
    if (res == "-1"){
        return "искомая подстрока не найдена";
    }
    else{
        return "индекс искомой подстроки: " + QString::fromStdString(res);
    }
}
