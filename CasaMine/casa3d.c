#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int win_id;

//Aqui se capturam as teclas comuns (letras, números e ESC, por exemplo)
void myKeyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
            break; 
        case 'R': 
        case 'r':// muda a cor corrente para vermelho
        glColor3f(1.0f, 0.0f, 0.0f);
        break;
        case 'G':
        case 'g':// muda a cor corrente para verde
        glColor3f(0.0f, 1.0f, 0.0f);
        break;
        case 'B':
        case 'b':// muda a cor corrente para azul
        glColor3f(0.0f, 0.0f, 1.0f);
        break;
        //case 27:
        //  glutDestroyWindow(win_id);
        //  exit(0);
        //  break;
    }
    glutPostRedisplay();
}

//Aqui se capturam as teclas especiais (Alt, Control, Shift, F1, F2, etc.)
void myKeyboardSpecial(int key, int x, int y ) {
    switch ( key ) {
        case GLUT_KEY_UP:                   // Quando a seta para cima é teclada...
        glutFullScreen ( );               // Vá para o modo tela cheia...
        break;
        case GLUT_KEY_DOWN:                 // Quando a seta para baixo for teclada...
        glutReshapeWindow ( 640, 480 );   // Vá para modo em janela de 640 por 480
        break;
        default:
        printf("Você apertou a tecla especial código: %d\n", key);  // ...para ajudar você a debugar...       
        break;
    }
}

void init(void){
    // Define a cor de fundo da janela de visualização como preto
    glClearColor (0.0, 0.0, 0.0, 0.0);
    // Define o modo de rastreio de cor utilizado para misturar a cor do material nos pontos da face (smoothing)
    glShadeModel (GL_SMOOTH);
    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);

    //Parâmetros para a luz ambiente, difusa e especular, definindo também a posição da luz
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

    // Passa os parâmetros definidos acima para a OpenGL
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Habilita a luz ambiente, a luz zero e o depth buffer
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    //Primeira cor, para depois mudarmos com os eventos
    glColor3f(0.5, 1.0, 0.5);
}

void display(void){
    // Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Entra no modo de definição de matriz de visualização
    glMatrixMode(GL_MODELVIEW);
    // Carrega a matriz identidade
    glLoadIdentity();
    // Define a posição da câmera, para onde ela aponta e qual o vetor UP
    /*gluLookAt(5.0, 1.5, 5.0,  // Posição da câmera 
              0.0, 0.0, 0.0,  // Ponto para onde a câmera está olhando 
              0.0, 1.0, 0.0); // Vetor de orientação da câmera*/

    gluLookAt(5.0, 1.5, 5,  // Posição da câmera 
              0.0, 0.0, 0.0,  // Ponto para onde a câmera está olhando 
              0.0, 1.0, 0.0); // Vetor de orientação da câmera

    /* Paredes */
    glTranslatef(0.0, 0.0, 0.0); //JANELA
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0); //JANELA
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glColor3f(1.0, 0.8, 0.6);

    glTranslatef(0.0, 0.0, 20.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -30.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 10.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, 10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, 10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, 10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, -20.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(-10.0, 0.0, 30.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(-10.0, 0.0, 0.0); //PORTA BAIXO
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glColor3f(1.0, 0.8, 0.6);

    glTranslatef(-10.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(-10.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 10.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, 10.0); //JANELA
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, 10.0); //JANELA
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glColor3f(1.0, 0.8, 0.6);

    glTranslatef(0.0, 0.0, 10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 10.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(10.0, -10.0, 30.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(10.0, 0.0, 0.0); //PORTA CIMA
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glColor3f(1.0, 0.8, 0.6);

    glTranslatef(10.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 10.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(-10.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(-10.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(0.0, 10.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(10.0, 0.0, 0.0); //JANELA
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glTranslatef(10.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    //COMEÇA O TELHADO
    glColor3f(0.5, 0.2, 0.0);

    glTranslatef(7.5, 2.5, 2.5);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, 5.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, 5.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -15.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 8; i++){
        glTranslatef(0.0, 0.0, -5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(0.0, -5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, 5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(5.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, -5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(-10.0, 10.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, 5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(-5.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, -5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(0.0, 5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, 5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(-15.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, -5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(0.0, -5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, 5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(-5.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, -5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(-5.0, -5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, 5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(0.0, -5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, -5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(-5.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 11; i++){
        glTranslatef(0.0, 0.0, 5.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(22.5, 12.5, -2.5);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(10.0);
    glPopMatrix();

    for(int i = 0; i < 5; i++){
        glTranslatef(0.0, 0.0, -10.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(10.0);
        glPopMatrix();
    }

    glTranslatef(12.5, 2.5, 10.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 2; i++){
        glTranslatef(0.0, 5.0, 0.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(0.0, 0.0, 5.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    for(int i = 0; i < 2; i++){
        glTranslatef(0.0, -5.0, 0.0);
        glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glutSolidCube(5.0);
        glPopMatrix();
    }

    glTranslatef(-5.0, 5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    glTranslatef(0.0, 5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -5.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    glTranslatef(0.0, -5.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidCube(5.0);
    glPopMatrix();

    // Executa os comandos OpenGL, e depois troca os buffers de vídeo
    glFlush();
}

void reshape (int w, int h){
    // Define o viewport como o tamanho da janela
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    // Entra no modo de definição de matriz de projeção
    glMatrixMode (GL_PROJECTION);
    // Carrega a matriz identidade
    glLoadIdentity();
    // Define a projeção ortogonal
    if (w <= h)
        // Se a largura for menor que a altura, a projeção é feita para manter a proporção da janela
        glOrtho (-50, 50, -50*(GLfloat)h/(GLfloat)w, 50*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
    else
        // Se a altura for menor que a largura, a projeção é feita para manter a proporção da janela
        glOrtho (-50*(GLfloat)w/(GLfloat)h, 50*(GLfloat)w/(GLfloat)h, -50, 50, -100.0, 100.0);
}

int main(int argc, char** argv){
    // Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas
    glutInit(&argc, argv);
    // Inicializa o display, indicando que usará:
    // - um buffer de imagem (single buffer);
    // - buffer de profundidade;
    // - padrão de cores RGB)
    glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
    // Especifica as dimensões da janela de exibição
    glutInitWindowSize (600, 500); 
    // Especifica a posição inicial da janela de exibição
    glutInitWindowPosition (100, 100);
    // Cria a janela de exibição
    win_id = glutCreateWindow (argv[0]);
    // Chama a função init
    init ();
    // Estabelece a função "display" como a função callback de exibição.
    glutDisplayFunc(display); 
    // Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
    glutReshapeFunc(reshape);
    // Estabelece a função "keyboard" como a função callback de evento de teclado.
    glutKeyboardFunc(myKeyboard);
    // Estabelece a função "keyboardSpecial" como a função callback de evento de teclado especial.
    glutSpecialFunc(myKeyboardSpecial);
    // Entra no loop de eventos, não retorna
    glutMainLoop();
    return 0;
}