/***********************************************************************
 * Source File:
 *     WORLD
 * Author:
 *     Adam Tipton
 * Description:
 *     These are the definitions for the world class. drawCircle code
 *     copied from the uiDraw.cpp file. 
 *     With slightly altered code, this will draw a world shaped object
 *     on the screen.
 ************************************************************************/

#include "world.h"


// Not sure I need them but including just in case

#define deg2rad(value) ((M_PI / 180) * (value))


/****************************************************
* DRAWWORLD
*     This is the code for creating a circle on the 
*     screen that represents a world.
****************************************************/
void World::drawWorld(const Point & center, int radius, float red, float green, float blue)
{
   assert(radius > 1.0);
   const double increment = 1.0 / (double)radius;

   // begin drawing
   glBegin(GL_POLYGON);
   glColor3f(red /* red % */, green /* green % */, blue /* blue % */);
   // go around the circle
   for (double radians = 0; radians < M_PI * 2.0; radians += increment)
      glVertex2f(center.getX() + (radius * cos(radians)),
         center.getY() + (radius * sin(radians)));

   // complete drawing
   
   glEnd();
}