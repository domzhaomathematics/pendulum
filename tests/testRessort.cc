#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
#include "Ressort.h"
#include "IntegrateurEuler.h"
#include "IntegrateurRK.h"
#include "Newmark.h"


using namespace std;


//puisque nous n'avons defini aucun support a dessin dans ces tests (on n'avait pas encore vu cela), ils ne compilent plus

int main() 
{

	Ressort r1(0.33, 0.25, 0.15,Vecteur(0.8,0,0.6),Vecteur(0,0,0));
	r1.Vitesse(0);
	r1.Parametre(0.18*r1.A()+r1.O());
	cout << r1 << endl;

	IntegrateurEulerCromer in(0.01);
	double t = 0;
	while(t<0.04) {
		in.evolue(r1, t); // un object oscillateur , et le temps
		t += 0.01;
		cout << r1 << endl;
		cout << (r1.Parametre()*r1.A())/sqrt(r1.A()*r1.A())<< endl;
		cout << (r1.Vitesse()*r1.A()) / sqrt(r1.A()*r1.A()) << endl;

		cout<<endl;
	}

	return 0;
}
