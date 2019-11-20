#include <cmath>
#include <iostream>
#include <sstream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
#include "Ressort.h"
#include "Pendule.h"
#include "OscillateurDouble.h"
#include "TextViewer.h"
#include "Systeme.h"
#include "EspacePhase.h"
#include <cmath>



using namespace std;

int main()
{
	TextViewer sup(cout);
	
	Ressort r1(0.33, 0.25, 0.15, Vecteur(0.8, 0, 0.6), Vecteur(0, 0, 0), &sup, Vecteur(0,0,0), Vecteur(0,0,0));
	r1.Parametre(0.18*r1.A() + r1.O());

	//Les angles et vitesse angulaire
	vector<double> theta = { 3.14 / 2 };
	vector<double> thetaP = {0};
	Pendule p1(0.445, 0.1,10, Vecteur(0, 0, 0), &sup, Vecteur(theta), Vecteur(thetaP));
	//il ne faut pas que le parametre soit comme l'origine
	cout << p1;



	vector<double> parametres = { 3.14 / 2, 0 };
	vector<double> vitesses = { 0,3 };
	OscillateurDouble od(10, 20,10,10, Vecteur(0, 0, 0), &sup, Vecteur(parametres), Vecteur(vitesses));
	
	vector<Oscillateur*> v = { &r1,&p1, &od };
	
	Systeme S(v, &sup);
	cout << *((S.Collection())[0]) << endl;

    r1.dessine();
    S.dessine();
    
    /*double t(0.0);
    while (t <=0.04)
    {
		t +=0.01;
		S.evolue(t, 0.01);
		S.dessine();
    }*/

    EspacePhase E(&r1, &sup);
    E.dessine();

    double t2(0.0);
    while (t2 <=0.04)
    {
        t2 +=0.01;
        E.evolue(t2, 0.01);
        E.dessine();
    }


	int i;
	cin >> i;

	return 0;
}
