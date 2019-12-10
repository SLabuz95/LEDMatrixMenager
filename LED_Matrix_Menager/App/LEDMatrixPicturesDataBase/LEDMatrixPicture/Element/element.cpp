
// _INCLUDES_ LEDMatrixPictureElement.cpp -------------------------------------------------------------------------------------------------------------------
#include"element.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabase.hpp"
#include<QEvent>
#include<QMouseEvent>
#include"Rect/rect.hpp"
#include"Rect/LEDMatrix/ledmatrix.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ LEDMatrixPictureElement -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool LEDMatrixPictureElement::optionality[];
constexpr bool LEDMatrixPictureElement::paramIsObject[];
uint LEDMatrixPictureElement::numbOfElements = 0;

// _CONSTRUCTORS_ LEDMatrixPictureElement.cpp
LEDMatrixPictureElement::LEDMatrixPictureElement() : LEDMatrixPictureElement(static_cast<uint>(0)){
    //QPen outlinePen(Qt::black);
    //outlinePen.setWidth(2);
    //addRect(0, 0, 80, 100, outlinePen);
    //setSceneRect(QRect(QPoint(-100, 100), QPoint(100, -100)));
}

LEDMatrixPictureElement::LEDMatrixPictureElement(uint numbOfParams) : DataBaseObject(static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE_ELEMENT)),numbOfParams + NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_PARAMETERS){
    SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), UINT_MAX, SET_PARAM_ACTION_ADD};
    QString name = QString("Element") + QString::number(++numbOfElements);
    setParam(name, spr);
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_X))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_Y))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_TYPE))) = true;
    if(curItem())
    curItem()->setAcceptHoverEvents(true);
}

LEDMatrixPictureElement::LEDMatrixPictureElement(DataBaseObject* obj) : DataBaseObject(*obj, static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE_ELEMENT)), NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_PARAMETERS){
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_X))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_Y))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_TYPE))) = true;
    if(curItem())
    curItem()->setAcceptHoverEvents(true);
}

LEDMatrixPictureElement::LEDMatrixPictureElement(DataBaseObject* obj, uint numbOfParams) : DataBaseObject(*obj, static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE_ELEMENT)),numbOfParams + NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_PARAMETERS){
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_X))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_Y))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_TYPE))) = true;
    if(curItem())
    curItem()->setAcceptHoverEvents(true);
}

// _DESTRUCTORS_ LEDMatrixPictureElement.cpp
LEDMatrixPictureElement::~LEDMatrixPictureElement(){
    //SET_PTR_DO(dataBaseGeneralInformation, nullptr);
    //ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);
}

// _PRIVATE_METHODS_ LEDMatrixPictureElement.cpp


// _PUBLIC_METHODS_ LEDMatrixPictureElement.cpp
const QString LEDMatrixPictureElement::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, LEDMatrixPictureElement, DataBaseObject);
    switch(static_cast<LEDMatrixPictureElementParameters>(param)){
    case LED_MATRIX_PICTURE_ELEMENT_X:
        return DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_X);
    case LED_MATRIX_PICTURE_ELEMENT_Y:
        return DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_Y);
    case LED_MATRIX_PICTURE_ELEMENT_ROTATION:
        return DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_ROTATION);
    case LED_MATRIX_PICTURE_ELEMENT_TYPE:
        return DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_TYPE);
    default:
        return QString();
    }
}

QString LEDMatrixPictureElement::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,LEDMatrixPictureElement, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_QSTRING(LEDMatrixPictureElement);
    if(getElementType() == LED_MATRIX_PICTURE_ELEMENT_NO_TYPE)
        return QString();
    switch (static_cast<LEDMatrixPictureElementParameters>(paramRules.param)) {
    case LED_MATRIX_PICTURE_ELEMENT_X:
        return QString::number(curItem()->x());
    case LED_MATRIX_PICTURE_ELEMENT_Y:
        return QString::number(curItem()->y());
    case LED_MATRIX_PICTURE_ELEMENT_TYPE:
        return QString::number(getElementType());
    case LED_MATRIX_PICTURE_ELEMENT_ROTATION:
        return QString::number(curItem()->rotation());
    default:
        return QString();
    }
}

bool LEDMatrixPictureElement::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, LEDMatrixPictureElement, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_BOOL(LEDMatrixPictureElement);    
    if(getElementType() == LED_MATRIX_PICTURE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<LEDMatrixPictureElementParameters>(paramRules.param)) {
    case LED_MATRIX_PICTURE_ELEMENT_X:
    {
        *static_cast<qreal*>(value) = curItem()->x();
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_Y:
    {
        *static_cast<qreal*>(value) = curItem()->y();
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_ROTATION:
    {
        *static_cast<qreal*>(value) = curItem()->rotation();
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_TYPE:
    {
        *static_cast<uint*>(value) = getElementType();
    }
        break;
    default:
        return false;
    }
    return true;
}

bool LEDMatrixPictureElement::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,LEDMatrixPictureElement, DataBaseObject);
    bool ret = false;
    bool setParamId = false;
    if(getElementType() == LED_MATRIX_PICTURE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<LEDMatrixPictureElementParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    case LED_MATRIX_PICTURE_ELEMENT_X:
    {

         curItem()->setX(*static_cast<qreal*>(value));
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_Y:
    {
        ret = true;
         curItem()->setY(*static_cast<qreal*>(value));
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_ROTATION:
    {
        ret = true;
        curItem()->setRotation(*static_cast<qreal*>(value));
    }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureElement);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureElement);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(LEDMatrixPictureElement);
    return true;
}

bool LEDMatrixPictureElement::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,LEDMatrixPictureElement, DataBaseObject);
    bool ret = false;
    if(getElementType() == LED_MATRIX_PICTURE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<LEDMatrixPictureElementParameters>(paramRules.param)) {
    case LED_MATRIX_PICTURE_ELEMENT_X:
    {
        ret = true;
         curItem()->setX(static_cast<qreal>(str.toDouble()));
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_Y:
    {
        ret = true;
         curItem()->setY(static_cast<qreal>(str.toDouble()));
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_ROTATION:
    {
        ret = true;
        curItem()->setRotation(static_cast<qreal>(str.toDouble()));
    }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureElement);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureElement);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool LEDMatrixPictureElement::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, LEDMatrixPictureElement, DataBaseObject);
    bool ret = false;
    if(getElementType() == LED_MATRIX_PICTURE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<LEDMatrixPictureElementParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat LEDMatrixPictureElement::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // LED_MATRIX_PICTURE_ELEMENT = object
    case PARAM_LENGTH_1:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_X), PARAM_LENGTH_1){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_X, value, dbObjectParamRules);
        }
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_Y), PARAM_LENGTH_1){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_Y, value, dbObjectParamRules);
        }
    }
        break;
    case PARAM_LENGTH_8:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_TYPE), PARAM_LENGTH_8){
            return DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE;
        }
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_ROTATION), PARAM_LENGTH_8){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(LEDMatrixPictureElement, LED_MATRIX_PICTURE_ELEMENT_ROTATION, value, dbObjectParamRules);
        }
    }
        break;
    default:
        break;
    }
    return DataBaseObject::checkParamAndProccess(param, value, dbObjectParamRules);
}


DataBaseObject* LEDMatrixPictureElement::createObject(uint newType){
    DataBaseObject* newObj = nullptr;
    switch(newType){
    case LED_MATRIX_PICTURE_ELEMENT_TYPE_RECT:
        newObj = new LEDMatrixPictureElementRect(this);
        break;
    case LED_MATRIX_PICTURE_ELEMENT_TYPE_LED_MATRIX:
        newObj = new LEDMatrixPictureElementLEDMatrix(this);
        break;
    }
    return newObj;
}
