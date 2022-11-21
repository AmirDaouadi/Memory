#include<stdlib.h>
#include<graph.h>

int main(void) {
  InitialiserGraphique();
  CreerFenetre(0,0,1250,750);
  ChargerImageFond("./pp/cars.jpg");
  EcrireTexte (560,100,"Jeu de paire",2);
  EcrireTexte (100,250,"Choisir un niveau",2);
  EcrireTexte (100,400,"Easy",2);
  int spriteEtoile = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile,225,365);
  EcrireTexte (100,500,"Medium",2);
  int spriteEtoile2 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile2,235,465);
  int spriteEtoile3 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile3,285,465);
  EcrireTexte (100,600,"Hard",2);
    int spriteEtoile4 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile4,235,565);
      int spriteEtoile5 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile5,285,565);
      int spriteEtoile6 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile6,335,565);
  

  Touche();
  FermerGraphique();
  return EXIT_SUCCESS;
}