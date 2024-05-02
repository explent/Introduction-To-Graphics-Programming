#include "HelloGL.h"
#include "Structures.h"
#include "MeshLoader.h"

HelloGL::HelloGL(int argc, char* argv[])
{	
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT /* | GL_DEPTH_BUFFER_BIT */ );
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i < 29; i++) {
		cube[i]->Draw();
	}	
	//cube[0]->Draw();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update() 
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
	if (rotation >= 360.0f) {
		rotation = 0.0f;
	}
	for (int i = 0; i < 29; i++) {
		cube[i]->Update();
	}
	//cube[199]->Update();
}

void HelloGL::InitObjects() {
	Teapot::Load((char*)"teapt.txt");
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	option = 1;
	rotation = 0.0f;
	cameraSpeed = 0.1f;
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 10.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	//for (int i = 0; i < 199; i++) {
	//	teapot[i] = new Teapot(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	//}
	for (int i = 0; i < 29; i++) {
		cube[i] = new Cube(cubeMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	//cube[0] = new Cube(cubeMesh,0.0f,0.0f,0.0f);
	//cube[1] = new Cube(cubeMesh, 2.0f, 0.0f, 0.0f);
}

void HelloGL::InitGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE /*| GL_DEPTH*/);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	//glMatrixMode(GL_MODELVIEW);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 50, 1000);
	glMatrixMode(GL_MODELVIEW);
	//	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
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
	delete[] cube;
	delete[] teapot;
}