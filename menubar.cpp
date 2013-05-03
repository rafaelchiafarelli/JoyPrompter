#include <QApplication>
#include <QAction>
#include <QMenu>

#include "menubar.h"

MenuBar::MenuBar(QWidget *parent)
: QMenuBar(parent)
{
	QAction *fullScreenA = new QAction("&Start Prompt", this);
	fullScreenA->setShortcut(tr("CTRL+F"));
	
	QAction *open_project = new QAction("&Open", this);
	open_project->setShortcut(tr("CTRL+O"));
	
	QAction *new_project = new QAction("&New", this);
	new_project->setShortcut(tr("CTRL+N"));
	
	QAction *quit = new QAction("&Quit", this);
	quit->setShortcut(tr("CTRL+Q"));
	
	QAction *save = new QAction("&Save", this);
	save->setShortcut(tr("CTRL+S"));
	
	QMenu *file;
	file = this->addMenu("&File");
	file->addAction(new_project);
	file->addAction(open_project);
	file->addAction(save);
	file->addSeparator();
	file->addAction(quit);
	
	QMenu *windowm;
	windowm = this->addMenu("&Window");
	windowm->addAction(fullScreenA);
	
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(new_project, SIGNAL(triggered()), parent, SLOT(goToPrompt()));
	connect(open_project, SIGNAL(triggered()), parent, SLOT(getFile()));
	connect(save, SIGNAL(triggered()), parent, SLOT(saveFile()));
	connect(fullScreenA, SIGNAL(triggered()), parent, SLOT(goToPrompt()));
	
}
