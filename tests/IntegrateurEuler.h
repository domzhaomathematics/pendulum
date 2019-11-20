#pragma once
#include <iostream>
#include "Vecteur.h"
#include "Integrateur.h"
#include "Oscillateur.h"
using namespace std;


class IntegrateurEulerCromer :public Integrateur
{
	public:
    //constructeur
	IntegrateurEulerCromer(double n)
	: Integrateur(n)
	{}
    //methode evolue
	void evolue(Oscillateur& o, double tps);
};
