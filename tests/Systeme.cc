#include <vector>
#include <sstream>
#include <iostream>
#include "Oscillateur.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "IntegrateurEuler.h"
#include "Systeme.h"
#include "Newmark.h"
#include "IntegrateurRK.h"



using namespace std;

//Constructeurs et destructeurs

Systeme::Systeme(const Systeme& s)
: Dessinable(s)
{
	for (size_t i(0); i < s.collection.size(); i++) 
	{
		collection.push_back((s.collection)[i]);
	
	}
}

Systeme::Systeme(std::vector<Oscillateur*>& v, SupportADessin* support) 
: Dessinable(support) 
{
	for(size_t i(0);i<v.size();i++)
	{
		collection.push_back(v[i]);

	}
}

Systeme::Systeme(SupportADessin* vue)
:Dessinable(vue)
{}

Systeme::~Systeme()
{
	for (auto el : collection)
	{
		delete el;
	}
}

// Methodes

vector<Oscillateur*> Systeme::Collection() const
{
	return collection;

}

void Systeme::Collection(std::vector<Oscillateur*> const & v)
{
    collection = v;
}

 void Systeme::dessine() const
{
     
	support->dessine(*this);
  
}

 void Systeme::evolue(double t,  double step)
{
     
     IntegrateurRK in(step);
	 for (size_t i(0); i < collection.size(); i++)
	 {
		 in.evolue(*collection[i], t);
	 }
}
