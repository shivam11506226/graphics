#include<gl/glut.h>
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glClearColor(0,0,0,0);
	gluPerspective(90.0,4.0/3.0,5,40);
	gluLookAt(4,6,5,0,0,0,0,1,0);
	glutWireTeapot(2.0);
	glFlush(); 
}
int main(int a,char** b)
{
	glutInit(&a,b);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(200,50);
	glutCreateWindow("Are bhai bhai bhai");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
