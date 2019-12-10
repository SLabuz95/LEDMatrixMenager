#ifndef LEDMATRIXPICTUREPARAMETERS_HPP
#define LEDMATRIXPICTUREPARAMETERS_HPP

#include"../SharedCode/GeneralPurposeMacros/filemenegmentmacros.hpp"

// _LED_MATRIX_PICTURE_PARAM_NAME_MACROS_ ---------------------------------------------------------
//#define LED_MATRIX_PICTURE_ELEMENTS_PARAM_NAME ("elements")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <LEDMatrixPictureParameters Enum Name>_PARAM_NAME
// Example:For LED_MATRIX_PICTURE_NAME, type macro LED_MATRIX_PICTURE_NAME_PARAM_NAME
//
// ------------------------------------------

#define LEDMatrixPicture_PARAM_ID_REQUIRED (true)

// _LED_MATRIX_PICTURE_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//#define LED_MATRIX_PICTURE_ELEMENTS_PARAM_NAME_LENGTH (PARAM_LENGTH_7)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <LEDMatrixPictureParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For LED_MATRIX_PICTURE_NAME, type macro LED_MATRIX_PICTURE_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _LED_MATRIX_PICTURE_PARAM_OPTIONALITY_MACROS_
#define LED_MATRIX_PICTURE_ELEMENTS_PARAM_OPTIONALITY (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <LEDMatrixPictureParameters Enum Name>_PARAM_OPTIONALITY
// Example:For LED_MATRIX_PICTURE_NAME, type macro LED_MATRIX_PICTURE_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _LED_MATRIX_PICTURE_PARAM_PARAM_IS_OBJECT_MACROS_
#define LED_MATRIX_PICTURE_ELEMENTS_PARAM_PARAM_IS_OBJECT (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <LEDMatrixPictureParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For LED_MATRIX_PICTURE_NAME, type macro LED_MATRIX_PICTURE_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ LEDMatrixPictureParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum LEDMatrixPictureParameters{
    // All List Parameters Below vvvvvvvvvvvvv
    //LED_MATRIX_PICTURE_BASIC_CONFIG,
    LED_MATRIX_PICTURE_ELEMENTS,
    NUMB_OF_LED_MATRIX_PICTURE_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // LEDMATRIXPICTUREPARAMETERS_HPP
