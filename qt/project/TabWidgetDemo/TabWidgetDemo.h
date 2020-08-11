#pragma once

#include <QtWidgets/QWidget>
#include "ui_TabWidgetDemo.h"

#include <QDebug>

class TabWidgetDemo : public QWidget
{
	Q_OBJECT

public:
	TabWidgetDemo(QWidget *parent = Q_NULLPTR);

public slots:
    void pushButtonInsertLineclickedSlot();
	void pushButtonDeleteLineclickedSlot();
	void pushButtonRemakeItemclickedSlot();

private:
	Ui::TabWidgetDemoClass ui;
};
