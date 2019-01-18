#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QWidget>
#include <QIcon>

#include "application_window.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QDesktopWidget *desktop = QApplication::desktop();
	QWidget *screen = desktop->screen(desktop->primaryScreen());	
	ApplicationWindow window;
	
	window.resize(screen->height(),screen->height()*2/3);
	window.move((screen->width()-window.width())/2,(screen->height()-window.height())/2);
	window.setWindowTitle("JoyPrompter");
	window.setWindowIcon(QIcon("../Icons/joyland32x32.png"));
	window.show();
	
	return app.exec();
}
