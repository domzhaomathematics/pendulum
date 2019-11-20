#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"
//#include "TextViewer.h"
using namespace std;



//constructeurs
Oscillateur::Oscillateur(SupportADessin* support)
: Dessinable(support), vitesse(Vecteur(1)),parametre(Vecteur(1))
{}



Oscillateur::Oscillateur(Vecteur & p, Vecteur & v, SupportADessin* support) //donner valeur par defaut a support! (a faire)
: Dessinable(support), vitesse(v), parametre(p)
{
	if (v.taille() != p.taille())
	{
		cout <<"erreur: dimension parametre != dimension vitesse" <<endl;
		if (v.taille() < p.taille())
		{
			for (size_t i(v.taille()); i < parametre.taille(); i++)
			{
				v + 0;
			}
		} 
		if (v.taille() > p.taille())
		{
			Vecteur vide (parametre.taille());
			vide += v;
			v = vide;
		}
		
	}
}//pas ne pas cree des objects inutiles



Oscillateur::Oscillateur(const Oscillateur& o): Dessinable(o.Support()), parametre(o.parametre),vitesse(o.vitesse)
{}


//get
Vecteur Oscillateur::Parametre() const
{
	return parametre;
}
Vecteur Oscillateur::Vitesse() const
{
	return vitesse;
}

//set   (overloading)
void Oscillateur::Parametre(Vecteur v) 
{
	parametre = v;
	if (vitesse.taille() != v.taille())
	{
		cout <<"erreur: dimension parametre != dimension vitesse" <<endl;
	}
	if (vitesse.taille() < v.taille())
	{
		for (size_t i(vitesse.taille()); i < v.taille(); i++)
		{
			vitesse + 0;
		}
	} 
	if (vitesse.taille() > v.taille())
	{
		Vecteur vide (v.taille());
		vide += vitesse;
		vitesse = vide;
	}
	
}
void Oscillateur::Vitesse(Vecteur v)
{
	if (v.taille() != parametre.taille())
	{
		cout << " dimension vitesse != dimension parametre" <<endl;
		if (v.taille() < parametre.taille())
		{
			vitesse = v;
			for (size_t i(v.taille()); i < parametre.taille(); i++)
			{
				(vitesse.Composantes()).push_back(0);
			} // to see, not sure
		} 
		if (v.taille() > parametre.taille())
		{
			Vecteur vide (parametre.taille());
			vitesse = vide;
			vitesse += v;
		}
	} else
	{
		vitesse = v;
	}
}


// methodes
Vecteur Oscillateur::f(double t, Vecteur P, Vecteur Q)
{
	
	vector<double> v({0,-9.81});
	Vecteur acceleration(v);
	return acceleration;
	
}

void Oscillateur::dessine() const 
{
	support->dessine(*this);
}

void Oscillateur::ajoute(SupportADessin* a)
{
    support = a;
}
