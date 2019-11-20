#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
#include "Pendule.h"
#include "IntegrateurEuler.h"
#include "IntegrateurRK.h"
#include "Newmark.h"

using namespace std;



//puisque nous n'avons defini aucun support a dessin dans ces tests (on n'avait pas encore vu cela), ils ne compilent plus


int main()
{

	Pendule P1(0.33, 0.25, 0.15, Vecteur(0, 1, 0), Vecteur(0, 0, 0));
	P1.Vitesse(0);
	P1.Parametre(Vecteur(0,P1.L(),0));
	cout << P1 << endl;
	

	IntegrateurEulerCromer in(0.01);
	double t = 0;
	while (t < 0.04) {
		in.evolue(P1, t); // un object oscillateur , et le temps
		t += 0.01;
		cout << P1 << endl;
		cout << (P1.Parametre()) << endl;
		cout << (P1.Vitesse()) << endl;

		cout << endl;
	}


	return 0;
}
