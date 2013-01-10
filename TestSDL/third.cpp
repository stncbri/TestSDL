////
////  third.cpp
////  TestSDL
////
////  Created by RamanujanB on 9/20/12.
////  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
////
//
//#include <iostream>
//#include <SDL/SDL.h>
//#include <GLUT/GLUT.h>
//#include "SDLMain.h"
////#include <>
//
//
//
//
//void drawCube(float size)
//{
//    
//    float difamb[]={1,.5,.3,1};
//    glBegin(GL_QUADS);
//    //    glColor3f(1, 0, 0);
//    
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb);
//    glNormal3f(0, 0, 1);
//    glVertex3f(size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, size/2);
//    glVertex3f(-size/2, -size/2, size/2);
//    glVertex3f(size/2, -size/2, size/2);
//    
//    //     glColor3f(0, 1, 0);
//    glNormal3f(-1, 0, 0);
//    glVertex3f(-size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, -size/2);
//    glVertex3f(-size/2, -size/2, -size/2);
//    glVertex3f(-size/2, -size/2, size/2);
//    
//    //     glColor3f(0, 0, 1);
//    glNormal3f(0, 0, -1);
//    glVertex3f(size/2, size/2, -size/2);
//    glVertex3f(-size/2, size/2, -size/2);
//    glVertex3f(-size/2, -size/2, -size/2);
//    glVertex3f(size/2, -size/2, -size/2);
//    
//    //     glColor3f(1, 1, 0);
//    glNormal3f(1, 0, 0);
//    glVertex3f(size/2, size/2, -size/2);
//    glVertex3f(size/2, size/2, size/2);
//    glVertex3f(size/2, -size/2, size/2);
//    glVertex3f(size/2, -size/2, -size/2);
//    
//    //     glColor3f(0, 1, 1);
//    glNormal3f(0, 1, 0);
//    glVertex3f(size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, -size/2);
//    glVertex3f(size/2, size/2, -size/2);
//    
//    //     glColor3f(1, 0, 1);
//    glNormal3f(0, -1, 1);
//    glVertex3f(size/2, -size/2, size/2);
//    glVertex3f(-size/2, -size/2, size/2);
//    glVertex3f(-size/2, -size/2, -size/2);
//    glVertex3f(size/2, -size/2, -size/2);
//    
//    glEnd();
//    
//}
//
//float angle=0.0;
//const int triangle=1;
//
//unsigned int loadTexture(const char * filename)
//{
//    SDL_Surface* img=SDL_LoadBMP("/Users/ramanujanb/Desktop/brick.bmp");
//    unsigned int id;
//    glGenTextures(1, &id);
//    glBindTexture(GL_TEXTURE_2D, id);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w,img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    SDL_FreeSurface(img);
//    return id;
//}
//
//unsigned int tex;
//void init()
//{
//    glClearColor(0.0, 0.0, 0.0, 1.0 );
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    float pos[]={-2,2,-3.0,0};
//    glLightfv(GL_LIGHT0, GL_POSITION, pos);
//    
//    gluPerspective(45, 640/480, 1, 500);
//    glMatrixMode(GL_MODELVIEW);
//    glEnable(GL_DEPTH_TEST); 
//    glEnable(GL_TEXTURE_2D);
//    tex=loadTexture("/Users/ramanujanb/Desktop/brick.bmp");
//    //    glEnable(GL_LIGHTING);
//    //    glEnable(GL_LIGHT0);
//    ////    glEnable(GL_COLOR_MATERIAL);
//    //    
//    //    float dif[]={1 ,1,1,1};
//    //    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
//    //    float amb[]={0.2 ,0.2,0.2,1};
//    //    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
//}
//
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glTranslatef(0.0, 0.0, -5.0);
//    glRotatef(angle, 1, 1,1);
//    glBindTexture(GL_TEXTURE_2D, tex);
//    
//    glBegin(GL_QUADS);
//    glTexCoord2f(0, 2);
//    glVertex3f(-2,2, 0);
//    glTexCoord2f(0, 0);
//    glVertex3f(-2,-2, 0);
//    glTexCoord2f(2, 0);
//    glVertex3f(2,-2, 0);
//    glTexCoord2f(2,2);
//    glVertex3f( 2,  2,0);
//    glEnd();
//    //    drawCube(1);    
//}
//
//int mainxxx(int argc,   char ** argv )
//{
//    
//    SDL_Init(SDL_INIT_EVERYTHING);
//    
//    SDL_Surface* screen ;
//    
//    screen=SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_OPENGL);
//    SDL_WM_SetCaption("testing 1,2,3,", NULL);
//    const int FPS=30;
//    UInt32 start;   
//    
//    init();
//    bool isRunning=true;
//    SDL_Event event;
//    while (isRunning) 
//    {
//        start=SDL_GetTicks();
//        
//        while (SDL_PollEvent(&event)) 
//        {
//            switch (event.type ) 
//            {
//                case  SDL_QUIT:
//                    isRunning=false;
//                    break; 
//                    
//            }
//            
//        }
//        display();
//        angle+=0.5;
//        if (angle>360) {
//            angle-=360;
//        }
//        
//        SDL_GL_SwapBuffers();
//        
//        if(1000/FPS>SDL_GetTicks() -start )
//            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
//    }
//    SDL_Quit();
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
//
