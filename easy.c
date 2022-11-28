#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"timer.h"


void facile(void) {
    int random = 0, i;
    srand(time(NULL));
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

    for (i=0; i< 2; i++) {
        random = rand() % 60 + 1;
    }

    for (unsigned int l = 0; l < 2; l += 1) {
        for (unsigned int c = 0; c < 2; c += 1) {
            DessinerRectangle( 330 + (c * 295)+15, 50 + (l * 295)+15 , 265 , 265 );
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
    facile();
    return EXIT_SUCCESS;
}
*/