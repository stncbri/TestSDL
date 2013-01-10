//
//  collision.h
//  TestSDL
//
//  Created by RamanujanB on 10/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TestSDL_collision_h
#define TestSDL_collision_h

#include "vector3d.h"

class collision{
    
    public:
    static bool sphereplane(vector3d& sp,vector3d pn,vector3d p1,vector3d p2,vector3d p3,vector3d p4, float r);
    static bool spheresphere(vector3d& c1,float r1,vector3d c2,float r2);
    static bool raysphere(float xc,float yc,float zc,float xd,float yd,float zd,float xs,float ys,float zs,float r);
    static bool rayplane(const float& nx,float ny,float nz,float x0,float y0,float z0,float xs,float ys,float zs,float xd,float yd,float zd,vector3d p1,vector3d p2,vector3d p3,vector3d p4);
    static float trianglearea(vector3d p1,vector3d p2,vector3d p3);
    static float pointdistace(vector3d p1,vector3d p2);
    
};

#endif
