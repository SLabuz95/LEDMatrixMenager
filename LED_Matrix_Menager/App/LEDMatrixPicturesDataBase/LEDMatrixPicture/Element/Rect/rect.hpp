#ifndef LEDMATRIXPICTUREELEMENTRECT_HPP
#define LEDMATRIXPICTUREELEMENTRECT_HPP

#include<QGraphicsRectItem>
#include"../element.hpp"
#include"rectparams.hpp"

class LEDMatrixPictureElementRect : public LEDMatrixPictureElement, public QGraphicsRectItem{
public:
    LEDMatrixPictureElementRect();
    LEDMatrixPictureElementRect(uint numbOfParams);
    LEDMatrixPictureElementRect(DataBaseObject* obj);
    LEDMatrixPictureElementRect(DataBaseObject* obj, uint numbOfParams);
    virtual ~LEDMatrixPictureElementRect() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT)
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT)
    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(LEDMatrixPictureElementRect, LEDMatrixPictureElement, LEDMatrixPictureElementRectParameters, NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_RECT_PARAMETERS, NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual  LEDMatrixPictureElementTypes getElementType() const override {return LED_MATRIX_PICTURE_ELEMENT_TYPE_RECT;}

    virtual QGraphicsItem* curItem()override{return this;}
};


#endif // LEDMATRIXPICTUREELEMENTRECT_HPP
