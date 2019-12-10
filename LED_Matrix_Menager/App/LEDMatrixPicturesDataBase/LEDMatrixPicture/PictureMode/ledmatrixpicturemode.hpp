#ifndef LEDMATRIXPICTUREMODE_HPP
#define LEDMATRIXPICTUREMODE_HPP

#include<QObject>

class LEDMatrixPictureElement;

enum LEDMatrixPictureModeType{
    LED_MATRIX_PICTURE_MODE_ADD_LED_MATRIX_PANEL,
    LED_MATRIX_PICTURE_MODE_DRAW_RECT,
    LED_MATRIX_PICTURE_MODE_SCENE_MOVE,
    NUMB_OF_LED_MATRIX_PICTURE_MODE_TYPES
};

enum LEDMatrixPictureModeDrawRectPhase{
    LED_MATRIX_PICTURE_MODE_DRAW_RECT_PHASE_START_POINT,
    LED_MATRIX_PICTURE_MODE_DRAW_RECT_PHASE_END_POINT
};

struct LEDMatrixPictureMode{
    LEDMatrixPictureModeType type = NUMB_OF_LED_MATRIX_PICTURE_MODE_TYPES;
    uint phase = 0;
    LEDMatrixPictureElement* tempElement = nullptr;
};


#endif // LEDMATRIXPICTUREMODE_HPP
