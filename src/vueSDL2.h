#ifndef VUESDL2_H_INCLUDED
#define VUESDL2_H_INCLUDED
#pragma once


//inclusion des headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "define.h"
#include "tGrille.h"
#include "etatPartie.h"
#include "fichier.h"

//définiton des maccros correspondant à la taille de la fenêtre d'affichage
#define WINDOW_LARGEUR 500
#define WINDOW_HAUTEUR 500


//PROTOTYPE
extern void afficheGrilleSDL2(SDL_Window** pFenetre,const tGrille stGrille);
extern void initAffichage(SDL_Window** pFenetre);
extern void arretAffichage(SDL_Window** pFenetre);

#endif // VUESDL2_H_INCLUDED
