#ifndef APPWINDOWLAYOUTMACROS_HPP
#define APPWINDOWLAYOUTMACROS_HPP


#include"../SharedCode/GeneralPurposeMacros/layoutmacros.hpp"

// Default App Window Geometry

#define LO_APP_WINDOW_X (10)
#define LO_APP_WINDOW_Y (10)
#define LO_APP_WINDOW_WIDTH (640)
#define LO_APP_WINDOW_HEIGHT (480)

#define LO_APP_WINDOW_POS LO_APP_WINDOW_X, LO_APP_WINDOW_Y
#define LO_APP_WINDOW_SIZE LO_APP_WINDOW_WIDTH, LO_APP_WINDOW_HEIGHT
#define LO_APP_WINDOW_GEOMETRY LO_APP_WINDOW_POS, LO_APP_WINDOW_SIZE

// Menu Bar
#define LO_MENU_BAR_X (LAYOUT_CURRENT_LEFT)
#define LO_MENU_BAR_Y (LAYOUT_CURRENT_TOP)
#define LO_MENU_BAR_WIDTH (LAYOUT_CURRENT_WIDTH)
#define LO_MENU_BAR_HEIGHT (20)

#define LO_MENU_BAR_POS LO_MENU_BAR_X, LO_MENU_BAR_Y
#define LO_MENU_BAR_SIZE LO_MENU_BAR_WIDTH, LO_MENU_BAR_HEIGHT
#define LO_MENU_BAR_GEOMETRY LO_MENU_BAR_POS, LO_MENU_BAR_SIZE

// Tool Bar
#define LO_TOOL_BAR_X (LAYOUT_CURRENT_LEFT)
#define LO_TOOL_BAR_Y (LO_MENU_BAR_HEIGHT)
#define LO_TOOL_BAR_WIDTH (LAYOUT_CURRENT_WIDTH)
#define LO_TOOL_BAR_HEIGHT (20)

#define LO_TOOL_BAR_POS LO_TOOL_BAR_X, LO_TOOL_BAR_Y
#define LO_TOOL_BAR_SIZE LO_TOOL_BAR_WIDTH, LO_TOOL_BAR_HEIGHT
#define LO_TOOL_BAR_GEOMETRY LO_TOOL_BAR_POS, LO_TOOL_BAR_SIZE

// Default DataBaseViewer Geometry
#define LO_DATABASE_VIEWER_X (LAYOUT_CURRENT_LEFT)
#define LO_DATABASE_VIEWER_Y(win) (LAYOUT_WINDOW_BOTTOM(win))
#define LO_DATABASE_VIEWER_WIDTH (LAYOUT_CURRENT_WIDTH * 0.33)
#define LO_DATABASE_VIEWER_HEIGHT (LAYOUT_REST_OF_HEIGHT(LAYOUT_CURRENT_HEIGHT, LO_MENU_BAR_HEIGHT + LO_TABBAR_HEIGHT + LO_STATUS_BAR_HEIGHT))

#define LO_DATABASE_VIEWER_POS LO_DATABASE_VIEWER_X, LO_DATABASE_VIEWER_Y
#define LO_DATABASE_VIEWER_SIZE LO_DATABASE_VIEWER_WIDTH, LO_DATABASE_VIEWER_HEIGHT
#define LO_DATABASE_VIEWER_GEOMETRY LO_DATABASE_VIEWER_POS, LO_DATABASE_VIEWER_SIZE

// DataBaseViewer List Geometry
#define LO_DATABASE_VIEWER_LIST_SCROLL_BAR_WIDTH (5)

#define LO_DATABASE_VIEWER_LIST_X (LAYOUT_CURRENT_LEFT)
#define LO_DATABASE_VIEWER_LIST_Y (LAYOUT_CURRENT_TOP)
#define LO_DATABASE_VIEWER_LIST_WIDTH (LAYOUT_REST_OF_WIDTH(LAYOUT_CURRENT_WIDTH, LO_DATABASE_VIEWER_LIST_SCROLL_BAR_WIDTH))
#define LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight) (curHeight)

#define LO_DATABASE_VIEWER_LIST_POS LO_DATABASE_VIEWER_LIST_X, LO_DATABASE_VIEWER_LIST_Y
#define LO_DATABASE_VIEWER_LIST_SIZE(curHeight) LO_DATABASE_VIEWER_LIST_WIDTH, LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight)
#define LO_DATABASE_VIEWER_LIST_GEOMETRY(curHeight) LO_DATABASE_VIEWER_LIST_POS, LO_DATABASE_VIEWER_LIST_SIZE(curHeight)

// DataBaseViewerElement Geometry -------------------------------------------
#define LO_DATABASE_VIEWER_LIST_BORDER_WIDTH (2)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT (20)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_WIDTH (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET (5)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_LEVEL_HORIZONTAL_OFFSET (10)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_X (LAYOUT_POS_RIGHT_OF(LAYOUT_CURRENT_LEFT, level * LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_LEVEL_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_Y(curY) (curY)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_WIDTH (LAYOUT_REST_OF_WIDTH(LAYOUT_CURRENT_WIDTH, level * LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_LEVEL_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_DEFAULT_HEIGHT (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT )
#define LO_DATABASE_VIEWER_LIST_ELEMENT_HEIGHT(curHeight) (curHeight)
// ELEMENTS ---------------------------------------
// Check Box
#define LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_X (LAYOUT_POS_RIGHT_OF(LAYOUT_CURRENT_LEFT , LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_Y (LAYOUT_CURRENT_TOP)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_WIDTH (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_WIDTH)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_HEIGHT (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_POS LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_X, LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_Y
#define LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_SIZE LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_HEIGHT
#define LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_GEOMETRY LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_POS, LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_SIZE

// Text Label
#define LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_X (LAYOUT_POS_RIGHT_OF(LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_X + LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_Y (LAYOUT_CURRENT_TOP)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_WIDTH (LAYOUT_REST_OF_WIDTH(LAYOUT_CURRENT_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_WIDTH + 3 * LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_HEIGHT (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_POS LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_X, LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_Y
#define LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_SIZE LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_HEIGHT
#define LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_GEOMETRY LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_POS, LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_SIZE

// --------------------------------------------------------------------

#define LO_DATABASE_VIEWER_LIST_ELEMENT_POS(curY) LO_DATABASE_VIEWER_LIST_ELEMENT_X, LO_DATABASE_VIEWER_LIST_ELEMENT_Y(curY)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight) LO_DATABASE_VIEWER_LIST_ELEMENT_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_HEIGHT(curHeight)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curY, curHeight) LO_DATABASE_VIEWER_LIST_ELEMENT_POS(curY), LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight)
// -----------------------------------------------------------------------------
// Elements of DataBaseViewerListElementList
// Expand Button
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_X (LAYOUT_POS_RIGHT_OF(LAYOUT_CURRENT_LEFT , LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_Y (LAYOUT_CURRENT_TOP)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_WIDTH (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_WIDTH)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_HEIGHT (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_POS LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_X, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_Y
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_SIZE LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_HEIGHT
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_GEOMETRY LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_POS, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_SIZE

// Check Box
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_X (LAYOUT_POS_RIGHT_OF(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_X + LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_Y (LAYOUT_CURRENT_TOP)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_WIDTH (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_WIDTH)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_HEIGHT (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_POS LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_X, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_Y
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_SIZE LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_HEIGHT
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_GEOMETRY LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_POS, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_SIZE

// Text Label
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_X (LAYOUT_POS_RIGHT_OF(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_X + LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_Y (LAYOUT_CURRENT_TOP)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_WIDTH (LAYOUT_REST_OF_WIDTH(LAYOUT_CURRENT_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_WIDTH + LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_WIDTH + 4 * LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_HORIZONTAL_OFFSET))
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_HEIGHT (LO_DATABASE_VIEWER_LIST_ELEMENT_ELEMENTS_DEFAULT_HEIGHT)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_POS LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_X, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_Y
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_SIZE LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_HEIGHT
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_GEOMETRY LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_POS, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_SIZE

// --------------------------------------------------------------------

#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_POS(curY) LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_X, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_Y(curY)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_SIZE(curHeight) LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_HEIGHT(curHeight)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_GEOMETRY(curY, curHeight) LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_POS(curY), LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_SIZE(curHeight)

#define LO_DATABASE_VIEWER_LIST_ELEMENT_POS(curY) LO_DATABASE_VIEWER_LIST_ELEMENT_X, LO_DATABASE_VIEWER_LIST_ELEMENT_Y(curY)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight) LO_DATABASE_VIEWER_LIST_ELEMENT_WIDTH, LO_DATABASE_VIEWER_LIST_ELEMENT_HEIGHT(curHeight)
#define LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curY, curHeight) LO_DATABASE_VIEWER_LIST_ELEMENT_POS(curY), LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight)
// -----------------------------------------------------------------------------

// DataBaseViewerElementList --------------------------------------

#define LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_X (LAYOUT_CURRENT_LEFT)
#define LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_Y(curHeight) (curHeight)
#define LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_WIDTH (LO_DATABASE_VIEWER_LIST_ELEMENT_WIDTH)
#define LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT (LO_DATABASE_VIEWER_LIST_ELEMENT_DEFAULT_HEIGHT)

#define LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_POS LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_X, LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_Y
#define LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_SIZE LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_WIDTH, LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT
#define LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_GEOMETRY LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_POS, LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_SIZE
// -----------------------------------------------------------------------------

// Paint Panel ------------------------------------------------------ (Depends of QSplitter section size)
// Elements---------------------------------------------------------------------------

// PaintTools
#define LO_PAINT_TOOLS_X (LAYOUT_CURRENT_LEFT)
#define LO_PAINT_TOOLS_Y (LAYOUT_CURRENT_TOP)
#define LO_PAINT_TOOLS_WIDTH (20)
#define LO_PAINT_TOOLS_HEIGHT (LAYOUT_CURRENT_HEIGHT)

#define LO_PAINT_TOOLS_POS LO_PAINT_TOOLS_X, LO_PAINT_TOOLS_Y
#define LO_PAINT_TOOLS_SIZE LO_PAINT_TOOLS_WIDTH, LO_PAINT_TOOLS_HEIGHT
#define LO_PAINT_TOOLS_GEOMETRY LO_PAINT_TOOLS_POS, LO_PAINT_TOOLS_SIZE

// PaintArea
#define LO_PAINT_AREA_X (LO_PAINT_TOOLS_WIDTH)
#define LO_PAINT_AREA_Y (LAYOUT_CURRENT_TOP)
#define LO_PAINT_AREA_WIDTH (LAYOUT_REST_OF_WIDTH(LAYOUT_CURRENT_WIDTH, LO_PAINT_TOOLS_WIDTH))
#define LO_PAINT_AREA_HEIGHT (LAYOUT_CURRENT_HEIGHT)

#define LO_PAINT_AREA_POS LO_PAINT_AREA_X, LO_PAINT_AREA_Y
#define LO_PAINT_AREA_SIZE LO_PAINT_AREA_WIDTH, LO_PAINT_AREA_HEIGHT
#define LO_PAINT_AREA_GEOMETRY LO_PAINT_AREA_POS, LO_PAINT_AREA_SIZE


// -------------------------------------------------------------------

//---------------------------------------------------------------------------


#endif // APPWINDOWLAYOUTMACROS_HPP