// _INCLUDES_ ControlPanel.cpp -------------------------------------------------------------------------------------------------------------------
#include "controlpanel.hpp"
#include"../appwindow.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindowlayoutmacros.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include<QPainter>
#include<QPen>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ ControlPanel -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ ControlPanel.cpp
ControlPanel::ControlPanel(AppWindow* parent) : QWidget (parent), parent(parent), splitter(this), basicConfig(QString("PLACEHOLDER"), this), colorDialog(this)
{
  initalize();
}

// _DESTRUCTORS_ ControlPanel.cpp
ControlPanel::~ControlPanel(){
    clearMemory();
}

// _PRIVATE_METHODS_ ControlPanel.cpp
void ControlPanel::initalize(){
    createObjects();
    createLayout();
    connectEvents();
}

void ControlPanel::createObjects(){
    basicConfig.setAlignment(Qt::AlignCenter);
    colorDialog.setOption(QColorDialog::NoButtons);
    splitter.setOrientation(Qt::Vertical);
    splitter.addWidget(&basicConfig);
    splitter.addWidget(&colorDialog);
}

void ControlPanel::createLayout(){

}

void ControlPanel::connectEvents(){
    installEventFilter(this);
}

void ControlPanel::clearMemory(){

}

// _PUBLIC_METHODS_ ControlPanel.cpp

void ControlPanel::reload(){
    /*LEDMatrixPicture* curPicture = nullptr;
    LEDMatrixPicture* curPictureListElement = static_cast<LEDMatrixPicture*>(parent->get_picturesListPanel().get_list().get_currentElementRefObj());
    if(list.get_elements() && list.get_numbOfElements() > 0)
        curPicture = static_cast<LEDMatrixPicture*>((*list.get_elements())->get_refObj());
    // Element Changed - Reload List
    if(curPicture != curPictureListElement){
        clearAndLoad(curPictureListElement);
    }*/
}

void ControlPanel::resizeEvent(QResizeEvent *ev){
    splitter.resize(size());
}

void ControlPanel::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setPen(pen);
    p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
}

bool ControlPanel::eventFilter(QObject *obj, QEvent *ev){
    return QWidget::eventFilter(obj, ev);
}
// ----------------------------------------------------------------------------------------------------------------------------------------------
