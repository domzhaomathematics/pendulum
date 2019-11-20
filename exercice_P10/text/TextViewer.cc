#include <cmath>
#include <sstream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
#include "Ressort.h"
#include "Pendule.h"
#include "OscillateurDouble.h"
#include "EspacePhase.h"
#include "PenduleRessort.h"
#include "PenduleTorsion.h"
#include "ChariotPenduleRessort.h"
#include "TextViewer.h"
#include "Systeme.h"
#include <iostream>
using namespace std;


//constructeur et destructeur
TextViewer::TextViewer(std::ostream& f)
: SupportADessin(), flot(f)
{}
TextViewer::~TextViewer()
{}

//Methodes (redefinie)
void TextViewer::dessine(const Oscillateur&) { }
 void TextViewer::dessine(const Pendule& p ) 
{
	 Pendule p1(p);
	 flot << "un pendule" << endl;
	 cout << p1;
 }
 void TextViewer::dessine(const Ressort& r)
 {
	 Ressort r1(r);
	 flot << "un Ressort" << endl;
	 cout << r1;
 }

 
 void TextViewer::dessine(const Systeme& s ) //polymorphism, make it use the good method
 {
	 for (size_t i(0); i<(s.Collection()).size(); i++)
	 {
		(s.Collection()[i])->dessine();
	 }
 }

 void TextViewer::dessine(const OscillateurDouble& od)
 {
	 flot << "Un pendule double:" << endl;
	 cout << "La premiere masse du Pendule double :" << endl;
	 cout << " Position (angle1):" << (od.Parametre().Composantes()[0]) << endl;
	 cout << "Vitesse:" << (od.Vitesse().Composantes()[0]) << endl << endl;
	 cout << "La deuxieme masse du Pendule double: " << endl;
	 cout << " Position(angle 2):" << (od.Parametre().Composantes()[1]) << endl;
	 cout << "Vitesse:" << (od.Vitesse().Composantes()[1]) << endl << endl;

 
 
 }

 void TextViewer::dessine(EspacePhase const& e)
 {
     /*for (size_t i(0); i < e.Espace().size(); i++)
     {
         cout << e.Espace()[i][0] << ", "<< e.Espace()[i][1] <<endl;
     }*/
     cout << e.Espace()[e.Espace().size()-1][0] << ", " << e.Espace()[e.Espace().size()-1][1] << endl;
 }

 void TextViewer::dessine(PenduleTorsion const& e) {}
 void TextViewer::dessine(ChariotPenduleRessort const& e) {}
 void TextViewer::dessine(PenduleRessort const& e) {}
 void TextViewer::dessine(DeuxRessorts const& e) {}
 void TextViewer::dessine(PendulesRelierRessort const& e) {}
