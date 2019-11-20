#ifndef OscillateurDouble_HPP
#define OscillateurDouble_HPP

#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"




class OscillateurDouble: public Oscillateur
{
public:
	//Constructeurs
	OscillateurDouble(double m1, double m2,double l1,double l2, Vecteur o, SupportADessin* support, Vecteur p, Vecteur v);
	~OscillateurDouble();

   //gets
	double L1() const;
	double L2() const;
	double M1() const;
	double M2() const;
	Vecteur O()const;
	
    //les methodes
	Vecteur f(double t, Vecteur P, Vecteur Q);
	virtual void dessine() const override;

private:
	
    double l1; //longueur du premier pendule
    double l2; //longueur du deuxieme pendule
    double m1; //masse du premier pendule
    double m2; //masse du deuxieme pendule
	Vecteur o; //origine
	/*
	Le parametre de l'oscilatteur double sera presente 
	par un vecteur de 2 dimensions. La premiere composante represente 
	theta 1, l'autre theta2. Meme chose pour la vitesse (vitesse angulaire)
	
	*/


};



#endif
