#include<stdlib.h>
#include<graph.h>


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
  Zone hard = {100,550, 150, 75};
  Zone quitter = {20,5, 150, 75};

  InitialiserGraphique(); 
  CreerFenetre(0,0,1250,750);
  ChargerImageFond("./pp/fin.jpg");
  EcrireTexte (875,250,"Tu es meilleur",1);
  int spriteEtoile = ChargerSprite("./pp/trophe.png");
  AfficherSprite(spriteEtoile,875,325);
  int spriteEtoile1 = ChargerSprite("./pp/trophe.png");
  AfficherSprite(spriteEtoile1,65,270);
  
  dessinerbouton(hard, "Hard", CouleurParNom("black"), 2);
  dessinerbouton(quitter, "Quitter", CouleurParNom("red"), 2);

  while(boucle) {
    SourisPosition();

    if(SourisCliquee()){
      if(checkzone(hard, _X, _Y)) {
        boucle = 0;
      }
      if(checkzone(quitter, _X, _Y)) {
        boucle = 0;
      }

    }
  
    
  }

  FermerGraphique();
  return EXIT_SUCCESS;
}