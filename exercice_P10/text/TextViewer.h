#ifndef TestViewer_HPP
#define TestViewer_HPP

#include "SupportADessin.h"


class TextViewer:public SupportADessin
{
	public:
//constructeur et destructeur
	TextViewer(std::ostream& f);
	virtual ~TextViewer();

//fonction
	virtual void dessine(const Oscillateur&) override;
	virtual void dessine(const Pendule& ) override;
	virtual void dessine(const Ressort& ) override;
	virtual void dessine(const Systeme& ) override;
	virtual void dessine(const OscillateurDouble&) override;
    virtual void dessine(const EspacePhase &) override;
    virtual void dessine(const PenduleTorsion &) override;
    virtual void dessine(const PenduleRessort &) override;
    virtual void dessine(const ChariotPenduleRessort &) override;
    virtual void dessine(const DeuxRessorts &) override;
    virtual void dessine(const PendulesRelierRessort &) override;



	private:
	std::ostream& flot;
};
#endif

