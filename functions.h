//This example program is created by thecplusplusuy for demonstration purposes. It's a simple skybox:
//http://www.youtube.com/user/thecplusplusguy
//Free source, modify if you want, LGPL licence (I guess), I would be happy, if you would not delete the link
//so other people can see the tutorial
//this file is functions.h, it's contain the function prototypes
#include <SDL/SDL.h>
#include <GLUT/GLUT.h>
#include <SDL_image/SDL_image.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cmath>
#include "objloader.h"
#include "vector3d.h"
#ifndef FUNCTION_H
#define FUNCTION_H


 
void drawSkybox(float size);	//draw the skybox
void initskybox();	//load the textures
void killskybox();	//delete the textures
  
 
#endif
