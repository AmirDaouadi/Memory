#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"timer.h"

void moyen(void) {
    int i, j, t, used, r, l, c;
    int* tab = malloc(sizeof(int) * 8);
    char *file = (char*)malloc(30 * sizeof(char));
    size_t k, m;
    srand(time(NULL));
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

    for(i = 0; i < 8;) {
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

    for (i = 0; i < 8; i++) {
        tab[i + 8] = tab[i];
    }

    for (k = 0; k < 16 - 1; k++) {
        m = k + rand() / (RAND_MAX / (16 - k) + 1);
        t = tab[m];
        tab[m] = tab[k];
        tab[k] = t;

    }

    i=0;
    for (unsigned int l = 0; l < 4; l += 1) {
        for (unsigned int c = 0; c < 4; c += 1) {
            DessinerRectangle( 390 + (c * 120)+10, 45 + (l * 240)+10 , 100 , 100 );
            sprintf(file, "pp/medium/%d.jpg", tab[i]);
            ChargerImage(file, 390 + (c * 120)+10, 45 + (l * 240)+10 , 0, 0, 100, 100);
            i++;
        }
    }


    unsigned long chrono = timer(0);

    while (1) {
        maj_timer(chrono);
    }

    Touche();
}