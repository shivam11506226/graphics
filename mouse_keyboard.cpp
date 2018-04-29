#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

float tx,ty;
int move=2;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(tx,ty,0.0);
	glutSolidSphere(0.2,20,20);
	glFlush();
	glutSwapBuffers();
}

/*
void moving1()
{
	tx=tx+0.01;
	ty=ty;
}

void moving2()
{
	tx=tx-0.01;
	ty=ty;
}
*/
void xyz(int v)
{
	if(move==1)
	{
		tx=tx+0.01;
		ty=ty;
	}
	if(move==0)
	{
		tx=tx-0.01;
		ty=ty;
	}
	
	glutPostRedisplay();
	glutTimerFunc(10,xyz,0);
}

void mo(int but,int state,int x,int y)
{
	if(but==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		//moving1();
		move=1;
	}
	if(but==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		//moving2();
		move=0;
	}
}

void key(unsigned char k,int x,int y)
{
	if(k=='A' || k=='a')
	{
		//moving2();
		move=0;
	}
	if(k=='D' || k=='d')
	{
		//moving1();
		move=1;
	}
}

int main(int argc, char **argv ){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("");
	glutDisplayFunc(display);
	glutMouseFunc(mo);
	glutKeyboardFunc(key);
	glutTimerFunc(100,xyz,0);
	glutMainLoop();
	return 0;
}
