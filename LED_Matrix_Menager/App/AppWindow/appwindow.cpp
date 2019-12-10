#include"appwindow.hpp"
#include"../app.hpp"
#include"appwindowlayoutmacros.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ AppWindow -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ AppWindow.cpp
AppWindow::AppWindow(App* parent) : QWidget(), parent(parent),menuBar(this), toolBar(this), splitter(this), picturesSplitter(&splitter), picturesListPanel(this), componentListPanel(this), paintPanel(this), controlPanel(this)
{
    initilize();
}


// _DESTRUCTORS_ AppWindow.cpp
AppWindow::~AppWindow(){
    clearMemory();
}

// _PRIVATE_METHODS_ AppWindow.cpp
void AppWindow::initilize(){
    toolBar.move(LO_TOOL_BAR_X, LO_TOOL_BAR_Y);
    // Move DataBase Viewer to Splitter
    picturesSplitter.setOrientation(Qt::Vertical);
    picturesSplitter.addWidget(&picturesListPanel);
    picturesSplitter.addWidget(&componentListPanel);
    splitter.addWidget(&paintPanel);
    splitter.addWidget(&controlPanel);
    splitter.move(0, LO_MENU_BAR_HEIGHT + LO_TOOL_BAR_HEIGHT);
    setMinimumSize(QSize(100, 100));
    //setMaximumSize(QSize(4000,4000));
    setGeometry(LO_APP_WINDOW_GEOMETRY);
    show();
    move(400, 400);
    createObjects();
    createLayout();
    connectEvents();

}

void AppWindow::createObjects(){   // Pointers Only

}

void AppWindow::createLayout(){

}

void AppWindow::connectEvents(){
    installEventFilter(this);
}

void AppWindow::clearMemory(){

}

// _PUBLIC_METHODS_ AppWindow.cpp
    GET_DEFINITION(AppWindow, App*, parent)
    GET_DEFINITION(AppWindow, PicturesListPanel&, picturesListPanel)

void AppWindow::resizeEvent(QResizeEvent *ev){
    menuBar.resize(LO_MENU_BAR_SIZE);
    toolBar.resize(LO_TOOL_BAR_SIZE);
    splitter.resize(width(), height() - LO_MENU_BAR_HEIGHT - LO_TOOL_BAR_HEIGHT);
}

bool AppWindow::eventFilter(QObject *obj, QEvent *ev){
    return QObject::eventFilter(obj, ev);
}

void AppWindow::reload(){    
    // Reload Components List, Picture Basic Config
    // to check catch picture list element selection changed
    componentListPanel.reload();
    controlPanel.reload();

    // Paint Panel reload
    paintPanel.reload();

}

// ----------------------------------------------------------------------------------------------------------------------------------------------
