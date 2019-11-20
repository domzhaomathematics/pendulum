#pragma once
#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"


class Integrateur
{
	//dt est les intervalles de temps qu' on veut. tps est le temps actuel
	public:
    //constructeur
	Integrateur(double n)
	: dt(n)
	{}
    //methode evolue
	virtual void evolue(Oscillateur& o, double tps) = 0;
	
	protected:
    //pas de temps
	double dt;
};

