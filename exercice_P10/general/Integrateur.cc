#include <iostream>
#include <typeinfo>
#include <string>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
#include "OscillateurDouble.h"

using namespace std;

void Integrateur::evolue(Oscillateur& o, double tps)
{
	
    Vecteur pt0(o.Parametre());
    Vecteur vt0(o.Vitesse());
    Vecteur extra(vt0*dt); 
    Vecteur extra2(pt0 + extra);
    o.Parametre(extra2);
    Vecteur extra3(o.f(tps, pt0, vt0)*dt);
    Vecteur extra4(vt0 + extra3);
    o.Vitesse(extra4);

}


