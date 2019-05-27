/*************************************************************
 * File: velocity.h
 * Author: Adam Tipton
 *
 * Description: Contains the definition of the velocity class.
 *
 * This is my code! Don't share it, fool!
 *************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"

 /*****************************************
  * VELOCITY
  * This class will have all of the velocity
  * functionality.
  *****************************************/
class Velocity
{
private:

   float dx;
   float dy;
   
   Point point;

public:
   Velocity()
   {
      // initial directions
      dx = getDx();
      dy = getDy();
    
   }

   Velocity(float x, float y)
   {
      setDx(x);
      setDy(y);
      
   }

   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void  setDx(float dx);
   void  setDy(float dy);
        
};


#endif

