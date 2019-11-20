#include <iostream>
#include <typeinfo>
#include <string>
#include "Vecteur.h"
#include "IntegrateurRK.h"
#include "Oscillateur.h"
//#include "OscillateurDouble.h" on l'enleve ici pour faire compiler testintegrateur
using namespace std;


void IntegrateurRK::evolue(Oscillateur& o, double tps)
{
    k1=o.Vitesse();
    k11=o.f(tps, o.Parametre(),o.Vitesse());
    k2=o.Vitesse() + (dt/2)*k11;
    k21=o.f(tps + (dt/2), o.Parametre() + (dt/2)*k1,o.Vitesse() + (dt/2)*k11);
    k3=o.Vitesse() + (dt/2)*k21;
    k31=o.f(tps + (dt/2), o.Parametre() + (dt/2)*k2,o.Vitesse() + (dt/2)*k21);
    k4=o.Vitesse() + dt*k31;
    k41=o.f(tps + dt, o.Parametre() + dt*k3,o.Vitesse() + dt*k31);

	Vecteur p(o.Parametre());
	Vecteur extra((dt/6)*(k1 + 2*k2 + 2*k3 + k4));
	Vecteur extra2(p + extra);
	o.Parametre(extra2);
    //o.Parametre(o.Parametre() + (dt/6)*k1 + 2*k2 + 2*k3 + k4);
    Vecteur v(o.Vitesse());
    Vecteur extra3((dt/6)*(k11 + 2*k21 + 2*k31 + k41));
    Vecteur extra4(v + extra3);
    o.Vitesse(extra4);
    //o.Vitesse(o.Vitesse()+ (dt/6)*k11 + 2*k21 + 2*k31 + k41);
}
