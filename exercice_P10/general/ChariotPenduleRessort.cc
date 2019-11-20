#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "ChariotPenduleRessort.h"
using namespace std;

//Constructeur

ChariotPenduleRessort::ChariotPenduleRessort(double m1, double m2, double l, double k, double lambda, double u, Vecteur p,Vecteur v, SupportADessin* support):
	Oscillateur(p,v,support), m1(m1),m2(m2),l(l),k(k),lambda(lambda),u(u)
{}
//gets
double ChariotPenduleRessort::M1() const
{
	return m1;
}
double ChariotPenduleRessort::M2() const
{
	return m2;
}
double ChariotPenduleRessort::L() const
{
	return l;
}
double ChariotPenduleRessort::K() const
{
	return k;
}
double ChariotPenduleRessort::LAMBDA() const
{
	return lambda;
}
double ChariotPenduleRessort::U() const
{
	return u;
}


//Methodes

Vecteur ChariotPenduleRessort::f(double t, Vecteur P, Vecteur Q)
{
	double A = m1 + m2 * sin(P.Composantes()[1])*sin(P.Composantes()[1]);
	double B = k * P.Composantes()[0] + lambda * Q.Composantes()[0] - m2 * l*Q.Composantes()[1] * Q.Composantes()[1] * sin(P.Composantes()[1]);
	double C = sqrt(g*g)*sin(P.Composantes()[1]) + u * Q.Composantes()[1];//multiply by angle?
	double acc1 = (-1 * B + m2 * C*cos(P.Composantes()[1])) / A;
	double acc2 = (B*cos(P.Composantes()[1]) - (m1 + m2)*C) / A;
	vector<double> acc = { acc1,acc2 };
	return Vecteur(acc);


}
void ChariotPenduleRessort::dessine() const
{
	Dessinable::support->dessine(*this);
}

