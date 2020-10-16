#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

// Number of vertices in the graph
#define V 12

void printSolution(int color[]);

/* A utility function to check if the current color assignment
is safe for vertex v */
bool isSafe (int v, bool graph[V][V], int color[], int c)
{
for (int i = 0; i < V; i++)
if (graph[v][i] && c == color[i])
return false;
return true;
}

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
/* base case: If all vertices are assigned a color then
return true */
if (v == V)
return true;

/* Consider this vertex v and try different colors */
for (int c = 1; c <= m; c++)
{
/* Check if assignment of color c to v is fine*/
if (isSafe(v, graph, color, c))
{
color[v] = c;

/* recur to assign colors to rest of the vertices */
if (graphColoringUtil (graph, m, color, v+1) == true)
return true;

/* If assigning color c doesn't lead to a solution
then remove it */
color[v] = 0;
}
}

/* If no color can be assigned to this vertex then return false */
return false;
}

/* This function solves the m Coloring problem using Backtracking.
It mainly uses graphColoringUtil() to solve the problem. It returns
false if the m colors cannot be assigned, otherwise return true and
prints assignments of colors to all vertices. Please note that there
may be more than one solutions, this function prints one of the
feasible solutions.*/
bool graphColoring(bool graph[V][V], int m)
{
// Initialize all color values as 0. This initialization is needed
// correct functioning of isSafe()
int *color = new int[V];
for (int i = 0; i < V; i++)
color[i] = 0;

// Call graphColoringUtil() for vertex 0
if (graphColoringUtil(graph, m, color, 0) == false)
{
fprintf(stdout,"Solution does not exist");
return false;
}

// Print the solution
printSolution(color);
return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
fprintf(stdout,"Solution Exists:"
" Following are the assigned colors \n");
for (int i = 0; i < V; i++)
fprintf(stdout," %d ", color[i]);
fprintf(stdout,"\n");
}


void moroccoAlgo2(SDL_Window* Window)
{

    bool graph[V][V];
    for (int i=0; i<V; i++)
        for (int j=0; j<V; j++)
            graph[i][j]=0;

    graph[0][1]=1;
	graph[1][2]=1;
	graph[2][3]=1;
	graph[3][4]=1;
	graph[3][5]=1;
	graph[4][5]=1;
	graph[4][6]=1;
	graph[4][8]=1;
	graph[4][9]=1;
	graph[5][6]=1;
	graph[5][7]=1;
	graph[6][7]=1;
	graph[6][9]=1;
	graph[6][10]=1;
	graph[7][10]=1;
	graph[8][9]=1;
	graph[8][11]=1;
	graph[9][11]=1;
	graph[9][10]=1;
	graph[10][11]=1;

    for (int i=0; i<V; i++)
        for (int j=0; j<V; j++)
            if (graph[i][j]==1)
                graph[j][i]=1;

    int m=4;

    int *color = new int[48];
    for (int i = 0; i < 48; i++)
    color[i] = 0;

    graphColoringUtil(graph, m, color, 0);

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

	    int thecolor=color[u]; // coleur correspondant
	    SDL_Surface* colormap=maps[u][thecolor-1]; // capture de l'image correspondant a cette couleu


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
