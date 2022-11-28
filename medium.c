#include<stdio.h>
#include<stdlib.h>
#include<graph.h>

void medium(void) {
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

    for (unsigned int l = 0; l < 4; l += 1) {
        for (unsigned int c = 0; c < 4; c += 1) {
            DessinerRectangle( 385 + (c * 120)+10, 135 + (l * 120)+10 , 100 , 100 );
        }
    }
    
    Touche();
}
int main (void) {
    InitialiserGraphique();
    CreerFenetre(0 , 0 , 1250 , 750);
    medium();
    return EXIT_SUCCESS;
}