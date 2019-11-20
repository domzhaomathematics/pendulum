CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

CXXFLAGS += -pedantic -Wall         # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                   # pour profiler
# LDFLAGS  += -pg                   # pour profiler
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all:: testVecteur testOscillateur testIntegrateur testPendule testRessort exerciceP9

Vecteur.o: Vecteur.h Vecteur.cc 

testVecteur.o: testVecteur.cc Vecteur.h

testVecteur: Vecteur.o  testVecteur.o 


constantes.o: constantes.cc constantes.h Vecteur.h


Oscillateur.o: Oscillateur.cc Vecteur.h Oscillateur.h SupportADessin.h Dessinable.h

testOscillateur.o: testOscillateur.cc Vecteur.h Oscillateur.h  SupportADessin.h Dessinable.h

testOscillateur: testOscillateur.o Vecteur.o Oscillateur.o 

Integrateur.o: Integrateur.cc Integrateur.h Vecteur.h Oscillateur.h

IntegrateurRK.o: IntegrateurRK.cc IntegrateurRK.h Integrateur.h Vecteur.h Oscillateur.h

Newmark.o: Newmark.cc Newmark.h Integrateur.h Vecteur.h Oscillateur.h

IntegrateurEuler.o: IntegrateurEuler.cc IntegrateurEuler.h Integrateur.h Vecteur.h Oscillateur.h


testIntegrateur.o: testIntegrateur.cc Integrateur.h Vecteur.h Oscillateur.h IntegrateurEuler.h IntegrateurRK.h Newmark.h

testIntegrateur: testIntegrateur.o Integrateur.o Vecteur.o Oscillateur.o IntegrateurEuler.o IntegrateurRK.o Newmark.o


Pendule.o: Pendule.cc constantes.h Vecteur.h Oscillateur.h Integrateur.h IntegrateurRK.h IntegrateurEuler.h Newmark.h Pendule.h SupportADessin.h Dessinable.h

testPendule.o: testPendule.cc constantes.h Vecteur.h Oscillateur.h Integrateur.h Pendule.h SupportADessin.h Dessinable.h Integrateur.h IntegrateurRK.h IntegrateurEuler.h

testPendule: testPendule.o Vecteur.o Oscillateur.o Integrateur.o Pendule.o constantes.o Integrateur.o IntegrateurRK.o IntegrateurEuler.o


Ressort.o: Ressort.cc constantes.h Vecteur.h Oscillateur.h Dessinable.h SupportADessin.h Ressort.h Integrateur.h IntegrateurRK.h IntegrateurEuler.h

testRessort.o: testRessort.cc constantes.h Ressort.h Vecteur.h Oscillateur.h Ressort.h Integrateur.h Integrateur.h IntegrateurRK.h IntegrateurEuler.h

testRessort: testRessort.o Vecteur.o Oscillateur.o Ressort.o Integrateur.o constantes.o Integrateur.o IntegrateurRK.o IntegrateurEuler.o



