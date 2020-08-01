/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btntestnum;
    QPushButton *btnteststring;
    QPushButton *btntestdata;
    QPushButton *btnTestTimer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        btntestnum = new QPushButton(Dialog);
        btntestnum->setObjectName(QString::fromUtf8("btntestnum"));
        btntestnum->setGeometry(QRect(110, 40, 141, 23));
        btnteststring = new QPushButton(Dialog);
        btnteststring->setObjectName(QString::fromUtf8("btnteststring"));
        btnteststring->setGeometry(QRect(110, 90, 141, 23));
        btntestdata = new QPushButton(Dialog);
        btntestdata->setObjectName(QString::fromUtf8("btntestdata"));
        btntestdata->setGeometry(QRect(120, 140, 121, 23));
        btnTestTimer = new QPushButton(Dialog);
        btnTestTimer->setObjectName(QString::fromUtf8("btnTestTimer"));
        btnTestTimer->setGeometry(QRect(120, 190, 131, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        btntestnum->setText(QCoreApplication::translate("Dialog", "\346\265\213\350\257\225\345\237\272\346\234\254\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        btnteststring->setText(QCoreApplication::translate("Dialog", "\346\265\213\350\257\225\345\255\227\347\254\246\344\270\262\347\261\273", nullptr));
        btntestdata->setText(QCoreApplication::translate("Dialog", "\346\265\213\350\257\225\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        btnTestTimer->setText(QCoreApplication::translate("Dialog", "\346\265\213\350\257\225\345\256\232\346\227\266\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
