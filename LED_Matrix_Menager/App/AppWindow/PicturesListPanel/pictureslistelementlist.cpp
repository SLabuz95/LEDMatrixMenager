
// _INCLUDES_ PicturesListElementList.cpp -------------------------------------------------------------------------------------------------------------------
#include "pictureslistelementlist.hpp"
#include"../appwindowlayoutmacros.hpp"
#include"pictureslistpanel.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QDebug>
#include<QSize>
#include<QMenu>
#include<QAction>
#include<QMouseEvent>
#include"../../app.hpp"
#include"../appwindow.hpp"
#include<QPainter>
#include<QPen>
#include"App/LEDMatrixPicturesDataBase/LEDMatrixPicture/ledmatrixpicture.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ PicturesListElementList -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ PicturesListElementList.cpp
PicturesListElementList::PicturesListElementList(PicturesList* mainListParent, DataBaseObject* refObj, PicturesListElement* refListParent) :
    PicturesListElement (mainListParent, refObj, refListParent), expandButton(this)
{
    initalize();
}

// _DESTRUCTORS_ PicturesListElementList.cpp
PicturesListElementList::~PicturesListElementList(){
    clearMemory();
    clearElements();
}

// _PRIVATE_METHODS_ PicturesListElementList.cpp
void PicturesListElementList::createObjects(){
    if(refObj)
        load();
}

void PicturesListElementList::createLayout(){
    if(numbOfElements > 0){
        expandButton.show();
        expandButton.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_GEOMETRY);
        checkBox.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_GEOMETRY);
        titleLE.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_GEOMETRY);
    }else{
        expandButton.hide();
    }

}

void PicturesListElementList::clearMemory(){
  clearElements();
}

void PicturesListElementList::generateText(){

}

void PicturesListElementList::reload(){
    for(uint i = 0; i < numbOfElements; i++)
        (*(elements + i))->reload();
}

bool PicturesListElementList::addElement(PicturesListElement *newElem){
    ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(PicturesListElement, elements, numbOfElements, newElem);
}

bool PicturesListElementList::removeElement(PicturesListElement *remElem){
    ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(PicturesListElement, elements, numbOfElements, remElem);
}


bool PicturesListElementList::addListElement(PicturesListElement *newObj){
    addElement(newObj);
    mainListParent->reallocateElements(parent);
}

void PicturesListElementList::reallocateElements(PicturesListElement* &caller){
    static uint level = 0;
    level++;
    PicturesListElement* tempElement = nullptr;
    if(!caller){
        curHeight = LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT;
        for(uint i = 0; i < numbOfElements; i++){
            tempElement = (*(elements + i));
            if(expandButton.get_expanded()){
                tempElement->reallocateElements(caller);
                reallocationFlag = true;
                tempElement->set_reallocationFlag(true);
                tempElement->setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curHeight, tempElement->get_curHeight()));
                curHeight += tempElement->get_curHeight();
                tempElement->show();
            }else{
                tempElement->hide();
            }
        }
    }else{
        for(uint i = 0; i < numbOfElements; i++){
            tempElement = (*(elements + i));
            if(caller == tempElement)  {curHeight -= tempElement->get_curHeight(); caller = nullptr;}
            tempElement->reallocateElements(caller);
            if(!caller){
                if(expandButton.get_expanded()){
                    tempElement->set_reallocationFlag(true);
                    tempElement->setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curHeight, tempElement->get_curHeight()));
                    curHeight += tempElement->get_curHeight();
                    tempElement->show();
                }else{
                    tempElement->hide();
                }
            }
        }
    }
    level--;
    if(!caller){
        reallocationFlag = true;
        resize(LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight));
    }

}


void PicturesListElementList::load(){
    static uint level = 0;
    curHeight = LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT;
    if(refObj){
        // Find All objects
        uint numbOfParameters = refObj->getNumbOfParameters();
        DataBaseObject* tempObj = nullptr;
        GetParamRules getParamRules;
        for(uint i = 0; i < numbOfParameters; i++){
            if(refObj->isParamObject(i)){
                getParamRules.index = 0;
                while(true){
                    getParamRules.param = i;
                    getParamRules.initialized = false;
                    getParamRules.nextAvailable = false;
                    if(!refObj->getParam(&tempObj, getParamRules) && !getParamRules.initialized){
                        // Error
                    }
                    if(tempObj){
                            // Add Element
                            if(!addElement(mainListParent->get_parent()->createElement(tempObj, this))){
                                // Error
                            }
                            curHeight += (*(elements + numbOfElements -1))->get_curHeight();
                            (*(elements + numbOfElements - 1))->hide();
                    }else{
                        // Error
                    }
                    if(getParamRules.nextAvailable){
                        getParamRules.index++;
                    }else{
                        break;
                    }
                }
            }
        }

    }
    resize(LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight));
}

void PicturesListElementList::addNewDbObj(DataBaseObject* dbObj){
    if(!dbObj)   return;
    if(!expandButton.get_expanded())   expandButton.expand();
    mainListParent->set_newObjectFlag(true);
    addListElement(mainListParent->get_parent()->createElement(dbObj, this));
    mainListParent->putElementAtEditMode(*(elements + numbOfElements - 1));
}

void PicturesListElementList::createContextMenu(QAction *actions){
    // Action 1 (0) Add Test Group
    (actions + 0)->setText("Add Category");
    (actions + 0)->setParent(this);
    (actions + 1)->setText("Add Picture");
    (actions + 1)->setParent(this);
    (actions + 2)->setText("Change Name");
    (actions + 2)->setParent(this);
}

void PicturesListElementList::execContextMenu(QPoint& eventPos){
    QMenu menu;
    QAction action[3];
    createContextMenu(action);
    uint i = 0;
    for( ; i < 3; i++){
        menu.addAction(action + i);
    }
    QAction* at = nullptr;
    at = menu.exec(eventPos);
    for(i = 0; i < 3; i++){
        if(at == action + i)
            break;
    }
    switch(i){
    /*case 0:
    {

        addNewDbObj(new DataBaseCategory());
        //parent->get_parent()->get_dbMenager().get_dataBase()->addDataBaseObject(newDbCategory);
    }
        break;*/
    case 1:
    {
        addNewDbObj(new LEDMatrixPicture());
    }
        break;
    case 2:
    {
        mainListParent->putElementAtEditMode(this);
    }
        break;
    default:
        break;
    }
}

// _PUBLIC_METHODS_ PicturesListElementList.cpp
    GET_DEFINITION(PicturesListElementList, PicturesListElement**, elements);
    GET_DEFINITION(PicturesListElementList, uint, numbOfElements);

void PicturesListElementList::paintEvent(QPaintEvent *ev){
    PicturesListElement::paintEvent(ev);
    PicturesListElementList::createLayout();
}

void PicturesListElementList::resizeEvent(QResizeEvent *ev){
    if(!reallocationFlag){
        PicturesListElement* tempPtr = nullptr;
        mainListParent->reallocateElements(tempPtr);
    }
    reallocationFlag = false;
}

bool PicturesListElementList::eventFilter(QObject *obj, QEvent *ev){
    switch(ev->type()){
    case QEvent::MouseButtonDblClick:
    {
        return true;
    }
        break;
    case QEvent::MouseButtonPress:
    {
        if(obj == this)
        return true;
    }
        break;
    case QEvent::MouseButtonRelease:
    {
        if(!mainListParent->get_elementAtEditMode()){
            if(obj == this){
                if(static_cast<QMouseEvent*>(ev)->button() == Qt::RightButton){
                    QPoint point = static_cast<QMouseEvent*>(ev)->globalPos();
                    execContextMenu(point);
                    return true;
                }
            }
            if(obj == &expandButton){
                expandButton.toggle();
                PicturesListElement* tempPtr = this;
                mainListParent->reallocateElements(tempPtr);
                return true;
            }
        }
    }
        break;
    default:
        break;
    }
    return PicturesListElement::eventFilter(obj, ev);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
