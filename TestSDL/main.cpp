////
////  main.cpp
////  TestSDL
////
////  Created by RamanujanB on 9/18/12.
////  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
////
//
//#include <SDL/SDL.h>  
//#include <GLUT/GLUT.h> 
//#include "SDLMain.h"
//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <fstream>
//#include <cstdio>
//#include "objectLoader.h"
//#include "function.h"
//  
//
//
//
//float angle=0.0;
//
//int cube;
//objloader obj;
//bool mousein=false;
//coordinate spherecenter(0.0,0.0,0.0);
//coordinate raystart(0.0,0.0,0.0);
//
//std::vector<unsigned int> frames;
//int curframe=0;
//void init()
//{
//	glClearColor(0.5,0.5,0.5,1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45,640.0/480.0,1.0,500.0);
//	glMatrixMode(GL_MODELVIEW);
//	glEnable(GL_DEPTH_TEST);
//	cube=obj.load("/Users/ramanujanb/ios_proj/learning/test/TestSDL/CarlosOBJ.obj");
//    //	cube=loadObject("t/Users/ramanujanb/ios_proj/learning/test/TestSDL/monkey.obj");
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	float col[]={1.0,1.0,1.0,1.0};
//	glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
//	initskybox();
////    loadAnimation(frames,"/Users/ramanujanb/c++/proj/3d/anim/untitled",30,obj);
//}
//
//coordinate p1(-5.0,5.0,-5.0);
//coordinate p2(5.0,5.0,-5.0);
//coordinate p3(5.0,-5.0,-5.0);
//coordinate p4(-5.0,-5.0,-5.0);
//
//coordinate p5(-10.0,0,-10.0);
//coordinate p6(-10.0,-5.0,10.0);
//coordinate p7(10.0,-5.0,10.0);
//coordinate p8(10.0,0,-10.0);
///*
// 
// */
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    Control(0.2,0.2,mousein);
//    drawSkybox(50.0);
//    UpdateCamera();
//    float pos[]={-1.0,1.0,-2.0,1.0};
//    glLightfv(GL_LIGHT0,GL_POSITION,pos);
//    //      glTranslatef(0.0,0.0,-4.0);
//    //      glRotatef(angle,1,1,1);
//    glDisable(GL_LIGHTING);
//    //      if(raysphere(spherecenter.x,spherecenter.y,spherecenter.z,0.0,0.0,1.0,raystart.x, raystart.y,raystart.z,1.0))
//    if(rayplane(0.0,0.0,1.0,raystart.x,raystart.y,raystart.z,0.0,0.0,-1.0,p1,p2,p3,p4))
//        glColor3f(1.0,0.0,0.0);
//    else
//        glColor3f(1.0,1.0,1.0);
//    //xs+t*xd
//    glBegin(GL_LINES);
//    glVertex3f(raystart.x,raystart.y,raystart.z);
//    glVertex3f(raystart.x+100*0,raystart.y+100*0,raystart.z+100*-1);
//    glEnd();
//    glBegin(GL_QUADS);
//    glVertex3f(-5.0,5.0,-5.0);
//    glVertex3f(5.0,5.0,-5.0);
//    glVertex3f(5.0,-5.0,-5.0);
//    glVertex3f(-5.0,-5.0,-5.0);
//    glColor3f(0,0,0);
//    glVertex3f(-10.0,0.0,-10.0);
//    glVertex3f(-10.0,-5.0,10.0);
//    glVertex3f(10.0,-5.0,10.0);
//    glVertex3f(10.0,0.0,-10.0);
//    glEnd();
//    glEnable(GL_LIGHTING);
//    glCallList(cube);
//    //      tex->drawText(coordinate(10,0,0),coordinate(angle,0,0),"HELLO\nWORLD\nFROM\nOPENGL");
//    
////    glTranslatef(-20,0,0);
////    glCallList(frames[curframe]);
////    curframe++;
////    if(curframe>30)
////        curframe=0;
////    std::cout << curframe << std::endl;
//    
//    glColor3f(1.0,1.0,1.0);
//}
//
//
//int main(int argc,   char ** argv)
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);
//	bool running=true;
//	Uint32 start;
//	SDL_Event event;
//	init();
//	bool b[4]={0,0,0,0};
//	while(running)
//	{
//		start=SDL_GetTicks();
//		while(SDL_PollEvent(&event))
//		{
//			switch(event.type)
//			{
//				case SDL_QUIT:
//					running=false;
//					break;
//				case SDL_MOUSEBUTTONDOWN:
//					mousein=true;
//					SDL_ShowCursor(SDL_DISABLE);
//					break;
//				case SDL_KEYDOWN:
//					if(event.key.keysym.sym==SDLK_p)
//					{
//						mousein=false;
//						SDL_ShowCursor(SDL_ENABLE);
//						break;
//					}
//					if(event.key.keysym.sym==SDLK_ESCAPE)
//					{
//						running=false;
//						break;
//					}	
//					switch(event.key.keysym.sym)
//                {
//                    case SDLK_UP:
//                        b[0]=1;
//                        break;
//                        
//                    case SDLK_LEFT:
//                        b[1]=1;
//                        break;
//                        
//                    case SDLK_DOWN:
//                        b[2]=1;
//                        break;
//                        
//                    case SDLK_RIGHT:
//                        b[3]=1;
//                        break;
//                    default:
//                        break;
//                }
//					break;				
//				case SDL_KEYUP:
//					switch(event.key.keysym.sym)
//                {
//                    case SDLK_UP:
//                        b[0]=0;
//                        break;
//                        
//                    case SDLK_LEFT:
//                        b[1]=0;
//                        break;
//                        
//                    case SDLK_DOWN:
//                        b[2]=0;
//                        break;
//                        
//                    case SDLK_RIGHT:
//                        b[3]=0;
//                        break;
//                    default:
//                        break;
//                }
//					break;						
//			}
//		}
//		if(b[0])
//			raystart.y+=0.3;
//		if(b[1])
//			raystart.x-=0.3;
//		if(b[2])
//			raystart.y-=0.3;
//		if(b[3])
//			raystart.x+=0.3;
//		display();
//		SDL_GL_SwapBuffers();
//        
//        coordinate cameraPos=camPos();
//        if(spheresphere(cameraPos,2.0,coordinate(0,0,0),1.0))
//            std::cout << "collision\n";
//        sphereplane(cameraPos,coordinate(0,0,1),p1,p2,p3,p4,2.0);
//        sphereplane(cameraPos,coordinate(0,0.9701425,0.242535625),p5,p6,p7,p8,2.0);
//        moveTo(cameraPos);
//        
//		angle+=0.5;
//		if(angle>360)
//			angle-=360;
//		if(1000/30>(SDL_GetTicks()-start))
//			SDL_Delay(1000/30-(SDL_GetTicks()-start));
//	}
//	SDL_Quit();
//	killskybox();
//	return 0;	
//}




//*********

//#include <SDL/SDL.h>  
//#include <GLUT/GLUT.h> 
//#include "SDLMain.h"
//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <fstream>
//#include <cstdio>
//#include "objloader.h"
//#include "collision.h"
//#include "camera.h"
//#include "functions.h"
//
//camera cam;
//std::vector<std::vector<float> > heights;
//
//float angle=0.0;
//
//int cube;
//objloader obj; 
//vector3d spherecenter(0.0,0.0,0.0);
//vector3d raystart(0.0,0.0,0.0);
//
//std::vector<unsigned int> frames;
//int curframe=0;
//
//
//void renderHeightmap(float size,float h)
//{
//	for(int i=0;i<heights.size()-1;i++)
//		for(int j=0;j<heights[0].size()-1;j++)
//		{
//			glBegin(GL_TRIANGLE_STRIP);
//            glColor3f(heights[i][j],heights[i][j],heights[i][j]);
//            glVertex3f(i*size,heights[i][j]*h,j*size);
//            glVertex3f((i+1)*size,heights[i+1][j]*h,j*size);
//            glVertex3f(i*size,heights[i][j+1]*h,(j+1)*size);
//            glVertex3f((i+1)*size,heights[i+1][j+1]*h,(j+1)*size);
//			glEnd();
//		}
//}
//
//std::vector<collisionplane> collplane;
//
//void init()
//{
//    cam.setLocation(vector3d(10,10,10));
//	glClearColor(0.5,0.5,0.5,1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45,640.0/480.0,1.0,500.0);
//	glMatrixMode(GL_MODELVIEW);
//	glEnable(GL_DEPTH_TEST);
//	cube=obj.load("/Users/ramanujanb/ios_proj/learning/test/TestSDL/untitled.obj" ,&collplane);
//    for (int i=0; i<collplane.size(); i++) {
//        std::cout <<  collplane[i].p[0]<<  collplane[i].p[1]<<  collplane[i].p[2]<<  collplane[i].p[3]<<std::endl;
//    } 
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	float col[]={1.0,1.0,1.0,1.0};
//	glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
//	initskybox();
//    //    loadAnimation(frames,"/Users/ramanujanb/c++/proj/3d/anim/untitled",30,obj);
//}
//
//vector3d p1(-5.0,5.0,-5.0);
//vector3d p2(5.0,5.0,-5.0);
//vector3d p3(5.0,-5.0,-5.0);
//vector3d p4(-5.0,-5.0,-5.0);
//
//vector3d p5(-10.0,0,-10.0);
//vector3d p6(-10.0,-5.0,10.0);
//vector3d p7(10.0,-5.0,10.0);
//vector3d p8(10.0,0,-10.0);
///*
// 
// */
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    
//    cam.Control();//Control(0.2,0.2,mousein);
//    drawSkybox(50.0);
//    cam.UpdateCamera() ;
//    float pos[]={-1.0,1.0,6.0,1.0};
//    glLightfv(GL_LIGHT0,GL_POSITION,pos);
//    
//    glDisable(GL_LIGHTING);
//    //      if(raysphere(spherecenter.x,spherecenter.y,spherecenter.z,0.0,0.0,1.0,raystart.x, raystart.y,raystart.z,1.0))
//    
//    if(collision::rayplane(0.0,0.0,1.0,p1.x,p1.y,p1.z,raystart.x,raystart.y,raystart.z,0.0,0.0,-1.0,p1,p2,p3,p4))
//        glColor3f(1.0,0.0,0.0);
//    else
//        glColor3f(1.0,1.0,1.0);
//    
//    glEnable(GL_LIGHTING);
//    glCallList(cube); 
//    
//    glColor3f(1.0,1.0,1.0);
//}
//
//
//int main(int argc,   char ** argv)
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);
//	bool running=true;
//	Uint32 start;
//	SDL_Event event;
//    
//	init();
//	bool b[4]={0,0,0,0};
//	while(running)
//	{
//		start=SDL_GetTicks();
//		while(SDL_PollEvent(&event))
//		{
//			switch(event.type)
//			{
//				case SDL_QUIT:
//					running=false;
//					break;
//				case SDL_MOUSEBUTTONDOWN:
//					cam.mouseIn(true);
//					SDL_ShowCursor(SDL_DISABLE);
//					break;
//				case SDL_KEYDOWN:
//					if(event.key.keysym.sym==SDLK_p)
//					{
//						cam.mouseIn(false);
//						SDL_ShowCursor(SDL_ENABLE);
//						break;
//					}
//					if(event.key.keysym.sym==SDLK_ESCAPE)
//					{
//						running=false;
//						break;
//					}	
//					switch(event.key.keysym.sym)
//                {
//                    case SDLK_UP:
//                        b[0]=1;
//                        break;
//                        
//                    case SDLK_LEFT:
//                        b[1]=1;
//                        break;
//                        
//                    case SDLK_DOWN:
//                        b[2]=1;
//                        break;
//                        
//                    case SDLK_RIGHT:
//                        b[3]=1;
//                        break;
//                    default:
//                        break;
//                }
//					break;				
//				case SDL_KEYUP:
//					switch(event.key.keysym.sym)
//                {
//                    case SDLK_UP:
//                        b[0]=0;
//                        break;
//                        
//                    case SDLK_LEFT:
//                        b[1]=0;
//                        break;
//                        
//                    case SDLK_DOWN:
//                        b[2]=0;
//                        break;
//                        
//                    case SDLK_RIGHT:
//                        b[3]=0;
//                        break;
//                    default:
//                        break;
//                }
//					break;						
//			}
//		}
//		if(b[0])
//			raystart.y+=0.3;
//		if(b[1])
//			raystart.x-=0.3;
//		if(b[2])
//			raystart.y-=0.3;
//		if(b[3])
//			raystart.x+=0.3;
//		display();
//		SDL_GL_SwapBuffers();
//        
//        vector3d cameraPos=cam.getLocation();
//        if(collision::spheresphere(cameraPos,2.0,vector3d(0,0,0),1.0))
//            std::cout << "collision\n";
//        collision::sphereplane(cameraPos,vector3d(0,0,1),p1,p2,p3,p4,2.0);
//        collision::sphereplane(cameraPos,vector3d(0,0.9701425,0.242535625),p5,p6,p7,p8,2.0);
//        cam.setLocation(cameraPos );
//        
//		angle+=0.5;
//		if(angle>360)
//			angle-=360;
//		if(1000/30>(SDL_GetTicks()-start))
//			SDL_Delay(1000/30-(SDL_GetTicks()-start));
//	}
//	SDL_Quit();
//	killskybox();
//	return 0;	
//}
//
//
//void loadHeightmap(const char* name)
//{
//	SDL_Surface* img=SDL_LoadBMP(name);
//	if(!img)
//	{
//		std::cout << "image is not loaded" << std::endl;
//		return;
//	}
//	std::vector<float> tmp;
//	for(int i=0;i<img->h;i++)
//	{
//		tmp.clear();
//		for(int j=0;j<img->w;j++)
//		{
//			Uint32 pixel=((Uint32*)img->pixels)[i*img->pitch/4 + j];
//			Uint8 r,g,b;	//unsigned char
//			SDL_GetRGB(pixel,img->format,&r,&g,&b);
//			tmp.push_back((float)r/255.0);	//0.0,1.0
//		}
//		heights.push_back(tmp);
//	}
//}



//#include <iostream>
//#include <SDL/SDL.h>
//#include <GLUT/GLUT.h> 
//#include "camera.h"
//#include "functions.h"
//#include <vector>
//
//camera cam;
//std::vector<std::vector<float> > heights;
//
//void loadHeightmap(const char* name)
//{
//	SDL_Surface* img=SDL_LoadBMP(name);
//	if(!img)
//	{
//		std::cout << "image is not loaded" << std::endl;
//		return;
//	}
//	std::vector<float> tmp;
//	for(int i=0;i<img->h;i++)
//	{
//		tmp.clear();
//		for(int j=0;j<img->w;j++)
//		{
//			Uint32 pixel=((Uint32*)img->pixels)[i*img->pitch/4 + j];
//			Uint8 r,g,b;	//unsigned char
//			SDL_GetRGB(pixel,img->format,&r,&g,&b);
//			tmp.push_back((float)r/255.0);	//0.0,1.0
//		}
//		heights.push_back(tmp);
//	}
//}
//
//void renderHeightmap(float size,float h)
//{
//	for(int i=0;i<heights.size()-1;i++)
//		for(int j=0;j<heights[0].size()-1;j++)
//		{
//			glBegin(GL_TRIANGLE_STRIP);
//				glColor3f(heights[i][j],heights[i][j],heights[i][j]);
//				glVertex3f(i*size,heights[i][j]*h,j*size);
//				glVertex3f((i+1)*size,heights[i+1][j]*h,j*size);
//				glVertex3f(i*size,heights[i][j+1]*h,(j+1)*size);
//				glVertex3f((i+1)*size,heights[i+1][j+1]*h,(j+1)*size);
//			glEnd();
//		}
//}
//
//void init(float angle)
//{
//	glClearColor(0,0,0,1);
//	glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluPerspective(angle,640.0/480.0,1,1000);
//	glMatrixMode(GL_MODELVIEW);
//	initskybox();
//	glEnable(GL_DEPTH_TEST);
//	loadHeightmap("/Users/ramanujanb/ios_proj/learning/test/TestSDL/heightmap.bmp");
//}
//
//void display()
//{
//	glLoadIdentity();
//	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//	cam.Control();
//	drawSkybox(50);
//	
//	cam.UpdateCamera();
//	renderHeightmap(0.01,0.4);
//	
//}
//
//int   main(int argc,   char ** argv)
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_SetVideoMode(640,480,32,SDL_OPENGL);
//	Uint32 start;
//	SDL_Event event;
//	bool running=true;
//	float angle=50;
//	init(angle); 
//	while(running)
//	{
//		start=SDL_GetTicks();
//		while(SDL_PollEvent(&event))
//		{
//			switch(event.type)
//			{
//				case SDL_QUIT:
//					running=false;
//					break;
//				case SDL_KEYDOWN:
//					switch(event.key.keysym.sym)
//					{
//						case SDLK_ESCAPE:
//							running=false;
//							break;
//                         default:
//                            break;
//					}
//					break;
//				case SDL_MOUSEBUTTONDOWN:
//					cam.mouseIn(true);
//					break;
//					
//			}
//		}
//		display();
//		SDL_GL_SwapBuffers();
//		if(1000.0/30>SDL_GetTicks()-start)
//			SDL_Delay(1000.0/30-(SDL_GetTicks()-start));
//	}
//	killskybox();
//	SDL_Quit();
//    return 0;
//}

