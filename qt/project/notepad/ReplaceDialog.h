#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include "ui_ReplaceDialog.h"

class ReplaceDialog : public QDialog
{
	Q_OBJECT

public:
	ReplaceDialog(QWidget *parent = 0);
	~ReplaceDialog();
	void clear();
	void setFindText(QString);
	void setReplaceText(QString);
signals:
	void findText(QString, bool);
	void replaceText(QString,QString,bool);
	void replaceAllText(QString,QString,bool);
private slots:
	void enabledButtonSlot(QString);
	void findTextSlot();
	void replaceTextSlot();
	void replaceAllSlot();
private:
	Ui::ReplaceDialog ui;
	QString m_findText;
	QString m_replaceText;
};

#endif // REPLACEDIALOG_H
