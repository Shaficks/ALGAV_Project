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

/* Variables globales et Macros */
#define VRAI 1
#define FAUX 0

long int nbMotsBriandais = 0; //Entier représentant le nombre de mots de l'Arbre de la Briandais
long int nbMotsHybride = 0; //Entier représentant le nombre de mots du Trie Hybride
int tailleBase = 40; //Taille de la liste de mots courante. à revoir.
char* base[] = {"A","quel","genial","professeur","de","dactylographie","sommes","nous","redevables","de","la","superbe","phrase",
		"ci","dessous","un","modele","du","genre","que","toute","dactylo","connait","par","coeur","puisque","elle","fait",
		"appel","a","chacune","des","touches","du","clavier","de","la","machine","a","ecrire"};
char** shakespeare;

/* I - Bibliothèques utilisées dans le programme */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* II - Différents types et structures utilisés dans le programme */


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
  //On doit rajouter un entier pour stocker le nombre de mots - A VOIR (Peut être utiliser une union??? OU une variable GLOBALE???)
  char val;           /*!< Valeur contenue dans le noeud. */
  ArbreBriandais sibling;  /*!< Pointeur sur le frère suivant. */
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
  long int cle;       /*!< Champs indiquant si le noeud représente une clé ou pas. (-1 si le noeud ne représente pas une clé, le n° de la clé sinon.)*/
  char val;           /*!< Champs représentant le caractère contenu dans le noeud. */
  TrieHybride superiorChild; /*!< Pointeur sur le noeud fils supérieur. (Représente le caractère supérieur remplaçant le noeud courant)*/
  TrieHybride inferiorChild; /*!< Pointeur sur le noeud fils inférieur. (Représente le caractère inférieur remplaçant le noeud courant)*/
  TrieHybride nextChild; /*!< Pointeur sur le noeud fils suivant. (Représente le caractère i+1 d'un mot contenant le parent en position i)*/
};


/* III - Liste des primitives de base d'un Arbre de la Briandais */
ArbreBriandais arbreVide(); //Retourne un Arbre de la Briandais réduit à un noeud avec 2 liens vides.
void ajoutMotBriandais(ArbreBriandais a, char mot[]); //Ajoute un mot à l'arbre a et retourne l'Arbre résultat.
void ajoutSimpleBriandais(ArbreBriandais a, char mot[]); //Ajout simple d'un mot. Utilisée quand la ième lettre n'existe pas dans les racines de la forêt.
void constructArbreBriandais(ArbreBriandais a, char** dictionnaire, int taille); //Construit un Arbre de la Briandais à partir d'un dictionnaire donné.
int estArbreVide(ArbreBriandais a); //Retourne 1(VRAI) si l'Arbre est vide, 0(FAUX) sinon.
char valAB(ArbreBriandais a); //Retourne la valeur de la racine du premier arbre de a.
ArbreBriandais iemeArbre(ArbreBriandais a, int i); //Retourne une copie du i-ème arbre de la forêt lexicographique(Arbre de la Briandais).
ArbreBriandais tousFreresSauf(ArbreBriandais a, int i); //Retourne la liste de tous les Arbres de la forêt lexicographique a privée du i-ème Arbre.
ArbreBriandais insertArbreBriandais(ArbreBriandais a, ArbreBriandais ai, int i); //Retourne l'Arbre formé avec T en i-ème position

/* IV - Liste des primitives de base d'un Trie Hybride */
TrieHybride trieVide(); //Retourne un Trie Hybride réduit à un noeud avec 3 liens vides.
void ajoutMotTrie(TrieHybride t, char mot[]); //Ajoute un mot au Trie t et retourne le Trie résultat.
void ajoutSimpleTrie(TrieHybride t, char mot[], int option); //Ajout simple d'un mot. Utilisée quand la ième lettre n'existe pas dans les racines du Trie.
void constructTrieHybride(TrieHybride t, char** dictionnaire, int taille); //Construit un Trie Hybride à partir d'un dictionnaire donné.
int estTrieVide(TrieHybride t); //Retourne 1(VRAI) si le Trie est vide, 0(FAUX) sinon.
char valTH(TrieHybride t); //Retourne la valeur de la racine du Trie.
TrieHybride sousArbreTH(TrieHybride t, int i); //Retourne une copie du i-ème sous arbre du Trie t. (1 =< i >= 3 car c'est un Trie Hybride)
TrieHybride tousFilsSauf(TrieHybride t, int i); //Retourne la liste des sous-arbres du Trie t privée du i-ème sous-arbre.
TrieHybride insertTrieHybride(TrieHybride t, TrieHybride ti, int i); //Retourne le Trie formé avec T en i-ème sous arbre inséré dans la liste (1 <= i <= 3).

/* V - Liste des fonctions avancées pour les Arbres de la Briandais */
int rechercheMotBriandais(ArbreBriandais a, char mot[]); //Retourne 1(VRAI) si le mot existe dans l'Arbre a, 0(FAUX) sinon.
long int comptageMotsBriandais_V1(); //Retourne le nombre de mots présents dans l'Arbre a. Solution simple | Complexité O(1)
int comptageMotsBriandais_V2(ArbreBriandais a); //Retourne le nombre de mots présents dans l'Arbre a. Solution complexe | Appel récursif sur les noeuds de l'Arbre de la Briandais.
char** listeMotsBriandais(ArbreBriandais a); //Retourne la liste des mots présents dans l'Arbre a triés dans l'ordre alphabétique.
int comptageNilBriandais(ArbreBriandais a); //Retourne le nombre de pointeurs vers Nil présents dans l'Arbre a.
int hauteurBriandais(ArbreBriandais a); //Calcule et retourne la hauteur de l'Arbre a.
int profondeurMoyenneBriandais(ArbreBriandais a); //Calcule et retourne la profondeur moyenne des feuilles de l'Arbre a.
int prefixeBriandais(ArbreBriandais a, char mot[]); //Retourne le nombre de mots présents dans l'Arbre a pour lesquels le mot donné est préfixe et les affiche.
void suppressionMotBriandais_V1(ArbreBriandais a, char mot[]); //Supprime un mot de l'Arbre a et retourne l'Arbre résultat | Version Simple 
void suppressionMotBriandais_V2(ArbreBriandais a, char mot[]); //Supprime un mot de l'Arbre a et retourne l'Arbre résultat | Version Complexe

/* VI - Liste des fonctions avancées pour les Tries Hybrides */
int rechercheMotTrie(TrieHybride t, char mot[]); //Retourne 1(VRAI) si le mot existe dans le Trie a, 0(FAUX) sinon.
long int comptageMotsTrie_V1(); //Retourne le nombre de mots présents dans le Trie t. Solution Simple | Complexité O(1)
int comptageMotsTrie_V2(TrieHybride t); //Retourne le nombre de mots présents dans le Trie t. Solution Complexte | Appel récursif sur les noeuds du Trie Hybride.
char** listeMotsTrie(TrieHybride t); //Retourne la liste des mots présents dans le Trie t triés dans l'ordre alphabétique.
int comptageNilTrie(TrieHybride t); //Retourne le nombre de pointeurs vers Nil présents dans le Trie t.
int hauteurTrie(TrieHybride t); //Calcule et retourne la hauteur du Trie t.
int profondeurMoyenneTrie(ArbreBriandais t); //Calcule et retourne la profondeur moyenne des feuilles du Trie t.
int prefixeTrie(TrieHybride t, char mot[]); //Retourne le nombre de mots présents dans le Trie t pour lesquels le mot donné est préfixe et les affiche.
void suppressionMotTrie_V1(TrieHybride t, char mot[]); //Supprime un mot du Trie t et retourne le Trie résultat | Version Simple
void suppressionMotTrie_V2(TrieHybride t, char mot[]); //Supprime un mot du Trie t et retourne le Trie résultat | Version Complexe

/* VII - Liste des fonctions complextes pour les 2 structures */
ArbreBriandais fusionBriandais(ArbreBriandais a1, ArbreBriandais a2); //Fusionne les Arbres a1 et a2 et retourne l'Arbre résultat.
TrieHybride BriandaisToTrieHybride(ArbreBriandais a); //Convertit un Arbre de la Briandais en Trie Hybride et retourne ce dernier.
ArbreBriandais TrieHybrideToBriandais(TrieHybride t); //Convertit un Trie Hybride en Arbre de la Briandais et retourne ce dernier.
TrieHybride ajoutAvecReequilibrage(TrieHybride t, char mot[]); //Ajout d'un mot dans un Trie suivi par un rééquilibrage si nécessaire.


/* VIII - Fonction utilitaires */
void chargerMots(); //Charge la liste des mots du fichier donné dans la liste de mots globale. (A REPARER)
void afficheBriandaisSDL(ArbreBriandais a); //Affiche l'Arbre a en SDL.
void afficheTrieHybrideSDL(TrieHybride t); //Affiche le Trie t en SDL.
void menuPrincipal(); //Menu permettant d'utiliser l'ensemble des fonctionnalités du programme. (à détailler)
void *my_malloc(size_t size); //alloue de la memoire avec malloc mais quitte le programme en cas de probleme
char* resteMot(char mot[], int i); //Renvoie le reste d'un mot à partir d'une position i - ième lettre incluse.

#endif
