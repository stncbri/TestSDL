//This example program is created by thecplusplusuy for demonstration purposes. It's a simple skybox:
//http://www.youtube.com/user/thecplusplusguy
//Free source, modify if you want, LGPL licence (I guess), I would be happy, if you would not delete the link
//so other people can see the tutorial
//this file is functions.cpp, it's contain the actual implementation of the skybox
#include "functions.h"

 
enum {SKY_LEFT=0,SKY_BACK,SKY_RIGHT,SKY_FRONT,SKY_TOP,SKY_BOTTOM};	//constants for the skybox faces, so we don't have to remember so much number
unsigned int skybox[6];	//the ids for the textures
#ifndef M_PI
#define M_PI 3.1415926535
#endif


unsigned int loadTexture(const char* filename)	//load the filename named texture
{ 
    SDL_Surface* img=IMG_Load(filename);
    SDL_PixelFormat form={NULL,32,4,0,0,0,0,8,8,8,8,0xff000000,0x00ff0000,0x0000ff00,0x000000ff,0,255};
    SDL_Surface* img2=SDL_ConvertSurface(img,&form,SDL_SWSURFACE);
    unsigned int texture;
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img2->w,img2->h,0,GL_RGBA, GL_UNSIGNED_INT_8_8_8_8,img2->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    SDL_FreeSurface(img);
    SDL_FreeSurface(img2);
    return texture;
}



//load all of the textures, to the skybox array
void initskybox()
{
	skybox[SKY_LEFT]=loadTexture("/Users/ramanujanb/p-ios_proj/learning/test/TestSDL/left.bmp");
	skybox[SKY_BACK]=loadTexture("/Users/ramanujanb/p-ios_proj/learning/test/TestSDL/back.bmp");
	skybox[SKY_RIGHT]=loadTexture("/Users/ramanujanb/p-ios_proj/learning/test/TestSDL/right.bmp");
	skybox[SKY_FRONT]=loadTexture("/Users/ramanujanb/p-ios_proj/learning/test/TestSDL/front.bmp");
	skybox[SKY_TOP]=loadTexture("/Users/ramanujanb/p-ios_proj/learning/test/TestSDL/top.bmp");
	skybox[SKY_BOTTOM]=loadTexture("/Users/ramanujanb/p-ios_proj/learning/test/TestSDL/bottom.bmp");
}
//delete all of the textures from the skybox array (to avoid memory leaks)
void killskybox()
{
	glDeleteTextures(6,&skybox[0]);
}

void drawSkybox(float size)
{
	bool b1=glIsEnabled(GL_TEXTURE_2D);	//new, we left the textures turned on, if it was turned on
	glDisable(GL_LIGHTING);	//turn off lighting, when making the skybox
	//glDisable(GL_DEPTH_TEST);	//turn off depth texting
	glEnable(GL_TEXTURE_2D);	//and turn on texturing
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_BACK]);	//use the texture we want
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);	//and draw a face
		//back face
		glTexCoord2f(0,0);	//use the correct texture vector3d
		glVertex3f(size/2,size/2,size/2);	//and a vertex
		glTexCoord2f(1,0);	//and repeat it...
		glVertex3f(-size/2,size/2,size/2);
		glTexCoord2f(1,1);
		glVertex3f(-size/2,-size/2,size/2);
		glTexCoord2f(0,1);
		glVertex3f(size/2,-size/2,size/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_LEFT]);
	glBegin(GL_QUADS);	
		//left face
		glTexCoord2f(0,0);
		glVertex3f(-size/2,size/2,size/2);
		glTexCoord2f(1,0);
		glVertex3f(-size/2,size/2,-size/2);
		glTexCoord2f(1,1);
		glVertex3f(-size/2,-size/2,-size/2);
		glTexCoord2f(0,1);
		glVertex3f(-size/2,-size/2,size/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_FRONT]);
	glBegin(GL_QUADS);	
		//front face
		glTexCoord2f(1,0);
		glVertex3f(size/2,size/2,-size/2);
		glTexCoord2f(0,0);
		glVertex3f(-size/2,size/2,-size/2);
		glTexCoord2f(0,1);
		glVertex3f(-size/2,-size/2,-size/2);
		glTexCoord2f(1,1);
		glVertex3f(size/2,-size/2,-size/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_RIGHT]);	
	glBegin(GL_QUADS);	
		//right face
		glTexCoord2f(0,0);
		glVertex3f(size/2,size/2,-size/2);
		glTexCoord2f(1,0);
		glVertex3f(size/2,size/2,size/2);
		glTexCoord2f(1,1);
		glVertex3f(size/2,-size/2,size/2);
		glTexCoord2f(0,1);
		glVertex3f(size/2,-size/2,-size/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_TOP]);		
	glBegin(GL_QUADS);			//top face
		glTexCoord2f(1,0);
		glVertex3f(size/2,size/2,size/2);
		glTexCoord2f(0,0);
		glVertex3f(-size/2,size/2,size/2);
		glTexCoord2f(0,1);
		glVertex3f(-size/2,size/2,-size/2);
		glTexCoord2f(1,1);
		glVertex3f(size/2,size/2,-size/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_BOTTOM]);		
	glBegin(GL_QUADS);	
		//bottom face
		glTexCoord2f(1,1);
		glVertex3f(size/2,-size/2,size/2);
		glTexCoord2f(0,1);
		glVertex3f(-size/2,-size/2,size/2);
		glTexCoord2f(0,0);
		glVertex3f(-size/2,-size/2,-size/2);
		glTexCoord2f(1,0);
		glVertex3f(size/2,-size/2,-size/2);
	glEnd();
	//glEnable(GL_LIGHTING);	//turn everything back, which we turned on, and turn everything off, which we have turned on.
	//glEnable(GL_DEPTH_TEST);
	if(!b1)
		glDisable(GL_TEXTURE_2D);
}



 

 
 	  
  
