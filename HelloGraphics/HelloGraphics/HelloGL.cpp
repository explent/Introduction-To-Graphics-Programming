#include "HelloGL.h"
#include "Structures.h"
#include "MeshLoader.h"

HelloGL::HelloGL(int argc, char* argv[])
{	
	InitGL(argc, argv);
	InitObjects();
	InitLight();
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT /* | GL_DEPTH_BUFFER_BIT */ );




	int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	float centerX = windowWidth / 2.0f;
	float centerY = windowHeight / 2.0f;
	Color c = { 1.0f, 1.0f, 1.0f };
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i < 3; i++) {
		objects[i]->Draw();
	}	
	DrawString((char*)"OpenGLProgram", 20, 770, &c);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	std::cout << *GLUTCallbacks::Timer;
}

void HelloGL::Update() 
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	glutPostRedisplay();
	if (rotation >= 360.0f) {
		rotation = 0.0f;
	}
	for (int i = 0; i < 3; i++) {
		objects[i]->Update();
	}
}

void HelloGL::InitObjects() {
	Teapot::Load((char*)"teapt.txt");
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Penguins.raw", 512, 512);
	option = 1;
	rotation = 0.0f;
	cameraSpeed = 0.1f;
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 10.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	/*for (int i = 0; i < 199; i++) {
		teapot[i] = new Teapot(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}*/
	for (int i = 0; i < 3; i++) {
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
		}
	/*for (int i = 30; i < 60; i++) {
		objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}*/
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
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void HelloGL::InitLight() {
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8; 
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

void HelloGL::DrawString(const char* text, float x, float y, Color* color) {
	glColor3f(color->r, color->g, color->b);

	// Save the current matrix state
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	// Set up orthographic projection
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT), -1, 1);

	// Switch back to modelview matrix mode
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Set the text position
	glRasterPos2f(x, y);

	// Render the text
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	// Restore the matrix state
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
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
	delete[] objects;
	delete[] teapot;
}