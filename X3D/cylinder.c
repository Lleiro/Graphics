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

void TrianglesAmeliores(int nbPeak, int floors) {
  printf("DESSIN TRIANGLE ---------------\n");
  int etageCourrant;
  int premiereVal;
  int valCourante;
  for (int j = 0; j<floors+1; j++) {
    etageCourrant = j;
    premiereVal = nbPeak*etageCourrant;
    for (int i=0; i < nbPeak; i++) {
      valCourante = premiereVal+i;

      //si on est pas au rez-de-chaussée ni au dernier étage
      if (etageCourrant>= 1 && etageCourrant != floors) {
        if (etageCourrant%2 == 0) { //si l'étage est pair
           if (i != nbPeak-1) { // si on ne dessine PAS le DERNIER triangle
             //Triangle suppérieur
             printf("%d %d %d -1\n", valCourante, valCourante+1, valCourante+nbPeak+1);
             //triangle adj
             printf("%d %d %d -1\n", valCourante+nbPeak, valCourante, valCourante+nbPeak+1);
        //
           } else {// dessine UNIQUEMENT le DERNIER triangle
        //     //triangle suppérieur
             printf("%d %d %d -1\n", valCourante, valCourante-nbPeak+1, valCourante+1);
        //     //triangle adj
             printf("%d %d %d -1\n", valCourante+nbPeak, valCourante+1, valCourante);
          }
        } else { //si l'étage est impair
           if (i != nbPeak-1){//Dessine tous les triangles SAUF le dernier
        //     //dessine triangle suppérieur
             printf("%d %d %d -1\n", valCourante, valCourante+1, valCourante+nbPeak);
        //     //dessine triangle adjacent
             printf("%d %d %d -1\n", valCourante+nbPeak, valCourante+1, valCourante+nbPeak+1);
        //
           } else{//Dessine UNIQUEMENT le dernier triangle
        //     //dessine le triangle supérieur
             printf("%d %d %d -1\n", valCourante, valCourante-nbPeak+1, valCourante+nbPeak);
        //     //dessine triangle adjacent
             printf("%d %d %d -1\n", valCourante+nbPeak, valCourante+1-nbPeak, valCourante+1);
         }
        }
      } else if (etageCourrant == 0) {//si on est au rez-de chaussée
        if (i != nbPeak-1)
          printf("%d %d %d -1\n", valCourante, valCourante+nbPeak, valCourante+nbPeak+1);
        else
          printf("%d %d %d -1\n", valCourante, valCourante+nbPeak, valCourante+1);
      }
    }
  }
  printf("-----------------\n");
}

void Triangles(int nbPeak, int floors) {
  printf("DESSIN TRIANGLE ---------------\n");
  int etageCourrant;
  int premiereVal;
  int valCourante;
  for (int j = 0; j<floors+1; j++) {
    etageCourrant = j;
    premiereVal = nbPeak*etageCourrant;
    for (int i=0; i < nbPeak; i++) {
      valCourante = premiereVal+i;

      //si on est pas au rez-de-chaussée ni au dernier étage
      if (etageCourrant>= 1 && etageCourrant != floors) {

        //si l'étage est pair
        if (etageCourrant%2 == 0) {
          /* Pemert de GERER le passage à l'étage supp */
          if (i != nbPeak-1) {
            //Triangle suppérieur
            printf("%d %d %d -1\n", valCourante, valCourante+1, valCourante+nbPeak+1);
            /* triangle inférieur */
            printf("%d %d %d -1\n", valCourante+nbPeak, valCourante, valCourante+nbPeak+1);

          } else {// DESSINE UNIQUEMENT UN TRIANGLE
            //triangle suppérieur
            printf("%d %d %d -1\n", valCourante, valCourante-nbPeak+1, valCourante+1);
            //triangle inf
            printf("%d %d %d -1\n", valCourante+nbPeak, valCourante+1, valCourante);
            }

        } else {
          if (i != nbPeak-1){//Dessine tous les triangles SAUF le dernier
            //dessine triangle suppérieur
            printf("%d %d %d -1\n", valCourante, valCourante+1, valCourante+nbPeak);
            //dessine le triangle inférieur
            printf("%d %d %d -1\n", valCourante, valCourante+1, valCourante-nbPeak);
            //dessine triangle adjacent
            printf("%d %d %d -1\n", valCourante+nbPeak, valCourante+1, valCourante+nbPeak+1);

          } else{//Dessine UNIQUEMENT le dernier triangle
            //dessine le triangle supérieur
            printf("%d %d %d -1\n", valCourante, valCourante-nbPeak+1, valCourante+nbPeak);
            //dessine le triangle inf
            printf("%d %d %d -1\n", valCourante, valCourante-nbPeak+1, valCourante-nbPeak);
            //dessine triangle adjacent
            printf("%d %d %d -1\n", valCourante+nbPeak, valCourante+1-nbPeak, valCourante+1);
          }
        }
      }
    }
  }
  printf("-----------------\n");
}

void calculCoordonnees(int maxHeight, int floors, int nbPeak, float radius) {
  float height = 0;
  float heightBetweenEachFloor = maxHeight/(floors);
  float x = 0;
  float y = 0;
  float angle = (2*M_PI/nbPeak);
  printf("ANGLE : %f\n", angle);
  printf("Cos(angle) = %f\n", cos(angle*2));

  float tempRadius = radius;

  for(int i=0; i<floors + 1 ; i++) {

    if (i == floors) {
      height += heightBetweenEachFloor/4;
    }

    for(int j=0; j<nbPeak; j++){
      //printf("Valeur de j = %d\n", j);

      if (i%2==0 && i!= floors) {
        x = radius * cos(angle * j + M_PI/nbPeak);
        y = radius * sin(angle * j + M_PI/nbPeak);
      } else if (i%2==1 && i!= floors) {
        x = radius * cos(angle * j);
        y = radius * sin(angle * j);
      } else {
        x = 0;
        y = 0;
      }


      printf("%f\t %f\t %f,\n", x, height, y);
    }

    if (i != floors -1){
      height += heightBetweenEachFloor;
    }

    float var = i;
    if (i<17) {
      radius = tempRadius + 1/4 *var*(26-var*2)/(40);
    } else {
      radius = tempRadius - (var*var*var/1000)/(23-var);
    }
    //radius = tempRadius + var*(1-var)/157;
  }

}

void algoCouleur(int nbPeak, int floors){
  int nbPeakTotal = nbPeak*2*floors-nbPeak; //-nbPeak car il faut retirer le rez-de-chaussée
  for (int j=0; j < nbPeakTotal/36; j++)
    printf("1 1 0 0 0 0\n");
}



int main () {
  int maxHeight = 24;
  int floors = 22;
  int nbPeak = 18;
  int radius = 3;


  /* l'algo couleur ne fonctionne pas */
  algoCouleur(nbPeak, floors);

  /*Le programme était entièrement paramétrable jusqu'au radius.
  Je n'ai pas réussi à trouver une function correcte qui me permet de faire un gherkin correcte en toute circonstances.
  Rayon à part, on peut choisir la hauteur, le nombre d'étages et le nombre de points sur le cercle formant un étage.*/
  TrianglesAmeliores(nbPeak, floors);
  indexedFaceSet(nbPeak, floors);
  calculCoordonnees(maxHeight, floors, nbPeak, radius);

  return 0;
}
