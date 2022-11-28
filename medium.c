#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"timer.h"

void moyen(void) {
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

    for (unsigned int l = 0; l < 4; l += 1) {
        for (unsigned int c = 0; c < 4; c += 1) {
            DessinerRectangle( 385 + (c * 120)+10, 135 + (l * 120)+10 , 100 , 100 );
        }
    }

    unsigned long chrono = timer(0);

    while (1) {
        maj_timer(chrono);
    }

    Touche();
}
/*
int main (void) {
    InitialiserGraphique();
    CreerFenetre(0 , 0 , 1250 , 750);
    moyen();
    return EXIT_SUCCESS;
}
*/