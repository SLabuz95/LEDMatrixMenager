
// _INCLUDES_ LEDMatrixPictureElementLEDMatrix.cpp -------------------------------------------------------------------------------------------------------------------
#include"ledmatrix.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
#include<QPen>
#include<QBrush>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ LEDMatrixPictureElementLEDMatrix -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool LEDMatrixPictureElementLEDMatrix::optionality[];
constexpr bool LEDMatrixPictureElementLEDMatrix::paramIsObject[];

// _CONSTRUCTORS_ LEDMatrixPictureElementLEDMatrix.cpp
LEDMatrixPictureElementLEDMatrix::LEDMatrixPictureElementLEDMatrix() : LEDMatrixPictureElementLEDMatrix(static_cast<uint>(0)){}

LEDMatrixPictureElementLEDMatrix::LEDMatrixPictureElementLEDMatrix(uint numbOfParams) : LEDMatrixPictureElementRect(numbOfParams + NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_LED_MATRIX_PARAMETERS){
    setRect(QRectF(pos(), QSize(64, 64)));
    QColor color(Qt::blue);
    color.setAlpha(127);
    setPen(QPen(color));
    setBrush(QBrush(color));
    setFlag(QGraphicsItem::ItemIsMovable);
    hide();
}


LEDMatrixPictureElementLEDMatrix::LEDMatrixPictureElementLEDMatrix(DataBaseObject* obj) : LEDMatrixPictureElementLEDMatrix(obj, 0){}

LEDMatrixPictureElementLEDMatrix::LEDMatrixPictureElementLEDMatrix(DataBaseObject* obj, uint numbOfParams) : LEDMatrixPictureElementRect(obj,numbOfParams + NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_LED_MATRIX_PARAMETERS){
    setRect(QRectF(pos(), QSize(64, 64)));
    QColor color(Qt::blue);
    color.setAlpha(127);
    setPen(QPen(color));
    setBrush(QBrush(color));
    setFlag(QGraphicsItem::ItemIsMovable);

}

// _DESTRUCTORS_ LEDMatrixPictureElementLEDMatrix.cpp
LEDMatrixPictureElementLEDMatrix::~LEDMatrixPictureElementLEDMatrix(){

}

// _PRIVATE_METHODS_ LEDMatrixPictureElementLEDMatrix.cpp


// _PUBLIC_METHODS_ LEDMatrixPictureElementLEDMatrix.cpp
const QString LEDMatrixPictureElementLEDMatrix::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, LEDMatrixPictureElementLEDMatrix, LEDMatrixPictureElementRect);
    switch(static_cast<LEDMatrixPictureElementLEDMatrixParameters>(param)){
    default:
        return QString();
    }
}

QString LEDMatrixPictureElementLEDMatrix::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,LEDMatrixPictureElementLEDMatrix, LEDMatrixPictureElementRect);
    DB_OBJECT_IS_INITIALIZED_QSTRING(LEDMatrixPictureElementLEDMatrix);
    switch (static_cast<LEDMatrixPictureElementLEDMatrixParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool LEDMatrixPictureElementLEDMatrix::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, LEDMatrixPictureElementLEDMatrix, LEDMatrixPictureElementRect);
    DB_OBJECT_IS_INITIALIZED_BOOL(LEDMatrixPictureElementLEDMatrix);
    switch (static_cast<LEDMatrixPictureElementLEDMatrixParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool LEDMatrixPictureElementLEDMatrix::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,LEDMatrixPictureElementLEDMatrix, LEDMatrixPictureElementRect);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<LEDMatrixPictureElementLEDMatrixParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureElementLEDMatrix);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureElementLEDMatrix);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(LEDMatrixPictureElementLEDMatrix);
    return true;
}

bool LEDMatrixPictureElementLEDMatrix::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,LEDMatrixPictureElementLEDMatrix, LEDMatrixPictureElementRect);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureElementLEDMatrixParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPictureElementLEDMatrix);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPictureElementLEDMatrix);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool LEDMatrixPictureElementLEDMatrix::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, LEDMatrixPictureElementLEDMatrix, LEDMatrixPictureElementRect);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureElementLEDMatrixParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat LEDMatrixPictureElementLEDMatrix::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // LED_MATRIX_PICTURE_ELEMENT = object
    default:
        break;
    }
    return LEDMatrixPictureElementRect::checkParamAndProccess(param, value, dbObjectParamRules);
}



