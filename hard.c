#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"timer.h"

void hard(void) {
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

    for (unsigned int l = 0; l < 8; l += 1) {
        for (unsigned int c = 0; c < 8; c += 1) {
            DessinerRectangle( 285 + (c * 85)+5, 35 + (l * 85)+5 , 75 , 75 );
        }
    }
    
    Touche();
}
int main (void) {
    InitialiserGraphique();
    CreerFenetre(0 , 0 , 1250 , 750);
    hard();
    return EXIT_SUCCESS;
}