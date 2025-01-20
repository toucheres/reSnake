#pragma once

#include <QWidget>
#include "ui_SmallWidget.h"

class SmallWidget : public QWidget
{
	Q_OBJECT

public:
	SmallWidget(QWidget *parent = nullptr);
	~SmallWidget();

	int getnum();
	void setnum(int);

private:
	Ui::SmallWidgetClass ui;
};
