#ifndef LEDMATRIXPICTUREELEMENTPARAMETERS_HPP
#define LEDMATRIXPICTUREELEMENTPARAMETERS_HPP

#include"../SharedCode/GeneralPurposeMacros/filemenegmentmacros.hpp"

// _LED_MATRIX_PICTURE_ELEMENT_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define LED_MATRIX_PICTURE_ELEMENT_X_PARAM_NAME ("x")
#define LED_MATRIX_PICTURE_ELEMENT_Y_PARAM_NAME ("y")
#define LED_MATRIX_PICTURE_ELEMENT_ROTATION_PARAM_NAME ("rotation")
#define LED_MATRIX_PICTURE_ELEMENT_TYPE_PARAM_NAME ("elemType")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <LEDMatrixPictureElementParameters Enum Name>_PARAM_NAME
// Example:For LED_MATRIX_PICTURE_ELEMENT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_NAME_PARAM_NAME
//
// ------------------------------------------

#define LEDMatrixPictureElement_PARAM_ID_REQUIRED (false)

// _LED_MATRIX_PICTURE_ELEMENT_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define LED_MATRIX_PICTURE_ELEMENT_X_PARAM_NAME_LENGTH (PARAM_LENGTH_1)
#define LED_MATRIX_PICTURE_ELEMENT_Y_PARAM_NAME_LENGTH (PARAM_LENGTH_1)
#define LED_MATRIX_PICTURE_ELEMENT_ROTATION_PARAM_NAME_LENGTH (PARAM_LENGTH_8)
#define LED_MATRIX_PICTURE_ELEMENT_TYPE_PARAM_NAME_LENGTH (PARAM_LENGTH_8)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <LEDMatrixPictureElementParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For LED_MATRIX_PICTURE_ELEMENT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _LED_MATRIX_PICTURE_ELEMENT_PARAM_OPTIONALITY_MACROS_
#define LED_MATRIX_PICTURE_ELEMENT_X_PARAM_OPTIONALITY (false)
#define LED_MATRIX_PICTURE_ELEMENT_Y_PARAM_OPTIONALITY (false)
#define LED_MATRIX_PICTURE_ELEMENT_ROTATION_PARAM_OPTIONALITY (true)
#define LED_MATRIX_PICTURE_ELEMENT_TYPE_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <LEDMatrixPictureElementParameters Enum Name>_PARAM_OPTIONALITY
// Example:For LED_MATRIX_PICTURE_ELEMENT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _LED_MATRIX_PICTURE_ELEMENT_PARAM_PARAM_IS_OBJECT_MACROS_
#define LED_MATRIX_PICTURE_ELEMENT_X_PARAM_PARAM_IS_OBJECT (false)
#define LED_MATRIX_PICTURE_ELEMENT_Y_PARAM_PARAM_IS_OBJECT (false)
#define LED_MATRIX_PICTURE_ELEMENT_ROTATION_PARAM_PARAM_IS_OBJECT (false)
#define LED_MATRIX_PICTURE_ELEMENT_TYPE_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <LEDMatrixPictureElementParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For LED_MATRIX_PICTURE_ELEMENT_NAME, type macro LED_MATRIX_PICTURE_ELEMENT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ LEDMatrixPictureElementParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum LEDMatrixPictureElementParameters{    
    LED_MATRIX_PICTURE_ELEMENT_TYPE,    // if not set, any other param cant be set (return false)
    // All List Parameters Below vvvvvvvvvvvvv
    LED_MATRIX_PICTURE_ELEMENT_X,
    LED_MATRIX_PICTURE_ELEMENT_Y,
    LED_MATRIX_PICTURE_ELEMENT_ROTATION,

    NUMB_OF_LED_MATRIX_PICTURE_ELEMENT_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // LEDMATRIXPICTUREELEMENTPARAMETERS_HPP
