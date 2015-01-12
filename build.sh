#!/bin/bash
cd "$( dirname "${BASH_SOURCE[0]}" )"
rm -rf JoyPrompter.app
moc application_window.h -o moc_application_window.h
moc teleprompter_window.h -o moc_teleprompter_window.h
qmake -spec macx-xcode
xcodebuild
macdeployqt build/Release/JoyPrompter.app
mv build/Release/JoyPrompter.app .
rm -rf build moc_* *.xcodeproj *.plist
