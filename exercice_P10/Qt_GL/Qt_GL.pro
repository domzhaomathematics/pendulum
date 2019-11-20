QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = exercice_P10_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    glsphere.cc \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    glsphere.h \
    ../general/Dessinable.h \
    ../general/SupportADessin.h \
    ../general/Systeme.h \
    ../general/Vecteur.h \
    ../general/constantes.h \
    ../general/Oscillateur.h \
    ../general/Pendule.h \
    ../general/Ressort.h \
    ../general/OscillateurDouble.h \
    ../general/DeuxRessorts.h \
    ../general/PenduleRessort.h \
    ../general/EspacePhase.h \
    ../general/ChariotPenduleRessort.h \
    ../general/PenduleTorsion.h \
    ../general/PendulesRelierRessort.h \
    ../general/IntegrateurEuler.h \
    ../general/IntegrateurRK.h \
    ../general/Integrateur.h


RESOURCES += \
    resource.qrc
