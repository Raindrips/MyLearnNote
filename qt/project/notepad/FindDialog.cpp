#include "FindDialog.h"

FindDialog::FindDialog(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
	clear();
	ui.findButton->setDefault(true);
	this->setFixedSize(this->size());
    this->setWindowTitle(QString("����"));

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

	//�����ź�.
	emit findText(m_text, ui.checkBox->isChecked(), dir);
}
void FindDialog::clear()
{
	//���ؼ����г�ʼ��.
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
