#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{	
	option = 1;
	rotation = 0.0f;
	cameraSpeed = 0.1f;
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glutWireCube(1);
//	DrawPolygon();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void HelloGL::DrawPolygon()
{
		glBegin(GL_POLYGON);
		{
			glVertex2f(-0.75, 0.5);
			glVertex2f(0.75, 0.5);
			glVertex2f(0.75, -0.5);
			glVertex2f(-0.75, -0.5);
			glEnd();
		}
}

void HelloGL::Update() 
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
	if (rotation >= 360.0f) {
		rotation = 0.0f;
	}
}

void HelloGL::Keyboard(unsigned char key, int x, int y) 
{
	if (key == 'd') {
		rotation += 0.5f;
	}
	if (key == 'a') {
		rotation -= 0.5f;
	}
	if (key == ' ') {
		if (option < 3) {
			option += 1;
			if (option == 2) {
				std::cout << "camera center selected";
			}
			else if (option == 3) {
				std::cout << "camera up selected";
			}
		}
		else if (option == 3) {
			option = 1; 
			std::cout << "camera eye selected";
		}
	}
	if (key == 'j') {
		if (option == 1) {
			camera->eye.x += cameraSpeed;
		}
		else if (option == 2) {
			camera->center.x += cameraSpeed;
		}
		else if (option == 3) {
			camera->up.x += cameraSpeed;
		}
	}
	if (key == 'l') {
		if (option == 1) {
			camera->eye.x -= cameraSpeed;
		}
		else if (option == 2) {
			camera->center.x -= cameraSpeed;
		}
		else if (option == 3) {
			camera->up.x -= cameraSpeed;
		}
	}
	if (key == 'i') {
		if (option == 1) {
			camera->eye.y += cameraSpeed;
		}
		else if (option == 2) {
			camera->center.y += cameraSpeed;
		}
		else if (option == 3) {
			camera->up.y += cameraSpeed;
		}
	}
	if (key == 'k') {
		if (option == 1) {
			camera->eye.y -= cameraSpeed;
		}
		else if (option == 2) {
			camera->center.y -= cameraSpeed;
		}
		else if (option == 3) {
			camera->up.y -= cameraSpeed;
		}
	}
	if (key == 'n') {
		if (option == 1) {
			camera->eye.z += cameraSpeed;
		}
		else if (option == 2) {
			camera->center.z += cameraSpeed;
		}
		else if (option == 3) {
			camera->up.z += cameraSpeed;
		}
	}
	if (key == 'm') {
		if (option == 1) {
			camera->eye.z -= cameraSpeed;
		}
		else if (option == 2) {
			camera->center.z -= cameraSpeed;
		}
		else if (option == 3) {
			camera->up.z -= cameraSpeed;
		}
	}
}

HelloGL::~HelloGL(void) 
{
	delete camera;
}