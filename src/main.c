/**
 * /file main.c
 * /brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * /author Chafik NOUIRA
 * /date 24 octobre 2015
 * /version 1.0
 *0
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
  int n = strlen(mot);

  //Au cas où le mot est vide
  if(!strlen(mot)) {
    printf("Il faut un mot !\n");
    return;
  }

  //Au cas où l'arbre est vide, faire un ajout simple en utilisant la fonction correspondante.
  if(a->sibling == NULL) {
    ajoutSimpleBriandais(a,mot);
    printf("Mot \'%s\' ajouté avec succès !\n",mot);
    nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
    return;
  }
  //Au cas où l'arbre n'est pas vide
  else {
    int i;
    ArbreBriandais it = a, prec;
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
                nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
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
                        nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
                        return;
                    }
                    //S'il s'agit d'un frère du fils, appel à la fonction d'ajout simple
                    else {
                        ajoutSimpleBriandais(prec,resteMot(mot,i));
                        printf("Mot \'%s\' ajouté avec succès !\n",mot);
                        nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
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

    //Ajout de la première lettre et modification des pointeurs afin de valider l'insertion
    //P.S : La première version gérait 2 cas : Insertion au milieu et en fin de la liste
    noeud = my_malloc(sizeof(*noeud));
    noeud->val = mot[0];
    noeud->sibling = it->sibling;
    noeud->child = NULL;
    it->sibling = noeud;
    it = it->sibling;

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
void constructArbreBriandais(ArbreBriandais a, char** dictionnaire, int taille) {
    int i;
    for(i = 0; i < taille; i++)
        ajoutMotBriandais(a, dictionnaire[i]);
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
        it->sibling = NULL;
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
        //Ici on suppose que la racine 'ai' n'existe pas dans l'arbre a, sinon on aura une duplication
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
  // t->cle et t->val n'ont pas besoin d'initialisation car c'est la cellule sentinelle
  t->superiorChild = NULL;
  t->inferiorChild = NULL;
  t->nextChild = NULL;
  return t;
}

//Ajoute un mot au Trie t et retourne le Trie résultat.
void ajoutMotTrie(TrieHybride t, char mot[]) {

    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return;
    }

    int i, option=3;
    TrieHybride it = t, prec;
    prec = it;
    it = it->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre à ajouter est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            prec = it;
            it = it->inferiorChild;
            option = 1;
        }
        //Siinon si la lettre à ajouter est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            prec = it;
            it = it->superiorChild;
            option = 2;
        }
        //Sinon si la lettre à ajouter existe déjà. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
            //Cas particulier : L'existence de toutes les lettres mais pas de la clé
            if(mot[i+1] == '\0') {
                if(it->cle == -1) {
                    //Incrémentation du nobmre de mots existants dans le Trie Hybirde
                    it->cle = ++nbMotsHybride;
                    return;
                }
            }
            prec = it;
            it = it->nextChild;
            if(!it) ++i;
            option = 3;
            break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant.
	 Donc appel de la fonction d'ajout simple d'un mot.
	 Cette vérification gére aussi les Tries vides */

      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
        ajoutSimpleTrie(prec, resteMot(mot,i), option);
        printf("\nMot \'%s\' ajouté avec succès.\n",mot);
        return;
      }
    }
    printf("\nLe mot \'%s\' existe déjà dans le Trie !!!\n",mot);
}

//Ajoute un mot au Trie t et retourne le Trie résultat.
//PS : L'entier option sert à préciser s'il s'agit d'une lettre supérieure, inférieure ou suivante
void ajoutSimpleTrie(TrieHybride t, char mot[], int option) {
    int i;
    TrieHybride it = t, noeud = my_malloc(sizeof(*noeud));
    noeud->cle = -1;
    noeud->val = mot[0];
    noeud->superiorChild = NULL;
    noeud->inferiorChild = NULL;
    noeud->nextChild = NULL;

    switch(option) {
    case 1 : //Inférieur
        it->inferiorChild = noeud;
        it = it->inferiorChild;
        break;

    case 2 : //Supérieur
        it->superiorChild = noeud;
        it = it->superiorChild;
        break;

    case 3 : //Suivant
        it->nextChild = noeud;
        it = it->nextChild;
        break;

    default : break; //Cas par défaut, il n'y en a pas.
    }

    for(i = 1; mot[i] != '\0'; i++) {
      noeud = my_malloc(sizeof(*noeud));
      noeud->cle = -1;
      noeud->val = mot[i];
      noeud->superiorChild = NULL;
      noeud->inferiorChild = NULL;
      noeud->nextChild = NULL;
      it->nextChild = noeud;
      it = it->nextChild;
    }
    //Incrémentation du nombre de clés présents dans le Trie Hybride
    it->cle = ++nbMotsHybride;
}

//Construit un Trie Hybride à partir d'un dictionnaire donné.
void constructTrieHybride(TrieHybride t, char** dictionnaire, int taille) {
    int i;
    for(i = 0; i < taille; i++)
      ajoutMotTrie(t, dictionnaire[i]);
}

//Retourne 1(VRAI) si le Trie est vide, 0(FAUX) sinon.
int estTrieVide(TrieHybride t) {
  return t->nextChild == NULL;
}

//Retourne la valeur de la racine du Trie.
char valTH(TrieHybride t) {
  return t->nextChild->val;
}

//Retourne une copie du i-ème sous arbre du Trie t. (1 =< i >= 3 car c'est un Trie Hybride) - Par défaut cette fonction retourne le sous-arbre gauche.
TrieHybride sousArbreTH(TrieHybride t, int i) {
  switch(i) {
  case 1 : return t->nextChild->inferiorChild;
    break;
  case 2 : return t->nextChild;
    break;
  case 3 : return t->nextChild->superiorChild;
    break;
  default : return t->nextChild->inferiorChild; break;
  }
}

//Retourne la liste des sous-arbres du Trie t privée du i-ème sous-arbre.
TrieHybride tousFilsSauf(TrieHybride t, int i); //On en a vraiment besoin ??

//Retourne le Trie formé avec T en i-ème sous arbre inséré dans la liste (1 <= i <= 3).
TrieHybride insertTrieHybride(TrieHybride t, TrieHybride ti, int i);

/* V - Liste des fonctions avancées pour les Arbres de la Briandais */

//Retourne 1(VRAI) si le mot existe dans l'Arbre a, 0(FAUX) sinon.
int rechercheMotBriandais(ArbreBriandais a, char mot[]) {
  int n = strlen(mot);

  //Au cas où le mot est vide
  if(!strlen(mot)) {
    printf("Il faut un mot !\n");
    return FAUX;
  }

  //Au cas où l'arbre est vide
  if(a->sibling == NULL) {
    printf("L'arbre est vide !\n");
    return FAUX;
  }
  //Au cas où l'arbre n'est pas vide
  else {
    int i;
    ArbreBriandais it = a;
    it = a->sibling; //Noeud courant

    //Parcours du mot lettre par lettre - La lettre représentant la fin du mot sera prise en compte aussi
    for(i = 0; i < n+1; i++) {
        //Boucle principale servant à parcourir les noeuds de l'arbre
        while(it) {
            //Parcours de la liste des racines de la i-ème forêt lexicographique afin de trouver la position de la i-ème lettre du mot
            while(toupper(mot[i]) > toupper(it->val)) {
                it = it->sibling;
                if(!it) break; //Si it est NULL, c'est qu'on a atteint la fin de la liste, on fait donc un break;
            }

            //Au cas où le neoud est vide, ça veut dire qu'on a atteint la fin de la liste des racines de la forêt lexicographique. Donc le mot n'existe pas.
            if(it == NULL) {
	      printf("Le mot \'%s\' n'existe pas dans l'Arbre.\n",mot);
	      return FAUX;
            }

            //Au cas où le noeud n'est pas vide
            else {
                //Si le noeud courant contient la même lettre, passage direct au fils
                if(toupper(mot[i]) == toupper(it->val)) {
                    it = it->child;
                    break;
                }
                //Sinon, si la lettre n'est pas la même, c'est qu'elle n'existe pas dans la forêt lexicgrpahique ==> Donc le mot n'existe pas
                else {
		  printf("Le mot \'%s\' n'existe pas dans l'Arbre\n",mot);
		  return FAUX;
		}
	    }
	}
    }
  }
  printf("Le mot \'%s\' existe dans l'Arbre !!!\n",mot);
  return VRAI;
}


//Retourne le nombre de mots présents dans l'Arbre a. Solution simple | Complexité O(1)
long int comptageMotsBriandais_V1() {
  return nbMotsBriandais;
}

//Retourne le nombre de mots présents dans l'Arbre a. Solution complexe | Appel récursif sur les noeuds de l'Arbre de la Briandais.
int comptageMotsBriandais_V2(ArbreBriandais a) {
  if(!a) return 0; //Si le noeud est NULL
  else if(a->val == '\0') return 1 + comptageMotsBriandais_V2(a->sibling); //Si le noeud représente la fin d'un mot. Il peut aussi avoir un frère
  return comptageMotsBriandais_V2(a->sibling) + comptageMotsBriandais_V2(a->child); //Cas général
}

//Retourne la liste des mots présents dans l'Arbre a triés dans l'ordre alphabétique.
char** listeMotsBriandais(ArbreBriandais a);

//Retourne le nombre de pointeurs vers Nil présents dans l'Arbre a.
int comptageNilBriandais(ArbreBriandais a) {
  if(!a) return 1; //Si le noeud est NULL
  return comptageNilBriandais(a->sibling) + comptageNilBriandais(a->child); //Cas général
}

//Calcule et retourne la hauteur de l'Arbre a.
int hauteurBriandais(ArbreBriandais a);

//Calcule et retourne la profondeur moyenne des feuilles de l'Arbre a.
int profondeurMoyenneBriandais(ArbreBriandais a);

//Retourne le nombre de mots présents dans l'Arbre a pour lesquels le mot donné est préfixe et les affiche.
int prefixeBriandais(ArbreBriandais a, char mot[]) {
  int i, n = strlen(mot);
  ArbreBriandais it = a->sibling;
  //Au cas où le mot est vide
  if(!strlen(mot)) {
    printf("Il faut un mot !\n");
    return FAUX;
  }

  //Au cas où l'arbre est vide
  if(it == NULL) {
    printf("L'arbre est vide !\n");
    return FAUX;
  }
  //Au cas où l'arbre n'est pas vide
  else {

    //Parcours du mot lettre par lettre - La lettre représentant la fin du mot sera prise en compte aussi
    for(i = 0; i < n; i++) {
        //Boucle principale servant à parcourir les noeuds de l'arbre
        while(it) {
            //Parcours de la liste des racines de la i-ème forêt lexicographique afin de trouver la position de la i-ème lettre du mot
            while(toupper(mot[i]) > toupper(it->val)) {
                it = it->sibling;
                if(!it) break; //Si it est NULL, c'est qu'on a atteint la fin de la liste, on fait donc un break;
            }

            //Au cas où le neoud est vide, ça veut dire qu'on a atteint la fin de la liste des racines de la forêt lexicographique. Donc le mot n'existe pas.
            if(it == NULL) {
                printf("Le mot \'%s\' n'existe pas dans l'Arbre.\n",mot);
                break;
            }

            //Au cas où le noeud n'est pas vide
            else {
                //Si le noeud courant contient la même lettre, passage direct au fils
                if(toupper(mot[i]) == toupper(it->val)) {
                    it = it->child;
                    break;
                }
                //Sinon, si la lettre n'est pas la même, c'est qu'elle n'existe pas dans la forêt lexicgrpahique ==> Donc le mot n'existe pas
                else {
                    printf("Le mot \'%s\' n'existe pas dans l'Arbre\n",mot);
                    break;
                }
            }
        }
    }
  }
  if(i == n) return comptageMotsBriandais_V2(it);
  return 0;
}

//Supprime un mot de l'Arbre a et retourne l'Arbre résultat | Version Simple
void suppressionMotBriandais_V1(ArbreBriandais a, char mot[]) {
  ArbreBriandais it = a, prec;

  //Au cas où le mot est vide
  if(!strlen(mot)) {
    printf("Il faut un mot !\n");
    return;
  }
  
  //Au cas où l'arbre est vide, faire un ajout simple en utilisant la fonction correspondante.
  if(a->sibling == NULL) {
    printf("L'arbre est vide !\n");
    return;
  }
  //Au cas où l'arbre n'est pas vide
  else {
    int i;
    prec = it; //Noeud précédant
    it = a->sibling; //Noeud courant
    
    //Parcours du mot lettre par lettre - La lettre représentant la fin du mot sera prise en compte aussi
    for(i = 0; mot[i] != '\0'; i++) {
      //Boucle principale servant à parcourir les noeuds de l'arbre
      while(it) {
	//Parcours de la liste des racines de la i-ème forêt lexicographique afin de trouver la position de la i-ème lettre du mot
	while(toupper(mot[i]) > toupper(it->val)) {
	  prec = it;
	  it = it->sibling;
	  if(!it) break; //Si it est NULL, c'est qu'on a atteint la fin de la liste, on fait donc un break;
	}
	
	//Au cas où le neoud est vide, ça veut dire qu'on a atteint la fin de la liste des racines de la forêt lexicographique - Donc le mot n'existe pas dans l'Arbre
	if(it == NULL) {
	  printf("\nLe mot \'%s\' n'existe pas dans l'Arbre de la Briandais.\n",mot);
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
	  //Sinon, si la lettre n'est pas la même, c'est qu'elle n'existe pas dans la forêt lexicgrpahique - Donc le mot n'existe pas
	  else {
	    printf("\nLe mot \'%s\' n'existe pas dans l'Arbre de la Briandais.\n",mot);
	    return;
	  }
	}
      }
    }
  }
  prec->child = it->sibling;
  free(it);
  --nbMotsBriandais;
  printf("Le mot \'%s\' a été supprimé de l'Arbre de la Briandais !!!\n",mot); 
}
							     

//Supprime un mot de l'Arbre a et retourne l'Arbre résultat | Version Complexe
void suppressionMotBriandais_V2(ArbreBriandais a, char mot[]);


/* VI - Liste des fonctions avancées pour les Tries Hybrides */

//Retourne 1(VRAI) si le mot existe dans le Trie a, 0(FAUX) sinon.
int rechercheMotTrie(TrieHybride t, char mot[]) {
    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return FAUX;
    }
    if(!t->nextChild) {
        printf("Le Trie est vide !\n");
        return FAUX;
    }

    int i;
    TrieHybride it = t->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre à ajouter est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            it = it->inferiorChild;
        }
        //Siinon si la lettre à ajouter est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            it = it->superiorChild;
        }
        //Sinon si la lettre à ajouter existe déjà. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
            //Cas particulier : L'existence de toutes les lettres mais pas de la clé
            if(mot[i+1] == '\0') {
                //Pas de clé, on retourner FAUX
                if(it->cle == -1) {
                    printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
                    return FAUX;
                }
            }
            it = it->nextChild;
            if(!it) ++i;
            break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant.
	 Donc appel de la fonction d'ajout simple d'un mot.
	 Cette vérification gére aussi les Tries vides */

      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
        printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
        return FAUX;
      }
    }
    printf("\nLe mot \'%s\' existe dans le Trie !!!\n",mot);
    return VRAI;
}

//Retourne le nombre de mots présents dans le Trie t. Solution Simple | Complexité O(1)
long int comptageMotsTrie_V1() {
  return nbMotsHybride;
}

//Retourne le nombre de mots présents dans le Trie t. Solution Complexte | Appel récursif sur les noeuds du Trie Hybride.
int comptageMotsTrie_V2(TrieHybride t) {
  if(!t) return 0; //Si le noeud est NULL
  //Cas où le noeud représente une clé
  else if(t->cle != -1) return 1 + comptageMotsTrie_V2(t->nextChild) + comptageMotsTrie_V2(t->inferiorChild) + comptageMotsTrie_V2(t->superiorChild);
  return  comptageMotsTrie_V2(t->nextChild) + comptageMotsTrie_V2(t->inferiorChild) + comptageMotsTrie_V2(t->superiorChild); //Cas général
}

//Retourne la liste des mots présents dans le Trie t triés dans l'ordre alphabétique.
char** listeMotsTrie(TrieHybride t);

//Retourne le nombre de pointeurs vers Nil présents dans le Trie t.
int comptageNilTrie(TrieHybride t) {
  if(!t) return 1; //Si le noeud est NULL
  return  comptageNilTrie(t->nextChild) + comptageNilTrie(t->inferiorChild) + comptageNilTrie(t->superiorChild); //Cas général
}

//Calcule et retourne la hauteur du Trie t.
int hauteurTrie(TrieHybride t);

//Calcule et retourne la profondeur moyenne des feuilles du Trie t.
int profondeurMoyenneTrie(ArbreBriandais t);

//Retourne le nombre de mots présents dans le Trie t pour lesquels le mot donné est préfixe et les affiche.
int prefixeTrie(TrieHybride t, char mot[]) {

    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return 0;
    }
    //Au cas où le Trie est vide
    if(!t->nextChild) {
        printf("Le Trie est vide !\n");
        return 0;
    }

    int i;
    TrieHybride it = t, prec;
    prec = it;
    it = it->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre i est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            prec = it;
            it = it->inferiorChild;
        }
        //Siinon si la lettre i est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            prec = it;
            it = it->superiorChild;
        }
        //Sinon si la lettre i est la même que celle du noeud. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
            prec = it;
            it = it->nextChild;
            if(!it) ++i;
            break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant - Donc le préfixe n'existe pas dans le Trie */
      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
        return 0;
      }
    }
    return comptageMotsTrie_V2(prec);
}

//Supprime un mot du Trie t et retourne le Trie résultat | Version Simple
void suppressionMotTrie_V1(TrieHybride t, char mot[]) {

    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return;
    }
    //Au cas où le Trie est vide
    if(!t->nextChild) {
        printf("Le Trie est vide !\n");
        return;
    }

    int i;
    TrieHybride it = t, prec;
    prec = it;
    it = it->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre i est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            prec = it;
            it = it->inferiorChild;
        }
        //Siinon si la lettre i est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            prec = it;
            it = it->superiorChild;
        }
        //Sinon si la lettre i est la même que celle du noeud. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
	  //Cas particulier : L'existence de toutes les lettres mais pas de la clé
	  if(mot[i+1] == '\0') {
	    if(it->cle == -1) {
	      printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
	      return;
	    }
	  }
	  prec = it;
	  it = it->nextChild;
	  if(!it) ++i;
	  break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant - Donc absence du mot dans le Trie - Pas de suppression possible */
      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
	printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
        return;
      }
    }
    prec->cle = -1;
    --nbMotsHybride; //Décrémentation du nombre des mots
    printf("\nLe mot \'%s\' a été supprimé du Trie.\n",mot);
}

//Supprime un mot du Trie t et retourne le Trie résultat | Version Complexe
void suppressionMotTrie_V2(TrieHybride t, char mot[]);


int main(void) {



  /*
  //Test Trie Hybride
  TrieHybride t = trieVide();



  constructTrieHybride(t,base,tailleBase);
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
  

  tmp = t->nextChild->superiorChild;


  printf("\n1 %c | %ld",tmp->val, tmp->cle);
  printf("\n2 %c | %ld",tmp->nextChild->val, tmp->nextChild->cle);
  printf("\n3 %c | %ld",tmp->nextChild->nextChild->val, tmp->nextChild->nextChild->cle);
  printf("\n4 %c | %ld",tmp->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->cle);
  //printf("\n5 %c | %ld",tmp->nextChild->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->nextChild->cle);
  //printf("\n6 %c | %ld",tmp->nextChild->nextChild->nextChild->nextChild->nextChild->val, tmp->nextChild->nextChild->nextChild->nextChild->nextChild->cle);
  
  printf("\n\n");
  */


  
  //Test Arbre Briandais
  ArbreBriandais a = arbreVide(); //tmp;
  constructArbreBriandais(a,base,tailleBase);

  
  printf("\nComptage Mots : V1 %ld | V2 %d\n",comptageMotsBriandais_V1(),comptageMotsBriandais_V2(a->sibling));
  rechercheMotBriandais(a,"dactylo");  
  suppressionMotBriandais_V1(a,"dactylo");
  printf("Comptage Mots : V1 %ld | V2 %d\n\n",comptageMotsBriandais_V1(),comptageMotsBriandais_V2(a->sibling));

  rechercheMotBriandais(a,"dactylo");
  rechercheMotBriandais(a,"dactylographie");

  /*
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
