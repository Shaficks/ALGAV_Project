/**
 * /file tools.c
 * /brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * /author Chafik NOUIRA
 * /date 24 octobre 2015
 * /version 1.0
 *
 * Projet ALGAV - Fichier tools du programme :
 *      - Implémentation des fonctions utilitaires du programme.
 */

/* Inclusion du Header du programme */
#include "../headers/main.h"


/* VIII - Fonction utilitaires */
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


void *my_malloc(size_t size) {
  void *p;
  p = malloc(size);
  if(p == NULL) {
    fprintf(stderr, "Erreur : impossible d'allouer la memoire\n");
    exit(-1);
  }
  return p;
}



char* resteMot(char mot[], int i) {
    char *res = malloc(sizeof(res));
    int j, n = strlen(mot);
    for(j = 0; i+j < n+1; j++) {
        //printf("\nReste Mot %d\n",j);
        res[j] = mot[i+j];
    }
    return res;
}

