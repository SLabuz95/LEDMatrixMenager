#ifndef APPWINDOW_HPP
#define APPWINDOW_HPP

#include<QWidget>
#include<QSplitter>
#include"MenuBar/menubar.hpp"
#include"ToolBar/toolbar.hpp"
#include"ComponentListPanel/componentlistpanel.hpp"
#include"PicturesListPanel/pictureslistpanel.hpp"
#include"PaintPanel/paintpanel.hpp"
#include"ControlPanel/controlpanel.hpp"

class App;
class AppWindow : public QWidget{
public:
    AppWindow(App* parent);
    ~AppWindow();
private:
    // Parent
    App* parent = nullptr;

    // Top
    MenuBar menuBar;
    ToolBar toolBar;

    // Horizontal Splitter for  ------------------------------------------------------
    QSplitter splitter;

    // Splitter Content =============================================================

    // Components List Panel (Pictures Splitter <- List of Pictures  + List of Components - GraphicalObjects)
    QSplitter picturesSplitter;
    PicturesListPanel picturesListPanel;
    ComponentListPanel componentListPanel;

    // Paint Panel
    PaintPanel paintPanel;

    // Control Panel(Basic Configuration + Color Pallete)
    ControlPanel controlPanel;

    // ===============================================================================
    // -------------------------------------------------------------------------------

    // _PRIVATE_METHODS_ AppWindow.hpp
    void initilize();
    void createObjects();   // Pointers Only
    void createLayout();
    void connectEvents();
    void clearMemory();
public:
    // _PUBLIC_METHODS_ AppWindow.hpp
    GET_DECLARATION(App*, parent)
    GET_DECLARATION(QSplitter&, windowSplitter)
    GET_DECLARATION(PicturesListPanel&, picturesListPanel)

    void resizeEvent(QResizeEvent* ev);
    bool eventFilter(QObject*, QEvent*);
    void reload();
};

#endif // APPWINDOW_HPP
