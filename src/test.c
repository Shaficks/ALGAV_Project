/**
 * \file test.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Projet ALGAV - Fichier test du programme :
 * Fichier contenant des fonctions effectuant des séries de test destinées à être utilisées lors de la soutenance.
 */
#include "../headers/main.h"

/*=======================================================*/
/*        Fonctions de Calcul de temps d'exécution       */
/*=======================================================*/
clock_t top_chrono;

void demarrer_chrono() {
    top_chrono = clock();
}

void stop_chrono() {
    printf("%lf sec", (((double)(clock() - top_chrono))/CLOCKS_PER_SEC)*10);
}


/*********************** Fonction de construction d'un Arbre de la Briandais à partir d'un fichier de Shakespeare *******************************/
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
}

/*********************** Fonction de construction d'un Trie Hybride à partir d'un fichier de Shakespeare *******************************/
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
}



/*=======================================================*/
/*             Tests Arbre de la Briandais               */
/*=======================================================*/

/* Construction d'un Arbre de la Briandais à partir de tous les fichiers de Shakespeare et affichage des différentes informations */
void testShakespeareBriandais() {
  demarrer_chrono();
  ArbreBriandais a = arbreVide(); //Déclaration et initialisation de l'Arbre de la Briandais

  //Construction de l'Arbre de la Briandais à partir de tous les fichiers de Skahespeare
  constructShakespeareBriandais(a,"../files/Shakespeare/1henryiv.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/1henryvi.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/2henryiv.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/2henryvi.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/3henryvi.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/allswell.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/asyoulikeit.txt");
  /*constructShakespeareBriandais(a,"../files/Shakespeare/cleopatra.txt");
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
*/
  printf("\nTemps de construction à partir des fichiers Shakespeare : ");
  stop_chrono(); printf("\n");

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  demarrer_chrono();
  printf("Comptage Mots : V1 %ld - V2 %d | Nb d'opérations : ... | Temps d'exécution : ",comptageMotsBriandais_V1(),comptageMotsBriandais_V2(a->sibling));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Comptage Pointeurs vers Nil : %d | Nb d'opérations : ... | Temps d'exécution : ",comptageNilBriandais(a->sibling));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Hauteur de l'Arbre : %d | Nb d'opérations : ... | Temps d'exécution : ",hauteurBriandais(a));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Comptage Feuilles : %d | Nb d'opérations : ... | Temps d'exécution : ",comptageFeuillesBriandais(a));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Profondeur Moyenne de l'Arbre : %f --> %d | Nb d'opérations : ... | Temps d'exécution : ",profondeurMoyenneBriandais(a),(int)profondeurMoyenneBriandais(a));
  stop_chrono(); printf("\n");
}



void testBaseBriandais() {
  ArbreBriandais a = arbreVide(); //Déclaration de l'Arbre de la Briandais

  demarrer_chrono(); //Fonction qui fixe le temps de départ, sert pour calculer le temps d'exécution par la suite.
  constructArbreBriandais(a,base,tailleBase); //Construction de l'arbre à partir de l'Exemple de Base


  printf("\nTemps de construction à partir de l'Exemple de Base : ");
  stop_chrono(); printf("\n");

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  demarrer_chrono();
  printf("Comptage Mots : V1 %ld - V2 %d | Nb d'opérations : ... | Temps d'exécution : ",comptageMotsBriandais_V1(),comptageMotsBriandais_V2(a->sibling));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Comptage Pointeurs vers Nil : %d | Nb d'opérations : ... | Temps d'exécution : ",comptageNilBriandais(a->sibling));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Hauteur de l'Arbre : %d | Nb d'opérations : ... | Temps d'exécution : ",hauteurBriandais(a));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Comptage Feuilles : %d | Nb d'opérations : ... | Temps d'exécution : ",comptageFeuillesBriandais(a));
  stop_chrono(); printf("\n");
  demarrer_chrono();
  printf("Profondeur Moyenne de l'Arbre : %f --> %d | Nb d'opérations : ... | Temps d'exécution : ",profondeurMoyenneBriandais(a),(int)profondeurMoyenneBriandais(a));
  stop_chrono(); printf("\n");

  char mot[50];
  //Ajout d'un mot
  printf("\nEntrez un mot à ajouter : "); scanf("%s",mot);
  demarrer_chrono();
  ajoutMotBriandais(a,mot);
  printf("\nNb d'opérations : ... | Temps d'exécution : ");
  stop_chrono();printf("\n");

  //Test de la fonction préfixe
  printf("Entrez une chaine afin de voir de combien de mots elle est préfixe : "); scanf("%s",mot);
  demarrer_chrono();
  printf("\nNb de mots qui ont \'%s\' comme préfixe : %d | Nb d'opérations : ... | Temps d'exécution : ",mot,prefixeBriandais(a,mot));
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono();
  rechercheMotBriandais(a,mot);
  printf("\nNb d'opérations : ... | Temps d'exécution : ");
  stop_chrono();

  //Suppression d'un mot
  printf("\nEntrez un mot à supprimer : "); scanf("%s",mot);
  demarrer_chrono();
  suppressionMotBriandais_V1(a,mot);
  printf("\nNb d'opérations : ... | Temps d'exécution : ");
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono();
  rechercheMotBriandais(a,mot);
  printf("\nNb d'opérations : ... | Temps d'exécution : ");
  stop_chrono();

  //Lister les mots
  printf("\nEntrez n'importe quel chiffre pour voir la liste des mots : "); scanf("%s",mot);
  demarrer_chrono();
  listeMotsBriandais(a->sibling, mot, 0);
  printf("\nNb d'opérations : ... | Temps d'exécution : ");
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono();
  afficheStructureBriandais(a->sibling,0);
  printf("\nNb d'opérations : ... | Temps d'exécution : ");
  stop_chrono();
}


void testComplexeBriandais() {

}
/*=======================================================*/
/*                  Tests Trie Hybride                   */
/*=======================================================*/

/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare et affichage des différentes informations */
void testShakespeareTrieHybride() {
  TrieHybride t = trieVide(); //Déclaration et initialisation du Trie du départ

  //Construction du Trie Hybride à partir de tous les fichiers de Shakespeare
  demarrer_chrono();
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
  stop_chrono();

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsTrie_V1(),comptageMotsTrie_V2(t->nextChild));
}
