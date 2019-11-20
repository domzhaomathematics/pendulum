#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "Ressort.h"
//#include "TextViewer.h"

using namespace std;

//Constructeurs et destructeurs

Ressort::Ressort(const Ressort& r)
:Oscillateur(r), k(r.k),M(r.M),lambda(r.lambda), a(r.a), o(r.o)
{}
Ressort::Ressort(double k, double m, double l,Vecteur a, Vecteur o,  SupportADessin* support, Vecteur para, Vecteur vit)
:Oscillateur(para, vit, support), k(k),M(m),lambda(l),a(a), o(o) //x axis
{}

Ressort::~Ressort()
{}

//get
double Ressort:: K() const
{
	return k;
}
double Ressort::mass() const
{
	return M;
}
double Ressort::friction() const
{
	return lambda; 
}

Vecteur Ressort::A() const
{
	return a;
}

Vecteur Ressort::O() const
{
	return o;
}
//set
void Ressort:: K(double a)
{
	k = a;
}
void Ressort:: mass(double b)
{
	M = b;
}
void Ressort::friction(double c)
{
	lambda = c;
}

void Ressort::A(Vecteur b)
{
	a = b; 

}

void Ressort::O(Vecteur b)
{
	o = b;
}

// Methodes
Vecteur Ressort::f(double t, Vecteur P, Vecteur Q)
{
return (((-1*(P*a) / sqrt(a*a))*(k / M)) - ((Q*a) / sqrt(a*a))*(lambda / M) + (g * a))*a*(1/sqrt(abs(a*a)));
	
// (P*a) / sqrt(a*a) pour la direction et norme du vecteur (- si dans le sens oppose), cela est necessaire car on le fait en 3 dimensions.
}


void Ressort::dessine() const
{
    cout << "dans dessine du ressort"<< endl;

	Dessinable::support->dessine(*this);

}
