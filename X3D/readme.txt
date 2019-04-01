
  To run the cylinder you have to open a terminal (with a linux or MACOS) and execute ./cylinder.
  You have to be in the repository where the file cylinder is.

  If it's not working, try to recompile the file cylinder.c with the command : gcc cylinder.c -o cylinder -Wall -std=c99 -lm
  and then execute ./cylinder

  To run the x3D file, you'll need to open view3dscene first, and the open the file TheGherkin.x3d with it.
  We've forgot to put different points of view (SORRY !), we tried to do one without trying it, it's in comment in TheGherkin.x3d file
  between the lines 25 and 33.

  This program will write in the terminal every coordinates and the link between the points.
  The first part will draw every triangle of the Gherkin. The second part will link the points for the floors (this is not essential).
  Finally we have the coordinates of each points.

  The coordinates, the number of floors, the number of triangles and the height is fully configurable in the file cylinder.c
  However, if you change those parameters the colors won't follow, we didn't find an algorithm to fill the colors in the right place

  I hope this may help you understanding how to run our project.
  Thank you for reading and your time.
