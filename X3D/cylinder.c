#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void indexedFaceSet(int nbPeak, int floors) {
  int valeurCourante;
  int etageCourrant;
  int premiereVal;
  for (int j = 0; j<floors+1; j++) {
    etageCourrant = j;
    premiereVal = nbPeak*etageCourrant+j;
    for (int i=0; i < nbPeak; i++) {
      valeurCourante = i + premiereVal;
      if (i == nbPeak -1)
        printf("%d %d %d -1\n", premiereVal, valeurCourante+1, valeurCourante-nbPeak+2);
      else
        printf("%d %d %d -1\n", premiereVal, valeurCourante+1, valeurCourante+2);
    }
  }
}

void functionOfLife(int maxHeight, int floors, int nbPeak, float radius) {
  int height = 0;
  int heightBetweenEachFloor = maxHeight/floors;
  float x = 1;
  float y = 0;
  float angle = (2*M_PI/nbPeak);
  printf("ANGLE : %f\n", angle);
  printf("Cos(angle) = %f\n", cos(angle*2));

  for(int i=0; i<floors + 1; i++) {
    printf("0\t %d\t 0,\n", height);
    for(int j=0; j<nbPeak; j++){
      //printf("Valeur de j = %d\n", j);

      x = radius * cos(angle * j + M_PI/nbPeak);
      y = radius * sin(angle * j + M_PI/nbPeak);
      printf("%f\t %d\t %f,\n", x, height, y);
    }

    height += heightBetweenEachFloor;

    //Il faudrait un truc du style f(x) = K + 1/(2*maxHeight)  * X (maxHeight - X); où K = une constante
    if (i < floors*0.4)
      radius = radius + 0.5;
    else
      radius -= 0.5;
  }

}

int main () {
  int maxHeight = 20;
  int floors = 3;
  int nbPeak = 4;


  indexedFaceSet(nbPeak, floors);
  functionOfLife(maxHeight, floors, nbPeak, 3);
  return 0;
}
