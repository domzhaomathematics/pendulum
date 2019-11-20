#ifndef ESPACEPHASE_HPP
#define ESPACEPHASE_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include "Oscillateur.h"
#include "Vecteur.h"
#include "Dessinable.h"

class EspacePhase: Dessinable
{
protected:
	std::vector<std::vector<double>>  espace;
    Oscillateur* o;
public:
    EspacePhase(SupportADessin* support = nullptr); //on definit un constructeur par defaut pour permettre un attribut EspacePhase pas toujours initialisee dans GLwidget
    EspacePhase(Oscillateur* oo, SupportADessin* support = nullptr);
    std::vector<std::vector<double>> Espace() const;
    Oscillateur O() const;
    void ajouter(Oscillateur& o);               //pour ajouter un oscillateur
    virtual void dessine() const override;
    void evolue(double t, double step);
    void ajoute(SupportADessin* a);             //pour ajouter un support a dessin
    SupportADessin* Support() {return support;}


	//L'espace sera dessiner avec une fonction dessine et sera evoluer (son oscillateur)




};

#endif
