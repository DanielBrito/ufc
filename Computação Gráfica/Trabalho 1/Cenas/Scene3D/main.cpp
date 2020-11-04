// Default libraries:
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <bits/stdc++.h>

// Helps to draw the sphere and cylinder:
#define PI 3.1415926

using namespace glm;
using namespace std;

// Defining variables for transformation:
float axisX=0.0, axisY=0.0, axisZ=0.0;

// Defining 3D object class (parent):
class Form3D{

public:
  string name;

  // Defining the constructor with the proper fields:
  Form3D(string name){

    this->name = name;
  }

  // Method to draw the figure:
  virtual void draw(){}
};

// Defining 3D scene which will containing 3D objects(cubes, tetrahedrons, spheres, cylinders):
class Scene3D{

public:
  vector<Form3D*> forms;

  // Method to add a new object to the scene:
  void addForm(Form3D* form){

    cout << "New form: " << form->name << "\n";
    this->forms.push_back(form);
  }

  // Method to draw all the forms of the scene:
  void drawForms(){

    for(Form3D* form : this->forms){

      form->draw();
    }
  }
};

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

// Defining Face class:
class Face{

public:
  Vertex *v1{}, *v2{}, *v3{}, *v4{};

  // Defining the constructor with the proper fields (Tetrahedron):
  Face(Vertex* v1, Vertex* v2, Vertex* v3){

    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
  }

  // Defining the constructor with the proper fields (Cube):
  Face(Vertex* v1, Vertex* v2, Vertex* v3, Vertex* v4){

    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
    this->v4 = v4;
  }
};

// Defining Tetrahedron class (child):
class Tetrahedron: public Form3D{

public:
  Face* faces[4]{};

  // Defining the constructor with the proper fields:
  Tetrahedron(string name, Vertex* v0, Vertex* v1, Vertex* v2): Form3D(name){

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
  void draw() override{

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

// Defining Cube class (child):
class Cube: public Form3D{

public:
  Face* faces[6];
  double radius;
  Vertex* center;

  // Defining the constructor with the proper fields:
  Cube(string name, double radius, Vertex* center): Form3D(name){

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
  void draw() override{

    glBegin(GL_LINE_STRIP);
      for(int i = 0; i < 6; i++){

        glColor3f(0, 0, 0);
        glVertex3f(this->faces[i]->v1->x, this->faces[i]->v1->y, this->faces[i]->v1->z);
        glVertex3f(this->faces[i]->v2->x, this->faces[i]->v2->y, this->faces[i]->v2->z);
        glVertex3f(this->faces[i]->v3->x, this->faces[i]->v3->y, this->faces[i]->v3->z);
        glVertex3f(this->faces[i]->v4->x, this->faces[i]->v4->y, this->faces[i]->v4->z);
      }
    glEnd();
  }
};

// Defining Cylinder class (child):
class Cylinder: public Form3D{

public:
  double height;
  double radius;
  int numberVertexes;

  // Defining the constructor with the proper fields:
  Cylinder(string name, double height, double radius, int numberVertexes): Form3D(name){

    this->height = height;
    this->radius = radius;
    this->numberVertexes = numberVertexes;
  }

  // Method to draw the object:
  void draw() override{

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

    glColor3ub(0 , 0, 0);

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

// Defining Sphere class (child):
class Sphere: public Form3D{

public:
  double radius;
  int numberHorizontalSegments;
  int numberVerticalSegments;
  vector<Vertex*> vertexes;

  // Defining the constructor with the proper fields:
  Sphere(string name, float radius, int numberHorizontalSegments, int numberVerticalSegments): Form3D(name){

    this->numberHorizontalSegments = numberHorizontalSegments;
    this->numberVerticalSegments = numberVerticalSegments;
    this->radius = radius;

    for(int i=0; i<=this->numberHorizontalSegments; i++){

      double lat0 = (2.0*PI * float(i-1)) / float(this->numberHorizontalSegments);
      double z0  = sin(lat0);
      double zr0 =  cos(lat0);
      double lat1 = (2.0*PI * float(i)) / float(this->numberHorizontalSegments);
      double z1 = sin(lat1);
      double zr1 = cos(lat1);

      for(int j=0; j<=this->numberVerticalSegments; j++){

        double lng = (2.0*PI * float(j)) / float(this->numberVerticalSegments);
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
  void draw() override{

    glBegin(GL_LINE_STRIP);
      for (int i=0; i < this->vertexes.size() ; i++){

        glColor3f(0, 0, 0);
        glVertex3f(this->vertexes[i]->x, this->vertexes[i]->y, this->vertexes[i]->z);
      }
    glEnd();
  }
};

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
  Rz[2] = vec4(0.0, sin(axisX), cos(axisX), 0.0);

  Rz[0] = vec4(cos(axisX), -sin(axisX), 0.0, 0.0);
  Rz[1] = vec4(sin(axisX), cos(axisX), 0.0, 0.0);

  glRotatef(axisX, 1.0, 0.0, 0.0);
  glRotatef(axisZ, 0.0, 0.0, 1.0);

  glMultMatrixf((GLfloat*)&Rz);
}

// Displaying the scene:
void display(){

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPushMatrix();

  Scene3D* scene3D = new Scene3D();

  Vertex* v0 = new Vertex(0.0, -0.25, 0.5);
  Vertex* v1 = new Vertex( 0.5, -0.25, -0.25);
  Vertex* v2 = new Vertex(-0.5, -0.25, -0.25);
  Tetrahedron* tetrahedron = new Tetrahedron("my tetrahedron", v0, v1, v2);

  Vertex* center = new Vertex(0, 0, 0);
  Cube* cube = new Cube("my cube", 0.25, center);

  Cylinder* cylinder = new Cylinder("my cylinder", 1.0, 0.3, 40);

  Sphere* sphere = new Sphere("my sphere", 15.0, 50, 50);

  scene3D->addForm(tetrahedron);
  scene3D->addForm(cube);
  scene3D->addForm(cylinder);
  scene3D->addForm(sphere);

  transform();

  scene3D->drawForms();

  glFlush();
  glPopMatrix();
}

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

// Main function:
int main(int argc,char**argv){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
  glutInitWindowSize(600, 600);
  glutCreateWindow("3D Scene");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();

  return 0;
}
