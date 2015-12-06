/**
 * \file arbreBriandais.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Projet ALGAV - Fichier test du programme :
 * Fichier contenant les implémentations des primitives et fonctions avancées des Arbres de la Briandais.
 */

#include "../headers/main.h"


/********** III - Liste des primitives de base d'un Arbre de la Briandais **********/
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
  ArbreBriandais it = a, prec;

  //Au cas où le mot est vide
  if(!strlen(mot)) {
    //printf("Il faut un mot !\n");
    return;
  }

  //Au cas où l'arbre est vide, faire un ajout simple en utilisant la fonction correspondante.
  if(a->sibling == NULL) {
    ajoutSimpleBriandais(a,mot);
    //printf("Mot \'%s\' ajouté avec succès !\n",mot);
    nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
    return;
  }
  //Au cas où l'arbre n'est pas vide
  else {
    int i;
    prec = it; //Noeud précédant
    it = a->sibling; //Noeud courant

    //Parcours du mot lettre par lettre - La lettre représentant la fin du mot sera prise en compte aussi
    for(i = 0; i < n; i++) {
        //Boucle principale servant à parcourir les noeuds de l'arbre
        while(it) {
            //Parcours de la liste des racines de la i-ème forêt lexicographique afin de trouver la position de la i-ème lettre du mot
            while(toupper(mot[i]) > toupper(it->val)) {
                ++nb_operations;
                prec = it;
                it = it->sibling;
                if(!it) break; //Si it est NULL, c'est qu'on a atteint la fin de la liste, on fait donc un break;
            }

            //Au cas où le neoud est vide, ça veut dire qu'on a atteint la fin de la liste des racines de la forêt lexicographique
            if(it == NULL) {
                ajoutSimpleBriandais(prec,resteMot(mot,i)); //On effectue un ajout simple du reste du mot à partir de l'ième lettre incluse
                //printf("Mot \'%s\' ajouté avec succès !\n",mot);
                nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
                return;
            }
            //Au cas où le noeud n'est pas vide
            else {
                //Si le noeud courant contient la même lettre, passage direct au fils
                if(toupper(mot[i]) == toupper(it->val)) {
                    ++nb_operations;
                    prec = it;
                    it = it->child;
                    break;
                }
                //Sinon, si la lettre n'est pas la même, c'est qu'elle n'existe pas dans la forêt lexicgrpahique
                else {
                    //S'il s'agit du fils (La relation parent-fils sera gérée ici au niveau de la fonction principale)
                    if(prec->child == it) {
                        ++nb_operations;
                        ArbreBriandais noeud = NULL;
                        noeud = my_malloc(sizeof(*noeud));
                        noeud->val = mot[i];
                        noeud->sibling = it;
                        noeud->child = NULL;
                        prec->child = noeud;
                        it = prec->child;
                        int j;
                        for(j = i+1; j < n+1; j++, it = it->child) {
                          ++nb_operations;
                          noeud = my_malloc(sizeof(*noeud));
                          noeud->val = mot[j];
                          noeud->sibling = NULL;
                          noeud->child = NULL;
                          it->child = noeud;
                        }
                        //printf("Mot \'%s\' ajouté avec succès !\n",mot);
                        nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
                        return;
                    }
                    //S'il s'agit d'un frère du fils, appel à la fonction d'ajout simple
                    else {
                        ajoutSimpleBriandais(prec,resteMot(mot,i));
                        //printf("Mot \'%s\' ajouté avec succès !\n",mot);
                        nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
                        return;
                    }
                }
            }
        }
    }
  }
  //Au cas où toutes les lettres existent mais pas le noeud représentant la fin du mot, dans ce cas on l'ajoute
  if(prec) {
    if(prec->child) {
        if(prec->child->val != '\0') {
            ++nb_operations;
            ArbreBriandais noeud = my_malloc(sizeof(*noeud));
            noeud->val = '\0';
            noeud->sibling = prec->child;
            noeud->child = NULL;
            prec->child = noeud;
            //printf("Mot \'%s\' ajouté avec succès !\n",mot);
            nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
            return;
        }
    }
    else if(!prec->child) {
      ++nb_operations;
      ArbreBriandais noeud = my_malloc(sizeof(*noeud));
      noeud->val = '\0';
      noeud->sibling = NULL;
      noeud->child = NULL;
      prec->child = noeud;
      //printf("Mot \'%s\' ajouté avec succès !\n",mot);
      nbMotsBriandais++; //Incrémentation du nombre de mots dans l'Arbre de la Briandais
      return;
    }
  }
  //printf("Le mot \'%s\' existe déjà dans l'Arbre !!!\n",mot);
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
    ++nb_operations;

    //Ajout des lettres suivantes
    for(i = 1; i < n+1; i++, it = it->child) {
        noeud = my_malloc(sizeof(*noeud));
        noeud->val = mot[i];
        noeud->sibling = NULL;
        noeud->child = NULL;
        it->child = noeud;
        ++nb_operations;
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

//Retourne 1(VRAI) si le neoud est une feuille, 0(FAUX) sinon.
int estFeuilleBriandais(ArbreBriandais a) {
    if(!a) return FAUX;
    return (!a->child && !a->sibling)?VRAI:FAUX;
}

//Retourne le nombre de feuilles de l'Arbre de la Briandais.
int comptageFeuillesBriandais(ArbreBriandais a) {
    ++nb_operations;
    if(!a) return 0;
    if(estFeuilleBriandais(a)) return 1;
    return comptageFeuillesBriandais(a->child) + comptageFeuillesBriandais(a->sibling);
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


/********** V - Liste des fonctions avancées pour les Arbres de la Briandais **********/
//Retourne 1(VRAI) si le mot existe dans l'Arbre a, 0(FAUX) sinon.
int rechercheMotBriandais(ArbreBriandais a, char mot[]) {

    ArbreBriandais it = a;
    it = a->sibling; //Noeud courant


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

    //Parcours du mot lettre par lettre - La lettre représentant la fin du mot sera prise en compte aussi
    for(i = 0; mot[i] != '\0'; i++) {
        //Boucle principale servant à parcourir les noeuds de l'arbre
        while(it) {
            //Parcours de la liste des racines de la i-ème forêt lexicographique afin de trouver la position de la i-ème lettre du mot
            while(toupper(mot[i]) > toupper(it->val)) {
                ++nb_operations;
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
                    ++nb_operations;
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

  //Au cas où toutes les lettres existent mais pas le noeud représentant la fin du mot, dans ce cas le mot n'existe pas
  if(!it) {
    printf("Le mot \'%s\' n'existe pas dans l'Arbre\n",mot);
    return FAUX;
  }
  else {
    if(it->val != '\0') {
        printf("Le mot \'%s\' n'existe pas dans l'Arbre\n",mot);
        return FAUX;
    }
  }
  ++nb_operations;
  printf("Le mot \'%s\' existe dans l'Arbre !!!\n",mot);
  return VRAI;
}

//Retourne le nombre de mots présents dans l'Arbre a. Solution simple | Complexité O(1)
long int comptageMotsBriandais_V1() {
  return nbMotsBriandais;
}

//Retourne le nombre de mots présents dans l'Arbre a. Solution complexe | Appel récursif sur les noeuds de l'Arbre de la Briandais.
int comptageMotsBriandais_V2(ArbreBriandais a) {
  ++nb_operations;
  if(!a) return 0; //Si le noeud est NULL
  if(estFeuilleBriandais(a)) {
    if(a->val == '\0') return 1;
    else return 0;
  }
  else if(a->val == '\0') return 1 + comptageMotsBriandais_V2(a->sibling); //Si le noeud représente la fin d'un mot. Il peut aussi avoir un frère
  return comptageMotsBriandais_V2(a->sibling) + comptageMotsBriandais_V2(a->child); //Cas général
}

//Retourne la liste des mots présents dans l'Arbre a triés dans l'ordre alphabétique.
void listeMotsBriandais(ArbreBriandais a, char mot[], int profondeur) {
  ++nb_operations;
  if(!a) return;
  if(a) {
    mot[profondeur] = a->val;
    if(a->val == '\0') {
      printf("\n%s",mot);
    }
    if(a->child)
        listeMotsBriandais(a->child,mot,profondeur+1);
    if(a->sibling)
        listeMotsBriandais(a->sibling,mot,profondeur);
  }
}

//Retourne le nombre de pointeurs vers Nil présents dans l'Arbre a.
int comptageNilBriandais(ArbreBriandais a) {
  ++nb_operations;
  if(!a) return 1; //Si le noeud est NULL
  if(estFeuilleBriandais(a)) return 2;
  return comptageNilBriandais(a->sibling) + comptageNilBriandais(a->child); //Cas général
}

//Calcule et retourne la hauteur de l'Arbre a.
int hauteurBriandais(ArbreBriandais a) {
    ++nb_operations;
	if(!a) return 0;
	if(estFeuilleBriandais(a)) return 1;
    return max2(1+hauteurBriandais(a->child) , hauteurBriandais(a->sibling));
}

//Calcule et retourne la somme des profondeurs des feuilles de l'Arbre a. n départ = 0.
int profondeurTotaleBriandais(ArbreBriandais a, int n) {
    //++nb_operations;
    if(!a) return 0;
    if(estFeuilleBriandais(a)) return n+1;
    return profondeurTotaleBriandais(a->child,n+1) + profondeurTotaleBriandais(a->sibling,n);
}

//Calcule et retourne la profondeur moyenne des feuilles de l'Arbre a.
float profondeurMoyenneBriandais(ArbreBriandais a) {
    if(!a) return 0;
    return ((float)profondeurTotaleBriandais(a,0)/(float)comptageFeuillesBriandais(a));
}

/* Calcule le nombre de feuilles du Trie et la somme de leurs profondeurs et stocke les résultats dans des variables globales.
  nb_feuilles et prof_totale_feuilles */
void profondeursFeuilles(ArbreBriandais a, int profondeur) {
    ++nb_operations;
    if(!a) return;
    if(estFeuilleBriandais(a)) {
        nb_feuilles++;
        prof_totale_feuilles += profondeur+1;
        return;
    }
    profondeursFeuilles(a->sibling,profondeur);
    profondeursFeuilles(a->child,profondeur+1);
}

/* Calcule et retourne le résultat de la division de nb_feuilles par prof_totale_feuilles */
float profondeurMoyenneBriandaisV2(ArbreBriandais a) {
    profondeursFeuilles(a, 0);
    return prof_totale_feuilles / nb_feuilles;
}

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
                ++nb_operations;
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
                    ++nb_operations;
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
            ++nb_operations;
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
                ++nb_operations;
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


  free(it); ++nb_operations;
  --nbMotsBriandais;
  printf("Le mot \'%s\' a été supprimé de l'Arbre de la Briandais !!!\n",mot);
}

//Supprime un mot de l'Arbre a et retourne l'Arbre résultat | Version Complexe
void suppressionMotBriandais_V2(ArbreBriandais a, char mot[]) {
  ArbreBriandais it = a, prec, potentiel, prec_potentiel;
  int n = strlen(mot);

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
    //potentiel = prec; //Noeud potentiel à partir duquel on va supprimer
    it = a->sibling; //Noeud courant

    //Parcours du mot lettre par lettre - La lettre représentant la fin du mot sera prise en compte aussi
    for(i = 0; mot[i] <= n; i++) {
      //Boucle principale servant à parcourir les noeuds de l'arbre
      while(it) {

	//Parcours de la liste des racines de la i-ème forêt lexicographique afin de trouver la position de la i-ème lettre du mot
        while(toupper(mot[i]) > toupper(it->val)) {
            ++nb_operations;
            prec = it;
	    //potentiel = ()
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
	      if(it->sibling) {
		potentiel = it;
		prec_potentiel = prec;
	      }
                ++nb_operations;
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
  printf("\nTest 1\n");

  if(potentiel) {
    printf("\nPotentiel != NULL\n");
    if(potentiel->sibling) {
      printf("\nTest 2\n");
      if(prec_potentiel->child) {
	if(potentiel == prec_potentiel->child) {
	  prec_potentiel->child = potentiel->sibling;
	  printf("\nTest 3\n");
	}
      }
      else {
	printf("\nTest 4\n");
	prec_potentiel->sibling = potentiel->sibling;
      }

      freeBriandais(potentiel);
      printf("\nTest 5\n");
    }
  }



  --nbMotsBriandais;
  printf("Le mot \'%s\' a été supprimé de l'Arbre de la Briandais !!!\n",mot);


}

//Suppression d'un ensemble de mots(liste) d'un Arbre de la Briandais a.
void suppressionListeBriandais(ArbreBriandais a, char** liste, int taille) {
    int i;
    for(i = 0; i < taille; i++)
        suppressionMotBriandais_V1(a,liste[i]);
}

/* Fonction qui affiche un aperçu visuel de l'Arbre de la Briandais a */
void visualizeBriandais(ArbreBriandais a, int profondeur) {
    ++nb_operations;
    int i;
    for (i=0; i < profondeur; i++) {
        ++nb_operations;
        fputs("|___ ", stdout);
    }
    if(a) {
        if(a->val == '\0')
	  printf("[!][%d]\n",profondeur+1);
	else printf("[%c]\n", a->val);
    }
    if (a->child) visualizeBriandais(a->child, profondeur + 1); //Les fils sont affichés au niveau inféreieur, d'où le +1
    if (a->sibling) visualizeBriandais(a->sibling, profondeur); //Les frère sont dans le même niveau
}

//Calcule et retourne le nombre de noeuds d'un Arbre de la Briandais
int compteBriandais(ArbreBriandais a) {
    if(!a) return 0;
    return 1 + compteBriandais(a->child) + compteBriandais(a->sibling);
}
