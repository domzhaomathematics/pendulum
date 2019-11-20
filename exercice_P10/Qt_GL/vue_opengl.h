#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "SupportADessin.h"
#include "glsphere.h"

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Oscillateur const&) override;
  virtual void dessine(Pendule const&) override;
  virtual void dessine(Ressort const&) override;
  virtual void dessine(Systeme const&) override;
  virtual void dessine(OscillateurDouble const& a_dessiner) override;
  virtual void dessine(EspacePhase const& a_dessiner) override;
    virtual void dessine(DeuxRessorts const&) override;
    virtual void dessine(PenduleTorsion const&) override;
    virtual void dessine(ChariotPenduleRessort const&) override;
    virtual void dessine(PenduleRessort const&) override;
    virtual void dessine(PendulesRelierRessort const&) override;


  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineSphere(QMatrix4x4 const& point_de_vue, double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);


 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  GLSphere sphere;

  // Caméra
  QMatrix4x4 matrice_vue;
};

#endif
