#ifndef TELEPROMPTER_WINDOW_H
#define TELEPROMPTER_WINDOW_H

#include <QtWidgets/QWidget>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QtWidgets/QTextEdit>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QContextMenuEvent>

class TeleprompterWindow : public QTextEdit
{
Q_OBJECT
	
public:
    TeleprompterWindow(QWidget *parent = nullptr, QWidget *setupHandler = nullptr);
	void setPadding(int paddingVal);
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseEvent(QMouseEvent *){} //disable mouse clicking
    void contextMenuEvent(QContextMenuEvent *){} //disable right-click menu
private:
    QWidget *setupWindow;
	QTimer *timer;
	bool timerStarted;
	int speed;
    int old_speed;
	int padding;
public slots:
	void scrollText();
};

#endif
