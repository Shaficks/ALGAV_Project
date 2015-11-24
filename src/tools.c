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


//Retourne le reste d'un mot à partir de l'ième lettre incluse
char* resteMot(char mot[], int i) {
    char *res = malloc(sizeof(res));
    int j, n = strlen(mot);
    for(j = 0; i+j < n+1; j++) {
        //printf("\nReste Mot %d\n",j);
        res[j] = mot[i+j];
    }
    return res;
}

int max2(int a, int b) {
    return (a>b)?a:b;
}


int max3(int a, int b, int c) {
    if(a>b && a>c) return a;
    if(b>a && b>c) return b;
    return c;
}


void constructShakespeareBriandais(ArbreBriandais a, char chemin[]) {
  FILE* f = NULL;
  char mot[50];  
  f = fopen(chemin,"r+");
  if(f == NULL) {
    printf("Chargement \'%s\' échoué...",chemin);
    return;
  }
  else printf("Chargement Réussi !!\n");

  
  do {
    fgets(mot, sizeof mot, f);
    //printf("%s",mot);
    ajoutMotBriandais(a,mot);
  } while (!feof(f));
  fclose(f);

  printf("\nC'est fini !\n");
}


void constructShakespeareTrie(TrieHybride t, char chemin[]) {
  FILE* f = NULL;
  char mot[50];  
  f = fopen(chemin,"r+");
  if(f == NULL) {
    printf("Chargement \'%s\' échoué...",chemin);
    return;
  }
  else printf("Chargement Réussi !!\n");

  do {
    fgets(mot, sizeof mot, f);
    //printf("%s",mot);
    ajoutMotTrie(t,mot);
  } while (!feof(f));
  fclose(f);

  printf("\nC'est fini !\n");
}
