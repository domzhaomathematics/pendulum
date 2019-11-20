#include <QApplication>
#include "glwidget.h"
#include "vue_opengl.h"
#include "Oscillateur.h"
#include "Ressort.h"
#include "Pendule.h"
#include "OscillateurDouble.h"
#include "EspacePhase.h"
#include "DeuxRessorts.h"
#include "PenduleRessort.h"
#include "ChariotPenduleRessort.h"
#include "PenduleTorsion.h"
#include "PendulesRelierRessort.h"
using namespace std;

int main(int argc, char* argv[])
{

    VueOpenGL vue; //un support quelconque, juste pour initialiser les oscillateurs

    //on definit les oscillateurs
    Ressort* r1p(new Ressort(0.66, 0.5, 0.15, Vecteur(0.8, 0, 0.6), Vecteur(0, 0, 0), &vue, Vecteur(0,0,0), Vecteur(0,0,0)));
    (*r1p).Parametre(0.18*(*r1p).A() + (*r1p).O());

    std::vector<double> theta = { 3.14 / 2 };
    std::vector<double> thetaP = {0};
    Pendule* p1p(new Pendule(0.445, 0.1,1, Vecteur(0, 0, 0), &vue, Vecteur(theta), Vecteur(thetaP)));

    std::vector<double> parametres = { 3.14 / 2, 0 };
    std::vector<double> vitesses = { 0, 3 };

    OscillateurDouble* o1p(new OscillateurDouble(10,10,1,1, Vecteur(0, 0, 0), &vue, Vecteur(parametres), Vecteur(vitesses)));

    vector<double> v = {1,2};
    vector<double> v2 = {1,3};
    DeuxRessorts* dr1p(new DeuxRessorts(10.0, 5.0, 3.0, 4.0,5.0,1.0,2.0,3.0,3.0, Vecteur(v), Vecteur(v2), Vecteur(1,0,0), &vue) );

    PenduleTorsion* pt1p(new PenduleTorsion(10,3,2,1,4,Vecteur(theta), Vecteur(1), &vue));
    ChariotPenduleRessort* c1p(new ChariotPenduleRessort(1,2,2,3,2,2,Vecteur(v), Vecteur(v2), &vue) );
    PenduleRessort* pr1p(new PenduleRessort(1,1,2,Vecteur(0,2,3), Vecteur(0,0,0), &vue));

    vector<double> v3 = {3.14/2,3.14/2};
    vector<double> v4 = {0,0};
    PendulesRelierRessort* prr1p(new PendulesRelierRessort(1,1,3,2,1.5,1.5,1,0.75, Vecteur(v3), Vecteur(v4), &vue));


    QApplication a(argc, argv);

    //les differents oscillateurs qu'on peut mettre dans la collection de systeme : r1p, p1p, o1p, dr1p, pt1p, c1p, pr1p
    GLWidget w(std::vector<Oscillateur*> { p1p, r1p, p1p, o1p, dr1p, pt1p, c1p, pr1p}); //le widget qui va dessiner le systeme
    w.show();


    EspacePhase e(p1p, &vue);
    GLWidget w2(e);                     //le widget qui va dessiner l'espace des phases
    w2.show();

    return a.exec();
}
