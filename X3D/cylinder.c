#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void functionOfLife(int maxHeight, int floors, int nbPeak, int radius) {
  int height = 0;
  int heightBetweenEachFloor = maxHeight/floors;
  float x = 1;
  float y = 0;
  float angle = (2*M_PI/nbPeak);
  printf("ANGLE : %f\n", angle);
  printf("Cos(angle) = %f\n", cos(angle*2));
  for(int i=0; i<floors + 1; i++) {
    printf("------- DÉBUT ÉTAGE : %d ------\n", height/heightBetweenEachFloor);
    printf("HAUTEUR : %d\n", height);

    for(int j=0; j<nbPeak; j++){
      //printf("Valeur de j = %d\n", j);      
      printf("%f\t %d\t %f\n", x, height, y);
      x = radius * cos(angle * j);
      y = radius * sin(angle * j);
      //printf("x = %f , y = %f \n", x, y);
    }

    printf("-------- FIN DE L'ÉTAGE : %d -------\n", height/heightBetweenEachFloor);
    printf("====================\n");

    height += heightBetweenEachFloor;
  }

}

int main () {
  int maxHeight = 8;
  int floors = 1;
  int nbPeak = 6;

  functionOfLife(maxHeight, floors, nbPeak, 1);
  return 0;
}
