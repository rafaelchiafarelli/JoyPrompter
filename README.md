#JoyPrompter Source

## changes from the original version
	padding limit is 3000 pixels
	timer interval is 20 milisseconds
	Left key will scroll back at the maximum speed while is pressed
	Right key will scroll forward ar the maximum speed while is pressed

## Windows 10 + Qt4

You'll need to install Qt.
I believe any version is going to work

Compile and run the application


## Mac OS X

You'll need a set of developer tools for compiling JoyPrompter on Mac. The binary can be built with any qt-compatible c++ compiler, but the build script generates an Xcode project, and hence uses the g++ installed with Xcode, by default.

In order to use the build script you'll need to do the following assuming you don't have Xcode or QT4 installed on your computer:

    # install Xcode
    xcode-select --install
    # install Homebrew
    ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    # install QT4
    brew install qt4

Once you have Xcode and QT4 installed run the following and you should have a shiny new JoyPrompter.app file in your source directory:

    git clone https://github.com/andrewstucki/JoyPrompter.git
    cd JoyPrompter && ./build.sh
