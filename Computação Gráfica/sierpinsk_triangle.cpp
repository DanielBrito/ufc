#include <GL/glut.h>
#include <stdio.h>
#include <vector>
//#include <glm/glm.hpp>
using namespace std;
//using namespace glm;
vector<GLfloat> points;

GLfloat v[6] = {0.0, 0.0, 10.0, 0.0, 5.0, 8.666};
int n=5;

void triangle(GLfloat ax, GLfloat ay, GLfloat bx, GLfloat by, GLfloat cx, GLfloat cy){
    points.push_back(ax);
    points.push_back(ay);

    points.push_back(bx);
    points.push_back(by);

    points.push_back(cx);
    points.push_back(cy);
}

void divide_triangle(GLfloat ax, GLfloat ay, GLfloat bx, GLfloat by, GLfloat cx, GLfloat cy, int k){
    if (k>0){
        GLfloat abx = (ax + bx) / 2.0;
        GLfloat aby = (ay + by) / 2.0;

        GLfloat acx = (ax + cx) / 2.0;
        GLfloat acy = (ay + cy) / 2.0;

        GLfloat bcx = (cx + bx) / 2.0;
        GLfloat bcy = (cy + by) / 2.0;

        divide_triangle(ax, ay, abx, aby, acx, acy, k-1);
        divide_triangle(cx, cy, acx, acy, bcx, bcy, k-1);
        divide_triangle(bx, by, bcx, bcy, abx, aby, k-1);
    }
    else{
        triangle(ax, ay, bx, by, cx, cy);
    }
}

void display(void){
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);

    points.clear();
    divide_triangle(v[0], v[1], v[2], v[3], v[4], v[5], n);
    printf("n = %d\n", n);
    printf("size = %d\n", points.size());
    glBegin(GL_TRIANGLES);

    for (int i = 0; i<points.size(); i+=2){
        glVertex2d(points[i], points[i+1]);
    }

    glEnd();
    glFlush();
}

void reshape(int w, int h){
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0*w/h, 11.0*w/h, -1.0, 11.0);
   glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y){
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            {n++;
            glutPostRedisplay();}
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN){
            n--;
            glutPostRedisplay();}
         break;
      default:
         break;
   }
}

void init(void){
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 11.0, -1.0, 11.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Sierpinsk Triangle");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
