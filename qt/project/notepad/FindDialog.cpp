#include "FindDialog.h"

FindDialog::FindDialog(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
	clear();
	ui.findButton->setDefault(true);
	this->setFixedSize(this->size());
    this->setWindowTitle(QString("查找"));

	connect(ui.findButton, SIGNAL(clicked()), this, SLOT(onFindSlot()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

FindDialog::~FindDialog()
{

}
void FindDialog::onFindSlot()
{
	int dir = 0;
	if (ui.upButton->isChecked())
		dir = 1;

	m_text = ui.findLineEdit->text();

	//发出信号.
	emit findText(m_text, ui.checkBox->isChecked(), dir);
}
void FindDialog::clear()
{
	//给控件进行初始化.
	ui.checkBox->setChecked(false);
	ui.downButton->setChecked(true);
}
void FindDialog::closeEvent(QCloseEvent *event)
{
	event->accept();
}
QString FindDialog::getFindText()
{
	return m_text;
}
bool FindDialog::getSSign()
{
	return ui.checkBox->isChecked();
}
int	FindDialog::getDirSign()
{
	int dir = 0;
	if (ui.upButton->isChecked())
		dir = 1;
	return dir;
}
void FindDialog::setFindText(QString text)
{
	m_text = text;
	ui.findLineEdit->setText(text);
}
