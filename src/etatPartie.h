#ifndef ETATPARTIE_H_INCLUDED
#define ETATPARTIE_H_INCLUDED
#pragma once


//inclusion des headers
#include "tGrille.h"

//définition du type structuré correspondant à un etat de la partie à un instant t
typedef struct tEtatPartie{
    tGrille stGrille;
    int nNumeroTour;
    int nNbCelluleVivante;
}tEtatPartie;

//PROTOTYPES des méthodes
extern int getNumeroTour(tEtatPartie *pstEtatPartie);
extern int getNbCelluleVivante(tEtatPartie *pstEtatPartie);
extern void setNumeroTour(tEtatPartie *pstEtatPartie, const int nNumeroTour);
extern void setNbCelluleVivante(tEtatPartie *pstEtatPartie, const int nNbCelluleVivante);
extern tCellule getCelluleGrilleEtatPartie(tEtatPartie *pstEtatPartie, const int nX, const int nY);
extern void setCelluleGrilleEtatPartie(tEtatPartie *pstEtatPartie, const int nX, const int nY, const tCellule nVal);
#endif // ETATPARTIE_H_INCLUDED
