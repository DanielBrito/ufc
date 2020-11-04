// Default libraries:
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

// Defining variables for transformation:
float axisX=0.0, axisY=0.0, axisZ=0.0;

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

// Defining Face class for drawing the Cube:
class Face{

public:
  Vertex *v1{}, *v2{}, *v3{}, *v4{};

  // Defining the constructor with the proper fields:
  Face(Vertex* v1, Vertex* v2, Vertex* v3, Vertex* v4){

    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
    this->v4 = v4;
  }
};

// Defining Cube class:
class Cube{

public:
  Face* faces[6];
  double radius;
  Vertex* center;

  // Defining the constructor with the proper fields:
  Cube(double radius, Vertex* center){

    this->radius = radius;
    this->center = center;

    Vertex* v0 = new Vertex(this->radius, this->radius, -this->radius );
    Vertex* v1 = new Vertex(-this->radius, this->radius, -this->radius );
    Vertex* v2 = new Vertex(-this->radius, this->radius, this->radius );
    Vertex* v3 = new Vertex(this->radius, this->radius, this->radius);

    float l = fabs(v1->x - v0->x);

    Vertex* v4 = new Vertex(v0->x, v0->y+l, v0->z);
    Vertex* v5 = new Vertex(v1->x, v1->y+l, v1->z);
    Vertex* v6 = new Vertex(v2->x, v2->y+l, v2->z);
    Vertex* v7 = new Vertex(v3->x, v3->y+l, v3->z);

    this->faces[0] = new Face(v0, v1, v2, v3);
    this->faces[1] = new Face(v0, v4, v5, v1);
    this->faces[2] = new Face(v2, v6, v5, v1);
    this->faces[3] = new Face(v2, v6, v7, v3);
    this->faces[4] = new Face(v3, v7, v4, v0);
    this->faces[5] = new Face(v4, v5, v6, v7);
  }

  // Method to draw the object:
  void draw(){

    glBegin(GL_LINE_STRIP);
      for(int i = 0; i < 6; i++){

        glColor3f(0,0,0);
        glVertex3f(this->faces[i]->v1->x, this->faces[i]->v1->y, this->faces[i]->v1->z);
        glVertex3f(this->faces[i]->v2->x, this->faces[i]->v2->y, this->faces[i]->v2->z);
        glVertex3f(this->faces[i]->v3->x, this->faces[i]->v3->y, this->faces[i]->v3->z);
        glVertex3f(this->faces[i]->v4->x, this->faces[i]->v4->y, this->faces[i]->v4->z);
      }
    glEnd();
  }
};

// Initializing the scene:
void init(){

  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

// Setting the reshape callback for the current window:
void reshape(GLsizei width, GLsizei height){

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Configuring keys for transformation:
void specialKeys(int key, int x, int y){

  switch(key){

    case GLUT_KEY_RIGHT:
      axisX += 1;
      glutPostRedisplay();
      break;

    case GLUT_KEY_LEFT:
      axisX -= 1;
      if(axisX < 0.0) axisX=0.0;
      glutPostRedisplay();
      break;

    case GLUT_KEY_UP:
      axisY += 1;
      glutPostRedisplay();
      break;

    case GLUT_KEY_DOWN:
      axisY -= 1;
      if(axisY < 0.0) axisY=0.0;
      glutPostRedisplay();
      break;

    default:
      break;
  }
}

// Function for transformation:
void transform(){

  mat4 Rz = mat4(1.0);
  mat4 Rz1 = mat4(1.0);

  Rz[1] = vec4(0.0, cos(axisX), -sin(axisX), 0.0);
  Rz[2] = vec4(0.0, sin(axisX), cos(axisX), 0.0);

  Rz1[0] = vec4(cos(axisY), 0.0, sin(axisY), 0.0);
  Rz1[2] = vec4(-sin(axisY), 0.0, cos(axisY), 0.0);

  Rz[0] = vec4(cos(axisX), -sin(axisX), 0.0, 0.0);
  Rz[1] = vec4(sin(axisX), cos(axisX), 0.0, 0.0);

  glMultMatrixf((GLfloat*)&Rz);
  glMultMatrixf((GLfloat*)&Rz1);
}

// Displaying the scene:
void display(){

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPushMatrix();

  Vertex* center = new Vertex(0, 0, 0);

  Cube* cube = new Cube(0.2, center);

  transform();

  cube->draw();

  glFlush();
  glPopMatrix();
}

// Main function:
int main(int argc,char**argv){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
  glutInitWindowSize(600,600);
  glutCreateWindow("Cube");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();

  return 0;
}
