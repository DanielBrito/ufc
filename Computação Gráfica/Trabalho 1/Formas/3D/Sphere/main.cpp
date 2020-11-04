// Default libraries:
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

// Helps to draw the sphere:
#define PI 3.1415927

// Defining varibles for transformation:
float axisY=0.0, axisX=0.0, axisZ=0.0;

// Defining Vertex class for 3D object:
class Vertex{

public:
  double x, y, z;

  // Defining the constructor with the proper fields:
  Vertex(double x, double y, double z){

    this->x = x;
    this->y = y;
    this->z = z;
  }
};

// Defining Sphere class:
class Sphere{

public:
  double radius;
  int numberHorizontalSegments;
  int numberVerticalSegments;
  vector<Vertex*> vertexes;

  // Defining the constructor with the proper fields:
  Sphere(float radius, int numberHorizontalSegments, int numberVerticalSegments){
    
    this->numberHorizontalSegments = numberHorizontalSegments;
    this->numberVerticalSegments = numberVerticalSegments;
    this->radius = radius;

    for(int i=0; i<=this->numberHorizontalSegments; i++){

      double lat0 =(2.0f*PI * float(i-1)) / float(this->numberHorizontalSegments);
      double z0  = sin(lat0);
      double zr0 =  cos(lat0);
      double lat1 =(2.0f*PI * float(i)) / float(this->numberHorizontalSegments);
      double z1 = sin(lat1);
      double zr1 = cos(lat1);

      for(int j=0; j<=this->numberVerticalSegments; j++){

        double lng =(2.0f*PI * float(j)) / float(this->numberVerticalSegments);
        double x = cos(lng);
        double y = sin(lng);

        Vertex* v1 = new Vertex(x * zr0, y * zr0, z0);
        Vertex* v2 = new Vertex(x * zr1, y * zr1, z1);

        this->vertexes.push_back(v1);
        this->vertexes.push_back(v2);
      }
    }
  }

  // Method to draw the object:
  void draw(){

    glBegin(GL_LINE_STRIP);
      for(int i=0; i < this->vertexes.size() ; i++){

        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(this->vertexes[i]->x, this->vertexes[i]->y, this->vertexes[i]->z);
      }
    glEnd();
  }
};

// Configuring keys for transformation:
void specialKeys(int button, int x, int y){

  switch(button){

    case GLUT_KEY_UP:
      axisX += 1.0f;
      glutPostRedisplay();
      break;

    case GLUT_KEY_DOWN:
      axisX -= 1.0f;
      if(axisX < 0.0) axisX = 0.0;
      glutPostRedisplay();
      break;

    case GLUT_KEY_RIGHT:
      axisY += 1.0f;
      glutPostRedisplay();
      break;

    case GLUT_KEY_LEFT:
      axisY -= 1.0f;
      if(axisY < 0.0) axisY = 0.0;
      glutPostRedisplay();
      break;

    default:
      break;
  }
}

// Initializing the scene:
void init(){

  glClearColor(1, 1, 1, 1);
  glShadeModel(GL_SMOOTH);
}

// Function for transformation:
void transform(){

  glRotatef(axisX, 1.0, 0.0, 0.0);
  glRotatef(axisY, 0.0, 1.0, 0.0);
}

// Displaying the scene:
void display(){

  glClear(GL_COLOR_BUFFER_BIT);

  Sphere* sphere = new Sphere(15.0, 50, 50);

  transform();

  sphere->draw();

  glFlush();
}

// Setting the reshape callback for the current window:
void reshape(int w, int h){

  glViewport(100, 100, 400, 400);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Main function:
int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Sphere");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();

  return 0;
}
