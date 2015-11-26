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

  /*=======================================================*/
  /*                    Trie Hybride                       */
  /*=======================================================*/

  /********** Test n°1 - Construction Shakespeare **********

  TrieHybride t = trieVide(); //Déclaration et initialisation du Trie du départ

  constructShakespeareTrie(t,"../files/Shakespeare/1henryiv.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/1henryvi.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/2henryiv.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/2henryvi.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/3henryvi.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/allswell.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/asyoulikeit.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/cleopatra.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/comedy_errors.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/coriolanus.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/cymbeline.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/hamlet.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/henryv.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/henryviii.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/john.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/julius_caesar.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/lear.txt");
  //constructShakespeareTrie(t,"../files/Shakespeare/lll.txt"); //Fichier binaire
  constructShakespeareTrie(t,"../files/Shakespeare/macbeth.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/measure.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/merchant.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/merry_wives.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/midsummer.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/mucho_ado.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/othello.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/pericles.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/richardii.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/richardiii.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/romeo_juliet.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/taming_shrew.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/tempest.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/timon.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/titus.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/troilus_cressida.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/twelfth_night.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/two_gentlement.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/winters_tale.txt");


  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(),comptageMotsTrie_V2(t->nextChild));
*/
  /*
  TrieHybride t = trieVide();
  constructTrieHybride(t,base,tailleBase);

  char mot[50];
  listerTrie(t->nextChild,mot,0);
  afficheStructureHybride(t->nextChild,0);
  */
  /*
  ajoutMotTrie(t,"LM");
  ajoutMotTrie(t,"AB");
  ajoutMotTrie(t,"DF");
  ajoutMotTrie(t,"GH");
  */
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

  //visualiseTrie(t);

/*
  printf("\n1 %c | %ld",tmp->val, tmp->cle);
  printf("\n2 %c | %ld",tmp->nextChild->val, tmp->nextChild->cle);
  printf("\n3 %c | %ld",tmp->nextChild->nextChild->val, tmp->nextChild->nextChild->cle);
  printf("\n4 %c | %ld",tmp->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->cle);
  //printf("\n5 %c | %ld",tmp->nextChild->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->nextChild->cle);
  //printf("\n6 %c | %ld",tmp->nextChild->nextChild->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->nextChild->nextChild->cle);
*/
  printf("\n\n");

  /*=======================================================*/
  /*                Arbre de la Briandais                  */
  /*=======================================================*/

  /********** Test n°1 - Construction Shakespeare **********
  
  ArbreBriandais a = arbreVide();
  
  constructShakespeareBriandais(a,"../files/Shakespeare/1henryiv.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/1henryvi.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/2henryiv.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/2henryvi.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/3henryvi.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/allswell.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/asyoulikeit.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/cleopatra.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/comedy_errors.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/coriolanus.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/cymbeline.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/hamlet.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/henryv.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/henryviii.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/john.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/julius_caesar.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/lear.txt");
  //constructShakespeareBriandais(a,"../files/Shakespeare/lll.txt"); //Fichier binaire
  constructShakespeareBriandais(a,"../files/Shakespeare/macbeth.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/measure.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/merchant.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/merry_wives.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/midsummer.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/mucho_ado.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/othello.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/pericles.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/richardii.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/richardiii.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/romeo_juliet.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/taming_shrew.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/tempest.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/timon.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/titus.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/troilus_cressida.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/twelfth_night.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/two_gentlement.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/winters_tale.txt");
  
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsBriandais_V1(),comptageMotsBriandais_V2(a->sibling));
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
  ArbreBriandais a = arbreVide();
  TrieHybride t = trieVide();
  char mot[50];
  constructArbreBriandais(a,base,tailleBase);

  listerBriandais(a->sibling,mot,0);
  BriandaisToTrieHybrideV1(a->sibling, t, mot, 0);

  
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(t->nextChild),comptageMotsTrie_V2(t->nextChild));

  printf("\n\n"); 
  


  return EXIT_SUCCESS;
}
