#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include "ui_FindDialog.h"
#include <QCloseEvent>

class FindDialog : public QDialog
{
	Q_OBJECT
	typedef enum
	{
		tag_down = 0,
		tag_up = 1
	}Tag_Director;

public:
	FindDialog(QWidget *parent = 0);
	~FindDialog();
	void clear();
	QString getFindText();
	bool getSSign();
	int	getDirSign();
	void setFindText(QString);
signals:
	void findText(QString,bool,int);
private slots:
	void onFindSlot();
protected:
	void closeEvent(QCloseEvent *event);
private:
	Ui::FindDialog ui;
	QString m_text;
};

#endif // FINDDIALOG_H
