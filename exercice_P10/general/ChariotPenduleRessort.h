#ifndef ChariotPenduleRessort_hpp
#define ChariotPenduleRessort_hpp
#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class ChariotPenduleRessort : public Oscillateur
{

	//Conception: la premiere composante du parametre est la position du chariot, la deuxieme composante est l'angle du pendule.
protected:
	double m1;
	double m2;
	double l;
	double k;
	double lambda; //Coefficient de friction
	double u;
public:

	ChariotPenduleRessort(double m1,double m2,double l, double k , double lambda, double u, Vecteur p,Vecteur v, SupportADessin* support);
//gets
	double M1() const;
	double M2() const;
	double L() const;
	double K() const;
	double LAMBDA() const;
	double U() const;
	Vecteur f(double t, Vecteur P, Vecteur Q);
	virtual void dessine() const override;












};




#endif
