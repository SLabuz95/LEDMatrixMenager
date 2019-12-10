#include"painttools.hpp"
#include<QMouseEvent>
#include<QMenu>
#include"../paintpanel.hpp"
#include"App/LEDMatrixPicturesDataBase/LEDMatrixPicture/EventChangeMode/eventchangemode.hpp"
#include<QApplication>

PaintTools::PaintTools(PaintPanel* parent) : QToolBar (parent), parent(parent){
    init();
}

PaintTools::~PaintTools(){

}

void PaintTools::init(){
    setOrientation(Qt::Vertical);
    for(uint i = 0; i < NUMB_OF_PAINT_TOOLS_OPTIONS; i++){
        QAction* tempAction = paintToolsOptions + i;
        tempAction->setIcon(PAINT_TOOLS_OPTION_ICON_ACCESS(PAINT_TOOLS_OPTION_RECT));
        tempAction->setParent(this);
        addAction(tempAction);
    }
    connect(paintToolsOptions, SIGNAL(triggered()), this, SLOT(addLedMatrix()));
    connect(paintToolsOptions + 1, SIGNAL(triggered()), this, SLOT(addRect()));
}

void PaintTools::actionRun(PaintToolsOptions option){
    switch(option){
    case PAINT_TOOLS_OPTION_LED_MATRIX:
    {
        LEDMatrixPictureEventChangeMode changeModeEv(LED_MATRIX_PICTURE_MODE_ADD_LED_MATRIX_PANEL);
        QApplication::sendEvent(&parent->get_paintArea(), &changeModeEv);
    }
        break;
    case PAINT_TOOLS_OPTION_RECT:
    {
        //parent->parent->readNewScript();
    }
        break;
    default:
        break;
    }
}

bool PaintTools::eventFilter(QObject *obj, QEvent *ev){
    switch(ev->type()){
    case QEvent::MouseButtonRelease:
    {
        if(obj == this){
            QAction* activeted = actionAt(static_cast<QMouseEvent*>(ev)->pos());
            if(activeted){
                uint i = 0;
                for( ; i < NUMB_OF_PAINT_TOOLS_OPTIONS; i++)
                    if(paintToolsOptions + i == activeted)
                        break;
                if(i == NUMB_OF_PAINT_TOOLS_OPTIONS)
                    break;
                actionRun(static_cast<PaintToolsOptions>(i));
            }
        }
    }
        break;
    default:
        break;
    }
    return QToolBar::eventFilter(obj, ev);
}

void PaintTools::addLedMatrix(){
    LEDMatrixPictureEventChangeMode changeModeEv(LED_MATRIX_PICTURE_MODE_ADD_LED_MATRIX_PANEL);
    QApplication::sendEvent(&parent->get_paintArea(), &changeModeEv);
}

void PaintTools::addRect(){

}
