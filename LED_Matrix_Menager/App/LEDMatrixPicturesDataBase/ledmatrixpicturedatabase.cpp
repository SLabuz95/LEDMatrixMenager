
// _INCLUDES_ LEDMatrixPictureDataBase.cpp -------------------------------------------------------------------------------------------------------------------
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"ledmatrixpicturedatabase.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"LEDMatrixPicture/ledmatrixpicture.hpp"
#include"LEDMatrixPicture/Element/element.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ LEDMatrixPictureDataBase -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool LEDMatrixPictureDataBase::optionality[];
constexpr bool LEDMatrixPictureDataBase::paramIsObject[];

// _CONSTRUCTORS_ LEDMatrixPictureDataBase.cpp
LEDMatrixPictureDataBase::LEDMatrixPictureDataBase() : DataBase(){

}

// _DESTRUCTORS_ LEDMatrixPictureDataBase.cpp
LEDMatrixPictureDataBase::~LEDMatrixPictureDataBase(){
    //SET_PTR_DO(dataBaseGeneralInformation, nullptr);

}

// _PRIVATE_METHODS_ LEDMatrixPictureDataBase.cpp


// _PUBLIC_METHODS_ LEDMatrixPictureDataBase.cpp
const QString LEDMatrixPictureDataBase::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, LEDMatrixPictureDataBase, DataBase);
    switch(static_cast<LEDMatrixPictureDataBaseParameters>(param)){
    default:
        return QString();
    }
}

QString LEDMatrixPictureDataBase::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,LEDMatrixPictureDataBase, DataBase);
    DB_OBJECT_IS_INITIALIZED_QSTRING(LEDMatrixPictureDataBase);
    switch (static_cast<LEDMatrixPictureDataBaseParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool LEDMatrixPictureDataBase::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, LEDMatrixPictureDataBase, DataBase);
    DB_OBJECT_IS_INITIALIZED_BOOL(LEDMatrixPictureDataBase);
    switch (static_cast<LEDMatrixPictureDataBaseParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool LEDMatrixPictureDataBase::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,LEDMatrixPictureDataBase, DataBase);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<LEDMatrixPictureDataBaseParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureDataBase);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureDataBase);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(LEDMatrixPictureDataBase);
    return true;
}

bool LEDMatrixPictureDataBase::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,LEDMatrixPictureDataBase, DataBase);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureDataBaseParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureDataBase);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureDataBase);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool LEDMatrixPictureDataBase::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, LEDMatrixPictureDataBase, DataBase);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureDataBaseParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat LEDMatrixPictureDataBase::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {

    default:
        break;
    }
    return DataBase::checkParamAndProccess(param, value, dbObjectParamRules);
}

DataBaseObject* LEDMatrixPictureDataBase::createObject(DataBaseObject *obj, uint newType){
    if(obj == this)
        return this;
    if(obj->getObjectType() != NUMB_OF_DATABASE_OBJECT_TYPES) return nullptr;
    DB_OBJECT_CREATE_OBJECT_CALL_BASE(obj, LEDMatrixPictureDataBase, DataBase);
    switch(static_cast<LEDMatrixPictureDataBaseTypes>(newType)){
    case LED_MATRIX_PICTURE:
        return new LEDMatrixPicture(obj);
    case LED_MATRIX_PICTURE_ELEMENT:
        return new LEDMatrixPictureElement(obj);
    default:
        return nullptr;
    }
}


/*void LEDMatrixPictureDataBase::set_dataBaseGeneralInformation(LEDMatrixPictureDataBaseGeneralInformation* set){dataBaseGeneralInformation = set;}
LEDMatrixPictureDataBaseGeneralInformation* LEDMatrixPictureDataBase::get_dataBaseGeneralInformation(){return dataBaseGeneralInformation;}
//GET_SET_NDO_DEFINITION(LEDMatrixPictureDataBase, LEDMatrixPictureDataBaseGeneralInformation*, dataBaseGeneralInformation)
GET_DEFINITION(LEDMatrixPictureDataBase,DataBase**, dataBaseObjects)
GET_DEFINITION(LEDMatrixPictureDataBase,uint, numbOfDataBases)
GET_DEFINITION(LEDMatrixPictureDataBase,LEDMatrixPictureDataBaseError, error)*/


/*void LEDMatrixPictureDataBase::prepareToRead(){

}*/


// ----------------------------------------------------------------------------------------------------------------------------------------------
