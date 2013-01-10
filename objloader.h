#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <GLUT/GLUT.h> 
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cmath>
#include "vector3d.h"
#include "collisionplane.h"
#ifndef OBJLOADER_H
#define OBJLOADER_H

#ifndef GL_UNSIGNED_SHORT_5_6_5
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#endif
#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif


 

struct face{
	int facenum;
	bool four;
	int faces[4];
	int texcoord[4];
	int mat;
	face(int facen,int f1,int f2,int f3,int t1,int t2,int t3,int m);
	face(int facen,int f1,int f2,int f3,int f4,int t1,int t2,int t3,int t4,int m);
};

struct material{
	std::string name;
	float alpha,ns,ni;
	float dif[3],amb[3],spec[3];
	int illum;
	int texture;
	material(const char* na,float al,float n,float ni2,float* d,float* a,float* s,int i,int t);
};

struct texcoord{
	float u,v;
	texcoord(float a,float b);
};

class objloader{
	std::vector<std::string*> coord;
	std::vector<vector3d*> vertex;
	std::vector<face*> faces;
	std::vector<vector3d*> normals;
	std::vector<unsigned int> texture;
	std::vector<unsigned int> lists;
	std::vector<material*> materials;
	std::vector<texcoord*> texturevector3d;
	std::vector<vector3d*> vertexnormals;
	bool ismaterial,isnormals,istexture,isvertexnormal;
	unsigned int loadTexture(const char* filename);
	void clean();
	void smoothnormals();
	public:
	objloader();
	~objloader();
	int load(std::string,std::vector<collisionplane>* collplane=NULL);
};

#endif
