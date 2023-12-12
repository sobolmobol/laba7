/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *sub_str;
    QLineEdit *str;
    QLabel *result;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        sub_str = new QLineEdit(Form);
        sub_str->setObjectName(QString::fromUtf8("sub_str"));

        gridLayout->addWidget(sub_str, 1, 2, 1, 1);

        str = new QLineEdit(Form);
        str->setObjectName(QString::fromUtf8("str"));

        gridLayout->addWidget(str, 0, 2, 1, 1);

        result = new QLabel(Form);
        result->setObjectName(QString::fromUtf8("result"));

        gridLayout->addWidget(result, 2, 2, 1, 1);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        label_2->setText(QApplication::translate("Form", "\320\230\321\201\320\272\320\276\320\274\320\260\321\217 \320\277\320\276\320\264\321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        label->setText(QApplication::translate("Form", "\320\241\321\202\321\200\320\276\320\272\320\260", nullptr));
        result->setText(QString());
        pushButton->setText(QApplication::translate("Form", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
