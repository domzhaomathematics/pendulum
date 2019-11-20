#ifndef Ressort_HPP
#define Ressort_HPP
#include <iostream>
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"



class Ressort :public Oscillateur
{
	// Pour la conception du Ressort, nous avons decider que le parametre sera un vecteur 3 dimension qui correspond a la position vectorielle du ressort.
	//Cela complique les choses, mais est tres utile pour l'implementation

public:
//constructeurs
	Ressort(const Ressort& r);
	Ressort(double k, double m, double l,Vecteur a, Vecteur o, SupportADessin* support, Vecteur para, Vecteur vit); //faire valeurs par defaut (a faire)
	~Ressort();
	
//get
	double K() const;
	double mass() const;
	double friction() const;
	Vecteur A() const;
	Vecteur O()const;

//set
	void K(double a);
	void mass(double b);
	void friction(double c);
	void A(Vecteur b);
	void O(Vecteur b);

// methodes
	Vecteur f(double t, Vecteur P, Vecteur Q); 
	virtual void dessine() const override;
	
	
	private :
    double k;       //constante de rigidite
    double M;       //masse
    double lambda;  //frottement
	Vecteur a;   //axe du ressort
	Vecteur o; // origine du ressort
	

};
#endif
