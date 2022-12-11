#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"easy.h"
#include"medium.h"
#include"hard.h"

typedef struct {
    int positionX, positionY, longueur, hauteur;
} hitbox;

typedef struct {
    hitbox hitbox;
    int affichee, trouvee, numero;
} carte;
 
int check_hitbox(hitbox h, int x, int y) {
    return x >= h.positionX && x <= h.positionX + h.longueur && y >= h.positionY && y <= h.positionY + h.hauteur;
}
void dessinerbouton(hitbox h, char* texte, couleur couleurtexte, int tailletexte) {
    ChoisirCouleurDessin(couleurtexte);
    EcrireTexte(h.positionX, h.positionY + h.hauteur / 2 + TailleSupPolice(tailletexte) / 2, texte, tailletexte);
}

int main(void) {
  int boucle = 1;
  hitbox easy = {100, 350, 150, 75};
  hitbox medium = {100, 450, 150, 75};
  hitbox hard = {100, 550, 150, 75};
  hitbox quitter = {20, 675, 150, 75};

  InitialiserGraphique();
  CreerFenetre(0, 0, 1250, 750);
  ChargerImageFond("./pp/cars.jpg");
  EcrireTexte (560, 100, "Jeu de paire", 2);
  EcrireTexte (100, 250, "Choisir un niveau", 2);
  int spriteEtoile = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile, 225, 365);
  int spriteEtoile2 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile2, 235, 465);
  int spriteEtoile3 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile3, 285, 465);
  int spriteEtoile4 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile4, 235, 565);
  int spriteEtoile5 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile5,285,565);
  int spriteEtoile6 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile6,335,565);

  dessinerbouton(easy, "Easy", CouleurParNom("black"), 2);
  dessinerbouton(medium, "Medium", CouleurParNom("black"), 2);
  dessinerbouton(hard, "Hard", CouleurParNom("black"), 2);
  dessinerbouton(quitter, "Quitter", CouleurParNom("red"), 2);

  while(boucle) {
    SourisPosition();

    if(SourisCliquee()){
      if(check_hitbox(easy, _X, _Y)) {
        facile();
        boucle = 0;
      }
      if(check_hitbox(medium, _X, _Y)) {
        moyen();
        boucle = 0;
      }
      if(check_hitbox(hard, _X, _Y)) {
        difficile();
        boucle = 0;
      }
      if(check_hitbox(quitter, _X, _Y)) {
        boucle = 0;
      }
    }
  }

  LibererSprite(spriteEtoile);
  LibererSprite(spriteEtoile2);
  LibererSprite(spriteEtoile3);
  LibererSprite(spriteEtoile4);
  LibererSprite(spriteEtoile5);
  LibererSprite(spriteEtoile6);

  FermerGraphique();
  return EXIT_SUCCESS;
}