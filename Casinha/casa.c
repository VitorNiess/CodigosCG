#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

#define PI 3.141592653

void reshape(int w, int h) {
  glViewport(0, 0, w, h);       /* Establish viewing area to cover entire window. */
  glMatrixMode(GL_PROJECTION);  /* Start modifying the projection matrix. */
  glLoadIdentity();             /* Reset project matrix. */
  glOrtho(0, w, 0, h, -1, 1);   /* Map abstract coords directly to window coords. */
  //glScalef(1, -1, 1);           /* Invert Y axis so increasing Y goes down. */
  //glTranslatef(0, -h, 0);       /* Shift origin up to upper-left corner. */
}

//Reconheço que poderia ter feito funções para cada elemento e que seria muito melhor.
//Porém, eu não consegui, então não faça mais bullying por conta disso :)

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS); //quad frontal
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(200, 200); //a
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(200, 400); //b
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(400, 370); //c
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(400, 170); //d
  glEnd();

  glBegin(GL_QUADS); //ret porta
    glColor3f(0, 0, 0);
    glVertex2i(250, 192); //a
    glColor3f(0, 0, 0);
    glVertex2i(250, 332); //b
    glColor3f(0, 0, 0);
    glVertex2i(350, 317); //c
    glColor3f(0, 0, 0);
    glVertex2i(350, 177); //d
  glEnd();

  glBegin(GL_QUADS); //ret parede
    glColor3f(0.7, 0.7, 0.7);
    glVertex2i(400, 170); //a
    glColor3f(0.7, 0.7, 0.7);
    glVertex2i(400, 370); //b
    glColor3f(0.7, 0.7, 0.7);
    glVertex2i(700, 370); //c
    glColor3f(0.7, 0.7, 0.7);
    glVertex2i(700, 170); //d
  glEnd();

  glBegin(GL_QUADS); //ret telhado
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(400, 370); //a
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(300, 480); //b
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(600, 480); //c
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(700, 370); //d
  glEnd();

  glBegin(GL_TRIANGLES); //triang telhado
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(200, 400); //a
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(400, 370); //b
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(300, 480); //c
  glEnd();

  glBegin(GL_QUADS); //ret chamine
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(430, 460); //a
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(430, 530); //b
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(480, 530); //c
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(480, 460); //d
  glEnd();

  glBegin(GL_QUADS); //ret chamine topo
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(415, 530); //a
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(415, 550); //b
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(495, 550); //c
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(495, 530); //d
  glEnd();

  glBegin(GL_QUADS); //jan 1
    glColor3f(0, 0, 0);
    glVertex2i(450, 250); //a
    glColor3f(0, 0, 0);
    glVertex2i(450, 310); //b
    glColor3f(0, 0, 0);
    glVertex2i(520, 310); //c
    glColor3f(0, 0, 0);
    glVertex2i(520, 250); //d
  glEnd();

  glBegin(GL_LINES); //jan 1 - linhas
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(485, 250); //a
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(485, 310); //b

    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(450, 280); //a
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(520, 280); //d
  glEnd();

  glBegin(GL_QUADS); //jan 2
    glColor3f(0, 0, 0);
    glVertex2i(580, 250); //a
    glColor3f(0, 0, 0);
    glVertex2i(580, 310); //b
    glColor3f(0, 0, 0);
    glVertex2i(650, 310); //c
    glColor3f(0, 0, 0);
    glVertex2i(650, 250); //d
  glEnd();

  glBegin(GL_LINES); //jan 2 - linhas
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(615, 250); //a
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(615, 310); //b

    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(580, 280); //a
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(650, 280); //d
  glEnd();

  float ang, x = 295, y = 430, raio = 20, dbPi = 2.0 * PI;
  int numTri = 500;

  glBegin(GL_TRIANGLE_FAN); // janela circular
    glColor3f(0, 0, 0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  glBegin(GL_LINES); //jan circular - linhas
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(250, 430); //a
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(330, 430); //b

    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(295.7, 460); //a
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(295.7, 400); //d
  glEnd();

  x = 440, y = 640, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 1
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 420, y = 610, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 2
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 465, y = 610, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 3
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 467, y = 650, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 4
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 495, y = 640, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 5
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 493, y = 670, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 6
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 525, y = 677, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 7
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 510, y = 700, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 8
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  x = 540, y = 700, raio = 30;

  glBegin(GL_TRIANGLE_FAN); // nuvem 9
    glColor3f(1.0, 1.0, 1.0);

    for(int i = 0; i <= numTri; i++){
      glVertex2f(x + (raio * cos(i * dbPi / numTri)), y + (raio * sin(i * dbPi / numTri)));
    }
  glEnd();

  glFlush();  /* Single buffered, so needs a flush. */
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(1000, 800);
  glutCreateWindow("Casinha");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
