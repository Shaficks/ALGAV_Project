/**
 * /file main.c
 * /brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * /author Chafik NOUIRA
 * /date 24 octobre 2015
 * /version 1.0
 * 
 * Projet ALGAV - Fichier main du programme : 
 *      - Implémentation des Arbres de la Briandais et Tries Hybrides
 *      - Implémentation des Primitives de chaque structure
 *      - Implémentation de fonctions avancées pour chaque structure
 *      - Comparaison des résultats et efficacité
 */

/* Inclusion du Header du programme */
#include "../headers/main.h"

/* Implémentation des fonctions utilitaires */


void chargerMots() {
  int i = -1;
  FILE* f = NULL;
  char mot[50];
  printf("Avant de charger\n");
  f = fopen("../files/Shakespeare/timon.txt","r+");
  if(f == NULL) {
    printf("é zebi o.O !!");
    return;
  }
  else printf("Chargement Réussi !!\n");
  
  do {
    i++;
    fgets(mot, sizeof base[i], f);
    printf("%s",mot);
  } while (i<20);
  fclose(f);
  
}
void afficheListeMots() {
  int i;
  for (i=0; i<30; i++)
    printf("%s\n",base[i]);
}

int main(void) {
 

  chargerMots();
  //afficheListeMots();

  return EXIT_SUCCESS;
}
