#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;
void timer(int);
float y = 0;
float z = 0;

float l1 = 0;
float l2 = 0;
float l1a = 0.0095;
float l2a = 0.0005;

float l3, l4;
float l3a = 0.0005;
float l4a = 0.0095;

float l5, l6;
float l5a = 0.0095;
float l6a = 0.0005;

float l7, l8;
float l7a = 0.0005;
float l8a = 0.0095;

int i = 0;
int j = 0;
int k = 0;
int status = 1;
int status2 = 1;
int status3 = 1;
int statusx1 = 1;
int statusx2 = 1;
int statusx3 = 3;
int statusx4 = 4;
float r1, r2, r3;
 
void kotak ()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5, 0.5 + y);
		glVertex2f(0.5, 0.5 + y);
		glVertex2f(0.5, -0.5 + y);
		glVertex2f(-0.5, -0.5 + y);
	glEnd();
	
	glColor3f(0 + r1, 0 + r2, 0 + r3);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5, 0.5 + z);
		glVertex2f(0.5, 0.5 + z);
		glVertex2f(0.5, -0.5 + z);
		glVertex2f(-0.5, -0.5 + z);
	glEnd();
	
	glFlush();
	glutSwapBuffers(); 
}

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
		glVertex2f(0 +l1 , -0.5 + l2);
	glEnd();
	
	glColor3f(0.64, 0.36, 0.36);
	glPointSize(2.5);
	glBegin(GL_POINTS);
		glVertex2f(0.5 + l3 , 0 + l4);
	glEnd();	
	
		glColor3f(0.29, 0.23, 0.22);
	glPointSize(2.5);
	glBegin(GL_POINTS);
		glVertex2f(0 + l5 , 0.5 + l6);
	glEnd();
	
		glColor3f(0.93, 0.93, 0.93);
	glPointSize(2.5);
	glBegin(GL_POINTS);
		glVertex2f(-0.5 + l7 , 0 + l8);
	glEnd();
	
	glFlush();
	glutSwapBuffers(); 
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(200, timer, 0);
	
	switch(status){
		case 1:
			if(y < 0.4)
				y = y + 0.05;
			else
				status = -1;
			break;
		case -1:
			if(y > -0.4)
				y = y - 0.05;
			else
				status = 1;
			break;
	}
}

void timer1(int)
{
	glutPostRedisplay();
	glutTimerFunc(50, timer1, 0);
	
	switch(status3){
		case 1:
			r1 = 0;
			r2 = 0;
			r3 = 1;
			
			for(int i=0; i < 10; i++){
				r1 = r1 + 0.1;
				r3 = r3 - 0.1;
			}
			
			status3 = 2;

		case 2:
			r1 = 1;
			r2 = 1;
			r3 = 1;
			
		case 3:
			r1 = 0;
			r2 = 1;
			r3 = 0;
			
	}
	
	switch(status2){
		case 1:
			if(z < 0.4)
				z = z + 0.0125;
			else
				status2 = -1;
			break;
		case -1:
			if(z > -0.4)
				z = z - 0.0125;
			else
				status2 = 1;
			break;
	}
}

void timera(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, timera, 0);
	
	switch (statusx1) {
	case 1:
		l1 = l1 + l1a;
		l1a = l1a - 0.00009090909;
		l2 = l2 + l2a;
		l2a = l2a + 0.00009090909;
		
		if (l1a < 0.00049){
			cout << "\nDivisi 1 done";
			cout << " l1 = " << l1;
			cout << " l2 = " << l2;
			cout << "\n\n";
			statusx1 = 2;
			
			l1a = 0.0005;
			l2a = 0.0095;
		}		
		break;
	case 2:
		l1 = l1 - l1a;
		l1a = l1a + 0.00009090909;
		l2 = l2 + l2a;
		l2a = l2a - 0.00009090909;

		if (l2a < 0.00049){
			cout << "\nDivisi 2 done";
			cout << " l1 = " << l1;
			cout << " l2 = " << l2;
			cout << "\n\n";
			statusx1 = 3;
			
			l1a = 0.0095;
			l2a = 0.0005;
		}
		break;
	case 3:
		l1 = l1 - l1a;
		l1a = l1a - 0.00009090909;
		l2 = l2 - l2a;
		l2a = l2a + 0.00009090909;

		if (l1a < 0.00049){
			cout << "\nDivisi 3 done";
			cout << " l1 = " << l1;
			cout << " l2 = " << l2;
			cout << "\n\n";			
			statusx1 = 4;
			
			l1a = 0.0005;
			l2a = 0.0095;
		}
		break;
	case 4:
		l1 = l1 + l1a;
		l1a = l1a + 0.00009090909;
		l2 = l2 - l2a;
		l2a = l2a - 0.00009090909;
		
		if (l2a < 0.00049){
			cout << "\nDivisi 4 done";
			cout << " l1 = " << l1;
			cout << " l2 = " << l2;
			cout << "\n\n";			
			statusx1 = 1;
			
			l1a = 0.0095;
			l2a = 0.0005;
		}
		break;		
	}
}

void timerb(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, timerb, 0);
	
	switch (statusx2) {
	case 1:
		l3 = l3 - l3a;
		l3a = l3a + 0.00009090909;
		l4 = l4+ l4a;
		l4a = l4a - 0.00009090909;
		
		if (l4a < 0.00049){
			cout << "\nDivisi B1 done";
			cout << " l3 = " << l3;
			cout << " l4 = " << l4;
			cout << "\n\n";
			statusx2 = 2;

			l3a = 0.0095;
			l4a = 0.0005;
		}		
		break;
	case 2:
		l3 = l3 - l3a;
		l3a = l3a - 0.00009090909;
		l4 = l4 - l4a;
		l4a = l4a + 0.00009090909;
		
		if (l3a < 0.00049){
			cout << "\nDivisi B2 done";
			cout << " l3 = " << l3;
			cout << " l4 = " << l4;
			cout << "\n\n";
			statusx2 = 3;

			l3a = 0.0005;
			l4a = 0.0095;
		}
		break;
	case 3:
		l3 = l3 + l3a;
		l3a = l3a + 0.00009090909;
		l4 = l4 - l4a;
		l4a = l4a - 0.00009090909;
		
		if (l4a < 0.00049){
			cout << "\nDivisi B3 done";
			cout << " l3 = " << l3;
			cout << " l4 = " << l4;
			cout << "\n\n";			
			statusx2 = 4;
			
			l3a = 0.0095;
			l4a = 0.0005;
		}
		break;
	case 4:
		l3 = l3 + l3a;
		l3a = l3a - 0.00009090909;
		l4 = l4 + l4a;
		l4a = l4a + 0.00009090909;
		
		if (l3a < 0.00049){
			cout << "\nDivisi 4 done";
			cout << " l3 = " << l3;
			cout << " l4 = " << l4;
			cout << "\n\n";			
			statusx2 = 1;
			l3a = 0.0005;
			l4a = 0.0095;
		}
		break;		
	}
}

void timerc(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, timerc, 0);
	
	switch (statusx3) {
	case 1:
		l5 = l5 + l5a;
		l5a = l5a - 0.00009090909;
		l6 = l6 + l6a;
		l6a = l6a + 0.00009090909;
		
		if (l5a < 0.00049){
			cout << "\nDivisi C1 done";
			cout << " l5 = " << l5;
			cout << " l6 = " << l6;
			cout << "\n\n";
			statusx3 = 2;
			
			l5a = 0.0005;
			l6a = 0.0095;
		}		
		break;
	case 2:
		l5 = l5 - l5a;
		l5a = l5a + 0.00009090909;
		l6 = l6 + l6a;
		l6a = l6a - 0.00009090909;

		if (l6a < 0.00049){
			cout << "\nDivisi C2 done";
			cout << " l5 = " << l5;
			cout << " l6 = " << l6;
			cout << "\n\n";
			statusx3 = 3;
			
			l5a = 0.0095;
			l6a = 0.0005;
		}
		break;
	case 3:
		l5 = l5 - l5a;
		l5a = l5a - 0.00009090909;
		l6 = l6 - l6a;
		l6a = l6a + 0.00009090909;

		if (l5a < 0.00049){
			cout << "\nDivisi C3 done";
			cout << " l5 = " << l5;
			cout << " l6 = " << l6;
			cout << "\n\n";			
			statusx3 = 4;
			
			l5a = 0.0005;
			l6a = 0.0095;
		}
		break;
	case 4:
		l5 = l5 + l5a;
		l5a = l5a + 0.00009090909;
		l6 = l6 - l6a;
		l6a = l6a - 0.00009090909;
		
		if (l6a < 0.00049){
			cout << "\nDivisi C4 done";
			cout << " l5 = " << l5;
			cout << " l6 = " << l6;
			cout << "\n\n";			
			statusx3 = 1;
			
			l5a = 0.0095;
			l6a = 0.0005;
		}
		break;		
	}
}

void timerd(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, timerd, 0);
	
	switch (statusx4) {
	case 1:
		l7 = l7 + l7a;
		l7a = l7a - 0.00009090909;
		l8 = l8 + l8a;
		l8a = l8a + 0.00009090909;
		
		if (l7a < 0.00049){
			cout << "\nDivisi D1 done";
			cout << " l7 = " << l7;
			cout << " l8 = " << l8;
			cout << "\n\n";
			statusx4 = 2;
			
			l7a = 0.0005;
			l8a = 0.0095;
		}		
		break;
	case 2:
		l7 = l7 - l7a;
		l7a = l7a + 0.00009090909;
		l8 = l8 + l8a;
		l8a = l8a - 0.00009090909;

		if (l8a < 0.00049){
			cout << "\nDivisi D2 done";
			cout << " l7 = " << l7;
			cout << " l8 = " << l8;
			cout << "\n\n";
			statusx4 = 3;
			
			l7a = 0.0095;
			l8a = 0.0005;
		}
		break;
	case 3:
		l7 = l7 - l7a;
		l7a = l7a - 0.00009090909;
		l8 = l8 - l8a;
		l8a = l8a + 0.00009090909;

		if (l7a < 0.00049){
			cout << "\nDivisi D3 done";
			cout << " l7 = " << l7;
			cout << " l8 = " << l8;
			cout << "\n\n";			
			statusx4 = 4;
			
			l7a = 0.0005;
			l8a = 0.0095;
		}
		break;
	case 4:
		l7 = l7 + l7a;
		l7a = l7a + 0.00009090909;
		l8 = l8 - l8a;
		l8a = l8a - 0.00009090909;
		
		if (l8a < 0.00049){
			cout << "\nDivisi D4 done";
			cout << " l7 = " << l7;
			cout << " l8 = " << l8;
			cout << "\n\n";			
			statusx4 = 1;
			
			l7a = 0.0095;
			l8a = 0.0005;
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
 
    glutTimerFunc(250, timer, 0);
    glutTimerFunc(1, timer1, 0);
    
    glutDisplayFunc(titik);
    
	glutTimerFunc(1, timera, 0);
	glutTimerFunc(1, timerb, 0);
    glutTimerFunc(1, timerc, 0);
    glutTimerFunc(1, timerd, 0);
	glutMainLoop();	
	return 0;                      
}
