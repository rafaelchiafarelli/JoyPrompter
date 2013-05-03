/*
 *  editor_window.cpp
 *  JoyPrompter
 *
 *  Created by Andrew Stucki on 2/5/11.
 *  Copyright 2011 JoyVision. All rights reserved.
 *
 */

//to-do: implement drag and drop for native file types - just need to add type-checking via writing a magic number
//0xCAFEF00D

//#include <QList>
//#include <QString>
//#include <QUrl>
//#include <QFile>
//#include <QTextStream>
//#include <QIODevice>

#include "editor_window.h"

EditorWindow::EditorWindow(QWidget *parent)
: QTextEdit(parent)
{
	this->setAcceptRichText(false);
	this->setAcceptDrops(true);
}

void EditorWindow::dropEvent(QDropEvent *event)
{
//	if (event->mimeData()->hasFormat("text/uri-list")) {
//		QList<QUrl> urls = event->mimeData()->urls();
//		if (urls.isEmpty())
//			return;
//		
//		QString fileName = urls.first().toLocalFile();
//		if (fileName.isEmpty())
//			return;
//
//		QFile file(fileName);
//		if (!file.open (QIODevice::ReadOnly))
//			return;
//		QTextStream stream ( &file );
//		this->setPlainText(stream.readAll());
//		file.close();
//	}
	if (event->mimeData()->hasText())
		this->setPlainText(event->mimeData()->text());

}