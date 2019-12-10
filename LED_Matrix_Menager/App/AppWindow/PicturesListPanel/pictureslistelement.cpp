
// _INCLUDES_ PicturesListElement.cpp -------------------------------------------------------------------------------------------------------------------
#include "pictureslistelement.hpp"
#include"../appwindowlayoutmacros.hpp"
#include<QResizeEvent>
#include"pictureslist.hpp"
#include<QPainter>
#include<QPen>
#include<QAction>
#include<QMenu>
#include<QKeyEvent>
#include"pictureslistpanel.hpp"
#include"../appwindow.hpp"
#include"../../app.hpp"
#include"DataBase/databasesearchengine.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ PicturesListElement -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ PicturesListElement.cpp
PicturesListElement::PicturesListElement(PicturesList* mainListParent, DataBaseObject*& refObj, PicturesListElement* refListParent) :
    mainListParent(mainListParent), parent(refListParent), refObj(refObj), titleLE(this), checkBox(this)
{
    initalize();
    if(refListParent)
        setParent(refListParent);
    else {
        setParent(mainListParent);
    }
}


// _DESTRUCTORS_ PicturesListElement.cpp
PicturesListElement::~PicturesListElement(){
    clearMemory();
}

// _PRIVATE_METHODS_ PicturesListElement.cpp
void PicturesListElement::initalize(){
    setUpdatesEnabled(false);
    generateText();
    createObjects();
    createLayout();
    connectEvents();
}

void PicturesListElement::generateText(){

}

void PicturesListElement::createObjects(){
    if(!mainListParent->get_newObjectFlag()){
        QString title;
        GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
        if(!refObj->getParam(&title, gpr) || !gpr.initialized || title.isEmpty()){
            titleLE.setText(QString("DatabaseObject Error"));
        }else{
            titleLE.setText(title);
        }
    }
}

void PicturesListElement::createLayout(){
    generateText();
    // Title Label
    if(mainListParent->get_elementAtEditMode() == this){
        if(!mainListParent->get_newNameAccepted()){
            titleLE.setStyleSheet("border: 1px solid red;");
        }else{
            titleLE.setStyleSheet("");
        }
        titleLE.setFrame(true);
        titleLE.setReadOnly(false);
    }else{
        titleLE.setReadOnly(true);
        titleLE.setFrame(false);
        titleLE.setStyleSheet("");
    }
    titleLE.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_GEOMETRY);

    // CheckBox
    checkBox.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_GEOMETRY);
}

void PicturesListElement::connectEvents(){
    titleLE.installEventFilter(this);
    this->installEventFilter(this);
}

void PicturesListElement::clearMemory(){

}

void PicturesListElement::reallocateElements(PicturesListElement* &caller){
    curHeight = LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT;
}

void PicturesListElement::createContextMenu(QAction *actions){
    // Action 1 (0) Add Test Group
    (actions + 0)->setText("Change Name");
    (actions + 0)->setParent(this);
}

void PicturesListElement::execContextMenu(QPoint& eventPos){
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
        mainListParent->putElementAtEditMode(this);
    }
        break;
    default:
        break;
    }
}


// _PUBLIC_METHODS_ PicturesListElement.cpp
GET_DEFINITION(PicturesListElement, PicturesList*, mainListParent)
GET_DEFINITION(PicturesListElement, PicturesListElement*, parent)
GET_DEFINITION(PicturesListElement, uint, curHeight)
GET_SET_NDO_DEFINITION(PicturesListElement, DataBaseObject*, refObj)
GET_DEFINITION(PicturesListElement, QLineEdit&, titleLE)
GET_SET_NDO_DEFINITION(PicturesListElement, bool, reallocationFlag);

bool PicturesListElement::editModeCheckName(QKeyEvent *ev){
    QLineEdit* le = &titleLE;
    uint len = le->text().length();
    if(len > 29){
        switch(ev->key()){
        case Qt::Key_Left:
            return false;
        case Qt::Key_Right:
            return false;
        case Qt::Key_Backspace:
            le->backspace();
            break;
        case Qt::Key_Delete:
            le->del();
            break;
        default:
            return true;
        }
    }
    else{
        switch(ev->key()){
        case Qt::Key_Escape:
            mainListParent->editModeCancel();
            return true;
        case Qt::Key_Left:
            return false;
        case Qt::Key_Right:
            return false;
        case Qt::Key_Enter:
            return true;
        case Qt::Key_Tab:
            return true;
        case Qt::Key_Slash:
            return true;
        case Qt::Key_Backslash:
            return true;
        case Qt::Key_Return:
            mainListParent->editModeAccept();
            return true;
        case Qt::Key_Colon:
            return true;
        case Qt::Key_Asterisk:
            return true;
        case Qt::Key_Less:
            return true;
        case Qt::Key_Greater:
            return true;
        case Qt::Key_QuoteDbl:
            return true;
        case Qt::Key_Question:
            return true;
        case Qt::Key_Bar:
            return true;
        case Qt::Key_Alt:
            return true;
        case Qt::Key_Shift:
            return true;
        case Qt::Key_Control:
            return true;
        case Qt::Key_Space:
            return true;
        case Qt::Key_Backspace:
            le->backspace();
            break;
        case Qt::Key_Delete:
            le->del();
            break;
        default:
            le->insert(ev->text());
            break;
        }
    }
    len = le->text().length();
    if(le->text().isEmpty() || len > 30){
        le->setStyleSheet("border: 1px solid red;");
        mainListParent->set_newNameAccepted(false);
        return true;
    }    else{
        le->setStyleSheet("");
    }

    // Check if category exist
    QString tempText = le->text();
    DataBaseSearchEngineFilter* filter = nullptr;
    DataBaseObject* searchObject = nullptr;
    if(!parent){
        // No Parent - check DataBases
        filter = new DataBaseSearchEngineFilter(false, DATABASE_OBJECT_MENAGER, DB_GET_REAL_PARAM(DataBaseMenager, DATABASE_MENAGER_OBJECTS));
        DataBaseSearchEngineFilter* nameDeepFilter = new DataBaseSearchEngineFilter(true, UINT_MAX, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempText);
        filter->addLinkedDeepFilter(nameDeepFilter);
        searchObject = &mainListParent->get_parent()->get_parent()->get_parent()->get_dbMenager();
    }else{
        filter = new DataBaseSearchEngineFilter(false, DATABASE_OBJECT_DATABASE, DB_GET_REAL_PARAM(DataBaseCategory, DATABASE_CATEGORY_OBJECTS));
        DataBaseSearchEngineFilter* nameDeepFilter = new DataBaseSearchEngineFilter(true, UINT_MAX, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempText);
        filter->addLinkedDeepFilter(nameDeepFilter);
        searchObject = parent->get_refObj();
    }
    DataBaseSearchEngine dbSearchEngine;
    dbSearchEngine.addFilter(filter);
    if(searchObject && dbSearchEngine.search(searchObject)){   // Success
        if(dbSearchEngine.get_result().numbOfObjects > 0){  // Category with the same name exist
            if(!mainListParent->get_newObjectFlag()){
                QString oldName;
                GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
                if(!refObj->getParam(&oldName, gpr)){
                    le->setStyleSheet("border: 1px solid red;");
                    mainListParent->set_newNameAccepted(false);
                }
                if(oldName == tempText){
                    le->setStyleSheet("");
                    mainListParent->set_newNameAccepted(true);
                }else{
                    le->setStyleSheet("border: 1px solid red;");
                    mainListParent->set_newNameAccepted(false);
                }
            }else{
                le->setStyleSheet("border: 1px solid red;");
                mainListParent->set_newNameAccepted(false);
            }
        }else{
            le->setStyleSheet("");
            mainListParent->set_newNameAccepted(true);
        }
    }else{  // Search Engine Fail
        le->setStyleSheet("border: 1px solid red;");
        mainListParent->set_newNameAccepted(false);
    }

    return true;
}

void PicturesListElement::resizeEvent(QResizeEvent *event){
    // Title Label
    titleLE.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_GEOMETRY);

    // CheckBox
    checkBox.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_GEOMETRY);

}

void PicturesListElement::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setBrush(QColor(190, 190, 190, 200));
    p.setPen(pen);
    if(mainListParent->get_currentElement() == this){
        p.setBrush(QColor(240, 240, 240, 200));
    }else{
        p.setBrush(QColor(220, 220, 220, 200));
    }
    p.drawRoundedRect(QRect(QPoint(0,0), size() - QSize(1, 1)), 5, 5);
    PicturesListElement::createLayout();
}

bool PicturesListElement::eventFilter(QObject *obj, QEvent *ev){
    switch (ev->type()) {
        case QEvent::MouseButtonDblClick:
        {
            if(obj == this || obj == &titleLE){
                //mainListParent->get_parent()->get_parent()->get_parent()->openDBObject(this);
                return true;
            }
        }
        break;
        case QEvent::KeyPress:
        {
            if(obj == &titleLE && this == mainListParent->get_elementAtEditMode()){
                if(editModeCheckName(static_cast<QKeyEvent*>(ev))){
                    return true;
                }
            }
        }
        break;
        case QEvent::MouseButtonPress:
        {
        if(!mainListParent->get_elementAtEditMode()){
            if(obj == this || obj == &titleLE){
                if(static_cast<QMouseEvent*>(ev)->button() == Qt::RightButton){
                    QPoint point = static_cast<QMouseEvent*>(ev)->globalPos();
                    execContextMenu(point);
                    return true;
                }else{
                    mainListParent->selectElement(this);
                    mainListParent->get_parent()->get_parent()->reload();
                    return true;
                }
            }
        }
        }
        break;
    default:
        break;
    }
    return QWidget::eventFilter(obj, ev);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
