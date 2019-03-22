#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void indexedFaceSet(int nbPeak, int floors) {
  printf("DESSIN Etage ---------------\n");
  int etageCourrant;
  int premiereVal;
  for (int j = 0; j<floors+1; j++) {
    etageCourrant = j;
    premiereVal = nbPeak*etageCourrant;
    for (int i=0; i < nbPeak; i++) {
      printf("%d ", premiereVal+i);
    }
    printf("-1 \n");
  }
  printf("-----------------\n");
}

void onFaitLesTriangles(int nbPeak, int floors) {
  printf("DESSIN TRIANGLE ---------------\n");
  int etageCourrant;
  int premiereVal;
  int valCourante;
  for (int j = 0; j<floors; j++) {
    etageCourrant = j;
    premiereVal = nbPeak*etageCourrant;
    for (int i=0; i < nbPeak; i++) {
      valCourante = premiereVal+i;
      if (etageCourrant%2 == 1) {
        if (i != nbPeak-1)
          printf("%d %d %d -1\n", valCourante, valCourante+1, valCourante+nbPeak);
        else
          printf("%d %d %d -1\n", valCourante, valCourante+2, valCourante+nbPeak);
        printf("%d %d %d -1\n", valCourante, valCourante+1, valCourante-nbPeak);
      }

    }
  }
  printf("-----------------\n");
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
    for(int j=0; j<nbPeak; j++){
      //printf("Valeur de j = %d\n", j);

      if (i%2==0) {
        x = radius * cos(angle * j + M_PI/nbPeak);
        y = radius * sin(angle * j + M_PI/nbPeak);
      } else {
        x = radius * cos(angle * j);
        y = radius * sin(angle * j);
      }
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
  int nbPeak = 6;



  onFaitLesTriangles(nbPeak, floors);
  indexedFaceSet(nbPeak, floors);
  functionOfLife(maxHeight, floors, nbPeak, 3);
  return 0;
}
