#include<stdlib.h>
#include<graph.h>
#include"easy.h"
#include"medium.h"
#include"hard.h"



typedef struct {
    int x,y,L,H;
} Zone;
 
 /*Check si une position (x,y) se trouve dans la zone; retourne 1 si dedans, sinon 0.*/
int checkzone(Zone z, int x, int y) {
    return x >= z.x && x <= z.x + z.L && y >= z.y && y <= z.y + z.H;
}
void dessinerbouton(Zone z, char* texte, couleur couleurtexte, int tailletexte) {
    ChoisirCouleurDessin(couleurtexte);
    EcrireTexte(z.x, 
        z.y + z.H / 2 + TailleSupPolice(tailletexte) / 2,
         texte, tailletexte);
}

int main(void) {
  int boucle = 1;
  Zone easy = {100,350, 150, 75};
  Zone medium = {100,450, 150, 75};
  Zone hard = {100,550, 150, 75};
  Zone quitter = {20,675, 150, 75};

  InitialiserGraphique(); 
  CreerFenetre(0,0,1250,750);
  ChargerImageFond("./pp/cars.jpg");
  EcrireTexte (560,100,"Jeu de paire",2);
  EcrireTexte (100,250,"Choisir un niveau",2);
  int spriteEtoile = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile,225,365);
  int spriteEtoile2 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile2,235,465);
  int spriteEtoile3 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile3,285,465);
    int spriteEtoile4 = ChargerSprite("./pp/etoile.png");
  AfficherSprite(spriteEtoile4,235,565);
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
      if(checkzone(easy, _X, _Y)) {
        facile();
      }
      if(checkzone(medium, _X, _Y)) {
        moyen();
      }
      if(checkzone(hard, _X, _Y)) {
        difficile();
      }
      if(checkzone(quitter, _X, _Y)) {
        boucle = 0;
      }

    }
  
    
  }

  FermerGraphique();
  return EXIT_SUCCESS;
}