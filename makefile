###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Alvey, CS165
# Author:
#     Adam Tipton
# Summary:
#     This is the final implimentation of the MoonLander project
#	  The lander and velocity classes will be finished, allowing
#	  The lander to interact in the game.
# Above and Beyond
#     1. When fuel is exhausted the "-" will appear red if
#		 fuel gauge counts backwards.
#	  2. When lander runs out of fuel display 
#        "Houston, we have a problem!" at the top of the screen.
#     3. Added a WORLD class to create an earth that creeps
#		 across the sky.
#	  4. Crash and Landed safely appear top center now.
#	  5. Lander spawns in upper right corner with initial
#		 leftward velocity. 
###############################################################


LFLAGS = -lglut -lGLU -lGL -lz

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o world.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o world.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h uiDraw.h uiInteract.h point.h ground.h lander.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h lander.h velocity.h world.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h lander.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.h lander.cpp point.h velocity.h
	g++ -c lander.cpp
velocity.o: velocity.h velocity.cpp point.h
	g++ -c velocity.cpp
world.o: world.h world.cpp point.h
	g++ -c world.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
