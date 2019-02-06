#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#pragma once

//Définitions des maccros du jeu
#define INIT_VAR 0

//définit les règles de naissance et de mort des cellules
#define NB_MIN_CELLULE_AUTOUR_RESTER_ENVIE 2
#define NB_MAX_CELLULE_AUTOUR_RESTER_ENVIE 3
#define NB_CELLULE_AUTOUR_NAITRE 3

#define PROBABILITE_CREATION 50 //définit la probabilité d'appartition d'une cellule vivante lors de l'initialisation (0 -> 0%, 100 -> 100%)

//coordonnée de la case de référence pour la recherche par rapport à la case de la matrice d'état des cellules
#define COOR_CASE_RECHERCHE_X 0
#define COOR_CASE_RECHERCHE_Y 0
#define PORTEE_ANALYSE 1    //définit la distance d'analyse autour de la cellule analysé

//emplacement des fichiers
#define SAVE_PATH "./save/sauvegarde.b"
#define SAVE_TEXT_PATH "./save/sauvegarde_Texte.txt"
#define TEXT_PATH "./save/Texte.txt"


#endif // DEFINE_H_INCLUDED
