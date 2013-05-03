#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>;

#include "editor_window.h"
#include "teleprompter_window.h"
#include "controls_menu.h"

class ApplicationWindow : public QWidget
{
	Q_OBJECT
	
public:
    ApplicationWindow(QWidget *parent = 0);
protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
private:
    TeleprompterWindow *teleWindow;
    EditorWindow *edit;
	ControlsMenu *optionBar;
public slots:
    void goToPrompt();
	void getFile();
	void saveFile();
	
};

#endif
