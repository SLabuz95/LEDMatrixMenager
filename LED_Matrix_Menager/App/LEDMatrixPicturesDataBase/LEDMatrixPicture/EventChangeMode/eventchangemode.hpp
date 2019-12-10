#ifndef LEDMATRIXPICTURECHANGEMODE_HPP
#define LEDMATRIXPICTURECHANGEMODE_HPP

#include<QEvent>
#include"App/LEDMatrixPicturesDataBase/LEDMatrixPicture/PictureMode/ledmatrixpicturemode.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class LEDMatrixPictureEventChangeMode : public QEvent{
    public:
    LEDMatrixPictureEventChangeMode(LEDMatrixPictureModeType newModeType, uint phase = 0) : QEvent(LEDMatrixPictureChangeMode), newModeType(newModeType), phase(phase){}
    virtual ~LEDMatrixPictureEventChangeMode()override{}

private:

    LEDMatrixPictureModeType newModeType = NUMB_OF_LED_MATRIX_PICTURE_MODE_TYPES;
    uint phase = 0;

public:
    static const QEvent::Type LEDMatrixPictureChangeMode = static_cast<QEvent::Type>(1000);

    LEDMatrixPictureModeType  get_newModeType() const {return newModeType;}
    uint get_phase(){return phase;}

};

#endif // LEDMATRIXPICTURECHANGEMODE_HPP
