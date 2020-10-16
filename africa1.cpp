#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
#include "Graph.h"


void africaAlgo1(SDL_Window* Window)
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
    SDL_Surface* emptymapafrica = IMG_Load("images/emptymapafrica.png");
    SDL_Surface* suivant = IMG_Load("images/suivant.png");
    SDL_Surface* suivanthover = IMG_Load("images/suivanthover.png");
    SDL_Surface* returnbutton = IMG_Load("images/return.png");
    SDL_Surface* divisemap = IMG_Load("images/divisemap.png");
    SDL_Surface* linedmapafrica = IMG_Load("images/linedmapafrica.png");
    SDL_Surface* africagraph = IMG_Load("images/africagraph.png");
    SDL_Surface* graphbutton = IMG_Load("images/graphbutton.png");


	Graph g1(48);
	g1.addEdge(0, 1);g1.addEdge(0, 5);
	g1.addEdge(1, 2);g1.addEdge(1, 3);g1.addEdge(1, 5);g1.addEdge(1, 6);g1.addEdge(1, 7);
	g1.addEdge(2, 3);
	g1.addEdge(3, 7);g1.addEdge(3, 8);g1.addEdge(3, 4);g1.addEdge(3, 9);
	g1.addEdge(4, 9);
	g1.addEdge(5, 6);g1.addEdge(5, 14);
	g1.addEdge(6, 14);g1.addEdge(6, 17);g1.addEdge(6, 21);g1.addEdge(6, 7);g1.addEdge(6, 20);
	g1.addEdge(7, 8);g1.addEdge(7, 21);g1.addEdge(7, 24);g1.addEdge(7, 25);
	g1.addEdge(8, 9);g1.addEdge(8, 25);g1.addEdge(8, 26);g1.addEdge(8, 27);
	g1.addEdge(9, 10);g1.addEdge(9, 12);g1.addEdge(9, 32);g1.addEdge(9, 31);g1.addEdge(9, 27);g1.addEdge(9, 33);
	g1.addEdge(10, 11);g1.addEdge(10, 12);
	g1.addEdge(11, 12);g1.addEdge(11, 13);
	g1.addEdge(12, 13);g1.addEdge(12, 33);
	g1.addEdge(13, 33);
	g1.addEdge(14, 15);g1.addEdge(14, 16);g1.addEdge(14, 17);
	g1.addEdge(16, 17);
	g1.addEdge(17, 18);g1.addEdge(17, 19);g1.addEdge(17, 20);
	g1.addEdge(18, 19);
	g1.addEdge(19, 20);
	g1.addEdge(20, 21);g1.addEdge(20, 22);
	g1.addEdge(21, 22);g1.addEdge(21, 23);g1.addEdge(21, 24);
	g1.addEdge(22, 23);
	g1.addEdge(23, 24);
	g1.addEdge(24, 25);
	g1.addEdge(25, 26);
	g1.addEdge(26, 27);g1.addEdge(26, 28);g1.addEdge(26, 29);g1.addEdge(26, 30);
	g1.addEdge(27, 30);g1.addEdge(27, 31);
	g1.addEdge(28, 29);
	g1.addEdge(29, 30);
	g1.addEdge(30, 31);
	g1.addEdge(31, 32);g1.addEdge(31, 34);g1.addEdge(31, 35);g1.addEdge(31, 36);g1.addEdge(31, 37);g1.addEdge(31, 46);
	g1.addEdge(32, 33);g1.addEdge(32, 34);g1.addEdge(32, 36);
	g1.addEdge(33, 36);
	g1.addEdge(34, 35);g1.addEdge(34, 36);
	g1.addEdge(35, 36);
	g1.addEdge(36, 37);g1.addEdge(36, 38);g1.addEdge(36, 39);
	g1.addEdge(37, 38);g1.addEdge(37, 46);g1.addEdge(37, 40);g1.addEdge(37, 42);g1.addEdge(37, 39);
	g1.addEdge(38, 39);
	g1.addEdge(39, 42);g1.addEdge(39, 43);
	g1.addEdge(40, 46);g1.addEdge(40, 41);g1.addEdge(40, 43);
	g1.addEdge(41, 42);g1.addEdge(41, 43);
	g1.addEdge(42, 44);
	g1.addEdge(43, 44);g1.addEdge(43, 45);























	//cout << "Coloring of Morocco Map \n";
	g1.greedyColoring();

/*on dessine l'arriere plan*/
    SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(mapbackground,NULL,SDL_GetWindowSurface(Window),&position3);
    SDL_BlitSurface(emptymapafrica,NULL,SDL_GetWindowSurface(Window),&position4);
    SDL_BlitSurface(divisemap,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(returnbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(returnbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(graphbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_UpdateWindowSurface(Window);

    // chargement des images colories pour l'afrique
    SDL_Surface* maps[48][4];
    int i=0,j=0;
    for (i=0; i<48; i++)
        for(j=0; j<4; j++)
        {
            if (i<10)
            {
                string green="images/africa/green";
                green.push_back((char)(i + '0'));
                green=green+".png";

                string red="images/africa/red";
                red.push_back((char)(i + '0'));
                red=red+".png";

                string blue="images/africa/bleu";
                blue.push_back((char)(i + '0'));
                blue=blue+".png";

                string yellow="images/africa/yellow";
                yellow.push_back((char)(i + '0'));
                yellow=yellow+".png";

            const char *cgreen = green.c_str();
            const char *cred = red.c_str();
            const char *cblue = blue.c_str();
            const char *cyellow = yellow.c_str();

            if (j==0) maps[i][j]=IMG_Load(cgreen);
            else if (j==1) maps[i][j]=IMG_Load(cred);
            else if (j==2) maps[i][j]=IMG_Load(cblue);
            else if (j==3) maps[i][j]=IMG_Load(cyellow);
            }

            else if (i>=10)
            {
                int a=i/10;
                int b=i-10*a;

                string green="images/africa/green";
                green.push_back((char)(a + '0'));
                green.push_back((char)(b + '0'));
                green=green+".png";



                string red="images/africa/red";
                red.push_back((char)(a + '0'));
                red.push_back((char)(b + '0'));
                red=red+".png";


                string blue="images/africa/bleu";
                blue.push_back((char)(a + '0'));
                blue.push_back((char)(b + '0'));
                blue=blue+".png";


                string yellow="images/africa/yellow";
                yellow.push_back((char)(a + '0'));
                yellow.push_back((char)(b + '0'));
                yellow=yellow+".png";

            const char *cgreen = green.c_str();
            const char *cred = red.c_str();
            const char *cblue = blue.c_str();
            const char *cyellow = yellow.c_str();

            if (j==0) maps[i][j]=IMG_Load(cgreen);
            else if (j==1) maps[i][j]=IMG_Load(cred);
            else if (j==2) maps[i][j]=IMG_Load(cblue);
            else if (j==3) maps[i][j]=IMG_Load(cyellow);
            }




        }



	// affichage de colouer lors de clic sur suivant


    SDL_Event event;

    for (int u = -1; u < 48; u++)
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
                            SDL_BlitSurface(linedmapafrica,NULL,SDL_GetWindowSurface(Window),&position4);
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
                        fprintf(stdout,"u = %d - color = %d\n",u,color);
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
                            SDL_BlitSurface(africagraph,NULL,SDL_GetWindowSurface(Window),&position);
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

        if (u==47)
        {

        while (SDL_WaitEvent(&event) ) // attente de clic sur SUIVANT
        {
            if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
            {
                    if (830<event.button.x&&event.button.x<1270&&407<event.button.y&&event.button.y<520)
                    {
                            for (i=0; i<48; i++)
                                for(j=0; j<4; j++)
                                    SDL_FreeSurface(maps[i][j]);
                        return;
                    }


            }


        }
        }

        }

    }


}

