#ifndef PenduleRelierRessort_hpp
#define PenduleRelierRessort_hpp
#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class PendulesRelierRessort : public Oscillateur
{
protected:
	//Les parametres sont l'angle 1, l'angle 2
	double m1;
	double m2;
	double k;
	double d; //ecart entre les deux pendules, on suppose que c'est aussi la longueur au repos du pendule
	double l1;
	double l2;
	double a1;
	double a2;

public:
	//Constructeur
    PendulesRelierRessort(double m1, double m2, double k, double d, double l1, double l2, double a1, double a2, Vecteur p, Vecteur v, SupportADessin* support);

	//get
	double M1() const;
	double M2() const;
	double K() const;
	double D() const;
	double L1() const;
	double L2() const;
	double A1() const;
	double A2() const;

	//Methodes
	Vecteur f(double t, Vecteur P, Vecteur Q);
	virtual void dessine() const override;
	


	

	






};

#endif
