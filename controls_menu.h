#ifndef CONTROLS_MENU_H
#define CONTROLS_MENU_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>

class ControlsMenu : public QHBoxLayout
{
public:
    ControlsMenu(QWidget *parent = nullptr);
	QSpinBox *padding;
	QComboBox *sizebox;
};

#endif
