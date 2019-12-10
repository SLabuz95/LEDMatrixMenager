#ifndef PICTURESLISTELEMENT_HPP
#define PICTURESLISTELEMENT_HPP

// _INCLUDES_ PicturesListElement.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QCheckBox>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"DataBase/databaseobject.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ PicturesListElement.hpp --------------------------------------------------------------------------------------------------------------------------------------
class PicturesList;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ PicturesListElement -----------------------------------------------------------------------------------------------------------------------------------------------
class PicturesListElement : public QWidget{
public:
    // _CONSTRUCTORS_ PicturesListElement.hpp
    PicturesListElement(PicturesList* mainListParent, DataBaseObject*& refObj, PicturesListElement* refListParent = nullptr);

    // _DESTRUCTORS_ PicturesListElement.hpp
    virtual ~PicturesListElement();

protected:
    // _PRIVATE_MEMBERS_ PicturesListElement.hpp
    PicturesList* mainListParent = nullptr;
    PicturesListElement* parent = nullptr;
    DataBaseObject* refObj = nullptr;
    uint curHeight = 0;
    bool reallocationFlag = false;

    QLineEdit titleLE;
    QCheckBox checkBox;

public:
    // _PUBLIC_MEMBERS_ PicturesListElement.hpp

protected:
    // _PRIVATE_METHODS_ PicturesListElement.hpp
    virtual void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();
    virtual void generateText();
    virtual void clearElements(){}
    virtual void load(){}
    virtual inline void addNewDbObj(DataBaseObject* dbObj){

    }

    // On Action Functions
    virtual bool onPressedEvent(){}
    virtual bool onReleasedEvent(){}

    virtual void createContextMenu(QAction* actions);
    virtual void execContextMenu(QPoint& eventPos);

public:
    // _PUBLIC_METHODS_ PicturesListElement.hpp
    GET_DECLARATION(PicturesList*, mainListParent)
    GET_DECLARATION(PicturesListElement*, parent)
    GET_SET_DECLARATION(DataBaseObject*, refObj)
    GET_DECLARATION(uint, curHeight)
    GET_DECLARATION(QLineEdit&, titleLE)
    GET_SET_DECLARATION(bool, reallocationFlag)

    virtual void reload(){}
    bool editModeCheckName(QKeyEvent *ev);
    virtual void reallocateElements(PicturesListElement*&);
    void resizeEvent(QResizeEvent*);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);

     PicturesListElement* allowUpdate(){setUpdatesEnabled(true); return this;}
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // PICTURESLISTELEMENT_HPP
