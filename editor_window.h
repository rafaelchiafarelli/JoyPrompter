/*
 *  editor_window.h
 *  JoyPrompter
 *
 *  Created by Andrew Stucki on 2/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QDropEvent>

class EditorWindow : public QTextEdit
{	
public:
    EditorWindow(QWidget *parent = 0);
	void dropEvent(QDropEvent *event);
};

#endif