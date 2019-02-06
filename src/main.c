//PROGRAMME jeuDeLaVie Version 2(SDL2)
//BUT Programme qui construit et affiche le programme du jeu de la vie comme d�finit par  John Horton Conway en 1970
//Principe :
//	Le jeu de la vie n�est pas un jeu, puisqu'il ne n�cessite aucun joueur.
//Il s�agit d�un automate cellulaire, un mod�le o� chaque �tat conduit m�caniquement � l��tat suivant � partir de r�gles pr�-�tablies.
//Le � jeu � se d�roule sur une grille � deux dimensions, th�oriquement infinie (mais de longueur et de largeur finies et plus ou moins grandes dans la pratique), dont les cases � qu�on appelle des � cellules �, par analogie avec les cellules vivantes � peuvent prendre deux �tats distincts : � vivante � ou � morte �.
//� chaque �tape, l��volution d�une cellule est enti�rement d�termin�e par l��tat de ses huit voisines de la fa�on suivante :
//   Une cellule morte poss�dant exactement trois voisines vivantes devient vivante (elle na�t).
//   Une cellule vivante poss�dant deux ou trois voisines vivantes le reste, sinon elle meurt.
//ENTREE L'environnement
//SORTIE Les fichiers correspondant � la sauvegarde, aux �tats en fontion du temps du jeu. L'affichage de la grille.

//Appel des biblioth�que et des headers du programme
#include <stdio.h>
#include <stdlib.h>
#include "vue.h"
#include "traitementjeuDeLaVie.h"
#include "etatPartie.h"
#include "fichier.h"
#include "vueSDL2.h"

//###########################################
//PROGRAMME PRINCIPAL
//*****************************************************************************************************//
//
// DESCRIPTION Appel les fonctions initialisation, d'affichage, d'etape suivante, de sauvegarde, de gestion code erreur.
//      Utilisae une boucle do while pour la boucle de jeu, et un switch case pour le choix des appels.
//
// ENTREE / L'environnement
//
// SORTIE / Fichiers, l'affichage d'une fen�tre en SDL
//
// NOTE L'�tat des cellule � un instant t est stock� dans une matrice d'�num�ration.
//      Le type etat de la partie caract�rise la matrice d'�num�ration ainsi que le nb de cellules vivantes et l'instant t. (le nb de tour depuis le d�part)
//*****************************************************************************************************//
int main(int argc, char* argv[])
{
    int codeEtatFichier=INIT_VAR;
    SDL_Window* pFenetre=NULL;

    tEtatPartie stEtatPartie;
    setNumeroTour(&stEtatPartie,INIT_VAR);
    setNbCelluleVivante(&stEtatPartie,INIT_VAR);

    char cMenu = 'b';
    do{
        //fonction affichage et de saisie du caract�re correspondant au choix de l'utilisateur
        choixMenuPrincipal(&cMenu);
        //choix des appels par unmenu switch
        switch(cMenu){
            case 'n':   //nouvelle partie
                initGrille(stEtatPartie.stGrille,&(stEtatPartie.nNbCelluleVivante));
                setNumeroTour(&stEtatPartie,INIT_VAR);
                codeEtatFichier =supprimerFichier(TEXT_PATH);
                afficheEtatManipulationFichier(codeEtatFichier);
                codeEtatFichier = ajoutFichierTexte(TEXT_PATH,getNumeroTour(&stEtatPartie),getNbCelluleVivante(&stEtatPartie));
                afficheEtatManipulationFichier(codeEtatFichier);
                initAffichage(&pFenetre);

                break;
            case 10:    //avancer d'un etat � un autre  10 correspond au code ASCII DU retour chariot
                setNumeroTour(&stEtatPartie,getNumeroTour(&stEtatPartie)+1);    //incr�mentation du num�ro du tour dans l'�tat de la partie.
                etapeSuivante(stEtatPartie.stGrille,&(stEtatPartie.nNbCelluleVivante));
                codeEtatFichier = ajoutFichierTexte(TEXT_PATH,getNumeroTour(&stEtatPartie),getNbCelluleVivante(&stEtatPartie));
                afficheEtatManipulationFichier(codeEtatFichier);
                break;
            case 's':   //sauvegarde l'�tat d'une partie
                codeEtatFichier = sauvegardePartie(SAVE_PATH,&stEtatPartie);
                afficheEtatManipulationFichier(codeEtatFichier);
                codeEtatFichier = copieFichierText(SAVE_TEXT_PATH,TEXT_PATH);
                afficheEtatManipulationFichier(codeEtatFichier);
                break;
            case 'c':   //charge une sauvegarde
                arretAffichage(&pFenetre);
                codeEtatFichier = chargementPartie(SAVE_PATH,&stEtatPartie);
                afficheEtatManipulationFichier(codeEtatFichier);
                codeEtatFichier = copieFichierText(TEXT_PATH,SAVE_TEXT_PATH);
                afficheEtatManipulationFichier(codeEtatFichier);
                initAffichage(&pFenetre);
                break;
            case 'l':   //lit le fichier texte qui r�capitule la population en fonction du numero du tour..
                codeEtatFichier=afficheFichierText(TEXT_PATH);
                afficheEtatManipulationFichier(codeEtatFichier);
                break;
        }
        afficheGrilleSDL2(&pFenetre,stEtatPartie.stGrille);
        afficheGrille(stEtatPartie.stGrille);
        afficheEtatPartie(getNumeroTour(&stEtatPartie),getNbCelluleVivante(&stEtatPartie));

    }while(cMenu!='q'); //touche q permet d'interrompre le programme.
    arretAffichage(&pFenetre);

    return 0;
}
