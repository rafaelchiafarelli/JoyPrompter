#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTextCursor>
#include <QTextStream>
#include <QApplication>
#include <QFile>
#include <QIODevice>

#include "application_window.h"
#include "controls_menu.h"
#include "menubar.h"

ApplicationWindow::ApplicationWindow(QWidget *parent)
: QWidget(parent)
{
	teleWindow = new TeleprompterWindow(0,this);
	teleWindow->setWindowTitle("JoyPrompter - Full Screen");
	this->setAcceptDrops(true);
	
	QPushButton *fullScreen = new QPushButton("Start Prompt", this);
	fullScreen->setGeometry(50,40,75,30);
	
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	optionBar = new ControlsMenu();
	
	edit = new EditorWindow(this);
	layout->addLayout(optionBar,0);
	layout->addWidget(edit, 0);
	layout->addWidget(fullScreen, 0);
	
	MenuBar *menu = new MenuBar(this);
	
	layout->setMenuBar(menu);
	
	connect(fullScreen, SIGNAL(clicked()), this, SLOT(goToPrompt()));
}

void ApplicationWindow::goToPrompt()
{
	teleWindow->setFontPointSize(this->optionBar->sizebox->currentText().toInt());
	teleWindow->setPlainText(this->edit->toPlainText());
	
	teleWindow->setPadding(this->optionBar->padding->value());
	
	teleWindow->selectAll();
	teleWindow->setAlignment(Qt::AlignCenter);
	
	QTextCursor cursor = teleWindow->textCursor();
	cursor.clearSelection();
	cursor.setPosition(0,QTextCursor::MoveAnchor);
	teleWindow->setTextCursor(cursor);
	
	teleWindow->setReadOnly(true);
	//teleWindow->show();
	teleWindow->showFullScreen();
	teleWindow->setFocus();
	teleWindow->setCursor(QCursor(Qt::BlankCursor));
	this->hide();
}

void ApplicationWindow::getFile()
{
	QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
}

void ApplicationWindow::saveFile()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), ".", tr("Text File (*.jyp)"));
	QFile file( filename );
	file.open(QIODevice::WriteOnly | QFile::Text);
	QTextStream out(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	out << this->edit->toPlainText();
	QApplication::restoreOverrideCursor();
	file.close();
}

void ApplicationWindow::dragEnterEvent(QDragEnterEvent *event)
{
	event->accept();
}

void ApplicationWindow::dropEvent(QDropEvent *event){
	this->edit->dropEvent(event);
}