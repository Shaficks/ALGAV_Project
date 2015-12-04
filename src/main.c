/**
 * \file main.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
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


char tab[50000][50];
int tailleTab = 0;

int compteBriandais(ArbreBriandais a) {
    if(!a) return 0;
    return 1 + compteBriandais(a->child) + compteBriandais(a->sibling);
}

int compteHybride(TrieHybride t) {
    if(!t) return 0;
    return 1 + compteHybride(t->inferiorChild) + compteHybride(t->nextChild) + compteHybride(t->superiorChild);
}


//Retourne la liste des mots présents dans le Trie t triés dans l'ordre alphabétique.
void listeMotsTrieTab(TrieHybride t) {
  ++nb_operations;
  if(t) {
    if(t->cle != -1) {
      //while(strlen(tab[tailleTab]) == 0) tailleTab++;
      strcpy(tab[tailleTab++],t->mot);
    }
    if(t->inferiorChild)
        listeMotsTrieTab(t->inferiorChild);
    if(t->nextChild)
        listeMotsTrieTab(t->nextChild);
    if(t->superiorChild)
        listeMotsTrieTab(t->superiorChild);
  }
}

int cmpt = 0;

void reequilibrageRec(TrieHybride res, char tab[5000][50], int t_min, int t_max) {
  if(t_min > t_max) return;
  if(t_max == t_min) {
    ajoutMotTrie(res,tab[t_min]);
    return;
  }
  int milieu = (t_min+t_max)/2;
  printf("\n%s | %d",tab[milieu],++cmpt);
  ajoutMotTrie(res,tab[milieu]);
  reequilibrageRec(res,tab,t_min,milieu-1);
  reequilibrageRec(res,tab,milieu+1,t_max);
}


void suppressionListeBriandais(ArbreBriandais a, char** liste, int taille) {
    int i;
    for(i = 0; i < taille; i++)
        suppressionMotBriandais_V1(a,liste[i]);
}


void suppressionListeHybride(TrieHybride t, char** liste, int taille) {
    int i;
    for(i = 0; i < taille; i++)
        suppressionMotTrie_V1(t,liste[i]);
}




/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare et Rééquilibrage */
void testReequilibrageTrieHybride() {
  TrieHybride t = trieVide(); //Déclaration et initialisation du Trie Hybride

  //Construction de l'Arbre de la Briandais à partir de tous les fichiers de Skahespeare
  demarrer_chrono(); nb_operations = 0;
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
  
  TrieHybride res = trieVide();

  printf("\nRééquilibrage en cours...\n");
  listeMotsTrieTab(t->nextChild);
  
  demarrer_chrono(); nb_operations = 0;
  reequilibrageRec(res,tab,0,tailleTab-1);
  printf("\nDone !\nRééquilibrage Shakespeare - Trie Hybride : Nb opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono(); printf("\n\n");


  /*   Comparaison du Trie initial et du Trie résultat
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */

  printf("Comptage Mots : t-%d - res-%d\n", comptageMotsTrie_V2(t->nextChild),comptageMotsTrie_V2(res->nextChild));

  printf("Comptage Pointeurs vers Nil : t-%d res-%d\n",comptageNilTrie(t->nextChild),comptageNilTrie(res->nextChild));

  printf("Hauteur de l'Arbre : t-%d res-%d\n",hauteurTrie(t->nextChild),hauteurTrie(res->nextChild));

  printf("Comptage Feuilles : t-%d res-%d\n",comptageFeuillesTrie(t->nextChild),comptageFeuillesTrie(res->nextChild));

  printf("Profondeur Moyenne du Trie t : %f --> %d\n",profondeurMoyenneTrieV2(t->nextChild),
            (int)profondeurMoyenneTrieV2(t->nextChild));

  printf("Profondeur Moyenne du Trie res : %f --> %d\n",profondeurMoyenneTrieV2(res->nextChild),
	 (int)profondeurMoyenneTrieV2(res->nextChild));
  printf("\n");
}








int main(void) {
  printf("\n\n");



  //testReequilibrageTrieHybride();

  
  
  //Test rééquilibirage
  TrieHybride t = trieVide(), t2 = trieVide(), res = trieVide();
  constructTrieHybride(t,base,tailleBase);

  printf("\nMots t :\n");
  listeMotsTrieTab(t->nextChild);

  
  printf("\nTest 1\n");

  printf("\nListe Tab :");
  int i;
  for(i = 0; i < tailleTab; i++) {
    printf("\n%s",tab[i]);
    //ajoutMotTrie(t2,tab[i]);
  }


  printf("\nListe mots rééquilibrage\n");
  
  reequilibrageRec(res,tab,0,tailleTab);


  printf("\nListe Trie res :");
  listeMotsTrie(res->nextChild);


  printf("\nHauteur t : %d | Hauteur res : %d\n",hauteurTrie(t->nextChild),hauteurTrie(res->nextChild));
  printf("Nombre mots t : %d | Nombe mots res : %d\n",comptageMotsTrie_V2(t->nextChild),comptageMotsTrie_V2(res->nextChild));
  
  

/*
 //Test suppression d'une liste de mots
 ArbreBriandais a = arbreVide(); constructArbreBriandais(a,base,tailleBase);
 TrieHybride t = trieVide(); constructTrieHybride(t,base,tailleBase);


 ajoutMotBriandais(a,"premier"); ajoutMotBriandais(a,"deux"); ajoutMotBriandais(a,"trois");
 ajoutMotTrie(t,"premier"); ajoutMotTrie(t,"deux"); ajoutMotTrie(t,"trois");

 suppressionListeBriandais(a,base,tailleBase);
 suppressionListeHybride(t,base,tailleBase);

 printf("\nListe mots Briandais\n");
 char mot[50];
 listeMotsBriandais(a->sibling,mot,0);

 printf("\nListe mots Hybride\n");
 listeMotsTrie(t->nextChild);
*/





  /********** Menu Principal **********/
  /*system("clear");



  int choix1 = -1, choix2 = -1;

  printf("1 : Arbre de la Briandais");
  printf("\n2 : Trie Hybride");
  while(choix1 != 1 && choix1 != 2) {
    printf("\nEntrez votre choix : ");
    scanf("%d",&choix1);
  }

    if(choix1 == 1) {
        system("clear");
        printf("1 : Test Shakespeare Briandais");
        printf("\n2 : Test Base Briandais");
        printf("\n3 : Test Fusion Shakespeare Briandais");
        printf("\n4 : Test Conversion Shakespeare Briandais to Trie Hybride");
        printf("\n5 : Test Affichage structure Exemple de base");
        while(!(choix2 >= 1 && choix2 <= 5)) {
            printf("\nEntrez votre choix : ");
            scanf("%d",&choix2);
        }
        switch(choix2) {
        case 1 : system("clear"); testShakespeareBriandais(); break;
        case 2 : system("clear"); testBaseBriandais(); break;
        case 3 : system("clear"); testFusionBriandais(); break;
        case 4 : system("clear"); testConversionBriandais(); break;
        case 5 : system("clear"); testVisualizeBriandais(); break;
        default : break;
        }
    }
    else {
        system("clear");
        printf("1 : Test Shakespeare Trie Hybride");
        printf("\n2 : Test Base Trie Hybride");
        printf("\n3 : Test Conversion Shakespeare Trie Hybride to Briandais");
        while(!(choix2 >= 1 && choix2 <= 3)) {
            printf("\nEntrez votre choix : ");
            scanf("%d",&choix2);
        }
        switch(choix2) {
        case 1 : system("clear"); testShakespeareTrieHybride(); break;
        case 2 : system("clear"); testBaseTrieHybride(); break;
        case 3 : system("clear"); testConversionTrieHybride(); break;
        default : break;
        }
    }
  */
  printf("\n\n");
  return EXIT_SUCCESS;
}
