#ifndef DeuxRessorts_hpp
#define DeuxRessorts_hpp
#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class DeuxRessorts : public Oscillateur
{
protected:
    double m1;
    double m2;
	double k1;
	double k2;
	double k3;
	double l1;// origine et L1
	double l2; // distance entre m1 et m2 au repos
	double l3;//distance entre m2 et son origine
	double lambda;
	Vecteur axis;

	// le parametre est la position entre le repos (l1) et la position de la masse . Donc il faut rajouter l1 apres
	//x1 et x2 (delta) est dans la direction positive
	// Le milieu n'est pas compresser au debut
	// au debut 

public: 
	//constructeur
	DeuxRessorts(double m1, double m2, double k1, double k2,
		double k3,double l1,double l2,double l3,double lambda,Vecteur p, Vecteur v, Vecteur axis,
		SupportADessin* support);

	//Get
    double M1() const;
    double M2() const;
    double K1() const;
    double K2() const;
    double K3() const;
    double L1() const;
    double L2() const;
    double L3() const;
    double LAMBDA() const;
    Vecteur A() const;

	//methodes
	Vecteur f(double t, Vecteur P, Vecteur Q);
	virtual void dessine() const override;









};

#endif
