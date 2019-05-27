/*************************************************************
 * File: lander.h
 * Author: Adam Tipton
 *
 * Description: Contains the definition of the lander class.
 *
 * This is my code! Don't share it, fool!
 *************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

 /*****************************************
  * LANDER
  * This class will have all of the lander
  * functionality.
  *****************************************/

#define DEFAULT_FUEL 500

class Lander
{
private:
   // Private variables
   int  fuel;
   bool alive;
   bool landed;
   

   Point point;
   Velocity velocity;


public:
   
   // Constructor
   Lander() : point(170, 170), alive(true), landed(false), fuel(DEFAULT_FUEL)
   {
      velocity.setDx(velocity.getDx() - 1);
   }
   
   Point                 getPoint() const { return point; }
   Velocity           getVelocity() const { return velocity; }

   bool                   isAlive() const { return alive; }
   bool                  isLanded() const { return landed; }
   int                    getFuel() const { return fuel; }
      
   void    setLanded(bool landed) { this->landed = landed; }
   void      setAlive(bool alive) { this->alive = alive; }
   void         setFuel(int fuel) { this->fuel = fuel; }

   void applyGravity(float amount);
   void          applyThrustLeft();
   void         applyThrustRight();
   void        applyThrustBottom();

   void                  advance();
   void                     draw() const;

   bool                 canThrust();

};


#endif
