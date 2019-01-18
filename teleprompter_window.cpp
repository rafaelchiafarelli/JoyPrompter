#include <sstream>

#include <QCursor>
#include <QtWidgets/QScrollBar>
#include <QString>

#include "teleprompter_window.h"
#include "application_window.h"

#define STYLE "text-align:center;color:white;background-color:black;selection-color:white;selection-background-color:black;"

inline std::string toString (int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

TeleprompterWindow::TeleprompterWindow(QWidget *parent,QWidget *setupHandler)
: QTextEdit(parent)
{

	this->setAlignment(Qt::AlignCenter);
	this->viewport()->setCursor(QCursor(Qt::BlankCursor));
	this->verticalScrollBar()->hide();
	this->horizontalScrollBar()->hide();
	setupWindow = setupHandler;
	
	speed = 1;
	
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(scrollText()));
    timer->blockSignals(true);
    timer->setInterval(20); //50Hz
	timerStarted=false;
}

void TeleprompterWindow::setPadding(int padding)
{
	std::stringstream out;
	out << padding;
	QString paddingString = STYLE;
	paddingString.append("padding-left:");
	paddingString.append(out.str().c_str());
	paddingString.append("px;padding-right:");
	paddingString.append(out.str().c_str());
	paddingString.append("px;");
	this->setStyleSheet(paddingString);
}


void TeleprompterWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->type() == event->KeyRelease)
    {

        switch (event->key()) {
            case Qt::Key_Left:
            case Qt::Key_Right:
                 speed = old_speed;
            break;

        }

    }

}

void TeleprompterWindow::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) {
		case Qt::Key_Escape:
            this->timer->stop();
            this->timer->blockSignals(true);
            killTimer(this->timer->timerId());
			this->timerStarted = false;
			this->setReadOnly(false);
			this->hide();
			static_cast<ApplicationWindow *>(this->setupWindow)->show();
			break;
		case Qt::Key_Space:
			if (this->timerStarted) {
                this->timer->stop();
				killTimer(this->timer->timerId());
			} else {
				this->timer->start(0);
			}
            this->timer->blockSignals(this->timerStarted);
            this->timerStarted = !this->timerStarted;
			break;

        case Qt::Key_Left:
            this->old_speed = speed;
            speed = -10;
            break;
        case Qt::Key_Right:
            this->old_speed = speed;
            speed = 10;
            break;

		case Qt::Key_Down:
			if (this->speed<10)
				this->speed += 1;
			break;
		case Qt::Key_Up:
			if (this->speed > 1)
				this->speed -= 1;
			break;
		case Qt::Key_1:
			this->speed = 1;
			break;
		case Qt::Key_2:
			this->speed = 2;
			break;
		case Qt::Key_3:
			this->speed = 3;
			break;
		case Qt::Key_4:
			this->speed = 4;
			break;
		case Qt::Key_5:
			this->speed = 5;
			break;
		case Qt::Key_6:
			this->speed = 6;
			break;
		case Qt::Key_7:
			this->speed = 7;
			break;
		case Qt::Key_8:
			this->speed = 8;
			break;
		case Qt::Key_9:
			this->speed = 9;
			break;
		case Qt::Key_0:
			this->speed = 10;
			break;
		default:
			event->ignore();
	}
}

void TeleprompterWindow::wheelEvent(QWheelEvent *event){
	if (!this->timerStarted) {
		QTextEdit::wheelEvent(event);
	}
}

void TeleprompterWindow::scrollText()
{

	this->verticalScrollBar()->setValue(this->verticalScrollBar()->value()+this->speed);
}
