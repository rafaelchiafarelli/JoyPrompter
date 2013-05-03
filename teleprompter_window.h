#ifndef TELEPROMPTER_WINDOW_H
#define TELEPROMPTER_WINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QTextEdit>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QContextMenuEvent>

class TeleprompterWindow : public QTextEdit
{
Q_OBJECT
	
public:
    TeleprompterWindow(QWidget *parent = 0, QWidget *setupHandler = 0);
	void setPadding(int paddingVal);
protected:
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
	void mouseEvent(QMouseEvent *){}; //disable mouse clicking
	void contextMenuEvent(QContextMenuEvent *){}; //disable right-click menu
private:
    QWidget *setupWindow;
	QTimer *timer;
	bool timerStarted;
	int speed;
	int padding;
public slots:
	void scrollText();
};

#endif
