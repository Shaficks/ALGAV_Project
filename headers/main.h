/**
 * \file main.h
 * \brief Bibliothèque contenant les déclarations des structures, des variables globales, des différentes
          fonctions et procédures ainsi que les bibliothèques utilisées dans le programme.
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Header du main.c pour le projet "Projet ALGAV" -
 */
#ifndef HEADER
#define HEADER

/********** Variables globales et Macros **********/
#define VRAI 1
#define FAUX 0


char graph[5000][20]; //Tableau qui contiendra le code GraphViz qui sera généré par la fonction graphViz
char tab[50000][50]; //Tableau de chaines de caractères qui sera utilisé dans la fonction reequilibrageDichotomique
int tailleTab = 0; //Taille du tableau de chaines de caractères tab

//nb_feuilles et prof_totale_feuilles seront utilisées pour calculer la profondeur moyenne d'un Arbre.
float nb_feuilles = 0;
float prof_totale_feuilles = 0;

long int nb_operations = 0; //Variable globale servant à calculer le nombre d'opérations effectuées par les fonctions.
long int nbMotsBriandais = 0; //Entier représentant le nombre de mots de l'Arbre de la Briandais
long int nbMotsHybride = 0; //Entier représentant le nombre de mots du Trie Hybride
int tailleBase = 40; //Taille de la liste de mots courante. à revoir.
char* base[] = {"A","quel","genial","professeur","de","dactylographie","sommes","nous","redevables","de","la","superbe","phrase",
		"ci","dessous","un","modele","du","genre","que","toute","dactylo","connait","par","coeur","puisque","elle","fait",
		"appel","a","chacune","des","touches","du","clavier","de","la","machine","a","ecrire"};
int tailleShakespeare = 0; //Taille de la liste de mots d'une oeuvre quelconque de Shakespeare
char** shakespeare; //Tableau contenant les mots d'une oeuvre de Shakespeare

/********** I - Bibliothèques utilisées dans le programme **********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/********** II - Différents types et structures utilisés dans le programme **********/

/**
 * \typedef ArbreBriandais
 * \brief Type représentant un Arbre de la Briandais, il contient un pointeur vers la racine de l'arbre.
 *        Lors de la déclaration d'une variable, le pointeur (*) sera caché dans le type.
 */
typedef struct Briandais* ArbreBriandais;

/**
 * \struct Briandais
 * \brief Structure représentant un noeud d'un Arbre de la Briandais.
 */
struct Briandais {
  char val; /*!< Valeur contenue dans le noeud. */
  ArbreBriandais sibling; /*!< Pointeur sur le frère suivant. */
  ArbreBriandais child; /*!< Pointeur sur le premier fils. */
};


/**
 * \typedef TrieHybride
 * \brief Type représentant un Trie Hybride, il contient un pointeur vers la racine du Trie.
 */
typedef struct Hybride* TrieHybride;

/**
 * \struct Hybride
 * \brief Structure représentant un noeud d'un Arbre de la Briandais
 */
struct Hybride {
  char mot[50]; /*!< Mot correspondant si le noeud contient une clé.*/
  long int cle; /*!< Champs indiquant si le noeud représente une clé ou pas. (-1 si le noeud ne représente pas une clé, le n° de la clé sinon.)*/
  char val; /*!< Champs représentant le caractère contenu dans le noeud. */
  TrieHybride superiorChild; /*!< Pointeur sur le noeud fils supérieur. (Représente le caractère supérieur remplaçant le noeud courant)*/
  TrieHybride inferiorChild; /*!< Pointeur sur le noeud fils inférieur. (Représente le caractère inférieur remplaçant le noeud courant)*/
  TrieHybride nextChild; /*!< Pointeur sur le noeud fils suivant. (Représente le caractère i+1 d'un mot contenant le parent en position i)*/
};


/********** III - Liste des primitives de base d'un Arbre de la Briandais - Implémentation dans arbreBriandais.c **********/
ArbreBriandais arbreVide(); //Retourne un Arbre de la Briandais réduit à un noeud avec 2 liens vides.
void ajoutMotBriandais(ArbreBriandais a, char mot[]); //Ajoute un mot à l'arbre a et retourne l'Arbre résultat.
void ajoutSimpleBriandais(ArbreBriandais a, char mot[]); //Ajout simple d'un mot. Utilisée quand la ième lettre n'existe pas dans les racines de la forêt.
void constructArbreBriandais(ArbreBriandais a, char** dictionnaire, int taille); //Construit un Arbre de la Briandais à partir d'un dictionnaire donné.
int estArbreVide(ArbreBriandais a); //Retourne 1(VRAI) si l'Arbre est vide, 0(FAUX) sinon.
int estFeuilleBriandais(ArbreBriandais a); //Retourne 1(VRAI) si le neoud est une feuille, 0(FAUX) sinon.
int comptageFeuillesBriandais(ArbreBriandais a); //Retourne le nombre de feuilles de l'Arbre de la Briandais.
char valAB(ArbreBriandais a); //Retourne la valeur de la racine du premier arbre de a.
ArbreBriandais iemeArbre(ArbreBriandais a, int i); //Retourne une copie du i-ème arbre de la forêt lexicographique(Arbre de la Briandais).
ArbreBriandais tousFreresSauf(ArbreBriandais a, int i); //Retourne la liste de tous les Arbres de la forêt lexicographique a privée du i-ème Arbre.
ArbreBriandais insertArbreBriandais(ArbreBriandais a, ArbreBriandais ai, int i); //Retourne l'Arbre formé avec T en i-ème position

/********** IV - Liste des primitives de base d'un Trie Hybride - Implémentation dans trieHybride.c **********/
TrieHybride trieVide(); //Retourne un Trie Hybride réduit à un noeud avec 3 liens vides.
void ajoutMotTrie(TrieHybride t, char mot[]); //Ajoute un mot au Trie t et retourne le Trie résultat.
void ajoutSimpleTrie(TrieHybride t, char mot[], char original[], int option); //Ajout simple d'un mot. Utilisée quand la ième lettre n'existe pas dans les racines du Trie.
void constructTrieHybride(TrieHybride t, char** dictionnaire, int taille); //Construit un Trie Hybride à partir d'un dictionnaire donné.
int estTrieVide(TrieHybride t); //Retourne 1(VRAI) si le Trie est vide, 0(FAUX) sinon.
int estFeuilleTrie(TrieHybride t); //Retourne 1(VRAI) si le noeud est une feuille, 0(FAUX) sinon.
/* Retourne 1(VRAI) si le Trie t est déséquilibré, 0(FAUX) sinon.
  (Un écart maximal autorisé demandé par la fonction doit être saisi au clavier)*/
int estDesequilibre(TrieHybride t);
int comptageFeuillesTrie(TrieHybride t); //Retourne le nombre de feuilles du Trie Hybride.
char valTH(TrieHybride t); //Retourne la valeur de la racine du Trie.
TrieHybride sousArbreTH(TrieHybride t, int i); //Retourne une copie du i-ème sous arbre du Trie t. (1 =< i >= 3 car c'est un Trie Hybride)
TrieHybride tousFilsSauf(TrieHybride t, int i); //Retourne la liste des sous-arbres du Trie t privée du i-ème sous-arbre.
TrieHybride insertTrieHybride(TrieHybride t, TrieHybride ti, int i); //Retourne le Trie formé avec T en i-ème sous arbre inséré dans la liste (1 <= i <= 3).

/********** V - Liste des fonctions avancées pour les Arbres de la Briandais - Implémentation dans arbreBriandais.c **********/
int rechercheMotBriandais(ArbreBriandais a, char mot[]); //Retourne 1(VRAI) si le mot existe dans l'Arbre a, 0(FAUX) sinon.
long int comptageMotsBriandais_V1(); //Retourne le nombre de mots présents dans l'Arbre a. Solution simple | Complexité O(1)
int comptageMotsBriandais_V2(ArbreBriandais a); //Retourne le nombre de mots présents dans l'Arbre a. Solution complexe | Appel récursif sur les noeuds de l'Arbre de la Briandais.
void listeMotsBriandais(ArbreBriandais a, char mot[], int profondeur); //Retourne la liste des mots présents dans l'Arbre a triés dans l'ordre alphabétique.
int comptageNilBriandais(ArbreBriandais a); //Retourne le nombre de pointeurs vers Nil présents dans l'Arbre a.
int hauteurBriandais(ArbreBriandais a); //Calcule et retourne la hauteur de l'Arbre a.
int profondeurTotaleBriandais(ArbreBriandais a, int n); //Calcule et retourne la somme des profondeurs des feuilles de l'Arbre a. n départ = 0.
float profondeurMoyenneBriandais(ArbreBriandais a); //Calcule et retourne la profondeur moyenne des feuilles de l'Arbre a.
/* Calcule le nombre de feuilles du Trie et la somme de leurs profondeurs et stocke les résultats dans des variables globales.
  nb_feuilles et prof_totale_feuilles */
void profondeursFeuilles(ArbreBriandais a, int profondeur);
float profondeurMoyenneBriandaisV2(ArbreBriandais a); /* Calcule et retourne le résultat de la division de nb_feuilles par prof_totale_feuilles */
int prefixeBriandais(ArbreBriandais a, char mot[]); //Retourne le nombre de mots présents dans l'Arbre a pour lesquels le mot donné est préfixe.
void suppressionMotBriandais_V1(ArbreBriandais a, char mot[]); //Supprime un mot de l'Arbre a et retourne l'Arbre résultat | Version Simple
void suppressionMotBriandais_V2(ArbreBriandais a, char mot[]); //Supprime un mot de l'Arbre a et retourne l'Arbre résultat | Version Complexe
void suppressionListeBriandais(ArbreBriandais a, char** liste, int taille); //Suppression d'un ensemble de mots(liste) d'un Arbre de la Briandais(a).
int compteBriandais(ArbreBriandais a); //Calcule et retourne le nombre de noeuds d'un Arbre de la Briandais

/********** VI - Liste des fonctions avancées pour les Tries Hybrides - Implémentation dans trieHybride.c **********/
int rechercheMotTrie(TrieHybride t, char mot[]); //Retourne 1(VRAI) si le mot existe dans le Trie a, 0(FAUX) sinon.
long int comptageMotsTrie_V1(); //Retourne le nombre de mots présents dans le Trie t. Solution Simple | Complexité O(1)
int comptageMotsTrie_V2(TrieHybride t); //Retourne le nombre de mots présents dans le Trie t. Solution Complexte | Appel récursif sur les noeuds du Trie Hybride.
void listeMotsTrie(TrieHybride t); //Retourne la liste des mots présents dans le Trie t triés dans l'ordre alphabétique.
int comptageNilTrie(TrieHybride t); //Retourne le nombre de pointeurs vers Nil présents dans le Trie t.
int hauteurTrie(TrieHybride t); //Calcule et retourne la hauteur du Trie t.
int minProfondeurTrie(TrieHybride t); //Calcule et retourne la profondeur minimale du Trie t.
int profondeurTotaleTrie(TrieHybride t, int n); //Retourne la somme des profondeurs de toutes les feuilles du Trie. n = 0 lors de l'appel.
float profondeurMoyenneTrie(TrieHybride t); //Calcule et retourne la profondeur moyenne des feuilles du Trie t.
/*Calcule le nombre de feuilles du Trie et la somme de leurs profondeurs et stocke les résultats dans des variables globales.
  nb_feuilles et prof_totale_feuilles */
void profondeursFeuillesTrie(TrieHybride t, int profondeur);
float profondeurMoyenneTrieV2(TrieHybride t); /* Calcule et retourne le résultat de la division de nb_feuilles par prof_totale_feuilles */
int prefixeTrie(TrieHybride t, char mot[]); //Retourne le nombre de mots présents dans le Trie t pour lesquels le mot donné est préfixe et les affiche.
void suppressionMotTrie_V1(TrieHybride t, char mot[]); //Supprime un mot du Trie t et retourne le Trie résultat | Version Simple
void suppressionMotTrie_V2(TrieHybride t, char mot[]); //Supprime un mot du Trie t et retourne le Trie résultat | Version Complexe
void suppressionListeHybride(TrieHybride t, char** liste, int taille); //Suppression d'un ensemble de mots(liste) d'un Trie Hybride(t).
void listeMotsTrieTab(TrieHybride t); //Stocke dans le tableau global tab la liste des mots présents dans le Trie t triés dans l'ordre alphabétique.
int compteHybride(TrieHybride t); //Calcule et retourne le nombre de noeuds d'un Trie Hybride.

/********** VII - Liste des fonctions complextes pour les 2 structures - Implémentation dans fonctions_complexes.c **********/
void fusionBriandais(ArbreBriandais a, ArbreBriandais b, ArbreBriandais res, ArbreBriandais parent); //Fusionne les Arbres a et b dans res.
void fusionBriandaisRec(ArbreBriandais a, ArbreBriandais res, char mot[], int profondeur) ; //Fonction qui copie un Arbre de la Briandais a dans un autre b
void fusionBriandaisV2(ArbreBriandais a, ArbreBriandais b, ArbreBriandais res); //Fusion 2 Arbres de la Briandais a et b dans res
TrieHybride BriandaisToTrieHybride(ArbreBriandais a); //Convertit un Arbre de la Briandais en Trie Hybride et retourne ce dernier.
ArbreBriandais TrieHybrideToBriandais(TrieHybride t); //Convertit un Trie Hybride en Arbre de la Briandais et retourne ce dernier.
/* Convertit un Arbre de la Briandais a en Trie Hybride t et retourne ce dernier - Version simple */
void BriandaisToTrieHybrideV1(ArbreBriandais a, TrieHybride t, char mot[], int profondeur);
/* Convertit un Trie Hybride t en un Arbre de la Briandais a et retourne ce dernier */
void TrieHybrideToBriandaisV1(TrieHybride t, ArbreBriandais a);
TrieHybride ajoutAvecReequilibrage(TrieHybride t, char mot[]); //Ajout d'un mot dans un Trie suivi par un rééquilibrage si nécessaire.
/* Construction d'un Trie Hybride le plus équilibré possible à partir d'une liste de mots
   Cette solution est inspirée de la Recherche Dichotomique */
void reequilibrageDichotomique(TrieHybride res, char tab[5000][50], int t_min, int t_max);

/********** VIII - Fonction utilitaires - Implémentation dans tools.c **********/
void chargerMots(); //Charge la liste des mots du fichier donné dans la liste de mots globale.
void afficheListeMots(); //Affiche la liste des mots du Tableau global contenant l'exemple de base
void *my_malloc(size_t size); //Alloue de la memoire avec malloc mais quitte le programme en cas de probleme
char* resteMot(char mot[], int i); //Renvoie le reste d'un mot à partir d'une position i - ième lettre incluse.
int max2(int a, int b); //Fonction qui retourne l'entier le plus grand entre a et b
int max3(int a, int b, int c); //Fonction qui retourne l'entier le plus grand entre a, b et c
int min3(int a, int b, int c); //Fonction qui retourne l'entier le plus petit entre a, b et c
void freeBriandais(ArbreBriandais a); //Fonction qui, à partir d'une racine d'un arbre de la briandais, supprime tout l'arbre en libérant l'espace mémoire.
void freeHybride(TrieHybride t); //Fonction qui, à partir d'une racine d'un Trie Hybride, supprime tout le Trie en libérant l'espace mémoire.
int compteBriandais(ArbreBriandais a); //Calcule et retourne le nombre de noeuds d'un Arbre de la Briandais
int compteHybride(TrieHybride t); //Calcule et retourne le nombre de noeuds d'un Trie Hybride.
void graphViz(TrieHybride t, int profondeur); //Sert à générer du Code GraphViz à partir du Trie t (N'est pas tout à fait au point)

/********** IX - Fonctions d'affichage des Structures **********/
void visualizeBriandais(ArbreBriandais a, int profondeur); //Fonction qui affiche un aperçu visuel d'un arbre de la Briandais.
void visualizeHybrideV2(TrieHybride t, int profondeur); //Fonction qui affiche un aperçu visuel d'un Trie Hybride.
/* Fonction qui affiche un aperçu visuel du Trie Hybride t et stocke le code XML correspondant à l'arbre dans le fichier Trie.xml */
/* Servira à visualiser le Trie plus tard en visualisant l'hiérarchie du fichier Trie.xml */
void visualizeHybrideXML(TrieHybride t, int profondeur);

/********** Fonctions de construction à partir d'un fichier de Shakespeare **********/
void constructShakespeareBriandais(ArbreBriandais a, char chemin[]);
void constructShakespeareTrie(TrieHybride t, char chemin[]);

/********** Fonctions de tests - Impémentation dans test.c **********/

/*************** ARBRES DE LA BRIANDAIS ***************/
/* Construction d'un Arbre de la Briandais à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testShakespeareBriandais();
/* Construction d'un Arbre de la Briandais à partir de l'exemple de base afin d'y effectuer certaines opérations */
void testBaseBriandais();
/* Construction par Fusion d'arbres */
void testFusionBriandais();
/* Construction d'un Arbre de la Briandais et Conversion en Trie Hybride */
void testConversionBriandais();
/* Construction d'un Arbre de la Briandais à partir de tous les fichiers de Shakespeare et affichage d'un aperçu visuel de ce dernier */
void testVisualizeBriandais();
/*************** TRIES HYBRIDES ***************/
/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testShakespeareTrieHybride();
/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare afin d'y effectuer différentes opérations */
void testBaseTrieHybride();
/* Construction d'un Trie Hybride à partir de tous les fichiers de Shakespeare et Conversion en un Arbre de la Briandais */
void testConversionTrieHybride();
/* Construction d'un Trie Hybride à partir de l'Exemple de Base et Rééquilibrage du Trie en utilisant le rééquilibrage façon dichotomique */
void testReequilibrageDichotomiqueTrieHybride();

#endif
