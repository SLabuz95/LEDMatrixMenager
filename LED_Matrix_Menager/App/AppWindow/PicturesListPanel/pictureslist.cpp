
// _INCLUDES_ PicturesList.cpp -------------------------------------------------------------------------------------------------------------------
#include "pictureslist.hpp"
#include"pictureslistpanel.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindowlayoutmacros.hpp"
#include"pictureslistelement.hpp"
#include"pictureslistelementlist.hpp"
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<QDebug>
#include<QSize>
#include<QLineEdit>
#include"App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabase.hpp"
#include"App/AppWindow/appwindow.hpp"
#include"App/app.hpp"
#include"DataBase/databasecategory.hpp"
//#include"../SharedCode/App/app.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ PicturesList -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ PicturesList.cpp
PicturesList::PicturesList(PicturesListPanel* parent) : QWidget (parent), parent(parent)

{
  initalize();
}

// _DESTRUCTORS_ PicturesList.cpp
PicturesList::~PicturesList(){
    clearMemory();
}

// _PRIVATE_METHODS_ PicturesList.cpp
void PicturesList::initalize(){
    //createObjects();
    createLayout();
    connectEvents();
}

void PicturesList::createObjects(){

}

void PicturesList::createLayout(){

}

void PicturesList::connectEvents(){

}

void PicturesList::clearMemory(){
    clearElements();
}


// _PUBLIC_METHODS_ PicturesList.cpp
GET_DEFINITION(PicturesList, PicturesListPanel*, parent)
GET_DEFINITION(PicturesList, PicturesListElement**, elements)
GET_DEFINITION(PicturesList, uint, numbOfElements)
GET_DEFINITION(PicturesList,PicturesListElement*, currentElement)
GET_DEFINITION(PicturesList, PicturesListElement*, elementAtEditMode)
GET_SET_NDO_DEFINITION(PicturesList, bool, newNameAccepted)
GET_SET_NDO_DEFINITION(PicturesList, bool, newObjectFlag)

bool PicturesList::addElement(PicturesListElement *newElem){
     ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(PicturesListElement, elements, numbOfElements, newElem);
}

bool PicturesList::removeElement(PicturesListElement *remElem){
    ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(PicturesListElement, elements, numbOfElements, remElem);
}

void PicturesList::clearElements(){
    ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);
}

DataBaseObject* PicturesList::get_currentElementRefObj(){
    if(currentElement)
        return currentElement->get_refObj();
    else
        nullptr;
}

void PicturesList::reload(){
    for(uint i = 0; i < numbOfElements; i++)
        (*(elements + i))->reload();
}

bool PicturesList::load(LEDMatrixPictureDataBase *db){
    uint curHeight = 0;
    if(db){
        //uint tempNumbOfNewDBElements = db->get_numbOfDataBaseObjects();
        //uint tempNumbOfElements = numbOfElements;
            // _PH_ Algorytm sprawdzania przekroczenia
            /* 1. Pobierz ilość obiektów bazy ktora chcesz dodac
             * 2. Pobierz aktulaną ilość obiektów listy
             * 3. Oblicz sumę obu licz podzielonych wczesniej przez 2
             * 4. Sprawdz czy ta suma jest mniejsza od maxa podzielonego przez 2
             * 5. Jak mniejsza to git
             * 6. Jak nie, to sprawdz czy równa
             * 7. Jeśli równa, to sprawdz czy suma obu liczb ale niepodzielonych jest równa max
             * 8. Jeśli jest, to jest git
             * 9. Jesli nie, to nie git
             */
            //uint sumOfHalfs = (tempNumbOfElements*0.5) + (tempNumbOfNewDBElements*0.5);
            //if(sumOfHalfs < static_cast<uint>(UINT_MAX*0.5) || (sumOfHalfs == static_cast<uint>(UINT_MAX*0.5) && ((tempNumbOfElements + tempNumbOfNewDBElements) == UINT_MAX))){
                //DataBaseObject** objects = db->get_dataBaseObjects();
                //PicturesListElement** newElements = new PicturesListElement*[numbOfElements + tempNumbOfNewDBElements];
                // Przepisz utworzone elementy
                //uint i = 0;
                //for( ; i < numbOfElements; i++, newElements++, elements++){
                 //   (*newElements) = (*elements);
                 //   curHeight += (*elements)->get_curHeight();
                //}
                //elements -= numbOfElements;
                //newElements -= numbOfElements;
                //SET_PTR_DOA(elements, newElements);
                //elements += numbOfElements;
                //numbOfElements += tempNumbOfNewDBElements;
                //for( ; i < numbOfElements; i++, elements++, objects++){

                    //(*elements) = parent->createElement((*objects), nullptr);
                    //curHeight += (*elements)->get_curHeight();
                //}
                //elements -= numbOfElements;
                //}else{  // Gdy nie Git
                 //   resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
                  //  return false;
                //}
            loadDBObject(db);
        }else{
            resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
            return false;
        }
    resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
    return true;
}

bool PicturesList::loadDBObject(LEDMatrixPictureDataBase* dbObj){
    uint curHeight = 0;
    if(dbObj){
        if(numbOfElements + 1 > numbOfElements){
            PicturesListElement** newElements = new PicturesListElement*[numbOfElements + 1];
            PicturesListElement** tempNewElements = newElements;
            for(uint i = 0; i < numbOfElements; i++, tempNewElements++, elements++){
                (*tempNewElements) = (*elements);
                curHeight += (*elements)->get_curHeight();
            }
            (*tempNewElements) = parent->createElement(dbObj, nullptr);
            curHeight += (*tempNewElements)->get_curHeight();
            elements -= numbOfElements;
            tempNewElements -= numbOfElements;
            SET_PTR_DOA(elements, tempNewElements);
            numbOfElements++;
            if(newObjectFlag){
                putElementAtEditMode((*(elements + numbOfElements - 1)));
            }
        }else{
            resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
            return false;
        }
    }else{
        resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
        return false;
    }
    resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
    return true;
}

void PicturesList::reallocateElements(PicturesListElement* &caller){
    uint curHeight = 0;
    PicturesListElement** tempElement = elements;
    static const uint level = 0;
    for(uint i = 0; i < numbOfElements; i++,tempElement++){
        if(caller == *tempElement) caller = nullptr;
        (*tempElement)->reallocateElements(caller);
        if(!caller){
            (*tempElement)->set_reallocationFlag(true);
            (*tempElement)->setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curHeight, (*tempElement)->get_curHeight()));
        }
        curHeight += (*tempElement)->get_curHeight();
        (*tempElement)->show();
    }
    reallocationFlag = true;
    resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
}

void PicturesList::putElementAtEditMode(PicturesListElement *ele){
    elementAtEditMode = ele;
    if(newObjectFlag)
        newNameAccepted = false;
    else {
        newNameAccepted = true;
    }
    elementAtEditMode->repaint();
    //elementAtEditMode->get_titleLE().installEventFilter(this);
}

void PicturesList::editModeAccept(){
    if(newNameAccepted){
        QString newName = elementAtEditMode->get_titleLE().text();
        if(newName.isEmpty()){
            newNameAccepted = false;
            elementAtEditMode->repaint();
            return;
        }
        DataBaseObject* refObj = elementAtEditMode->get_refObj();
        SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), UINT_MAX, SET_PARAM_ACTION_ADD};
        if(!refObj->setParam(&newName, spr)){
            newNameAccepted = false;
            elementAtEditMode->repaint();
            return;
        }
        if(newObjectFlag){
            if(refObj->getObjectType() == DATABASE_OBJECT_DATABASE){    // DataBase - add to dbMenager with createFunctin
                if(!parent->get_parent()->get_parent()->get_dbMenager().createDataBase(*static_cast<DataBase*>(refObj)))
                {
                    return;
                }
            }else{  // DataBaseCategory element
                DataBaseObject* refObjOfParent = elementAtEditMode->get_parent()->get_refObj();
                if(refObjOfParent){
                    SetParamRules spr;// = {DB_GET_REAL_PARAM(DataBaseCategory, DATABASE_CATEGORY_OBJECTS), UINT_MAX, SET_PARAM_ACTION_ADD};
                    switch(refObjOfParent->getObjectType()){
                    case DATABASE_OBJECT_DATABASE:
                    case DATABASE_OBJECT_CATEGORY:
                        spr = {DB_GET_REAL_PARAM(DataBaseCategory, DATABASE_CATEGORY_OBJECTS), UINT_MAX, SET_PARAM_ACTION_ADD};
                        break;
                    default:
                        return;
                    }
                    if(!refObjOfParent->setParam(&refObj, spr)){    // Error
                        return;
                    }
                }else{
                    // Internal App Error
                    return;
                }
            }
        }

        //elementAtEditMode->get_titleLE().removeEventFilter(this);
        newObjectFlag = false;
        elementAtEditMode = nullptr;
        newNameAccepted = false;
    }
}

void PicturesList::editModeCancel(){
    if(!newObjectFlag){
        QString oldName;
        DataBaseObject* refObj = elementAtEditMode->get_refObj();
        GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
        if(!refObj->getParam(&oldName, gpr)){
            newNameAccepted = false;
            elementAtEditMode->repaint();
            return;
        }
         elementAtEditMode->get_titleLE().setText(oldName);
    }else{
        if(!elementAtEditMode->get_parent()){    // PicturesList element
             if(!removeElement(elementAtEditMode)){
                 return;
             }
        }else{  // DataBaseViewerElementList element
            if(elementAtEditMode->get_parent() && elementAtEditMode->get_parent()->get_refObj()->getObjectType() < DATABASE_OBJECT_RECORD){
                if(!static_cast<PicturesListElementList*>(elementAtEditMode->get_parent())->removeElement(elementAtEditMode)){
                    return;
                }
            }else{  // Internal App Error
                return;
            }
        }
        PicturesListElement* tempPtr = nullptr;
        reallocateElements(tempPtr);
        newObjectFlag = false;
    }
    elementAtEditMode = nullptr;
    newNameAccepted = false;
}

void PicturesList::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setBrush(QColor(230,230,230, 200));
    p.setPen(pen);
    p.drawRoundedRect(QRect(QPoint(0,0), size() - QSize(1,1)), 5, 5);
}

void PicturesList::resizeEvent(QResizeEvent *ev){
    if(!reallocationFlag){
        PicturesListElement* tempPtr = nullptr;
        reallocateElements(tempPtr);
    }
    reallocationFlag = false;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
