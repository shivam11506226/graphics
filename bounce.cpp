#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>

float a= 1.0;
float b = 1.0;
float c = 1.0;
float ty=0, flag=0;

void drawCircle(int r, int h, int k){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glTranslatef(0, ty, 0);
	glBegin(GL_POINTS);
	glColor3f(a,b,c);
	int y =(int)r;
	int x = 0;
	int p = 1-y;
	while(x<=y){
		if(p<0){
			glVertex2d(x+h,y+k);
			glVertex2d(h-x,y+k);
			glVertex2d(h-x,k-y);
			glVertex2d(x+h,k-y);
			glVertex2d(y+h,x+k);
			glVertex2d(h-y,x+k);
			glVertex2d(h-y,k-x);
			glVertex2d(y+h,k-x);
			x = x+1;
			y = y;
			p = p+2*x+3;
		}else{
			glVertex2d(x+h,y+k);
			glVertex2d(h-x,y+k);
			glVertex2d(h-x,k-y);
			glVertex2d(x+h,k-y);
			glVertex2d(y+h,x+k);
			glVertex2d(h-y,x+k);
			glVertex2d(h-y,k-x);
			glVertex2d(y+h,k-x);
			x = x+1;
			y = y-1;
			p = p+2*x-2*y+5;
		}
	}
	
	glEnd();
	
	
}

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawCircle(10,50,10);
	glutSwapBuffers();
}


void bouncer(int v)
{
        if(flag == 0)
        {
                ty += 1;
                if(ty >= 80)
                        flag = 1;
        }
        else
        {
                ty -= 1;
                if(ty <= 0)
                        flag = 0;
        }

        glutPostRedisplay();
        glutTimerFunc(10, bouncer, 0);
}


int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Midpoint Circle Algorithm");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(100, bouncer, 0);
	glutMainLoop();
	return 0;
}
