#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "../inc/Joueur.h"
#include "../inc/fonction.h"
#include <string>
#include "../inc/Grille.h"

using namespace std;


// implementation constructeur joueur apres demande d'informations ˆ l'utilisateur

Joueur::Joueur(string nom, char pion) : nom_(nom), pion_(pion)
    {

    };

char Joueur::getPion()
    {
        return pion_;
    };

string Joueur::getName()
    {
        return nom_;
    };

int Joueur::ordreDeJeu()
    {

        return rand();
    };

