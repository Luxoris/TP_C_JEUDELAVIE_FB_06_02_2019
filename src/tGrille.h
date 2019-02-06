#ifndef TGRILLE_H_INCLUDED
#define TGRILLE_H_INCLUDED
#pragma once

//inclusion des headers
#include "cellule.h"
#include "tBool.h"

//DEFINTION DES MACCROS
#define TAILLE_GRILLE 25
#define INDEX_MIN_GRILLE 0

//Définition du type Grille
typedef tCellule tGrille[TAILLE_GRILLE][TAILLE_GRILLE];


//Prototype des méthodes du type grille
tBool caseAppartientGrille(const int nX, const int nY);
extern tCellule getCelluleGrille(const tGrille stGrille, const int nX, const int nY);
extern void setCelluleGrille(tGrille stGrille, const int nX, const int nY, const tCellule nVal);
extern void copieGrille(const tGrille stGrille, tGrille stGrilleCopie);

#endif // TGRILLE_H_INCLUDED
