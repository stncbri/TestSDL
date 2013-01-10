#ifndef COLLISIONPLANE_H
#define COLLISIONPLANE_H
#include "vector3d.h"

class collisionplane{
	public:
		vector3d p[4];
		vector3d normal;
		collisionplane(float n1,float n2,float n3, //normal vector
		               float a,float b,float c, // cood1
		               float d,float e,float f,// cood2
		               float g,float h,float i,// cood3
		               float j,float k,float l);// cood4
};

#endif
