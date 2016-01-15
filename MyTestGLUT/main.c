#include <GLUT/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(30.0, 20.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutSolidCube(2.0);
    glutSolidTorus(0.5,2.0,200,200);
    glFlush();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(10.0, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutCreateWindow("test test");
    glClearColor(0.0, 0.8, 1.0, 1.0);
    GLfloat light_position[ ] = {100.0, 200.0, 300.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    
    glutMainLoop();
    
    return 0;
}