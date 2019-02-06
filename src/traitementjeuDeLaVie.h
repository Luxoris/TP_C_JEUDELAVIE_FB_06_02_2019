#ifndef TRAITEMENTJEUDELAVIE_H_INCLUDED
#define TRAITEMENTJEUDELAVIE_H_INCLUDED
#pragma once

//Inclusion des headers
#include "tGrille.h"
#include "tBool.h"

//PROTOTYPES des méthodes

extern void initGrille(tGrille stGrille, int *pNbCelluleVivante);
extern void NbCelluleVivanteAutour(const tGrille stGrille,const int nX, const int nY, int *pNbCelluleVivanteAutour);
extern void testNouvelleEtat(const tCellule stCellulePrecedent,tCellule *pstCelluleSuivant,const int nNbCelluleVivanteAutour);
extern void etapeSuivante(tGrille stGrille, int *pnNbCelluleVivante);

#endif // TRAITEMENTJEUDELAVIE_H_INCLUDED
