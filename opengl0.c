#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

#define W 600
#define H 400

double mul = 1.0;

void rotate(double deg, double *x, double *y){
    double rad = deg * M_PI / 180;
    double x1, y1;

    *x = cos(rad);
}

void render(void){
    //Clearing our buffer
    glClear(GL_COLOR_BUFFER_BIT);


    // glBegin(GL_POLYGON);

    // glVertex2f(-.5, -.5);
    // glVertex2f(.5, -.5);
    // glVertex2f(-.5, .5);
    // glVertex2f(.5, .5);


    // glBegin(GL_TRIANGLES);

    // glColorf3(1,0,0);
    // glVertex2f(W/2, -H/2);
    // glColorf3(0,1,0);
    // glVertex2f(W/2, H/2);
    // glColorf3(0,0,1);
    // glVertex2f(-W/2, 0);

    
    glBegin(GL_TRIANGLES);

    float theta;
    for (theta = 0; theta < 2 * M_PI; theta += (M_PI / 60)){
        
        glColorf3(1,0,0);
        glVertex2f(H * cos(theta) / 2.1 + (0 * mul), ((H * sin(theta)) / 2.1) - (5 * mul));
        glColorf3(0,1,0);
        glVertex2f(H * cos(theta) / 2.1 - (5 * mul), ((H * sin(theta)) / 2.1) - (5 * mul));
        glColorf3(0,0,1);
        glVertex2f(H * cos(theta) / 2.1 + (5 * mul), ((H * sin(theta)) / 2.1) - (5 * mul));

    }

    glENd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y){


    switch ((key))
    {
    case 'c':
    case 'C':
        render();
        break;
    case 'q':
    case 'Q':
        exit();
        break;
    case 'm':
        mul /= 2;
        break;
    case 'M':
        mul *= 2;
        break;
    default:
        printf("Read '%c' with mouse at (%d, %d)\n", key, x, y);
    }
}


int main(int argc, char *argv[]){

    //Glut initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(W, H);
    glutCreateWindow("OpenGL Hello World");
    glutKeyboardFunc(keyboard);

    //OpenGL initialization
    //OpenGL is state oriented? Depends on which mode u set, openGL will know what you are working on
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gk0rtho(-W/2, W/2, -H/2, H/2, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(hello);
    glutMainLoop();

    return 0;


}

//gcc opengl0.c -lglut -lGL