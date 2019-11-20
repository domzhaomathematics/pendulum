#include <vector>
#include <cmath>
#include <iostream>
#include "Vecteur.h"

using namespace std;

//Constructeurs

	Vecteur::Vecteur(size_t n)
	{
		for (size_t i(0); i<n;i++)
		{
			composantes.push_back(0);
		}
	}

	Vecteur::Vecteur(double a, double b, double c)
	{
		composantes = {a,b,c};
	}

	Vecteur::Vecteur(const Vecteur& autre)
	{
		composantes = autre.composantes;
	}

	Vecteur::Vecteur(vector<double> v)
	{
		composantes = v;
	}


	//Surcharge des operateurs

	Vecteur Vecteur::operator+(double valeur) 
	{
		composantes.push_back(valeur);
		return Vecteur(*this);
	}

	void Vecteur::set_coord(size_t place, double valeur)
	{
		if (place > composantes.size())
		{
			cout << "le vecteur est de dimension trop petite";
		} else
		{
			composantes[place - 1] = valeur;
		}
	}

	bool Vecteur::operator==(Vecteur v) const
	{
		bool retour(true);
		if (v.composantes.size() != composantes.size())
		{
			retour = false;
		} else
		{
			for (size_t i(0); i < composantes.size(); i++)
			{
				if (v.composantes[i] != composantes[i])
				{
					retour = false;
				}
			}
		}
		return retour;
	}

	bool Vecteur::operator!=(Vecteur v) const
	{
		return not(*this == v);
	}

    void Vecteur::operator+=(Vecteur b)
    {
		unsigned int tailleMin = composantes.size() > (b.composantes).size() ? (b.composantes).size() : composantes.size();
		
		for (size_t i(0); i < tailleMin; i++)
		{
			composantes[i] = composantes[i] + b.composantes[i];
		}
		if (composantes.size() != (b.composantes).size())
		{
			cout << "les vecteurs additionnes ne sont pas de meme dimension " <<endl;
		}
	}

	Vecteur Vecteur::operator+(Vecteur b) const
	{
		Vecteur v(*this);
		v += b;
		if (composantes.size() != (b.composantes).size())
		{
			cout << "les vecteurs soustraits ne sont pas de meme dimension " <<endl;
		}
		return v;
		
	}

	void Vecteur::operator-=(Vecteur b) //Par convention on prend la taille fixe du premier operande (objet appelant)
	{
		unsigned int tailleMin = composantes.size() > (b.composantes).size() ? (b.composantes).size() : composantes.size();
		
		for (size_t i(0); i < tailleMin; i++)
		{
			composantes[i] = composantes[i] - b.composantes[i];
		}
		if (composantes.size() != (b.composantes).size())
		{
			cout << "les vecteurs soustraits ne sont pas de meme dimension " <<endl;
		}
	}

	Vecteur Vecteur::operator-(Vecteur b) const// par convention on prend la taille de l'objet avec la plus petit dimension
	{	
		Vecteur v(*this);
		v -= b;
		if (composantes.size() != (b.composantes).size())
		{
			cout << "les vecteurs soustraits ne sont pas de meme dimension " <<endl;
		}
		return v;
	}

	Vecteur Vecteur::operator-() const
	{
		Vecteur v(*this*(-1.0));

		return v;
	}

	Vecteur Vecteur::operator*(double a) const 
	{
		Vecteur vect(composantes.size());
		vect.composantes = composantes;
		for (size_t i(0); i < composantes.size(); i++)
		{
			(vect.composantes)[i] = a*composantes[i];
		}
		return vect;
	}

	double Vecteur::operator*(Vecteur autre) const //utilise comme si les deux vecteurs sont de taille de du vect de plus petite dimension
	{
		unsigned int tailleMin = composantes.size() >(autre.composantes).size() ? (autre.composantes).size() : composantes.size();
		double produit(0);
	
		for (size_t i(0); i < tailleMin; i++)
		{
			produit += composantes[i] * ((autre).composantes)[i];
		}
		if (composantes.size() != (autre.composantes).size())
		{
			cout << "les vecteurs multiplies ne sont pas de meme dimension " <<endl;
		}
		return produit;
	}

	Vecteur Vecteur::operator^(Vecteur autre) const  // Si le vecteur n'est pas de taille 3, on enleve (si plus grand) ou rajoute 0 si plus petit
	{
		Vecteur vect(3);
		Vecteur vect1(3);
		Vecteur vect2(3);
		if (composantes.size() != 3) {
			for (size_t i(0); i < (composantes.size()>3 ? 3 :composantes.size()); i++)
			{
				(vect1.composantes)[i] = composantes[i];
			}
		
		}
		else
		{
			for (size_t i(0); i < 3; i++) {
				(vect1.composantes)[i] = composantes[i];
			}
		}

		if ((autre.composantes).size() != 3)
		{
			for (size_t i(0); i < ((autre.composantes).size()>3? 3:(autre.composantes).size()); i++)
			{
				(vect2.composantes)[i] = autre.composantes[i];
			}
		}
		else
		{
			for (int i(0); i < 3; i++) {
				(vect2.composantes)[i] = (autre.composantes)[i];
			}
		}
		
		(vect.composantes)[0] = (vect1.composantes)[1] * (vect2.composantes)[2] - (vect1.composantes)[2] * (vect2.composantes)[1];
		(vect.composantes)[1] = (vect1.composantes)[2] * (vect2.composantes)[0] - (vect1.composantes)[0] * (vect2.composantes)[2];
		(vect.composantes)[2] = (vect1.composantes)[0] * (vect2.composantes)[1] - (vect1.composantes)[1] * (vect2.composantes)[0];

		
		return  vect;

	}



	//Methodes

	double Vecteur::norme()
	{
		double norme2 = 0;
		for (size_t i(0); i < composantes.size(); i++)
		{
			norme2 += composantes[i] * composantes[i];
		}

		return sqrt(norme2);
	}

	double Vecteur::norme2()
	{
		double norme2 = 0;
		for (size_t i(0); i < composantes.size(); i++)
		{
			norme2 += composantes[i] * composantes[i];
		}
		return norme2;
	}
	
	Vecteur& Vecteur:: operator =(const Vecteur& v)  
	{
	composantes = v.composantes;
	return *this;
	}
	size_t Vecteur::taille()
	{
		return composantes.size();
	}
	
	
Vecteur operator+(double a, Vecteur b)
{

	return b + a;
}

Vecteur operator*(double a, Vecteur b) 
{

	return  b*a;
}



//Get


vector<double> Vecteur::Composantes()  const
{
	return composantes;
}
