#ifndef LEDMATRIXPICTURE_HPP
#define LEDMATRIXPICTURE_HPP

#include"DataBase/databaseobject.hpp"
#include<QGraphicsScene>
#include"ledmatrixpictureparameters.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"PictureMode/ledmatrixpicturemode.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QGraphicsRectItem>

class LEDMatrixPictureElement;
class LEDMatrixPicture : public DataBaseObject, public QGraphicsScene{
public:
    LEDMatrixPicture();
    LEDMatrixPicture(uint);
    LEDMatrixPicture(DataBaseObject* obj);
    virtual ~LEDMatrixPicture() override;

protected:
    // Items Bounding Rect (Dynamic by Scene Change)
    QRectF tempItemsBoundingRect;

    QRectF lastViewRect;

    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(LED_MATRIX_PICTURE_ELEMENTS)
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(LED_MATRIX_PICTURE_ELEMENTS)

    };
    // LED Matrix Picture Basic Config
    //LEDMatrixPictureBasicConfig *basicConfig = nullptr;

    // LED Matrix Picture Elements
    LEDMatrixPictureElement **elements = nullptr;
    uint numbOfElements = 0;

    // For Scene Mode
    LEDMatrixPictureMode* curMode = nullptr;

    QPointF lastMPos;

    // Changed Flag
    bool changedFlag = false;

public:
    GET_DECLARATION(bool, changedFlag)
    GET_DECLARATION(QRectF, tempItemsBoundingRect)

    DB_OBJECT_STANDARD_METHODS_NO_TYPES(LEDMatrixPicture, DataBaseObject, LEDMatrixPictureParameters, NUMB_OF_LED_MATRIX_PICTURE_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    void activateMode(LEDMatrixPictureModeType type, uint phase);
    void deactivateCurMode();

    bool eventFilter(QObject *obj, QEvent *ev) override;

    bool addElement(LEDMatrixPictureElement* newElem){ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(LEDMatrixPictureElement, elements, numbOfElements, newElem);}
    bool removeElement(LEDMatrixPictureElement* remElem){ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(LEDMatrixPictureElement, elements, numbOfElements, remElem);}
    void clearElements(){ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);}

    void setLastViewRect(QRectF rect){lastViewRect = rect;}
    QRectF getLastViewRect(){return lastViewRect.isEmpty()? (lastViewRect = tempItemsBoundingRect) : lastViewRect;}

};


#endif // LEDMATRIXPICTURE_HPP
