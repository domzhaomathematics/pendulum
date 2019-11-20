TEMPLATE = lib

CONFIG = staticlib c++11

SOURCES += \
    Vecteur.cc \
    constantes.cc \
    Oscillateur.cc \
    Pendule.cc \
    Ressort.cc \
    OscillateurDouble.cc \
    Integrateur.cc \
    IntegrateurEuler.cc \
    IntegrateurRK.cc \
    Newmark.cc \
    DeuxRessorts.cc \
    PenduleRessort.cc \
    EspacePhase.cc \
    ChariotPenduleRessort.cc \
    PenduleTorsion.cc \
    PendulesRelierRessort.cc \
    Systeme.cc

HEADERS += \
    Vecteur.h \
    constantes.h \
    Oscillateur.h \
    Pendule.h \
    Ressort.h \
    Integrateur.h \
    IntegrateurEuler.h \
    IntegrateurRK.h \
    Newmark.h \
    OscillateurDouble.h \
    Systeme.h \
    Dessinable.h \
    DeuxRessorts.h \
    PenduleRessort.h \
    EspacePhase.h \
    ChariotPenduleRessort.h \
    PenduleTorsion.h \
    PendulesRelierRessort.h \
    SupportADessin.h
