#include "SmallWidget.h"

SmallWidget::SmallWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.input1, &QDoubleSpinBox::valueChanged,ui.input2, &QSlider::setValue);
	connect(ui.input2, &QSlider::valueChanged,ui.input1, &QDoubleSpinBox::setValue);
}

SmallWidget::~SmallWidget()
{}

int SmallWidget::getnum()
{
	return ui.input1->value();
}

void SmallWidget::setnum(int num)
{
	ui.input1->setValue(num);
}