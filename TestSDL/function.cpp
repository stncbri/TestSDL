////
////  function.cpp
////  TestSDL
////
////  Created by RamanujanB on 9/25/12.
////  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
////
//
//#include <iostream>
//#include "function.h"
// 
// 
//float camX=0.0,camY=0.0,camZ=5.0;	//current position of the camera
//float camYaw=0.0;	//camera rotation in Y axis
//float camPitch=0.0;	//camera rotation in X axis
//enum {SKY_LEFT=0,SKY_BACK,SKY_RIGHT,SKY_FRONT,SKY_TOP,SKY_BOTTOM};      //constants for the skybox faces, so we don't have to remember so much number
//unsigned int skybox[6]; //the ids for the textures
//
//
//
//#ifndef M_PI	//if the pi is not defined in the cmath header file
//#define M_PI 3.1415926535	//define it
//#endif
//
//
//
//unsigned int loadTexture(const char* filename)  //load the filename named texture
//{
//    unsigned int num;       //the id for the texture
//    glGenTextures(1,&num);  //we generate a unique one
//    SDL_Surface* img=SDL_LoadBMP(filename); //load the bmp image
//    glBindTexture(GL_TEXTURE_2D,num);       //and use the texture, we have just generated
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //same if the image bigger
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);      //we repeat the pixels in the edge of the texture, it will hide that 1px wide line at the edge of the cube, which you have seen in the video
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);      //we do it for vertically and horizontally (previous line)
//    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);        //we make the actual texture
//    SDL_FreeSurface(img);   //we delete the image, we don't need it anymore
//    return num;     //and we return the id
//} 
//
//void initskybox()
//{
//    skybox[SKY_LEFT]=loadTexture("/Users/ramanujanb/ios_proj/learning/test/TestSDL/left.bmp");
//    skybox[SKY_BACK]=loadTexture("/Users/ramanujanb/ios_proj/learning/test/TestSDL/back.bmp");
//    skybox[SKY_RIGHT]=loadTexture("/Users/ramanujanb/ios_proj/learning/test/TestSDL/right.bmp");
//    skybox[SKY_FRONT]=loadTexture("/Users/ramanujanb/ios_proj/learning/test/TestSDL/front.bmp");
//    skybox[SKY_TOP]=loadTexture("/Users/ramanujanb/ios_proj/learning/test/TestSDL/top.bmp");
//    skybox[SKY_BOTTOM]=loadTexture("/Users/ramanujanb/ios_proj/learning/test/TestSDL/bottom.bmp");
//}
//
//void killskybox()
//{
//    glDeleteTextures(6,&skybox[0]);
//}
//
//
//void drawSkybox(float size)
//{
//    bool b1=glIsEnabled(GL_TEXTURE_2D);     //new, we left the textures turned on, if it was turned on
//    glDisable(GL_LIGHTING); //turn off lighting, when making the skybox
//    glDisable(GL_DEPTH_TEST);       //turn off depth texting
//    glEnable(GL_TEXTURE_2D);        //and turn on texturing
//    glBindTexture(GL_TEXTURE_2D,skybox[SKY_BACK]);  //use the texture we want
//    glBegin(GL_QUADS);      //and draw a face
//    //back face
//    glTexCoord2f(0,0);      //use the correct texture coordinate
//    glVertex3f(size/2,size/2,size/2);       //and a vertex
//    glTexCoord2f(1,0);      //and repeat it...
//    glVertex3f(-size/2,size/2,size/2);
//    glTexCoord2f(1,1);
//    glVertex3f(-size/2,-size/2,size/2);
//    glTexCoord2f(0,1);
//    glVertex3f(size/2,-size/2,size/2);
//    glEnd();
//    glBindTexture(GL_TEXTURE_2D,skybox[SKY_LEFT]);
//    glBegin(GL_QUADS);     
//    //left face
//    glTexCoord2f(0,0);
//    glVertex3f(-size/2,size/2,size/2);
//    glTexCoord2f(1,0);
//    glVertex3f(-size/2,size/2,-size/2);
//    glTexCoord2f(1,1);
//    glVertex3f(-size/2,-size/2,-size/2);
//    glTexCoord2f(0,1);
//    glVertex3f(-size/2,-size/2,size/2);
//    glEnd();
//    glBindTexture(GL_TEXTURE_2D,skybox[SKY_FRONT]);
//    glBegin(GL_QUADS);     
//    //front face
//    glTexCoord2f(1,0);
//    glVertex3f(size/2,size/2,-size/2);
//    glTexCoord2f(0,0);
//    glVertex3f(-size/2,size/2,-size/2);
//    glTexCoord2f(0,1);
//    glVertex3f(-size/2,-size/2,-size/2);
//    glTexCoord2f(1,1);
//    glVertex3f(size/2,-size/2,-size/2);
//    glEnd();
//    glBindTexture(GL_TEXTURE_2D,skybox[SKY_RIGHT]);
//    glBegin(GL_QUADS);     
//    //right face
//    glTexCoord2f(0,0);
//    glVertex3f(size/2,size/2,-size/2);
//    glTexCoord2f(1,0);
//    glVertex3f(size/2,size/2,size/2);
//    glTexCoord2f(1,1);
//    glVertex3f(size/2,-size/2,size/2);
//    glTexCoord2f(0,1);
//    glVertex3f(size/2,-size/2,-size/2);
//    glEnd();
//    glBindTexture(GL_TEXTURE_2D,skybox[SKY_TOP]);          
//    glBegin(GL_QUADS);                      //top face
//    glTexCoord2f(1,0);
//    glVertex3f(size/2,size/2,size/2);
//    glTexCoord2f(0,0);
//    glVertex3f(-size/2,size/2,size/2);
//    glTexCoord2f(0,1);
//    glVertex3f(-size/2,size/2,-size/2);
//    glTexCoord2f(1,1);
//    glVertex3f(size/2,size/2,-size/2);
//    glEnd();
//    glBindTexture(GL_TEXTURE_2D,skybox[SKY_BOTTOM]);               
//    glBegin(GL_QUADS);     
//    //bottom face
//    glTexCoord2f(1,1);
//    glVertex3f(size/2,-size/2,size/2);
//    glTexCoord2f(0,1);
//    glVertex3f(-size/2,-size/2,size/2);
//    glTexCoord2f(0,0);
//    glVertex3f(-size/2,-size/2,-size/2);
//    glTexCoord2f(1,0);
//    glVertex3f(size/2,-size/2,-size/2);
//    glEnd();
//    glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
//    glEnable(GL_DEPTH_TEST);
//    if(!b1)
//        glDisable(GL_TEXTURE_2D);
//}
//
//
//
//void lockCamera()
//{
//	//set campitch between -90 and 90 and set camyaw between 0 and 360 degrees
//	if(camPitch>90)
//		camPitch=90;
//	if(camPitch<-90)
//		camPitch=-90;
//	if(camYaw<0.0)
//		camYaw+=360.0;
//	if(camYaw>360.0)
//		camYaw-=360;
//}
//
//void moveCamera(float dist,float dir)
//{
//	float rad=(camYaw+dir)*M_PI/180.0;	//convert the degrees into radians
//	camX-=sin(rad)*dist;	//calculate the new coorinate, if you don't understand, draw a right triangle with the datas, you have
//	camZ-=cos(rad)*dist;	//and try to calculate the new coorinate with trigonometric functions, that should help
//}
//
//void moveCameraUp(float dist,float dir)
//{
//	//the the same, only this time we calculate the y coorinate
//	float rad=(camPitch+dir)*M_PI/180.0;
//	camY+=sin(rad)*dist;	
//}
//
//void Control(float movevel,float mousevel,bool mi)	//move and mouse sensitivity, and is the mouse inside the window?
//{
//	if(mi)	//if the mouse is in the screen
//	{
//		int MidX=320;	//middle of the screen
//		int MidY=240;
//		SDL_ShowCursor(SDL_DISABLE);	//we don't show the cursor
//		int tmpx,tmpy;
//		SDL_GetMouseState(&tmpx,&tmpy);	//get the current position of the cursor
//		camYaw+=mousevel*(MidX-tmpx);	//get the rotation, for example, if the mouse current position is 315, than 5*0.2, this is for Y
//		camPitch+=mousevel*(MidY-tmpy);	//this is for X
//		lockCamera();
//		SDL_WarpMouse(MidX,MidY);	//move back the cursor to the center of the screen
//		Uint8* state=SDL_GetKeyState(NULL);	//which key is pressed?
//		if(state[SDLK_w])
//		{
//			if(camPitch!=90 && camPitch!=-90)	//if we are facing directly  
//				moveCamera(movevel,0.0);	//move forward
//			moveCameraUp(movevel,0.0);	//move up/down
//		}else if(state[SDLK_s])
//		{
//			//same, just we use 180 degrees, so we move at the different direction (move back)
//			if(camPitch!=90 && camPitch!=-90)
//				moveCamera(movevel,180.0);
//			moveCameraUp(movevel,180.0);
//		}		
//		if(state[SDLK_a])	//move left
//			moveCamera(movevel,90.0);
//		else if(state[SDLK_d])	//move right
//			moveCamera(movevel,270);	
//	}
//	glRotatef(-camPitch,1.0,0.0,0.0);	//rotate the camera (more precisly move everything in the opposit direction)
//	glRotatef(-camYaw,0.0,1.0,0.0);
//}
//
//void UpdateCamera()
//{
//	glTranslatef(-camX,-camY,-camZ);	//move the camera
//}
//
//
//
//
//float trianglearea(coordinate p1,coordinate p2,coordinate p3)
//{
//    //area of the triangle with the heron fomula
//    float a=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
//    float b=sqrt((p3.x-p2.x)*(p3.x-p2.x)+(p3.y-p2.y)*(p3.y-p2.y)+(p3.z-p2.z)*(p3.z-p2.z));
//    float c=sqrt((p1.x-p3.x)*(p1.x-p3.x)+(p1.y-p3.y)*(p1.y-p3.y)+(p1.z-p3.z)*(p1.z-p3.z));
//    float s=(a+b+c)/2.;
//    return (sqrt(s*((s-a)*(s-b)*(s-c))));
//    
//}
//
//
//
//
////draw a cube, not related to the 3D camera
//void drawCube(float size)
//{
//	float difamb[]={1.0,0.5,0.3,1.0};
//	glBegin(GL_QUADS);
//    //front face
//    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
//    glNormal3f(0.0,0.0,1.0);
//    glVertex3f(size/2,size/2,size/2);
//    glVertex3f(-size/2,size/2,size/2);
//    glVertex3f(-size/2,-size/2,size/2);
//    glVertex3f(size/2,-size/2,size/2);
//    
//    //left face
//    glNormal3f(-1.0,0.0,0.0);
//    glVertex3f(-size/2,size/2,size/2);
//    glVertex3f(-size/2,size/2,-size/2);
//    glVertex3f(-size/2,-size/2,-size/2);
//    glVertex3f(-size/2,-size/2,size/2);
//    
//    //back face
//    glNormal3f(0.0,0.0,-1.0);
//    glVertex3f(size/2,size/2,-size/2);
//    glVertex3f(-size/2,size/2,-size/2);
//    glVertex3f(-size/2,-size/2,-size/2);
//    glVertex3f(size/2,-size/2,-size/2);
//    
//    //right face
//    glNormal3f(1.0,0.0,0.0);
//    glVertex3f(size/2,size/2,-size/2);
//    glVertex3f(size/2,size/2,size/2);
//    glVertex3f(size/2,-size/2,size/2);
//    glVertex3f(size/2,-size/2,-size/2);
//    
//    //top face
//    glNormal3f(0.0,1.0,0.0);
//    glVertex3f(size/2,size/2,size/2);
//    glVertex3f(-size/2,size/2,size/2);
//    glVertex3f(-size/2,size/2,-size/2);
//    glVertex3f(size/2,size/2,-size/2);
//    
//    //bottom face
//    glNormal3f(0.0,-1.0,0.0);
//    glVertex3f(size/2,-size/2,size/2);
//    glVertex3f(-size/2,-size/2,size/2);
//    glVertex3f(-size/2,-size/2,-size/2);
//    glVertex3f(size/2,-size/2,-size/2);
//	glEnd();
//}
//
//
//bool sphereplane(coordinate& sp, coordinate vn,coordinate p1,coordinate p2,coordinate p3, coordinate p4,float r)
//{
//    //float nx,float ny,float nz,float xs,float ys,float zs,float xd,float yd,float zd,coordinate p1,coordinate p2,coordinate p3,coordinate p4,float* dist,coordinate* point)
//    float dist1=0,dist2=0;
//    if(rayplane(-vn.x,-vn.y,-vn.z,sp.x,sp.y,sp.z,vn.x,vn.y,vn.z,p1,p2,p3,p4,&dist1) || rayplane(vn.x,vn.y,vn.z,sp.x,sp.y,sp.z,-vn.x,-vn.y,-vn.z,p1,p2,p3,p4,&dist2))
//    {
//        if(dist1>r || dist2>r)
//            return false;
//        if(dist1>0)
//        {
//            sp.x=sp.x-vn.x*(r-dist1);
//            sp.y=sp.y-vn.y*(r-dist1);
//            sp.z=sp.z-vn.z*(r-dist1);
//        }else{
//            sp.x=sp.x+vn.x*(r-dist2);
//            sp.y=sp.y+vn.y*(r-dist2);
//            sp.z=sp.z+vn.z*(r-dist2);              
//        }
//        return 1;
//    }
//    return 0;
//}
//
//bool spheresphere(coordinate& c1,float r1,coordinate c2,float r2)
//{
//    float dist=pointdistance(c1,c2);
//    if(dist<=(r1+r2)*(r1+r2))
//    {
//        float a=sqrt(dist)-(r1+r2);
//        coordinate vec(c2.x-c1.x,c2.y-c1.y,c2.z-c1.z);  //c2-c1
//        float len=sqrt((vec.x*vec.x+vec.y*vec.y+vec.z*vec.z));
//        vec.x/=len;
//        vec.y/=len;
//        vec.z/=len;
//        c1.x=c1.x+vec.x*a;
//        c1.y=c1.y+vec.y*a;
//        c1.z=c1.z+vec.z*a;
//        return 1;
//    }
//    return 0;
//}
//
//
//
//
//bool raysphere(float xc,float yc, float zc,float xd,float yd, float zd,float xs,float ys, float zs,float r,float* dist,coordinate* point)
//{
//    float b=2*(xd*(xs-xc)+yd*(ys-yc)+zd*(zs-zc));
//    float c=xs*xs-2*xs*xc+xc*xc+ys*ys-2*ys*yc+yc*yc+zs*zs-2*zs*zc+zc*zc-r*r;
//    float disc=(b*b-4*c);
//    if(disc<0)
//        return false;
//    if(dist!=NULL)
//    {
//        //-b+disc/2
//        (*dist)=(-b+disc)/2;
//        if(point!=NULL)
//        {
//            //xs+t*xd
//            point->x=xs+(*dist)*xd;
//            point->y=ys+(*dist)*yd;
//            point->z=zs+(*dist)*zd;
//        }
//    }
//    return true;
//    //(x+y)^2=x^2+2xy+y^2
//}
//
//bool rayplane(float nx,float ny,float nz,float xs,float ys,float zs,float xd,float yd,float zd,coordinate p1,coordinate p2,coordinate p3,coordinate p4,float* dist,coordinate* point)
//{
//    float a=xd*nx+yd*ny+zd*nz;
//    if(a==0)
//        return false;
//    float t=((p1.x*nx+p1.y*ny+p1.z*nz-nx*xs-ny*ys-nz*zs)/a);
//    if(t<0)
//        return false;
//    float x=xs+t*xd;
//    float y=ys+t*yd;
//    float z=zs+t*zd;
//    coordinate cp(x,y,z);
//    if(abs(trianglearea(p1,p3,p4)-trianglearea(p1,p4,cp)-trianglearea(p1,p3,cp)-trianglearea(p3,p4,cp))<0.000001 || abs(trianglearea(p1,p2,p3)-trianglearea(p1,p2,cp)-trianglearea(p2,p3,cp)-trianglearea(p1,p3,cp))<0.000001)
//    {
//        if(dist!=NULL)
//        {
//            (*dist)=t;
//            if(point!=NULL)
//            {
//                point->x=x;
//                point->y=y;
//                point->z=z;
//            }
//        }
//        return true;
//    }
//    return false;
//}
//
//
//float pointdistance(coordinate c1,coordinate c2)
//{
//    coordinate vec(c2.x-c1.x,c2.y-c1.y,c2.z-c1.z);
//    return (vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
//}
//
//void moveTo(coordinate c)
//{
//    camX=c.x;
//    camY=c.y;
//    camZ=c.z;
//}
//coordinate camPos()
//{
//    return (coordinate(camX,camY,camZ));
//}
//
//
//void loadAnimation(std::vector<unsigned int>& frames,std::string filename,unsigned int num,objloader& obj)
//{
//    char tmp[200];
//    for(int i=1;i<=num;i++)
//    {
//        if(i<10)
//            sprintf(tmp,"_00000%d",i);
//        else if(i<100)
//            sprintf(tmp,"_0000%d",i);
//        else if(i<1000)
//            sprintf(tmp,"_000%d",i);
//        else if(i<10000)
//            sprintf(tmp,"_00%d",i);
//        else if(i<100000)
//            sprintf(tmp,"_0%d",i); 
//        else if(i<1000000)
//            sprintf(tmp,"_%d",i);  
//        std::string tmp2(filename+tmp);
//        tmp2+=".obj";
//        std::cout << tmp2 << std::endl;
//        unsigned int id=obj.load(tmp2);
//        frames.push_back(id);
//    }
//}
//
