#include<GL/GLUT.h>

float ty=-1, flag=0;

void draw()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0, ty, 0);

        glColor3f(0.7, 0.4, 0.8);
        glutWireSphere(0.2, 50, 50);

        glFlush();
}

void bouncer(int v)
{
        if(flag == 0)
        {
                ty += 0.028;
                if(ty >= 0.8)
                        flag = 1;
        }
        else
        {
                ty -= 0.03;
                if(ty <= -0.8)
                        flag = 0;
        }

        glutPostRedisplay();
        glutTimerFunc(12, bouncer, 0);
}

int main(int argv, char **argc)
{
        glutInit(&argv, argc);
        glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
        glutInitWindowSize(700, 500);
        glutInitWindowPosition(70, 50);
        glutCreateWindow("Bouncing ball");
        glutDisplayFunc(draw);
        glutTimerFunc(100, bouncer, 0);
        glutMainLoop();

        return 0;
}
