#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define delta 1000000L

int main()
{
	InitialiserGraphique();
	CreerFenetre(0,0,800,500);
	unsigned long start = Microsecondes();
	
	char buf[100];
	while(1){
		
		EffacerEcran(CouleurParNom("white"));
		
		snprintf(buf, 100, "temps : %05d", (Microsecondes() - start) / 1000000);
		
		EcrireTexte(10,10, buf, 0);	
		
	}
	FermerGraphique();
}
