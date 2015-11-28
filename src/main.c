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
#include "arbreBriandais.c"
#include "trieHybride.c"
#include "fonctions_complexes.c"
#include "tools.c"
#include "test.c"


void listerBriandais(ArbreBriandais a, char mot[], int profondeur) {
  if(a) {
    mot[profondeur] = a->val;
    if(a->val == '\0') {
      mot[profondeur] = a->val;
      printf("\n%s",mot);
    }
    listerBriandais(a->child,mot,profondeur+1);
    listerBriandais(a->sibling,mot,profondeur);
  }
}


void listerTrie(TrieHybride t, char mot[], int profondeur) {
  if(t) {
    mot[profondeur] = t->val;
    if(t->cle != -1) {
      mot[profondeur+1] = '\0';
      printf("\n%s",mot);
    }
    listerTrie(t->inferiorChild,mot,profondeur);
    listerTrie(t->nextChild,mot,profondeur+1);
    listerTrie(t->superiorChild,mot,profondeur);
  }
}


int main(void) {

  //Construction d'un Arbre de la Briandais à partir de TOUS les fichiers de Shakespeare
  //testShakespeareBriandais();
  TrieHybride t = trieVide();
  constructTrieHybride(t,base,tailleBase);
  graphiz(t->nextChild,0);

  int i;
  for(i = 0; i < 100; i++)
    printf("\n%s",graph[i]);





  printf("\n\n");





/*
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsBriandais_V1(),comptageMotsBriandais_V2(a->sibling));
  //rechercheMotBriandais(a,"dactylo");
  suppressionMotBriandais_V1(a,"dactylographie");
  printf("Comptage Mots : V1 %ld | V2 %d\n\n",comptageMotsBriandais_V1(),comptageMotsBriandais_V2(a->sibling));

  rechercheMotBriandais(a,"dactylo");
  rechercheMotBriandais(a,"dactylographie");



  printf("\nHauteur Briandais : %d\n",hauteurBriandais(a));


  printf("\nComptage Feuilles Briandais : %d\n",comptageFeuillesBriandais(a));

  printf("\nProfondeur Totale Briandais : %d\n",profondeurTotaleBriandais(a,0));

  printf("\nProfondeur Totale Briandais : %f --> %d\n",profondeurMoyenneBriandais(a),(int)profondeurMoyenneBriandais(a));

*//*
  //afficheStructureBriandais(a->sibling,0);
  ArbreBriandais a = arbreVide();
  //TrieHybride t = trieVide();
  char mot[50];
  constructArbreBriandais(a,base,tailleBase);

  //listerBriandais(a->sibling,mot,0);
  //BriandaisToTrieHybrideV1(a->sibling, t, mot, 0);

  suppressionMotBriandais_V1(a,"dactylographie");
  listerBriandais(a->sibling,mot,0);
  rechercheMotBriandais(a,"dactyl");

  //printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));
*/
  printf("\n\n");



  return EXIT_SUCCESS;
}
