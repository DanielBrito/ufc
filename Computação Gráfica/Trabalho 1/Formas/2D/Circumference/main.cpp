// Default libraries:
#include <GL/glut.h>
#include <bits/stdc++.h>

// Helps to draw the circumference:
#define PI 3.1415927

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

// Defining Circumference class:
class Circumference{

public:
  Vertex* center;
  double radius;
  int numberVertexes;

  // Defining the constructor with the proper fields:
  Circumference(Vertex* center, double radius, int numberVertexes){

    this->center = center;
    this->radius = radius;
    this->numberVertexes = numberVertexes;
  }

  // Method to draw the figure:
  void draw(){

    vector<Vertex*> vertexes;

    for(int i=0; i<numberVertexes; i++){

      double theta = 2.0 * PI * double(i) / double(numberVertexes);
      double x = this->radius * cosf(float(theta));
      double y = this->radius * sinf(float(theta));

      Vertex* v = new Vertex(this->center->x+x, this->center->y+y);
      vertexes.push_back(v);
    }

    glBegin(GL_LINE_LOOP);
      glColor3f(0, 0, 0);
      for(int i=0; i<this->numberVertexes; i++){

        glVertex2f(vertexes[i]->x, vertexes[i]->y);
      }
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

  Vertex* center = new Vertex(5.0, 10.0);

  Circumference* circle = new Circumference(center, 20.0, 8);

  transform();

  circle->draw();

  glFlush();
}

// Setting the reshape callback for the current window:
void reshape(int w, int h){

  glViewport(0, 0,(GLsizei) w,(GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-40.0, 40.0, -40.0, 40.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Main function:
int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Circumference");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
