#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP

#include<QWidget>
#include<QSplitter>
#include<QColorDialog>
#include<QLabel>

class AppWindow;
class ControlPanel : public QWidget{
public:
    ControlPanel(AppWindow* parent);
    ~ControlPanel();

protected:
    AppWindow* parent = nullptr;

    // Vertical Splitter For ------------------------------------------------
    QSplitter splitter;

    // Splitter Content =====================================================

    // Basic Config Scroll Area Widget
    QLabel basicConfig; // PlaceHolder

    // Color Dialog Picker
    QColorDialog colorDialog;

    // ======================================================================
    // ----------------------------------------------------------------------
    void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();
public:

    void resizeEvent(QResizeEvent* ev);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);

    void reload();
};

#endif // CONTROLPANEL_HPP
