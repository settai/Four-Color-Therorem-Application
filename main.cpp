// A C++ program to implement greedy algorithm for graph coloring
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;
#include "Graph.h"


int homepage_choice(SDL_Window* Window);
int algopage_choice(SDL_Window* Window, int maptocolor);

void moroccoAlgo1(SDL_Window* Window);
void africaAlgo1(SDL_Window* Window);

void moroccoAlgo2(SDL_Window* Window);
void africaAlgo2(SDL_Window* Window);

void africaAlgo2AUTO(SDL_Window* Window, int colorsNbr);


int main(int argc, char** argv)
{

    /* Initialisation simple de la SDL */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Rect position = { 0,0, 0, 0};

    /* Création de la fenêtre principale SDL et son titre*/
    SDL_Window* Window = NULL;
    Window = SDL_CreateWindow("Greedy Algorithme - Coloration de la carte du Maroc",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1344,756,SDL_WINDOW_SHOWN);

    /* Chargement des images */
    SDL_Surface* background = IMG_Load("images/background.jpg");
    SDL_Surface* mapbackground = IMG_Load("images/mapbackground.png");
    SDL_Surface* emptymap = IMG_Load("images/emptymap.png");
    SDL_Surface* suivant = IMG_Load("images/suivant.png");
    SDL_Surface* suivanthover = IMG_Load("images/suivanthover.png");
    SDL_Surface* returnbutton = IMG_Load("images/return.png");
    SDL_Surface* divisemap = IMG_Load("images/divisemap.png");
    SDL_Surface* linedmap = IMG_Load("images/linedmap.png");
    SDL_Surface* moroccograph = IMG_Load("images/moroccograph.png");




home:
while(1)
{

    int choice=homepage_choice(Window); // Affichage de Page d'acceuil ou première menu et acquisition de choix effectué


    switch(choice) {


       case 1:
           choice=algopage_choice(Window,1);
           switch(choice)
           {
                case 1: moroccoAlgo1(Window); goto home;
                case 2: moroccoAlgo2(Window); goto home;
                case 3: goto home;
           }

        case 2:
           choice=algopage_choice(Window,2);
           switch(choice)
           {
                case 1: africaAlgo1(Window); goto home;
                case 2: africaAlgo2AUTO(Window,4); goto home;
                case 4: africaAlgo2AUTO(Window,3); goto home;;
                case 3: goto home;
           }

       case 3:
            SDL_DestroyWindow(Window);
            return 0;
    }

}
}



int homepage_choice(SDL_Window* Window)
{
    int choice;
    SDL_Rect position = { 0,0, 0, 0};

    /*chargement des images */
    SDL_Surface* homepage = IMG_Load("images/homepage.png");


    /*on dessine l'arriere plan*/
    SDL_BlitSurface(homepage,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_UpdateWindowSurface(Window);

    SDL_Event event;
    while (SDL_WaitEvent(&event) )
    {
        if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
        {
                if (566<event.button.x&&event.button.x<872&&323<event.button.y&&event.button.y<410)
                    {choice=1; SDL_FreeSurface(homepage); return choice;}

                else if (566<event.button.x&&event.button.x<872&&438<event.button.y&&event.button.y<522)
                    {choice=2; SDL_FreeSurface(homepage); return choice;}

                else if (566<event.button.x&&event.button.x<872&&554<event.button.y&&event.button.y<640)
                    {choice=3; SDL_FreeSurface(homepage); return choice;}

        }

    }

}


int algopage_choice(SDL_Window* Window, int maptocolor)
{
    int choice;
    SDL_Rect position = { 0,0, 0, 0};

    /*chargement des images */
    SDL_Surface* algopage = IMG_Load("images/algopage.png");
    SDL_Surface* bonus3 = IMG_Load("images/bonus3.png");


    /*on dessine l'arriere plan*/
    SDL_BlitSurface(algopage,NULL,SDL_GetWindowSurface(Window),&position);
    if (maptocolor == 2 ) SDL_BlitSurface(bonus3,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_UpdateWindowSurface(Window);

    SDL_Event event;
    while (SDL_WaitEvent(&event) )
    {
        if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
        {
                if (566<event.button.x&&event.button.x<872&&323<event.button.y&&event.button.y<410)
                    {choice=1; SDL_FreeSurface(algopage); SDL_FreeSurface(bonus3); return choice;}

                else if (566<event.button.x&&event.button.x<872&&438<event.button.y&&event.button.y<522)
                    {choice=2; SDL_FreeSurface(algopage); SDL_FreeSurface(bonus3); return choice;}

                 else if (893<event.button.x&&event.button.x<1000&&426<event.button.y&&event.button.y<532)
                    {choice=4; SDL_FreeSurface(algopage); SDL_FreeSurface(bonus3); return choice;}

                else if (566<event.button.x&&event.button.x<872&&554<event.button.y&&event.button.y<640)
                    {choice=3; SDL_FreeSurface(algopage); SDL_FreeSurface(bonus3); return choice;}

        }

    }

}
