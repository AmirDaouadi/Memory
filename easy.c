#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"timer.h"
#include"InterfaceGraphique.h"
#include"fin.h"

carte creation_carte_easy(int ligne, int colonne, int fichier) {
    char image[20];
    sprintf(image, "pp/easy/%d.jpg", fichier);
    ChargerImage(image, 330 + (colonne * 295) + 15, 50 + (ligne * 295) + 15 , 0, 0, 265, 265);
    hitbox h = {330 + (colonne * 295) + 15, 50 + (ligne * 295) + 15, 265, 265};
    carte c = {h, 0, 0, fichier};
    return c;
}

void facile(void) {
    int tab[4], i, r, used, j, t, ligne, colonne;
    int ancienne_carte_ligne = -1;
    int ancienne_carte_colonne = -1;
    unsigned long pause;
    size_t k, m;
    carte tableau_carte[2][2];
    carte c;
    srand(time(NULL));
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirEcran(1);
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirEcran(0);
    ChoisirCouleurDessin(CouleurParNom("black"));

    for (i = 0; i < 2;) {
        r = rand() % 60 + 1;
        used = 0;

        for (j = 0; j < i; j++) {
            if (tab[j] == r) {
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
    ChoisirEcran(2);
    ChargerImage("pp/easy/carte.jpg", 345, 65, 0, 0, 265, 265);
    ChoisirEcran(1);
    for (ligne = 0; ligne < 2; ligne += 1) {
        for (colonne = 0; colonne < 2; colonne += 1) {
            tableau_carte[ligne][colonne] = creation_carte_easy(ligne, colonne, tab[i]);
            CopierZone(2, 0, 345, 65, 265, 265, 330 + (colonne * 295) + 15, 50 + (ligne * 295) + 15);
            i++;
        }
    }
    ChoisirEcran(0);

    unsigned long chrono = timer(0);
    int nombre_cartes_trouvees = 0;
    while (nombre_cartes_trouvees < 4) {
        maj_timer(chrono);

        SourisPosition();
        if (SourisCliquee()) {
            for (ligne = 0; ligne < 2; ligne += 1) {
                for (colonne = 0; colonne < 2; colonne += 1) {
                    if (check_hitbox(tableau_carte[ligne][colonne].hitbox, _X, _Y) && !tableau_carte[ligne][colonne].affichee && !tableau_carte[ligne][colonne].trouvee) {
                        CopierZone(1, 0, tableau_carte[ligne][colonne].hitbox.positionX, tableau_carte[ligne][colonne].hitbox.positionY, 265, 265, tableau_carte[ligne][colonne].hitbox.positionX, tableau_carte[ligne][colonne].hitbox.positionY);
                        tableau_carte[ligne][colonne].affichee = 1;
                        if (ancienne_carte_ligne != -1) {
                            if (!tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].trouvee && tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].affichee && (tableau_carte[ligne][colonne].hitbox.positionX != tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].hitbox.positionX || tableau_carte[ligne][colonne].hitbox.positionY != tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].hitbox.positionY)) {
                                if (tableau_carte[ligne][colonne].numero == tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].numero) {
                                    tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].trouvee = 1;
                                    tableau_carte[ligne][colonne].trouvee = 1;
                                    nombre_cartes_trouvees += 2;
                                } else {
                                    pause = Microsecondes() + 1000000;
                                    while (Microsecondes() < pause);
                                    while (SourisCliquee());
                                    CopierZone(2, 0, 345, 65, 265, 265, tableau_carte[ligne][colonne].hitbox.positionX, tableau_carte[ligne][colonne].hitbox.positionY);
                                    tableau_carte[ligne][colonne].affichee = 0;
                                    CopierZone(2, 0, 345, 65, 265, 265, tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].hitbox.positionX, tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].hitbox.positionY);
                                    tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].affichee = 0;
                                }
                            }
                        }
                        ancienne_carte_ligne = ligne;
                        ancienne_carte_colonne = colonne;
                    }
                }
            }
        }

        if (ToucheEnAttente() && Touche()==XK_t){
            chrono = end_timer(chrono);
            CopierZone(0, 4, 330, 50, 590, 650, 330, 50);
            CopierZone(1, 0, 330, 50, 590, 650, 330, 50);
            while (Touche() != XK_t);
            CopierZone(4, 0, 330, 50, 590, 650, 330, 50);
            while (SourisCliquee());
            chrono = timer(chrono);
        }
    }
    fin();
}