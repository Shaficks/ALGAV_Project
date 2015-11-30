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
  //else printf("Chargement Réussi !!\n");

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
  //else printf("Chargement Réussi !!\n");

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

/* Construction d'un Arbre de la Briandais à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testShakespeareBriandais() {
  demarrer_chrono(); nb_operations = 0;
  ArbreBriandais a = arbreVide(); //Déclaration et initialisation de l'Arbre de la Briandais

  //Construction de l'Arbre de la Briandais à partir de tous les fichiers de Skahespeare
  constructShakespeareBriandais(a,"../files/Shakespeare/1henryiv.txt");
  printf("\n1 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/1henryvi.txt");
  printf("\n2 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/2henryiv.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/2henryvi.txt");
  printf("\n4 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/3henryvi.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/allswell.txt");
  printf("\n6 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/asyoulikeit.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/cleopatra.txt");
  printf("\n8 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/comedy_errors.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/coriolanus.txt");
  printf("\n10 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/cymbeline.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/hamlet.txt");
  printf("\n12 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/henryv.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/henryviii.txt");
  printf("\n14 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/john.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/julius_caesar.txt");
  printf("\n16 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/lear.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/macbeth.txt");
  printf("\n18 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/measure.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/merchant.txt");
  printf("\n20 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/merry_wives.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/midsummer.txt");
  printf("\n22 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/much_ado.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/othello.txt");
  printf("\n24 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/pericles.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/richardii.txt");
  printf("\n26 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/richardiii.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/romeo_juliet.txt");
  printf("\n28 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/taming_shrew.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/tempest.txt");
  printf("\n30 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/timon.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/titus.txt");
  printf("\n32 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/troilus_cressida.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/twelfth_night.txt");
  printf("\n34 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/two_gentlemen.txt");
  constructShakespeareBriandais(a,"../files/Shakespeare/winters_tale.txt");
  printf("\n36 : "); stop_chrono();
  constructShakespeareBriandais(a,"../files/Shakespeare/lll.txt");
  printf("\n37 : "); stop_chrono();

  printf("\nConstruction à partir de TOUS les fichiers de Shakespeare : Nb opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono(); printf("\n");

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  demarrer_chrono(); nb_operations = 0;
  comptageMotsBriandais_V2(a->sibling);
  printf("Comptage Mots : V1 %ld - V2 %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageMotsBriandais_V1(),
            comptageMotsBriandais_V2(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageNilBriandais(a->sibling);
  printf("Comptage Pointeurs vers Nil : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageNilBriandais(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  hauteurBriandais(a->sibling);
  printf("Hauteur de l'Arbre : %d | Nb d'opérations : %ld | Temps d'exécution : ",hauteurBriandais(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageFeuillesBriandais(a->sibling);
  printf("Comptage Feuilles : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageFeuillesBriandais(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  profondeurMoyenneBriandaisV2(a->sibling);
  printf("Profondeur Moyenne de l'Arbre : %f --> %d | Nb d'opérations : %ld | Temps d'exécution : ",profondeurMoyenneBriandaisV2(a->sibling),
            (int)profondeurMoyenneBriandaisV2(a->sibling),nb_operations);
  stop_chrono(); printf("\n");


  char mot[50];
  //Ajout d'un mot
  printf("\nEntrez un mot à ajouter : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  ajoutMotBriandais(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();printf("\n");

  //Test de la fonction préfixe
  printf("Entrez une chaine afin de voir de combien de mots elle est préfixe : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  prefixeBriandais(a,mot);
  printf("\nNb de mots qui ont \'%s\' comme préfixe : %d | Nb d'opérations : %ld | Temps d'exécution : ",mot,prefixeBriandais(a,mot),nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotBriandais(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Suppression d'un mot
  printf("\nEntrez un mot à supprimer : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  suppressionMotBriandais_V1(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotBriandais(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Lister les mots
  printf("\nEntrez n'importe quel chiffre pour voir la liste des mots : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  listeMotsBriandais(a->sibling, mot, 0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeBriandais(a->sibling,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

}

/* Construction d'un Arbre de la Briandais à partir de l'exemple de base afin d'y effectuer certaines opérations */
void testBaseBriandais() {
  ArbreBriandais a = arbreVide(); //Déclaration de l'Arbre de la Briandais

  demarrer_chrono(); //Fonction qui fixe le temps de départ, sert pour calculer le temps d'exécution par la suite.
  constructArbreBriandais(a,base,tailleBase); //Construction de l'arbre à partir de l'Exemple de Base

  printf("\nConstruction à partir de l'Exemple de Base : Nb opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono(); printf("\n");

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  demarrer_chrono(); nb_operations = 0;
  comptageMotsBriandais_V2(a->sibling);
  printf("Comptage Mots : V1 %ld - V2 %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageMotsBriandais_V1(),
            comptageMotsBriandais_V2(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageNilBriandais(a->sibling);
  printf("Comptage Pointeurs vers Nil : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageNilBriandais(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  hauteurBriandais(a->sibling);
  printf("Hauteur de l'Arbre : %d | Nb d'opérations : %ld | Temps d'exécution : ",hauteurBriandais(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageFeuillesBriandais(a->sibling);
  printf("Comptage Feuilles : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageFeuillesBriandais(a->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  profondeurMoyenneBriandaisV2(a->sibling);
  printf("Profondeur Moyenne de l'Arbre : %f --> %d | Nb d'opérations : %ld | Temps d'exécution : ",profondeurMoyenneBriandaisV2(a->sibling),
            (int)profondeurMoyenneBriandaisV2(a->sibling),nb_operations);
  stop_chrono(); printf("\n");


  char mot[50];
  //Ajout d'un mot
  printf("\nEntrez un mot à ajouter : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  ajoutMotBriandais(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();printf("\n");

  //Test de la fonction préfixe
  printf("Entrez une chaine afin de voir de combien de mots elle est préfixe : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  prefixeBriandais(a,mot);
  printf("\nNb de mots qui ont \'%s\' comme préfixe : %d | Nb d'opérations : %ld | Temps d'exécution : ",mot,prefixeBriandais(a,mot),nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotBriandais(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Suppression d'un mot
  printf("\nEntrez un mot à supprimer : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  suppressionMotBriandais_V1(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotBriandais(a,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Lister les mots
  printf("\nEntrez n'importe quel chiffre pour voir la liste des mots : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  listeMotsBriandais(a->sibling, mot, 0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeBriandais(a->sibling,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

}

/* Construction par Fusion d'arbres */
void testFusionBriandais();

/* Construction d'un Arbre de la Briandais et Conversion en Trie Hybride */
void testConversionBriandais();

/* Construction d'un Arbre de la Briandais et affichage d'un aperçu visuel de ce dernier */
void testVisualizeBriandais() {
  ArbreBriandais a = arbreVide();
  constructArbreBriandais(a,base,tailleBase);
  visualizeBriandais(a->sibling);
}



/*=======================================================*/
/*                  Tests Trie Hybride                   */
/*=======================================================*/


/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testShakespeareTrieHybride() {
  demarrer_chrono(); nb_operations = 0;
  TrieHybride t = trieVide(); //Déclaration et initialisation du Trie Hybride

  //Construction de l'Arbre de la Briandais à partir de tous les fichiers de Skahespeare
  constructShakespeareTrie(t,"../files/Shakespeare/1henryiv.txt");
  printf("\n1 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/1henryvi.txt");
  printf("\n2 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/2henryiv.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/2henryvi.txt");
  printf("\n4 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/3henryvi.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/allswell.txt");
  printf("\n6 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/asyoulikeit.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/cleopatra.txt");
  printf("\n8 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/comedy_errors.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/coriolanus.txt");
  printf("\n10 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/cymbeline.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/hamlet.txt");
  printf("\n12 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/henryv.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/henryviii.txt");
  printf("\n14 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/john.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/julius_caesar.txt");
  printf("\n16 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/lear.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/winters_tale.txt");
  printf("\n18 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/macbeth.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/measure.txt");
  printf("\n20 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/merchant.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/merry_wives.txt");
  printf("\n22 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/midsummer.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/much_ado.txt");
  printf("\n24 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/othello.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/pericles.txt");
  printf("\n26 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/richardii.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/richardiii.txt");
  printf("\n28 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/romeo_juliet.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/taming_shrew.txt");
  printf("\n30 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/tempest.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/timon.txt");
  printf("\n32 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/titus.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/troilus_cressida.txt");
  printf("\n34 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/twelfth_night.txt");
  constructShakespeareTrie(t,"../files/Shakespeare/two_gentlemen.txt");
  printf("\n36 : "); stop_chrono();
  constructShakespeareTrie(t,"../files/Shakespeare/lll.txt");
  printf("\n37 : "); stop_chrono();

  printf("\nConstruction à partir de TOUS les fichiers de Shakespeare : Nb opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono(); printf("\n");

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  demarrer_chrono(); nb_operations = 0;
  comptageMotsTrie_V2(t->nextChild);
  printf("Comptage Mots : V1 %ld - V2 %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageMotsTrie_V1(),
            comptageMotsTrie_V2(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageNilTrie(t->nextChild);
  printf("Comptage Pointeurs vers Nil : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageNilTrie(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  hauteurTrie(t->nextChild);
  printf("Hauteur de l'Arbre : %d | Nb d'opérations : %ld | Temps d'exécution : ",hauteurTrie(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageFeuillesTrie(t->nextChild);
  printf("Comptage Feuilles : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageFeuillesTrie(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  profondeurMoyenneTrie(t->nextChild);
  printf("Profondeur Moyenne de l'Arbre : %f --> %d | Nb d'opérations : %ld | Temps d'exécution : ",profondeurMoyenneTrieV2(t->nextChild),
            (int)profondeurMoyenneTrieV2(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");


  char mot[50];
  //Ajout d'un mot
  printf("\nEntrez un mot à ajouter : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  ajoutMotTrie(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();printf("\n");

  //Test de la fonction préfixe
  printf("Entrez une chaine afin de voir de combien de mots elle est préfixe : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  prefixeTrie(t,mot);
  printf("\nNb de mots qui ont \'%s\' comme préfixe : %d | Nb d'opérations : %ld | Temps d'exécution : ",mot,prefixeTrie(t,mot),nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotTrie(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Suppression d'un mot
  printf("\nEntrez un mot à supprimer : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  suppressionMotTrie_V1(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotTrie(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Lister les mots
  printf("\nEntrez n'importe quel chiffre pour voir la liste des mots : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  listeMotsTrie(t->nextChild, mot, 0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeHybride(t->nextChild,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();
}


/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testBaseTrieHybride() {


/* Construction d'un Trie Hybride et Conversion en un Arbre de la Briandais */
void testConversionTrieHybride();

/* Construction d'un Trie Hybride et affichage d'un aperçu visuel de ce dernier */
void testVisualizeTrieHybride();
  demarrer_chrono(); nb_operations = 0;
  TrieHybride t = trieVide(); //Déclaration et initialisation du Trie Hybride

  //Construction à partir de l'exemle de base
  constructTrieHybride(t,base,tailleBase);

  printf("\nConstruction à partir de TOUS les fichiers de Shakespeare : Nb opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono(); printf("\n");

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  demarrer_chrono(); nb_operations = 0;
  comptageMotsTrie_V2(t->nextChild);
  printf("Comptage Mots : V1 %ld - V2 %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageMotsTrie_V1(),
            comptageMotsTrie_V2(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageNilTrie(t->nextChild);
  printf("Comptage Pointeurs vers Nil : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageNilTrie(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  hauteurTrie(t->nextChild);
  printf("Hauteur de l'Arbre : %d | Nb d'opérations : %ld | Temps d'exécution : ",hauteurTrie(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageFeuillesTrie(t->nextChild);
  printf("Comptage Feuilles : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageFeuillesTrie(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  profondeurMoyenneTrie(t->nextChild);
  printf("Profondeur Moyenne de l'Arbre : %f --> %d | Nb d'opérations : %ld | Temps d'exécution : ",profondeurMoyenneTrieV2(t->nextChild),
            (int)profondeurMoyenneTrieV2(t->nextChild),nb_operations);
  stop_chrono(); printf("\n");


  char mot[50];
  //Ajout d'un mot
  printf("\nEntrez un mot à ajouter : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  ajoutMotTrie(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();printf("\n");

  //Test de la fonction préfixe
  printf("Entrez une chaine afin de voir de combien de mots elle est préfixe : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  prefixeTrie(t,mot);
  printf("\nNb de mots qui ont \'%s\' comme préfixe : %d | Nb d'opérations : %ld | Temps d'exécution : ",mot,prefixeTrie(t,mot),nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotTrie(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Suppression d'un mot
  printf("\nEntrez un mot à supprimer : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  suppressionMotTrie_V1(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotTrie(t,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Lister les mots
  printf("\nEntrez n'importe quel chiffre pour voir la liste des mots : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  listeMotsTrie(t->nextChild, mot, 0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeHybrideV2(t->nextChild,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();
}
