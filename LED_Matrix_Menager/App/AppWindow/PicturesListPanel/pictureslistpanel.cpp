// _INCLUDES_ PicturesListPanel.cpp -------------------------------------------------------------------------------------------------------------------
#include "pictureslistpanel.hpp"
#include"../appwindow.hpp"
#include"pictureslistelement.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindowlayoutmacros.hpp"
#include"pictureslistelementlist.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include"../../app.hpp"
#include<QPainter>
#include<QPen>
#include"App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabase.hpp"
#include"App/LEDMatrixPicturesDataBase/LEDMatrixPicture/ledmatrixpicture.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ PicturesListPanel -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ PicturesListPanel.cpp
PicturesListPanel::PicturesListPanel(AppWindow* parent) : QScrollArea (parent), parent(parent), list(this)
{
  initalize();
}

// _DESTRUCTORS_ PicturesListPanel.cpp
PicturesListPanel::~PicturesListPanel(){
    clearMemory();
}

// _PRIVATE_METHODS_ PicturesListPanel.cpp
void PicturesListPanel::initalize(){
    createObjects();
    createLayout();
    connectEvents();
}

void PicturesListPanel::createObjects(){

}

void PicturesListPanel::createLayout(){
    setStyleSheet("background-color: transparent");
    verticalScrollBar()->setStyleSheet("QScrollBar::vertical{background: transparent; width: 5px;} QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical, QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical, QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{border: none; background: none; color: none;} QScrollBar::handle:vertical{background-color: white; border: 1px solid black;}");
    setFrameShape(QFrame::NoFrame);
    setWidget(&list);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    show();
}

void PicturesListPanel::connectEvents(){
    installEventFilter(this);
}

void PicturesListPanel::clearMemory(){

}

void PicturesListPanel::createContextMenu(QAction *actions){
    // Action 1 (0) Add Pictures Data Base
    (actions + 0)->setText("New Pictures Catalog");
    (actions + 0)->setParent(this);
}

void PicturesListPanel::execContextMenu(QPoint& eventPos){
    QMenu menu;
    QAction action[1];
    createContextMenu(action);
    uint i = 0;
    for( ; i < 1; i++){
        menu.addAction(action + i);
    }
    QAction* at = nullptr;
    at = menu.exec(eventPos);
    for(i = 0; i < 1; i++){
        if(at == action + i)
            break;
    }
    switch(i){
    case 0:
    {
        addNewDbObj(new LEDMatrixPictureDataBase());
     }
        break;
    default:
        break;
    }
}

// _PUBLIC_METHODS_ PicturesListPanel.cpp
GET_DEFINITION(PicturesListPanel, AppWindow*, parent)
GET_DEFINITION(PicturesListPanel, PicturesList&, list)

void PicturesListPanel::resizeEvent(QResizeEvent *ev){
    list.resize(LO_DATABASE_VIEWER_LIST_SIZE(LAYOUT_CURRENT_HEIGHT));
}

void PicturesListPanel::clear(){
    list.clearElements();
}

bool PicturesListPanel::load(LEDMatrixPictureDataBase *db){
    list.load(db);
}

bool PicturesListPanel::clearAndLoad(LEDMatrixPictureDataBase *db){
    list.clearElements();
    list.load(db);
}
/*
bool PicturesListPanel::clearAndLoadDbObj(DataBaseObject *dbObj){
    list.clearElements();
    list.loadDBObject(dbObj);
}

bool PicturesListPanel::loadDbObj(DataBaseObject *dbObj){
    list.loadDBObject(dbObj);
}
*/
PicturesListElement* PicturesListPanel::createElement(DataBaseObject* refObj, PicturesListElement* refObjParent){
    return PicturesListPanel::createElement(refObj, refObjParent, refObj->getObjectType());
}

PicturesListElement* PicturesListPanel::createElement(DataBaseObject* refObj, PicturesListElement* refObjParent, uint type){
    switch(type){
    case DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE):
    {
        return (new PicturesListElement(&list, refObj, refObjParent))->allowUpdate();
    }
        break;
    case DB_GET_REAL_TYPE(DataBaseObject, DATABASE_OBJECT_DATABASE):
    {
        return (new PicturesListElementList(&list, refObj, refObjParent))->allowUpdate();
    }
        break;
    default:
        break;
    }
    return nullptr;
}

bool PicturesListPanel::eventFilter(QObject *obj, QEvent *ev){
    // Events Catched by PicturesListPanel
    // - Mouse Pressed (Right Button on PicturesListPanel widget, call function execContextMenu)
    switch(ev->type()){
    case QEvent::MouseButtonPress:
    {

    }
        break;
    case QEvent::MouseButtonRelease:
    {
        if(!list.get_elementAtEditMode()){
            if(obj == this && static_cast<QMouseEvent*>(ev)->button() == Qt::RightButton){
                QPoint point = static_cast<QMouseEvent*>(ev)->globalPos();
                execContextMenu(point);
                return true;
            }
        }
    }
        break;
    default:
        break;
    }
    return QScrollArea::eventFilter(obj, ev);
}

void PicturesListPanel::paintEvent(QPaintEvent *ev){
    QPainter p(viewport());
    QPen pen(QColor(0,0,0));
    p.setPen(pen);
    p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
}
// ----------------------------------------------------------------------------------------------------------------------------------------------
