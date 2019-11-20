#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
#include "IntegrateurEuler.h"
#include "Newmark.h"
#include "IntegrateurRK.h"

using namespace std;


int main()
{
	// On initialise l'oscillateur
    vector<double> a={0,1};
	vector<double> b={1,2};
	Vecteur para(a);
	Vecteur vit(b);
	Oscillateur o(para, vit);
	cout << o << endl;

	// on teste l'integrateur 
	double t = 0;
	IntegrateurRK i(0.01);
	while (t < 0.68)
	{
		cout << "temps" << t << " ";
		i.evolue(o, t);					//on fait evoluer o pout t=0.01, verification locale
		cout << o << endl;
		
		t += 0.01;

	}

	// On essaye avec une differente vitesse

	vector<double> T={0,0};//on essaye avec la vitesse nulle
	Vecteur c(T);
	o.Vitesse(c);
	cout << o << endl;
	i.evolue(o, 0.01);
	cout << o << endl;

	int ls;
	cin >> ls;
	
	return 0;
}

