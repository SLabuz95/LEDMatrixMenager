
// _INCLUDES_ LEDMatrixPicture.cpp -------------------------------------------------------------------------------------------------------------------
#include"ledmatrixpicture.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabase.hpp"
#include"Element/element.hpp"
#include<QEvent>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include<App/AppWindow/PaintPanel/paintpanel.hpp>
#include<QDebug>
#include"EventChangeMode/eventchangemode.hpp"
#include"Element/Rect/LEDMatrix/ledmatrix.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ LEDMatrixPicture -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool LEDMatrixPicture::optionality[];
constexpr bool LEDMatrixPicture::paramIsObject[];


// _CONSTRUCTORS_ LEDMatrixPicture.cpp
LEDMatrixPicture::LEDMatrixPicture() : LEDMatrixPicture(static_cast<uint>(0)){

}

LEDMatrixPicture::LEDMatrixPicture(uint numbOfParams) : DataBaseObject(static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE)), numbOfParams + NUMB_OF_LED_MATRIX_PICTURE_PARAMETERS), QGraphicsScene(){
    //setSceneRect(QRectF(QPoint(-1000,-1000), QSize(2000, 2000)));
    //sceneRectItem.setRect(sceneRect());
    //addItem(&sceneRectItem);
    //qDebug() << "Bounding Rect";
    //qDebug() << tempItemsBoundingRect;
    installEventFilter(this);
}

LEDMatrixPicture::LEDMatrixPicture(DataBaseObject* obj) : DataBaseObject(*obj, static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE)), NUMB_OF_LED_MATRIX_PICTURE_PARAMETERS), QGraphicsScene(){
    //setSceneRect(QRectF(QPoint(-1000,-1000), QSize(2000, 2000)));
    //sceneRectItem.setRect(sceneRect());
   // qDebug() << "Bounding Rect";
    //qDebug() << tempItemsBoundingRect;
    //addItem(&sceneRectItem);
    installEventFilter(this);
}

// _DESTRUCTORS_ LEDMatrixPicture.cpp
LEDMatrixPicture::~LEDMatrixPicture(){
    //SET_PTR_DO(dataBaseGeneralInformation, nullptr);
    SET_PTR_DO(curMode, nullptr);
    //ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);
}

// _PRIVATE_METHODS_ LEDMatrixPicture.cpp


// _PUBLIC_METHODS_ LEDMatrixPicture.cpp

GET_DEFINITION(LEDMatrixPicture, QRectF, tempItemsBoundingRect)

bool LEDMatrixPicture::get_changedFlag(){
    return changedFlag && !(changedFlag = false);
}

const QString LEDMatrixPicture::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, LEDMatrixPicture, DataBaseObject);
    switch(static_cast<LEDMatrixPictureParameters>(param)){
    default:
        return QString();
    }
}

QString LEDMatrixPicture::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,LEDMatrixPicture, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_QSTRING(LEDMatrixPicture);
    switch (static_cast<LEDMatrixPictureParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool LEDMatrixPicture::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, LEDMatrixPicture, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_BOOL(LEDMatrixPicture);
    switch (static_cast<LEDMatrixPictureParameters>(paramRules.param)) {
    case LED_MATRIX_PICTURE_ELEMENTS:
    {
        if(paramRules.index < numbOfElements)
        {
            if(paramRules.index + 1 < numbOfElements)
                paramRules.nextAvailable = true;
            *static_cast<LEDMatrixPictureElement**>(value) = (*(elements + paramRules.index));
        }else{
            return false;
        }
    }
        break;
    default:
        return false;
    }
    return true;
}

bool LEDMatrixPicture::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,LEDMatrixPicture, DataBaseObject);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<LEDMatrixPictureParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    case LED_MATRIX_PICTURE_ELEMENTS:
    {
        switch(paramRules.action){
        case SET_PARAM_ACTION_ADD:
        {
            setParamId = true;
            if(numbOfElements == UINT_MAX || (*static_cast<DataBaseObject**>(value))->getObjectType() != DB_GET_REAL_TYPE(LEDMatrixPictureDataBase, LED_MATRIX_PICTURE_ELEMENT) || (*static_cast<LEDMatrixPictureElement**>(value))->getElementType() == LED_MATRIX_PICTURE_ELEMENT_NO_TYPE)
            {}
            else{
                if(!(ret = addElement(*static_cast<LEDMatrixPictureElement**>(value)))){
                    return  false;
                }
                addItem((*static_cast<LEDMatrixPictureElement**>(value))->curItem());
                tempItemsBoundingRect = itemsBoundingRect();
                //qDebug() << "Bounding Rect";
                //qDebug() << tempItemsBoundingRect;
                ret = true;
            }
        }
            break;
        case SET_PARAM_ACTION_REMOVE:
        {
            if(removeElement(*static_cast<LEDMatrixPictureElement**>(value))){
                ret = true;
            }

        }
            break;
        default:
            return false;
        }
    }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPicture);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPicture);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    if(ret) changedFlag = true;
    DB_SET_PARAM_ID(LEDMatrixPicture);
    return true;
}

bool LEDMatrixPicture::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,LEDMatrixPicture, DataBaseObject);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, LEDMatrixPicture);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, LEDMatrixPicture);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool LEDMatrixPicture::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, LEDMatrixPicture, DataBaseObject);
    bool ret = false;
    switch (static_cast<LEDMatrixPictureParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat LEDMatrixPicture::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // LED_MATRIX_PICTURE_ELEMENT = object
    default:
        break;
    }
    return DataBaseObject::checkParamAndProccess(param, value, dbObjectParamRules);
}

void LEDMatrixPicture::activateMode(LEDMatrixPictureModeType type, uint phase){
    deactivateCurMode();
    SET_PTR_NDO(curMode, new LEDMatrixPictureMode{type});
    // Init Sequance
    switch(type){
    case LED_MATRIX_PICTURE_MODE_DRAW_RECT:
    {

    }
        break;
    case LED_MATRIX_PICTURE_MODE_ADD_LED_MATRIX_PANEL:
    {   // Current Size 64x64  - Item
        // Track Mouse Move to Redraw Matrix Position
        for(int i = 0; i < views().size(); i++){
            views().at(i)->setMouseTracking(true);
        }
        curMode->tempElement = new LEDMatrixPictureElementLEDMatrix();
        //qDebug() << "Scene Active MOde";
        //qDebug() << this;
        SetParamRules spr = {DB_GET_REAL_PARAM(LEDMatrixPicture, LED_MATRIX_PICTURE_ELEMENTS), UINT_MAX, SET_PARAM_ACTION_ADD};
        if(!setParam(&(curMode->tempElement), spr)){
            SET_PTR_DO(curMode->tempElement, nullptr);
            deactivateCurMode();
        }
    }
        break;
    }
}

void LEDMatrixPicture::deactivateCurMode(){
    // DeInit Sequance
    if(curMode){
        switch(curMode->type){
        case LED_MATRIX_PICTURE_MODE_DRAW_RECT:
        {

        }
            break;
        case LED_MATRIX_PICTURE_MODE_ADD_LED_MATRIX_PANEL:
        {
            for(int i = 0; i < views().size(); i++){
                views().at(i)->setMouseTracking(false);
            }
            if(curMode->tempElement){
                SetParamRules spr = {DB_GET_REAL_PARAM(LEDMatrixPicture, LED_MATRIX_PICTURE_ELEMENTS), UINT_MAX, SET_PARAM_ACTION_REMOVE};
                if(!setParam(&(curMode->tempElement), spr)){
                    SET_PTR_DO(curMode->tempElement, nullptr);
                    // Internal Error
                }
            }
        }
            break;
        }
    }
    // --------------
    SET_PTR_DO(curMode, nullptr);

    changedFlag = true;
}

bool LEDMatrixPicture::eventFilter(QObject *obj, QEvent *ev){    
    // Process Cur Mode Events
    if(ev->type() == LEDMatrixPictureEventChangeMode::LEDMatrixPictureChangeMode)
        activateMode(static_cast<LEDMatrixPictureEventChangeMode*>(ev)->get_newModeType(), static_cast<LEDMatrixPictureEventChangeMode*>(ev)->get_phase());
    if(curMode){
        switch (curMode->type) {

        case LED_MATRIX_PICTURE_MODE_ADD_LED_MATRIX_PANEL:
        {   // SINGLE PHASE MODE
            switch(ev->type()){
            case QEvent::GraphicsSceneMouseMove:
            {
                curMode->tempElement->curItem()->setPos(static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
            }
            break;
            case QEvent::Enter:
            {
                if(obj == this){
                    curMode->tempElement->curItem()->show();
                }
            }
                break;
            case QEvent::Leave:
            {
                if(obj == this){
                    curMode->tempElement->curItem()->hide();
                }
            }
                break;
            case QEvent::GraphicsSceneMouseRelease:
            {
                if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() == Qt::LeftButton)
                {
                    curMode->tempElement->curItem()->setPos(static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
                    // TEST of Getting
                    GetParamRules gpr = {DB_GET_REAL_PARAM(LEDMatrixPicture, LED_MATRIX_PICTURE_ELEMENTS), 0};
                    if(!getParam(&(curMode->tempElement), gpr)){
                        qDebug() << "Fail";
                    }
                    curMode->tempElement->curItem()->setPos(curMode->tempElement->curItem()->pos() + QPoint(0, 5));
                    //

                    curMode->tempElement = nullptr;
                    deactivateCurMode();
                }else if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() == Qt::RightButton){
                    deactivateCurMode();
                }

            }
            break;
            }
        }
            break;
        }
    }else{
        switch(ev->type()){
        case QEvent::GraphicsSceneMousePress:
        {

        }
            break;        
        }
    }
    return QGraphicsScene::eventFilter(obj, ev);
}


