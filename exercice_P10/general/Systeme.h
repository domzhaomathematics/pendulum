#ifndef SYSTEME_HPP
#define SYSTEME_HPP
#include <vector>
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"


class Systeme: public Dessinable
{
	public:
//constructeur et destructeur
	Systeme(const Systeme& s);
	Systeme(std::vector<Oscillateur*>& v, SupportADessin* support);
	Systeme(SupportADessin* vue);

    ~Systeme();  

//get de la collection
	std::vector<Oscillateur*> Collection() const;
//set de la collection
    void Collection(std::vector<Oscillateur*> const & v);
//dessine du systeme
	virtual void dessine() const override ;
//evolue du systeme
	void evolue(double t, double step);
	
	protected: 
    //la collection heterogene des oscillateurs du systeme
	std::vector<Oscillateur*>  collection;























};



#endif 


