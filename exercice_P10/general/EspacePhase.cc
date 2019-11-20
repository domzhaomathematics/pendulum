#include <iostream>
#include <vector>
#include "Oscillateur.h"
#include "Vecteur.h"
#include "EspacePhase.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#include "Integrateur.h"
#include "IntegrateurEuler.h"
#include "Newmark.h"
#include "IntegrateurRK.h"

using namespace std;

//Constructeurs

EspacePhase::EspacePhase(SupportADessin* support)
    :Dessinable(support)
{
    espace = {{0,0}};
}

EspacePhase::EspacePhase(Oscillateur* oo, SupportADessin* support)
    : Dessinable(support), o(oo)
{
    espace = {{(*o).Parametre().Composantes()[0], (*o).Vitesse().Composantes()[0]}};
}


//Get
std::vector<std::vector<double>> EspacePhase::Espace() const
{
	return espace;
}

Oscillateur EspacePhase::O() const
{
    return *o;
}


//Methode
void EspacePhase::ajouter(Oscillateur& o)
{
    espace.push_back({ o.Parametre().Composantes()[0],o.Vitesse().Composantes()[0] });
	// permet de rajouter un oscillateur dans la liste espace ( une position et une vitesse) correspondant a un ligne
}


void EspacePhase::ajoute(SupportADessin* a)
{
    support = a;
}



void EspacePhase::dessine() const
{
    
    Oscillateur O(*o);
    cout << O << endl;

    support->dessine(*this);
}

void EspacePhase::evolue(double t, double step)
{
    IntegrateurRK in(step);
     cout << "taille " << Espace().size() <<endl;
     in.evolue(*o,t);
     cout << (*o).Parametre().Composantes()[0] <<endl;
     (*this).ajouter(*o);
     cout << espace[espace.size() -1][0] <<endl;
}
