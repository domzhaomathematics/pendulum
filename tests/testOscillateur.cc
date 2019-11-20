#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
using namespace std;

int main()
{
	//on definit des vecteurs qu'on met dans l'oscillateur
    Vecteur v(1,2,3);
	Vecteur p(1,3,4);
	Oscillateur o(p,v);
	
	//on l'affiche
	cout <<"affichage de o : "<< o << endl;
	cout <<"on change les attributs "<<endl;
	
	//on change les attributs, puis l'affiche et sa fonction f
	Vecteur h(2,3,5);
	Vecteur hh(1,1,1);
	o.Parametre(h);
	o.Vitesse(hh);
	cout << "son paramètre : "<<o.Parametre()<< "; et sa vitesse : " << o.Vitesse() <<endl;
	cout << "sa fonction pour t= 5 : " << o.f(5, h, hh)<<endl;
	
	//on test ce qu'il se passe pour des parametres et des vitesses de dimension differentes
	vector <double> f({3,2});
	Vecteur faux(f);
	cout << "on change la vitesse en un vecteur de dimension differente" <<endl;
	o.Vitesse(faux);
	cout << o <<endl;
	cout << "on change le parametre en un vecteur de dimension differente" <<endl;
	o.Parametre(faux);
	cout<<o<<endl;


	return 0;
}

