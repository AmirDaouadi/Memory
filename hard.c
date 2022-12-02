#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"timer.h"

void difficile(void) {
    int i, j, t, used, r, l, c;
    int* tab = malloc(sizeof(int) * 64);
    char *file = (char*)malloc(30 * sizeof(char));
    size_t k, m;
    srand(time(NULL));
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

    for(i = 0; i < 32;) {
        r = rand() % 60 + 1;
        used = 0;

        for (j = 0; j < i; j++) {
            if(tab[j] == r) {
                used = 1;
                break;
            }
        }
    
        if (!used) {
            tab[i] = r;
            i++;
        }
    }

    for (i = 0; i < 32; i++) {
        tab[i + 32] = tab[i];
    }

    for (k = 0; k < 64 - 1; k++) {
        m = k + rand() / (RAND_MAX / (64 - k) + 1);
        t = tab[m];
        tab[m] = tab[k];
        tab[k] = t;
    }  
        i=0;
    for (unsigned int l = 0; l < 8; l += 1) {
        for (unsigned int c = 0; c < 8; c += 1) {
            DessinerRectangle( 340 + (c * 85)+5, 35 + (l * 85)+15 , 75 , 75 );
            sprintf(file, "pp/hard//%d.jpg", tab[i]);
            ChargerImage(file, 340 + (c * 85)+5, 35 + (l * 85)+5 , 0, 0, 75, 75);
            i++;
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
    difficile();
    return EXIT_SUCCESS;
}
*/