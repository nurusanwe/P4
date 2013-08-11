#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "inc/fonction.h"
#include "inc/Joueur.h"
#include "inc/Grille.h"
#include "api/inc/fmod.h"
//#include <windows.h>


/*
{
Pour la sauvegarde => Sauvegarder au moins la grille jeu.save() après chaque coup joué, réécris par dessus dans le fichier .txt

Problème : on manipule la classe joueur dans les parties : un deuxième fichier .txt enregistrant les noms et pions des joueurs ? J1.save()
et J2.save() qui se rajoutent à la suite dans le.txt ?

Le restore => on recrée les objet J1 et J2 avec le constructeur et les données du deuxième .txt
On recrée une grille et on la remplis avec les données du premier .txt => créer un autre constructeur ? Remplir les cases du tableau
manuellement ?
}

*/


using namespace std;

int main()

{


srand(time(NULL));

int choix = 0; //variable du menu
int test = 0; //le joueur ne passe pas son tour si il se trompe de colonnes


//on créé les objets sons et on initialise la biblio
FMOD_SYSTEM *system;
FMOD_SOUND *musique;
FMOD_RESULT resultat;

FMOD_System_Create(&system);
FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);

/* On ouvre la musique */
resultat = FMOD_System_CreateSound(system, "Kalimba.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);

//On check que le son est bien chargé
if (resultat != FMOD_OK)
	{
		fprintf(stderr, "Impossible de lire le fichier mp3\n");
		exit(EXIT_FAILURE);
	}

/* On active la répétition de la musique à l'infini */
FMOD_Sound_SetLoopCount(musique, -1);

/* On joue la musique */
FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);

//le programme tourne jusqu'a ce que l'on ai tape la valeur 4 dans le choix = menu()
while (choix !=4)
        {
            choix = menu();

            //les differents choix possible et leurs actions (switch est incompatible avec l'initialisation d'objets)
            //choix 1 efface la console, affiche les regles du jeu, met sur pause et réafiche le menu en rééfacant les regles auparavant
            if (choix == 1)
                {
                    std::system("clear") ;
                    regle_du_jeu();
                    cout<<"Appuyez sur une touche puis entree pour continuer"<<endl;
                    getchar();                                                 //Met le system en pause, attends la saisie d'un caractere
                    getchar();
                    std::system("clear") ;

                }




            //choix 2 nouveau jeu
            else if(choix == 2)
                {
                    //clear la console et crée les objets
                    std::system("clear") ;

                    int New=0;

                    cout<<"Attention en commencant une nouvelle partie vous allez perdre la sauvegarde de la partie precedemment";
                    cout<<"entame, souhaitez vous tout de meme poursuivre ?"<<endl;
                    cout<<"Pour continuer tapez 1, pour revenir au menu tapez 0"<<endl;
                    cin>>New;

                    if(New==1)    //Si la personne souhaite reset sa sauvegarde
                    {
                    Grille jeu;
                    int gagne = 0; //condition d'arret de la boucle de jeu au tour par tour
                    cout<<"Joueur 1 :"<<endl;
                    Joueur J1(nameIt(),'X'); //nameIt dans fonction.h => affiche la demande de nom et renvoie un string ayant le nom du joueur
                    cout<<"Joueur 2 : "<<endl;
                    Joueur J2(nameIt(),'O');


                    jeu.affichePlateau();    //fonction dans Grille.h : affiche plateau_[ligne][column]



                    if(J1.ordreDeJeu()>J2.ordreDeJeu())         //Pour determiner qui doit jouer en premier de manière aléatoire ^^
                        {
                            while (gagne!=1)//condition d'arrêt du jeu
                                {
                                    //ces while sont pour tester que le personne a bien joue : voir placerPion dans Grille.h, au passage on clear l'écran et on réaffiche la grille
                                    while(test==0)
                                        {
                                            cout<<J1.getName()<<" avec le pion "<<J1.getPion()<<" a vous de jouer :"<<endl;
                                            jeu.placerPion(jouerOU(),J1.getPion(),test);              //on place le pion avec jouerOU() (affiche et renvoie une colonne), getPion pour savoir quel pion placer et test pour controler que la personne a bien jouée
                                        };

                                        test = 0;  //on remet a zero la variable test a chaque sortie de boucle : le joueur n'a pas encore joué, si il joue bien sa variable test deviendra 1 dans la boucle, avant de se reset a zero en sortie de boucle, etc

                                        std::system("clear");
                                        jeu.affichePlateau();

                                        gagne = jeu.testVictoire(J1.getPion(),J1.getName());
                                        if (gagne==1) continue;    //gagne prends 1 et ferme la boucle en cas de victoire, de plus en cas de victoire affiche le nom du joueur via getName

                                        while(test==0)
                                            {
                                                cout<<J2.getName()<<" avec le pion "<<J2.getPion()<<"a vous de jouer :"<<endl;
                                                jeu.placerPion(jouerOU(),J2.getPion(),test);
                                            };

                                        std::system("clear");
                                        jeu.affichePlateau();
                                        test = 0;
                                        gagne = jeu.testVictoire(J2.getPion(),J2.getName());
                                };
                        }
                    else //Si c'est au joueur 2 de commencer en premier on réécrit le même code en inversant
                        {
                            while (gagne!=1)//condition d'arrêt du jeu
                                {
                                    while(test==0)
                                        {
                                            cout<<J2.getName()<<" avec le pion "<<J2.getPion()<<" a vous de jouer :"<<endl;
                                            jeu.placerPion(jouerOU(),J2.getPion(),test);
                                        };

                                    std::system("clear");
                                    jeu.affichePlateau();
                                    test = 0;
                                    gagne = jeu.testVictoire(J2.getPion(),J2.getName());
                                    if (gagne==1) continue;

                                    while(test==0)
                                        {
                                            cout<<J1.getName()<<" avec le pion "<<J1.getPion()<<" a vous de jouer :"<<endl;
                                            jeu.placerPion(jouerOU(),J1.getPion(),test);
                                        };

                                    test = 0;

                                    std::system("clear");
                                    jeu.affichePlateau();

                                    gagne = jeu.testVictoire(J1.getPion(),J1.getName());
                                };
                        }

                }
                else{}; //Si la personne ne veux pas reset sa sauvegarde on la ramene au menu directement
                }

            else if (choix == 3)   //continuer le jeu, untilise un service grille.restore
                {

                }

            else if(choix == 4)  //quitter, pour éviter l'affichage du else apparait avec rien
                {

                }

            else
                {cout<<"Entrez une valeur correcte"<<endl;}

        };


return 0;

}
