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

void PaintArea::autocomputeSceneSize()
{

  /*// Widget viewport recangle
  QRectF widget_rect_in_scene(mapToScene(-20, -20), mapToScene(rect().bottomRight() + QPoint(20, 20)));

  // Copy the new size from the old one
  QPointF new_top_left(sceneRect().topLeft());
  QPointF new_bottom_right(sceneRect().bottomRight());

  // Check that the scene has a bigger limit in the top side
  if (sceneRect().top() > widget_rect_in_scene.top())
    new_top_left.setY(widget_rect_in_scene.top());

  // Check that the scene has a bigger limit in the bottom side
  if (sceneRect().bottom() < widget_rect_in_scene.bottom())
    new_bottom_right.setY(widget_rect_in_scene.bottom());

  // Check that the scene has a bigger limit in the left side
  if (sceneRect().left() > widget_rect_in_scene.left())
    new_top_left.setX(widget_rect_in_scene.left());

  // Check that the scene has a bigger limit in the right side
  if (sceneRect().right() < widget_rect_in_scene.right())
    new_bottom_right.setX(widget_rect_in_scene.right());

  // Set new scene size*/
  setSceneRect(scene()->get_tempItemsBoundingRect().united(mapToScene(rect()).boundingRect()));

}

bool PaintArea::eventFilter(QObject *obj, QEvent *ev){
    qDebug() << ev->type();
    switch (ev->type()) {
    /*case QEvent::MouseMove:
    {
        if(obj == this){
            QGraphicsView::mouseMoveEvent(static_cast<QMouseEvent*>(ev));
            if (static_cast<QMouseEvent*>(ev)->buttons() & Qt::LeftButton)
              // If we are moveing with the left button down, update the scene to trigger autocompute
              //scene()->update(mapToScene(rect()).boundingRect());
                autocomputeSceneSize();

        }
    }
        break;
    case QEvent::MouseButtonPress:
    {
        if(obj == this){
            if (static_cast<QMouseEvent*>(ev)->buttons() & Qt::LeftButton)
                // Set drag mode when left button is pressed
                setDragMode(QGraphicsView::ScrollHandDrag);
            QGraphicsView::mousePressEvent(static_cast<QMouseEvent*>(ev));
            return true;
        }
    }
        break;
    case QEvent::MouseButtonRelease:
    {

        if(obj == this){
            if (dragMode() & QGraphicsView::ScrollHandDrag)
                // Unset drag mode when left button is released
                setDragMode(QGraphicsView::NoDrag);
            QGraphicsView::mouseReleaseEvent(static_cast<QMouseEvent*>(ev));
        }

    }
    break;*/
    case LEDMatrixPictureEventChangeMode::LEDMatrixPictureChangeMode:
    {
        if(scene()) return QApplication::sendEvent(scene(), ev);
    }
        break;
    default:
        break;
    }
    if(scene() && scene()->get_changedFlag())  parent->get_parent()->reload();
    return QGraphicsView::eventFilter(obj, ev);
}

void PaintArea::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPointF delta = lastMousePos - mapToScene(static_cast<QMouseEvent*>(event)->pos());
        (lastMousePos = mapToScene(static_cast<QMouseEvent*>(event)->pos()))+=(delta);
        QRectF rect = sceneRect();
        rect.translate(delta);
        setSceneRect(rect);
        autocomputeSceneSize();
    }
    QGraphicsView::mouseMoveEvent(event);
  /*if (event->buttons() & Qt::LeftButton)
    // If we are moveing with the left button down, update the scene to trigger autocompute
    //scene()->update(mapToScene(rect()).boundingRect());*/

}

void PaintArea::mousePressEvent(QMouseEvent* event)
{

   lastMousePos = mapToScene(static_cast<QMouseEvent*>(event)->pos());
  if (event->buttons() & Qt::LeftButton)
    // Set drag mode when left button is pressed
    setDragMode(QGraphicsView::ScrollHandDrag);
  QGraphicsView::mousePressEvent(event);
}

void PaintArea::mouseReleaseEvent(QMouseEvent* event)
{
    lastMousePos = mapToScene(static_cast<QMouseEvent*>(event)->pos());
  if (dragMode() & QGraphicsView::ScrollHandDrag)
    // Unset drag mode when left button is released
    setDragMode(QGraphicsView::NoDrag);
  QGraphicsView::mouseReleaseEvent(event);
}

void PaintArea::wheelEvent(QWheelEvent *ev)
  {

    // if ctrl pressed, use original functionality
      if (ev->modifiers() & Qt::ControlModifier)
        QGraphicsView::wheelEvent(ev);
      // Rotate scene
      else if (ev->modifiers() & Qt::ShiftModifier)
      {
        if (ev->delta() > 0)
        {
          rotate(1);
        }
        else
        {
          rotate(-1);
        }
      }
      // Zoom
      else
      {
        ViewportAnchor previous_anchor = transformationAnchor();
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        if (ev->delta() > 0)
        {
          scale(1.1, 1.1);
        }
        else
        {
          scale(0.9, 0.9);
        }
        setTransformationAnchor(previous_anchor);
      }
      autocomputeSceneSize();
  }

void PaintArea::drawBackground(QPainter *painter, const QRectF &rect){
    //painter->drawRect(sceneRect());
}

void PaintArea::saveView(){
    if(scene())     scene()->setLastViewRect(mapToScene(rect()).boundingRect());
}

LEDMatrixPicture* PaintArea::scene(){
    return static_cast<LEDMatrixPicture*>(QGraphicsView::scene());
}

void PaintArea::setScene(LEDMatrixPicture *newScene){
    // Save View For Last Scene
    saveView();
    QGraphicsView::setScene(newScene);
    if(newScene){
        fitInView(newScene->getLastViewRect(), Qt::KeepAspectRatio);
    }

}

// ----------------------------------------------------------------------------------------------------------------------------------------------
