#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define delta 1000000L

void start_timer(void) {
    unsigned long int start = Microsecondes();
    unsigned int minute = 0;
    unsigned int a = 0;

    char buf[100];
    while(1){                
        unsigned long int seconde = ((Microsecondes() - start) / 1000000)-a;
        
        if (seconde>=60) {
            minute +=1;
            a += 60;
        }

        snprintf(buf, 100, "temps : %02d:%02d", minute, seconde);
        
        EcrireTexte(20,20, buf, 1);            
    }
}