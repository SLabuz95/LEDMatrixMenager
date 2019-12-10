#ifndef PICTURESLISTELEMENTLIST_HPP
#define PICTURESLISTELEMENTLIST_HPP

// _INCLUDES_ PicturesListElementList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"pictureslistelement.hpp"
#include"../SharedCode/ExpandButton/expandbutton.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ PicturesListElementList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class PicturesList;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ PicturesListElementList -----------------------------------------------------------------------------------------------------------------------------------------------
class PicturesListElementList : public PicturesListElement{
public:
    // _CONSTRUCTORS_ PicturesListElementList.hpp
    PicturesListElementList(PicturesList* mainListParent,  DataBaseObject* refObj,PicturesListElement* refListParent = nullptr);
    // _DESTRUCTORS_ PicturesListElementList.hpp
    virtual ~PicturesListElementList() override;

protected:
    // _PRIVATE_MEMBERS_ PicturesListElementList.hpp
    PicturesListElement** elements = nullptr;
    uint numbOfElements = 0;

    ExpandButton expandButton;
public:
    // _PUBLIC_MEMBERS_ PicturesListElementList.hpp

protected:
    // _PRIVATE_METHODS_ PicturesListElementList.hpp
    void createObjects()override;
    void createLayout()override;
    void connectEvents()override{expandButton.installEventFilter(this);}
    void clearMemory()override;
    void generateText()override;
    void reallocateElements(PicturesListElement*&)override;
    void clearElements()override{}
    void load()override;
    virtual inline void addNewDbObj(DataBaseObject* dbObj) override;
    // On Action Functions
    bool onPressedEvent()override{}
    bool onReleasedEvent()override{}

    void createContextMenu(QAction* actions) override;
    void execContextMenu(QPoint& eventPos) override;

public:
    // _PUBLIC_METHODS_ PicturesListElementList.hpp
    GET_DECLARATION(PicturesListElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(uint, level)


    bool addElement(PicturesListElement*);    // Dont reallocate
    bool removeElement(PicturesListElement*); // Dont reallocate
    bool addListElement(PicturesListElement* newObj);
    bool removeListElement(PicturesListElement*);

    virtual void reload()override;
    void resizeEvent(QResizeEvent* ev)override;
    bool eventFilter(QObject* obj, QEvent* ev)override;
    void paintEvent(QPaintEvent* ev)override;
};


// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // PICTURESLISTELEMENTLIST_HPP
