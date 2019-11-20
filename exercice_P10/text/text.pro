CONFIG += c++11

TARGET = exercice_P10_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    exerciceP9.cpp \
    TextViewer.cc

HEADERS += \
    ../general/Systeme.h \
    TextViewer.h \
    ../general/Vecteur.h \
    ../general/constantes.h \
    ../general/Oscillateur.h \
    ../general/Pendule.h \
    ../general/Ressort.h \
    ../general/Integrateur.h \
    ../general/Dessinable.h \
    ../general/OscillateurDouble.h \
    ../general/DeuxRessorts.h \
    ../general/PenduleRessort.h \
    ../general/EspacePhase.h \
    ../general/ChariotPenduleRessort.h \
    ../general/PenduleTorsion.h \
    ../general/PendulesRelierRessort.h \
    ../general/IntegrateurEuler.h \
    ../general/IntegrateurRK.h \
    ../general/SupportADessin.h
