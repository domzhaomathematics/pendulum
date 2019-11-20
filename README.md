# pendulum
Simulation of many types of 1D and 2D pendulums, springs and different systems built with them (Coupled pendulums, Coupled springs, pendulum+spring,etc) using 3 different numerical analysis algorithms(RK, Euler-Cromer, Newmark) and implementing 23 classes with different inheritence scheme following the good practices of object oriented programming. There is also the graphical component of the project to show the simulation in real-time using QT 3.0.1. To do so , we needed to create the graphical shapes (for the masses) and define the movements in a 3D space.

In this repo, there are all the files necessary to run the simulation. First of all, in the tests folder, there are all the .cc and .h files implementation of the classes. In the exercice_p10 folder, there are all the graphical components of the project.We also take advantage of the c++ language and extensively use pointers and templates. All the MakeFiles are provided. 

To run the the text simulation , you need to run the exercicep9.cc file in /exercice_P10/text/.
To run the graphical simulation, after downloading QT 3.0.1 , you need to run 

The project is done in french, so all the conception diagram,documentation, journal, code is in french.


![Alt text](https://github.com/domzhaomathematics/pendulum/blob/master/images/CONCEPTION/CONCEPTION-1.png)
![Alt text](https://github.com/domzhaomathematics/pendulum/blob/master/images/CONCEPTION/CONCEPTION-2.png)

Classes description

Tout en haut de hiérarchie, nous avons la classe abstraite Dessinable. Elle prend un pointeur de la classe SupportAdessin comme attribut et est doté d’une méthode virtuelle pure : dessine(), qui permettra éventuellement de dessiner les oscillateurs. La classe SupportADessin est une classe abstraite avec une fonction virtuelle pure ‘’dessine() ‘’ qui prend comme argument chaque type d’oscillateur.

La classe Oscillateur hérite de dessinable, donc tout Oscillateur est un Dessinable . Elle redéfinie la méthode dessine() et a comme attribut un Vecteur nommé paramètre et un autre nommée vitesse. L classe Vecteur est une classe définie par nous qui permet de créer des vecteurs à n-dimensions. Oscillateur a aussi une fonction f() qui retourne le Vecteur accélération de celui-ci (dépend pour chaque type d’oscillateur).
Les classes Pendule, Ressort et PenduleTorsion sont des oscillateurs avec un paramètre de une dimension et héritent de la classe Oscillateur. Pour chacun de ces pendules on redéfinie la méthode f() pour leurs donner l’accélération correcte(décrite dans le complément mathématique). La classe OscillateurDouble est un pendule double avec un paramètre de deux dimensions et hérite aussi directement de Oscillateur. Tous les autres Oscillateurs couplés héritent directement de Oscillateur.

Par la suite, nous avons crée la classe Systeme qui est un Dessinable (hérite de Dessinable) qui a un tableau dynamique de pointeur sur des Oscillateurs. Systeme a un méthode evolue() qui lui permet de faire évoluer tous les oscillateurs dans son tableau dynamique et elle redéfinie la méthode dessine() comme tous les Oscillateurs. C’est en gros un sytème d’oscillateurs.

La classe EspacePhase Hérite de Dessinable et a comme attribut un Oscillateur. Sa méthode dessine permet de dessiner l’Espace des phases de son Oscillateur attribut.
Finalement il y a la classe constante qui définit le Vecteur g (gravité) qui sera utiliser partout dans le code.
Passons à la partie simulation du projet. Nous avons la classe TextViewer qui hérite de SupportADessin et qui permet de faire la simulation texte de tous les dessinables. La classe VueOpenGl hérite aussi de SupportADessin et permet de faire la simulation graphique des Dessinables.

La classe GlWidget a un VueOpenGl comme attribut et permet d’affiche la simulation graphique sur une fenêtre. La classe GlSphere est une classe à part qui permet de dessiner des sphères.
Finalement, nous avons la classe abstraite Integrateur avec la méthode virtuelle pure evolue(). La classe IntegrateurRK, IntegrateurEulerCromer et IntegrateurNewmark héritent tous de la classe Integrateur et redéfinissent la méthode evolue() chacun de leurs façon propre. Les intégrateurs permettent de simuler le mouvement en donnant la nouvelle position des Oscillateurs à chaque instant t.


