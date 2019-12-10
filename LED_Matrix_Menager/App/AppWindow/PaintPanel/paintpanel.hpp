#ifndef PAINTPANEL_HPP
#define PAINTPANEL_HPP

#include<QWidget>
#include<QGraphicsView>
#include"PaintArea/paintarea.hpp"
#include"PaintTools/painttools.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class AppWindow;
class QGraphicsScene;
class LEDMatrixPicture;
class PaintPanel : public QWidget{
public:
    PaintPanel(AppWindow* parent);
    ~PaintPanel();

protected:
    AppWindow* parent = nullptr;

    PaintTools paintTools;
    PaintArea paintArea;

    //QGraphicsView paintArea;
    //QGraphicsScene* refScene = nullptr;

    void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();
public:
    GET_DECLARATION(PaintArea&, paintArea)
    GET_DECLARATION(AppWindow*, parent)

    void resizeEvent(QResizeEvent* ev);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);
    void reload();
};

#endif // PAINTPANEL_HPP
