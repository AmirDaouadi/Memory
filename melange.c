#include <time.h>
#include "affichageMain.h"
#define TAILLE_EASY 4
#define TAILLE_MEDIUM 6
#define TAILLE_HARD 8
#define NB_CARTES_UNIQUES 32
#define N 64 
void initialiserVisibilite(Carte* tab, int T){
    int i;
    /* Les cartes sont retournées, càd tableauCartes[i].visibilite==1 */
    for(i=0;i<T*T;i++){
        tab[i].visibilite = 1;
    }
}
void generationIds(int* tab, int T){
    int i, im=0, randomN, randomM;
    for(i=0;i<NB_CARTES_UNIQUES && im < T*T/2;i++){
        randomN = NB_CARTES_UNIQUES - i;
        randomM = T*T/2 - im;
        if(rand()%randomN<randomM){
            tab[im] = i + 1;
            tab[T*T/2+im] = i + 1;
            im++;    
        }
    }
}
void affectationAleatoirePosition(Carte* tableauCartes,int*  tableauTmpIds, int T){
    int j, randomPosition;
    for(j=0;j<T*T;j++){
        randomPosition = rand()%(T*T);
        while(1){
            if(tableauTmpIds[randomPosition] != -1){
                tableauCartes[j].id = tableauTmpIds[randomPosition];
                tableauTmpIds[randomPosition] = -1;
                break;
            } else {
                randomPosition = rand()%(T*T);
            }
        }
    }
}
void affichage(Carte* tab, int T){
    int i, j;
    for(j=0;j<T;j++){
        for (i=0;i<T;i++) {
            printf("+------");
        }
            
        printf("+\n");
        for(i=0;i<T;i++) {
            printf("| %3d  ", tab[j*T+i].id);
        
        }
        printf("|\n");
    }
    for (i=0;i<T;i++) {
        printf("+------");
    }
    printf("+\n");
}
int main(void){
    /*fonction qui nous donne la difficulté*/
    int T = TAILLE_HARD; 
    int* tableauTmpIds = malloc(T*T*sizeof(int));
    Carte* tableauCartes = malloc(T*T*sizeof(Carte));
    srand(time(NULL));
    
    /* Initialisation */
    initialiserVisibilite(tableauCartes, T);
    /* Generation des ids par paire dans un tableau tampon voir algo de Knuth */
    generationIds(tableauTmpIds,T);
    /* Affectation dans le tableauCartes des ids par paire */
    affectationAleatoirePosition(tableauCartes, tableauTmpIds, T);    
    /* Affichage des valeurs dans un beau tableau */
    affichage(tableauCartes, T);
    return 0;
}