#ifndef CONTROLS_MENU_H
#define CONTROLS_MENU_H

#include <QWidget>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QComboBox>

class ControlsMenu : public QHBoxLayout
{
public:
    ControlsMenu(QWidget *parent = 0);
	QSpinBox *padding;
	QComboBox *sizebox;
};

#endif
