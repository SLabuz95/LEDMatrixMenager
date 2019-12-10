#ifndef PICTURESLISTPANEL_HPP
#define PICTURESLISTPANEL_HPP


#include<QScrollArea>
#include"pictureslist.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class AppWindow;
class LEDMatrixPictureDataBase;
class DataBaseObject;
class PicturesListPanel : public QScrollArea{
public:
    PicturesListPanel(AppWindow* parent);
    ~PicturesListPanel();

protected:
    AppWindow* parent = nullptr;
    PicturesList list;

    public:
        // _PUBLIC_MEMBERS_ DataBaseViewer.hpp

    protected:
        // _PRIVATE_METHODS_ DataBaseViewer.hpp
        void initalize();
        virtual void createObjects();
        virtual void createLayout();
        virtual void connectEvents();
        virtual void clearMemory();

        void createContextMenu(QAction* actions);
        void execContextMenu(QPoint& eventPos);

    public:
        // _PUBLIC_METHODS_ DataBaseViewer.hpp
        GET_DECLARATION(AppWindow*, parent)
        GET_DECLARATION(PicturesList&, list)

        void reload(){list.reload();}

        void clear();
        bool clearAndLoad(LEDMatrixPictureDataBase*);
        bool load(LEDMatrixPictureDataBase*);
        //bool clearAndLoadDbObj(DataBaseObject*);
        //bool loadDbObj(DataBaseObject*);

        inline void addNewDbObj(LEDMatrixPictureDataBase* dbObj){
            if(dbObj){
                list.addNewDbObject(dbObj);
            }
        }

        virtual PicturesListElement* createElement(DataBaseObject*, PicturesListElement*);
        virtual PicturesListElement* createElement(DataBaseObject*, PicturesListElement*, uint);

        //inline bool addElement(PicturesListElement* newElem){
        //    return list.addElement(newElem);
        //}

        //inline bool removeElement(PicturesListElement* remElem){
        //    return list.removeElement(remElem);
        //}

        void resizeEvent(QResizeEvent* ev);
        void paintEvent(QPaintEvent* ev);
        bool eventFilter(QObject* obj, QEvent* ev);

};


#endif // PICTURESLISTPANEL_HPP
