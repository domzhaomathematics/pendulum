#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "PenduleTorsion.h"
using namespace std;

//Constructeur


PenduleTorsion::PenduleTorsion(double lambda, double c, double i, double l, double lf, Vecteur p, Vecteur v, SupportADessin* support):
Oscillateur(p,v,support), lambda(lambda),c(c),i(i), l(l), lf(lf)
{}


//gets
double PenduleTorsion::LAMBDA() const
{
	return lambda;
}

double PenduleTorsion::C() const
{
	return c;
}

double PenduleTorsion::I() const
{
	return i;
}

double PenduleTorsion::L() const
{
    return l;
}
double PenduleTorsion::LF() const
{
    return lf;
}


//Methodes

Vecteur PenduleTorsion::f(double t, Vecteur P, Vecteur Q)
{
    vector<double> acc = { -1 * (c*P.Composantes()[0] + lambda * Q.Composantes()[0]) / i };
	return Vecteur(acc);
		
}
void PenduleTorsion::dessine() const
{
	Dessinable::support->dessine(*this);
}


