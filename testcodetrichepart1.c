#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#define sec 1000000L


void AfficherCartes(Carte* tab, int T, int emplacementCarteX, int emplacementCarteY, int coteCarte){
	int i,j,tmpEmplacementCarteX=emplacementCarteX;
	char idString[5];
	for(i=0;i<T;i++){
		emplacementCarteX = tmpEmplacementCarteX;
		for(j=0;j<T;i++){
			if(tab[i*T+j].visibilite ==0){
			ChoisirCouleurDessin(r);
				sprintf(idString,"%d",tab[i*T+j}].id);
							/*tab[i*T+j}].id,idString,10);*/
				EcrireTexte(emplacementCarteX+1,emplacementCarteY+coteCarte,idString,2);}
			else{
				ChoisirCouleurDessin(b);
				RemplirRectangle(emplacementCarteX+1,emplacementCarteY+coteCarte+1,coteCarte+1);}
			emplacementCarteX = emplacementCarteX + coteCarte +6;}
  	emplacementCarteX = emplacementCarteX + coteCarte +6;}
}
    return EXIT_SUCCESS;
