#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <string>
#include <stdlib.h>
#include <iostream>
#include "Grille.h"

using namespace std;


int menu();
void regle_du_jeu();
string nameIt(); //fonction demandant son nom à l'utilisateur et le renvoyant
int jouerOU();    //demande ou jouer et renvoie le num de la column
void afficheVictoire(string winner);

#endif // FONCTION_H_INCLUDED

