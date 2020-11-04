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

  // Method to draw the form:
  void draw(){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
      glColor3f(0, 0, 0);
      glVertex2f(this->x, this->y);
    glEnd();

    glFlush();
  }
};

// Defining Edge class:
class Edge{

public:
  Vertex *start, *end;

  // Defining the constructor with the proper fields:
  Edge(Vertex* start, Vertex* end){

    this->start = start;
    this->end = end;
  }

  // Method to draw the form:
  void draw(){

    glBegin(GL_LINES);
      glVertex2f(this->start->x, this->start->y);
      glVertex2f(this->end->x, this->end->y);
    glEnd();
  }
};

// Defining Face class:
class Face{

  // Implemented inside each object 
};

// Initializing the scene:
void init(){

  glClearColor(1, 1, 1, 1);
  glShadeModel(GL_SMOOTH);
}

// Displaying the scene:
void display(){

  glClear(GL_COLOR_BUFFER_BIT);

  Vertex* vertex = new Vertex(0.0, 0.0);
  vertex->draw();

  Vertex* start = new Vertex(-5.0, 0.0);
  Vertex* end = new Vertex(5.0, 5.0);
  Edge* edge = new Edge(start, end);
  edge->draw();

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
  glutCreateWindow("Mesh");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
