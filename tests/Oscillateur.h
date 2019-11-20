#pragma once
#ifndef OSCILLATEUR_HPP
#define OSCILLATEUR_HPP 

#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Dessinable.h"


class Oscillateur: public Dessinable
{
	
public :	
//constructeurs
    Oscillateur(SupportADessin* support = nullptr); //On definit un constructeur par defaut pour oscillateur pour faciliter le constructeur par defaut de EspacePhase
    Oscillateur(Vecteur & p,Vecteur & v, SupportADessin* support = nullptr); //pas ne pas cree des objects inutiles
    Oscillateur(const Oscillateur& o);

//destructeur
	virtual ~Oscillateur() {} 

//get
	Vecteur Parametre() const; 
	Vecteur Vitesse() const;
	

//set   (surcharge)
	void Parametre(Vecteur v);			// on devrait avoir des const & mais ca ne marche pas
	void Vitesse(Vecteur v);

// methodes
	virtual Vecteur f(double t, Vecteur P, Vecteur Q); //virtual pour que les pointeurs d'un oscillateur utilise la fonciton approprie
	virtual void dessine() const override;
    void ajoute(SupportADessin* a);

//surcharge d operateur d affichage
    friend std::ostream& operator<<(std::ostream& os, Oscillateur& o)
	{
		os << "parametre : " << o.parametre << std::endl;
		os<< "vitesse : "<< o.vitesse << std::endl;
		return os;
	}
	
    protected:
	Vecteur parametre;
	Vecteur vitesse;

};

#endif

