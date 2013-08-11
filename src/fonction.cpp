#ifndef FONCTION_CPP_INCLUDED
#define FONCTION_CPP_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "../inc/fonction.h"
#include "../inc/Grille.h"
#include <string>

using namespace std;

int menu()
    {

        int choix = 0 ;

        cout << "           ****************************************************************" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *  ***  * *  *  ****  ****  ****  *    *  ****  ****    *      *" << endl;
        cout << "           *  * *  * *  *  *     *     *  *  *    *  *     *       *      *" << endl;
        cout << "           *  ***  * *  *  ****  ****  ****  * *  *  *     ****    *  *   *" << endl;
        cout << "           *  *    * *  *     *     *  *  *  *  * *  *     *       *****  *" << endl;
        cout << "           *  *    ***  *  ****  ****  *  *  *    *  ****  ****       *   *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *                         cree par                             *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *           Romain GARDET et Patricia LAUBERTIE                *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           ****************************************************************" << endl;
        cout << "           ****************************************************************" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *                           MENU                               *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           ****************************************************************" << endl;
        cout << "           ****************************************************************" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *              1 - Regles du jeu                               *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *              2 - Nouvelle partie                             *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *              3 - Reprendre la partie en cours                *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *              4 - Quitter                                     *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           ****************************************************************" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *              *** Que voulez-vous faire ? ***                 *" << endl;
        cout << "           *                                                              *" << endl;
        cout << "           *              (entrer le numero de votre choix)               *" << endl;
        cout << "           ****************************************************************" << endl;
        cin >> choix ;

        return choix ;

    };

void regle_du_jeu()
    {

        cout << "       ****************************************************************" << endl;
        cout << "       *                                                              *" << endl;
        cout << "       *                        REGLES DU JEU                         *" << endl;
        cout << "       *                                                              *" << endl;
        cout << "       ****************************************************************" << endl;
        cout << "       * Le but du jeu est d'aligner 4 pions sur une grille comptant  *" << endl;
        cout << "       * 6 rangees et 7 colonnes. Chaque joueur dispose de 21 pions   *" << endl;
        cout << "       * Tour a tour les deux joueurs placent, un pion dans la colon- *" << endl;
        cout << "       * ne de leur choix, le pion coulisse alors jusqu'a la position *" << endl;
        cout << "       * la  plus basse possible dans la colonne suite a quoi c'est a*" << endl;
        cout << "       * l'adversaire de jouer. Le vainqueur est le joueur qui reali- *" << endl;
        cout << "       * se le premier un alignement (horizontal, vertical ou diago-  *" << endl;
        cout << "       * nal) d'au moins quatre pions de sa couleur. Si alors que     *" << endl;
        cout << "       * toutes les cases de la grille de jeu sont remplies aucun des *" << endl;
        cout << "       * deux joueurs n'a realise un tel alignement, la partie est    *" << endl;
        cout << "       * declaree nulle.                                              *" << endl;
        cout << "       *                                                              *" << endl;
        cout << "       ****************************************************************" << endl;
        cout<<endl;
        cout<<endl;

    };


string nameIt()
    {
        string name;
        cout<<"Veuillez entrer votre nom :"<<endl;
        cin>>name ;
        cout<<endl;
        return name;
    };

    int jouerOU()
    {
        int columnJoue = 0;
        cout<<"Ou souhaitez vous jouer votre pion ?"<<endl;
        cin>>columnJoue;
        cout<<endl;
        return columnJoue;
    };


void afficheVictoire(string winner)
    {
        cout<<endl;
        cout<<"             ************************************************************************"<<endl;
        cout<<"             *   Le joueur "<<winner<<" vient de l'emporter haut la main ^^ !!!!!   *"<<endl;
        cout<<"             ************************************************************************"<<endl;
        cout<<endl;
    };

#endif // FONCTION_CPP_INCLUDED

