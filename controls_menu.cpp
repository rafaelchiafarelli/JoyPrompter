#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>

#include "controls_menu.h"

ControlsMenu::ControlsMenu(QWidget *parent)
: QHBoxLayout(parent)
{
	padding = new QSpinBox();
    padding->setMaximum(3000);
	padding->setValue(150);
	padding->setFixedSize(padding->sizeHint());
	
	sizebox = new QComboBox();
	sizebox->addItem("12");
	sizebox->addItem("36");
	sizebox->addItem("48");
	sizebox->addItem("60");
	sizebox->addItem("72");
	sizebox->addItem("84");
	sizebox->setCurrentIndex(5);
	sizebox->addItem("96");
	sizebox->addItem("108");
	sizebox->setFixedSize(sizebox->sizeHint());
	
	this->addWidget(new QLabel("Padding:"),0,Qt::AlignLeft);
	this->addWidget(padding,0,Qt::AlignLeft);
	this->addSpacing(5);
	this->addWidget(new QLabel("Font Size:"),0,Qt::AlignLeft);
	this->addWidget(sizebox,0,Qt::AlignLeft);
	this->addStretch();
}
