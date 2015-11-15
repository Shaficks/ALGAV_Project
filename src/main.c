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
#include "tools.c"


/* III - Liste des primitives de base d'un Arbre de la Briandais */
//Fonction qui retourne un arbre vide
ArbreBriandais arbreVide() {
  ArbreBriandais a;
  a = my_malloc(sizeof(*a));
  // a->val n'a pas besoin d'initialisation car c'est la cellule sentinelle
  a->sibling = NULL;
  a->child = NULL;
  return a;
}

//Fonction d'ajout d'un mot dans un arbre de la Briandais. Elle ne retourne rien car elle modifie directement via les pointeurs.
void ajoutMotBriandais(ArbreBriandais a, char mot[]) {
  int i, n = strlen(mot);
  ArbreBriandais it = a, prec = NULL;

  //Au cas où le mot est vide
  if(!strlen(mot)) {
    printf("Il faut un mot !\n");
    return;
  }

  //Au cas où l'arbre est vide, faire un ajout simple en utilisant la fonction correspondante.
  if(it->sibling == NULL) {
    ajoutSimpleBriandais(it,mot);
    printf("Mot \'%s\' ajouté avec succès !\n",mot);
    return;
  }
  //Au cas où l'arbre n'est pas vide
  else {
    prec = it; //Noeud précédant
    it = a->sibling; //Noeud courant

    //Parcours du mot lettre par lettre - La lettre représentant la fin du mot sera prise en compte aussi
    for(i = 0; i < n+1; i++) {
        //Boucle principale servant à parcourir les noeuds de l'arbre
        while(it) {
            //Parcours de la liste des racines de la i-ème forêt lexicographique afin de trouver la position de la i-ème lettre du mot
            while(toupper(mot[i]) > toupper(it->val)) {
                prec = it;
                it = it->sibling;
                if(!it) break; //Si it est NULL, c'est qu'on a atteint la fin de la liste, on fait donc un break;
            }

            //Au cas où le neoud est vide, ça veut dire qu'on a atteint la fin de la liste des racines de la forêt lexicographique
            if(it == NULL) {
                ajoutSimpleBriandais(prec,resteMot(mot,i)); //On effectue un ajout simple du reste du mot à partir de l'ième lettre incluse
                printf("Mot \'%s\' ajouté avec succès !\n",mot);
                return;
            }
            //Au cas où le noeud n'est pas vide
            else {
                //Si le noeud courant contient la même lettre, passage direct au fils
                if(toupper(mot[i]) == toupper(it->val)) {
                    prec = it;
                    it = it->child;
                    break;
                }
                //Sinon, si la lettre n'est pas la même, c'est qu'elle n'existe pas dans la forêt lexicgrpahique
                else {
                    //S'il s'agit du fils (La relation parent-fils sera gérée ici au niveau de la fonction principale)
                    if(prec->child == it) {
                        ArbreBriandais noeud = NULL;
                        noeud = my_malloc(sizeof(*noeud));
                        noeud->val = mot[i];
                        noeud->sibling = it;
                        noeud->child = NULL;
                        prec->child = noeud;
                        it = prec->child;
                        int j;
                        for(j = i+1; j < n+1; j++, it = it->child) {
                          noeud = my_malloc(sizeof(*noeud));
                          noeud->val = mot[j];
                          noeud->sibling = NULL;
                          noeud->child = NULL;
                          it->child = noeud;
                        }
                        printf("Mot \'%s\' ajouté avec succès !\n",mot);
                        return;
                    }
                    //S'il s'agit d'un frère du fils, appel à la fonction d'ajout simple
                    else {
                        ajoutSimpleBriandais(prec,resteMot(mot,i));
                        printf("Mot \'%s\' ajouté avec succès !\n",mot);
                        return;
                    }
                }
            }
        }
    }
  }
  printf("Le mot \'%s\' existe déjà dans l'Arbre !!!\n",mot);
}

//Fonction d'ajout simple d'un mot dans un arbre de la Briandais, utilisée quand l'arbre est vide. (Elle ne retourne rien car elle modifie via les pointeurs)
void ajoutSimpleBriandais(ArbreBriandais a, char mot[]) {
    int i, n = strlen(mot);
    ArbreBriandais it = NULL, noeud = NULL;
    it = a;

    //Si le noeud n'a pas de frère
    if(it->sibling == NULL) {
        //Ajout de la première lettre et avancement de l'itérateur
        noeud = my_malloc(sizeof(*noeud));
        noeud->val = mot[0];
        noeud->sibling = NULL;
        noeud->child = NULL;
        it->sibling = noeud;
        it = it->sibling;
    }
    //Sinon
    else {
        //Ajout de la première lettre et modification des pointeurs
        noeud = my_malloc(sizeof(*noeud));
        noeud->val = mot[0];
        noeud->sibling = it->sibling;
        noeud->child = NULL;
        it->sibling = noeud;
        it = it->sibling;
    }

    //Ajout des lettres suivantes
    for(i = 1; i < n+1; i++, it = it->child) {
        noeud = my_malloc(sizeof(*noeud));
        noeud->val = mot[i];
        noeud->sibling = NULL;
        noeud->child = NULL;
        it->child = noeud;
    }
}

//Fonction qui construit un arbre de la Briandais à partir d'une liste de mots.
void constructArbreBriandais(ArbreBriandais a, char** mots, int taille) {
    int i;
    for(i = 0; i < taille; i++)
        ajoutMotBriandais(a, mots[i]);
}

//Retourne 1 si l'arbre est vide, 0 sinon.
int estArbreVide(ArbreBriandais a) {
  return a->sibling == NULL;
}

//Retourne la valeur de la racine du premier arbre de a.
char valAB(ArbreBriandais a) {
  return a->sibling->val;
}

//Retourne (Une copie de - A Faire !!!) l'ième arbre de la forêt lexicographique
ArbreBriandais iemeArbre(ArbreBriandais a, int i) {
    int cpt;
    ArbreBriandais it = NULL;

    if(!a) {
        printf("\nIl faut un arbre non vide !\n");
        return NULL;
    }

    //Une boucle qui nous sert juste à parcourir la liste des racine de l'arbre jusqu'au i-ème élément
    for(cpt = 1, it = a; cpt < i && it != NULL; cpt++, it = it->sibling);

    if(!it) {
        printf("\nL'arbre contient moins que %d éléments !\n",i);
        return NULL;
    }
    else {
        ArbreBriandais resultat = arbreVide();
        resultat->sibling = it;
        return resultat;
    }

}

//Retourne la liste de tous les arbres privée du ième arbre
ArbreBriandais tousFreresSauf(ArbreBriandais a, int i) {
    int cpt;
    ArbreBriandais it, resultat = arbreVide();

    if(!a) {
        printf("\nIl faut un arbre non vide !\n");
        return NULL;
    }

    //Une boucle qui nous sert juste à parcourir la liste des racine de l'arbre jusqu'au i-1 ème élément
    for(cpt = 1, it = a; cpt < i-1 && it != NULL; cpt++, it = it->sibling);

    if(!it) {
        printf("\nL'arbre contient moins que %d éléments !\n",i);
    }
    else {
        it->sibling = it->sibling->sibling;
    }
    resultat->sibling = a;
    return resultat;
}

//Retourne l'Arbre formé avec T en i-ème position, A REVOIR AVEC LA PROF : PROBLEME DE DUPLICATION !!!
ArbreBriandais insertArbreBriandais(ArbreBriandais a, ArbreBriandais ai, int i) {
    int cpt;
    ArbreBriandais it, prec, resultat = arbreVide();

    if(!a) {
        if(ai) {
            resultat->sibling = ai;
            return resultat;
        }
        else {
            printf("\nIl faut un arbre non vide !\n");
            return NULL;
        }
    }

    //Une boucle qui nous sert juste à parcourir la liste des racine de l'arbre jusqu'au i-1 ème élément
    for(cpt = 1, it = a; cpt < i-1 && it != NULL; cpt++, prec = it, it = it->sibling);

    if(!it) {
        printf("\nL'arbre contient moins que %d éléments !\n",i);
        prec->sibling = ai;
    }
    else {
        //Ici on suppose que la racine ai n'existe pas dans l'arbre a, sinon on aura une duplication
        ai->sibling = it->sibling;
        it->sibling = ai;
    }
    resultat->sibling = a;
    return resultat;
}



/* IV - Liste des primitives de base d'un Trie Hybride */
//Retourne un Trie Hybride réduit à un noeud avec 3 liens vides.
TrieHybride trieVide() {
  TrieHybride t;
  t = my_malloc(sizeof(*t));
  // t->val n'a pas besoin d'initialisation car c'est la cellule sentinelle
  t->superiorChild = NULL;
  t->inferiorChild = NULL;
  t->nextChild = NULL;
  return t;
}

//Ajoute un mot au Trie t et retourne le Trie résultat.
void ajoutMotTrie(TrieHybride t, char mot[]) {

    //Au cas où l'arbre est vide
    if(!t->nextChild) {
        ajoutSimpleTrie(t,mot);
        printf("\nLe mot \'%s\' a été ajouté avec succès !\n",mot);
        return;
    }


}

//Ajoute un mot au Trie t et retourne le Trie résultat.
void ajoutSimpleTrie(TrieHybride t, char mot[]) {
    int i, n = strlen(mot);
    TrieHybride it = t;

    if(!t->nextChild) {
        TrieHybride noeud;
        for(i = 0; i < n+1; i++) {
          noeud = my_malloc(sizeof(*noeud));
          noeud->val = mot[i];
          noeud->superiorChild = NULL;
          noeud->inferiorChild = NULL;
          noeud->nextChild = NULL;
          it->nextChild = (TrieHybride)noeud;
          it = (TrieHybride)it->nextChild;
        }
    }
}

//Construit un Trie Hybride à partir d'un dictionnaire donné.
void constructTrieHybride(char** dictionnaire);

//Retourne 1(VRAI) si le Trie est vide, 0(FAUX) sinon.
int estTrieVide(TrieHybride t);

//Retourne la valeur de la racine du Trie.
char valTH(TrieHybride t);

//Retourne une copie du i-ème sous arbre du Trie t. (1 =< i >= 3 car c'est un Trie Hybride)
TrieHybride sousArbreTH(TrieHybride t, int i);

//Retourne la liste des sous-arbres du Trie t privée du i-ème sous-arbre.
TrieHybride tousFilsSauf(TrieHybride t, int i);

//Retourne le Trie formé avec T en i-ème sous arbre inséré dans la liste (1 <= i <= 3).
TrieHybride H_Trie(int i, TrieHybride* tList, TrieHybride t);


int main(void) {

  TrieHybride t = trieVide();


  ajoutMotTrie(t, "Chafik");

  printf("\n%c\n",t->nextChild->val);
  /*
  printf("\n%c\n",t->nextChild->nextChild->val);
  printf("\n%c\n",t->nextChild->nextChild->nextChild->val);
  printf("\n%c\n",t->nextChild->nextChild->nextChild->nextChild->val);
  */





  /*
  ArbreBriandais a = arbreVide(), tmp;
  constructArbreBriandais(a,base,tailleBase);

  //a = iemeArbre(a->sibling,3);
  //a = tousFreresSauf(a->sibling,3);
  tmp = iemeArbre(a->sibling,3);
  a = insertArbreBriandais(a->sibling,tmp->sibling,2);
  ArbreBriandais c = a->sibling->sibling;

  //ArbreBriandais c = a->sibling->sibling->sibling;
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
