#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#pragma once

//inclusion des headers
#include "etatPartie.h"
#include <stdio.h>

//prototypes des méthodes
extern int ajoutFichierTexte(const char cCheminFichier[],const int nNumeroTour,const int nNbCelluleVivante);
extern int sauvegardePartie(const char cCheminFichier[],const tEtatPartie *pstEtatPartie);
extern int copieFichierText(const char cCheminFichierCopie[],const char cCheminFichier[]);
extern int supprimerFichier(const char cCheminFichier[]);
extern int chargementPartie(const char cCheminFichier[],tEtatPartie *pstEtatPartie);

#endif // FICHIER_H_INCLUDED
