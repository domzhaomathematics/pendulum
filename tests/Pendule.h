#ifndef  Pendule_HPP
#define Pendule_HPP
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"



class Pendule:public Oscillateur
{
	
public:
//constructeur
	Pendule(double m, double lambda,double l, Vecteur o, SupportADessin* support, Vecteur para, Vecteur vit);
	//La vitesse est une vitesse angulaire et le parametre est un angle (1D)
	~Pendule();

//get
	double L() const;
	double M() const;
	double Lambda() const;
	Vecteur O() const;

	

//set
	void L(double a);
	void M(double b);
	void Lambda(double c);
	void O(Vecteur b);

//methods
	Vecteur f(double t, Vecteur P, Vecteur Q);
	virtual void dessine() const override;
	
	private:
    double l; //longueur du pendule
	double m; //masse
	double lambda; //frottement
    Vecteur o; //origine
	
	
};







#endif 
