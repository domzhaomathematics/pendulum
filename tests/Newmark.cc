#include <iostream>
#include <typeinfo>
#include <string>
#include "Vecteur.h"
#include "Newmark.h"
#include "Oscillateur.h"
//#include "OscillateurDouble.h" on l'enleve ici pour faire compiler testintegrateur
using namespace std;




void IntegrateurNewmark::evolue(Oscillateur& o, double tps)
{
    cout << "dans newmark" <<endl;
    q = (0,0,0);
	s=o.f(tps, o.Parametre(), o.Vitesse());
    cout << "q : "<< q <<endl;
    cout << "parametre : " << o.Parametre() <<endl;
    while ((o.Parametre() - q).norme() >= epsilon)
	{
        cout << "dans while du newmark" <<endl;
		q = o.Parametre();
        double v2(tps+dt);
        r = o.f(v2, o.Parametre(), o.Vitesse());
        Vecteur v3((dt/2)*(r + s));
        Vecteur v4(o.Vitesse() + v3);
        o.Vitesse(v4);
        Vecteur v5(dt*o.Vitesse());
        Vecteur v6((dt*dt/3)*(0.5*r + s));
        Vecteur v7(o.Parametre() + v5 + v6);
        o.Parametre(v7);
        cout << (o.Parametre() -q).norme() <<endl;
	}
}


