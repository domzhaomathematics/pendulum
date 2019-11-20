#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "constantes.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "OscillateurDouble.h"
#include "SupportADessin.h"
#include "Dessinable.h"

using namespace std;


//Constructeur et destructeur

OscillateurDouble::OscillateurDouble(double m1, double m2,double l1,double l2, Vecteur o, SupportADessin* support, Vecteur p, Vecteur v)
	:m1(m1), m2(m2),l1(l1),l2(l2),o(o),Oscillateur(p,v,support)
{}

OscillateurDouble:: ~OscillateurDouble()
{}

//get
double OscillateurDouble::L1() const
{
	return l1;
}
double OscillateurDouble::M1() const
{
	return m1;
}
double OscillateurDouble::L2() const
{
	return l2;
}
double OscillateurDouble::M2() const
{
	return m2;
}
Vecteur OscillateurDouble::O()const
{
	return o;
}





//methodes

Vecteur OscillateurDouble::f(double t, Vecteur P, Vecteur Q)
{

	double p1 = P.Composantes()[0];  //theta1
	double p2 = P.Composantes()[1]; //theta2
	double g1 = sqrt(g*g); //norme de g
	//Les accelerations (theta1**), vecteurs 2D
	vector<double> acc = { ((m2*g1*cos(p1 - p2)*sin(p2) - (m1 + m2)*g1*sin(p1) - m2 * l1*(Q.Composantes()[0] * Q.Composantes()[0])*cos(p1 - p2)*sin(p1 - p2) - m2 * l2*Q.Composantes()[1] * Q.Composantes()[1] * sin(p1 - p2)) / ((m1 + m2 * sin(p1 - p2)*sin(p1 - p2))*l1))
	,(((m1 + m2)*g1*cos(p1 - p2)*sin(p1) - (m1 + m2)*g1*sin(p2) + m2 * l2*(Q.Composantes()[1] * Q.Composantes()[1]) *cos(p1 - p2)*sin(p1 - p2) + (m1 + m2) * l1*Q.Composantes()[0] * Q.Composantes()[0] * sin(p1 - p2)) / ((m1 + m2 * sin(p1 - p2)*sin(p1 - p2))*l2)) };

	return Vecteur(acc);

}
void OscillateurDouble::dessine() const 
{
	Dessinable::support->dessine(*this);
}


//Fonctions globales pour l'operateur. Cela n'est plus necessaire, mais on l'avait fait car initialement le parametre etait un vector<Vecteur>
vector<Vecteur> operator+(vector<Vecteur> v1, vector<Vecteur> v2)
{
	vector<Vecteur> v3 = { v1[0] + v2[0],v1[1] + v2[1] };
	return v3;
}

vector<Vecteur> operator*(vector<Vecteur> v1, double a)
{
	vector<Vecteur> v2 = { v1[0] * a,v1[1] * a };
	return v2;
}