#include "Cube.h"
#include <time.h>
#include "exception"

#define CUBE_SIZE 13
#define TIMER 10

unsigned int c[9] = {0xFFFFFF, 0xFFFF00, 0x0000FF, 0x00FF00, 0xFF0000, 	0xFF7C00};


GLfloat lightPos[] = {0, 100, 200, 0}; 

int xRot = 24, yRot = 34, zRot = 0;

double translateZ = -35.0;

Cube_3D cube;

int timerOn = 0;
Cube cube_2D;


void display() {
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glTranslatef(0, 0, translateZ);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glTranslatef(CUBE_SIZE / -2.0, CUBE_SIZE / -2.0, CUBE_SIZE / -2.0);
	cube.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat fAspect = (GLfloat)w/(GLfloat)h;
    gluPerspective(60, fAspect, 1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	srand(time(0));


	float mat_specular[] = {0.3, 0.3, 0.3, 0};
	float diffuseLight[] = {0.2, 0.2, 0.2, 1};
	float ambientLight[] = {0.9, 0.9, 0.9, 1.0};
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	cube.clear(CUBE_SIZE, c);
}

void specialKeys(int key, int, int)
{

	if (key == GLUT_KEY_DOWN) {
		xRot += 3;
		if (xRot >= 360)
			xRot -= 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_UP) {
		xRot -= 3;
		if (xRot < 0)
			xRot += 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_RIGHT) {
		yRot += 3;
		if (yRot >= 360)
			yRot -= 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_LEFT) {
		yRot -= 3;
		if (yRot < 0)
			yRot += 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_F2) {
		translateZ += 5;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_F3) {
		translateZ -= 5;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_F1) {
		cube.clear(CUBE_SIZE, c);
		glutPostRedisplay();
	}
    
    if (key == GLUT_KEY_F4) {
        cube.set_from_file(CUBE_SIZE, cube_2D, c);
        glutPostRedisplay();
    }
    if (key == GLUT_KEY_F7) {
        cube.change_point_of_view_right();
        glutPostRedisplay();
    }
    
    if (key == GLUT_KEY_F5) {
        Solution_of_Rubics_cube::solve(cube_2D);
        cube_2D.get_right_answer();
        for (char v : cube_2D.get_right_answer_3D())
            std::cout << v;
        
        int i = 0;
        while (i < cube_2D.get_right_answer_3D().size()) {
            if (cube.current == -1) {
                cube.Rotate(cube_2D.get_right_answer_3D()[i] - '0', 3);
                display();
                cube.set_current();
            }
            i++;
        }
        glutPostRedisplay();
    }
}

void keys(unsigned char key, int, int) {
	
	if (cube.current == -1 && key >= '0' && key < '7') {
		cube.Rotate(key - '0', 3);
		display();
	}
}

void mouse(int key, int state, int, int)
{
	if (key == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		timerOn = 1 - timerOn;
	}
}

void timer(int)
{
	glutTimerFunc(TIMER, timer, 0);
	if (timerOn) {
		if (cube.current == -1)
			keys(rand() % 6 + '0', 0, 0);
		else
			cube.Rotate(cube.current, 3);
	}
	else
	{
		if (cube.current != -1)
			cube.Rotate(cube.current, 3);
	}
	display();
}

int main(int argc, char **argv) {
    cube_2D.input("input.txt");
    try {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(1, 1);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	glutTimerFunc(TIMER, timer, 0);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
    }catch(Cube_exception &ex) {
        std::cout << ex.what() << std::endl;
    }
	return 0;
}

