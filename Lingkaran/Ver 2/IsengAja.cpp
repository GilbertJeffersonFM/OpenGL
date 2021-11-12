#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;
void timer(int);
float y = 0;
float z = 0;

float theta = 0;
float thetb = 0;
float thetc = 0;
float thetd = 0;

float l1 = 0;
float l2 = -0.5;

float l3 = 0;
float l4 = -0.5;

float l5 = 0;
float l6 = -0.5;

float l7 = 0;
float l8 = -0.5;

int i = 270;
int j = 0;
int k = 0;
int l = 0;
int status = 1;
int status2 = 1;
int status3 = 1;
int statusx1 = 1;
int statusx2 = 1;
int statusx3 = 3;
int statusx4 = 4;
float r1, r2, r3;

void titik()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.05,0.05,0.05);
	glBegin(GL_LINES);
		glVertex2f(0, 1);
		glVertex2f(0, -1);
		
		glVertex2f(1, 0);
		glVertex2f(-1, 0);	
	glEnd();
	
	glColor3f(1, 0.75, 0.41);
	glPointSize(2.5);
	glBegin(GL_POINTS);
		glVertex2f(l1 , l2);
	glEnd();
	
	glColor3f(0.64, 0.36, 0.36);
	glPointSize(2.5);
	glBegin(GL_POINTS);
		glVertex2f(l3 , l4);
	glEnd();	
	
		glColor3f(0.29, 0.23, 0.22);
	glPointSize(2.5);
	glBegin(GL_POINTS);
		glVertex2f(l5 , l6);
	glEnd();
	
		glColor3f(0.93, 0.93, 0.93);
	glPointSize(2.5);
	glBegin(GL_POINTS);
		glVertex2f(l7 , l8);
	glEnd();
	
	glFlush();
	glutSwapBuffers(); 
}

void timer(int){
	glutPostRedisplay();
	glutTimerFunc(4000/360, timer, 0);
	
	switch(status){
		case 1:
			theta = i * 3.142 / 180;
			l1 = 0.5 * cos(theta);
			l2 = 0.5 * sin(theta);
			i = i + 1;
		
			if(i == 360){
				i = 0;
			}
			if(i == 270){
				status =2;
				j = 270;
				cout << "1";
			}
			break;
		case 2: 	
			thetb = j * 3.142 / 180;
			l3 = 0.5 * cos(thetb);
			l4 = 0.5 * sin(thetb);
			j = j + 1;
				
			if(j == 360){
				j = 0;

			}
			if(j == 270){
				status =3;
				k = 270;
				cout << "2";				
			}
			break;
		case 3: 	
			thetc = k * 3.142 / 180;
			l5 = 0.5 * cos(thetc);
			l6 = 0.5 * sin(thetc);
			k = k + 1;
				
			if(k == 360){
				k = 0;
			}
			if(k == 270){
				status =4;
				l = 270;
				cout << "3";
			}
			break;
		case 4: 	
			thetd = l * 3.142 / 180;
			l7 = 0.5 * cos(thetd);
			l8 = 0.5 * sin(thetd);
			l = l + 1;
				
			if(l == 360){
				l = 0;
			}
			if(l == 270){
				status =1;
				i = 270;
				cout << "4";
			}
			break;
	}
}



int main(int argc, char **argv)
 {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GilbertJFM 52419624");
    
    glutDisplayFunc(titik);
    
	glutTimerFunc(1, timer, 0);
	glutMainLoop();	
	return 0;                      
}
