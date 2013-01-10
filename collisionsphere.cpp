//
//  collisionsphere.cpp
//  TestSDL
//
//  Created by RamanujanB on 10/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "collisionsphere.h" 

collisionsphere::collisionsphere(){
    r=0;
}

collisionsphere::collisionsphere(const vector3d& vec,float rad){
    center.change(vec);
    r=rad;
}