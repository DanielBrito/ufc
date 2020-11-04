// Default libraries:
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

// Defining Vertex class for 2D object:
class Vertex{
  
public:
  double x, y;

  // Defining the constructor with the proper fields:
  Vertex(double x, double y){

    this->x = x;
    this->y = y;
  }
};

// Defining Square class:
class Square{

public:
  double radius;
  Vertex* center;

  // Defining the constructor with the proper fields:
  Square(double radius, Vertex* center){

    this->radius = radius;
    this->center = center;
  }

  // Method to draw the figure:
  void draw(){

    glBegin(GL_LINE_LOOP);
      glColor3d(0, 0, 0);
      glVertex2d(this->center->x + radius, this->center->y + radius);
      glVertex2d(this->center->x + radius, this->center->y - radius);
      glVertex2d(this->center->x - radius, this->center->y - radius);
      glVertex2d(this->center->x - radius, this->center->y + radius);
    glEnd();
  }
};

void transform(){

  // TODO - Optional
}

// Initializing the scene:
void init(){

  glClearColor(1, 1, 1, 1);
  glShadeModel(GL_SMOOTH);
}

// Displaying the scene:
void display(){

  glClear(GL_COLOR_BUFFER_BIT);

  Vertex* center = new Vertex(2.0, 2.0);
  Square* square = new Square(5, center);

  transform();

  square->draw();

  glFlush();
}

// Setting the reshape callback for the current window:
void reshape(int w, int h){

  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Main function:
int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Square");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
