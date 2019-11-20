#pragma once
#ifndef VECTEUR_HPP
#define VECTEUR_HPP
#include <vector>
#include <iostream>


class Vecteur 
{
	
public:
	// constructeur
	friend class Oscillateur;
    Vecteur(size_t n);                      //cree un vecteur de taille n contenant des 0
    Vecteur(double a, double b, double c);  //cree un vecteur (a,b,c)
    Vecteur(const Vecteur& autre);          //copie
    Vecteur(std::vector<double> v);         //cree le vecteur v

    //set
	void set_coord(size_t place, double valeur);

    //surcharge operateur
    Vecteur operator+(double valeur);       //ajoute valeur a la fin du vecteur actuel
    bool operator==(Vecteur v) const;       //retourne vrai si les composantes de v sont egales a celles du vecteur actuel
    bool operator!=(Vecteur v) const;       //retourne faux si les composantes de v sont egales a celles du vecteur actuel
    void operator+=(Vecteur b);             //ajoute b au vecteur actuel
    Vecteur operator+(Vecteur b) const;     // par convention on prend la taille de l'objet avec la plus petit dimension
    Vecteur operator-(Vecteur b) const;		// par convention on prend la taille de l'objet avec la plus petit dimension
	void operator-=(Vecteur b);
	Vecteur operator-() const;
	Vecteur operator*(double a) const;
	double operator*(Vecteur autre) const;
	
	//utilise comme si les deux vecteurs sont de taille de du vect de plus petite dimension
	Vecteur operator^(Vecteur autre) const;
	// Si le vecteur n'est pas de taille 3, on enleve (si plus grand) ou rajoute 0 si plus petit
	double norme();
	double norme2();
	Vecteur& operator=(const Vecteur& v);

//get function
	std::vector<double> Composantes()const;
	size_t taille();
	

private:
    //les composantes du vecteur
    std::vector<double> composantes;
    //l'operateur d'affichage est un friend de la classe vecteur
	friend std::ostream& operator<<(std::ostream& os, const Vecteur& v)
	{
		os << "(";
	for (size_t i(0); i < (v.composantes).size(); i++)
	{
		os << v.composantes[i];
		if (i < ((v.composantes).size() - 1)) { os << ","; }
	}
	os << ")" << std::endl;
	 return os;
	}
    friend Vecteur operator+(double a, Vecteur b);
	friend Vecteur operator*(double a, Vecteur b);
};


#endif
