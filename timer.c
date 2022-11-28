#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define delta 1000000L

unsigned long timer(void) {
    return Microsecondes();
}
Microsecondes();

void maj_timer(unsigned long temps) {
    int secondes = ((Microsecondes() - temps) / delta);
    int minutes = 0;
    char texte[15];
        
    while (secondes >= 60) {
        minutes += 1;
        secondes -= 60;
    }

    ChoisirEcran(3);
    EffacerEcran(CouleurParComposante(54, 57, 63));
    ChoisirCouleurDessin(CouleurParNom("white"));
    snprintf(buf, 100, "temps : %02d:%02d", minutes, secondes);
    EcrireTexte(20, 20, buf, 1);
    CopierZone(3, 0, 0, 0, 150, 30, 0, 0);
    ChoisirEcran(0);
}