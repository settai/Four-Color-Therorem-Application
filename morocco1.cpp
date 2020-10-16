#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;
#include "Graph.h"


void moroccoAlgo1(SDL_Window* Window)
{

        int SHOW=1;

    /* Initialisation simple de la SDL */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Rect position = { 0,0, 0, 0};
    SDL_Rect position2 = { 123,55, 0, 0};
    SDL_Rect position3 = { 35,41, 0, 0}; //map background
    SDL_Rect position4 = { 90,100, 0, 0}; //map colorings
    SDL_Rect position6 = { 405,160, 0, 0}; // fenetre de graphe

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
    SDL_Surface* graphbutton = IMG_Load("images/graphbutton.png");

	Graph g1(12);
	g1.addEdge(0, 1);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	g1.addEdge(3, 5);
	g1.addEdge(4, 5);
	g1.addEdge(4, 6);
	g1.addEdge(4, 8);
	g1.addEdge(4, 9);
	g1.addEdge(5, 6);
	g1.addEdge(5, 7);
	g1.addEdge(6, 7);
	g1.addEdge(6, 9);
	g1.addEdge(6, 10);
	g1.addEdge(7, 10);
	g1.addEdge(8, 9);
	g1.addEdge(8, 11);
	g1.addEdge(9, 11);
	g1.addEdge(9, 10);
	g1.addEdge(10, 11);

	//cout << "Coloring of Morocco Map \n";
	g1.greedyColoring();

/*on dessine l'arriere plan*/
    SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(mapbackground,NULL,SDL_GetWindowSurface(Window),&position3);
    SDL_BlitSurface(emptymap,NULL,SDL_GetWindowSurface(Window),&position4);
    SDL_BlitSurface(divisemap,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(returnbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(returnbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(graphbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_UpdateWindowSurface(Window);


        SDL_Surface* green0 = IMG_Load("images/maps/green0.png");
    SDL_Surface* red0 = IMG_Load("images/maps/red0.png");
    SDL_Surface* blue0 = IMG_Load("images/maps/blue0.png");
    SDL_Surface* yellow0 = IMG_Load("images/maps/yellow0.png");

    SDL_Surface* green1 = IMG_Load("images/maps/green1.png");
    SDL_Surface* red1 = IMG_Load("images/maps/red1.png");
    SDL_Surface* blue1 = IMG_Load("images/maps/blue1.png");
    SDL_Surface* yellow1 = IMG_Load("images/maps/yellow1.png");

    SDL_Surface* green2 = IMG_Load("images/maps/green2.png");
    SDL_Surface* red2 = IMG_Load("images/maps/red2.png");
    SDL_Surface* blue2 = IMG_Load("images/maps/blue2.png");
    SDL_Surface* yellow2 = IMG_Load("images/maps/yellow2.png");

    SDL_Surface* green3 = IMG_Load("images/maps/green3.png");
    SDL_Surface* red3 = IMG_Load("images/maps/red3.png");
    SDL_Surface* blue3 = IMG_Load("images/maps/blue3.png");
    SDL_Surface* yellow3 = IMG_Load("images/maps/yellow3.png");

    SDL_Surface* green4 = IMG_Load("images/maps/green4.png");
    SDL_Surface* red4 = IMG_Load("images/maps/red4.png");
    SDL_Surface* blue4 = IMG_Load("images/maps/blue4.png");
    SDL_Surface* yellow4 = IMG_Load("images/maps/yellow4.png");

    SDL_Surface* green5 = IMG_Load("images/maps/green5.png");
    SDL_Surface* red5 = IMG_Load("images/maps/red5.png");
    SDL_Surface* blue5 = IMG_Load("images/maps/blue5.png");
    SDL_Surface* yellow5 = IMG_Load("images/maps/yellow5.png");

    SDL_Surface* green6 = IMG_Load("images/maps/green6.png");
    SDL_Surface* red6 = IMG_Load("images/maps/red6.png");
    SDL_Surface* blue6 = IMG_Load("images/maps/blue6.png");
    SDL_Surface* yellow6 = IMG_Load("images/maps/yellow6.png");

    SDL_Surface* green7 = IMG_Load("images/maps/green7.png");
    SDL_Surface* red7 = IMG_Load("images/maps/red7.png");
    SDL_Surface* blue7 = IMG_Load("images/maps/blue7.png");
    SDL_Surface* yellow7 = IMG_Load("images/maps/yellow7.png");

    SDL_Surface* green8 = IMG_Load("images/maps/green8.png");
    SDL_Surface* red8 = IMG_Load("images/maps/red8.png");
    SDL_Surface* blue8 = IMG_Load("images/maps/blue8.png");
    SDL_Surface* yellow8 = IMG_Load("images/maps/yellow8.png");

    SDL_Surface* green9 = IMG_Load("images/maps/green9.png");
    SDL_Surface* red9 = IMG_Load("images/maps/red9.png");
    SDL_Surface* blue9 = IMG_Load("images/maps/blue9.png");
    SDL_Surface* yellow9 = IMG_Load("images/maps/yellow9.png");

    SDL_Surface* green10 = IMG_Load("images/maps/green10.png");
    SDL_Surface* red10 = IMG_Load("images/maps/red10.png");
    SDL_Surface* blue10 = IMG_Load("images/maps/blue10.png");
    SDL_Surface* yellow10 = IMG_Load("images/maps/yellow10.png");

    SDL_Surface* green11 = IMG_Load("images/maps/green11.png");
    SDL_Surface* red11 = IMG_Load("images/maps/red11.png");
    SDL_Surface* blue11 = IMG_Load("images/maps/blue11.png");
    SDL_Surface* yellow11 = IMG_Load("images/maps/yellow11.png");


    SDL_Surface* maps[12][4]={{green0,red0,blue0,yellow0},{green1,red1,blue1,yellow1},{green2,red2,blue2,yellow2},{green3,red3,blue3,yellow3},
                            {green4,red4,blue4,yellow4},{green5,red5,blue5,yellow5},{green6,red6,blue6,yellow6},{green7,red7,blue7,yellow7},
                            {green8,red8,blue8,yellow8},{green9,red9,blue9,yellow9},{green10,red10,blue10,yellow10},{green11,red11,blue11,yellow11}};


	// affichage de colouer lors de clic sur suivant
    SDL_Event event;

    for (int u = -1; u < 12; u++)
	{
	    if (u==-1)
        {
            while (SDL_WaitEvent(&event) ) // attente de clic sur SUIVANT
            {

                if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
                {
                        if (830<event.button.x&&event.button.x<1270&&265<event.button.y&&event.button.y<370)
                        {
                            SDL_BlitSurface(suivant,NULL,SDL_GetWindowSurface(Window),&position);
                            SDL_BlitSurface(linedmap,NULL,SDL_GetWindowSurface(Window),&position4);
                            SDL_UpdateWindowSurface(Window);
                            break;
                        }

                         else if (830<event.button.x&&event.button.x<1270&&407<event.button.y&&event.button.y<520)
                        {
                            return;
                        }
                }
            }
        }


        else
        {

	    int color=g1.whatColor(u); // coleur correspondant
	    SDL_Surface* colormap=maps[u][color]; // capture de l'image correspondant a cette couleu


        while (SDL_WaitEvent(&event) ) // attente de clic sur SUIVANT
        {



            if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
            {
                     if (830<event.button.x&&event.button.x<1270&&265<event.button.y&&event.button.y<370)
                    {
                        SDL_BlitSurface(colormap,NULL,SDL_GetWindowSurface(Window),&position4);
                        SDL_UpdateWindowSurface(Window);
                        break;
                    }

                    else if (830<event.button.x&&event.button.x<1270&&407<event.button.y&&event.button.y<520)
                    {
                        return;
                    }

                    else if(975<event.button.x&&event.button.x<1160&&677<event.button.y&&event.button.y<727)
                    {


                        SDL_Surface* save = IMG_Load("images/save.png");

                        if (SHOW==1)
                        {
                            SHOW=0;
                            IMG_SavePNG(SDL_GetWindowSurface(Window), "images/save.png");
                            SDL_BlitSurface(moroccograph,NULL,SDL_GetWindowSurface(Window),&position);
                        }
                        else
                        {
                            SHOW=1;
                            SDL_BlitSurface(save,NULL,SDL_GetWindowSurface(Window),&position);
                        }

                        SDL_UpdateWindowSurface(Window);
                        fprintf(stdout,"SHOW = %d \n",SHOW);


                    }

            }


        }

        if (u==11)
        {

        while (SDL_WaitEvent(&event) ) // attente de clic sur SUIVANT
        {
            if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
            {
                    if (830<event.button.x&&event.button.x<1270&&407<event.button.y&&event.button.y<520)
                    {
                        for (int i=0; i<12; i++)
                            for(int j=0; j<4; j++)
                                SDL_FreeSurface(maps[i][j]);
                        return;
                    }


            }


        }
        }



    }

}


}

