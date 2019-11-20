#pragma once
#include "Vecteur.h"
#include "Integrateur.h"



class IntegrateurNewmark :public Integrateur
{
	public:
    //constructeur
    IntegrateurNewmark(double n, double e=0.1)
        : Integrateur(n), q(0,0,0), r(0), s(0), epsilon(e) {}
    //methode evolue
	void evolue(Oscillateur& o, double tps);
	
	private:
    //les variables intermediaires necessaires
	Vecteur q;
	Vecteur r;
	Vecteur s;
	double epsilon;
};

