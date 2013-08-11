#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include "../inc/Grille.h"
#include "../inc/fonction.h"


using namespace std;

int i = 0;
int j = 0;


// constructeur avec i et j déclaré plus haut
Grille::Grille()
    {
        for (j=0; j<7; j++)
            {
                hauteur_[j] = 0;
            }
        for (i=0; i<6; i++)
            {
                for (j=0; j<7; j++)
                    {
                        plateau_[i][j] = ' ';
                    }
            }
    };


//affichage du plateau de jeu
void Grille::affichePlateau()
    {
        int i = 0;
        int j = 0;

        cout << " ___ ___ ___ ___ ___ ___ ___ " << endl;
        cout << "| 0 | 1 | 2 | 3 | 4 | 5 | 6 |" << endl;
        cout << " ___ ___ ___ ___ ___ ___ ___ " << endl;



        for(i=0;i<6;i++)
            {
                for(j=0;j<7;j++)
                    {
                        cout << "| " << plateau_[i][j] << " ";
                    }
                cout << "|" << endl ;
                cout << "|===|===|===|===|===|===|===|" << endl;
            }
    cout << endl;
    };




//fonction plçant les pions
void Grille::placerPion(int column, char caractereJoue,int& AJoue)
    {
        if ((column == 0)||(column == 1)||(column == 2)||(column == 3)||(column == 4)||(column == 5)||(column == 6)) //si la colonne existe
            {
                if (hauteur_[column]<6) //et si la colonne n'est pas pleine !
                    {
                        plateau_[5-hauteur_[column]][column] = caractereJoue;
                        hauteur_[column] ++;
                        AJoue=1; //alors on place le caractere du joueur, on incremente la heuteur de la colonne, et on dit que le joueur a joué
                    }
                else
                    {
                        cout<<"Veuillez choisir une autre colonne, celle-ci est pleine !"<<endl;
                        AJoue=0;
                    }  //la colonne est pleine donc le joueur n'a pas joué, on ne quitte pas la boucle while dans le main
            }
        else
            {
                cout<<"Veuillez choisir colonne qui existe !"<<endl;
                AJoue=0;
            }  //idem mais la source de l'erreur est le choix d'une colonne inexistante
    };


int Grille::testVictoire(char pion, string name)
    {

        int i = 0;
        int j = 0;
        int gagne = 0;
/*Vérification horizontale pour savoir si le joueur a gagné:
on balaye toutes les lignes de 0 à 6 en vérifiant 4 cases à chaque fois
Si 4 cases qui se suivent valent 1 alors gagne prend pour valeur 1*/
        for(j=0;j<4;j++)
            {
                for(i=0;i<6;i++)
                    {
                        if(plateau_[i][j]==pion && plateau_[i+1][j]==pion&& plateau_[i+2][j]==pion&& plateau_[i+3][j]==pion)
                            {gagne=1;}
                    }
            }
/*Même chose mais verticalement maintenant*/
        for(j=0;j<7;j++)
            {
                for(i=0;i<3;i++)
                    {
                        if(plateau_[i][j]==pion && plateau_[i][j+1]==pion && plateau_[i][j+2]==pion && plateau_[i][j+3]==pion)
                            {gagne=1;}
                    }
            }
/*Et diagonale bas gauche vers haut droit*/
        for(j=0;j<7;j++)
            {
                for(i=0;i<6;i++)
                    {
                        if(plateau_[i][j]==pion && plateau_[i+1][j+1]==pion && plateau_[i+2][j+2]==pion && plateau_[i+3][j+3]==pion)
                            {gagne=1;}
                    }
            }
/*Même chose pour les diagonales bas droite vers haut gauche*/
        for(i=0;i<6;i++)
            {
                for(j=6;j>=0;j--)
                    {
                        if(plateau_[i][j]==pion && plateau_[i-1][j+1]==pion && plateau_[i-2][j+2]==pion && plateau_[i-3][j+3]==pion)
                            {gagne=1;}
                    }
            }
        if (gagne==1) {afficheVictoire(name);}
        return gagne;
    };


