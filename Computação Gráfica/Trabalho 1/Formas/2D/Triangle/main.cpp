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

// Defining Triangle class:
class Triangle{

public:
  Vertex *point1, *point2, *point3;

  // Defining the constructor with the proper fields:
  Triangle(Vertex* p1, Vertex* p2, Vertex* p3){

    this->point1 = p1;
    this->point2 = p2;
    this->point3 = p3;
  }

  // Method to draw the figure:
  void draw(){

    glBegin(GL_LINE_LOOP);
      glColor3b(0, 0, 0);
      glVertex2f(this->point1->x, this->point1->y);
      glVertex2f(this->point2->x, this->point2->y);
      glVertex2f(this->point3->x, this->point3->y);
    glEnd();
  }
};

// Initializing the scene:
void init(){

  glClearColor(1, 1, 1, 1);
  glShadeModel(GL_SMOOTH);
}

void transform(){

  // TODO - Optional
}

// Displaying the scene:
void display(){

  glClear(GL_COLOR_BUFFER_BIT);

  Vertex* p1 = new Vertex(-3.0, -3.0);
  Vertex* p2 = new Vertex(3.0, -3.0);
  Vertex* p3 = new Vertex(0, 3.0);

  Triangle *triangle = new Triangle(p1, p2, p3);

  transform();

  triangle->draw();

  glFlush();
}

// Setting the reshape callback for the current window:
void reshape(int w, int h){

  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Main function:
int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Triangle");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
