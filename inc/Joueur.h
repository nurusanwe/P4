#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string>
#include <stdlib.h>
#include <iostream>
#include "fonction.h"
#include "Grille.h"

using namespace std;

class Joueur{
    public:
        // Constructeur de l'objet joueur
        Joueur(string nom, char Pion); //le nom s'obtiendra grâce à nameIt() dans fonction.h, qui renvoie un string

        // Les services
        char getPion(); // service qui renvoie le pion choisit par le joueur et le donne au service placerPion de Grille.h
        string getName();      //renvoie le nom pour la fonction affiche victoire qui est utlisée dans le service testVictoire de la grille.cpp
        int ordreDeJeu();

    private:
    // Donnees membres
    string nom_;
    char pion_;
};

#endif // JOUEUR_H_INCLUDED
