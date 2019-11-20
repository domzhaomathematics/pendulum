#ifndef DESSINABLE_HPP
#define DESSINABLE_HPP
#include <iostream>

class SupportADessin;

class Dessinable 
{
	
	public:
	//constructeur et destructeur
    Dessinable(SupportADessin* sd = nullptr): support(sd) {} //par defaut on met la valeur nullptr, pour faciliter le constructeur par defaut de Oscillateur
	
	virtual ~Dessinable() {}
	//functions
    SupportADessin* Support() const {return support;}
    void Support(SupportADessin* sd) {support = sd;}
	//to override
	virtual void dessine() const=0 ;

		
	protected:
	SupportADessin*  support;

};
#endif
