#ifndef LEDMATRIXPICTUREELEMENTRECTPARAMETERS_HPP
#define LEDMATRIXPICTUREELEMENTRECTPARAMETERS_HPP

#include"../SharedCode/GeneralPurposeMacros/filemenegmentmacros.hpp"

#define LEDMatrixPictureElementRect_PARAM_ID_REQUIRED (false)

// _LED_MATRIX_PICTURE_ELEMENT_RECT_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH_PARAM_NAME ("width")
#define LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT_PARAM_NAME ("height")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <LEDMatrixPictureElementRectParameters Enum Name>_PARAM_NAME
// Example:For LED_MATRIX_PICTURE_ELEMENT_RECT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_RECT_NAME_PARAM_NAME
//
// ------------------------------------------

// _LED_MATRIX_PICTURE_ELEMENT_RECT_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH_PARAM_NAME_LENGTH (PARAM_LENGTH_5)
#define LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <LEDMatrixPictureElementRectParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For LED_MATRIX_PICTURE_ELEMENT_RECT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_RECT_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _LED_MATRIX_PICTURE_ELEMENT_RECT_PARAM_OPTIONALITY_MACROS_
#define LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH_PARAM_OPTIONALITY (false)
#define LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <LEDMatrixPictureElementRectParameters Enum Name>_PARAM_OPTIONALITY
// Example:For LED_MATRIX_PICTURE_ELEMENT_RECT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_RECT_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _LED_MATRIX_PICTURE_ELEMENT_RECT_PARAM_PARAM_IS_OBJECT_MACROS_
#define LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH_PARAM_PARAM_IS_OBJECT (false)
#define LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <LEDMatrixPictureElementRectParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For LED_MATRIX_PICTURE_ELEMENT_RECT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_RECT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ LEDMatrixPictureElementRectParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum LEDMatrixPictureElementRectParameters{
    // All List Parameters Below vvvvvvvvvvvvv
    LED_MATRIX_PICTURE_ELEMENT_RECT_WIDTH,
    LED_MATRIX_PICTURE_ELEMENT_RECT_HEIGHT,

    NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_RECT_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------



#endif // LEDMATRIXPICTUREELEMENTRECTPARAMETERS_HPP
