#ifndef PenduleRessort_hpp
#define PenduleRessort_hpp
#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"


class PenduleRessort : public Oscillateur
{
protected:
	double m; //masse
	double l; //longeur du ressort au repos
	double k; // constante du ressort

	//Le parametre est le vecteur position reelle en 3D
public:
	//constructeur

	PenduleRessort(double m, double L, double k, Vecteur p, Vecteur v, SupportADessin* support);

	//get
	double M() const;
	double L() const;
	double K()const;

	//methodes
	Vecteur f(double t, Vecteur P, Vecteur Q);
	virtual void dessine() const override;







};

#endif