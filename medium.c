#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"timer.h"
#include"InterfaceGraphique.h"
#include"fin.h"

carte creation_carte_medium(int ligne, int colonne, int fichier) {
    char image[20];
    sprintf(image, "pp/medium/%d.jpg", fichier);
    ChargerImage(image, 390 + (colonne * 120) + 10, 45 + (ligne * 180) + 10 , 0, 0, 100, 100);
    hitbox h = {390 + (colonne * 120) + 10, 45 + (ligne * 180) + 10, 100, 100};
    carte c = {h, 0, 0, fichier};
    return c;
}

void moyen(void) {
    int tab[16], i, r, used, j, t, ligne, colonne;
    int ancienne_carte_ligne = -1;
    int ancienne_carte_colonne = -1;
    unsigned long pause;
    size_t k, m;
    carte tableau_carte[4][4];
    carte c;
    srand(time(NULL));
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirEcran(1);
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirEcran(0);
    ChoisirCouleurDessin(CouleurParNom("black"));

    for (i = 0; i < 8;) {
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
    ChoisirEcran(2);
    ChargerImage("pp/medium/carte.jpg", 400, 55, 0, 0, 100, 100);
    ChoisirEcran(1);
    for (ligne = 0; ligne < 4; ligne += 1) {
        for (colonne = 0; colonne < 4; colonne += 1) {
            tableau_carte[ligne][colonne] = creation_carte_medium(ligne, colonne, tab[i]);
            CopierZone(2, 0, 400, 55, 100, 100, 390 + (colonne * 120) + 10, 45 + (ligne * 180) + 10);
            i++;
        }
    }
    ChoisirEcran(0);

    unsigned long chrono = timer(0);
    int nombre_cartes_trouvees = 0;
    while (nombre_cartes_trouvees < 16) {
        maj_timer(chrono);

        SourisPosition();
        if (SourisCliquee()) {
            for (ligne = 0; ligne < 4; ligne += 1) {
                for (colonne = 0; colonne < 4; colonne += 1) {
                    if (check_hitbox(tableau_carte[ligne][colonne].hitbox, _X, _Y) && !tableau_carte[ligne][colonne].affichee && !tableau_carte[ligne][colonne].trouvee) {
                        CopierZone(1, 0, tableau_carte[ligne][colonne].hitbox.positionX, tableau_carte[ligne][colonne].hitbox.positionY, 100, 100, tableau_carte[ligne][colonne].hitbox.positionX, tableau_carte[ligne][colonne].hitbox.positionY);
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
                                    CopierZone(2, 0, 400, 55, 100, 100, tableau_carte[ligne][colonne].hitbox.positionX, tableau_carte[ligne][colonne].hitbox.positionY);
                                    tableau_carte[ligne][colonne].affichee = 0;
                                    CopierZone(2, 0, 400, 55, 100, 100, tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].hitbox.positionX, tableau_carte[ancienne_carte_ligne][ancienne_carte_colonne].hitbox.positionY);
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
            CopierZone(0, 4, 390, 45, 590, 650, 390, 45);
            CopierZone(1, 0, 390, 45, 590, 650, 390, 45);
            while (Touche() != XK_t);
            CopierZone(4, 0, 390, 45, 590, 650, 390, 45);
            while (SourisCliquee());
            chrono = timer(chrono);
        }
    }
    fin();
}