// _INCLUDES_ PaintPanel.cpp -------------------------------------------------------------------------------------------------------------------
#include "paintpanel.hpp"
#include"../appwindow.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindowlayoutmacros.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include<QPainter>
#include<QPen>
#include"App/LEDMatrixPicturesDataBase/LEDMatrixPicture/ledmatrixpicture.hpp"
#include"App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabase.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ PaintPanel -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ PaintPanel.cpp
PaintPanel::PaintPanel(AppWindow* parent) : QWidget(parent), parent(parent), paintTools(this), paintArea(this)
{
   initalize();
}

// _DESTRUCTORS_ PaintPanel.cpp
PaintPanel::~PaintPanel(){
    clearMemory();
}

// _PRIVATE_METHODS_ PaintPanel.cpp
void PaintPanel::initalize(){
    paintTools.move(LO_PAINT_TOOLS_POS);
    paintArea.move(LO_PAINT_AREA_POS);
    createObjects();
    createLayout();
    connectEvents();
}

void PaintPanel::createObjects(){

}

void PaintPanel::createLayout(){

}

void PaintPanel::connectEvents(){
    //installEventFilter(this);
}

void PaintPanel::clearMemory(){

}

// _PUBLIC_METHODS_ PaintPanel.cpp
GET_DEFINITION(PaintPanel, PaintArea&, paintArea)
GET_DEFINITION(PaintPanel, AppWindow*, parent)

void PaintPanel::resizeEvent(QResizeEvent *ev){
    paintTools.resize(LO_PAINT_TOOLS_SIZE);
    paintArea.resize(LO_PAINT_AREA_SIZE);
}

void PaintPanel::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setPen(pen);
    //p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
}

bool PaintPanel::eventFilter(QObject *obj, QEvent *ev){
    return QWidget::eventFilter(obj, ev);
}

void PaintPanel::reload(){
    LEDMatrixPicture* picture = static_cast<LEDMatrixPicture*>(parent->get_picturesListPanel().get_list().get_currentElementRefObj());
    if(picture && picture->getObjectType() == DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE))
        paintArea.setScene(picture);
    else
        paintArea.setScene(nullptr);
    paintArea.show();
}




/*void PaintPanel::setPicture(LEDMatrixPicture* newPicture){
    paintArea.setScene(newPicture);
}*/
// ----------------------------------------------------------------------------------------------------------------------------------------------
