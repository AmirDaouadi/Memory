#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

typedef struct {
    int positionX, positionY, longueur, hauteur;
} hitbox;

typedef struct {
    hitbox hitbox;
    int affichee, trouvee, numero;
} carte;
 
int check_hitbox(hitbox h, int x, int y);

void dessinerbouton(hitbox h, char* texte, couleur couleurtexte, int tailletexte);

#endif