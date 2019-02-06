#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#pragma once

//D�finitions des maccros du jeu
#define INIT_VAR 0

//d�finit les r�gles de naissance et de mort des cellules
#define NB_MIN_CELLULE_AUTOUR_RESTER_ENVIE 2
#define NB_MAX_CELLULE_AUTOUR_RESTER_ENVIE 3
#define NB_CELLULE_AUTOUR_NAITRE 3

#define PROBABILITE_CREATION 50 //d�finit la probabilit� d'appartition d'une cellule vivante lors de l'initialisation (0 -> 0%, 100 -> 100%)

//coordonn�e de la case de r�f�rence pour la recherche par rapport � la case de la matrice d'�tat des cellules
#define COOR_CASE_RECHERCHE_X 0
#define COOR_CASE_RECHERCHE_Y 0
#define PORTEE_ANALYSE 1    //d�finit la distance d'analyse autour de la cellule analys�

//emplacement des fichiers
#define SAVE_PATH "./save/sauvegarde.b"
#define SAVE_TEXT_PATH "./save/sauvegarde_Texte.txt"
#define TEXT_PATH "./save/Texte.txt"


#endif // DEFINE_H_INCLUDED
