
// _INCLUDES_ LEDMatrixPictureElementRect.cpp -------------------------------------------------------------------------------------------------------------------
#include"rect.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ LEDMatrixPictureElementRect -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool LEDMatrixPictureElementRect::optionality[];
constexpr bool LEDMatrixPictureElementRect::paramIsObject[];

// _CONSTRUCTORS_ LEDMatrixPictureElementRect.cpp
LEDMatrixPictureElementRect::LEDMatrixPictureElementRect() : LEDMatrixPictureElementRect(static_cast<uint>(0)){}

LEDMatrixPictureElementRect::LEDMatrixPictureElementRect(uint numbOfParams) : LEDMatrixPictureElement(numbOfParams + NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_RECT_PARAMETERS){
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElementRect, LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(LEDMatrixPictureElementRect, LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT))) = true;

}


LEDMatrixPictureElementRect::LEDMatrixPictureElementRect(DataBaseObject* obj) : LEDMatrixPictureElementRect(obj, 0){}

LEDMatrixPictureElementRect::LEDMatrixPictureElementRect(DataBaseObject* obj, uint numbOfParams) : LEDMatrixPictureElement(obj,numbOfParams + NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_RECT_PARAMETERS){

}

// _DESTRUCTORS_ LEDMatrixPictureElementRect.cpp
LEDMatrixPictureElementRect::~LEDMatrixPictureElementRect(){

}

// _PRIVATE_METHODS_ LEDMatrixPictureElementRect.cpp


// _PUBLIC_METHODS_ LEDMatrixPictureElementRect.cpp
const QString LEDMatrixPictureElementRect::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, LEDMatrixPictureElementRect, LEDMatrixPictureElement);
    switch(static_cast<LEDMatrixPictureElementRectParameters>(param)){
    DB_GET_PARAM_NAME(LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH);
    DB_GET_PARAM_NAME(LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT);
    default:
        return QString();
    }
}

QString LEDMatrixPictureElementRect::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,LEDMatrixPictureElementRect, LEDMatrixPictureElement);
    DB_OBJECT_IS_INITIALIZED_QSTRING(LEDMatrixPictureElementRect);
    switch (static_cast<LEDMatrixPictureElementRectParameters>(paramRules.param)) {
    case LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH:
        return QString::number(rect().width());
    case LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT:
        return QString::number(rect().height());
    default:
        return QString();
    }
}

bool LEDMatrixPictureElementRect::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, LEDMatrixPictureElementRect, LEDMatrixPictureElement);
    DB_OBJECT_IS_INITIALIZED_BOOL(LEDMatrixPictureElementRect);
    switch (static_cast<LEDMatrixPictureElementRectParameters>(paramRules.param)) {
    case LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH:
    {
        *static_cast<qreal*>(value) = rect().width();
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT:
    {
        *static_cast<qreal*>(value) = rect().height();
    }
        break;
    default:
        return false;
    }
    return true;
}

bool LEDMatrixPictureElementRect::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,LEDMatrixPictureElementRect, LEDMatrixPictureElement);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<LEDMatrixPictureElementRectParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    case LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH:
    {
        ret = true;
        setRect(QRectF(pos(), QSizeF(*static_cast<qreal*>(value), rect().height())));
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT:
    {
        ret = true;
        setRect(QRectF(pos(), QSizeF(rect().width(), *static_cast<qreal*>(value))));
    }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureElementRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureElementRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(LEDMatrixPictureElementRect);
    return true;
}

bool LEDMatrixPictureElementRect::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,LEDMatrixPictureElementRect, LEDMatrixPictureElement);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureElementRectParameters>(paramRules.param)) {
    case LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH:
    {
        ret = true;
        setRect(QRectF(pos(), QSizeF(str.toDouble(), rect().height())));
    }
        break;
    case LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT:
    {
        ret = true;
        setRect(QRectF(pos(), QSizeF(rect().width(), str.toDouble())));
    }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureElementRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureElementRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool LEDMatrixPictureElementRect::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, LEDMatrixPictureElementRect, LEDMatrixPictureElement);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureElementRectParameters>(rules.param)) {

    default:
        return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat LEDMatrixPictureElementRect::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    case PARAM_LENGTH_5:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH), PARAM_LENGTH_5){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(LEDMatrixPictureElementRect, LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH, value, dbObjectParamRules);
        }
    }
        break;
    case PARAM_LENGTH_6:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT), PARAM_LENGTH_6){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(LEDMatrixPictureElementRect, LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT, value, dbObjectParamRules);
        }
    }
        break;
    default:
        break;
    }
    return LEDMatrixPictureElement::checkParamAndProccess(param, value, dbObjectParamRules);
}



