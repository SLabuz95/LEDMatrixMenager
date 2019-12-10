#ifndef PAINTTOOLS_HPP
#define PAINTTOOLS_HPP
#include<QToolBar>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

#define PAINT_TOOLS_OPTION_ICON_ACCESS(enumName) enumName##_ICON

#define PAINT_TOOLS_OPTION_RECT_ICON (QIcon("Icons/paintToolRect.png"))
#define PAINT_TOOLS_OPTION_LED_MATRIX_ICON (QIcon("Icons/paintToolLEDMatrix.png"))

enum PaintToolsOptions{
    PAINT_TOOLS_OPTION_LED_MATRIX,
    PAINT_TOOLS_OPTION_RECT,
    NUMB_OF_PAINT_TOOLS_OPTIONS
};

class PaintPanel;
class PaintTools : public QToolBar{
    Q_OBJECT
public:
    PaintTools(PaintPanel*);
    ~PaintTools();

private:
    PaintPanel* parent = nullptr;

    QAction paintToolsOptions[NUMB_OF_PAINT_TOOLS_OPTIONS];

    void init();

public:
    GET_DECLARATION(PaintPanel*, parent)

    void actionRun(PaintToolsOptions option);
    void reloadToolBar();
    bool eventFilter(QObject*, QEvent*);    

public slots:
    void addLedMatrix();
    void addRect();
};

#endif // PAINTTOOLS_HPP
