#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "SupportADessin.h"
#include "Dessinable.h"

using namespace std;


//Constructeur et destructeur

Pendule::Pendule(double m, double lambda,double l,Vecteur o, SupportADessin* support, Vecteur para, Vecteur vit) //faire valeurs par defaut (a faire)
	:Oscillateur(para, vit, support), m(m),lambda(lambda),o(o),l(l)
	
{
	  // le parametre est un angle (vecteur une dimension)
	// La vitesse est une vitesse angulaire (une dimension)
}



Pendule:: ~Pendule()
{

}

//get
double Pendule::L() const
{
	return l;
}
double Pendule::M() const
{
	return m;
}
double Pendule::Lambda() const
{
	return lambda;
}

Vecteur Pendule::O()const
{
	return o;
}

//set
void Pendule::L(double a)
{
	l = a;
}
void Pendule::M(double b)
{
	m = b;
}


void  Pendule::Lambda(double c)
{
	lambda = c;
}
/*void Pendule::A(Vecteur b)
{
	a = b;
}
*/
void Pendule::O(Vecteur b)
{
	o = b;
}


//Methodes

Vecteur Pendule::f(double t, Vecteur P, Vecteur Q)
{
	//P est l'angle et Q, la vitesse angulaire
	vector<double> a = { -sqrt(g*g) * (1 / l)*sin(P.Composantes()[0]) - (lambda / (m*l*l))*(Q.Composantes()[0]) };
	return Vecteur(a); // acceleration angulaire (1 dimension)
}

void Pendule::dessine() const
{
    cout << "dans dessine du pendule"<< endl;

	Dessinable::support->dessine(*this);

}
