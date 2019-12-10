#ifndef PAINTAREA_HPP
#define PAINTAREA_HPP

#include<QWidget>
#include<QGraphicsView>
//#include"../PaintTools/painttools.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class PaintPanel;
class QGraphicsScene;
class LEDMatrixPicture;
class PaintArea : public QGraphicsView{
public:
    PaintArea(PaintPanel* parent, QGraphicsScene* refScene = nullptr);
    virtual ~PaintArea() override;

protected:
    PaintPanel* parent = nullptr;
    QPointF lastMousePos;

    //PaintTools paintTools;
    //QGraphicsView view;
    //QGraphicsScene* refScene = nullptr;
    bool repaintPixelPointer = false;

    void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();

    void autocomputeSceneSize();

    inline void saveView();

public:
    GET_DECLARATION(PaintPanel*, parent)

    void resizeEvent(QResizeEvent* ev) override;
    void paintEvent(QPaintEvent* ev) override;
    bool eventFilter(QObject* obj, QEvent* ev) override;
    void wheelEvent(QWheelEvent* ev)override;
    void mouseMoveEvent(QMouseEvent* event)override;

    void mousePressEvent(QMouseEvent* event)override;

    void mouseReleaseEvent(QMouseEvent* event)override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    inline LEDMatrixPicture* scene();
    void setScene(LEDMatrixPicture*);
};

#endif // PAINTAREA_HPP
