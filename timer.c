#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define DELTA 1000000L

void maj_timer(unsigned long start) {
    unsigned int secondes = ((Microsecondes() - start) / DELTA);
    unsigned int minutes = 0;
    char buf[100];
        
    while (secondes >= 60) {
        minutes += 1;
        secondes -= 60;
    }

    ChoisirEcran(3);
    ChargerImageFond("./pp/ciel.jpg");
    ChoisirCouleurDessin(CouleurParNom("black"));
    snprintf(buf, 100, "Temps : %02d:%02d", minutes, secondes);
    EcrireTexte(570, 20, buf, 1);
    CopierZone(3, 0, 570, 0, 150, 30, 570, 0);
    ChoisirEcran(0);
}

unsigned long timer(unsigned long start) {
    start = Microsecondes() - start;
    maj_timer(start);
    return start;
}

unsigned long end_timer(unsigned long start) {
    return Microsecondes()-start;
}