#include<gl/glut.h>
#include<gl/gl.h>
#include<gl/glu.h>
GLubyte fish[] = {

	0x90,0x00,0x00,0x00,
	0xf0,0x00,0x00,0x00,
	0x90,0x00,0x00,0x00,
	0xf0,0x00,0x00,0x00,
	};
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBitmap(8,4,-300,-600,-100,-50,fish);
	glFlush(); 
}

int main(int a,char** b)
{
	glutInit(&a,b);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(200,50);
	glutCreateWindow("Are bhai bhai bhai");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
