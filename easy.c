#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"timer.h"


void facile(void) {
    int i, j, t, used, r, l, c;
    int* tab = malloc(sizeof(int) * 4);
    char *file = (char*)malloc(30 * sizeof(char));
    size_t k, m;
    srand(time(NULL));
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));

     for(i = 0; i < 2;) {
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

    for (i = 0; i < 2; i++) {
        tab[i + 2] = tab[i];
    }

    for (k = 0; k < 4 - 1; k++) {
        m = k + rand() / (RAND_MAX / (4 - k) + 1);
        t = tab[m];
        tab[m] = tab[k];
        tab[k] = t;

    }

    i=0;
    for (unsigned int l = 0; l < 2; l += 1) {
        for (unsigned int c = 0; c < 2; c += 1) {
            DessinerRectangle( 330 + (c * 295)+15, 50 + (l * 295)+15 , 265 , 265 );
            sprintf(file, "pp/easy/%d.jpg", tab[i]);
            ChargerImage(file, 330 + (c * 295)+15, 50 + (l * 295)+15 , 0, 0, 265, 265);
            i++;
        }
    }

    unsigned long chrono = timer(0);

   while (1) {
        maj_timer(chrono);
    }
    Touche();


}
