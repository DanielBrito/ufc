// Default libraries:
#include <GL/glut.h>
#include <bits/stdc++.h>

// Helps to draw the circumference:
#define PI 3.1415927

using namespace std;

// Defining 2D object class (parent):
class Form2D{

public:
  string name;

  // Defining the constructor with the proper fields:
  Form2D(string name){

    this->name = name;
  }

  // Method to draw the figure:
  virtual void draw(){}
};

// Defining 2D scene which will containing 2D objects(square, triangle, circumference):
class Scene2D{

public:
  vector<Form2D*> forms;

  // Method to add a new object to the scene:
  void addForm(Form2D* form){

    cout << "New form: " << form->name << "\n";
    this->forms.push_back(form);
  }

  // Method to draw all the forms of the scene:
  void drawForms(){

    for(Form2D* form : this->forms){

      form->draw();
    }
  }
};

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

// Defining Triangle class (child):
class Triangle: public Form2D{

public:
  Vertex *point1, *point2, *point3;

  // Defining the constructor with the proper fields:
  Triangle(string name, Vertex *p1, Vertex *p2, Vertex *p3) : Form2D(name) {

    this->point1 = p1;
    this->point2 = p2;
    this->point3 = p3;
  }

  // Method to draw the figure:
  void draw() override {

    glBegin(GL_LINE_LOOP);
      glColor3b(0, 0, 0);
      glVertex2f(this->point1->x, this->point1->y);
      glVertex2f(this->point2->x, this->point2->y);
      glVertex2f(this->point3->x, this->point3->y);
    glEnd();
  }
};

// Defining Square class (child):
class Square: public Form2D{

public:
  double radius;
  Vertex* center;

  // Defining the constructor with the proper fields:
  Square(string name, double radius, Vertex* center): Form2D(name){

    this->radius = radius;
    this->center = center;
  }

  // Method to draw the figure:
  void draw() override{

    glBegin(GL_LINE_LOOP);
      glColor3d(0, 0, 0);
      glVertex2d(this->center->x + radius, this->center->y + radius);
      glVertex2d(this->center->x + radius, this->center->y - radius);
      glVertex2d(this->center->x - radius, this->center->y - radius);
      glVertex2d(this->center->x - radius, this->center->y + radius);
    glEnd();
  }
};

// Defining Circumference class (child):
class Circumference: public Form2D{

public:
  Vertex* center;
  double radius;
  int numberVertexes;

  // Defining the constructor with the proper fields:
  Circumference(string name, Vertex* center, double radius, int numberVertexes): Form2D(name){

    this->center = center;
    this->radius = radius;
    this->numberVertexes = numberVertexes;
  }

  // Method to draw the figure:
  void draw() override{

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

// Displaying the scene:
void display(){

  glClear(GL_COLOR_BUFFER_BIT);

  Scene2D* scene2D = new Scene2D();

  Vertex* p1 = new Vertex(-3.0, -3.0);
  Vertex* p2 = new Vertex(3.0, -3.0);
  Vertex* p3 = new Vertex(0, 3.0);
  Triangle* triangle = new Triangle("my triangle", p1, p2, p3);

  Vertex* centerSquare = new Vertex(2.0, 2.0);
  Square* square = new Square("my square", 5, centerSquare);

  Vertex* centerCircle = new Vertex(5.0, 10.0);
  Circumference* circle = new Circumference("my circle", centerCircle, 5.0, 30);

  scene2D->addForm(triangle);
  scene2D->addForm(square);
  scene2D->addForm(circle);

  scene2D->drawForms();

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
  glutCreateWindow("2D Scene");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}