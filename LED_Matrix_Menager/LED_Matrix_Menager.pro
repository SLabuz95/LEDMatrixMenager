QT += core widgets
TEMPLATE = app
TARGET = LEDMatrixMenager
VERSION_PE_HEADER = 1.0

#INCLUDEPATH += ../../../../Praca_dyplomowa/Informatyka_2019_20

# Temporary Include Path to Experimental Version of DataBase and Objects of DataBase
INCLUDEPATH += ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode

CFLAGS += -Wnoextra-semi-stmt

HEADERS += \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/database.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasecategory.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasecategoryparameters.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasecategorytype.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databaseobject.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databaseobjectparameters.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databaseobjectsreadfilecontainer.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databaseobjecttype.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databaseparams.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasesearchengine.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasesearchengineenums.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasesearchenginefilter.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasesearchenginefiltererror.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/getparamrules.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/setparamrules.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBaseMenager/databasemenager.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBaseMenager/databasemenagerparameters.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBaseMenager/databasereader.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBaseMenager/databasewriter.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialog.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialogquestion.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialogresultenum.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialogtypeenum.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialogyesnoquestion.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Enum/DataBaseFiles/databaseerror.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Enum/DataBaseFiles/databasefileoperationstat.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Enum/FilesMenegment/filereaderror.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Enum/FilesMenegment/filereadingstat.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Enum/UnderUseObject/underuseobjecttypes.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/ExpandButton/expandbutton.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/FileableObject/fileableobject.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/GeneralPurposeMacros/databasemenegmentmacros.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/GeneralPurposeMacros/filemenegmentmacros.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/GeneralPurposeMacros/layoutmacros.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/GeneralPurposeMacros/memorymenegementmacros.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/GeneralPurposeMacros/programcontrolmenegment.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/GeneralPurposeMacros/standardclassdefinitions.hpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/UnderUseObject/underuseobject.hpp \
    App/AppWindow/ComponentListPanel/componentlist.hpp \
    App/AppWindow/ComponentListPanel/componentlistelement.hpp \
    App/AppWindow/ComponentListPanel/componentlistelementlist.hpp \
    App/AppWindow/ComponentListPanel/componentlistpanel.hpp \
    App/AppWindow/ControlPanel/controlpanel.hpp \
    App/AppWindow/MenuBar/menubar.hpp \
    App/AppWindow/PaintPanel/PaintArea/paintarea.hpp \
    App/AppWindow/PaintPanel/PaintTools/painttools.hpp \
    App/AppWindow/PaintPanel/paintpanel.hpp \
    App/AppWindow/PicturesListPanel/pictureslist.hpp \
    App/AppWindow/PicturesListPanel/pictureslistelement.hpp \
    App/AppWindow/PicturesListPanel/pictureslistelementlist.hpp \
    App/AppWindow/PicturesListPanel/pictureslistpanel.hpp \
    App/AppWindow/ToolBar/toolbar.hpp \
    App/AppWindow/appwindow.hpp \
    App/AppWindow/appwindowlayoutmacros.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/BasicConfig/ledmatrixpicturebasicconfig.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/BasicConfig/ledmatrixpicturebasicconfigparameters.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/Rect/LEDMatrix/ledmatrix.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/Rect/LEDMatrix/ledmatrixparams.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/Rect/rect.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/Rect/rectparams.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/element.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/elementparams.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/elementtypes.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/EventChangeMode/eventchangemode.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/PictureMode/ledmatrixpicturemode.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/ledmatrixpicture.hpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/ledmatrixpictureparameters.hpp \
    App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabase.hpp \
    App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabaseparameters.hpp \
    App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabasetypes.hpp \
    App/app.hpp

SOURCES += \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/database.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasecategory.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databaseobject.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databaseobjectsreadfilecontainer.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasesearchengine.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBase/databasesearchenginefilter.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBaseMenager/databasemenager.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBaseMenager/databasereader.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/DataBaseMenager/databasewriter.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialog.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialogquestion.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/Dialog/dialogyesnoquestion.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/ExpandButton/expandbutton.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/FileableObject/fileableobject.cpp \
    ../../../../Praca_dyplomowa/Informatyka_2019_20/EXPERIMENTAL/SharedCode/UnderUseObject/underuseobject.cpp \
    App/AppWindow/ComponentListPanel/componentlist.cpp \
    App/AppWindow/ComponentListPanel/componentlistelement.cpp \
    App/AppWindow/ComponentListPanel/componentlistelementlist.cpp \
    App/AppWindow/ComponentListPanel/componentlistpanel.cpp \
    App/AppWindow/ControlPanel/controlpanel.cpp \
    App/AppWindow/MenuBar/menubar.cpp \
    App/AppWindow/PaintPanel/PaintArea/paintarea.cpp \
    App/AppWindow/PaintPanel/PaintTools/painttools.cpp \
    App/AppWindow/PaintPanel/paintpanel.cpp \
    App/AppWindow/PicturesListPanel/pictureslist.cpp \
    App/AppWindow/PicturesListPanel/pictureslistelement.cpp \
    App/AppWindow/PicturesListPanel/pictureslistelementlist.cpp \
    App/AppWindow/PicturesListPanel/pictureslistpanel.cpp \
    App/AppWindow/ToolBar/toolbar.cpp \
    App/AppWindow/appwindow.cpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/Rect/LEDMatrix/ledmatrix.cpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/Rect/rect.cpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/Element/element.cpp \
    App/LEDMatrixPicturesDataBase/LEDMatrixPicture/ledmatrixpicture.cpp \
    App/LEDMatrixPicturesDataBase/ledmatrixpicturedatabase.cpp \
    App/app.cpp \
    main.cpp

