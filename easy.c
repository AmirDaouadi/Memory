#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

void easy(void) {
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

    for (unsigned int l = 0; l < 2; l += 1) {
        for (unsigned int c = 0; c < 2; c += 1) {
            DessinerRectangle( 330 + (c * 295)+15, 50 + (l * 295)+15 , 265 , 265 );
        }
    }
    
    Touche();
}
int main (void) {
    InitialiserGraphique();
    CreerFenetre(0 , 0 , 1250 , 750);
    easy();
    return EXIT_SUCCESS;
}