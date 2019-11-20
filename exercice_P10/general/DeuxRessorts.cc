#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "DeuxRessorts.h"
using namespace std;


//Constructeur

DeuxRessorts::DeuxRessorts(double m1, double m2, double k1, double k2,
	double k3, double l1, double l2, double l3, double lambda,
	Vecteur p, Vecteur v, Vecteur axis,
	SupportADessin* support): 
	Oscillateur(p,v,support), m1(m1),m2(m2),k1(k1),k2(k2),k3(k3),l1(l1),
	l2(l2),l3(l3),lambda(lambda),axis(axis)
{}
//Get
double DeuxRessorts::M1() const
{
	return m1;
}
double DeuxRessorts::M2() const
{
	return m2;
}
double DeuxRessorts::K1() const
{
	return k1;
}
double DeuxRessorts::K2() const
{
	return k2;
}
double DeuxRessorts::K3() const
{
	return k3;
}
double DeuxRessorts::L1() const
{
	return l1;
}
double DeuxRessorts::L2() const
{
	return l2;
}
double DeuxRessorts::L3() const
{
	return l3;
}
double DeuxRessorts::LAMBDA() const
{
	return lambda;
}
Vecteur DeuxRessorts::A() const
{
	return axis;
}

//methodes
Vecteur DeuxRessorts::f(double t, Vecteur P, Vecteur Q)
{
	double acc1 = -1 * (lambda /m1)*Q.Composantes()[0] - ((k1 + k3) / m1)*P.Composantes()[0] + (k3 / m1)*P.Composantes()[1];
	double acc2 = -1 * (lambda / m2)*Q.Composantes()[1] - ((k2 + k3) / m2)*P.Composantes()[1] + (k3 / m2)*P.Composantes()[0];
	vector<double>  acc = { acc1, acc2 };
	return Vecteur(acc);
}
void DeuxRessorts::dessine() const
{
	Dessinable::support->dessine(*this);
}



