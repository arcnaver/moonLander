/***********************************************************************
 * Header File:
 *    WORLD : Puts a world on the screen
 * Author:
 *    Adam Tipton
 * Summary:
 *    Defines a world for drawing on the screen. A circle.
 * SOURCE:
 *    includes, ifdefs, and drawCircle code copied from uiDraw.cpp.
 ************************************************************************/


#ifndef WORLD_H
#define WORLD_H

#ifdef __APPLE__
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#endif // __linux__

#ifdef _WIN32
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#endif // _WIN32

#include "point.h"
#include <cassert>
#include <cmath>

/********************************************
* WORLD
*   For creating world object
*********************************************/

class World
{
public:
   // This will define our world
   void drawWorld(const Point & center, int radius, 
                 float red, float green, float blue);

private:
   Point world;
};



#endif  //WORLD_H