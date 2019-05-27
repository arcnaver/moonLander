/***********************************************************************
 * Source File:
 *     LANDER
 * Author:
 *     Adam Tipton
 * Description:
 *     These are the definitions for the lander class.
 ************************************************************************/
#include "lander.h"
#include "uiDraw.h"


void Lander::applyGravity(float amount)
{
   velocity.setDy(velocity.getDy() - amount);
}

void Lander::applyThrustLeft()
{
   if (fuel > 0)
   {
    
      velocity.setDx(velocity.getDx() + .1);

      this->fuel = fuel - 1;
   }
}

void Lander::applyThrustRight()
{
   if (fuel > 0)
   {
      velocity.setDx(velocity.getDx() - .1);

      this->fuel = fuel - 1;
   }
}

void Lander::applyThrustBottom()
{
   if (fuel > 0)
   {
      velocity.setDy(velocity.getDy() + .3);

      this->fuel = fuel - 1;
   }
    
  
}

void Lander::advance()
{
   point.addX(velocity.getDx()); // get the direction from velocity
   point.addY(velocity.getDy()); // get the direction from velocity
}

void Lander::draw() const
{
   if (isAlive())
   {
      drawLander(point);
   }
}

bool Lander::canThrust()
{
   return (isAlive() && !isLanded() && fuel > 0);
}
