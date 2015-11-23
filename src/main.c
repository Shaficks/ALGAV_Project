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
#include "tools.c"



int main(void) {



  //Test Trie Hybride
  TrieHybride t = trieVide();


  
  //constructTrieHybride(t,base,tailleBase);
  
  ajoutMotTrie(t,"LM");
  ajoutMotTrie(t,"AB");
  ajoutMotTrie(t,"DF");
  ajoutMotTrie(t,"GH");

/*
  printf("\nNombre de mots ajoutés dans le Trie Hybride : %ld\n",nbMotsHybride);

  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));
  suppressionMotTrie_V1(t,"Chafik");
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));

  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));
  suppressionMotTrie_V1(t,"dactylogra");
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));

  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));
  suppressionMotTrie_V1(t,"dactylo");
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));


  printf("\nHauteur Trie : %d\n", hauteurTrie(t->nextChild));

  printf("\nComptage Feuilles : %d \n",comptageFeuillesTrie(t));

  printf("\nProfondeur Totale Trie : %d \n",profondeurTotaleTrie(t,0));

  printf("\nProfondeur Moyenne Trie : %f \n",profondeurMoyenneTrie(t));
*/

  //afficheStructureHybride(t->nextChild,0);

  //tmp = t->nextChild->superiorChild;

  //char mot[50];
  //listeMotsTrie(t->nextChild,mot);
  
  visualiseTrie(t);

/*
  printf("\n1 %c | %ld",tmp->val, tmp->cle);
  printf("\n2 %c | %ld",tmp->nextChild->val, tmp->nextChild->cle);
  printf("\n3 %c | %ld",tmp->nextChild->nextChild->val, tmp->nextChild->nextChild->cle);
  printf("\n4 %c | %ld",tmp->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->cle);
  //printf("\n5 %c | %ld",tmp->nextChild->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->nextChild->cle);
  //printf("\n6 %c | %ld",tmp->nextChild->nextChild->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->nextChild->nextChild->cle);
*/
  printf("\n\n");




  //Test Arbre Briandais
  //ArbreBriandais a = arbreVide(); //tmp;
  //constructArbreBriandais(a,base,tailleBase);

/*
  ajoutMotBriandais(a,"AB");
  ajoutMotBriandais(a,"ACBD");
  ajoutMotBriandais(a,"ACUlmk");
  ajoutMotBriandais(a,"ACZlmk");
  ajoutMotBriandais(a,"TABCD");
  ajoutMotBriandais(a,"ZABCDEFGHI");
*/

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

*/
  //afficheStructureBriandais(a->sibling,0);


  //char mot[50];
  //listeMotsBriandais(a,mot);
  
  printf("\n\n");



/*
  //char mot[50];
  //listeMotsBriandais(a->sibling,mot);


  ArbreBriandais c = a->sibling->sibling->sibling;
  printf("\n\n");
  printf("%c\n",c->val);
  printf("%c\n",c->child->val);
  printf("%c\n",c->child->child->val);
  printf("%c\n",c->child->child->child->val);

  printf("%c\n",c->child->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->child->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->child->child->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->child->child->child->child->child->child->val);
  printf("%c\n",c->child->child->child->child->child->child->child->sibling->child->child->child->child->child->child->child->val);
*/


  return EXIT_SUCCESS;
}
