#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Systeme.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Oscillateur.h"
#include "Vecteur.h"
#include "Integrateur.h"
#include <vector>
#include "OscillateurDouble.h"
#include "EspacePhase.h"
#include "DeuxRessorts.h"
#include "PenduleRessort.h"
#include "ChariotPenduleRessort.h"
#include "PenduleTorsion.h"
#include "PendulesRelierRessort.h"
#include "constantes.h"
#include <cmath>
using namespace std;

// ======================================================================

void VueOpenGL::dessine(Oscillateur const& a_dessiner) {}
void VueOpenGL::dessine(PendulesRelierRessort const& a_dessiner)
{
    QMatrix4x4 matrice;
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    QMatrix4x4 reference(matrice); //pour revenir a l'origine

    std::vector<double> vec(a_dessiner.Parametre().Composantes());  //les composantes du parametre du ressort relies aux pendules

    glBegin(GL_LINES); //on fait des lignes qui representent le ressort entre les masse
    prog.setAttributeValue(SommetId, -a_dessiner.D()*0.5,0.0,0.0);
    prog.setAttributeValue(SommetId, -a_dessiner.L1()*sin(vec[0]), 0.0, -a_dessiner.L1()*cos(vec[0]));
    prog.setAttributeValue(SommetId, a_dessiner.D()*0.5,0.0,0.0);
    prog.setAttributeValue(SommetId, a_dessiner.L2()*sin(vec[1]), 0.0, -a_dessiner.L2()*cos(vec[1]));
    prog.setAttributeValue(SommetId, -a_dessiner.A1()*sin(vec[0]), 0.0, -a_dessiner.A1()*cos(vec[0]));
    prog.setAttributeValue(SommetId, a_dessiner.A2()*sin(vec[1]), 0.0, -a_dessiner.A2()*cos(vec[1]));
    glEnd();

    //dessin des masses, les doubles determine la couleur
    matrice.translate(-a_dessiner.L1()*sin(vec[0]), 0.0, -a_dessiner.L1()*cos(vec[0]));
    matrice.scale(0.1); //une sphere plus petite
    dessineSphere(matrice, 0.0, 1.0, 0.0);
    matrice = reference;
    matrice.translate(a_dessiner.L2()*sin(vec[1]), 0.0, -a_dessiner.L2()*cos(vec[1]));
    matrice.scale(0.1);
    dessineSphere(matrice, 0.0, 1.0,0.0);
}
void VueOpenGL::dessine(DeuxRessorts const& a_dessiner)
{
    QMatrix4x4 matrice;
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    QMatrix4x4 reference(matrice); //pour revenir a l'origine
    std::vector<double> vec(a_dessiner.Parametre().Composantes());  //les composantes du parametre du ressort double
    Vecteur v2(a_dessiner.A()*(a_dessiner.L1() + vec[0]));                              //position de la premiere masse (vectorielle)
    Vecteur v3(a_dessiner.A()*(a_dessiner.L1() + a_dessiner.L2() + vec[1]));            //position de la deuxieme masse (vectorielle)
    Vecteur v4(a_dessiner.A()*(a_dessiner.L1() + a_dessiner.L2() + a_dessiner.L3()));   //position de la fin du ressort 3 (vectorielle)

    glBegin(GL_LINES); //on fait des lignes qui representent le ressort entre les masse
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, v2.Composantes()[0], v2.Composantes()[1], v2.Composantes()[2]);
    prog.setAttributeValue(SommetId, v2.Composantes()[0], v2.Composantes()[1], v2.Composantes()[2]);
    prog.setAttributeValue(SommetId, v3.Composantes()[0], v3.Composantes()[1], v3.Composantes()[2]);
    prog.setAttributeValue(SommetId, v3.Composantes()[0], v3.Composantes()[1], v3.Composantes()[2]);
    prog.setAttributeValue(SommetId, v4.Composantes()[0], v4.Composantes()[1], v4.Composantes()[2]);
    glEnd();

    //dessin des masses, les doubles determine la couleur
    matrice.translate(v2.Composantes()[0], v2.Composantes()[1], v2.Composantes()[2]);
    matrice.scale(0.1); //une sphere plus petite
    dessineSphere(matrice, 0.0, 1.0, 0.0);
    matrice = reference;
    matrice.translate(v3.Composantes()[0], v3.Composantes()[1], v3.Composantes()[2]);
    matrice.scale(0.1);
    dessineSphere(matrice, 0.0, 1.0,0.0);
}
void VueOpenGL::dessine(PenduleTorsion const& a_dessiner)
{
    QMatrix4x4 matrice;
    QMatrix4x4 reference(matrice);
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    std::vector<double> vec((a_dessiner.Parametre()).Composantes()); //Les composantes du parametre du pendule torsion
    glBegin(GL_LINES); //les lignes represente la barre et le fil
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, 0.0, 0.0, -a_dessiner.LF());
    prog.setAttributeValue(SommetId, a_dessiner.L()*0.5*cos(vec[0]), a_dessiner.L()*0.5*sin(vec[0]), -a_dessiner.LF());
    prog.setAttributeValue(SommetId, -a_dessiner.L()*0.5*cos(vec[0]), -a_dessiner.L()*0.5*sin(vec[0]), -a_dessiner.LF());
    glEnd();
    //on dessine des petites masses au bout
    matrice.translate(a_dessiner.L()*0.5*cos(vec[0]), a_dessiner.L()*0.5*sin(vec[0]), -a_dessiner.LF());
    matrice.scale(0.05); //une sphere plus petite
    dessineSphere(matrice, 0.0, 1.0, 1.0);
    matrice = reference;
    matrice.translate(-a_dessiner.L()*0.5*cos(vec[0]), -a_dessiner.L()*0.5*sin(vec[0]), -a_dessiner.LF());
    matrice.scale(0.05);
    dessineSphere(matrice, 0.0, 1.0,1.0);
}
void VueOpenGL::dessine(ChariotPenduleRessort const& a_dessiner)
{
    QMatrix4x4 matrice;
    QMatrix4x4 reference(matrice);
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    std::vector<double> vec((a_dessiner.Parametre()).Composantes()); //Les composantes du parametre du chariot

    glBegin(GL_LINES); //les lignes representent le chariot
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, vec[0], 0.0, 0.0);
    prog.setAttributeValue(SommetId, vec[0], 0.0, 0.0);
    prog.setAttributeValue(SommetId, a_dessiner.L()*sin(vec[0]), 0.0, -a_dessiner.L()*cos(vec[0]));
    glEnd();
//dessin de la masse
    matrice.translate(vec[0],0.0,0.0);
    matrice.scale(0.1);
    dessineSphere(matrice, 1.0,0.0,1.0);

    matrice = reference;
    matrice.translate(a_dessiner.L()*sin(vec[0]), 0.0, -a_dessiner.L()*cos(vec[0]));
    matrice.scale(0.1);
    dessineSphere(matrice, 1.0,0.0,1.0);
}
void VueOpenGL::dessine(PenduleRessort const& a_dessiner)
{
    QMatrix4x4 matrice;
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    std::vector<double> vec(a_dessiner.Parametre().Composantes()); //composantes du parametre du ressort

    glBegin(GL_LINES); //on dessine le ressort
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, vec[0], vec[1], vec[2]);
    glEnd();
//dessin de la masse
    matrice.translate(vec[0], vec[1], vec[2]);
    matrice.scale(0.1);
    dessineSphere(matrice, 0.0, 1.0,1.0);
}
void VueOpenGL::dessine(EspacePhase const& a_dessiner)
{

    QMatrix4x4 matrice;
    QMatrix4x4 reference(matrice);

    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    if (a_dessiner.Espace().size() > 1)  //pour ne pas avoir de segmentation fault car on utilise i-1
    {
        prog.setAttributeValue(CouleurId, 1.0,1.0,1.0);
        for (size_t i(1); i < (a_dessiner.Espace().size()); i++)
        {
            matrice = reference;
            glBegin(GL_LINE_STRIP); //on fait un trait entre chaque point de l'espace des phases
            prog.setAttributeValue(SommetId, a_dessiner.Espace()[i-1][0], a_dessiner.Espace()[i-1][1], 0.0);
            prog.setAttributeValue(SommetId, a_dessiner.Espace()[i][0], a_dessiner.Espace()[i][1], 0.0);



        }
        glEnd();

    }


}

void VueOpenGL::dessine(Systeme const& a_dessiner)
{
    QMatrix4x4 matrice;
    dessineAxes(matrice); //on dessine un repere
    vector<Oscillateur*> v(a_dessiner.Collection());
    for (size_t i(0); i<v.size(); i++) //on dessine chaque element du systeme
    {
       (v[i])->dessine();
        prog.setUniformValue("vue_modele", matrice_vue * matrice);

    }

}

//le graphe pour faire l'energie du pendule dans sa fonction dessine
vector<vector<double>> graph;
double t(0);
//il faut le definier ici pour qu'il ne disparait pas apres chaque dessin
//(on sait que c'est pas super au niveau d'implementation, desole, mais c'etait la seule facon rapide de le faire)

void VueOpenGL::dessine(Pendule const& a_dessiner)
{
    QMatrix4x4 matrice;
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    std::vector<double> vec((a_dessiner.Parametre()).Composantes()); //Les composantes du parametre du pendule
    glBegin(GL_LINES); //les lignes represente le pendule qui va de l'origine a la position de la masse
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, sin(vec[0])*a_dessiner.L(), 0.0, -cos(vec[0])*a_dessiner.L());
    glEnd();
//dessin de la masse
    matrice.translate(sin(vec[0])*a_dessiner.L(),0.0, -cos(vec[0])*a_dessiner.L());
    matrice.scale(0.1);
    dessineSphere(matrice, 1.0,0.0,0.0);
    cout << "dans systeme : " << a_dessiner.Parametre().Composantes()[0] << endl;

    //on ajoute ici une grille energie en fonction du temps, pour un pendule, il va s'afficher a partir de la position du pendule
    graph.push_back({ a_dessiner.L()*cos(a_dessiner.Parametre().Composantes()[0])*a_dessiner.M()*sqrt(g*g),0.5*a_dessiner.M()*a_dessiner.Vitesse().Composantes()[0] * a_dessiner.L()*a_dessiner.Vitesse().Composantes()[0] * a_dessiner.L(),
    a_dessiner.L()*cos(a_dessiner.Parametre().Composantes()[0])*a_dessiner.M()*sqrt(g*g) + 0.5*a_dessiner.M()*a_dessiner.Vitesse().Composantes()[0] * a_dessiner.L()*a_dessiner.Vitesse().Composantes()[0] * a_dessiner.L(),t });
    t += 0.01;
    for (size_t i(1); i < (graph.size()); i++)
    {
        glBegin(GL_LINES); //on fait un trait entre chaque point de l'energie
        prog.setAttributeValue(CouleurId, 1.0, 0.3,0.3); //orange
        prog.setAttributeValue(SommetId, graph[i-1][0], graph[i-1][3], 0.0);
        prog.setAttributeValue(SommetId, graph[i][0], graph[i][3], 0.0);

        prog.setAttributeValue(CouleurId, 1.0, 1.0,1.0); //blanc
        prog.setAttributeValue(SommetId, graph[i-1][1], graph[i-1][3], 0.0);
        prog.setAttributeValue(SommetId, graph[i][1], graph[i][3], 0.0);

        prog.setAttributeValue(CouleurId, 0.0, 1.0,1.0); //cyan
        prog.setAttributeValue(SommetId, graph[i-1][2], graph[i-1][3], 0.0);
        prog.setAttributeValue(SommetId, graph[i][2], graph[i][3], 0.0);



    }
    glEnd();
}

void VueOpenGL::dessine(OscillateurDouble const& a_dessiner)
{
    QMatrix4x4 matrice;
    QMatrix4x4 reference(matrice);
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    std::vector<double> vec((a_dessiner.Parametre()).Composantes()); //les composantes du parametre du pendule double
    glBegin(GL_LINES); //on dessine des lignes entre origine et premier masse, et premiere masse et deuxieme masse
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, sin(vec[0])*a_dessiner.L1(), 0.0, -cos(vec[0])*a_dessiner.L1());
    prog.setAttributeValue(SommetId, sin(vec[0])*a_dessiner.L1(), 0.0, -cos(vec[0])*a_dessiner.L1());
    prog.setAttributeValue(SommetId, (sin(vec[0])*a_dessiner.L1() + sin(vec[1])*a_dessiner.L2()), 0.0, (-cos(vec[0])*a_dessiner.L1()-cos(vec[1])*a_dessiner.L2()));
    glEnd();

    //dessin des masses
    matrice.translate(sin(vec[0])*a_dessiner.L1(), 0.0, -cos(vec[0])*a_dessiner.L1());
    matrice.scale(0.1);
    dessineSphere(matrice, 1.0,0.0,0.0);

    matrice = reference;
    matrice.translate((sin(vec[0])*a_dessiner.L1() + sin(vec[1])*a_dessiner.L2()), 0.0, (-cos(vec[0])*a_dessiner.L1()-cos(vec[1])*a_dessiner.L2()));
    matrice.scale(0.1);
    dessineSphere(matrice, 1.0,0.0,0.0);
}



void VueOpenGL::dessine(Ressort const& a_dessiner)
{
    QMatrix4x4 matrice;
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    std::vector<double> vec(a_dessiner.Parametre().Composantes()); //composantes du parametre du ressort

    glBegin(GL_LINES); //on dessine le ressort
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, vec[0], vec[1], vec[2]);
    glEnd();
//dessin de la masse
    matrice.translate(vec[0], vec[1], vec[2]);
    matrice.scale(0.1);
    dessineSphere(matrice, 0.0, 1.0,0.0);

}



// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  initializePosition();
  sphere.initialize();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
  matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}

// ======================================================================

void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}

// ======================================================================

void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 0.0,0.0, 0.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if(en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

  glEnd();
}
