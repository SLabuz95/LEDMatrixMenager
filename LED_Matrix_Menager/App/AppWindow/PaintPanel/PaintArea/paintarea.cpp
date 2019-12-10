// _INCLUDES_ PaintArea.cpp -------------------------------------------------------------------------------------------------------------------
#include "paintarea.hpp"
#include"../paintpanel.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"App/LEDMatrixPicturesDataBase/LEDMatrixPicture/EventChangeMode/eventchangemode.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include<QPainter>
#include<QPen>
#include<QDebug>
#include<QApplication>
#include"App/LEDMatrixPicturesDataBase/LEDMatrixPicture/ledmatrixpicture.hpp"
#include"App/AppWindow/appwindow.hpp"
#include"App/app.hpp"
#include<QtMath>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ PaintArea -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ PaintArea.cpp
PaintArea::PaintArea(PaintPanel* parent, QGraphicsScene* refScene) : QGraphicsView(refScene,parent), parent(parent)
{
   initalize();

}

// _DESTRUCTORS_ PaintArea.cpp
PaintArea::~PaintArea(){
    clearMemory();
}

// _PRIVATE_METHODS_ PaintArea.cpp
void PaintArea::initalize(){
    //setMouseTracking(true);
    //setDragMode(QGraphicsView::ScrollHandDrag);
    //setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    //setInteractive(false);
    //setRenderHint(QPainter::HighQualityAntialiasing, true);
    createObjects();
    createLayout();
    connectEvents();
}

void PaintArea::createObjects(){

}

void PaintArea::createLayout(){

}

void PaintArea::connectEvents(){
    installEventFilter(this);
}

void PaintArea::clearMemory(){

}

// _PUBLIC_METHODS_ PaintArea.cpp
GET_DEFINITION(PaintArea, PaintPanel*, parent)


void PaintArea::resizeEvent(QResizeEvent *ev){

}

void PaintArea::paintEvent(QPaintEvent *ev){

    QGraphicsView::paintEvent(ev);
}

bool PaintArea::eventFilter(QObject *obj, QEvent *ev){
    switch (ev->type()) {

    case LEDMatrixPictureEventChangeMode::LEDMatrixPictureChangeMode:
    {
        if(scene()) return QApplication::sendEvent(scene(), ev);
    }
        break;
    default:
        break;
    }
    if(scene() && static_cast<LEDMatrixPicture*>(scene())->get_changedFlag())  parent->get_parent()->reload();
    return QGraphicsView::eventFilter(obj, ev);
}

void PaintArea::wheelEvent(QWheelEvent *ev)
  {
    if(ev->delta() > 0){
        scale(1.1, 1.1);
        if(scene()){
            //viewport()->rect();
            //setSceneRect(QRectF(sceneRect().topLeft(),frameSize()));
            //qDebug() << "Transform";
            //qDebug() << sceneRect();
        }
    }
    else{
        scale(0.9, 0.9);
        if(scene()){
            //setSceneRect(QRectF(sceneRect().topLeft(),frameSize()));
            //qDebug() << "Transform";
            //qDebug() << sceneRect();
        }
    }
    //QGraphicsView::wheelEvent(ev);
  }

void PaintArea::drawBackground(QPainter *painter, const QRectF &rect){
    painter->drawRect(sceneRect());
}
// ----------------------------------------------------------------------------------------------------------------------------------------------
