//
//  game.h
//  TestSDL
//
//  Created by RamanujanB on 10/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TestSDL_game_h
#define TestSDL_game_h

#include <SDL/SDL.h>  
#include <GLUT/GLUT.h>  
#include <vector> 
#include "objloader.h" 
#include "camera.h"
#include "functions.h"
#include "collisionsphere.h"
#include "collisionplane.h"
#include "vector3d.h"



class game
{
    
    
    objloader obj;
    camera cam;
    void update();
    void show(); 
    
    
public:
    game();
    ~game();
    void start();
    
    
};


#endif
