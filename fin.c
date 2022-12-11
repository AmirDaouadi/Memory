#include<stdlib.h>
#include<graph.h>
#include"InterfaceGraphique.h"

void fin(void) {
  int boucle = 1;
  hitbox quitter = {20, 5, 150, 75};

  ChargerImageFond("./pp/fin.jpg");
  EcrireTexte (875,250,"Tu es meilleur",1);
  int spriteEtoile = ChargerSprite("./pp/trophe.png");
  AfficherSprite(spriteEtoile,875,325);
  int spriteEtoile1 = ChargerSprite("./pp/trophe.png");
  AfficherSprite(spriteEtoile1,65,270);
  
  dessinerbouton(quitter, "Quitter", CouleurParNom("red"), 2);

  while (boucle) {
    SourisPosition();
    if (SourisCliquee()) {
      if (check_hitbox(quitter, _X, _Y)) boucle = 0;
    }
  }

  LibererSprite(spriteEtoile);
  LibererSprite(spriteEtoile1);
}