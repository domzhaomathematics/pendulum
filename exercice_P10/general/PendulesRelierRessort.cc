#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "PendulesRelierRessort.h"
using namespace std;


//Constructeur

PendulesRelierRessort::PendulesRelierRessort(double m1, double m2, double k, double d, double l1, double l2, double a1, double a2,
	Vecteur p, Vecteur v, SupportADessin* support):Oscillateur(p,v,support),
	m1(m1), m2(m2), k(k),d(d),l1(l1),l2(l2),a1(a1),a2(a2)
{}

// get
double PendulesRelierRessort::M1() const
{
	return m1;
}
double PendulesRelierRessort::M2() const
{
	return m2;
}
double  PendulesRelierRessort::K() const
{
	return k;
}
double PendulesRelierRessort::D() const
{
	return d;
}

double PendulesRelierRessort::L1() const
{
	return l1;
}
double PendulesRelierRessort::L2() const
{
	return l2;
}
double PendulesRelierRessort::A1() const
{
	return a1;
}
double PendulesRelierRessort::A2() const
{
	return a2;
}


//Methodes

Vecteur PendulesRelierRessort::f(double t, Vecteur P, Vecteur Q)
{ 
    double l = sqrt(a1*a1 + a2 * a2 + d * d - 2 * a1*d*sin(P.Composantes()[0]) + 2 * a2*d*sin(P.Composantes()[1]) - 2 * a1*a2*cos(P.Composantes()[1] - P.Composantes()[0]));
    double acc1 = (k*a1*((l - d) / l)*(d*cos(P.Composantes()[0]) + a2 * sin(P.Composantes()[1] - P.Composantes()[0])) - m1 * sqrt(g*g)*l1*sin(P.Composantes()[0])) / (m1*l1*l1);
    double acc2 = (-1 * k*a2*((l - d) / l)*(d*cos(P.Composantes()[1]) + a1 * sin(P.Composantes()[1] - P.Composantes()[0])) - m2 * sqrt(g*g)*l2*sin(P.Composantes()[1])) / (m2*l2 *l2);
	vector<double> acc = { acc1,acc2 };
	return Vecteur(acc);
}
void PendulesRelierRessort::dessine() const
{
	Dessinable::support->dessine(*this);
}
