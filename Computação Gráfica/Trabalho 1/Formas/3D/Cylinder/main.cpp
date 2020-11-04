// Default libraries:
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <glm/glm.hpp>

// Helps to draw the circumference:
#define PI 3.1415927

// Defining variables for transformation:
float axisZ=0.0, axisX=0.0, axisY=0.0;

// Defining Cylinder class:
class Cylinder{

public:
  double height;
  double radius;
  int numberVertexes;

  // Defining the constructor with the proper fields:
  Cylinder(double height, double radius, int numberVertexes){

    this->height = height;
    this->radius = radius;
    this->numberVertexes = numberVertexes;
  }

  // Method to draw the object:
  void draw(){

    float x, y, angle;

    glBegin(GL_LINE_LOOP);
      glColor3ub(0, 0, 0);
      angle = 0.0;

      while( angle < 2*PI ) {

        x = this->radius * cos(angle);
        y = this->radius * sin(angle);

        glVertex3f(x, y , this->height);
        glVertex3f(x, y , 0.0);

        angle += 0.1;
      }

      glVertex3f(this->radius, 0.0, this->height);
      glVertex3f(this->radius, 0.0, 0.0);
    glEnd();

    glColor3ub(0, 0, 0);
    
    glBegin(GL_LINE_LOOP);
      angle = 0.0;

      while( angle < 2*PI ) {

        x = this->radius * cos(angle);
        y = this->radius * sin(angle);

        glVertex3f(x, y , this->height);

        angle += 0.1;
      }

      glVertex3f(this->radius, 0.0, this->height);
    glEnd();
  }
};

// Initializing the scene:
void init(){

  glClearColor(1, 1, 1, 1);
  glShadeModel (GL_SMOOTH);
}

// Function for transformation:
void transform(){

  glTranslatef(0.0, -0.4, -3.0);
  glRotatef(-40, 1.0, 0.0, 0.0);
}

// Configuring keys for transformation:
void specialKeys(int key, int x, int y){

  switch (key){

    case GLUT_KEY_RIGHT:
      axisZ += 1;
      glutPostRedisplay();
      break;

    case GLUT_KEY_LEFT:
      axisZ -= 1;
      if(axisZ<1) axisZ=1;
      glutPostRedisplay();
      break;

    case GLUT_KEY_UP:
      axisX += 1;
      glutPostRedisplay();
      break;

    case GLUT_KEY_DOWN:
      axisX -= 1;
      if(axisX<1) axisX=1;
      glutPostRedisplay();
      break;

    default:
      break;
  }
}

// Displaying the scene:
void display(){

  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  Cylinder* cylinder = new Cylinder(1.0, 0.3, 40);

  transform();

  cylinder->draw();

  glFlush();
}

// Setting the reshape callback for the current window:
void reshape(int width, int height){

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, (GLdouble)width/(GLdouble)height, 0.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, width, height);
}

// Main function:
int main(int argc, char **argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Cylinder");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();

  return 0;
}