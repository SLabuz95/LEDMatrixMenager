#ifndef PICTURESLIST_HPP
#define PICTURESLIST_HPP

// _INCLUDES_ PicturesList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ PicturesList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class PicturesListPanel;
class PicturesListElement;
class LEDMatrixPictureDataBase;
class DataBaseObject;
class QLineEdit;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ PicturesList -----------------------------------------------------------------------------------------------------------------------------------------------
class PicturesList : public QWidget{
public:
    // _CONSTRUCTORS_ PicturesList.hpp
    PicturesList(PicturesListPanel* parent);

    // _DESTRUCTORS_ PicturesList.hpp
    ~PicturesList();

private:
    // _PRIVATE_MEMBERS_ PicturesList.hpp
    PicturesListPanel* parent = nullptr;
    PicturesListElement** elements = nullptr;
    uint numbOfElements = 0;
    PicturesListElement* currentElement = nullptr;

    PicturesListElement* elementAtEditMode = nullptr;
    bool newNameAccepted = false;

    bool newObjectFlag = false;

    bool reallocationFlag = false;
public:
    // _PUBLIC_MEMBERS_ PicturesList.hpp

private:
    // _PRIVATE_METHODS_ PicturesList.hpp
    void initalize();
    void createObjects();
    void createLayout();
    void connectEvents();
    void clearMemory();
public:
    // _PUBLIC_METHODS_ PicturesList.hpp
    GET_DECLARATION(PicturesListPanel*, parent)
    GET_DECLARATION(PicturesListElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(PicturesListElement*, currentElement)
    GET_DECLARATION(PicturesListElement*, elementAtEditMode)
    GET_SET_DECLARATION(bool, newNameAccepted)
    GET_SET_DECLARATION(bool, newObjectFlag)

    DataBaseObject* get_currentElementRefObj();
    void reload();
    bool addElement(PicturesListElement* newElem);
    bool removeElement(PicturesListElement* remElem);
    void clearElements();
    bool load(LEDMatrixPictureDataBase*);
    bool loadDBObject(LEDMatrixPictureDataBase*);
    void reallocateElements(PicturesListElement*&);   // Caller (Reallocate from caller, if caller == nullptr, from first element)

    void addNewDbObject(LEDMatrixPictureDataBase* dbObj){
        newObjectFlag = true;
        loadDBObject(dbObj);
    }
    void selectElement(PicturesListElement* ele){currentElement = ele; repaint();}
    void putElementAtEditMode(PicturesListElement* ele);
    void editModeAccept();
    void editModeCancel();
    void paintEvent(QPaintEvent* ev);
    void resizeEvent(QResizeEvent* ev);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // PICTURESLIST_HPP
