#ifndef SUPPORTADESSIN_HPP
#define SUPPORTADESSIN_HPP


class Oscillateur;
class Pendule;
class Ressort;
class Systeme;
class OscillateurDouble;
class EspacePhase;
class ChariotPenduleRessort;
class PenduleRessort;
class PenduleTorsion;
class DeuxRessorts;
class PendulesRelierRessort;

#include <iostream>

class SupportADessin
{
public:
    //destructeur
	virtual ~SupportADessin() {};

    //les methodes dessine des diffrents oscillateurs, virtuelles pures ici pour etre redefinies dans le Text et le graphisme
	virtual void dessine(Oscillateur const&) = 0;
	virtual void dessine(Pendule const&)=0;
	virtual void dessine(Ressort const&)=0;
	virtual void dessine(Systeme const&)=0;
	virtual void dessine(OscillateurDouble const&) = 0;
    virtual void dessine(EspacePhase const&) = 0;
    virtual void dessine(DeuxRessorts const&) = 0;
    virtual void dessine(PenduleTorsion const&) = 0;
    virtual void dessine(ChariotPenduleRessort const&) = 0;
    virtual void dessine(PenduleRessort const&) = 0;
    virtual void dessine(PendulesRelierRessort const&) = 0;







};



#endif
