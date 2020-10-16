#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

// Number of vertices in the graph
#define X 48


bool isSafe (int v, bool graph[48][48], int color[], int c);


/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool graph[48][48], int m, int color[], int v, SDL_Window* Window, SDL_Surface* maps[48][5])
{
    SDL_Surface* africagraph = IMG_Load("images/africagraph.png");
                    SDL_Rect position = { 0,0, 0, 0};
    int SHOW=1;
    SDL_Rect position4 = { 90,100, 0, 0}; //map colorings

    /* base case: If all vertices are assigned a color then
    return true */
    if (v == 48)
        return true;

    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++)
    {
        /* Check if assignment of color c to v is fine*/
        if (isSafe(v, graph, color, c))
        {

            if (v==-1)
            {
                SDL_Surface* suivant = IMG_Load("images/suivant.png");
                SDL_Surface* linedmapafrica = IMG_Load("images/linedmapafrica.png");
                SDL_Rect position = { 0,0, 0, 0};

                SDL_Event event;
                while (SDL_WaitEvent(&event) ) // attente de clic sur SUIVANT
                {

                    if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
                    {
                            if (830<event.button.x&&event.button.x<1270&&265<event.button.y&&event.button.y<370)
                            {
                                SDL_BlitSurface(suivant,NULL,SDL_GetWindowSurface(Window),&position);
                                SDL_BlitSurface(linedmapafrica,NULL,SDL_GetWindowSurface(Window),&position4);
                                SDL_UpdateWindowSurface(Window);
                                v++;
                                c--;
                                break;
                            }

                             else if (830<event.button.x&&event.button.x<1270&&407<event.button.y&&event.button.y<520)
                            {
                                return 0;
                            }
                    }
                }
            }



            else if (v>=0)
            {


            /*if (30<v && v<37)
                SDL_Delay(1000);
            else
                SDL_Delay(300);*/


            if (m==4)
            {
            SDL_Event event;
            while (SDL_WaitEvent(&event) ) // attente de clic sur SUIVANT
            {
                if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
                {

                        if (830<event.button.x&&event.button.x<1270&&265<event.button.y&&event.button.y<370)
                        {
                            break;
                        }

                         else if (830<event.button.x&&event.button.x<1270&&407<event.button.y&&event.button.y<520)
                        {
                            goto end;
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
            }

            else if (m==3) SDL_Delay(100);

            color[v] = c;
            SDL_Surface* colormap=maps[v][c-1];
            SDL_BlitSurface(colormap,NULL,SDL_GetWindowSurface(Window),&position4);
            SDL_UpdateWindowSurface(Window);


            /* recur to assign colors to rest of the vertices */
            if (graphColoringUtil (graph, m, color, v+1,Window,maps) == true)
                return true;

            /* If assigning color c doesn't lead to a solution
            then remove it */

            if (m==4)
            {
            SDL_Event event;
            while (SDL_WaitEvent(&event) ) // attente de clic sur SUIVANT
            {
                if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
                {

                        if (830<event.button.x&&event.button.x<1270&&265<event.button.y&&event.button.y<370)
                        {
                            break;
                        }

                         else if (830<event.button.x&&event.button.x<1270&&407<event.button.y&&event.button.y<520)
                        {
                            goto end;
                        }

                }
            }
            }


            color[v] = 0;

            SDL_Surface* colormapBLANK=maps[v][4];
            SDL_BlitSurface(colormapBLANK,NULL,SDL_GetWindowSurface(Window),&position4);
            SDL_UpdateWindowSurface(Window);




        }
        }
    }

    /* If no color can be assigned to this vertex then return false */

    return false;
    end:;

}






void africaAlgo2AUTO(SDL_Window* Window,int colorsNbr)
{

    bool graph[48][48];
    for (int i=0; i<48; i++)
        for (int j=0; j<48; j++)
            graph[i][j]=0;

	graph[0][1]=1; graph[0][5]=1;
	graph[1][2]=1; graph[1][3]=1; graph[1][5]=1; graph[1][6]=1; graph[1][7]=1;
	graph[2][3]=1;
	graph[3][7]=1; graph[3][8]=1; graph[3][4]=1; graph[3][9]=1;
	graph[4][9]=1;
	graph[5][6]=1; graph[5][14]=1;
	graph[6][14]=1; graph[6][17]=1; graph[6][21]=1; graph[6][7]=1; graph[6][20]=1;
	graph[7][8]=1; graph[7][21]=1; graph[7][24]=1; graph[7][25]=1;
	graph[8][9]=1; graph[8][25]=1; graph[8][26]=1; graph[8][27]=1;
	graph[9][10]=1; graph[9][12]=1; graph[9][32]=1; graph[9][31]=1; graph[9][27]=1; graph[9][33]=1;
	graph[10][11]=1; graph[10][12]=1;
	graph[11][12]=1; graph[11][13]=1;
	graph[12][13]=1; graph[12][33]=1;
	graph[13][33]=1;
	graph[14][15]=1; graph[14][16]=1; graph[14][17]=1;
	graph[16][17]=1;
	graph[17][18]=1; graph[17][19]=1; graph[17][20]=1;
	graph[18][19]=1;
	graph[19][20]=1;
	graph[20][21]=1; graph[20][22]=1;
	graph[21][22]=1; graph[21][23]=1; graph[21][24]=1;
	graph[22][23]=1;
	graph[23][24]=1;
	graph[24][25]=1;
	graph[25][26]=1;
	graph[26][27]=1; graph[26][28]=1; graph[26][29]=1; graph[26][30]=1;
	graph[27][30]=1; graph[27][31]=1;
	graph[28][29]=1;
	graph[29][30]=1;
	graph[30][31]=1;
	graph[31][32]=1; graph[31][34]=1; graph[31][35]=1; graph[31][36]=1; graph[31][37]=1; graph[31][46]=1;
	graph[32][33]=1; graph[32][34]=1; graph[32][36]=1;
	graph[33][36]=1;
	graph[34][35]=1; graph[34][36]=1;
	graph[35][36]=1;
	graph[36][37]=1; graph[36][38]=1; graph[36][39]=1;
	graph[37][38]=1; graph[37][46]=1; graph[37][40]=1; graph[37][42]=1; graph[37][39]=1;
	graph[38][39]=1;
	graph[39][42]=1; graph[39][43]=1;
	graph[40][46]=1; graph[40][41]=1; graph[40][43]=1;
	graph[41][42]=1; graph[41][43]=1;
	graph[42][44]=1;
	graph[43][44]=1; graph[43][45]=1;

    for (int i=0; i<48; i++)
        for (int j=0; j<48; j++)
            if (graph[i][j]==1)
                graph[j][i]=1;

    int m=colorsNbr;
    //graphColoring (graph, m);

    int *color = new int[48];
    for (int i = 0; i < 48; i++)
    color[i] = 0;




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
    SDL_Surface* returnbutton = IMG_Load("images/return.png");
    SDL_Surface* divisemap = IMG_Load("images/divisemap.png");
    SDL_Surface* linedmapafrica = IMG_Load("images/linedmapafrica.png");
    SDL_Surface* moroccograph = IMG_Load("images/moroccograph.png");
    SDL_Surface* graphbutton = IMG_Load("images/graphbutton.png");



/*on dessine l'arriere plan*/
    SDL_BlitSurface(background,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(mapbackground,NULL,SDL_GetWindowSurface(Window),&position3);
    //SDL_BlitSurface(emptymap,NULL,SDL_GetWindowSurface(Window),&position4);
    SDL_BlitSurface(divisemap,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(returnbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(returnbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_BlitSurface(graphbutton,NULL,SDL_GetWindowSurface(Window),&position);
    SDL_UpdateWindowSurface(Window);

    // chargement des images colories pour l'afrique
    SDL_Surface* maps[48][5];
    int i=0,j=0;
    for (i=0; i<48; i++)
        for(j=0; j<5; j++)
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

                string blank="images/africa/blank";
                blank.push_back((char)(i + '0'));
                blank=blank+".png";

            const char *cgreen = green.c_str();
            const char *cred = red.c_str();
            const char *cblue = blue.c_str();
            const char *cyellow = yellow.c_str();
            const char *cblank = blank.c_str();

            if (j==0) maps[i][j]=IMG_Load(cgreen);
            else if (j==1) maps[i][j]=IMG_Load(cred);
            else if (j==2) maps[i][j]=IMG_Load(cblue);
            else if (j==3) maps[i][j]=IMG_Load(cyellow);
            else if (j==4) maps[i][j]=IMG_Load(cblank);
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

                string blank="images/africa/blank";
                blank.push_back((char)(a + '0'));
                blank.push_back((char)(b + '0'));
                blank=blank+".png";

            const char *cgreen = green.c_str();
            const char *cred = red.c_str();
            const char *cblue = blue.c_str();
            const char *cyellow = yellow.c_str();
            const char *cblank = blank.c_str();


            if (j==0) maps[i][j]=IMG_Load(cgreen);
            else if (j==1) maps[i][j]=IMG_Load(cred);
            else if (j==2) maps[i][j]=IMG_Load(cblue);
            else if (j==3) maps[i][j]=IMG_Load(cyellow);
            else if (j==4) maps[i][j]=IMG_Load(cblank);
            }
        }


    graphColoringUtil(graph, m, color, -1, Window, maps);




	// affichage de colouer lors de clic sur suivant

    for (i=0; i<48; i++)
        for(j=0; j<5; j++)
            SDL_FreeSurface(maps[i][j]);


}
