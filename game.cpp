//
//  game.cpp
//  TestSDL
//
//  Created by RamanujanB on 10/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
 
#include "game.h"


game::game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);  
	glClearColor(0.5,0.5,0.5,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);   
	initskybox(); 
    
}

game::~game(){
    SDL_Quit();
	killskybox();
}

void game::start(){
    
    Uint32 start;
	SDL_Event event;
    bool running=true; 
	while(running)
	{
		start=SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running=false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					cam.mouseIn(true);
					SDL_ShowCursor(SDL_DISABLE);
					break;
				case SDL_KEYDOWN: 
					if(event.key.keysym.sym==SDLK_ESCAPE)
					{
						running=false;
						break;
					}     
			}
		}
        
        update();
        show();
        SDL_GL_SwapBuffers();
        if(1000/30>(SDL_GetTicks()-start))
        SDL_Delay(1000/30-(SDL_GetTicks()-start));
	}

}


void game::update(){
   
     
}

void game::show(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    cam.Control( );
    drawSkybox(50.0);
    cam.UpdateCamera();
    }