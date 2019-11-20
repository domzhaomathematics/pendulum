#include <cmath>
#include <vector>
#include <iostream>
#include "Vecteur.h"
using namespace std;

int main() 
{
    //on cree des vecteurs de differente maniere
	Vecteur v1(1.0, 2.0, -0.1);
	Vecteur v2(2.6, 3.5,  4.1);
	Vecteur v3(v1);
	Vecteur v4(4); 
	Vecteur v5(-v1);
	vector<double> liste({0,1,2});
	Vecteur v6(liste);
	Vecteur vnul(0,0,0);
    //on les affiche
	cout << "Vecteur 1 : " << v1 << endl;
	cout << "Vecteur 2 : " << v2 << endl;
	cout << "Vecteur 3 : " << v3 <<endl;
	cout << "Vecteur 4 : " << v4 << endl;
	cout << "Vecteur 5 : " << v5 <<endl;
	cout << "Vecteur 6 : " << v6 <<endl;

    //on fait des tests d'egalite
	cout << "Le vecteur 1 est ";
	if (v1 == v2) {
		cout << "égal au";
	} else {
		cout << "différent du";
	}
	cout << " vecteur 2," << endl << "et est ";
	if (v1 != v3)
	{
		cout << "différent du";
	} else {
		cout << "égal au";
	}
	cout << " vecteur 3." << endl; 
	
    //on test les operateurs et on affiche le resultat
	cout << 1.0 + v2 << endl;
	v2 + 2.6; v2 +3.5; v2 + 4.1;
	v3 + 0; v3 + 0; v3 + 0;
	v4 + 1; v4 + 1; 
	cout << "(-1,-2,0.1) + le vecteur nul est " << v5 + vnul <<endl;
	cout << (v1 + v2) << endl;
	cout << (v1 + v3) << endl;
	cout << "addition opposee " << (v6 + v1) << ", est egale a soustraction " << v6 -v5 << endl;
	cout << (v1 - v4) << endl;
	cout << " v1 + v4 " << (v1 + v4) << ", v4 + v1 " << (v4 + v1) << endl;
	cout << -v1 << endl;
	cout << "Soustraction par soi-meme" << v1 + v5 << endl;
	cout << (v1*3) << endl;
	cout << (3*v1) <<endl;
	cout << (v1 * v2) << endl;
	cout << v1.norme2() << endl;
	cout << v2.norme2() << endl; 
	v1 = v1+v2;
	cout << v1; 


	return 0;
}
