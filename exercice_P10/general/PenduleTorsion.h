#ifndef PenduleTorsion_HPP
#define PenduleTorsion_HPP
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class PenduleTorsion :public Oscillateur
{
private:
	// le parametre est seulement un angle (1D)
	double lambda;
	double c; //constante de torsion
	double i; //moment d'inertie
    double l; //length of the bar
    double lf; //longueur fil
public:
    PenduleTorsion(double lambda,double c,double i, double l, double lf, Vecteur p, Vecteur v, SupportADessin* support);

	//gets
	double LAMBDA() const;
	double C() const;
	double I() const;
    double L() const;
    double LF() const;
	Vecteur f(double t, Vecteur P, Vecteur Q);
	virtual void dessine() const override;





};




#endif
