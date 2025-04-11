Installation Guide
Follow these steps to set up and run the project:

Step 1: Clone the Repository

    git clone <repository-url>
    cd <repository-folder>

Step 2: Install Required Extension

- Open Visual Studio Code.
- Navigate to the **Extensions** panel.
- Search for and install the `TDT4102` extension.
- Follow any additional instructions provided by the extension's installer.

Step 3: Set Up the Project Template

- Open the command palette (`Ctrl+Shift+P` or `Cmd+Shift+P` on macOS).
- Run the command:
  
      TDT4102: Create Project from TDT4102 Template

- Select **Blank Project** when prompted.
- **Skip** replacing the existing `main.cpp`.

Step 4: Compile and Run

- Press `Ctrl+F5` to compile and execute your project.
  
**You're all set!** Your project should now be up and running.

About the program:

The program is a simple RayTracing simulator in two dimensions. This program does not feature reflections, but it does stop rays when hitting objects. There are two types of objects implemented in this program: lines and circles. These two types of objects can be used as building blocks to draw different figures that will stop rays.
From the mouse cursors coordinates, it iteratively draws rays out in 360 degrees. For each iteration, it checks for collision with objects. The objects are stored in a vector of the objects type. The object type contains variables which constitute the objects geometry. 
For circles, if the ray is closer to the circle origin than the radius, it must have hit the circle circumference and therefore that point is the collision point and returned.
For line segments, we use the general formula ax+bx+c=0, and look at an infinite line. Then we make sure that the ray crosses the infinite line between the two endpoints of a line segment on that infinite line. We also use a thickness for the line segment, this is because when iterating, from one to the next, the iteration can “jump” over the line and therefore we need to have sufficient threshold to make sure the ray “collides” with the line. Finally, we check for all conditions, and then return the collision point if it has satisfied the conditions.
For the GUI, the user can choose ray color and number of rays. The color is changed through updating a variable, while the number of rays are changed by using a member function to update a variable in main.
