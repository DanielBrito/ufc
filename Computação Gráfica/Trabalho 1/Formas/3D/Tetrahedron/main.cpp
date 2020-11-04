// Default libraries:
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

// Defining varibles for transformation:
float axisZ=0.0, axisX=0.0, axisY=0.0;

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

// Defining Face class for drawing the Tetrahedron:
class Face{

public:
  Vertex *v1{}, *v2{}, *v3{};

  // Defining the constructor with the proper fields:
  Face(Vertex* v1, Vertex* v2, Vertex* v3){

    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
  }
};

// Defining Tetrahedron class:
class Tetrahedron{

public:
  Face* faces[4]{};

  // Defining the constructor with the proper fields:
  Tetrahedron(Vertex* v0, Vertex* v1, Vertex* v2){

    float l = fabs(v0->x - v1->x);
    float h = (l*sqrt(3.0))/4.0;
    float a = (l*sqrt(6.0))/3.0;

    Vertex* v3 = new Vertex(0.0, h+a, 0.0);

    this->faces[0] = new Face(v0, v1, v2);
    this->faces[1] = new Face(v0, v2, v3);
    this->faces[2] = new Face(v0, v1, v3);
    this->faces[3] = new Face(v3, v2, v1);
  }

  // Method to draw the object:
  void draw(){

    glBegin(GL_LINE_LOOP);
      for(int i = 0; i < 4; i++){

        glColor3f(0, 0, 0);
        glVertex3f(this->faces[i]->v1->x, this->faces[i]->v1->y, this->faces[i]->v1->z);
        glVertex3f(this->faces[i]->v2->x, this->faces[i]->v2->y, this->faces[i]->v2->z);
        glVertex3f(this->faces[i]->v3->x, this->faces[i]->v3->y, this->faces[i]->v3->z);
      }
    glEnd();
  }
};

// Initializing the scene:
void init(){

  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
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

// Function for transformation:
void transform(){

  mat4 Rz = mat4(1.0);

  Rz[1] = vec4(0.0, cos(axisX), -sin(axisX), 0.0);
  Rz[2] = vec4( 0.0, sin(axisX), cos(axisX), 0.0);

  Rz[0] = vec4(cos(axisX), -sin(axisX), 0.0, 0.0);
  Rz[1] = vec4(sin(axisX), cos(axisX), 0.0, 0.0);

  glRotatef(axisX,1.0f,0.0f,0.0f);
  glRotatef(axisZ,0.0f,0.0f,1.0f);

  glMultMatrixf((GLfloat*)&Rz);
}

// Displaying the scene:
void display (){

  Vertex* v0 = new Vertex(0.0, -0.25, 0.5);
  Vertex* v1 = new Vertex( 0.5, -0.25, -0.25);
  Vertex* v2 = new Vertex(-0.5, -0.25, -0.25);

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPushMatrix();

  Tetrahedron* tetrahedron = new Tetrahedron(v0, v1, v2);

  transform();

  tetrahedron->draw();

  glFlush();
  glPopMatrix();
}

// Main function:
int main(int argc,char**argv){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
  glutInitWindowSize(600,600);
  glutCreateWindow("Tetrahedron");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();

  return 0;
}
