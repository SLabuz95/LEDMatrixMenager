#ifndef LEDMATRIXPICTUREELEMENTLEDMATRIX_HPP
#define LEDMATRIXPICTUREELEMENTLEDMATRIX_HPP

#include"../rect.hpp"
#include"ledmatrixparams.hpp"

class LEDMatrixPictureElementLEDMatrix : public LEDMatrixPictureElementRect{
public:
    LEDMatrixPictureElementLEDMatrix();
    LEDMatrixPictureElementLEDMatrix(uint numbOfParams);
    LEDMatrixPictureElementLEDMatrix(DataBaseObject* obj);
    LEDMatrixPictureElementLEDMatrix(DataBaseObject* obj, uint numbOfParams);
    virtual ~LEDMatrixPictureElementLEDMatrix() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {

    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {

    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(LEDMatrixPictureElementLEDMatrix, LEDMatrixPictureElementRect, LEDMatrixPictureElementLEDMatrixParameters, NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_LED_MATRIX_PARAMETERS, NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_RECT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual  LEDMatrixPictureElementTypes getElementType() const override {return LED_MATRIX_PICTURE_ELEMENT_TYPE_LED_MATRIX;}

};


#endif // LEDMATRIXPICTUREELEMENTLEDMATRIX_HPP
