#ifndef LEDMATRIXPICTUREDATABASE_HPP
#define LEDMATRIXPICTUREDATABASE_HPP

#include"DataBase/database.hpp"
#include"ledmatrixpicturedatabaseparameters.hpp"
#include"ledmatrixpicturedatabasetypes.hpp"

class DataBaseObject;
class LEDMatrixPictureDataBase : public DataBase{
public:
    LEDMatrixPictureDataBase();
    virtual ~LEDMatrixPictureDataBase() override;

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
    DB_OBJECT_STANDARD_METHODS(LEDMatrixPictureDataBase, DataBase, LEDMatrixPictureDataBaseParameters, NUMB_OF_LED_MATRIX_PICTURE_DATA_BASE_PARAMETERS, NUMB_OF_DATABASE_PARAMETERS , LEDMatrixPictureDataBaseTypes, NUMB_OF_LED_MATRIX_PICTURE_DATA_BASE_TYPES, NUMB_OF_DATABASE_CATEGORY_TYPES)

    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    //virtual DataBaseObject* createObject()override{return nullptr;}
    virtual DataBaseObject* createObject(DataBaseObject* obj, uint newType) override;

};

#endif // LEDMATRIXPICTUREDATABASE_HPP
