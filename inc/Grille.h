#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "fonction.h"

using namespace std;

class Grille{
    public :

        // Constructeur de la grille par defaut
        Grille();

        // Les services
        void affichePlateau();                                         //affiche le plateau
        void placerPion(int column, char caractereJoue, int& Ajoue);  //passage par référence de la variable test qui vérifie si le joueur a joue ou a fait une erreur de frappe dans sa colonne
        int testVictoire(char pion, string name);                     //renvoie 0 ou 1, prends le nom des pions a vérifier, et déclare le joueur avec son name associé gagnant ou nom



    private :

        int hauteur_[7];
        char plateau_[6][7];
};

#endif // GRILLE_H_INCLUDED
