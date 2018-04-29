#include<gl/glut.h>
#include<gl/gl.h>
#include<gl/glu.h>
GLubyte fish[] = {

	0x90,0x00,0x90,0x00,0x90,0x00,0x90,0x00,
	0xf0,0x00,0x90,0x00,0xf0,0x00,0xb0,0x00,
	0x90,0x00,0xf0,0x00,0x90,0x00,0xd0,0x00,
	0xf0,0x00,0x90,0x00,0xf0,0x00,0x90,0x00,
	};
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBitmap(64,4,-500,-500,-150,-50,fish);
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
