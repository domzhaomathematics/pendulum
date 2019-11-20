
#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "IntegrateurEuler.h"
//#include "OscillateurDouble.h" on l'enleve pour fair compiler testintegrateur



void IntegrateurEulerCromer::evolue(Oscillateur& o, double tps)
{
	//on doit passer par des intermediaires pour que cela compilesur geany
	Vecteur pt0(o.Parametre());
	Vecteur vt0(o.Vitesse());
	Vecteur ft0(o.f(tps, pt0, vt0));
	Vecteur extra(ft0*dt);
	Vecteur extra2(vt0 + extra);
	o.Vitesse(extra2);
	Vecteur extra3(o.Vitesse()*dt);
	Vecteur extra4(pt0 + extra3);
	o.Parametre(extra4);
}
