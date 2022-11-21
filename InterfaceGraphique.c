#include<stdlib.h>
#include<graph.h>

int main(void) {
InitialiserGraphique();
CreerFenetre(0,0,1920,1080 );
  ChargerImageFond("./pp/cars.jpg");
Touche();
FermerGraphique();

return EXIT_SUCCESS;
}
