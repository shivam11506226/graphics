#include<gl/glut.h>
#include<gl/gl.h>
#include<gl/glu.h>
void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(0.2,30,30);
	glTranslatef(0.3,0,0);
	glRotatef(45,0,1,0);
	glutSolidCone(0.1,0.5,10,15);
	glFlush(); 
}
void init(){
	GLfloat black[] ={0.0,0.0,0.0,1.0};
	GLfloat white[] ={1.0,1.0,1.0,1.0};
	GLfloat yellow[] ={1.0,1.0,0.0,1.0};
	GLfloat cyan[] ={1.0,.4,1.0,1.0};
	GLfloat direction[] ={1.0,1.0,0.0,0.0};	
	
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,cyan);
	glMaterialfv(GL_FRONT,GL_SPECULAR,white);
	glMaterialf(GL_FRONT,GL_SHININESS,45);
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,black);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,yellow);
	glLightfv(GL_LIGHT0,GL_SPECULAR,white);
	glLightfv(GL_LIGHT0,GL_POSITION,direction);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
int main(int a,char** b)
{
	glutInit(&a,b);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(200,50);
	glutCreateWindow("Are bhai bhai bhai");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
