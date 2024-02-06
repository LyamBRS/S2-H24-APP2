TEMPLATE     = vcapp
TARGET       = testGraphicusGUI
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h 
SOURCES     += testGraphicusGUI.cpp monInterface.cpp
HEADERS     += monInterface.h \
../GraphicusSources/Canevas.h \
../GraphicusSources/Carre.h \
../GraphicusSources/Cercle.h \
../GraphicusSources/Coordonnee.h \
../GraphicusSources/Couche.h \
../GraphicusSources/forme.h \
../GraphicusSources/Rectangle.h \
../GraphicusSources/resultatCouleur.h \
../GraphicusSources/tests.h \
../GraphicusSources/Vecteur.h 

SOURCES     += testGraphicusGUI.cpp monInterface.cpp \
../GraphicusSources/Canevas.cpp \
../GraphicusSources/Carre.cpp \
../GraphicusSources/Cercle.cpp \
../GraphicusSources/Couche.cpp \
../GraphicusSources/forme.cpp \
../GraphicusSources/Rectangle.cpp \
../GraphicusSources/resultatCouleur.cpp \
../GraphicusSources/tests.cpp \
../GraphicusSources/Vecteur.cpp 
INCLUDEPATH += ../GraphicusGUI
LIBS        += ../GraphicusGUI/graphicusGUI.lib
QT          += widgets
