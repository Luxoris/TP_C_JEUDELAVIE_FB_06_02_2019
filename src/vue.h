#ifndef VUE_H_INCLUDED
#define VUE_H_INCLUDED
#pragma once

//inclusion des headers
#include "define.h"
#include "tGrille.h"
#include "etatPartie.h"
#include "fichier.h"

//PROTOTYPE
extern void choixMenuPrincipal(char *pcMenu);
extern void afficheGrille(const tGrille stGrille);
extern void afficheEtatPartie(const int nNumeroTour,const int nNbCelluleVivante);
extern void afficheEtatManipulationFichier(const int nCode);
extern int afficheFichierText(const char cCheminFichier[]);

#endif // VUE_H_INCLUDED
