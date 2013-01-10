//
//  collisionsphere.h
//  TestSDL
//
//  Created by RamanujanB on 10/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TestSDL_collisionsphere_h
#define TestSDL_collisionsphere_h

#include "vector3d.h"

class collisionsphere{
public:
    float r;
    vector3d center;
    collisionsphere();
    collisionsphere(const vector3d& vec,float rad );
    
};

#endif
