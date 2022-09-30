/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Zachary Gilbert

Hours to complete assignment: 12hrs

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

To create a Sierpinski triangle by using a recursive function.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

    One key algortihm that I implemented was the way I was drawing
    the triangles to the screen so after x amount of recursive calls, decrease length,
    and move onto the next level.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

    One feature I implemented was instead of drawing X amount of triangles to the screen
    constantly. I instead made a render texture from the drawings and then making a sprite
    of the screen size and setting the texture of the sprite to the render texture 
    that way im only refreshing a texture and not the hundreds or thousands of triangles. It
    was more of an optimization feature.
    Another feature I made was making a function that returned a ConvexShape that created a 
    triangle based on an x and y position and its length.(This was really helpful), which made the process
    a lot less of a headache when making triangles constantly.

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/

    How to draw triangles recursiveley.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

    No one helped me, only the SFML documentation helped so I could learn ConvexShape stuff

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/

    One serious problem I had was the printing of the triangles in a certain way,
    if you want to see check lines 72-78 in TFractal.cpp.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
 Have a great day!