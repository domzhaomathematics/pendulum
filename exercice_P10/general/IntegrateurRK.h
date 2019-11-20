#pragma once
#include "Vecteur.h"
#include "Integrateur.h"




class IntegrateurRK :public Integrateur
{//Runga-Kuta d'ordre 4
    public:
    //consructeur
    IntegrateurRK(double n)
        :Integrateur(n), k1(0), k2(0),k3(0),k4(0),k11(0),k21(0),k31(0),k41(0) {}
    //methode evolue
    void evolue(Oscillateur &o, double tps);

    private:
    //les variables intermediaires necessaires
    Vecteur k1;
    Vecteur k2;
    Vecteur k3;
    Vecteur k4;
    Vecteur k11;
    Vecteur k21;
    Vecteur k31;
    Vecteur k41;

};
