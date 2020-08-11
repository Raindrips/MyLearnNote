/********************************************************************************
** Form generated from reading UI file 'TabWidgetDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABWIDGETDEMO_H
#define UI_TABWIDGETDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabWidgetDemoClass
{
public:
    QPushButton *pushButtonDeleteLine;
    QPushButton *pushButtonRemakeItem;
    QLineEdit *lineEdit;
    QPushButton *pushButtonInsertLine;
    QTableWidget *tableWidget;

    void setupUi(QWidget *TabWidgetDemoClass)
    {
        if (TabWidgetDemoClass->objectName().isEmpty())
            TabWidgetDemoClass->setObjectName(QStringLiteral("TabWidgetDemoClass"));
        TabWidgetDemoClass->resize(736, 427);
        pushButtonDeleteLine = new QPushButton(TabWidgetDemoClass);
        pushButtonDeleteLine->setObjectName(QStringLiteral("pushButtonDeleteLine"));
        pushButtonDeleteLine->setGeometry(QRect(540, 70, 75, 23));
        pushButtonRemakeItem = new QPushButton(TabWidgetDemoClass);
        pushButtonRemakeItem->setObjectName(QStringLiteral("pushButtonRemakeItem"));
        pushButtonRemakeItem->setGeometry(QRect(640, 110, 75, 23));
        lineEdit = new QLineEdit(TabWidgetDemoClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(540, 110, 81, 20));
        pushButtonInsertLine = new QPushButton(TabWidgetDemoClass);
        pushButtonInsertLine->setObjectName(QStringLiteral("pushButtonInsertLine"));
        pushButtonInsertLine->setGeometry(QRect(540, 40, 75, 23));
        tableWidget = new QTableWidget(TabWidgetDemoClass);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 40, 481, 261));

        retranslateUi(TabWidgetDemoClass);

        QMetaObject::connectSlotsByName(TabWidgetDemoClass);
    } // setupUi

    void retranslateUi(QWidget *TabWidgetDemoClass)
    {
        TabWidgetDemoClass->setWindowTitle(QApplication::translate("TabWidgetDemoClass", "TabWidgetDemo", Q_NULLPTR));
        pushButtonDeleteLine->setText(QApplication::translate("TabWidgetDemoClass", "\345\210\240\351\231\244\350\241\214", Q_NULLPTR));
        pushButtonRemakeItem->setText(QApplication::translate("TabWidgetDemoClass", "\344\277\256\346\224\271Item", Q_NULLPTR));
        pushButtonInsertLine->setText(QApplication::translate("TabWidgetDemoClass", "\346\217\222\345\205\245\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TabWidgetDemoClass", "\350\200\201\345\270\210\345\220\215\345\255\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TabWidgetDemoClass", "\350\257\276\347\250\213\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TabWidgetDemoClass", "\344\270\212\350\257\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TabWidgetDemoClass", "\350\257\276\345\220\216\350\257\273\347\211\251", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("TabWidgetDemoClass", "1", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("TabWidgetDemoClass", "\350\223\235\350\200\201\345\270\210", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 1);
        ___qtablewidgetitem6->setText(QApplication::translate("TabWidgetDemoClass", "\344\270\200\351\230\263\346\214\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 2);
        ___qtablewidgetitem7->setText(QApplication::translate("TabWidgetDemoClass", "20:00-22:00", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 3);
        ___qtablewidgetitem8->setText(QApplication::translate("TabWidgetDemoClass", "\351\207\221\347\223\266\346\242\205", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class TabWidgetDemoClass: public Ui_TabWidgetDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABWIDGETDEMO_H
