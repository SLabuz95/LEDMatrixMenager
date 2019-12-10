#ifndef LEDMATRIXPICTUREELEMENT_HPP
#define LEDMATRIXPICTUREELEMENT_HPP

#include"DataBase/databaseobject.hpp"
#include"elementparams.hpp"
#include"elementtypes.hpp"
#include<QGraphicsItem>

class LEDMatrixPictureElement : public DataBaseObject{
public:
    LEDMatrixPictureElement();
    LEDMatrixPictureElement(uint numbOfParams);
    LEDMatrixPictureElement(DataBaseObject* obj);
    LEDMatrixPictureElement(DataBaseObject* obj, uint numbOfParams);
    virtual ~LEDMatrixPictureElement() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(LED_MATRIX_PICTURE_ELEMENT_TYPE),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(LED_MATRIX_PICTURE_ELEMENT_X),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(LED_MATRIX_PICTURE_ELEMENT_Y),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(LED_MATRIX_PICTURE_ELEMENT_ROTATION),
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(LED_MATRIX_PICTURE_ELEMENT_TYPE),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(LED_MATRIX_PICTURE_ELEMENT_X),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(LED_MATRIX_PICTURE_ELEMENT_Y),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(LED_MATRIX_PICTURE_ELEMENT_ROTATION),
    };

    static uint numbOfElements;

public:
    DB_OBJECT_STANDARD_METHODS(LEDMatrixPictureElement, DataBaseObject, LEDMatrixPictureElementParameters, NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS, LEDMatrixPictureElementTypes, NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_TYPES, NUMB_OF_DATABASE_OBJECT_TYPES)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override;

    virtual LEDMatrixPictureElementTypes getElementType()const{return LED_MATRIX_PICTURE_ELEMENT_NO_TYPE;}

    virtual QGraphicsItem* curItem(){return nullptr;}

};


#endif // LEDMATRIXPICTUREELEMENT_HPP
