#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "PenduleRessort.h"
using namespace std;

//constructeur
PenduleRessort::PenduleRessort(double m, double L, double k, Vecteur p, Vecteur v, SupportADessin* support):
	Oscillateur(p,v,support),m(m),l(L),k(k)
{}

//get
double PenduleRessort::M() const
{
	return m;
}
double PenduleRessort::L() const
{
	return l;
}
double PenduleRessort::K() const
{
	return k;
}

//methodes
Vecteur PenduleRessort::f(double t, Vecteur P, Vecteur Q)
{

	return g - (k/m)*(1 - (l / sqrt(P*P)))*P;

}

void PenduleRessort::dessine() const
{
	Dessinable::support->dessine(*this);
}