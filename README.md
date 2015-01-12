#JoyPrompter Source

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
