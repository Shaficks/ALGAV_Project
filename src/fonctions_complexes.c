/**
 * \file fonctions_complexes.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Projet ALGAV - Fichier test du programme :
 * Fichier contenant les implémentations des fonctions complexes.
 */

#include "../headers/main.h"
/*
//Fusionne les Arbres a et b dans res.
void fusionBriandais(ArbreBriandais a, ArbreBriandais b, ArbreBriandais res, ArbreBriandais parent) {
  ArbreBriandais ita, itb, prec = res, itres = res;
  if(a) ita = a;
  if(b) itb = b;

  //On commence par parcourir les noeuds de la forêt lexicographique de a
  while(ita) {
    while(itres) {
      if(toupper(itres->val) < toupper(ita->val)) {
	prec = itres;
	itres = itres->sibling;
      }
      else break;
      if(!itres) break;
    }

    //Si itres est NULL, c'est qu'on a atteint la fin de la liste ça veut dire que le noeud n'existe pas, on l'insère donc entièrement !
    if(itres == NULL) {
      prec->sibling = ita;
    }

    //Sinon, si on s'est arrêté au milieu de la liste ou au début
    else {
      if(toupper(itres->val) > toupper(ita->val)) {
	//S'il s'agit du fils direct du parent
	if(parent->child == itres) {
	  ArbreBriandais noeud = my_malloc(sizeof(*noeud));
	  noeud->val = ita->val;
	  noeud->sibling = itres;
	  noeud->child = ita->child;
	  parent->child = noeud;
	}
	//S'il s'agit d'un fils se trouvant pas directement en dessous du parent
	else {
	  ArbreBriandais noeud = my_malloc(sizeof(*noeud));
	  noeud->val = ita->val;
	  noeud->sibling = prec->sibling;
	  noeud->child = ita->child;
	  prec->sibling = noeud;
	}
      }
      else if(toupper(itres->val) == toupper(ita->val)) {
	fusionBriandais(ita->child,NULL,itres->child,itres);
      }

    }
  }
}
*/

//Fonction qui copie un Arbre de la Briandais a dans un autre b
void fusionBriandaisRec(ArbreBriandais a, ArbreBriandais res, char mot[], int profondeur) {
  ++nb_operations;
  if(!a) return;
  if(a) {
    mot[profondeur] = a->val;
    if(a->val == '\0') {
      ajoutMotBriandais(res,mot);
    }
    if(a->child)
      fusionBriandaisRec(a->child,res,mot,profondeur+1);
    if(a->sibling)
      fusionBriandaisRec(a->sibling,res,mot,profondeur);
  }
}

//Fusion 2 Arbres de la Briandais a et b dans res
void fusionBriandaisV2(ArbreBriandais a, ArbreBriandais b, ArbreBriandais res) {
  char mot[50];
  if(a)
    fusionBriandaisRec(a->sibling,res,mot,0);
  if(b)
    fusionBriandaisRec(b->sibling,res,mot,0);
}

//Convertit un Arbre de la Briandais a en un Trie Hybride t et retourne ce dernier.
void BriandaisToTrieHybrideV1(ArbreBriandais a, TrieHybride t, char mot[], int profondeur) {
  if(!a) return;
  if(a) {
    mot[profondeur] = a->val;
    if(a->val == '\0') {
      mot[profondeur] = a->val;
      ajoutMotTrie(t,mot);
    }
    if(a->child)
      BriandaisToTrieHybrideV1(a->child,t,mot,profondeur+1);
    if(a->sibling)
      BriandaisToTrieHybrideV1(a->sibling,t,mot,profondeur);
  }
}

//Convertit un Trie Hybridet t en un Arbre de la Briandais a et retourne ce dernier.
void TrieHybrideToBriandaisV1(TrieHybride t, ArbreBriandais a) {
  ++nb_operations;
  if(t) {
    if(t->cle != -1) {
      ajoutMotBriandais(a,t->mot);
    }
    if(t->inferiorChild)
      TrieHybrideToBriandaisV1(t->inferiorChild,a);
    if(t->nextChild)
      TrieHybrideToBriandaisV1(t->nextChild,a);
    if(t->superiorChild)
      TrieHybrideToBriandaisV1(t->superiorChild,a);
  }
}

//Ajout d'un mot dans un Trie suivi par un rééquilibrage si nécessaire.
TrieHybride ajoutAvecReequilibrage(TrieHybride t, char mot[]);

/* Construction d'un Trie Hybride le plus équilibré possible à partir d'une liste de mots
   Cette solution est inspirée de la Recherche Dichotomique */
void reequilibrageDichotomique(TrieHybride res, char tab[5000][50], int t_min, int t_max) {
  nb_operations++;
  if(t_max == t_min) {
    ajoutMotTrie(res,tab[t_min]);
    return;
  }
  if(t_min > t_max) return;
  int milieu = (t_min+t_max)/2;
  ajoutMotTrie(res,tab[milieu]);
  reequilibrageDichotomique(res,tab,t_min,milieu-1);
  reequilibrageDichotomique(res,tab,milieu+1,t_max);
}
