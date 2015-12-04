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
  ArbreBriandais a = arbreVide(); //Déclaration et initialisation de l'Arbre de la Briandais

  //Construction de l'Arbre de la Briandais à partir de tous les fichiers de Skahespeare
  demarrer_chrono(); nb_operations = 0;
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
void testFusionBriandais() {
  ArbreBriandais tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10,tmp11,tmp12,tmp13,tmp14,tmp15,tmp16,tmp17,tmp18,tmp19,tmp20;
  ArbreBriandais tmp21,tmp22,tmp23,tmp24,tmp25,tmp26,tmp27,tmp28,tmp29,tmp30,tmp31,tmp32,tmp33,tmp34,tmp35,tmp36,tmp37,res;
  tmp1=arbreVide();tmp2=arbreVide();tmp3=arbreVide();tmp4=arbreVide();tmp5=arbreVide();tmp6=arbreVide();tmp7=arbreVide();
  tmp8=arbreVide();tmp9=arbreVide();tmp10=arbreVide();tmp11=arbreVide();tmp12=arbreVide();tmp13=arbreVide();tmp14=arbreVide();
  tmp15=arbreVide();tmp16=arbreVide();tmp17=arbreVide();tmp18=arbreVide();tmp19=arbreVide();tmp20=arbreVide();tmp21=arbreVide();
  tmp22=arbreVide();tmp23=arbreVide();tmp24=arbreVide();tmp25=arbreVide();tmp26=arbreVide();tmp27=arbreVide();tmp28=arbreVide();
  tmp29=arbreVide();tmp30=arbreVide();tmp31=arbreVide();tmp32=arbreVide();tmp33=arbreVide();tmp34=arbreVide();tmp35=arbreVide();
  tmp36=arbreVide();tmp37=arbreVide();res=arbreVide();


  //Construction de l'Arbre de la Briandais à partir de tous les fichiers de Skahespeare
  demarrer_chrono(); nb_operations = 0;
  constructShakespeareBriandais(tmp1,"../files/Shakespeare/1henryiv.txt");
  printf("\n1 : "); stop_chrono();
  constructShakespeareBriandais(tmp2,"../files/Shakespeare/1henryvi.txt");
  printf("\n2 : "); stop_chrono();
  constructShakespeareBriandais(tmp3,"../files/Shakespeare/2henryiv.txt");
  constructShakespeareBriandais(tmp4,"../files/Shakespeare/2henryvi.txt");
  printf("\n4 : "); stop_chrono();
  constructShakespeareBriandais(tmp5,"../files/Shakespeare/3henryvi.txt");
  constructShakespeareBriandais(tmp6,"../files/Shakespeare/allswell.txt");
  printf("\n6 : "); stop_chrono();
  constructShakespeareBriandais(tmp7,"../files/Shakespeare/asyoulikeit.txt");
  constructShakespeareBriandais(tmp8,"../files/Shakespeare/cleopatra.txt");
  printf("\n8 : "); stop_chrono();
  constructShakespeareBriandais(tmp9,"../files/Shakespeare/comedy_errors.txt");
  constructShakespeareBriandais(tmp10,"../files/Shakespeare/coriolanus.txt");
  printf("\n10 : "); stop_chrono();
  constructShakespeareBriandais(tmp11,"../files/Shakespeare/cymbeline.txt");
  constructShakespeareBriandais(tmp12,"../files/Shakespeare/hamlet.txt");
  printf("\n12 : "); stop_chrono();
  constructShakespeareBriandais(tmp13,"../files/Shakespeare/henryv.txt");
  constructShakespeareBriandais(tmp14,"../files/Shakespeare/henryviii.txt");
  printf("\n14 : "); stop_chrono();
  constructShakespeareBriandais(tmp15,"../files/Shakespeare/john.txt");
  constructShakespeareBriandais(tmp16,"../files/Shakespeare/julius_caesar.txt");
  printf("\n16 : "); stop_chrono();
  constructShakespeareBriandais(tmp17,"../files/Shakespeare/lear.txt");
  constructShakespeareBriandais(tmp18,"../files/Shakespeare/macbeth.txt");
  printf("\n18 : "); stop_chrono();
  constructShakespeareBriandais(tmp19,"../files/Shakespeare/measure.txt");
  constructShakespeareBriandais(tmp20,"../files/Shakespeare/merchant.txt");
  printf("\n20 : "); stop_chrono();
  constructShakespeareBriandais(tmp21,"../files/Shakespeare/merry_wives.txt");
  constructShakespeareBriandais(tmp22,"../files/Shakespeare/midsummer.txt");
  printf("\n22 : "); stop_chrono();
  constructShakespeareBriandais(tmp23,"../files/Shakespeare/much_ado.txt");
  constructShakespeareBriandais(tmp24,"../files/Shakespeare/othello.txt");
  printf("\n24 : "); stop_chrono();
  constructShakespeareBriandais(tmp25,"../files/Shakespeare/pericles.txt");
  constructShakespeareBriandais(tmp26,"../files/Shakespeare/richardii.txt");
  printf("\n26 : "); stop_chrono();
  constructShakespeareBriandais(tmp27,"../files/Shakespeare/richardiii.txt");
  constructShakespeareBriandais(tmp28,"../files/Shakespeare/romeo_juliet.txt");
  printf("\n28 : "); stop_chrono();
  constructShakespeareBriandais(tmp29,"../files/Shakespeare/taming_shrew.txt");
  constructShakespeareBriandais(tmp30,"../files/Shakespeare/tempest.txt");
  printf("\n30 : "); stop_chrono();
  constructShakespeareBriandais(tmp31,"../files/Shakespeare/timon.txt");
  constructShakespeareBriandais(tmp32,"../files/Shakespeare/titus.txt");
  printf("\n32 : "); stop_chrono();
  constructShakespeareBriandais(tmp33,"../files/Shakespeare/troilus_cressida.txt");
  constructShakespeareBriandais(tmp34,"../files/Shakespeare/twelfth_night.txt");
  printf("\n34 : "); stop_chrono();
  constructShakespeareBriandais(tmp35,"../files/Shakespeare/two_gentlemen.txt");
  constructShakespeareBriandais(tmp36,"../files/Shakespeare/winters_tale.txt");
  printf("\n36 : "); stop_chrono();
  constructShakespeareBriandais(tmp37,"../files/Shakespeare/lll.txt");
  printf("\n37 : "); stop_chrono(); printf("\n\n");


  printf("\nConstuction par fusion en cours...\n");

  demarrer_chrono(); nb_operations = 0;
  fusionBriandaisV2(tmp1,tmp2,res);fusionBriandaisV2(tmp3,tmp4,res);fusionBriandaisV2(tmp5,tmp6,res);fusionBriandaisV2(tmp7,tmp8,res);fusionBriandaisV2(tmp9,tmp10,res);
  fusionBriandaisV2(tmp11,tmp12,res);fusionBriandaisV2(tmp13,tmp14,res);fusionBriandaisV2(tmp15,tmp16,res);fusionBriandaisV2(tmp17,tmp18,res);fusionBriandaisV2(tmp19,tmp20,res);
  fusionBriandaisV2(tmp21,tmp22,res);fusionBriandaisV2(tmp23,tmp24,res);fusionBriandaisV2(tmp25,tmp26,res);fusionBriandaisV2(tmp27,tmp28,res);fusionBriandaisV2(tmp29,tmp30,res);
  fusionBriandaisV2(tmp31,tmp32,res);fusionBriandaisV2(tmp33,tmp34,res);fusionBriandaisV2(tmp35,tmp36,res);fusionBriandaisV2(tmp37,NULL,res);


  printf("\nConstruction par fusion réussie ! Nombre d'opérations : %ld | Temps d'exécution : ",nb_operations); stop_chrono(); printf("\n\n");

  /* Affichage des différentes informations de l'arbre :
     - Nombre de mots, Nombre de pointeurs vers Nil, Hauteur, Profondeur moyenne */
  demarrer_chrono(); nb_operations = 0;
  comptageMotsBriandais_V2(res->sibling);
  printf("Comptage Mots : V1(Total tmp) %ld - V2 %d | Nb d'opérations : %ld | Temps d'exécution : ",(long int)(comptageMotsBriandais_V1()-comptageMotsBriandais_V2(res->sibling)),
            comptageMotsBriandais_V2(res->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageNilBriandais(res->sibling);
  printf("Comptage Pointeurs vers Nil : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageNilBriandais(res->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  hauteurBriandais(res->sibling);
  printf("Hauteur de l'Arbre : %d | Nb d'opérations : %ld | Temps d'exécution : ",hauteurBriandais(res->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  comptageFeuillesBriandais(res->sibling);
  printf("Comptage Feuilles : %d | Nb d'opérations : %ld | Temps d'exécution : ",comptageFeuillesBriandais(res->sibling),nb_operations);
  stop_chrono(); printf("\n");
  demarrer_chrono(); nb_operations = 0;
  profondeurMoyenneBriandaisV2(res->sibling);
  printf("Profondeur Moyenne de l'Arbre : %f --> %d | Nb d'opérations : %ld | Temps d'exécution : ",profondeurMoyenneBriandaisV2(res->sibling),
            (int)profondeurMoyenneBriandaisV2(res->sibling),nb_operations);
  stop_chrono(); printf("\n");


    char mot[50];
  //Ajout d'un mot
  printf("\nEntrez un mot à ajouter : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  ajoutMotBriandais(res,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();printf("\n");

  //Test de la fonction préfixe
  printf("Entrez une chaine afin de voir de combien de mots elle est préfixe : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  prefixeBriandais(res,mot);
  printf("\nNb de mots qui ont \'%s\' comme préfixe : %d | Nb d'opérations : %ld | Temps d'exécution : ",mot,prefixeBriandais(res,mot),nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotBriandais(res,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Suppression d'un mot
  printf("\nEntrez un mot à supprimer : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  suppressionMotBriandais_V1(res,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Recherche d'un mot
  printf("\nEntrez un mot à chercher : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  rechercheMotBriandais(res,mot);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Lister les mots
  printf("\nEntrez n'importe quel chiffre pour voir la liste des mots : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  listeMotsBriandais(res->sibling, mot, 0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeBriandais(res->sibling,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();
}

/* Construction d'un Arbre de la Briandais et Conversion en Trie Hybride */
void testConversionBriandais() {
  ArbreBriandais a = arbreVide(); //Déclaration et initialisation de l'Arbre de la Briandais

  //Construction de l'Arbre de la Briandais à partir de tous les fichiers de Skahespeare
  demarrer_chrono(); nb_operations = 0;
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
  stop_chrono(); printf("\n\n");

  TrieHybride t = trieVide();
  char mot[50];

  printf("\nConversion en cours...\n");
  demarrer_chrono(); nb_operations = 0;
  BriandaisToTrieHybrideV1(a->sibling,t,mot,0);
  printf("\nDone !\nConversion Shakespeare - Briandais to Trie Hybride : Nb opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono(); printf("\n\n");


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


  //char mot[50];
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
  listeMotsTrie(t->nextChild);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeHybrideV2(t->nextChild,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

}

/* Construction d'un Arbre de la Briandais à partir de tous les fichiers de Shakespeare et affichage d'un aperçu visuel de ce dernier */
void testVisualizeBriandais() {
  ArbreBriandais a = arbreVide();
  constructArbreBriandais(a,base,tailleBase);
  visualizeBriandais(a->sibling,0);
}



/*=======================================================*/
/*                  Tests Trie Hybride                   */
/*=======================================================*/


/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testShakespeareTrieHybride() {
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
  listeMotsTrie(t->nextChild);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeHybrideV2(t->nextChild,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();
}

/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testBaseTrieHybride() {
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
  listeMotsTrie(t->nextChild);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();

  //Et finalement, affichage de la structure
  printf("\nEntrez n'importe quel chiffre pour avoir un affichage de l'arbre : "); scanf("%s",mot);
  demarrer_chrono(); nb_operations = 0;
  visualizeHybrideV2(t->nextChild,0);
  printf("\nNb d'opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono();
}

/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare et Conversion en un Arbre de la Briandais */
void testConversionTrieHybride() {
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


  ArbreBriandais a = arbreVide();

  printf("\nConversion en cours...\n");
  demarrer_chrono(); nb_operations = 0;
  TrieHybrideToBriandaisV1(t->nextChild,a);
  printf("\nDone !\nConversion Shakespeare - Trie Hybride to Briandais : Nb opérations : %ld | Temps d'exécution : ",nb_operations);
  stop_chrono(); printf("\n\n");



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




