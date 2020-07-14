#include "ReplaceDialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.findButton->setEnabled(false);
	ui.replaceButton->setEnabled(false);
	ui.replaceAllButton->setEnabled(false);
	this->setFixedSize(this->size());
    this->setWindowTitle(QString("替换"));


	connect(ui.textLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enabledButtonSlot(QString)));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.findButton, SIGNAL(clicked()), this, SLOT(findTextSlot()));
	connect(ui.replaceButton, SIGNAL(clicked()), this, SLOT(replaceTextSlot()));
	connect(ui.replaceAllButton, SIGNAL(clicked()), this, SLOT(replaceAllSlot()));
}

ReplaceDialog::~ReplaceDialog()
{

}
void ReplaceDialog::enabledButtonSlot(QString text)
{
	if (!text.isEmpty())
	{
		ui.findButton->setEnabled(true);
		ui.replaceButton->setEnabled(true);
		ui.replaceAllButton->setEnabled(true);
	}
	else
	{
		ui.findButton->setEnabled(false);
		ui.replaceButton->setEnabled(false);
		ui.replaceAllButton->setEnabled(false);
	}
}
void ReplaceDialog::findTextSlot()
{
	m_findText = ui.textLineEdit->text();
	emit findText(m_findText,ui.checkBox->isChecked());
}
void ReplaceDialog::replaceTextSlot()
{
	m_replaceText = ui.replaceLineEdit->text();
	emit replaceText(ui.textLineEdit->text(), m_replaceText, ui.checkBox->isChecked());
}
void ReplaceDialog::replaceAllSlot()
{
	m_replaceText = ui.replaceLineEdit->text();
	emit replaceAllText(ui.textLineEdit->text(), m_replaceText, ui.checkBox->isChecked());
}
void ReplaceDialog::clear()
{
	//给控件进行初始化.
	ui.checkBox->setChecked(false);
	ui.textLineEdit->clear();
	ui.replaceLineEdit->clear();
	ui.findButton->setEnabled(false);
	ui.replaceButton->setEnabled(false);
	ui.replaceAllButton->setEnabled(false);
}
void ReplaceDialog::setFindText(QString text)
{
	m_findText = text;
	ui.textLineEdit->setText(text);
}
void ReplaceDialog::setReplaceText(QString text)
{
	m_replaceText = text;
	ui.replaceLineEdit->setText(text);
}
