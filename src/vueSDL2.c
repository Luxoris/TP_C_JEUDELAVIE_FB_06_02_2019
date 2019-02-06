#include "vueSDL2.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//References https://fr.wikibooks.org/wiki/Programmation_avec_la_SDL/Le_renderer

//###########################################
//PROCEDURE initaffichage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui initialise la SDL et crer la fenetre, renvoie le pointeur de fenetre
//
// ENTREE /Le pointeur de fenetre
//
// SORTIE / Le pointeur de fenetre
//
// NOTE -
//*****************************************************************************************************//
void initAffichage(SDL_Window** pFenetre){
    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
        {
            printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());

        }
    // Création de la fenêtre :
    *(pFenetre) = SDL_CreateWindow("Jeu de la Vie V2" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WINDOW_LARGEUR , WINDOW_HAUTEUR, SDL_WINDOW_RESIZABLE);
    if(pFenetre == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());

    }
}
//###########################################
//PROCEDURE arretAffichage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ferme la fenetre et quitte la SDL
//
// ENTREE /Le pointeur de fenetre
//
// SORTIE /
//
// NOTE -
//*****************************************************************************************************//
void arretAffichage(SDL_Window** pFenetre){
    SDL_DestroyWindow(*(pFenetre));
    SDL_Quit();
}

//###########################################
//PROCEDURE afficheGrilleSDL2
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui recupere la reference de la fenetre et affiche la grille
//
// ENTREE /La reference de la fenetre, la grille.
//
// SORTIE / L'affichage de la grille
//
// NOTE -
//*****************************************************************************************************//
void afficheGrilleSDL2(SDL_Window** pFenetre,const tGrille stGrille){
        //Initialisation des variables
        SDL_Renderer* renderer=NULL;//Déclaration du renderer
        int nX=INIT_VAR, nY=INIT_VAR;
        int nI=INIT_VAR, nJ=INIT_VAR;
        const int nLargeur = WINDOW_LARGEUR/TAILLE_GRILLE;
        const int nHauteur = WINDOW_HAUTEUR/TAILLE_GRILLE;


        //creation du moteur de rendu
        renderer = SDL_CreateRenderer(*(pFenetre), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
        if(renderer == NULL)//gestion des erreurs
        {
            printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());

        }

        //écran coloré en violet
        SDL_SetRenderDrawColor(renderer,160,0,160,255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        //lignes tracé en blanc
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        for(nX=0;nX<=(TAILLE_GRILLE+1);nX++){
            SDL_RenderDrawLine(renderer, 0 , nX*nHauteur , WINDOW_LARGEUR , nX*nHauteur);
            for(nY=0;nY<=(TAILLE_GRILLE+1);nY++){
                SDL_RenderDrawLine(renderer, nY*nLargeur, 0 , nY*nLargeur, WINDOW_HAUTEUR);
            }
        }

        //cellules vivantes tracés en noir
        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_Rect rectangle;
        for(nI=0;nI<TAILLE_GRILLE;nI++){
           for(nJ=0;nJ<TAILLE_GRILLE;nJ++){
                if(!celluleEstMorte(getCelluleGrille(stGrille,nI,nJ))){
                    rectangle.x=nJ*nLargeur+3;
                    rectangle.y=nI*nHauteur+3;
                    rectangle.h=nHauteur-4;
                    rectangle.w=nLargeur-4;
                    SDL_RenderDrawRect(renderer,&rectangle);
                    SDL_RenderFillRect(renderer,&rectangle);
                }
            }
        }
        //applicaton du rendu
        SDL_RenderPresent(renderer);
        //destruction du moteur de rendu
        SDL_DestroyRenderer(renderer);

}


