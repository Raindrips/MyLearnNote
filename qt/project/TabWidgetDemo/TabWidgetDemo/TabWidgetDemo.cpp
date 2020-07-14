#include "TabWidgetDemo.h"

TabWidgetDemo::TabWidgetDemo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButtonRemakeItem, SIGNAL(clicked(bool)),
		this, SLOT(pushButtonRemakeItemclickedSlot()));

	connect(ui.pushButtonInsertLine, SIGNAL(clicked(bool)),
		this, SLOT(pushButtonInsertLineclickedSlot()));

	connect(ui.pushButtonDeleteLine, SIGNAL(clicked(bool)),
		this, SLOT(pushButtonDeleteLineclickedSlot()));

	ui.tableWidget->insertColumn(2);
	ui.tableWidget->insertRow(1);

}



void TabWidgetDemo::pushButtonInsertLineclickedSlot()
{
	int currentRow = ui.tableWidget->currentRow();
	ui.tableWidget->insertRow(currentRow + 1);
}

void TabWidgetDemo::pushButtonDeleteLineclickedSlot()
{
	int currentRow = ui.tableWidget->currentRow();
	ui.tableWidget->removeRow(currentRow);
}

void TabWidgetDemo::pushButtonRemakeItemclickedSlot()
{
	int currentRow = ui.tableWidget->currentRow();
	int currentColumn = ui.tableWidget->currentColumn();
	QString itemStr = ui.lineEdit->text();
	ui.tableWidget->setItem(currentRow, currentColumn,
		                    new QTableWidgetItem(itemStr));
}
