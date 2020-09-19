#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include "Vector3.h"
#include <mmsystem.h>
#include <conio.h>
#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "Jaegers (Chan Kar Yong & Poh Chong Sien)"

int weapon = 1;
int robotAppearance = 1;
double riverflow = 0, riverflowDirection=0.5;
boolean shield = true;
boolean music = true;
boolean nightmode = true;
int animation = 999;
int animationSwitch = 1;
int questionnumber = 1;
int changeview = 1;
int direction = 0;
double face = 0;
int lightswitch = 1;

double size = 0.01;
double sizeX = 0.0;
double sizeY = 0.0;

double posX = 2;
double posY = -15.5;
double posZ = -25;

double walk1 = -1.2;
double walk2 = -1.2;
double walk3 = 1.2;
double walk4 = -1.2;
double walk6 = -0.6;
double walk8 = 0.6;

double robotX = 0;
double robotY = 0;
double robotZ = 0;
double moveX = 0;
double moveY = 0;
double moveZ = 0;

double animationMoveX = 0;
double animationMoveY = 0;
double animationMoveZ = 0;

double missileY = 0;

float lightx = 0;
float lighty = 11;
float lightz = 5;

double rotation = 0;
double rotate = 0.2;
double rotateX = 0;
double rotateY = 0;
double rotateZ = 0;

double rotateX1 = 0;
double rotateY1 = 0;
double rotateZ1 = 0;
double rotateX2 = 0;
double rotateY2 = 0;
double rotateZ2 = 0;
double rotateX3 = 0;
double rotateY3 = 0;
double rotateZ3 = 0;
double rotateX4 = 0;
double rotateY4 = 0;
double rotateZ4 = 0;
double rotateX5 = 0;
double rotateY5 = 0;
double rotateZ5 = 0;
double rotateX6 = 0;
double rotateY6 = 0;
double rotateZ6 = 0;
double rotateX7 = 0;
double rotateY7 = 0;
double rotateZ7 = 0;
double rotateX8 = 0;
double rotateY8 = 0;
double rotateZ8 = 0;
double rotateX9 = 0;
double rotateY9 = 0;
double rotateZ9 = 0;
double rotateX10 = 0;
double rotateY10 = 0;
double rotateZ10 = 0;

double rotateX0 = 0;
double rotateY0 = 0;
double rotateZ0 = 0;

float radius = 0.25;
int slices = 20;
int stacks = 20;


float baseRadius = 0.01;
float topRadius = 0.3;
float height = 0.8;

Vector3 vec1,vec2,vec3,vec4,vnormal;


GLUquadricObj* myQuadricObject = gluNewQuadric();

GLfloat lightdiffusecolour[] = { 1,1,1,0 };
GLfloat mediumdiffusecolour[] = { 0.7,0.7,0.7,0 };
GLfloat darkdiffusecolour[] = { 0.2,0.2,0.2,0 };
GLfloat reddiffusecolour[] = { 0.6,0.2,0.2,0 };

BITMAP BMP;

HBITMAP hBMP = NULL;

GLuint texture = 1;

BITMAP BMP_lightsky, BMP_orange, BMP_forehandside1, BMP_forehand1, BMP_chest1, BMP_chestback1, BMP_stomachback1, BMP_stomach1, BMP_shoulder1, BMP_shoulderback1, BMP_pyramid, BMP_yellowstar, BMP_clock, BMP_clockbuilding, BMP_treetrunk, BMP_treecolour, BMP_riverflow, BMP_riverflow2, BMP_riverflow3, BMP_housewindow, BMP_housecolour, BMP_swordcolour, BMP_blank, BMP_blue, BMP_chest, BMP_chestback, BMP_foot, BMP_footback, BMP_forehand, BMP_forehandside, BMP_handsome, BMP_knee, BMP_knee2, BMP_knee2back, BMP_knee3, BMP_lightgrey, BMP_red, BMP_shoulder, BMP_shoulderback, BMP_stomach, BMP_stomachback, BMP_thigh, BMP_toe, BMP_tyre, BMP_tyrestrip, BMP_wraist, BMP_darkgrey, BMP_mask, BMP_gem, BMP_yellow, BMP_chestbackdeco1, BMP_chestbackdeco2, BMP_sixpack, BMP_sky, BMP_grass, BMP_mountain;

GLuint tex_lightsky = 1, tex_orange = 1, tex_forehandside1 = 1, tex_forehand1 = 1, tex_chest1 = 1, tex_chestback1 = 1, tex_stomachback1 = 1, tex_stomach1 = 1, tex_shoulder1 = 1, tex_shoulderback1 = 1, tex_pyramid = 1, tex_yellowstar = 1, tex_clock = 1, tex_clockbuilding = 1, tex_treetrunk = 1, tex_treecolour = 1, tex_riverflow = 1, tex_riverflow2 = 1, tex_riverflow3 = 1, tex_housewindow = 1, tex_housecolour, tex_swordcolour = 1, tex_blank = 1, tex_blue = 1, tex_chest = 1, tex_chestback = 1, tex_foot = 1, tex_footback = 1, tex_forehand = 1, tex_forehandside = 1, tex_handsome = 1, tex_knee = 1, tex_knee2 = 1, tex_knee2back = 1, tex_knee3 = 1, tex_lightgrey = 1, tex_red = 1, tex_shoulder = 1, tex_shoulderback = 1, tex_stomach = 1, tex_stomachback = 1, tex_thigh = 1, tex_toe = 1, tex_tyre = 1, tex_tyrestrip = 1, tex_wraist = 1, tex_darkgrey = 1, tex_mask = 1, tex_gem = 1, tex_yellow = 1, tex_chestbackdeco1 = 1, tex_chestbackdeco2 = 1, tex_sixpack = 1, tex_sky = 1, tex_grass = 1, tex_mountain = 1;

void resetAnimation();

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			PostQuitMessage(0);
			break;
		}
		case VK_LEFT:
		{
			if (animationSwitch == 1) {
				animation = 999;
			direction = 1;
			face = 90;

			rotateX1 = 30;
			rotateX2 = 30;
			rotateX3 = -30;
			rotateX4 = 30;
			rotateX6 = 15;
			rotateX8 = -15;
			}
			

			break;
		}
		case VK_DOWN:
		{
			if (animationSwitch == 1) {
				animation = 999;
				direction = 2;
				face = 180;

				rotateX1 = 30;
				rotateX2 = 30;
				rotateX3 = -30;
				rotateX4 = 30;
				rotateX6 = 15;
				rotateX8 = -15;
			}
			
			break;
		}
		case VK_RIGHT:
		{
			if (animationSwitch == 1) {
				animation = 999;
				direction = 3;
				face = 270;

				rotateX1 = 30;
				rotateX2 = 30;
				rotateX3 = -30;
				rotateX4 = 30;
				rotateX6 = 15;
				rotateX8 = -15;
			}
			
			break;
		}
		case VK_UP:
		{
			if (animationSwitch == 1) {
				animation = 999;
				direction = 4;
				face = 0;

				rotateX1 = 30;
				rotateX2 = 30;
				rotateX3 = -30;
				rotateX4 = 30;
				rotateX6 = 15;
				rotateX8 = -15;
			}
			
			break;
		}
		
		case VK_SPACE:
		{
			if (nightmode)
				nightmode = false;
			else
				nightmode = true;
			break;
		}
		case 0x57:
		{
			//W
			lighty += 0.39;
			break;
		}
		case 0x41:
		{
			//A
			lightx -= 0.39;
			break;
		}
		case 0x53:
		{
			//S
			lighty -= 0.39;
			break;

		}
		case 0x44:
		{
			//D
			lightx += 0.39;
			break;
		}

		case 0x45:
		{
			//E
			lightz += 0.39;
			break;
		}

		case 0x51:
		{
			//Q
			lightz -= 0.39;
			break;
		}

		case 0x49:
		{
			//I
			posY -= 0.2;
			break;
		}
		case 0x4A:
		{
			//J
			posX += 0.2;
			break;
		}
		case 0x4B:
		{
			//K
			posY += 0.2;
			break;

		}
		case 0x4C:
		{
			//L
			posX -= 0.2;
			break;
		}

		case VK_PRIOR:
		{
			//PGUP
			posZ += 0.2;
			break;
		}

		case VK_NEXT:
		{
			//PGDN
			posZ -= 0.2;
			break;
		}
		case 0x4F:
		{
			//O
			rotateY += 2;
			break;
		}
		case 0x55:
		{
			//U
			rotateY -= 2;
			break;
		}
		case 0x47:
		{
			//G
			posZ += 1;
			break;
		}
		case 0x48:
		{
			//H
			posZ -= 1;
			break;
		}
		case 0x56:
		{
			//V
			//Change view
			if (changeview == 1) {
				glLoadIdentity();

				//glOrtho(-10, 10, -10, 10, -10, 10);
				gluPerspective(45, 1, 0.1, 300);
				changeview = 0;
			}
			else {
				glLoadIdentity();

				glOrtho(-10, 10, -10, 10, 10, 300);
				changeview = 1;
			}
			
		}
		case 0x30:
		{
			//0
			animation = 0;
			resetAnimation();
			break;
		}

		case 0x31:
		{
			//1
			if (animationSwitch == 1) {
				weapon = 1;
			}
			
			break;
		}
		case 0x32:
		{
			//2
			if (animationSwitch == 1) {
				weapon = 2;
			}
			break;
		}
		case 0x33:
		{
			//3
			if (!shield)
				shield = true;
			else
				shield = false;
			break;
		}
		case 0x34:
		{
			//4
			break;
		}
		case 0x35:
		{
			//5
			break;
		}
		case 0x36:
		{
			//6
			break;
		}
		case 0x37:
		{
			//7
			break;
		}
		case 0x38:
		{
			if (robotAppearance == 1)
				robotAppearance = 2;
			else
				robotAppearance = 1;
			break;
		}
		case 0x39:
		{
			if (music) {
				music = false;
				PlaySound("BackgroundMusic.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			}
			else {
				music = true;
	
				PlaySound(NULL, NULL, SND_SYNC);
				//PlaySound(NULL, NULL, SND_ASYNC);
			}
			break;
		}
		case 0x42:
		{
			if (lightswitch == 1) {
				lightswitch = 0;
			}
			else {
				lightswitch = 1;
			}
			
			break;
		}
		//test rotate
		case 0x58:
		{
			//X
			direction = 0;
			break;
		}
		case 0x59:
		{
			//Y
			break;
		}
		case 0x5A:
		{
			//Z
			direction = 0;
			

			if (weapon == 1) {
				//9
				if (animationSwitch == 0) {

					animationSwitch = 1;
				}
				else {
					resetAnimation();
					rotateX6 = 180;
					rotateX7 = 300;
					rotateY5 = -30;
					rotateX8 = 340;
					rotateX9 = 275;
					rotateZ9 = 335;
					animationSwitch = 0;
				}

				animation = 9;
			}
			if (weapon == 2) {
				//8
				if (animationSwitch == 0) {

					animationSwitch = 1;
				}
				else {
					resetAnimation();
					missileY = 0;
					animationSwitch = 0;
				}

				animation = 8;
			}
			
			break;
		}
		}
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

Vector3 crossProduct(Vector3 v1, Vector3 v2);

Vector3 getSurfaceNormal(Vector3 v1, Vector3 v2, Vector3 v3);

void walkAnimation();



void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------

//drive.google.com/file/d/1_b70g9WnD2wyRY2dmDR8pa1-zt7CXTwF/view?usp=sharing
//openinggl.blogspot.com/2012/04/adding-lighting-normals.html


	switch (questionnumber)
	{
	case 1:
	{	
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		GLfloat lightposition[] = { lightx,lighty,lightz ,0 };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);
		glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
		gluQuadricDrawStyle(myQuadricObject, GLU_FILL);
		
		
		glPushMatrix();

		

		glRotatef(rotateX, 1, 0, 0);
		glRotatef(rotateY, 0, 1, 0);
		glRotatef(rotateZ, 0, 0, 1);

		glTranslatef(posX, posY, posZ);
		glPushMatrix();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, tex_blank);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blank.bmWidth, BMP_blank.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blank.bmBits);

		glColor3f(1, 1, 0);
		glTranslatef(lightx, lighty, lightz);
		gluSphere(myQuadricObject, 0.5, slices, stacks);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glPopMatrix();

		
		glLightfv(GL_LIGHT0, GL_DIFFUSE, darkdiffusecolour);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		glBindTexture(GL_TEXTURE_2D, tex_grass);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_grass.bmWidth, BMP_grass.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_grass.bmBits);


		//Grass
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 5.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, 100.0f);
		glTexCoord2f(5.0f, 0.0f); glVertex3f(100.0f, 0.0f, 100.0f);
		glTexCoord2f(5.0f, 5.0f); glVertex3f(100.0f, 0.0f, -100.0f);
		glEnd();
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		//sky
		if (nightmode) {
			glBindTexture(GL_TEXTURE_2D, tex_sky);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_sky.bmWidth, BMP_sky.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_sky.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_lightsky);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightsky.bmWidth, BMP_lightsky.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightsky.bmBits);
		}


		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 150.0f, -100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 150.0f, -100.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 150.0f, 100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 150.0f, 100.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 150.0f, -100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 150.0f, 100.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 150.0f, -100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 150.0f, 100.0f);
		glEnd();

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, mediumdiffusecolour);


		riverflow += riverflowDirection;
		if (riverflow < 7 && riverflow >=0) {
			
			glBindTexture(GL_TEXTURE_2D, tex_riverflow);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_riverflow.bmWidth, BMP_riverflow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_riverflow.bmBits);
		}
		else if (riverflow >= 7&&riverflow<13) {
			
			glBindTexture(GL_TEXTURE_2D, tex_riverflow2);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_riverflow2.bmWidth, BMP_riverflow2.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_riverflow2.bmBits);
		}
		else if (riverflow >= 13&&riverflow <19) {
			glBindTexture(GL_TEXTURE_2D, tex_riverflow3);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_riverflow3.bmWidth, BMP_riverflow3.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_riverflow3.bmBits);
			
		} else if (riverflow == 19) {
			glBindTexture(GL_TEXTURE_2D, tex_riverflow3);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_riverflow3.bmWidth, BMP_riverflow3.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_riverflow3.bmBits);
			riverflowDirection = -0.5;
		} else if (riverflow <0) {
			glBindTexture(GL_TEXTURE_2D, tex_riverflow);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_riverflow.bmWidth, BMP_riverflow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_riverflow.bmBits);
			riverflowDirection = 0.5;
		}
		//River at the far
		glPushMatrix();

		//back
		glTranslatef(0, 0, 0);
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-120.0f, 0.0f, -120.0f);
		glVertex3f(-120.0f, 0.0f, -70.0f);
		glVertex3f(120.0f, 0.0f, -70.0f);
		glVertex3f(120.0f, 0.0f, -120.0f);
		glEnd();

		//river thickness
		//front
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-120.0f, 1.5f, -70.0f);
		glVertex3f(-120.0f, 0.0f, -70.0f);
		glVertex3f(120.0f, 0.0f, -70.0f);
		glVertex3f(120.0f, 1.5f, -70.0f);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-120.0f, 1.5f, -120.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-120.0f, 1.5f, -70.0f);
		glTexCoord2f(10.0f, 0.0f); glVertex3f(120.0f, 1.5f, -70.0f);
		glTexCoord2f(10.0f, 1.0f); glVertex3f(120.0f, 1.5f, -120.0f);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		//back to front river
		glTranslatef(0, 0, 0);
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-50.0f, 0.0f, -70.0f);
		glVertex3f(-50.0f, 0.0f, 120.0f);
		glVertex3f(-30.0f, 0.0f, 120.0f);
		glVertex3f(-30.0f, 0.0f, -70.0f);
		glEnd();
		//river thickness
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-30.0f, 1.5f, -70.0f);
		glVertex3f(-30.0f, 0.0f, -70.0f);
		glVertex3f(-30.0f, 0.0f, 120.0f);
		glVertex3f(-30.0f, 1.5f, 120.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-50.0f, 1.5f, -70.0f);
		glVertex3f(-50.0f, 0.0f, -70.0f);
		glVertex3f(-50.0f, 0.0f, 120.0f);
		glVertex3f(-50.0f, 1.5f, 120.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 10.0f); glVertex3f(-50.0f, 1.5f, -70.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-50.0f, 1.5f, 120.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-30.0f, 1.5f, 120.0f);
		glTexCoord2f(1.0f, 10.0f); glVertex3f(-30.0f, 1.5f, -70.0f);
		glEnd();
		glPopMatrix();

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);

		//sky
		glBindTexture(GL_TEXTURE_2D, tex_sky);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_sky.bmWidth, BMP_sky.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_sky.bmBits);

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 150.0f, -100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 150.0f, -100.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 150.0f, 100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 150.0f, 100.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 150.0f, -100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 150.0f, 100.0f);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 150.0f, -100.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, 0.0f, -100.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 0.0f, 100.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 150.0f, 100.0f);
		glEnd();

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);

		//-------------------------------- Buidling --------------------------------------------------

		//Tall building-----------------------
		glBindTexture(GL_TEXTURE_2D, tex_housecolour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_housecolour.bmWidth, BMP_housecolour.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_housecolour.bmBits);
		//-------Buidling 1-------------
		//Front 
		vec1 = { -20.9f, 30.09f, -55.6f };
		vec2 = { -20.9f, 0.0f, -55.6f };
		vec3 = { -13.9f, 0.0f, -55.6f };
		vec4 = { -13.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -20.9f, 30.09f, -62.6f };
		vec2 = { -20.9f, 0.0f, -62.6f };
		vec3 = { -13.9f, 0.0f, -62.6f };
		vec4 = { -13.9f, 30.09f, -62.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -20.9f, 30.09f, -62.6f };
		vec2 = { -20.9f, 0.0f, -62.6f };
		vec3 = { -20.9f, 0.0f, -55.6f };
		vec4 = { -20.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -13.9f, 30.09f, -62.6f };
		vec2 = { -13.9f, 0.0f, -62.6f };
		vec3 = { -13.9f, 0.0f, -55.6f };
		vec4 = { -13.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -13.9f, 30.09f, -62.6f };
		vec2 = { -20.9f, 30.09f, -62.6f };
		vec3 = { -20.9f, 30.09f, -55.6f };
		vec4 = { -13.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//-------Buidling 2-------------
		//Front 
		vec1 = { -13.9f, 20.09f, -55.6f };
		vec2 = { -13.9f, 0.0f, -55.6f };
		vec3 = { -6.9f, 0.0f, -55.6f };
		vec4 = { -6.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -13.9f, 20.09f, -62.6f };
		vec2 = { -13.9f, 0.0f, -62.6f };
		vec3 = { -6.9f, 0.0f, -62.6f };
		vec4 = { -6.9f, 20.09f, -62.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -13.9f, 20.09f, -62.6f };
		vec2 = { -13.9f, 0.0f, -62.6f };
		vec3 = { -13.9f, 0.0f, -55.6f };
		vec4 = { -13.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -6.9f, 20.09f, -62.6f };
		vec2 = { -6.9f, 0.0f, -62.6f };
		vec3 = { -6.9f, 0.0f, -55.6f };
		vec4 = { -6.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -6.9f, 20.09f, -62.6f };
		vec2 = { -13.9f, 20.09f, -62.6f };
		vec3 = { -13.9f, 20.09f, -55.6f };
		vec4 = { -6.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//-------Buidling 3-------------
		//Front 
		vec1 = { -6.9f, 30.09f, -55.6f };
		vec2 = { -6.9f, 0.0f, -55.6f };
		vec3 = { 0.1f, 0.0f, -55.6f };
		vec4 = { 0.1f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -6.9f, 30.09f, -62.6f };
		vec2 = { -6.9f, 0.0f, -62.6f };
		vec3 = { 0.1f, 0.0f, -62.6f };
		vec4 = { 0.1f, 30.09f, -62.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -6.9f, 30.09f, -62.6f };
		vec2 = { -6.9f, 0.0f, -62.6f };
		vec3 = { -6.9f, 0.0f, -55.6f };
		vec4 = { -6.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { 0.1f, 30.09f, -62.6f };
		vec2 = { 0.1f, 0.0f, -62.6f };
		vec3 = { 0.1f, 0.0f, -55.6f };
		vec4 = { 0.1f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { 0.1f, 30.09f, -62.6f };
		vec2 = { -6.9f, 30.09f, -62.6f };
		vec3 = { -6.9f, 30.09f, -55.6f };
		vec4 = { 0.1f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();
		//------------------------------------------- Second Buidling------------------------------------------
		//-------Buidling 1-------------
		//Front 
		vec1 = { -90.9f, 30.09f, -55.6f };
		vec2 = { -90.9f, 0.0f, -55.6f };
		vec3 = { -83.9f, 0.0f, -55.6f };
		vec4 = { -83.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -90.9f, 30.09f, -62.6f };
		vec2 = { -90.9f, 0.0f, -62.6f };
		vec3 = { -83.9f, 0.0f, -62.6f };
		vec4 = { -83.9f, 30.09f, -62.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -90.9f, 30.09f, -62.6f };
		vec2 = { -90.9f, 0.0f, -62.6f };
		vec3 = { -90.9f, 0.0f, -55.6f };
		vec4 = { -90.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -83.9f, 30.09f, -62.6f };
		vec2 = { -83.9f, 0.0f, -62.6f };
		vec3 = { -83.9f, 0.0f, -55.6f };
		vec4 = { -83.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -83.9f, 30.09f, -62.6f };
		vec2 = { -90.9f, 30.09f, -62.6f };
		vec3 = { -90.9f, 30.09f, -55.6f };
		vec4 = { -83.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//-------Buidling 2-------------
		//Front 
		vec1 = { -83.9f, 20.09f, -55.6f };
		vec2 = { -83.9f, 0.0f, -55.6f };
		vec3 = { -76.9f, 0.0f, -55.6f };
		vec4 = { -76.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -83.9f, 20.09f, -62.6f };
		vec2 = { -83.9f, 0.0f, -62.6f };
		vec3 = { -76.9f, 0.0f, -62.6f };
		vec4 = { -76.9f, 20.09f, -62.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -83.9f, 20.09f, -62.6f };
		vec2 = { -83.9f, 0.0f, -62.6f };
		vec3 = { -83.9f, 0.0f, -55.6f };
		vec4 = { -83.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -76.9f, 20.09f, -62.6f };
		vec2 = { -76.9f, 0.0f, -62.6f };
		vec3 = { -76.9f, 0.0f, -55.6f };
		vec4 = { -76.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -76.9f, 20.09f, -62.6f };
		vec2 = { -83.9f, 20.09f, -62.6f };
		vec3 = { -83.9f, 20.09f, -55.6f };
		vec4 = { -76.9f, 20.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//-------Buidling 3-------------
		//Front 
		vec1 = { -76.9f, 30.09f, -55.6f };
		vec2 = { -76.9f, 0.0f, -55.6f };
		vec3 = { -69.9f, 0.0f, -55.6f };
		vec4 = { -69.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -76.9f, 30.09f, -62.6f };
		vec2 = { -76.9f, 0.0f, -62.6f };
		vec3 = { -69.9f, 0.0f, -62.6f };
		vec4 = { -69.9f, 30.09f, -62.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -76.9f, 30.09f, -62.6f };
		vec2 = { -76.9f, 0.0f, -62.6f };
		vec3 = { -76.9f, 0.0f, -55.6f };
		vec4 = { -76.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -69.9f, 30.09f, -62.6f };
		vec2 = { -69.9f, 0.0f, -62.6f };
		vec3 = { -69.9f, 0.0f, -55.6f };
		vec4 = { -69.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -69.9f, 30.09f, -62.6f };
		vec2 = { -76.9f, 30.09f, -62.6f };
		vec3 = { -76.9f, 30.09f, -55.6f };
		vec4 = { -69.9f, 30.09f, -55.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//--------------------Window------------------------------------------------
		//--------------------Window Buidling 1------------------------------------------------
		//window 1
		glBindTexture(GL_TEXTURE_2D, tex_housecolour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_housewindow.bmWidth, BMP_housewindow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_housewindow.bmBits);
		//Front 
		vec1 = { -19.9f, 29.09f, -55.5f };
		vec2 = { -19.9f, 1.0f, -55.5f };
		vec3 = { -14.9f, 1.0f, -55.5f };
		vec4 = { -14.9f, 29.09f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -19.9f, 29.09f, -62.7f };
		vec2 = { -19.9f, 1.0f, -62.7f };
		vec3 = { -14.9f, 1.0f, -62.7f };
		vec4 = { -14.9f, 29.09f, -62.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -21.0f, 29.09f, -61.6f };
		vec2 = { -21.0f, 1.0f, -61.6f };
		vec3 = { -21.0f, 1.0f, -56.6f };
		vec4 = { -21.0f, 29.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -13.8f, 29.09f, -61.6f };
		vec2 = { -13.8f, 1.0f, -61.6f };
		vec3 = { -13.8f, 1.0f, -56.6f };
		vec4 = { -13.8f, 29.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//window 2
		//Front 
		vec1 = { -12.9f, 19.09f, -55.5f };
		vec2 = { -12.9f, 1.0f, -55.5f };
		vec3 = { -7.9f, 1.0f, -55.5f };
		vec4 = { -7.9f, 19.09f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -13.9f, 19.09f, -62.7f };
		vec2 = { -13.9f, 1.0f, -62.7f };
		vec3 = { -7.9f, 1.0f, -62.7f };
		vec4 = { -7.9f, 19.09f, -62.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -6.8f, 19.09f, -61.6f };
		vec2 = { -6.8f, 1.0f, -61.6f };
		vec3 = { -6.8f, 1.0f, -56.6f };
		vec4 = { -6.8f, 19.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//window 3
		//Front 
		vec1 = { -5.9f, 29.09f, -55.5f };
		vec2 = { -5.9f, 1.0f, -55.5f };
		vec3 = { -0.9f, 1.0f, -55.5f };
		vec4 = { -0.9f, 29.09f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -5.9f, 29.09f, -62.7f };
		vec2 = { -5.9f, 1.0f, -62.7f };
		vec3 = { -0.9f, 1.0f, -62.7f };
		vec4 = { -0.9f, 29.09f, -62.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { 0.2f, 29.09f, -61.6f };
		vec2 = { 0.2f, 1.0f, -61.6f };
		vec3 = { 0.2f, 1.0f, -56.6f };
		vec4 = { 0.2f, 29.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//--------------------Window Buidling 2------------------------------------------------
		//window 1
		glBindTexture(GL_TEXTURE_2D, tex_housecolour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_housewindow.bmWidth, BMP_housewindow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_housewindow.bmBits);
		//Front 
		vec1 = { -89.9f, 29.09f, -55.5f };
		vec2 = { -89.9f, 1.0f, -55.5f };
		vec3 = { -84.9f, 1.0f, -55.5f };
		vec4 = { -84.9f, 29.09f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -89.9f, 29.09f, -62.7f };
		vec2 = { -89.9f, 1.0f, -62.7f };
		vec3 = { -84.9f, 1.0f, -62.7f };
		vec4 = { -84.9f, 29.09f, -62.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -91.0f, 29.09f, -61.6f };
		vec2 = { -91.0f, 1.0f, -61.6f };
		vec3 = { -91.0f, 1.0f, -56.6f };
		vec4 = { -91.0f, 29.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -83.8f, 29.09f, -61.6f };
		vec2 = { -83.8f, 1.0f, -61.6f };
		vec3 = { -83.8f, 1.0f, -56.6f };
		vec4 = { -83.8f, 29.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//window 2
		//Front 
		vec1 = { -82.9f, 19.09f, -55.5f };
		vec2 = { -82.9f, 1.0f, -55.5f };
		vec3 = { -77.9f, 1.0f, -55.5f };
		vec4 = { -77.9f, 19.09f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -83.9f, 19.09f, -62.7f };
		vec2 = { -83.9f, 1.0f, -62.7f };
		vec3 = { -77.9f, 1.0f, -62.7f };
		vec4 = { -77.9f, 19.09f, -62.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -76.8f, 19.09f, -61.6f };
		vec2 = { -76.8f, 1.0f, -61.6f };
		vec3 = { -76.8f, 1.0f, -56.6f };
		vec4 = { -76.8f, 19.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//window 3
		//Front 
		vec1 = { -75.9f, 29.09f, -55.5f };
		vec2 = { -75.9f, 1.0f, -55.5f };
		vec3 = { -70.9f, 1.0f, -55.5f };
		vec4 = { -70.9f, 29.09f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -75.9f, 29.09f, -62.7f };
		vec2 = { -75.9f, 1.0f, -62.7f };
		vec3 = { -70.9f, 1.0f, -62.7f };
		vec4 = { -70.9f, 29.09f, -62.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -69.8f, 29.09f, -61.6f };
		vec2 = { -69.8f, 1.0f, -61.6f };
		vec3 = { -69.8f, 1.0f, -56.6f };
		vec4 = { -69.8f, 29.09f, -56.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);

		//---------------------------- CLOCK BUIDLING-------------------------------------------------
		glBindTexture(GL_TEXTURE_2D, tex_clockbuilding);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_clockbuilding.bmWidth, BMP_clockbuilding.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_clockbuilding.bmBits);
		vec1 = { 90.0f, 15.0f, -10.0f };
		vec2 = { 90.0f, 0.0f, -10.0f };
		vec3 = { 84.0f, 0.0f, -10.0f };
		vec4 = { 84.0f, 15.0f, -10.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 90.0f, 15.0f, -10.0f };
		vec2 = { 90.0f, 0.0f, -10.0f };
		vec3 = { 90.0f, 0.0f, -16.0f };
		vec4 = { 90.0f, 15.0f, -16.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 84.0f, 15.0f, -16.0f };
		vec2 = { 84.0f, 0.0f, -16.0f };
		vec3 = { 84.0f, 0.0f, -10.0f };
		vec4 = { 84.0f, 15.0f, -10.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 90.0f, 15.0f, -16.0f };
		vec2 = { 90.0f, 0.0f, -16.0f };
		vec3 = { 84.0f, 0.0f, -16.0f };
		vec4 = { 84.0f, 15.0f, -16.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_clock);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_clock.bmWidth, BMP_clock.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_clock.bmBits);
		vec1 = { 90.0f, 20.0f, -10.0f };
		vec2 = { 90.0f, 15.0f, -10.0f };
		vec3 = { 84.0f, 15.0f, -10.0f };
		vec4 = { 84.0f, 20.0f, -10.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 90.0f, 20.0f, -16.0f };
		vec2 = { 90.0f, 15.0f, -16.0f };
		vec3 = { 84.0f, 15.0f, -16.0f };
		vec4 = { 84.0f, 20.0f, -16.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 90.0f, 20.0f, -10.0f };
		vec2 = { 90.0f, 15.0f, -10.0f };
		vec3 = { 90.0f, 15.0f, -16.0f };
		vec4 = { 90.0f, 20.0f, -16.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 84.0f, 20.0f, -16.0f };
		vec2 = { 84.0f, 15.0f, -16.0f };
		vec3 = { 84.0f, 15.0f, -10.0f };
		vec4 = { 84.0f, 20.0f, -10.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_darkgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_darkgrey.bmWidth, BMP_darkgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_darkgrey.bmBits);
		vec1 = { 87.0f, 25.0f, -13.0f };
		vec2 = { 90.0f, 20.0f, -10.0f };
		vec3 = { 84.0f, 20.0f, -10.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		vec1 = { 87.0f, 25.0f, -13.0f };
		vec2 = { 90.0f, 20.0f, -16.0f };
		vec3 = { 84.0f, 20.0f, -16.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		vec1 = { 87.0f, 25.0f, -13.0f };
		vec2 = { 84.0f, 20.0f, -10.0f };
		vec3 = { 84.0f, 20.0f, -16.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		vec1 = { 87.0f, 25.0f, -13.0f };
		vec2 = { 90.0f, 20.0f, -10.0f };
		vec3 = { 90.0f, 20.0f, -16.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_mountain);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_mountain.bmWidth, BMP_mountain.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_mountain.bmBits);
		vec1 = { 75.0f, 50.0f, 60.0f };
		vec2 = { 55.0f, 0.0f, 80.0f };
		vec3 = { 95.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		vec1 = { 75.0f, 50.0f, 60.0f };
		vec2 = { 55.0f, 0.0f, 40.0f };
		vec3 = { 95.0f, 0.0f, 40.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		vec1 = { 75.0f, 50.0f, 60.0f };
		vec2 = { 55.0f, 0.0f, 40.0f };
		vec3 = { 55.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		vec1 = { 75.0f, 50.0f, 60.0f };
		vec2 = { 95.0f, 0.0f, 40.0f };
		vec3 = { 95.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//2nd mountain
		//left
		vec1 = { 55.0f, 30.0f, 60.0f };
		vec2 = { 40.0f, 0.0f, 40.0f };
		vec3 = { 40.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		vec1 = { 55.0f, 30.0f, 60.0f };
		vec2 = { 70.0f, 0.0f, 40.0f };
		vec3 = { 70.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		vec1 = { 55.0f, 30.0f, 60.0f };
		vec2 = { 40.0f, 0.0f, 80.0f };
		vec3 = { 70.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//front
		vec1 = { 55.0f, 30.0f, 60.0f };
		vec2 = { 40.0f, 0.0f, 40.0f };
		vec3 = { 70.0f, 0.0f, 40.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);

		glBindTexture(GL_TEXTURE_2D, tex_pyramid);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_pyramid.bmWidth, BMP_pyramid.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_pyramid.bmBits);
		//---------------PYRAMID-----------
		//left
		vec1 = { -85.0f, 40.0f, 60.0f };
		vec2 = { -72.0f, 0.0f, 40.0f };
		vec3 = { -72.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		vec1 = { -85.0f, 40.0f, 60.0f };
		vec2 = { -98.0f, 0.0f, 40.0f };
		vec3 = { -98.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		vec1 = { -85.0f, 40.0f, 60.0f };
		vec2 = { -72.0f, 0.0f, 80.0f };
		vec3 = { -98.0f, 0.0f, 80.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//front
		vec1 = { -85.0f, 40.0f, 60.0f };
		vec2 = { -72.0f, 0.0f, 40.0f };
		vec3 = { -98.0f, 0.0f, 40.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec4);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, mediumdiffusecolour);
		//------------------------------------ TREES ---------------------------------------------
		glBindTexture(GL_TEXTURE_2D, tex_treetrunk);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_treetrunk.bmWidth, BMP_treetrunk.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_treetrunk.bmBits);
		//tree 1
		//----------------trunk--------------------------
		//front
		vec1 = { 13.0f, 6.0f, -55.5f };
		vec2 = { 13.0f, 0.0f, -55.5f };
		vec3 = { 16.0f, 0.0f, -55.5f };
		vec4 = { 16.0f, 6.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { 13.0f, 6.0f, -58.5f };
		vec2 = { 13.0f, 0.0f, -58.5f };
		vec3 = { 16.0f, 0.0f, -58.5f };
		vec4 = { 16.0f, 6.0f, -58.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { 13.0f, 6.0f, -58.5f };
		vec2 = { 13.0f, 0.0f, -58.5f };
		vec3 = { 13.0f, 0.0f, -55.5f };
		vec4 = { 13.0f, 6.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { 16.0f, 6.0f, -58.5f };
		vec2 = { 16.0f, 0.0f, -58.5f };
		vec3 = { 16.0f, 0.0f, -55.5f };
		vec4 = { 16.0f, 6.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//----------------trunk 2 --------------------------
		//front
		vec1 = { -83.0f, 6.0f, -35.5f };
		vec2 = { -83.0f, 0.0f, -35.5f };
		vec3 = { -80.0f, 0.0f, -35.5f };
		vec4 = { -80.0f, 6.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -83.0f, 6.0f, -38.5f };
		vec2 = { -83.0f, 0.0f, -38.5f };
		vec3 = { -80.0f, 0.0f, -38.5f };
		vec4 = { -80.0f, 6.0f, -38.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -83.0f, 6.0f, -38.5f };
		vec2 = { -83.0f, 0.0f, -38.5f };
		vec3 = { -83.0f, 0.0f, -35.5f };
		vec4 = { -83.0f, 6.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -80.0f, 6.0f, -38.5f };
		vec2 = { -80.0f, 0.0f, -38.5f };
		vec3 = { -80.0f, 0.0f, -35.5f };
		vec4 = { -80.0f, 6.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);
		//---------------------leaves part-----------------------
		glBindTexture(GL_TEXTURE_2D, tex_treecolour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_treecolour.bmWidth, BMP_treecolour.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_treecolour.bmBits);
		//---------------leaves 1
		//part 1
		//top 
		vec1 = { 5.0f, 6.0f, -64.5f };
		vec2 = { 5.0f, 6.0f, -47.5f };
		vec3 = { 24.0f, 6.0f, -47.5f };
		vec4 = { 24.0f, 6.0f, -64.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { 8.0f, 12.0f, -50.5f };
		vec2 = { 5.0f, 6.0f, -47.5f };
		vec3 = { 24.0f, 6.0f, -47.5f };
		vec4 = { 21.0f, 12.0f, -50.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 21.0f, 12.0f, -50.5f };
		vec2 = { 24.0f, 6.0f, -47.5f };
		vec3 = { 24.0f, 6.0f, -64.5f };
		vec4 = { 21.0f, 12.0f, -61.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 21.0f, 12.0f, -61.5f };
		vec2 = { 24.0f, 6.0f, -64.5f };
		vec3 = { 5.0f, 6.0f, -64.5f };
		vec4 = { 8.0f, 12.0f, -61.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 8.0f, 12.0f, -61.5f };
		vec2 = { 5.0f, 6.0f, -64.5f };
		vec3 = { 5.0f, 6.0f, -47.5f };
		vec4 = { 8.0f, 12.0f, -50.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//part 2
		//top 
		vec1 = { 6.0f, 12.0f, -62.5f };
		vec2 = { 6.0f, 12.0f, -49.5f };
		vec3 = { 22.0f, 12.0f, -49.5f };
		vec4 = { 22.0f, 12.0f, -62.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { 10.0f, 18.0f, -53.5f };
		vec2 = { 6.0f, 12.0f, -49.5f };
		vec3 = { 22.0f, 12.0f, -49.5f };
		vec4 = { 18.0f, 18.0f, -53.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 18.0f, 18.0f, -53.5f };
		vec2 = { 22.0f, 12.0f, -49.5f };
		vec3 = { 22.0f, 12.0f, -62.5f };
		vec4 = { 18.0f, 18.0f, -59.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 18.0f, 18.0f, -59.5f };
		vec2 = { 22.0f, 12.0f, -62.5f };
		vec3 = { 6.0f, 12.0f, -62.5f };
		vec4 = { 10.0f, 18.0f, -59.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 10.0f, 18.0f, -59.5f };
		vec2 = { 6.0f, 12.0f, -62.5f };
		vec3 = { 6.0f, 12.0f, -49.5f };
		vec4 = { 10.0f, 18.0f, -53.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//part 3
		//top 
		vec1 = { 9.0f, 18.0f, -60.5f };
		vec2 = { 9.0f, 18.0f, -52.5f };
		vec3 = { 19.0f, 18.0f, -52.5f };
		vec4 = { 19.0f, 18.0f, -60.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { 13.0f, 24.0f, -55.5f };
		vec2 = { 9.0f, 18.0f, -52.5f };
		vec3 = { 19.0f, 18.0f, -52.5f };
		vec4 = { 15.0f, 24.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 15.0f, 24.0f, -55.5f };
		vec2 = { 19.0f, 18.0f, -52.5f };
		vec3 = { 19.0f, 18.0f, -60.5f };
		vec4 = { 15.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 15.0f, 24.0f, -57.5f };
		vec2 = { 19.0f, 18.0f, -60.5f };
		vec3 = { 9.0f, 18.0f, -60.5f };
		vec4 = { 13.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 13.0f, 24.0f, -57.5f };
		vec2 = { 9.0f, 18.0f, -60.5f };
		vec3 = { 9.0f, 18.0f, -52.5f };
		vec4 = { 13.0f, 24.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top leaves
		vec1 = { 13.0f, 24.0f, -57.5f };
		vec2 = { 13.0f, 24.0f, -55.5f };
		vec3 = { 15.0f, 24.0f, -55.5f };
		vec4 = { 15.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//---------------leaves 2
		//part 1
		//top 
		vec1 = { -91.0f, 6.0f, -44.5f };
		vec2 = { -91.0f, 6.0f, -27.5f };
		vec3 = { -72.0f, 6.0f, -27.5f };
		vec4 = { -72.0f, 6.0f, -44.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { -88.0f, 12.0f, -30.5f };
		vec2 = { -91.0f, 6.0f, -27.5f };
		vec3 = { -72.0f, 6.0f, -27.5f };
		vec4 = { -75.0f, 12.0f, -30.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -75.0f, 12.0f, -30.5f };
		vec2 = { -72.0f, 6.0f, -27.5f };
		vec3 = { -72.0f, 6.0f, -44.5f };
		vec4 = { -75.0f, 12.0f, -41.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -75.0f, 12.0f, -41.5f };
		vec2 = { -72.0f, 6.0f, -44.5f };
		vec3 = { -91.0f, 6.0f, -44.5f };
		vec4 = { -88.0f, 12.0f, -41.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -88.0f, 12.0f, -41.5f };
		vec2 = { -91.0f, 6.0f, -44.5f };
		vec3 = { -91.0f, 6.0f, -27.5f };
		vec4 = { -88.0f, 12.0f, -30.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//part 2
		//top 
		vec1 = { -90.0f, 12.0f, -42.5f };
		vec2 = { -90.0f, 12.0f, -29.5f };
		vec3 = { -74.0f, 12.0f, -29.5f };
		vec4 = { -74.0f, 12.0f, -42.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { -86.0f, 18.0f, -33.5f };
		vec2 = { -90.0f, 12.0f, -29.5f };
		vec3 = { -74.0f, 12.0f, -29.5f };
		vec4 = { -78.0f, 18.0f, -33.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -78.0f, 18.0f, -33.5f };
		vec2 = { -74.0f, 12.0f, -29.5f };
		vec3 = { -74.0f, 12.0f, -42.5f };
		vec4 = { -78.0f, 18.0f, -39.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -78.0f, 18.0f, -39.5f };
		vec2 = { -74.0f, 12.0f, -42.5f };
		vec3 = { -90.0f, 12.0f, -42.5f };
		vec4 = { -86.0f, 18.0f, -39.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -86.0f, 18.0f, -39.5f };
		vec2 = { -90.0f, 12.0f, -42.5f };
		vec3 = { -90.0f, 12.0f, -29.5f };
		vec4 = { -86.0f, 18.0f, -33.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//part 3
		//top 
		vec1 = { -87.0f, 18.0f, -40.5f };
		vec2 = { -87.0f, 18.0f, -32.5f };
		vec3 = { -77.0f, 18.0f, -32.5f };
		vec4 = { -77.0f, 18.0f, -40.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { -83.0f, 24.0f, -35.5f };
		vec2 = { -87.0f, 18.0f, -32.5f };
		vec3 = { -77.0f, 18.0f, -32.5f };
		vec4 = { -81.0f, 24.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -81.0f, 24.0f, -35.5f };
		vec2 = { -77.0f, 18.0f, -32.5f };
		vec3 = { -77.0f, 18.0f, -40.5f };
		vec4 = { -81.0f, 24.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -81.0f, 24.0f, -37.5f };
		vec2 = { -77.0f, 18.0f, -40.5f };
		vec3 = { -87.0f, 18.0f, -40.5f };
		vec4 = { -83.0f, 24.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -83.0f, 24.0f, -37.5f };
		vec2 = { -87.0f, 18.0f, -40.5f };
		vec3 = { -87.0f, 18.0f, -32.5f };
		vec4 = { -83.0f, 24.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top leaves
		vec1 = { -83.0f, 24.0f, -37.5f };
		vec2 = { -83.0f, 24.0f, -35.5f };
		vec3 = { -81.0f, 24.0f, -35.5f };
		vec4 = { -81.0f, 24.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//--------------------- STAR -----------------------------------------
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);
		glBindTexture(GL_TEXTURE_2D, tex_yellowstar);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_yellowstar.bmWidth, BMP_yellowstar.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_yellowstar.bmBits);
		//-------------------STAR 1-----------------------------------------
		//front
		//1
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 24.0f, -55.5f };
		vec2 = { 13.2f, 25.5f, -55.5f };
		vec3 = { 14.8f, 25.5f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//2
		glBegin(GL_TRIANGLES);
		vec1 = { 15.5f, 26.0f, -55.5f };
		vec2 = { 14.0f, 24.5f, -55.5f };
		vec3 = { 14.0f, 27.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//3
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 27.0f, -55.5f };
		vec2 = { 14.0f, 24.5f, -55.5f };
		vec3 = { 12.5f, 26.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//4
		glBegin(GL_TRIANGLES);
		vec1 = { 13.2f, 26.0f, -55.5f };
		vec2 = { 14.8f, 26.0f, -55.5f };
		vec3 = { 14.0f, 28.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		//1
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 24.0f, -57.5f };
		vec2 = { 13.2f, 25.5f, -57.5f };
		vec3 = { 14.8f, 25.5f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//2
		glBegin(GL_TRIANGLES);
		vec1 = { 15.5f, 26.0f, -57.5f };
		vec2 = { 14.0f, 24.5f, -57.5f };
		vec3 = { 14.0f, 27.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//3
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 27.0f, -57.5f };
		vec2 = { 14.0f, 24.5f, -57.5f };
		vec3 = { 12.5f, 26.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//4
		glBegin(GL_TRIANGLES);
		vec1 = { 13.2f, 26.0f, -57.5f };
		vec2 = { 14.8f, 26.0f, -57.5f };
		vec3 = { 14.0f, 28.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//side 
		vec1 = { 14.0f, 28.0f, -57.5f };
		vec2 = { 13.4f, 26.5f, -57.5f };
		vec3 = { 13.4f, 26.5f, -55.5f };
		vec4 = { 14.0f, 28.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 13.4f, 26.6f, -57.5f };
		vec2 = { 12.5f, 26.0f, -57.5f };
		vec3 = { 12.5f, 26.0f, -55.5f };
		vec4 = { 13.4f, 26.6f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 12.5f, 26.0f, -57.5f };
		vec2 = { 12.5f, 26.0f, -55.5f };
		vec3 = { 13.4f, 25.0f, -55.5f };
		vec4 = { 13.4f, 25.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 13.4f, 25.0f, -57.5f };
		vec2 = { 13.4f, 25.0f, -55.5f };
		vec2 = { 14.0f, 24.0f, -55.5f };
		vec4 = { 14.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//side 2
		vec1 = { 14.0f, 28.0f, -57.5f };
		vec2 = { 14.0f, 28.0f, -55.5f };
		vec3 = { 14.6f, 26.5f, -55.5f };
		vec4 = { 14.6f, 26.5f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 14.6f, 26.5f, -57.5f };
		vec2 = { 14.6f, 26.5f, -55.5f };
		vec3 = { 15.5f, 26.0f, -55.5f };
		vec4 = { 15.5f, 26.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 15.5f, 26.0f, -57.5f };
		vec2 = { 15.5f, 26.0f, -55.5f };
		vec3 = { 14.6f, 25.0f, -55.5f };
		vec4 = { 14.6f, 25.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 14.6f, 25.0f, -57.5f };
		vec2 = { 14.6f, 25.0f, -55.5f };
		vec2 = { 14.0f, 24.0f, -55.5f };
		vec4 = { 14.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//-------------------STAR 2-----------------------------------------
		//front
		//1
		glBegin(GL_TRIANGLES);
		vec1 = { -82.0f, 24.0f, -35.5f };
		vec2 = { -82.8f, 25.5f, -35.5f };
		vec3 = { -81.2f, 25.5f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//2
		glBegin(GL_TRIANGLES);
		vec1 = { -80.5f, 26.0f, -35.5f };
		vec2 = { -82.0f, 24.5f, -35.5f };
		vec3 = { -82.0f, 27.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//3
		glBegin(GL_TRIANGLES);
		vec1 = { -82.0f, 27.0f, -35.5f };
		vec2 = { -82.0f, 24.5f, -35.5f };
		vec3 = { -83.5f, 26.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//4
		glBegin(GL_TRIANGLES);
		vec1 = { -82.8f, 26.0f, -35.5f };
		vec2 = { -81.2f, 26.0f, -35.5f };
		vec3 = { -82.0f, 28.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		//1
		glBegin(GL_TRIANGLES);
		vec1 = { -82.0f, 24.0f, -37.5f };
		vec2 = { -82.8f, 25.5f, -37.5f };
		vec3 = { -81.2f, 25.5f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//2
		glBegin(GL_TRIANGLES);
		vec1 = { -80.5f, 26.0f, -37.5f };
		vec2 = { -82.0f, 24.5f, -37.5f };
		vec3 = { -82.0f, 27.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//3
		glBegin(GL_TRIANGLES);
		vec1 = { -82.0f, 27.0f, -37.5f };
		vec2 = { -82.0f, 24.5f, -37.5f };
		vec3 = { -83.5f, 26.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//4
		glBegin(GL_TRIANGLES);
		vec1 = { -82.8f, 26.0f, -37.5f };
		vec2 = { -81.2f, 26.0f, -37.5f };
		vec3 = { -82.0f, 28.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//side 
		vec1 = { -82.0f, 28.0f, -37.5f };
		vec2 = { -82.6f, 26.5f, -37.5f };
		vec3 = { -82.6f, 26.5f, -35.5f };
		vec4 = { -82.0f, 28.0f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -82.6f, 26.6f, -37.5f };
		vec2 = { -83.5f, 26.0f, -37.5f };
		vec3 = { -83.5f, 26.0f, -35.5f };
		vec4 = { -82.6f, 26.6f, -35.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -83.5f, 26.0f, -37.5f };
		vec2 = { -83.5f, 26.0f, -35.5f };
		vec3 = { -82.6f, 25.0f, -35.5f };
		vec4 = { -82.6f, 25.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -82.6f, 25.0f, -37.5f };
		vec2 = { -82.6f, 25.0f, -35.5f };
		vec2 = { -82.0f, 24.0f, -35.5f };
		vec4 = { -82.0f, 24.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//side 2
		vec1 = { -82.0f, 28.0f, -37.5f };
		vec2 = { -82.0f, 28.0f, -35.5f };
		vec3 = { -81.4f, 26.5f, -35.5f };
		vec4 = { -81.4f, 26.5f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -81.4f, 26.5f, -37.5f };
		vec2 = { -81.4f, 26.5f, -35.5f };
		vec3 = { -80.5f, 26.0f, -35.5f };
		vec4 = { -80.5f, 26.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -80.5f, 26.0f, -37.5f };
		vec2 = { -80.5f, 26.0f, -35.5f };
		vec3 = { -81.4f, 25.0f, -35.5f };
		vec4 = { -81.4f, 25.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { -81.4f, 25.0f, -37.5f };
		vec2 = { -81.4f, 25.0f, -35.5f };
		vec2 = { -82.0f, 24.0f, -35.5f };
		vec4 = { -82.0f, 24.0f, -37.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);


		//CS Background
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glTranslatef(40, 0, 80);
		//tree 1
		//------------------------------------ TREES ---------------------------------------------
		glBindTexture(GL_TEXTURE_2D, tex_treetrunk);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_treetrunk.bmWidth, BMP_treetrunk.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_treetrunk.bmBits);
		//tree 1
		//----------------trunk--------------------------
		//front
		vec1 = { 13.0f, 6.0f, -55.5f };
		vec2 = { 13.0f, 0.0f, -55.5f };
		vec3 = { 16.0f, 0.0f, -55.5f };
		vec4 = { 16.0f, 6.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { 13.0f, 6.0f, -58.5f };
		vec2 = { 13.0f, 0.0f, -58.5f };
		vec3 = { 16.0f, 0.0f, -58.5f };
		vec4 = { 16.0f, 6.0f, -58.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { 13.0f, 6.0f, -58.5f };
		vec2 = { 13.0f, 0.0f, -58.5f };
		vec3 = { 13.0f, 0.0f, -55.5f };
		vec4 = { 13.0f, 6.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { 16.0f, 6.0f, -58.5f };
		vec2 = { 16.0f, 0.0f, -58.5f };
		vec3 = { 16.0f, 0.0f, -55.5f };
		vec4 = { 16.0f, 6.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//---------------------leaves part-----------------------
		glBindTexture(GL_TEXTURE_2D, tex_treecolour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_treecolour.bmWidth, BMP_treecolour.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_treecolour.bmBits);
		//---------------leaves 1
		//part 1
		//top 
		vec1 = { 5.0f, 6.0f, -64.5f };
		vec2 = { 5.0f, 6.0f, -47.5f };
		vec3 = { 24.0f, 6.0f, -47.5f };
		vec4 = { 24.0f, 6.0f, -64.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { 8.0f, 12.0f, -50.5f };
		vec2 = { 5.0f, 6.0f, -47.5f };
		vec3 = { 24.0f, 6.0f, -47.5f };
		vec4 = { 21.0f, 12.0f, -50.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 21.0f, 12.0f, -50.5f };
		vec2 = { 24.0f, 6.0f, -47.5f };
		vec3 = { 24.0f, 6.0f, -64.5f };
		vec4 = { 21.0f, 12.0f, -61.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 21.0f, 12.0f, -61.5f };
		vec2 = { 24.0f, 6.0f, -64.5f };
		vec3 = { 5.0f, 6.0f, -64.5f };
		vec4 = { 8.0f, 12.0f, -61.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 8.0f, 12.0f, -61.5f };
		vec2 = { 5.0f, 6.0f, -64.5f };
		vec3 = { 5.0f, 6.0f, -47.5f };
		vec4 = { 8.0f, 12.0f, -50.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//part 2
		//top 
		vec1 = { 6.0f, 12.0f, -62.5f };
		vec2 = { 6.0f, 12.0f, -49.5f };
		vec3 = { 22.0f, 12.0f, -49.5f };
		vec4 = { 22.0f, 12.0f, -62.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { 10.0f, 18.0f, -53.5f };
		vec2 = { 6.0f, 12.0f, -49.5f };
		vec3 = { 22.0f, 12.0f, -49.5f };
		vec4 = { 18.0f, 18.0f, -53.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 18.0f, 18.0f, -53.5f };
		vec2 = { 22.0f, 12.0f, -49.5f };
		vec3 = { 22.0f, 12.0f, -62.5f };
		vec4 = { 18.0f, 18.0f, -59.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 18.0f, 18.0f, -59.5f };
		vec2 = { 22.0f, 12.0f, -62.5f };
		vec3 = { 6.0f, 12.0f, -62.5f };
		vec4 = { 10.0f, 18.0f, -59.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 10.0f, 18.0f, -59.5f };
		vec2 = { 6.0f, 12.0f, -62.5f };
		vec3 = { 6.0f, 12.0f, -49.5f };
		vec4 = { 10.0f, 18.0f, -53.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//part 3
		//top 
		vec1 = { 9.0f, 18.0f, -60.5f };
		vec2 = { 9.0f, 18.0f, -52.5f };
		vec3 = { 19.0f, 18.0f, -52.5f };
		vec4 = { 19.0f, 18.0f, -60.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//4 sides
		vec1 = { 13.0f, 24.0f, -55.5f };
		vec2 = { 9.0f, 18.0f, -52.5f };
		vec3 = { 19.0f, 18.0f, -52.5f };
		vec4 = { 15.0f, 24.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 15.0f, 24.0f, -55.5f };
		vec2 = { 19.0f, 18.0f, -52.5f };
		vec3 = { 19.0f, 18.0f, -60.5f };
		vec4 = { 15.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 15.0f, 24.0f, -57.5f };
		vec2 = { 19.0f, 18.0f, -60.5f };
		vec3 = { 9.0f, 18.0f, -60.5f };
		vec4 = { 13.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 13.0f, 24.0f, -57.5f };
		vec2 = { 9.0f, 18.0f, -60.5f };
		vec3 = { 9.0f, 18.0f, -52.5f };
		vec4 = { 13.0f, 24.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top leaves
		vec1 = { 13.0f, 24.0f, -57.5f };
		vec2 = { 13.0f, 24.0f, -55.5f };
		vec3 = { 15.0f, 24.0f, -55.5f };
		vec4 = { 15.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//--------------------- STAR -----------------------------------------
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);
		glBindTexture(GL_TEXTURE_2D, tex_yellowstar);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_yellowstar.bmWidth, BMP_yellowstar.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_yellowstar.bmBits);
		//-------------------STAR 1-----------------------------------------
		//front
		//1
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 24.0f, -55.5f };
		vec2 = { 13.2f, 25.5f, -55.5f };
		vec3 = { 14.8f, 25.5f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//2
		glBegin(GL_TRIANGLES);
		vec1 = { 15.5f, 26.0f, -55.5f };
		vec2 = { 14.0f, 24.5f, -55.5f };
		vec3 = { 14.0f, 27.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//3
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 27.0f, -55.5f };
		vec2 = { 14.0f, 24.5f, -55.5f };
		vec3 = { 12.5f, 26.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//4
		glBegin(GL_TRIANGLES);
		vec1 = { 13.2f, 26.0f, -55.5f };
		vec2 = { 14.8f, 26.0f, -55.5f };
		vec3 = { 14.0f, 28.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		//1
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 24.0f, -57.5f };
		vec2 = { 13.2f, 25.5f, -57.5f };
		vec3 = { 14.8f, 25.5f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//2
		glBegin(GL_TRIANGLES);
		vec1 = { 15.5f, 26.0f, -57.5f };
		vec2 = { 14.0f, 24.5f, -57.5f };
		vec3 = { 14.0f, 27.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//3
		glBegin(GL_TRIANGLES);
		vec1 = { 14.0f, 27.0f, -57.5f };
		vec2 = { 14.0f, 24.5f, -57.5f };
		vec3 = { 12.5f, 26.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//4
		glBegin(GL_TRIANGLES);
		vec1 = { 13.2f, 26.0f, -57.5f };
		vec2 = { 14.8f, 26.0f, -57.5f };
		vec3 = { 14.0f, 28.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//side 
		vec1 = { 14.0f, 28.0f, -57.5f };
		vec2 = { 13.4f, 26.5f, -57.5f };
		vec3 = { 13.4f, 26.5f, -55.5f };
		vec4 = { 14.0f, 28.0f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 13.4f, 26.6f, -57.5f };
		vec2 = { 12.5f, 26.0f, -57.5f };
		vec3 = { 12.5f, 26.0f, -55.5f };
		vec4 = { 13.4f, 26.6f, -55.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 12.5f, 26.0f, -57.5f };
		vec2 = { 12.5f, 26.0f, -55.5f };
		vec3 = { 13.4f, 25.0f, -55.5f };
		vec4 = { 13.4f, 25.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 13.4f, 25.0f, -57.5f };
		vec2 = { 13.4f, 25.0f, -55.5f };
		vec2 = { 14.0f, 24.0f, -55.5f };
		vec4 = { 14.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//side 2
		vec1 = { 14.0f, 28.0f, -57.5f };
		vec2 = { 14.0f, 28.0f, -55.5f };
		vec3 = { 14.6f, 26.5f, -55.5f };
		vec4 = { 14.6f, 26.5f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 14.6f, 26.5f, -57.5f };
		vec2 = { 14.6f, 26.5f, -55.5f };
		vec3 = { 15.5f, 26.0f, -55.5f };
		vec4 = { 15.5f, 26.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 15.5f, 26.0f, -57.5f };
		vec2 = { 15.5f, 26.0f, -55.5f };
		vec3 = { 14.6f, 25.0f, -55.5f };
		vec4 = { 14.6f, 25.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		vec1 = { 14.6f, 25.0f, -57.5f };
		vec2 = { 14.6f, 25.0f, -55.5f };
		vec2 = { 14.0f, 24.0f, -55.5f };
		vec4 = { 14.0f, 24.0f, -57.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glTranslatef(-40,0,-80);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		
		//-------------------------------------------------------------------------------------------------------------------
		// ---------------------------------------------- END BACKGROUND ----------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------------
		

		


		//animation
		if (animation == 9 && animationSwitch == 0) {
			
			if (rotateX6 < 315) {
				rotateX6+=4;
			}

			if (rotateX7 < 345) {
				rotateX7 += 1.5;
			}

			if (rotateY5 < 40) {
				rotateY5 +=2;
			}
		}
		else if (animation == 9 && animationSwitch == 1) {
			if (rotateX6 < 360) {
				rotateX6 += 4;
			}

			if (rotateX7 < 360) {
				rotateX7 += 1.5;
			}

			if (rotateY5 > 0) {
				rotateY5 -= 2;
			}

			if (rotateX8 < 360) {
				rotateX8 += 2;
			}

			if (rotateX9 < 360) {
				rotateX9 += 4;
			}

			if (rotateZ9 < 360) {
				rotateZ9 += 2;
			}
		}

		if (animation == 8 && animationSwitch==0) {

			if (rotateX3 > -94) {
				rotateX3 -= 4;
			}
			if (rotateX1 < 94) {
				rotateX1 += 4;
			}

			if (rotateX2 < 86) {
				rotateX2 += 4;
			}

			if (rotateX6 > -94) {
				rotateX6 -= 4;
			}

			if (animationMoveY >-6) {
				animationMoveY -= 0.2;
			}

			
		}
		else if (animation == 8 && animationSwitch == 1) {
			if (rotateX3 < 0) {
				rotateX3 += 4;
			}
			if (rotateX1 > 0) {
				rotateX1 -= 4;
			}

			if (rotateX2 > 0) {
				rotateX2 -= 4;
			}

			if (rotateX6 < 0) {
				rotateX6 += 4;
			}

			if (animationMoveY <0) {
				animationMoveY += 0.2;
			}
		}

		//walk
		if (direction ==1) {
			if (!(moveX > 98 )) {
				moveX += 0.2;
			}
			

			walkAnimation();
		}
		else if (direction == 2) {
			if (!( moveZ < -98.25)) {
				moveZ -= 0.2;
			}
			
			walkAnimation();
		}
		else if (direction == 3) {
			if (!(moveX < -98)) {
				moveX -= 0.2;
			}
			
			walkAnimation();
		}
		else if (direction == 4) {
			if (!(moveZ>101.75)) {
				moveZ += 0.2;
			}
			
			walkAnimation();
		}
		else if (direction == 0) {
			
		}

		glTranslatef(-2.0 + moveX, 0, -1.75 + moveZ);
		glRotatef(face, 0, 1, 0);
		glTranslatef(2.0 - moveX, 0, 1.75 - moveZ);

		//movepoint
		//////////////////////////////////////
		//////////////////////////////////////
		//////all
		
		glTranslatef(moveX, moveY, moveZ);
		glTranslatef(animationMoveX, animationMoveY, animationMoveZ);
		
		/////////////////////////////////////////



		//movepoint
		//////////////////////////////////////
		glPushMatrix();
		//////////////////////////////////////
		//////move left leg
		glTranslatef(-3.25, 13.0, -1.65);
		glRotatef(rotateX3, 1, 0, 0);
		glRotatef(rotateY3, 0, 1, 0);
		glRotatef(rotateZ3, 0, 0, 1);
		glTranslatef(3.25, -13.0, 1.65);
		/////////////////////////////////////////


		//thigh
		//front
		if (lightswitch == 0) {
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		}
		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 10.0f, -0.8f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 10.0f, -0.8f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.4f, 10.0f, -0.8f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 10.0f, -2.5f };
		vec2 = { -4.1f, 7.8f, -2.2f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 10.0f, -2.5f };
		vec2 = { -2.7f, 7.8f, -2.2f };
		vec3 = { -2.4f, 10.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//left
		vec1 = { -4.1f, 10.0f, -2.5f };
		vec2 = { -4.1f, 7.8f, -2.2f };
		vec3 = { -4.1f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 10.0f, -2.5f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -4.1f, 10.0f, -0.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.4f, 10.0f, -2.5f };
		vec2 = { -2.7f, 7.8f, -2.2f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.4f, 10.0f, -2.5f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.4f, 10.0f, -0.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//bottom
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 7.8f, -1.1f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_thigh);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_thigh.bmWidth, BMP_thigh.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_thigh.bmBits);


		//thigh2
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 13.0f, -0.8f };
		vec2 = { -4.1f, 10.0f, -0.8f };
		vec3 = { -2.4f, 10.0f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 13.0f, -0.8f };
		vec2 = { -2.4f, 10.0f, -0.8f };
		vec3 = { -2.4f, 13.0f, -0.8f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);


		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 13.0f, -2.5f };
		vec2 = { -4.1f, 10.0f, -2.5f };
		vec3 = { -2.4f, 10.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 13.0f, -2.5f };
		vec2 = { -2.4f, 10.0f, -2.5f };
		vec3 = { -2.4f, 13.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//left
		vec1 = { -4.1f, 13.0f, -0.8f };
		vec2 = { -4.1f, 10.0f, -0.8f };
		vec3 = { -4.1f, 10.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 13.0f, -0.8f };
		vec2 = { -4.1f, 10.0f, -2.5f };
		vec3 = { -4.1f, 13.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.4f, 13.0f, -0.8f };
		vec2 = { -2.4f, 10.0f, -0.8f };
		vec3 = { -2.4f, 10.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.4f, 13.0f, -0.8f };
		vec2 = { -2.4f, 10.0f, -2.5f };
		vec3 = { -2.4f, 13.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		vec1 = { -4.1f, 13.0f, -2.5f };
		vec2 = { -4.1f, 13.0f, -0.8f };
		vec3 = { -2.4f, 13.0f, -0.8f };
		vec4 = { -2.4f, 13.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		if (lightswitch == 0) {
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		}
		//movepoint
		//////////////////////////////////////
		glPushMatrix();
		//////////////////////////////////////
		//////move down left leg
		glTranslatef(-3.4,7.8,-1.65);
		glRotatef(rotateX1, 1, 0, 0);
		glRotatef(rotateY1, 0, 1, 0);
		glRotatef(rotateZ1, 0, 0, 1);
		glTranslatef(3.4, -7.8, 1.65);
		/////////////////////////////////////////
		if (lightswitch == 0) {
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		}

		//ROBOT START
		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);
		//FOOTS
		//FRONT
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-3.6f, 0.4f, 0.1f);
		glVertex3f(-3.8f, 0.0f, 0.0f);
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(-3.2f, 0.4f, 0.1f);
		glEnd();

		
		//LEFT
		glBegin(GL_TRIANGLES);
		vec1 = { -4.0f,0.6f,-0.4f };
		vec2 = { -4.2f,0.0f,-0.5f };
		vec3 = { -3.8f,0.0f,0.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.0f,0.6f,-0.4f };
		vec2 = { -3.8f,0.0f,0.0f };
		vec3 = { -3.6f,0.4f,0.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//RIGHT
		glBegin(GL_TRIANGLES);
		vec1 = { -3.2f,0.4f,0.1f };
		vec2 = { -3.0f,0.0f,0.0f };
		vec3 = { -2.6f,0.0f,-0.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.2f,0.4f,0.1f };
		vec2 = { -2.6f,0.0f,-0.5f };
		vec3 = { -2.8f,0.6f,-0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//BOTTOM
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-4.2f, 0.0f, -0.5f);
		glVertex3f(-3.8f, 0.0f, 0.0f);
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(-2.6f, 0.0f, -0.5f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_toe);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_toe.bmWidth, BMP_toe.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_toe.bmBits);

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f, 0.6f, -0.4f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.6f, 0.4f, 0.1f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-3.2f, 0.4f, 0.1f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.8f, 0.6f, -0.4f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//foot2
		//front
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(-4.5f, 0.0f, -0.5f);
		glVertex3f(-4.4f, 1.0f, -0.4f);
		glVertex3f(-3.4f, 1.2f, -0.4f);
		glVertex3f(-2.4f, 1.0f, -0.4f);
		glVertex3f(-2.3f, 0.0f, -0.5f);
		glEnd();

		//back
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-4.5f, 0.0f, -1.0f);
		glVertex3f(-4.4f, 1.2f, -0.9f);
		glVertex3f(-3.4f, 1.4f, -0.9f);
		glVertex3f(-2.4f, 1.2f, -0.9f);
		glVertex3f(-2.3f, 0.0f, -1.0f);
		glEnd();

		glBegin(GL_TRIANGLES);
		vec1 = { -4.4f, 1.2f, -0.9f };
		vec2 = { -4.5f, 0.0f, -1.0f };
		vec3 = { -4.5f, 0.0f, -0.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 1.2f, -0.9f };
		vec2 = { -4.5f, 0.0f, -0.5f };
		vec3 = { -4.4f, 1.0f, -0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		vec1 = { -3.4f, 1.4f, -0.9f };
		vec2 = { -4.4f, 1.2f, -0.9f };
		vec3 = { -4.4f, 1.0f, -0.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.4f, 1.4f, -0.9f };
		vec2 = { -4.4f, 1.0f, -0.4f };
		vec3 = { -3.4f, 1.2f, -0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		vec1 = { -3.4f, 1.2f, -0.4f };
		vec2 = { -2.4f, 1.0f, -0.4f };
		vec3 = { -2.4f, 1.2f, -0.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.4f, 1.2f, -0.4f };
		vec2 = { -2.4f, 1.2f, -0.9f };
		vec3 = { -3.4f, 1.4f, -0.9f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		vec1 = { -2.4f, 1.0f, -0.4f };
		vec2 = { -2.3f, 0.0f, -0.5f };
		vec3 = { -2.3f, 0.0f, -1.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.4f, 1.0f, -0.4f };
		vec2 = { -2.3f, 0.0f, -1.0f };
		vec3 = { -2.4f, 1.2f, -0.9f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		
		//Foot3
		//front
		vec1 = { -4.1f, 1.8f, -1.1f };
		vec2 = { -4.5f, 0.0f, -0.6f };
		vec3 = { -2.3f, 0.0f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 1.8f, -1.1f };
		vec2 = { -2.3f, 0.0f, -0.6f };
		vec3 = { -2.7f, 1.8f, -1.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();
		
		//back
		vec1 = { -4.1f, 1.8f, -2.2f };
		vec2 = { -4.5f, 0.0f, -2.6f };
		vec3 = { -2.3f, 0.0f, -2.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.7f, 1.8f, -2.2f);
		glEnd();

		//Left
		glBindTexture(GL_TEXTURE_2D, tex_foot);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_foot.bmWidth, BMP_foot.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_foot.bmBits);
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 1.8f, -2.2f };
		vec2 = { -4.5f, 0.0f, -2.6f };
		vec3 = { -4.5f, 0.0f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 1.8f, -2.2f };
		vec2 = { -4.5f, 0.0f, -0.6f };
		vec3 = { -4.1f, 1.8f, -1.1f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -2.7f, 1.8f, -1.1f };
		vec2 = { -2.3f, 0.0f, -0.6f };
		vec3 = { -2.3f, 0.0f, -2.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 1.8f, -1.1f };
		vec2 = { -2.3f, 0.0f, -2.6f };
		vec3 = { -2.7f, 1.8f, -2.2f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//Bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-4.5f, 0.0f, -2.6f);
		glVertex3f(-4.5f, 0.0f, -0.6f);
		glVertex3f(-2.3f, 0.0f, -0.6f);
		glVertex3f(-2.3f, 0.0f, -2.6f);
		glEnd();

		//foot4
		//back
		vec1 = { -4.0f, 0.8f, -2.8f };
		vec2 = { -4.0f, 0.0f, -2.8f };
		vec3 = { -2.8f, 0.0f, -2.8f };
		vec4 = { -2.8f, 0.8f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -4.0f, 0.8f, -2.8f };
		vec2 = { -4.0f, 0.8f, -1.8f };
		vec3 = { -2.8f, 0.8f, -1.8f };
		vec4 = { -2.8f, 0.8f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//bottom
		vec1 = { -4.0f, 0.0f, -2.8f };
		vec2 = { -4.0f, 0.0f, -1.8f };
		vec3 = { -2.8f, 0.0f, -1.8f };
		vec4 = { -2.8f, 0.0f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -4.0f, 0.8f, -2.8f };
		vec2 = { -4.0f, 0.0f, -2.8f };
		vec3 = { -4.0f, 0.0f, -1.8f };
		vec4 = { -4.0f, 0.8f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -2.8f, 0.8f, -2.8f };
		vec2 = { -2.8f, 0.0f, -2.8f };
		vec3 = { -2.8f, 0.0f, -1.8f };
		vec4 = { -2.8f, 0.8f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		

		//Foot3 leftdeco

		glBindTexture(GL_TEXTURE_2D, tex_yellow);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_yellow.bmWidth, BMP_yellow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_yellow.bmBits);

		//left
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.8f, 0.8f, -2.5f };
		vec4 = { -3.8f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -3.5f, 1.4f, -2.7f };
		vec2 = { -3.5f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -3.8f, 1.4f, -2.5f };
		vec2 = { -3.8f, 0.8f, -2.5f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.7f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 1.4f, -2.5f };
		vec3 = { -3.5f, 1.4f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//Foot3 rightdeco

		glTranslatef(0.5,0,0);

		glBindTexture(GL_TEXTURE_2D, tex_yellow);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_yellow.bmWidth, BMP_yellow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_yellow.bmBits);

		//left
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.8f, 0.8f, -2.5f };
		vec4 = { -3.8f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -3.5f, 1.4f, -2.7f };
		vec2 = { -3.5f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -3.8f, 1.4f, -2.5f };
		vec2 = { -3.8f, 0.8f, -2.5f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.7f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//topu
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 1.4f, -2.5f };
		vec3 = { -3.5f, 1.4f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_knee);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee.bmWidth, BMP_knee.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee.bmBits);

		glTranslatef(-0.5, 0, 0);

		//knee
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -4.3f, 5.8f, -0.8f };
		vec2 = { -4.1f, 1.8f, -1.1f };
		vec3 = { -2.7f, 1.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.3f, 5.8f, -0.8f };
		vec2 = { -2.7f, 1.8f, -1.1f };
		vec3 = { -2.5f, 5.8f, -0.8f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//BACK
		vec1 = { -2.5f, 5.8f, -2.5f };
		vec2 = { -2.7f, 1.8f, -2.2f };
		vec3 = { -4.1f, 1.8f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.5f, 5.8f, -2.5f };
		vec2 = { -4.1f, 1.8f, -2.2f };
		vec3 = { -4.3f, 5.8f, -2.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -4.3f, 5.8f, -2.5f };
		vec2 = { -4.1f, 1.8f, -2.2f };
		vec3 = { -4.1f, 1.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.3f, 5.8f, -2.5f };
		vec2 = { -4.1f, 1.8f, -1.1f };
		vec3 = { -4.3f, 5.8f, -0.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.5f, 5.8f, -0.8f };
		vec2 = { -2.7f, 1.8f, -1.1f };
		vec3 = { -2.7f, 1.8f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.5f, 5.8f, -0.8f };
		vec2 = { -2.7f, 1.8f, -2.2f };
		vec3 = { -2.5f, 5.8f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//knee 2.5
		//front
		vec1 = { -3.9f, 7.2f, -0.4f };
		vec2 = { -4.1f, 5.8f, -0.8f };
		vec3 = { -2.7f, 5.8f, -0.8f };
		vec4 = { -2.9f, 7.2f, -0.4f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();


		//front2
		vec1 = { -3.9f, 7.8f, -1.1f };
		vec2 = { -3.9f, 7.2f, -0.4f };
		vec3 = { -2.9f, 7.2f, -0.4f };
		vec4 = { -2.9f, 7.8f, -1.1f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -3.9f, 7.8f, -1.1f };
		vec2 = { -4.1f, 5.8f, -0.8f };
		vec3 = { -3.9f, 7.2f, -0.4f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		vec1 = { -2.9f, 7.8f, -1.1f };
		vec2 = { -2.7f, 5.8f, -0.8f };
		vec3 = { -2.9f, 7.2f, -0.4f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//knee 2
		//front
		glBindTexture(GL_TEXTURE_2D, tex_knee2);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee2.bmWidth, BMP_knee2.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee2.bmBits);
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 7.8f, -1.1f };
		vec2 = { -4.3f, 5.8f, -0.8f };
		vec3 = { -2.5f, 5.8f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 7.8f, -1.1f };
		vec2 = { -2.5f, 5.8f, -0.8f };
		vec3 = { -2.7f,7.8f,-1.1f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_knee2back);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee2back.bmWidth, BMP_knee2back.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee2back.bmBits);

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -2.7f, 7.8f, -2.2f };
		vec2 = { -2.5f, 5.8f, -2.5f };
		vec3 = { -4.3f, 5.8f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 7.8f, -2.2f };
		vec2 = { -4.3f, 5.8f, -2.5f };
		vec3 = { -4.1f, 7.8f, -2.2f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.3f, 5.8f, -2.5f };
		vec3 = { -4.3f, 5.8f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.3f, 5.8f, -0.8f };
		vec3 = { -4.1f, 7.8f, -1.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.7f, 7.8f, -1.1f };
		vec2 = { -2.5f, 5.8f, -0.8f };
		vec3 = { -2.5f, 5.8f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 7.8f, -1.1f };
		vec2 = { -2.5f, 5.8f, -2.5f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		
		//top
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_knee3);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee3.bmWidth, BMP_knee3.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee3.bmBits);

		//tyre
		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);

		glBegin(GL_TRIANGLES);

		//front
		vec1 = { -4.6f, 5.4f, -1.5f };
		vec2 = { -4.55f, 4.2f, -1.5f };
		vec3 = { -4.20f, 4.2f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.6f, 5.4f, -1.5f };
		vec2 = { -4.20f, 4.2f, -1.5f };
		vec3 = { -4.25f, 5.4f, -1.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//back
		vec1 = { -4.6f, 5.4f, -2.4f };
		vec2 = { -4.55f, 4.2f, -2.4f };
		vec3 = { -4.20f, 4.2f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.6f, 5.4f, -2.4f };
		vec2 = { -4.20f, 4.2f, -2.4f };
		vec3 = { -4.25f, 5.4f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBindTexture(GL_TEXTURE_2D, tex_tyre);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyre.bmWidth, BMP_tyre.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyre.bmBits);


		glBegin(GL_TRIANGLES);
		glColor4f(1, 1, 1, 0);
		vec1 = { -4.6f, 5.4f, -2.4f };
		vec2 = { -4.55f, 4.2f, -2.4f };
		vec3 = { -4.55f, 4.2f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.6f, 5.4f, -2.4f };
		vec2 = { -4.55f, 4.2f, -1.5f };
		vec3 = { -4.6f, 5.4f, -1.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);

		glBegin(GL_TRIANGLES);
		//bottom
		vec1 = { -4.55f, 4.2f, -2.4f };
		vec2 = { -4.55f, 4.2f, -1.5f };
		vec3 = { -4.20f, 4.2f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.55f, 4.2f, -2.4f };
		vec2 = { -4.20f, 4.2f, -1.5f };
		vec3 = { -4.20f, 4.2f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//top
		vec1 = { -4.60f, 5.4f, -2.4f };
		vec2 = { -4.60f, 5.4f, -1.5f };
		vec3 = { -4.25f, 5.4f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.60f, 5.4f, -2.4f };
		vec2 = { -4.25f, 5.4f, -1.5f };
		vec3 = { -4.25f, 5.4f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();



		//tyre 2
		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -4.55f, 4.0f, -1.5f };
		vec2 = { -4.50f, 2.8f, -1.5f };
		vec3 = { -4.15f, 2.8f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.55f, 4.0f, -1.5f };
		vec2 = { -4.15f, 2.8f, -1.5f };
		vec3 = { -4.20f, 4.0f, -1.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();


		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -4.55f, 4.0f, -2.4f };
		vec2 = { -4.50f, 2.8f, -2.4f };
		vec3 = { -4.15f, 2.8f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.55f, 4.0f, -2.4f };
		vec2 = { -4.15f, 2.8f, -2.4f };
		vec3 = { -4.20f, 4.0f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();
		//left
		glBindTexture(GL_TEXTURE_2D, tex_tyre);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyre.bmWidth, BMP_tyre.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyre.bmBits);


		glBegin(GL_TRIANGLES);
		vec1 = { -4.55f, 4.0f, -2.4f };
		vec2 = { -4.50f, 2.8f, -2.4f };
		vec3 = { -4.50f, 2.8f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.55f, 4.0f, -2.4f };
		vec2 = { -4.50f, 2.8f, -1.5f };
		vec3 = { -4.55f, 4.0f, -1.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);

		//bottom
		glBegin(GL_TRIANGLES);
		vec1 = { -4.50f, 2.8f, -2.4f };
		vec2 = { -4.50f, 2.8f, -1.5f };
		vec3 = { -4.15f, 2.8f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.50f, 2.8f, -2.4f };
		vec2 = { -4.15f, 2.8f, -1.5f };
		vec3 = { -4.15f, 2.8f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//top
		vec1 = { -4.55f, 4.0f, -2.4f };
		vec2 = { -4.55f, 4.0f, -1.5f };
		vec3 = { -4.20f, 4.0f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.55f, 4.0f, -2.4f };
		vec2 = { -4.20f, 4.0f, -1.5f };
		vec3 = { -4.20f, 4.0f, -2.4f };
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//End movepoint
		/////////////
		glPopMatrix();
		////////////

		
		//End movepoint
		/////////////
		glPopMatrix();
		////////////

		glBindTexture(GL_TEXTURE_2D, tex_wraist);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_wraist.bmWidth, BMP_wraist.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_wraist.bmBits);

		//waist 1.front
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.1f, 14.0f, -0.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.1f, 13.0f, -0.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.4f, 13.0f, -0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.4f, 14.0f, -0.5f);

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-4.1f, 14.0f, -1.1f);
		glVertex3f(-4.1f, 13.0f, -1.1f);
		glVertex3f(-4.1f, 13.0f, -0.5f);
		glVertex3f(-4.1f, 14.0f, -0.5f);

		//right
		glNormal3f(1, 0, 0);
		glVertex3f(-2.4f, 14.0f, -0.5f);
		glVertex3f(-2.4f, 13.0f, -0.5f);
		glVertex3f(-2.4f, 13.0f, -1.1f);
		glVertex3f(-2.4f, 14.0f, -1.1f);

		//bottom
		glNormal3f(0, -1, 0);
		glVertex3f(-4.1f, 13.0f, -1.1f);
		glVertex3f(-4.1f, 13.0f, -0.5f);
		glVertex3f(-2.4f, 13.0f, -0.5f);
		glVertex3f(-2.4f, 13.0f, -1.1f);

		//top
		glNormal3f(0, 1, 0);
		glVertex3f(-4.1f, 14.0f, -1.1f);
		glVertex3f(-4.1f, 14.0f, -0.5f);
		glVertex3f(-2.4f, 14.0f, -0.5f);
		glVertex3f(-2.4f, 14.0f, -1.1f);
		glEnd();
		//waist 1.back
		//front
		glBegin(GL_QUADS);
		glBindTexture(GL_TEXTURE_2D, tex_wraist);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_wraist.bmWidth, BMP_wraist.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_wraist.bmBits);

		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.1f, 14.0f, -2.9f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.1f, 13.0f, -2.9f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.4f, 13.0f, -2.9f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.4f, 14.0f, -2.9f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-4.1f, 14.0f, -2.9f);
		glVertex3f(-4.1f, 13.0f, -2.9f);
		glVertex3f(-4.1f, 13.0f, -2.2f);
		glVertex3f(-4.1f, 14.0f, -2.2f);

		//right
		glNormal3f(1, 0, 0);
		glVertex3f(-2.4f, 14.0f, -2.2f);
		glVertex3f(-2.4f, 13.0f, -2.2f);
		glVertex3f(-2.4f, 13.0f, -2.9f);
		glVertex3f(-2.4f, 14.0f, -2.9f);

		//bottom
		glNormal3f(0, -1, 0);
		glVertex3f(-4.1f, 13.0f, -2.9f);
		glVertex3f(-4.1f, 13.0f, -2.2f);
		glVertex3f(-2.4f, 13.0f, -2.2f);
		glVertex3f(-2.4f, 13.0f, -2.9f);

		//top
		glNormal3f(0, 1, 0);
		glVertex3f(-4.1f, 14.0f, -2.9f);
		glVertex3f(-4.1f, 14.0f, -2.2f);
		glVertex3f(-2.4f, 14.0f, -2.2f);
		glVertex3f(-2.4f, 14.0f, -2.9f);
		//wraist 1.top
		//top
		glNormal3f(0, 1, 0);
		glVertex3f(-4.1f, 14.0f, -2.2f);
		glVertex3f(-4.1f, 14.0f, -1.1f);
		glVertex3f(-2.4f, 14.0f, -1.1f);
		glVertex3f(-2.4f, 14.0f, -2.2f);

		//wraist 1.left
		//top
		glNormal3f(-1, 0, 0);
		glVertex3f(-4.1f, 14.0f, -2.2f);
		glVertex3f(-4.1f, 13.0f, -2.2f);
		glVertex3f(-4.1f, 13.0f, -1.1f);
		glVertex3f(-4.1f, 14.0f, -1.1f);
		glEnd();


		glPushMatrix();
		//wraist 1.left armor
		//front

		glTranslatef(-4.3f, 14.0f, 1.65f); 
		glRotatef(355, 0, 0, 1);
		glTranslatef(4.3f, -14.0f, -1.65f);

		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(-4.3f, 14.0f, -1.3f);
		glVertex3f(-4.7f, 13.2f, -1.3f);
		glVertex3f(-4.7f, 12.4f, -1.3f);
		glVertex3f(-4.3f, 11.0f, -1.3f);
		glVertex3f(-4.1f, 11.0f, -1.3f);
		glVertex3f(-4.1f, 14.0f, -1.3f);
		glEnd();

		//back
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-4.3f, 14.0f, -2.0f);
		glVertex3f(-4.7f, 13.2f, -2.0f);
		glVertex3f(-4.7f, 12.4f, -2.0f);
		glVertex3f(-4.3f, 11.0f, -2.0f);
		glVertex3f(-4.1f, 11.0f, -2.0f);
		glVertex3f(-4.1f, 14.0f, -2.0f);
		glEnd();

		//right
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-4.1f, 14.0f, -2.0f);
		glVertex3f(-4.1f, 11.0f, -2.0f);
		glVertex3f(-4.1f, 11.0f, -1.3f);
		glVertex3f(-4.1f, 14.0f, -1.3f);
		glEnd();

		//left1
		glBegin(GL_TRIANGLES);
		vec1 = { -4.3f, 14.0f, -2.0f };
		vec2 = { -4.7f, 13.2f, -2.0f };
		vec3 = { -4.7f, 13.2f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.3f, 14.0f, -2.0f };
		vec2 = { -4.7f, 13.2f, -1.3f };
		vec3 = { -4.3f, 14.0f, -1.3f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//left2
		vec1 = { -4.7f, 13.2f, -2.0f };
		vec2 = { -4.7f, 12.4f, -2.0f };
		vec3 = { -4.7f, 12.4f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.7f, 13.2f, -2.0f };
		vec2 = { -4.7f, 12.4f, -1.3f };
		vec3 = { -4.7f, 13.2f, -1.3f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//left3
		vec1 = { -4.7f, 12.4f, -2.0f };
		vec2 = { -4.3f, 11.0f, -2.0f };
		vec3 = { -4.3f, 11.0f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.7f, 12.4f, -2.0f };
		vec2 = { -4.3f, 11.0f, -1.3f };
		vec3 = { -4.7f, 12.4f, -1.3f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//BOTTOM
		vec1 = { -4.3f, 11.0f, -2.0f };
		vec2 = { -4.3f, 11.0f, -1.3f };
		vec3 = { -4.1f, 11.0f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.3f, 11.0f, -2.0f };
		vec2 = { -4.1f, 11.0f, -1.3f };
		vec3 = { -4.1f, 11.0f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//top
		vec1 = { -4.3f, 14.0f, -2.0f };
		vec2 = { -4.3f, 14.0f, -1.3f };
		vec3 = { -4.1f, 14.0f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.3f, 14.0f, -2.0f };
		vec2 = { -4.1f, 14.0f, -1.3f };
		vec3 = { -4.1f, 14.0f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glPopMatrix();



		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//private part
		//Front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-2.4f, 14.0f, -0.2f);
		glVertex3f(-2.4f, 12.0f, -0.2f);
		glVertex3f(-1.6f, 12.0f, -0.2f);
		glVertex3f(-1.6f, 14.0f, -0.2f);
		glEnd();

		//Left
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 0);
		glVertex3f(-2.4f, 14.0f, -2.7f);
		glVertex3f(-2.4f, 11.0f, -2.7f);
		glVertex3f(-2.4f, 11.0f, -0.7f);
		glVertex3f(-2.4f, 12.0f, -0.2f);
		glVertex3f(-2.4f, 14.0f, -0.2f);
		glEnd();

		//RIGHT
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(-1.6f, 14.0f, -2.7f);
		glVertex3f(-1.6f, 11.0f, -2.7f);
		glVertex3f(-1.6f, 11.0f, -0.7f);
		glVertex3f(-1.6f, 12.0f, -0.2f);
		glVertex3f(-1.6f, 14.0f, -0.2f);
		glEnd();

		//front 2
		glBegin(GL_TRIANGLES);
		vec1 = { -2.4f, 12.0f, -0.2f };
		vec2 = { -2.4f, 11.0f, -0.7f };
		vec3 = { -1.6f, 11.0f, -0.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.4f, 12.0f, -0.2f };
		vec2 = { -1.6f, 11.0f, -0.7f };
		vec3 = { -1.6f, 12.0f, -0.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//BOTTOM
		glBegin(GL_POLYGON);
		glNormal3f(0, -1, 0);
		glVertex3f(-2.4f, 11.0f, -0.7f);
		glVertex3f(-2.4f, 11.0f, -2.7f);
		glVertex3f(-1.6f, 11.0f, -2.7f);
		glVertex3f(-1.6f, 11.0f, -0.7f);
		glEnd();

		//top
		glBegin(GL_POLYGON);
		glNormal3f(0, 1, 0);
		glVertex3f(-2.4f, 14.0f, -0.2f);
		glVertex3f(-2.4f, 14.0f, -2.7f);
		glVertex3f(-1.6f, 14.0f, -2.7f);
		glVertex3f(-1.6f, 14.0f, -0.2f);
		glEnd();

		//BACK
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-2.4f, 14.0f, -2.7f);
		glVertex3f(-2.4f, 11.0f, -2.7f);
		glVertex3f(-1.6f, 11.0f, -2.7f);
		glVertex3f(-1.6f, 14.0f, -2.7f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_wraist);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_wraist.bmWidth, BMP_wraist.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_wraist.bmBits);

		glPushMatrix();

		glTranslatef(2.8,0,0);

		//wraist 1.front
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.4f, 14.0f, -0.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.4f, 13.0f, -0.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.7f, 13.0f, -0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.7f, 14.0f, -0.5f);

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//left
		glNormal3f(-1, 0, 0);
		glVertex3f(-4.4f, 14.0f, -1.1f);
		glVertex3f(-4.4f, 13.0f, -1.1f);
		glVertex3f(-4.4f, 13.0f, -0.5f);
		glVertex3f(-4.4f, 14.0f, -0.5f);

		//right
		glNormal3f(1, 0, 0);
		glVertex3f(-2.7f, 14.0f, -0.5f);
		glVertex3f(-2.7f, 13.0f, -0.5f);
		glVertex3f(-2.7f, 13.0f, -1.1f);
		glVertex3f(-2.7f, 14.0f, -1.1f);

		//bottom
		glNormal3f(0, -1, 0);
		glVertex3f(-4.4f, 13.0f, -1.1f);
		glVertex3f(-4.4f, 13.0f, -0.5f);
		glVertex3f(-2.7f, 13.0f, -0.5f);
		glVertex3f(-2.7f, 13.0f, -1.1f);

		//top
		glNormal3f(0, 1, 0);
		glVertex3f(-4.4f, 14.0f, -1.1f);
		glVertex3f(-4.4f, 14.0f, -0.5f);
		glVertex3f(-2.7f, 14.0f, -0.5f);
		glVertex3f(-2.7f, 14.0f, -1.1f);
		glEnd();
		//waist 1.back
		//front
		glBegin(GL_QUADS);
		glBindTexture(GL_TEXTURE_2D, tex_wraist);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_wraist.bmWidth, BMP_wraist.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_wraist.bmBits);

		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.4f, 14.0f, -2.9f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.4f, 13.0f, -2.9f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.7f, 13.0f, -2.9f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.7f, 14.0f, -2.9f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-4.4f, 14.0f, -2.9f);
		glVertex3f(-4.4f, 13.0f, -2.9f);
		glVertex3f(-4.4f, 13.0f, -2.2f);
		glVertex3f(-4.4f, 14.0f, -2.2f);

		//right
		glNormal3f(1, 0, 0);
		glVertex3f(-2.7f, 14.0f, -2.2f);
		glVertex3f(-2.7f, 13.0f, -2.2f);
		glVertex3f(-2.7f, 13.0f, -2.9f);
		glVertex3f(-2.7f, 14.0f, -2.9f);

		//bottom
		glNormal3f(0, -1, 0);
		glVertex3f(-4.4f, 13.0f, -2.9f);
		glVertex3f(-4.4f, 13.0f, -2.2f);
		glVertex3f(-2.7f, 13.0f, -2.2f);
		glVertex3f(-2.7f, 13.0f, -2.9f);

		//top
		glNormal3f(0, 1, 0);
		glVertex3f(-4.4f, 14.0f, -2.9f);
		glVertex3f(-4.4f, 14.0f, -2.2f);
		glVertex3f(-2.7f, 14.0f, -2.2f);
		glVertex3f(-2.7f, 14.0f, -2.9f);
		//wraist 1.top
		//top
		glNormal3f(0, 1, 0);
		glVertex3f(-4.4f, 14.0f, -2.2f);
		glVertex3f(-4.4f, 14.0f, -1.1f);
		glVertex3f(-2.7f, 14.0f, -1.1f);
		glVertex3f(-2.7f, 14.0f, -2.2f);

		//wraist 1.right
		//top
		glNormal3f(1, 0, 0);
		glVertex3f(-2.7f, 14.0f, -2.2f);
		glVertex3f(-2.7f, 13.0f, -2.2f);
		glVertex3f(-2.7f, 13.0f, -1.1f);
		glVertex3f(-2.7f, 14.0f, -1.1f);
		glEnd();

		//wraist 1.left armor
		//front
		
		glTranslatef(-2.7f, 14.0f, 1.65f);
		glRotatef(5, 0, 0, 1);
		glTranslatef(2.7f, -14.0f, -1.65f);

		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(-2.7f, 14.0f, -1.3f);
		glVertex3f(-2.7f, 11.0f, -1.3f);
		glVertex3f(-2.5f, 11.0f, -1.3f);
		glVertex3f(-2.1f, 12.4f, -1.3f);
		glVertex3f(-2.1f, 13.2f, -1.3f);
		glVertex3f(-2.5f, 14.0f, -1.3f);
		glEnd();

		//back
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-2.7f, 14.0f, -2.0f);
		glVertex3f(-2.7f, 11.0f, -2.0f);
		glVertex3f(-2.5f, 11.0f, -2.0f);
		glVertex3f(-2.1f, 12.4f, -2.0f);
		glVertex3f(-2.1f, 13.2f, -2.0f);
		glVertex3f(-2.5f, 14.0f, -2.0f);
		glEnd();

		//right



		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-2.7f, 14.0f, -1.3f);
		glVertex3f(-2.7f, 11.0f, -1.3f);
		glVertex3f(-2.7f, 11.0f, -2.0f);
		glVertex3f(-2.7f, 14.0f, -2.0f);
		glEnd();



		//left1
		glBegin(GL_TRIANGLES);
		vec1 = { -2.5f, 14.0f, -1.3f };
		vec2 = { -2.1f, 13.2f, -1.3f };
		vec3 = { -2.1f, 13.2f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.5f, 14.0f, -1.3f };
		vec2 = { -2.1f, 13.2f, -2.0f };
		vec3 = { -2.5f, 14.0f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//left2
		vec1 = { -2.1f, 13.2f, -1.3f };
		vec2 = { -2.1f, 12.4f, -1.3f };
		vec3 = { -2.1f, 12.4f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.1f, 13.2f, -1.3f };
		vec2 = { -2.1f, 12.4f, -2.0f };
		vec3 = { -2.1f, 13.2f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//left3
		vec1 = { -2.1f, 12.4f, -1.3f };
		vec2 = { -2.5f, 11.0f, -1.3f };
		vec3 = { -2.5f, 11.0f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.1f, 12.4f, -1.3f };
		vec2 = { -2.5f, 11.0f, -2.0f };
		vec3 = { -2.1f, 12.4f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//BOTTOM
		vec1 = { -2.7f, 11.0f, -2.0f };
		vec2 = { -2.7f, 11.0f, -1.3f };
		vec3 = { -2.5f, 11.0f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 11.0f, -2.0f };
		vec2 = { -2.5f, 11.0f, -1.3f };
		vec3 = { -2.5f, 11.0f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//top
		vec1 = { -2.7f, 14.0f, -2.0f };
		vec2 = { -2.7f, 14.0f, -1.3f };
		vec3 = { -2.5f, 14.0f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 14.0f, -2.0f };
		vec2 = { -2.5f, 14.0f, -1.3f };
		vec3 = { -2.5f, 14.0f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glPopMatrix();

		//movepoint
		//////////////////////////////////////
		glPushMatrix();
		glTranslatef(2.8f, 0.0f, 0.0f);
		//////////////////////////////////////
		//////move right leg
		glTranslatef(-3.25, 13.0, -1.65);
		glRotatef(rotateX4, 1, 0, 0);
		glRotatef(rotateY4, 0, 1, 0);
		glRotatef(rotateZ4, 0, 0, 1);
		glTranslatef(3.25, -13.0, 1.65);
		/////////////////////////////////////////

		

		//thigh
		//front
		
		glBindTexture(GL_TEXTURE_2D, tex_knee3);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee3.bmWidth, BMP_knee3.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee3.bmBits);

		glBegin(GL_TRIANGLES);
		vec1 = { -4.4f, 10.0f, -0.8f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 10.0f, -0.8f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.7f, 10.0f, -0.8f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -4.4f, 10.0f, -2.5f };
		vec2 = { -4.1f, 7.8f, -2.2f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 10.0f, -2.5f };
		vec2 = { -2.7f, 7.8f, -2.2f };
		vec3 = { -2.7f, 10.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -4.4f, 10.0f, -2.5f };
		vec2 = { -4.1f, 7.8f, -2.2f };
		vec3 = { -4.1f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 10.0f, -2.5f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -4.4f, 10.0f, -0.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.7f, 10.0f, -2.5f };
		vec2 = { -2.7f, 7.8f, -2.2f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 10.0f, -2.5f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.7f, 10.0f, -0.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//bottom
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 7.8f, -1.1f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();



		//thigh2
		//front
		glBindTexture(GL_TEXTURE_2D, tex_thigh);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_thigh.bmWidth, BMP_thigh.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_thigh.bmBits);

		glBegin(GL_TRIANGLES);
		vec1 = { -4.4f, 13.0f, -0.8f };
		vec2 = { -4.4f, 10.0f, -0.8f };
		vec3 = { -2.7f, 10.0f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 13.0f, -0.8f };
		vec2 = { -2.7f, 10.0f, -0.8f };
		vec3 = { -2.7f, 13.0f, -0.8f };
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -4.4f, 13.0f, -2.5f };
		vec2 = { -4.4f, 10.0f, -2.5f };
		vec3 = { -2.7f, 10.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 13.0f, -2.5f };
		vec2 = { -2.7f, 10.0f, -2.5f };
		vec3 = { -2.7f, 13.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//left
		vec1 = { -4.4f, 13.0f, -0.8f };
		vec2 = { -4.4f, 10.0f, -0.8f };
		vec3 = { -4.4f, 10.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 13.0f, -0.8f };
		vec2 = { -4.4f, 10.0f, -2.5f };
		vec3 = { -4.4f, 13.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.7f, 13.0f, -0.8f };
		vec2 = { -2.7f, 10.0f, -0.8f };
		vec3 = { -2.7f, 10.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 13.0f, -0.8f };
		vec2 = { -2.7f, 10.0f, -2.5f };
		vec3 = { -2.7f, 13.0f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		vec1 = { -4.4f, 13.0f, -2.5f };
		vec2 = { -4.4f, 13.0f, -0.8f };
		vec3 = { -2.7f, 13.0f, -0.8f };
		vec4 = { -2.7f, 13.0f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//PART 2
		//=========================================================================================================
		//FOOTS
		//FRONT

		

		

		//movepoint
		//////////////////////////////////////
		glPushMatrix();
		//////////////////////////////////////
		//////move down left leg
		glTranslatef(-3.4, 7.8, -1.65);
		glRotatef(rotateX2, 1, 0, 0);
		glRotatef(rotateY2, 0, 1, 0);
		glRotatef(rotateZ2, 0, 0, 1);
		glTranslatef(3.4, -7.8, 1.65);
		/////////////////////////////////////////


		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-3.6f, 0.4f, 0.1f);
		glVertex3f(-3.8f, 0.0f, 0.0f);
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(-3.2f, 0.4f, 0.1f);
		glEnd();


		//LEFT
		glBegin(GL_TRIANGLES);
		vec1 = { -4.0f,0.6f,-0.4f };
		vec2 = { -4.2f,0.0f,-0.5f };
		vec3 = { -3.8f,0.0f,0.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.0f,0.6f,-0.4f };
		vec2 = { -3.8f,0.0f,0.0f };
		vec3 = { -3.6f,0.4f,0.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//RIGHT
		glBegin(GL_TRIANGLES);
		vec1 = { -3.2f,0.4f,0.1f };
		vec2 = { -3.0f,0.0f,0.0f };
		vec3 = { -2.6f,0.0f,-0.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.2f,0.4f,0.1f };
		vec2 = { -2.6f,0.0f,-0.5f };
		vec3 = { -2.8f,0.6f,-0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//BOTTOM
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-4.2f, 0.0f, -0.5f);
		glVertex3f(-3.8f, 0.0f, 0.0f);
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(-2.6f, 0.0f, -0.5f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_toe);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_toe.bmWidth, BMP_toe.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_toe.bmBits);

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f, 0.6f, -0.4f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.6f, 0.4f, 0.1f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-3.2f, 0.4f, 0.1f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.8f, 0.6f, -0.4f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//foot2
		//front
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(-4.5f, 0.0f, -0.5f);
		glVertex3f(-4.4f, 1.0f, -0.4f);
		glVertex3f(-3.4f, 1.2f, -0.4f);
		glVertex3f(-2.4f, 1.0f, -0.4f);
		glVertex3f(-2.3f, 0.0f, -0.5f);
		glEnd();

		//back
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-4.5f, 0.0f, -1.0f);
		glVertex3f(-4.4f, 1.2f, -0.9f);
		glVertex3f(-3.4f, 1.4f, -0.9f);
		glVertex3f(-2.4f, 1.2f, -0.9f);
		glVertex3f(-2.3f, 0.0f, -1.0f);
		glEnd();

		glBegin(GL_TRIANGLES);
		vec1 = { -4.4f, 1.2f, -0.9f };
		vec2 = { -4.5f, 0.0f, -1.0f };
		vec3 = { -4.5f, 0.0f, -0.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.4f, 1.2f, -0.9f };
		vec2 = { -4.5f, 0.0f, -0.5f };
		vec3 = { -4.4f, 1.0f, -0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		vec1 = { -3.4f, 1.4f, -0.9f };
		vec2 = { -4.4f, 1.2f, -0.9f };
		vec3 = { -4.4f, 1.0f, -0.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.4f, 1.4f, -0.9f };
		vec2 = { -4.4f, 1.0f, -0.4f };
		vec3 = { -3.4f, 1.2f, -0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		vec1 = { -3.4f, 1.2f, -0.4f };
		vec2 = { -2.4f, 1.0f, -0.4f };
		vec3 = { -2.4f, 1.2f, -0.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.4f, 1.2f, -0.4f };
		vec2 = { -2.4f, 1.2f, -0.9f };
		vec3 = { -3.4f, 1.4f, -0.9f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		vec1 = { -2.4f, 1.0f, -0.4f };
		vec2 = { -2.3f, 0.0f, -0.5f };
		vec3 = { -2.3f, 0.0f, -1.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.4f, 1.0f, -0.4f };
		vec2 = { -2.3f, 0.0f, -1.0f };
		vec3 = { -2.4f, 1.2f, -0.9f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		
		//Foot3
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 1.8f, -1.1f };
		vec2 = { -4.5f, 0.0f, -0.6f };
		vec3 = { -2.3f, 0.0f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 1.8f, -1.1f };
		vec2 = { -2.3f, 0.0f, -0.6f };
		vec3 = { -2.7f, 1.8f, -1.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		vec1 = { -4.1f, 1.8f, -2.2f };
		vec2 = { -4.5f, 0.0f, -2.6f };
		vec3 = { -2.3f, 0.0f, -2.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.7f, 1.8f, -2.2f); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glEnd();

		//Left
		glBindTexture(GL_TEXTURE_2D, tex_foot);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_foot.bmWidth, BMP_foot.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_foot.bmBits);
		glColor4f(1, 1, 1, 0);
		glBegin(GL_TRIANGLES);
		
		 vec1 = { -4.1f, 1.8f, -2.2f };
		 vec2 = { -4.5f, 0.0f, -2.6f };
		vec3 = { -4.5f, 0.0f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 1.8f, -2.2f };
		vec2 = { -4.5f, 0.0f, -0.6f };
		vec3 = { -4.1f, 1.8f, -1.1f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_foot);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_foot.bmWidth, BMP_foot.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_foot.bmBits);
		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -2.7f, 1.8f, -1.1f };
		vec2 = { -2.3f, 0.0f, -0.6f };
		vec3 = { -2.3f, 0.0f, -2.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 1.8f, -1.1f };
		vec2 = { -2.3f, 0.0f, -2.6f };
		vec3 = { -2.7f, 1.8f, -2.2f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//Bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-4.5f, 0.0f, -2.6f);
		glVertex3f(-4.5f, 0.0f, -0.6f);
		glVertex3f(-2.3f, 0.0f, -0.6f);
		glVertex3f(-2.3f, 0.0f, -2.6f);
		glEnd();

		//foot4
		//back
		vec1 = { -4.0f, 0.8f, -2.8f };
		vec2 = { -4.0f, 0.0f, -2.8f };
		vec3 = { -2.8f, 0.0f, -2.8f };
		vec4 = { -2.8f, 0.8f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -4.0f, 0.8f, -2.8f };
		vec2 = { -4.0f, 0.8f, -1.8f };
		vec3 = { -2.8f, 0.8f, -1.8f };
		vec4 = { -2.8f, 0.8f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//bottom
		vec1 = { -4.0f, 0.0f, -2.8f };
		vec2 = { -4.0f, 0.0f, -1.8f };
		vec3 = { -2.8f, 0.0f, -1.8f };
		vec4 = { -2.8f, 0.0f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -4.0f, 0.8f, -2.8f };
		vec2 = { -4.0f, 0.0f, -2.8f };
		vec3 = { -4.0f, 0.0f, -1.8f };
		vec4 = { -4.0f, 0.8f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -2.8f, 0.8f, -2.8f };
		vec2 = { -2.8f, 0.0f, -2.8f };
		vec3 = { -2.8f, 0.0f, -1.8f };
		vec4 = { -2.8f, 0.8f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();



		//Foot3 leftdeco

		glBindTexture(GL_TEXTURE_2D, tex_yellow);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_yellow.bmWidth, BMP_yellow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_yellow.bmBits);

		//left
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.8f, 0.8f, -2.5f };
		vec4 = { -3.8f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -3.5f, 1.4f, -2.7f };
		vec2 = { -3.5f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -3.8f, 1.4f, -2.5f };
		vec2 = { -3.8f, 0.8f, -2.5f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.7f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//topu
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 1.4f, -2.5f };
		vec3 = { -3.5f, 1.4f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//Foot3 rightdeco

		glTranslatef(0.5, 0, 0);

		glBindTexture(GL_TEXTURE_2D, tex_yellow);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_yellow.bmWidth, BMP_yellow.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_yellow.bmBits);

		//left
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.8f, 0.8f, -2.5f };
		vec4 = { -3.8f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -3.5f, 1.4f, -2.7f };
		vec2 = { -3.5f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -3.8f, 1.4f, -2.5f };
		vec2 = { -3.8f, 0.8f, -2.5f };
		vec3 = { -3.5f, 0.8f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 0.8f, -2.7f };
		vec3 = { -3.5f, 0.8f, -2.7f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//topu
		vec1 = { -3.8f, 1.4f, -2.7f };
		vec2 = { -3.8f, 1.4f, -2.5f };
		vec3 = { -3.5f, 1.4f, -2.5f };
		vec4 = { -3.5f, 1.4f, -2.7f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_knee);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee.bmWidth, BMP_knee.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee.bmBits);

		glTranslatef(-0.5, 0, 0);

		//knee
		//front
		glBindTexture(GL_TEXTURE_2D, tex_knee);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee.bmWidth, BMP_knee.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee.bmBits);

		glBegin(GL_TRIANGLES);
		vec1 = { -4.3f, 5.8f, -0.8f };
		vec2 = { -4.1f, 1.8f, -1.1f };
		vec3 = { -2.7f, 1.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.3f, 5.8f, -0.8f };
		vec2 = { -2.7f, 1.8f, -1.1f };
		vec3 = { -2.5f, 5.8f, -0.8f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//BACK
		vec1 = { -2.5f, 5.8f, -2.5f };
		vec2 = { -2.7f, 1.8f, -2.2f };
		vec3 = { -4.1f, 1.8f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.5f, 5.8f, -2.5f };
		vec2 = { -4.1f, 1.8f, -2.2f };
		vec3 = { -4.3f, 5.8f, -2.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);
		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -4.3f, 5.8f, -2.5f };
		vec2 = { -4.1f, 1.8f, -2.2f };
		vec3 = { -4.1f, 1.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.3f, 5.8f, -2.5f };
		vec2 = { -4.1f, 1.8f, -1.1f };
		vec3 = { -4.3f, 5.8f, -0.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.5f, 5.8f, -0.8f };
		vec2 = { -2.7f, 1.8f, -1.1f };
		vec3 = { -2.7f, 1.8f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.5f, 5.8f, -0.8f };
		vec2 = { -2.7f, 1.8f, -2.2f };
		vec3 = { -2.5f, 5.8f, -2.5f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//knee 2.5
		//front
		vec1 = { -3.9f, 7.2f, -0.4f };
		vec2 = { -4.1f, 5.8f, -0.8f };
		vec3 = { -2.7f, 5.8f, -0.8f };
		vec4 = { -2.9f, 7.2f, -0.4f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front2
		vec1 = { -3.9f, 7.8f, -1.1f };
		vec2 = { -3.9f, 7.2f, -0.4f };
		vec3 = { -2.9f, 7.2f, -0.4f };
		vec4 = { -2.9f, 7.8f, -1.1f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -3.9f, 7.8f, -1.1f };
		vec2 = { -4.1f, 5.8f, -0.8f };
		vec3 = { -3.9f, 7.2f, -0.4f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		vec1 = { -2.9f, 7.8f, -1.1f };
		vec2 = { -2.7f, 5.8f, -0.8f };
		vec3 = { -2.9f, 7.2f, -0.4f };
		glBegin(GL_TRIANGLES);
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//knee 2
		//front

		glBindTexture(GL_TEXTURE_2D, tex_knee2);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee2.bmWidth, BMP_knee2.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee2.bmBits);

		glBegin(GL_QUADS);
		vec1 = { -4.1f, 7.8f, -1.1f };
		vec2 = { -4.3f, 5.8f, -0.8f };
		vec3 = { -2.5f, 5.8f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.7f, 7.8f, -1.1f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_knee2back);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_knee2back.bmWidth, BMP_knee2back.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_knee2back.bmBits);

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -2.7f, 7.8f, -2.2f };
		vec2 = { -2.5f, 5.8f, -2.5f };
		vec3 = { -4.3f, 5.8f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 7.8f, -2.2f };
		vec2 = { -4.3f, 5.8f, -2.5f };
		vec3 = { -4.1f, 7.8f, -2.2f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);
		

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.3f, 5.8f, -2.5f };
		vec3 = { -4.3f, 5.8f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.3f, 5.8f, -0.8f };
		vec3 = { -4.1f, 7.8f, -1.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//right
		vec1 = { -2.7f, 7.8f, -1.1f };
		vec2 = { -2.5f, 5.8f, -0.8f };
		vec3 = { -2.5f, 5.8f, -2.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.7f, 7.8f, -1.1f };
		vec2 = { -2.5f, 5.8f, -2.5f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//top
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -4.1f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -1.1f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.1f, 7.8f, -2.2f };
		vec2 = { -2.7f, 7.8f, -1.1f };
		vec3 = { -2.7f, 7.8f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//tyre
		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);

		glBegin(GL_TRIANGLES);

		//front
		vec1 = { -2.55f, 5.4f, -1.5f };
		vec2 = { -2.6f, 4.2f, -1.5f };
		vec3 = { -2.25f, 4.2f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.55f, 5.4f, -1.5f };
		vec2 = { -2.25f, 4.2f, -1.5f };
		vec3 = { -2.2f, 5.4f, -1.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//back
		vec1 = { -2.55f, 5.4f, -2.4f };
		vec2 = { -2.6f, 4.2f, -2.4f };
		vec3 = { -2.25f, 4.2f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.55f, 5.4f, -2.4f };
		vec2 = { -2.25f, 4.2f, -2.4f };
		vec3 = { -2.2f, 5.4f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_tyre);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyre.bmWidth, BMP_tyre.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyre.bmBits);

		//left
		glBegin(GL_TRIANGLES);
		glColor4f(1, 1, 1, 0);
		vec1 = { -2.2f, 5.4f, -1.5f };
		vec2 = { -2.25f, 4.2f, -1.5f };
		vec3 = { -2.25f, 4.2f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.2f, 5.4f, -1.5f };
		vec2 = { -2.25f, 4.2f, -2.4f };
		vec3 = { -2.2f, 5.4f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);

		glBegin(GL_TRIANGLES);
		//bottom
		vec1 = { -2.6f, 4.2f, -2.4f };
		vec2 = { -2.6f, 4.2f, -1.5f };
		vec3 = { -2.25f, 4.2f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 4.2f, -2.4f };
		vec2 = { -2.25f, 4.2f, -1.5f };
		vec3 = { -2.25f, 4.2f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//top
		vec1 = { -2.6f, 5.4f, -2.4f };
		vec2 = { -2.6f, 5.4f, -1.5f };
		vec3 = { -2.25f, 5.4f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 5.4f, -2.4f };
		vec2 = { -2.25f, 5.4f, -1.5f };
		vec3 = { -2.25f, 5.4f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//tyre 2
		//front
		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);

		glBegin(GL_TRIANGLES);
		vec1 = { -2.6f, 4.0f, -1.5f };
		vec2 = { -2.65f, 2.8f, -1.5f };
		vec3 = { -2.3f, 2.8f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 4.0f, -1.5f };
		vec2 = { -2.3f, 2.8f, -1.5f };
		vec3 = { -2.25f, 4.0f, -1.5f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//back
		vec1 = { -2.6f, 4.0f, -2.4f };
		vec2 = { -2.65f, 2.8f, -2.4f };
		vec3 = { -2.3f, 2.8f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 4.0f, -2.4f };
		vec2 = { -2.3f, 2.8f, -2.4f };
		vec3 = { -2.25f, 4.0f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_tyre);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyre.bmWidth, BMP_tyre.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyre.bmBits);


		//left
		glBegin(GL_TRIANGLES);
		glColor4f(1, 1, 1, 0);
		vec1 = { -2.25f, 4.0f, -1.5f };
		vec2 = { -2.3f, 2.8f, -1.5f };
		vec3 = { -2.3f, 2.8f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.25f, 4.0f, -1.5f };
		vec2 = { -2.3f, 2.8f, -2.4f };
		vec3 = { -2.25f, 4.0f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_tyrestrip);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_tyrestrip.bmWidth, BMP_tyrestrip.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_tyrestrip.bmBits);

		glBegin(GL_TRIANGLES);
		//bottom
		vec1 = { -2.65f, 2.8f, -2.4f };
		vec2 = { -2.65f, 2.8f, -1.5f };
		vec3 = { -2.3f, 2.8f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.65f, 2.8f, -2.4f };
		vec2 = { -2.3f, 2.8f, -1.5f };
		vec3 = { -2.3f, 2.8f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());

		//top
		vec1 = { -2.65f, 4.0f, -2.4f };
		vec2 = { -2.65f, 4.0f, -1.5f };
		vec3 = { -2.3f, 4.0f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.65f, 4.0f, -2.4f };
		vec2 = { -2.3f, 4.0f, -1.5f };
		vec3 = { -2.3f, 4.0f, -2.4f };
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//End movepoint
		/////////////
		glPopMatrix();
		////////////


		//End movepoint
		/////////////
		glPopMatrix();
		////////////
		

		//movepoint
		//////////////////////////////////////
		glPushMatrix();
		//////////////////////////////////////
		//////move upper body
		glTranslatef(-2.0, 14.0, -1.60);
		glRotatef(rotateX5, 1, 0, 0);
		glRotatef(rotateY5, 0, 1, 0);
		glRotatef(rotateZ5, 0, 0, 1);
		glTranslatef(2.0, -14.0, 1.60);
		/////////////////////////////////////////

		//stomach
		//front
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_stomach);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_stomach.bmWidth, BMP_stomach.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_stomach.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_stomach1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_stomach1.bmWidth, BMP_stomach1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_stomach1.bmBits);
		}
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-3.6f, 16.0f, -0.8f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.6f, 14.0f, -0.8f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 14.0f, -0.8f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, 16.0f, -0.8f);
		glEnd();

		if(robotAppearance == 1){
		glBindTexture(GL_TEXTURE_2D, tex_stomachback);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_stomachback.bmWidth, BMP_stomachback.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_stomachback.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_stomachback1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_stomachback1.bmWidth, BMP_stomachback1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_stomachback1.bmBits);
		}
		//Back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-3.6f, 16.0f, -2.4f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.6f, 14.0f, -2.4f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 14.0f, -2.4f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, 16.0f, -2.4f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}
		//Left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-3.6f, 16.0f, -2.4f);
		glVertex3f(-3.6f, 14.0f, -2.4f);
		glVertex3f(-3.6f, 14.0f, -0.8f);
		glVertex3f(-3.6f, 16.0f, -0.8f);
		glEnd();

		//Right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-0.4f, 16.0f, -0.8f);
		glVertex3f(-0.4f, 14.0f, -0.8f);
		glVertex3f(-0.4f, 14.0f, -2.4f);
		glVertex3f(-0.4f, 16.0f, -2.4f);
		glEnd();

		//Bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-3.6f, 14.01f, -2.4f);
		glVertex3f(-3.6f, 14.01f, -0.8f);
		glVertex3f(-0.4f, 14.01f, -0.8f);
		glVertex3f(-0.4f, 14.01f, -2.4f);
		glEnd();



		glBindTexture(GL_TEXTURE_2D, tex_sixpack);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_sixpack.bmWidth, BMP_sixpack.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_sixpack.bmBits);

		//stomach deco1

		//front
		vec1 = { -2.6f, 16.0f, -0.6f };
		vec2 = { -2.6f, 14.0f, -0.4f };
		vec3 = { -1.4f, 14.0f, -0.4f };
		vec4 = { -1.4f, 16.0f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//left
		vec1 = { -2.6f, 16.0f, -0.8f };
		vec2 = { -2.6f, 14.0f, -0.8f };
		vec3 = { -2.6f, 14.0f, -0.4f };
		vec4 = { -2.6f, 16.0f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -1.4f, 16.0f, -0.8f };
		vec2 = { -1.4f, 14.0f, -0.8f };
		vec3 = { -1.4f, 14.0f, -0.4f };
		vec4 = { -1.4f, 16.0f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -2.6f, 16.0f, -0.8f };
		vec2 = { -2.6f, 16.0f, -0.6f };
		vec3 = { -1.4f, 16.0f, -0.6f };
		vec4 = { -1.4f, 16.0f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//botom
		vec1 = { -2.6f, 14.0f, -0.8f };
		vec2 = { -2.6f, 14.0f, -0.4f };
		vec3 = { -1.4f, 14.0f, -0.4f };
		vec4 = { -1.4f, 14.0f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}
		//stomach decoleft

		//front
		vec1 = { -3.8f, 14.6f, -0.6f };
		vec2 = { -3.8f, 14.0f, -0.6f };
		vec3 = { -3.0f, 14.0f, -0.6f };
		vec4 = { -3.0f, 15.2f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -3.8f, 14.6f, -0.8f };
		vec2 = { -3.8f, 14.6f, -0.6f };
		vec3 = { -3.0f, 15.2f, -0.6f };
		vec4 = { -3.0f, 15.2f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -3.8f, 14.6f, -0.8f };
		vec2 = { -3.8f, 14.0f, -0.8f };
		vec3 = { -3.8f, 14.0f, -0.6f };
		vec4 = { -3.8f, 14.6f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -3.0f, 15.2f, -0.8f };
		vec2 = { -3.0f, 14.0f, -0.8f };
		vec3 = { -3.0f, 14.0f, -0.6f };
		vec4 = { -3.0f, 15.2f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//stomach decoright

		//front
		vec1 = { -1.0f, 15.2f, -0.6f };
		vec2 = { -1.0f, 14.0f, -0.6f };
		vec3 = { -0.2f, 14.0f, -0.6f };
		vec4 = { -0.2f, 14.6f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -1.0f, 15.2f, -0.8f };
		vec2 = { -1.0f, 15.2f, -0.6f };
		vec3 = { -0.2f, 14.6f, -0.6f };
		vec4 = { -0.2f, 14.6f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//left
		vec1 = { -1.0f, 15.2f, -0.8f };
		vec2 = { -1.0f, 14.0f, -0.8f };
		vec3 = { -1.0f, 14.0f, -0.6f };
		vec4 = { -1.0f, 15.2f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -0.2f, 14.6f, -0.8f };
		vec2 = { -0.2f, 14.0f, -0.8f };
		vec3 = { -0.2f, 14.0f, -0.6f };
		vec4 = { -0.2f, 14.6f, -0.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();
		//18
		//Center
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -4.2f, 18.0f, -0.4f };
		vec2 = { -3.6f, 16.0f, -0.8f };
		vec3 = { -0.4f, 16.0f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.2f, 18.0f, -0.4f };
		vec2 = { -0.4f, 16.0f, -0.8f };
		vec3 = { 0.2f, 18.0f, -0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -4.2f, 18.0f, -2.8f };
		vec2 = { -3.6f, 16.0f, -2.4f };
		vec3 = { -0.4f, 16.0f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.2f, 18.0f, -2.8f };
		vec2 = { -0.4f, 16.0f, -2.4f };
		vec3 = { 0.2f, 18.0f, -2.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -4.2f, 18.0f, -2.8f };
		vec2 = { -3.6f, 16.0f, -2.4f };
		vec3 = { -3.6f, 16.0f, -0.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.2f, 18.0f, -2.8f };
		vec2 = { -3.6f, 16.0f, -0.8f };
		vec3 = { -4.2f, 18.0f, -0.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { 0.2f, 18.0f, -0.4f };
		vec2 = { -0.4, 16.0f, -0.8f };
		vec3 = { -0.4f, 16.0f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { 0.2f, 18.0f, -0.4f };
		vec2 = { -0.4f, 16.0f, -2.4f };
		vec3 = { 0.2f, 18.0f, -2.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		

		//Chest LEFTSIDE
		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-4.2f, 21.0f, -2.8f);
		glVertex3f(-4.2f, 21.0f, -0.4f);
		glVertex3f(0.2f, 21.0f, -0.4f);
		glVertex3f(0.2f, 21.0f, -2.8f);
		glEnd();
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_chest);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chest.bmWidth, BMP_chest.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chest.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_chest1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chest1.bmWidth, BMP_chest1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chest1.bmBits);
		}
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.2f, 21.0f, -0.4f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.2f, 18.0f, -0.4f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, 18.0f, -0.4f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, 21.0f, -0.4f);
		glEnd();
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);

			//back
			glBindTexture(GL_TEXTURE_2D, tex_chestback);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chestback.bmWidth, BMP_chestback.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chestback.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);

			//back
			glBindTexture(GL_TEXTURE_2D, tex_chestback1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chestback1.bmWidth, BMP_chestback1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chestback1.bmBits);
		}
		glColor4f(1, 1, 1, 0);
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.2f, 21.0f, -2.8f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.2f, 18.0f, -2.8f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, 18.0f, -2.8f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, 21.0f, -2.8f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}
		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-4.2f, 21.0f, -2.8f);
		glVertex3f(-4.2f, 18.0f, -2.8f);
		glVertex3f(-4.2f, 18.0f, -0.4f);
		glVertex3f(-4.2f, 21.0f, -0.4f);
		glEnd();

		//Chest RIGHTSIDE
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_chest);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chest.bmWidth, BMP_chest.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chest.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_chest1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chest1.bmWidth, BMP_chest1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chest1.bmBits);
		}
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, 21.0f, -0.4f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, 18.0f, -0.4f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.2f, 18.0f, -0.4f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.2f, 21.0f, -0.4f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_chestback);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chestback.bmWidth, BMP_chestback.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chestback.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_chestback1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chestback1.bmWidth, BMP_chestback1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chestback1.bmBits);
		}
		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, 21.0f, -2.8f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, 18.0f, -2.8f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.2f, 18.0f, -2.8f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.2f, 21.0f, -2.8f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}
		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(0.2f, 21.0f, -0.4f);
		glVertex3f(0.2f, 18.0f, -0.4f);
		glVertex3f(0.2f, 18.0f, -2.8f);
		glVertex3f(0.2f, 21.0f, -2.8f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_chestbackdeco1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chestbackdeco1.bmWidth, BMP_chestbackdeco1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chestbackdeco1.bmBits);

		//Chestback deco
		//back
		vec1 = { -2.8f, 19.5f, -3.2f };
		vec2 = { -2.8f, 18.0f, -3.4f };
		vec3 = { -1.2f, 18.0f, -3.4f };
		vec4 = { -1.2f, 19.5f, -3.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//left
		vec1 = { -2.8f, 19.5f, -3.2f };
		vec2 = { -2.8f, 18.0f, -3.4f };
		vec3 = { -2.8f, 18.0f, -2.8f };
		vec4 = { -2.8f, 19.5f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//right
		vec1 = { -1.2f, 19.5f, -3.2f };
		vec2 = { -1.2f, 18.0f, -3.4f };
		vec3 = { -1.2f, 18.0f, -2.8f };
		vec4 = { -1.2f, 19.5f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -2.8f, 19.5f, -3.2f };
		vec2 = { -2.8f, 19.5f, -2.8f };
		vec3 = { -1.2f, 19.5f, -2.8f };
		vec4 = { -1.2f, 19.5f, -3.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//bottom
		vec1 = { -2.8f, 18.0f, -3.4f };
		vec2 = { -2.8f, 18.0f, -2.8f };
		vec3 = { -1.2f, 18.0f, -2.8f };
		vec4 = { -1.2f, 18.0f, -3.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//chestback circle 1

		glBindTexture(GL_TEXTURE_2D, tex_chestbackdeco2);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chestbackdeco2.bmWidth, BMP_chestbackdeco2.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chestbackdeco2.bmBits);

		//back
		vec1 = { -3.6f, 19.2f, -3.0f };
		vec2 = { -3.6f, 18.2f, -3.0f };
		vec3 = { -2.8f, 18.2f, -3.0f };
		vec4 = { -2.8f, 19.2f, -3.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//left
		vec1 = { -3.6f, 19.2f, -3.0f };
		vec2 = { -3.6f, 18.2f, -3.0f };
		vec3 = { -3.6f, 18.2f, -2.8f };
		vec4 = { -3.6f, 19.2f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -3.6f, 19.2f, -3.0f };
		vec2 = { -3.6f, 19.2f, -2.8f };
		vec3 = { -2.8f, 19.2f, -2.8f };
		vec4 = { -2.8f, 19.2f, -3.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -3.6f, 18.2f, -3.0f };
		vec2 = { -3.6f, 18.2f, -2.8f };
		vec3 = { -2.8f, 18.2f, -2.8f };
		vec4 = { -2.8f, 18.2f, -3.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();
		
		//chestback circle
		glTranslatef(2.4,0,0);
		//back
		glBindTexture(GL_TEXTURE_2D, tex_chestbackdeco2);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_chestbackdeco2.bmWidth, BMP_chestbackdeco2.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_chestbackdeco2.bmBits);

		vec1 = { -3.6f, 19.2f, -3.0f };
		vec2 = { -3.6f, 18.2f, -3.0f };
		vec3 = { -2.8f, 18.2f, -3.0f };
		vec4 = { -2.8f, 19.2f, -3.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		//right
		vec1 = { -2.8f, 19.2f, -3.0f };
		vec2 = { -2.8f, 18.2f, -3.0f };
		vec3 = { -2.8f, 18.2f, -2.8f };
		vec4 = { -2.8f, 19.2f, -2.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -3.6f, 19.2f, -3.0f };
		vec2 = { -3.6f, 19.2f, -2.8f };
		vec3 = { -2.8f, 19.2f, -2.8f };
		vec4 = { -2.8f, 19.2f, -3.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -3.6f, 18.2f, -3.0f };
		vec2 = { -3.6f, 18.2f, -2.8f };
		vec3 = { -2.8f, 18.2f, -2.8f };
		vec4 = { -2.8f, 18.2f, -3.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();
		glTranslatef(-2.4, 0, 0);

		//movepoint
		//////////////////////////////////////
		glPushMatrix();
		//////////////////////////////////////
		//////move shoulder left
		glTranslatef(-4.2, 20.5, -1.75);
		glRotatef(rotateX6, 1, 0, 0);
		glRotatef(rotateY6, 0, 1, 0);
		glRotatef(rotateZ6, 0, 0, 1);
		glTranslatef(4.2, -20.5, 1.75);
		/////////////////////////////////////////

		//LEFT ARM
		//Left shoulder
		//front
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_shoulder);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulder.bmWidth, BMP_shoulder.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulder.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_shoulder1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulder1.bmWidth, BMP_shoulder1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulder1.bmBits);
		}
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-6.0f, 22.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.0f, 19.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.2f, 19.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.2f, 22.0f, -1.0f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_shoulderback);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulderback.bmWidth, BMP_shoulderback.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulderback.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_shoulderback1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulderback1.bmWidth, BMP_shoulderback1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulderback1.bmBits);
		}
		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-6.0f, 22.0f, -2.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.0f, 19.0f, -2.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.2f, 19.0f, -2.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.2f, 22.0f, -2.5f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}
		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-6.0f, 22.0f, -2.5f);
		glVertex3f(-6.0f, 19.0f, -2.5f);
		glVertex3f(-6.0f, 19.0f, -1.0f);
		glVertex3f(-6.0f, 22.0f, -1.0f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-4.199f, 22.0f, -2.5f);
		glVertex3f(-4.199f, 19.0f, -2.5f);
		glVertex3f(-4.199f, 19.0f, -1.0f);
		glVertex3f(-4.199f, 22.0f, -1.0f);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-6.0f, 22.0f, -2.5f);
		glVertex3f(-6.0f, 22.0f, -1.0f);
		glVertex3f(-4.2f, 22.0f, -1.0f);
		glVertex3f(-4.2f, 22.0f, -2.5f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-6.0f, 19.0f, -2.5f);
		glVertex3f(-6.0f, 19.0f, -1.0f);
		glVertex3f(-4.2f, 19.0f, -1.0f);
		glVertex3f(-4.2f, 19.0f, -2.5f);
		glEnd();

		//Elbow
		//front

		glBindTexture(GL_TEXTURE_2D, tex_darkgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_darkgrey.bmWidth, BMP_darkgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_darkgrey.bmBits);


		glBegin(GL_TRIANGLES);
		vec1 = { -5.7f, 19.0f, -1.2f };
		vec2 = { -5.6f, 17.5f, -1.3f };
		vec3 = { -4.6f, 17.5f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.7f, 19.0f, -1.2f };
		vec2 = { -4.6f, 17.5f, -1.3f };
		vec3 = { -4.5f, 19.0f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -5.6f, 17.5f, -2.2f };
		vec3 = { -4.6f, 17.5f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -4.6f, 17.5f, -2.2f };
		vec3 = { -4.5f, 19.0f, -2.3f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -5.6f, 17.5f, -2.2f };
		vec3 = { -5.6f, 17.5f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -5.6f, 17.5f, -1.3f };
		vec3 = { -5.7f, 19.0f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -4.5f, 19.0f, -1.2f };
		vec2 = { -4.6f, 17.5f, -1.3f };
		vec3 = { -4.6f, 17.5f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.5f, 19.0f, -1.2f };
		vec2 = { -4.6f, 17.5f, -2.2f };
		vec3 = { -4.5f, 19.0f, -2.3f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//bottom
		glBegin(GL_TRIANGLES);
		vec1 = { -5.6f, 17.5f, -2.2f };
		vec2 = { -5.6f, 17.5f, -1.3f };
		vec3 = { -4.6f, 17.5f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.6f, 17.5f, -1.3f };
		vec2 = { -4.6f, 17.5f, -1.2f };
		vec3 = { -4.6f, 17.5f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//shoulder deco
		//front
		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-6.5f, 21.6f, -1.5f);
		glVertex3f(-6.5f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 21.6f, -1.5f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-6.5f, 21.6f, -2.0f);
		glVertex3f(-6.5f, 20.0f, -2.0f);
		glVertex3f(-6.0f, 20.0f, -2.0f);
		glVertex3f(-6.0f, 21.6f, -2.0f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-6.5f, 21.6f, -2.0f);
		glVertex3f(-6.5f, 20.0f, -2.0f);
		glVertex3f(-6.5f, 20.0f, -1.5f);
		glVertex3f(-6.5f, 21.6f, -1.5f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-6.5f, 20.0f, -2.0f);
		glVertex3f(-6.5f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 20.0f, -2.0f);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-6.5f, 21.6f, -2.0f);
		glVertex3f(-6.5f, 21.6f, -1.5f);
		glVertex3f(-6.0f, 21.6f, -1.5f);
		glVertex3f(-6.0f, 21.6f, -2.0f);
		glEnd();

		//shoulder deco2
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-6.4f, 23.0f, -1.65f);
		glVertex3f(-6.4f, 21.6f, -1.65f);
		glVertex3f(-6.15f, 21.6f, -1.65f);
		glVertex3f(-6.15f, 23.0f, -1.65f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-6.4f, 23.0f, -1.85f);
		glVertex3f(-6.4f, 21.6f, -1.85f);
		glVertex3f(-6.15f, 21.6f, -1.85f);
		glVertex3f(-6.15f, 23.0f, -1.85f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-6.4f, 23.0f, -1.85f);
		glVertex3f(-6.4f, 21.6f, -1.85f);
		glVertex3f(-6.4f, 21.6f, -1.65f);
		glVertex3f(-6.4f, 23.0f, -1.65f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-6.15f, 23.0f, -1.85f);
		glVertex3f(-6.15f, 21.6f, -1.85f);
		glVertex3f(-6.15f, 21.6f, -1.65f);
		glVertex3f(-6.15f, 23.0f, -1.65f);
		glEnd();

		//shoulder deco3
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.0f };
		vec2 = { -6.4f, 23.0f, -1.65f };
		vec3 = { -6.15f, 23.0f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.0f };
		vec2 = { -6.15f, 23.0f, -1.65f };
		vec3 = { -6.15f, 24.5f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 23.0f, -1.85f };
		vec3 = { -6.15f, 23.0f, -1.85f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.15f, 23.0f, -1.85f };
		vec3 = { -6.15f, 24.5f, -2.20f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 23.0f, -1.85f };
		vec3 = { -6.4f, 23.0f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 23.0f, -1.65f };
		vec3 = { -6.4f, 24.5f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -6.15f, 24.5f, -2.20f };
		vec2 = { -6.15f, 23.0f, -1.85f };
		vec3 = { -6.15f, 23.0f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.15f, 24.5f, -2.20f };
		vec2 = { -6.15f, 23.0f, -1.65f };
		vec3 = { -6.15f, 24.5f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 24.5f, -2.0f };
		vec3 = { -6.15f, 24.5f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.15f, 24.5f, -2.0f };
		vec3 = { -6.15f, 24.5f, -2.20f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//movepoint
		//////////////////////////////////////
		//////////////////////////////////////
		//////move forehand left
		glTranslatef(-5.1, 17.5, -1.75);
		glRotatef(rotateX7, 1, 0, 0);
		glRotatef(rotateY7, 0, 1, 0);
		glRotatef(rotateZ7, 0, 0, 1);
		glTranslatef(5.1, -17.5, 1.75);
		/////////////////////////////////////////
		//--------------------------------------------------------WEAPON PART----------------------------------------------------------
		glBindTexture(GL_TEXTURE_2D, tex_swordcolour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_swordcolour.bmWidth, BMP_swordcolour.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_swordcolour.bmBits);
		if (weapon == 1) {
			//--------------------------Sword-----------------------
			//side view
			//holding part
			vec1 = { -5.2f, 14.3f, -2.6f };
			vec2 = { -5.2f, 13.2f, -2.6f };
			vec3 = { -5.2f, 13.2f, -2.25f };
			vec4 = { -5.2f, 14.3f, -2.25f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.0f, 14.1f, -2.25f };
			vec2 = { -5.0f, 13.4f, -2.25f };
			vec3 = { -5.0f, 13.4f, -1.1f };
			vec4 = { -5.0f, 14.1f, -1.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.2f, 14.5f, -1.1f };
			vec2 = { -5.2f, 13.0f, -1.1f };
			vec3 = { -5.2f, 13.0f, -0.6f };
			vec4 = { -5.2f, 14.5f, -0.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -4.8f, 14.5f, -1.1f };
			vec2 = { -4.8f, 13.0f, -1.1f };
			vec3 = { -4.8f, 13.0f, -0.6f };
			vec4 = { -4.8f, 14.5f, -0.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();


			//---sword part---
			vec1 = { -5.0f, 14.2f, -0.6f };
			vec2 = { -5.0f, 13.3f, -0.6f };
			vec3 = { -5.0f, 13.3f, 2.8f };
			vec4 = { -5.0f, 14.2f, 2.8f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();
			//sharp
			glBegin(GL_TRIANGLES);
			vec1 = { -5.0f, 14.2f, 2.8f };
			vec2 = { -5.0f, 13.3f, 2.8f };
			vec3 = { -5.0f, 13.75f, 3.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glEnd();

			//sword front view
			vec1 = { -5.2f, 14.5f, -0.6f };
			vec2 = { -5.2f, 13.0f, -0.6f };
			vec3 = { -4.8f, 13.0f, -0.6f };
			vec4 = { -4.8f, 14.5f, -0.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.2f, 14.3f, -2.25f };
			vec2 = { -5.2f, 13.2f, -2.25f };
			vec3 = { -4.8f, 13.2f, -2.25f };
			vec4 = { -4.8f, 14.3f, -2.25f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//sword back view
			vec1 = { -5.2f, 14.5f, -1.1f };
			vec2 = { -5.2f, 13.0f, -1.1f };
			vec3 = { -4.8f, 13.0f, -1.1f };
			vec4 = { -4.8f, 14.5f, -1.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.2f, 14.3f, -2.6f };
			vec2 = { -5.2f, 13.2f, -2.6f };
			vec3 = { -4.8f, 13.2f, -2.6f };
			vec4 = { -4.8f, 14.3f, -2.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//sword top view
			vec1 = { -5.2f, 14.3f, -2.6f };
			vec2 = { -4.8f, 14.3f, -2.6f };
			vec3 = { -4.8f, 14.3f, -2.25f };
			vec4 = { -5.2f, 14.3f, -2.25f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.2f, 14.5f, -1.1f };
			vec2 = { -4.8f, 14.5f, -1.1f };
			vec3 = { -4.8f, 14.5f, -0.6f };
			vec4 = { -5.2f, 14.5f, -0.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.05f, 14.2f, -0.6f };
			vec2 = { -4.95f, 14.19f, -0.6f };
			vec3 = { -4.95f, 14.19f, 2.8f };
			vec4 = { -5.05f, 14.2f, 2.8f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();


			vec1 = { -5.05f, 14.2f, 2.8f };
			vec2 = { -4.95f, 14.2f, 2.8f };
			vec3 = { -4.95f, 13.75f, 3.5f };
			vec4 = { -5.05f, 13.75f, 3.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//sword bottom view
			vec1 = { -5.2f, 13.2f, -2.6f };
			vec2 = { -4.8f, 13.2f, -2.6f };
			vec3 = { -4.8f, 13.2f, -2.25f };
			vec4 = { -5.2f, 13.2f, -2.25f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.2f, 13.0f, -1.1f };
			vec2 = { -4.8f, 13.0f, -1.1f };
			vec3 = { -4.8f, 13.0f, -0.6f };
			vec4 = { -5.2f, 13.0f, -0.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.05f, 13.3f, -0.6f };
			vec2 = { -4.96f, 13.29f, -0.6f };
			vec3 = { -4.96f, 13.29f, 2.8f };
			vec4 = { -5.05f, 13.3f, 2.8f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();


			vec1 = { -5.05f, 13.3f, 2.8f };
			vec2 = { -4.95f, 13.3f, 2.8f };
			vec3 = { -4.95f, 13.75f, 3.5f };
			vec4 = { -5.05f, 13.75f, 3.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();
		}
		else if (weapon == 2) {
			//---------------------BAZOOKA----------------------
			if (animation == 8 && animationMoveY<-6) {
				missileY -= 0.5;

				glTranslatef(0,missileY,0);
				//missle left view
				vec1 = { -5.3f, 11.2f, -0.6f };
				vec2 = { -5.3f, 10.3f, -0.7f };
				vec3 = { -5.3f, 10.3f, 0.1f };
				vec4 = { -5.3f, 11.2f, 0.0f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				vec1 = { -5.3f, 10.3f, -0.7f };
				vec2 = { -5.3f, 9.9f, -0.7f };
				vec3 = { -5.3f, 9.9f, 0.1f };
				vec4 = { -5.3f, 10.3f, 0.1f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				glBegin(GL_TRIANGLES);
				vec1 = { -5.3f, 9.9f, -0.7f };
				vec2 = { -5.0f, 8.8f, -0.3f };
				vec3 = { -5.3f, 9.9f, 0.1f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glEnd();

				//missle right view
				vec1 = { -4.7f, 11.2f, -0.6f };
				vec2 = { -4.7f, 10.3f, -0.7f };
				vec3 = { -4.7f, 10.3f, 0.1f };
				vec4 = { -4.7f, 11.2f, 0.0f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				vec1 = { -4.7f, 10.3f, -0.7f };
				vec2 = { -4.7f, 9.9f, -0.7f };
				vec3 = { -4.7f, 9.9f, 0.1f };
				vec4 = { -4.7f, 10.3f, 0.1f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				glBegin(GL_TRIANGLES);
				vec1 = { -4.7f, 9.9f, -0.7f };
				vec2 = { -5.0f, 8.8f, -0.3f };
				vec3 = { -4.7f, 9.9f, 0.1f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glEnd();

				//missle part
				vec1 = { -5.3f, 11.2f, 0.0f };
				vec2 = { -5.3f, 10.3f, 0.1f };
				vec3 = { -4.7f, 10.3f, 0.1f };
				vec4 = { -4.7f, 11.2f, 0.0f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				vec1 = { -5.3f, 10.3f, 0.1f };
				vec2 = { -5.3f, 9.9f, 0.1f };
				vec3 = { -4.7f, 9.9f, 0.1f };
				vec4 = { -4.7f, 10.3f, 0.1f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				glBegin(GL_TRIANGLES);
				vec1 = { -5.3f, 9.9f, 0.1f };
				vec2 = { -5.0f, 8.8f, -0.3f };
				vec3 = { -4.7f, 9.9f, 0.1f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glEnd();

				//missle back view
				vec1 = { -5.3f, 11.2f, -0.6f };
				vec2 = { -5.3f, 10.3f, -0.7f };
				vec3 = { -4.7f, 10.3f, -0.7f };
				vec4 = { -4.7f, 11.2f, -0.6f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				vec1 = { -5.3f, 10.3f, -0.7f };
				vec2 = { -5.3f, 9.9f, -0.7f };
				vec3 = { -4.7f, 9.9f, -0.7f };
				vec4 = { -4.7f, 10.3f, -0.7f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();

				glBegin(GL_TRIANGLES);
				vec1 = { -5.3f, 9.9f, -0.7f };
				vec2 = { -5.0f, 8.8f, -0.3f };
				vec3 = { -4.7f, 9.9f, -0.7f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glEnd();


				//bottom view
				vec1 = { -5.5f, 11.2f, -0.8f };
				vec2 = { -4.5f, 11.2f, -0.8f };
				vec3 = { -4.5f, 11.2f, 0.2f };
				vec4 = { -5.5f, 11.2f, 0.2f };
				vnormal = getSurfaceNormal(vec1, vec2, vec3);
				glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
				glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
				glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
				glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
				glEnd();
				glTranslatef(0, -missileY, 0);
			}



			//side view
			//holding part
			vec1 = { -5.1f, 14.3f, -2.5f };
			vec2 = { -5.1f, 13.2f, -2.5f };
			vec3 = { -5.1f, 13.2f, -0.8f };
			vec4 = { -5.1f, 14.3f, -0.8f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -4.9f, 14.3f, -2.5f };
			vec2 = { -4.9f, 13.2f, -2.5f };
			vec3 = { -4.9f, 13.2f, -0.8f };
			vec4 = { -4.9f, 14.3f, -0.8f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//gun part
			//left view
			vec1 = { -5.5f, 15.8f, -0.8f };
			vec2 = { -5.5f, 11.2f, -0.8f };
			vec3 = { -5.5f, 11.2f, 0.2f };
			vec4 = { -5.5f, 15.8f, 0.2f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.5f, 17.5f, -0.6f };
			vec2 = { -5.5f, 15.8f, -0.8f };
			vec3 = { -5.5f, 15.8f, 0.2f };
			vec4 = { -5.5f, 17.5f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.5f, 18.5f, -1.0f };
			vec2 = { -5.5f, 17.5f, -0.6f };
			vec3 = { -5.5f, 17.5f, 0.0f };
			vec4 = { -5.5f, 18.5f, 0.4f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//missle left view
			vec1 = { -5.3f, 11.2f, -0.6f };
			vec2 = { -5.3f, 10.3f, -0.7f };
			vec3 = { -5.3f, 10.3f, 0.1f };
			vec4 = { -5.3f, 11.2f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.3f, 10.3f, -0.7f };
			vec2 = { -5.3f, 9.9f, -0.7f };
			vec3 = { -5.3f, 9.9f, 0.1f };
			vec4 = { -5.3f, 10.3f, 0.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			glBegin(GL_TRIANGLES);
			vec1 = { -5.3f, 9.9f, -0.7f };
			vec2 = { -5.0f, 8.8f, -0.3f };
			vec3 = { -5.3f, 9.9f, 0.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glEnd();

			//gun part
			//right view
			vec1 = { -4.5f, 15.8f, -0.8f };
			vec2 = { -4.5f, 11.2f, -0.8f };
			vec3 = { -4.5f, 11.2f, 0.2f };
			vec4 = { -4.5f, 15.8f, 0.2f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -4.5f, 17.5f, -0.6f };
			vec2 = { -4.5f, 15.8f, -0.8f };
			vec3 = { -4.5f, 15.8f, 0.2f };
			vec4 = { -4.5f, 17.5f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -4.5f, 18.5f, -1.0f };
			vec2 = { -4.5f, 17.5f, -0.6f };
			vec3 = { -4.5f, 17.5f, 0.0f };
			vec4 = { -4.5f, 18.5f, 0.4f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//missle right view
			vec1 = { -4.7f, 11.2f, -0.6f };
			vec2 = { -4.7f, 10.3f, -0.7f };
			vec3 = { -4.7f, 10.3f, 0.1f };
			vec4 = { -4.7f, 11.2f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -4.7f, 10.3f, -0.7f };
			vec2 = { -4.7f, 9.9f, -0.7f };
			vec3 = { -4.7f, 9.9f, 0.1f };
			vec4 = { -4.7f, 10.3f, 0.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			glBegin(GL_TRIANGLES);
			vec1 = { -4.7f, 9.9f, -0.7f };
			vec2 = { -5.0f, 8.8f, -0.3f };
			vec3 = { -4.7f, 9.9f, 0.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glEnd();


			//front view
			//holding part
			vec1 = { -5.1f, 14.3f, -0.8f };
			vec2 = { -5.1f, 13.2f, -0.8f };
			vec3 = { -4.9f, 13.2f, -0.8f };
			vec4 = { -4.9f, 14.3f, -0.8f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//gun part
			vec1 = { -5.5f, 18.5f, 0.4f };
			vec2 = { -5.5f, 17.5f, 0.0f };
			vec3 = { -4.5f, 17.5f, 0.0f };
			vec4 = { -4.5f, 18.5f, 0.4f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.5f, 17.5f, 0.0f };
			vec2 = { -5.5f, 15.8f, 0.2f };
			vec3 = { -4.5f, 15.8f, 0.2f };
			vec4 = { -4.5f, 17.5f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.5f, 15.8f, 0.2f };
			vec2 = { -5.5f, 11.2f, 0.2f };
			vec3 = { -4.5f, 11.2f, 0.2f };
			vec4 = { -4.5f, 15.8f, 0.2f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//missle part
			vec1 = { -5.3f, 11.2f, 0.0f };
			vec2 = { -5.3f, 10.3f, 0.1f };
			vec3 = { -4.7f, 10.3f, 0.1f };
			vec4 = { -4.7f, 11.2f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.3f, 10.3f, 0.1f };
			vec2 = { -5.3f, 9.9f, 0.1f };
			vec3 = { -4.7f, 9.9f, 0.1f };
			vec4 = { -4.7f, 10.3f, 0.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			glBegin(GL_TRIANGLES);
			vec1 = { -5.3f, 9.9f, 0.1f };
			vec2 = { -5.0f, 8.8f, -0.3f };
			vec3 = { -4.7f, 9.9f, 0.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glEnd();

			//back view
			//holding part
			vec1 = { -5.1f, 14.3f, -2.5f };
			vec2 = { -5.1f, 13.2f, -2.5f };
			vec3 = { -4.9f, 13.2f, -2.5f };
			vec4 = { -4.9f, 14.3f, -2.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//gun part
			//back view
			vec1 = { -5.5f, 15.8f, -0.8f };
			vec2 = { -5.5f, 11.2f, -0.8f };
			vec3 = { -4.5f, 11.2f, -0.8f };
			vec4 = { -4.5f, 15.8f, -0.8f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.5f, 17.5f, -0.6f };
			vec2 = { -5.5f, 15.8f, -0.8f };
			vec3 = { -4.5f, 15.8f, -0.8f };
			vec4 = { -4.5f, 17.5f, -0.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.5f, 18.5f, -1.0f };
			vec2 = { -5.5f, 17.5f, -0.6f };
			vec3 = { -4.5f, 17.5f, 0.0f };
			vec4 = { -4.5f, 18.5f, 0.4f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//missle back view
			vec1 = { -5.3f, 11.2f, -0.6f };
			vec2 = { -5.3f, 10.3f, -0.7f };
			vec3 = { -4.7f, 10.3f, -0.7f };
			vec4 = { -4.7f, 11.2f, -0.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { -5.3f, 10.3f, -0.7f };
			vec2 = { -5.3f, 9.9f, -0.7f };
			vec3 = { -4.7f, 9.9f, -0.7f };
			vec4 = { -4.7f, 10.3f, -0.7f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			glBegin(GL_TRIANGLES);
			vec1 = { -5.3f, 9.9f, -0.7f };
			vec2 = { -5.0f, 8.8f, -0.3f };
			vec3 = { -4.7f, 9.9f, -0.7f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glEnd();

			//top view
			vec1 = { -5.5f, 18.5f, -1.0f };
			vec2 = { -4.5f, 18.5f, -1.0f };
			vec3 = { -4.5f, 18.5f, 0.4f };
			vec4 = { -5.5f, 18.5f, 0.4f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//bottom view
			vec1 = { -5.5f, 11.2f, -0.8f };
			vec2 = { -4.5f, 11.2f, -0.8f };
			vec3 = { -4.5f, 11.2f, 0.2f };
			vec4 = { -5.5f, 11.2f, 0.2f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

		}


		//forehand
		//front
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_forehand);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehand.bmWidth, BMP_forehand.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehand.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_forehand1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehand1.bmWidth, BMP_forehand1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehand1.bmBits);
		}
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.8f, 17.5f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.8f, 14.5f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -1.0f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.8f, 17.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.8f, 14.5f, -2.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -2.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -2.5f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_forehandside);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehandside.bmWidth, BMP_forehandside.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehandside.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_forehandside1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehandside1.bmWidth, BMP_forehandside1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehandside1.bmBits);
		}
		
		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.8f, 17.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.8f, 14.5f, -2.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-5.8f, 14.5f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-5.8f, 17.5f, -1.0f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -2.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -1.0f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-5.8f, 17.5f, -2.5f);
		glVertex3f(-5.8f, 17.5f, -1.0f);
		glVertex3f(-4.4f, 17.5f, -1.0f);
		glVertex3f(-4.4f, 17.5f, -2.5f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-5.8f, 14.5f, -2.5f);
		glVertex3f(-5.8f, 14.5f, -1.0f);
		glVertex3f(-4.4f, 14.5f, -1.0f);
		glVertex3f(-4.4f, 14.5f, -2.5f);
		glEnd();

		//forehand deco 1
		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);


		//left
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 0);
		glVertex3f(-6.1f, 17.5f, -2.0f);
		glVertex3f(-6.1f, 17.1f, -2.0f);
		glVertex3f(-6.1f, 16.9f, -1.85f);
		glVertex3f(-6.1f, 16.9f, -1.65f);
		glVertex3f(-6.1f, 17.1f, -1.5f);
		glVertex3f(-6.1f, 17.5f, -1.5f);
		glEnd();

		//front
		vec1 = { -6.1f, 17.5f, -1.5f };
		vec2 = { -6.1f, 17.1f, -1.5f };
		vec3 = { -5.8f, 17.1f, -1.5f };
		vec4 = { -5.8f, 17.5f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front2
		vec1 = { -6.1f, 17.1f, -1.5f };
		vec2 = { -6.1f, 16.9f, -1.65f };
		vec3 = { -5.8f, 16.9f, -1.65f };
		vec4 = { -5.8f, 17.1f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -6.1f, 17.5f, -2.0f };
		vec2 = { -6.1f, 17.1f, -2.0f };
		vec3 = { -5.8f, 17.1f, -2.0f };
		vec4 = { -5.8f, 17.5f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back2
		vec1 = { -6.1f, 17.1f, -2.0f };
		vec2 = { -6.1f, 16.9f, -1.85f };
		vec3 = { -5.8f, 16.9f, -1.85f };
		vec4 = { -5.8f, 17.1f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//bottom
		vec1 = { -6.1f, 16.9f, -1.85f };
		vec2 = { -6.1f, 16.9f, -1.65f };
		vec3 = { -5.8f, 16.9f, -1.65f };
		vec4 = { -5.8f, 16.9f, -1.85f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -6.1f, 17.5f, -2.0f };
		vec2 = { -6.1f, 17.5f, -1.5f };
		vec3 = { -5.8f, 17.5f, -1.5f };
		vec4 = { -5.8f, 17.5f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//forehand deco 2
		//left
		vec1 = { -6.0f, 16.9f, -1.85f };
		vec2 = { -6.0f, 16.0f, -1.85f };
		vec3 = { -6.0f, 16.0f, -1.65f };
		vec4 = { -6.0f, 16.9f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -6.0f, 16.9f, -1.65f };
		vec2 = { -6.0f, 16.0f, -1.65f };
		vec3 = { -5.8f, 16.0f, -1.65f };
		vec4 = { -5.8f, 16.9f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -6.0f, 16.9f, -1.85f };
		vec2 = { -6.0f, 16.0f, -1.85f };
		vec3 = { -5.8f, 16.0f, -1.85f };
		vec4 = { -5.8f, 16.9f, -1.85f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//forehand deco 3
		//left
		vec1 = { -6.1f, 16.0f, -1.9f };
		vec2 = { -6.1f, 15.5f, -1.9f };
		vec3 = { -6.1f, 15.5f, -1.6f };
		vec4 = { -6.1f, 16.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -6.1f, 16.0f, -1.6f };
		vec2 = { -6.1f, 15.5f, -1.6f };
		vec3 = { -5.8f, 15.5f, -1.6f };
		vec4 = { -5.8f, 16.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -6.1f, 16.0f, -1.9f };
		vec2 = { -6.1f, 15.5f, -1.9f };
		vec3 = { -5.8f, 15.5f, -1.9f };
		vec4 = { -5.8f, 16.0f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//bottom
		vec1 = { -6.1f, 15.5f, -1.9f };
		vec2 = { -6.1f, 15.5f, -1.6f };
		vec3 = { -5.8f, 15.5f, -1.6f };
		vec4 = { -5.8f, 15.5f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -6.1f, 16.0f, -1.9f };
		vec2 = { -6.1f, 16.0f, -1.6f };
		vec3 = { -5.8f, 16.0f, -1.6f };
		vec4 = { -5.8f, 16.0f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//hand
		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-5.5f, 14.5f, -1.2f);
		glVertex3f(-5.5f, 13.5f, -1.2f);
		glVertex3f(-5.1f, 13.5f, -1.2f);
		glVertex3f(-5.1f, 14.5f, -1.2f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-5.5f, 14.5f, -2.2f);
		glVertex3f(-5.5f, 13.5f, -2.2f);
		glVertex3f(-5.1f, 13.5f, -2.2f);
		glVertex3f(-5.1f, 14.5f, -2.2f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-5.5f, 14.5f, -2.2f);
		glVertex3f(-5.5f, 13.5f, -2.2f);
		glVertex3f(-5.5f, 13.5f, -1.2f);
		glVertex3f(-5.5f, 14.5f, -1.2f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, -1);
		glVertex3f(-5.1f, 14.5f, -2.2f);
		glVertex3f(-5.1f, 13.5f, -2.2f);
		glVertex3f(-5.1f, 13.5f, -1.2f);
		glVertex3f(-5.1f, 14.5f, -1.2f);
		glEnd();

		//4finger
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-5.4f, 13.5f, -1.2f);
		glVertex3f(-5.4f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -1.2f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-5.4f, 13.5f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -2.2f);
		glVertex3f(-4.8f, 13.1f, -2.2f);
		glVertex3f(-4.8f, 13.5f, -2.2f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-5.4f, 13.5f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -1.2f);
		glVertex3f(-5.4f, 13.5f, -1.2f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-4.8f, 13.5f, -2.2f);
		glVertex3f(-4.8f, 13.1f, -2.2f);
		glVertex3f(-4.8f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -1.2f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-5.4f, 13.1f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.1f, -2.2f);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-5.4f, 13.5f, -2.2f);
		glVertex3f(-5.4f, 13.5f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -2.2f);
		glEnd();

		//thumb
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-5.0f, 14.5f, -1.1f);
		glVertex3f(-5.0f, 13.8f, -1.1f);
		glVertex3f(-4.7f, 13.8f, -1.1f);
		glVertex3f(-4.7f, 14.5f, -1.1f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-5.0f, 14.5f, -1.5f);
		glVertex3f(-5.0f, 13.8f, -1.5f);
		glVertex3f(-4.7f, 13.8f, -1.5f);
		glVertex3f(-4.7f, 14.5f, -1.5f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-5.0f, 14.5f, -1.5f);
		glVertex3f(-5.0f, 13.8f, -1.5f);
		glVertex3f(-5.0f, 13.8f, -1.1f);
		glVertex3f(-5.0f, 14.5f, -1.1f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-4.7f, 14.5f, -1.5f);
		glVertex3f(-4.7f, 13.8f, -1.5f);
		glVertex3f(-4.7f, 13.8f, -1.1f);
		glVertex3f(-4.7f, 14.5f, -1.1f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-5.0f, 13.8f, -1.5f);
		glVertex3f(-5.0f, 13.8f, -1.1f);
		glVertex3f(-4.7f, 13.8f, -1.1f);
		glVertex3f(-4.7f, 13.8f, -1.5f);
		glEnd();

		//End movepoint
		/////////////
		glPopMatrix();
		////////////

		//movepoint
		//////////////////////////////////////
		glPushMatrix();
		glTranslatef(6.2, 0, 0);
		//////////////////////////////////////
		//////move shoulder left
		glTranslatef(-4.2, 20.5, -1.75);
		glRotatef(rotateX8, 1, 0, 0);
		glRotatef(rotateY8, 0, 1, 0);
		glRotatef(rotateZ8, 0, 0, 1);
		glTranslatef(4.2, -20.5, 1.75);
		/////////////////////////////////////////

		//RIGHT ARM
		
		//Right shoulder
		//front
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_shoulder);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulder.bmWidth, BMP_shoulder.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulder.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_shoulder1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulder1.bmWidth, BMP_shoulder1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulder1.bmBits);
		}
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-6.0f, 22.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.0f, 19.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.2f, 19.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.2f, 22.0f, -1.0f);
		glEnd();

		
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_shoulderback);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulderback.bmWidth, BMP_shoulderback.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulderback.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_shoulderback1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_shoulderback1.bmWidth, BMP_shoulderback1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_shoulderback1.bmBits);
		}
		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-6.0f, 22.0f, -2.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.0f, 19.0f, -2.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.2f, 19.0f, -2.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.2f, 22.0f, -2.5f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}
		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-6.0f, 22.0f, -2.5f);
		glVertex3f(-6.0f, 19.0f, -2.5f);
		glVertex3f(-6.0f, 19.0f, -1.0f);
		glVertex3f(-6.0f, 22.0f, -1.0f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-4.199f, 22.0f, -2.5f);
		glVertex3f(-4.199f, 19.0f, -2.5f);
		glVertex3f(-4.199f, 19.0f, -1.0f);
		glVertex3f(-4.199f, 22.0f, -1.0f);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-6.0f, 22.0f, -2.5f);
		glVertex3f(-6.0f, 22.0f, -1.0f);
		glVertex3f(-4.2f, 22.0f, -1.0f);
		glVertex3f(-4.2f, 22.0f, -2.5f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-6.0f, 19.0f, -2.5f);
		glVertex3f(-6.0f, 19.0f, -1.0f);
		glVertex3f(-4.2f, 19.0f, -1.0f);
		glVertex3f(-4.2f, 19.0f, -2.5f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_darkgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_darkgrey.bmWidth, BMP_darkgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_darkgrey.bmBits);

		//shoulder deco
		glTranslatef(2.3, 0, 0);
		//front
		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-6.5f, 21.6f, -1.5f);
		glVertex3f(-6.5f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 21.6f, -1.5f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-6.5f, 21.6f, -2.0f);
		glVertex3f(-6.5f, 20.0f, -2.0f);
		glVertex3f(-6.0f, 20.0f, -2.0f);
		glVertex3f(-6.0f, 21.6f, -2.0f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-6.0f, 21.6f, -2.0f);
		glVertex3f(-6.0f, 20.0f, -2.0f);
		glVertex3f(-6.0f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 21.6f, -1.5f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-6.5f, 20.0f, -2.0f);
		glVertex3f(-6.5f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 20.0f, -1.5f);
		glVertex3f(-6.0f, 20.0f, -2.0f);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-6.5f, 21.6f, -2.0f);
		glVertex3f(-6.5f, 21.6f, -1.5f);
		glVertex3f(-6.0f, 21.6f, -1.5f);
		glVertex3f(-6.0f, 21.6f, -2.0f);
		glEnd();

		//shoulder deco2
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-6.4f, 23.0f, -1.65f);
		glVertex3f(-6.4f, 21.6f, -1.65f);
		glVertex3f(-6.15f, 21.6f, -1.65f);
		glVertex3f(-6.15f, 23.0f, -1.65f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-6.4f, 23.0f, -1.85f);
		glVertex3f(-6.4f, 21.6f, -1.85f);
		glVertex3f(-6.15f, 21.6f, -1.85f);
		glVertex3f(-6.15f, 23.0f, -1.85f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-6.4f, 23.0f, -1.85f);
		glVertex3f(-6.4f, 21.6f, -1.85f);
		glVertex3f(-6.4f, 21.6f, -1.65f);
		glVertex3f(-6.4f, 23.0f, -1.65f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-6.15f, 23.0f, -1.85f);
		glVertex3f(-6.15f, 21.6f, -1.85f);
		glVertex3f(-6.15f, 21.6f, -1.65f);
		glVertex3f(-6.15f, 23.0f, -1.65f);
		glEnd();



		//shoulder deco3
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.0f };
		vec2 = { -6.4f, 23.0f, -1.65f };
		vec3 = { -6.15f, 23.0f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.0f };
		vec2 = { -6.15f, 23.0f, -1.65f };
		vec3 = { -6.15f, 24.5f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 23.0f, -1.85f };
		vec3 = { -6.15f, 23.0f, -1.85f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.15f, 23.0f, -1.85f };
		vec3 = { -6.15f, 24.5f, -2.20f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 23.0f, -1.85f };
		vec3 = { -6.4f, 23.0f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 23.0f, -1.65f };
		vec3 = { -6.4f, 24.5f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -6.15f, 24.5f, -2.20f };
		vec2 = { -6.15f, 23.0f, -1.85f };
		vec3 = { -6.15f, 23.0f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.15f, 24.5f, -2.20f };
		vec2 = { -6.15f, 23.0f, -1.65f };
		vec3 = { -6.15f, 24.5f, -2.0f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.4f, 24.5f, -2.0f };
		vec3 = { -6.15f, 24.5f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -6.4f, 24.5f, -2.20f };
		vec2 = { -6.15f, 24.5f, -2.0f };
		vec3 = { -6.15f, 24.5f, -2.20f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		glTranslatef(-2.3, 0, 0);

		//Elbow
		//front

		glBindTexture(GL_TEXTURE_2D, tex_darkgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_darkgrey.bmWidth, BMP_darkgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_darkgrey.bmBits);


		glBegin(GL_TRIANGLES);
		vec1 = { -5.7f, 19.0f, -1.2f };
		vec2 = { -5.6f, 17.5f, -1.3f };
		vec3 = { -4.6f, 17.5f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.7f, 19.0f, -1.2f };
		vec2 = { -4.6f, 17.5f, -1.3f };
		vec3 = { -4.5f, 19.0f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -5.6f, 17.5f, -2.2f };
		vec3 = { -4.6f, 17.5f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -4.6f, 17.5f, -2.2f };
		vec3 = { -4.5f, 19.0f, -2.3f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -5.6f, 17.5f, -2.2f };
		vec3 = { -5.6f, 17.5f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.7f, 19.0f, -2.3f };
		vec2 = { -5.6f, 17.5f, -1.3f };
		vec3 = { -5.7f, 19.0f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -4.5f, 19.0f, -1.2f };
		vec2 = { -4.6f, 17.5f, -1.3f };
		vec3 = { -4.6f, 17.5f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -4.5f, 19.0f, -1.2f };
		vec2 = { -4.6f, 17.5f, -2.2f };
		vec3 = { -4.5f, 19.0f, -2.3f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//bottom
		glBegin(GL_TRIANGLES);
		vec1 = { -5.6f, 17.5f, -2.2f };
		vec2 = { -5.6f, 17.5f, -1.3f };
		vec3 = { -4.6f, 17.5f, -1.3f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -5.6f, 17.5f, -1.3f };
		vec2 = { -4.6f, 17.5f, -1.2f };
		vec3 = { -4.6f, 17.5f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//movepoint
		//////////////////////////////////////
		//////////////////////////////////////
		//////move forehand left
		glTranslatef(-5.1, 17.5, -1.75);
		glRotatef(rotateX9, 1, 0, 0);
		glRotatef(rotateY9, 0, 1, 0);
		glRotatef(rotateZ9, 0, 0, 1);
		glTranslatef(5.1, -17.5, 1.75);
		/////////////////////////////////////////

		glTranslatef(-6.3, 0, 0);

		glBindTexture(GL_TEXTURE_2D, tex_swordcolour);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_swordcolour.bmWidth, BMP_swordcolour.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_swordcolour.bmBits);

		//--------------------------------Shield--------------------------------
		//left view
		if (shield) {
			vec1 = { 1.9f, 18.3f, -1.1f };
			vec2 = { 1.9f, 16.09f, -0.0f };
			vec3 = { 1.9f, 15.09f, -0.0f };
			vec4 = { 1.9f, 9.09f, -1.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 18.3f, -2.5f };
			vec2 = { 1.9f, 9.09f, -2.5f };
			vec3 = { 1.9f, 15.09f, -3.6f };
			vec4 = { 1.9f, 16.09f, -3.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 18.3f, -1.1f };
			vec2 = { 1.9f, 13.09f, -1.1f };
			vec3 = { 1.9f, 13.09f, -2.5f };
			vec4 = { 1.9f, 18.3f, -2.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//right view
			vec1 = { 2.7f, 18.3f, -1.1f };
			vec2 = { 2.7f, 16.09f, -0.0f };
			vec3 = { 2.7f, 15.09f, -0.0f };
			vec4 = { 2.7f, 9.09f, -1.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 2.7f, 18.3f, -2.5f };
			vec2 = { 2.7f, 9.09f, -2.5f };
			vec3 = { 2.7f, 15.09f, -3.6f };
			vec4 = { 2.7f, 16.09f, -3.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 2.7f, 18.3f, -1.1f };
			vec2 = { 2.7f, 13.09f, -1.1f };
			vec3 = { 2.7f, 13.09f, -2.5f };
			vec4 = { 2.7f, 18.3f, -2.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//front view
			vec1 = { 1.9f, 18.3f, -1.1f };
			vec2 = { 1.9f, 16.09f, 0.0f };
			vec3 = { 2.7f, 16.09f, 0.0f };
			vec4 = { 2.7f, 18.3f, -1.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 16.09f, 0.0f };
			vec2 = { 1.9f, 15.09f, 0.0f };
			vec3 = { 2.7f, 15.09f, 0.0f };
			vec4 = { 2.7f, 16.09f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 18.3f, -1.1f };
			vec2 = { 1.9f, 9.09f, -1.1f };
			vec3 = { 2.7f, 9.09f, -1.1f };
			vec4 = { 2.7f, 18.3f, -1.1f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 18.3f, -2.5f };
			vec2 = { 1.9f, 9.09f, -2.5f };
			vec3 = { 2.7f, 9.09f, -2.5f };
			vec4 = { 2.7f, 18.3f, -2.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 18.3f, -2.5f };
			vec2 = { 1.9f, 16.09f, -3.6f };
			vec3 = { 2.7f, 16.09f, -3.6f };
			vec4 = { 2.7f, 18.3f, -2.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 15.09f, 0.0f };
			vec2 = { 1.9f, 9.09f, -1.1f };
			vec3 = { 2.7f, 9.09f, -1.1f };
			vec4 = { 2.7f, 15.09f, 0.0f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			//top view
			vec1 = { 1.9f, 18.3f, -2.5f };
			vec2 = { 1.9f, 18.3f, -1.1f };
			vec3 = { 2.7f, 18.3f, -1.1f };
			vec4 = { 2.7f, 18.3f, -2.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 13.09f, -2.5f };
			vec2 = { 1.9f, 13.09f, -1.1f };
			vec3 = { 2.7f, 13.09f, -1.1f };
			vec4 = { 2.7f, 13.09f, -2.5f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

			vec1 = { 1.9f, 15.09f, -3.6f };
			vec2 = { 1.9f, 9.09f, -2.5f };
			vec3 = { 2.7f, 9.09f, -2.5f };
			vec4 = { 2.7f, 15.09f, -3.6f };
			vnormal = getSurfaceNormal(vec1, vec2, vec3);
			glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
			glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
			glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
			glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
			glEnd();

		}
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiffusecolour);

		glTranslatef(6.3, 0, 0);
		//------------------------------------------- END  WEAPON -------------------------------------------------------

		if (lightswitch == 0) {
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		}

		//forehand
		//front
		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_forehand);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehand.bmWidth, BMP_forehand.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehand.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_forehand1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehand1.bmWidth, BMP_forehand1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehand1.bmBits);
		}
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.8f, 17.5f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.8f, 14.5f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -1.0f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.8f, 17.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.8f, 14.5f, -2.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -2.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -2.5f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}
		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-5.8f, 17.5f, -2.5f);
		glVertex3f(-5.8f, 14.5f, -2.5f);
		glVertex3f(-5.8f, 14.5f, -1.0f);
		glVertex3f(-5.8f, 17.5f, -1.0f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_forehandside);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehandside.bmWidth, BMP_forehandside.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehandside.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_forehandside1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_forehandside1.bmWidth, BMP_forehandside1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_forehandside1.bmBits);
		}
		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -2.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.4f, 14.5f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.4f, 17.5f, -1.0f);
		glEnd();

		if (robotAppearance == 1) {
			glBindTexture(GL_TEXTURE_2D, tex_red);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_red.bmWidth, BMP_red.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_red.bmBits);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, tex_orange);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_orange.bmWidth, BMP_orange.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_orange.bmBits);
		}

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-5.8f, 17.5f, -2.5f);
		glVertex3f(-5.8f, 17.5f, -1.0f);
		glVertex3f(-4.4f, 17.5f, -1.0f);
		glVertex3f(-4.4f, 17.5f, -2.5f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-5.8f, 14.5f, -2.5f);
		glVertex3f(-5.8f, 14.5f, -1.0f);
		glVertex3f(-4.4f, 14.5f, -1.0f);
		glVertex3f(-4.4f, 14.5f, -2.5f);
		glEnd();

		
		glTranslatef(1.7,0,0);
		//forehand deco 1

		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);


		//right
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(-5.8f, 17.5f, -2.0f);
		glVertex3f(-5.8f, 17.1f, -2.0f);
		glVertex3f(-5.8f, 16.9f, -1.85f);
		glVertex3f(-5.8f, 16.9f, -1.65f);
		glVertex3f(-5.8f, 17.1f, -1.5f);
		glVertex3f(-5.8f, 17.5f, -1.5f);
		glEnd();

		//front
		vec1 = { -6.1f, 17.5f, -1.5f };
		vec2 = { -6.1f, 17.1f, -1.5f };
		vec3 = { -5.8f, 17.1f, -1.5f };
		vec4 = { -5.8f, 17.5f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front2
		vec1 = { -6.1f, 17.1f, -1.5f };
		vec2 = { -6.1f, 16.9f, -1.65f };
		vec3 = { -5.8f, 16.9f, -1.65f };
		vec4 = { -5.8f, 17.1f, -1.5f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -6.1f, 17.5f, -2.0f };
		vec2 = { -6.1f, 17.1f, -2.0f };
		vec3 = { -5.8f, 17.1f, -2.0f };
		vec4 = { -5.8f, 17.5f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back2
		vec1 = { -6.1f, 17.1f, -2.0f };
		vec2 = { -6.1f, 16.9f, -1.85f };
		vec3 = { -5.8f, 16.9f, -1.85f };
		vec4 = { -5.8f, 17.1f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//bottom
		vec1 = { -6.1f, 16.9f, -1.85f };
		vec2 = { -6.1f, 16.9f, -1.65f };
		vec3 = { -5.8f, 16.9f, -1.65f };
		vec4 = { -5.8f, 16.9f, -1.85f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -6.1f, 17.5f, -2.0f };
		vec2 = { -6.1f, 17.5f, -1.5f };
		vec3 = { -5.8f, 17.5f, -1.5f };
		vec4 = { -5.8f, 17.5f, -2.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//forehand deco 2
		//right
		vec1 = { -5.9f, 16.9f, -1.85f };
		vec2 = { -5.9f, 16.0f, -1.85f };
		vec3 = { -5.9f, 16.0f, -1.65f };
		vec4 = { -5.9f, 16.9f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -6.1f, 16.9f, -1.65f };
		vec2 = { -6.1f, 16.0f, -1.65f };
		vec3 = { -5.9f, 16.0f, -1.65f };
		vec4 = { -5.9f, 16.9f, -1.65f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -6.1f, 16.9f, -1.85f };
		vec2 = { -6.1f, 16.0f, -1.85f };
		vec3 = { -5.9f, 16.0f, -1.85f };
		vec4 = { -5.9f, 16.9f, -1.85f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//forehand deco 3
		//right
		vec1 = { -5.8f, 16.0f, -1.9f };
		vec2 = { -5.8f, 15.5f, -1.9f };
		vec3 = { -5.8f, 15.5f, -1.6f };
		vec4 = { -5.8f, 16.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//front
		vec1 = { -6.1f, 16.0f, -1.6f };
		vec2 = { -6.1f, 15.5f, -1.6f };
		vec3 = { -5.8f, 15.5f, -1.6f };
		vec4 = { -5.8f, 16.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//back
		vec1 = { -6.1f, 16.0f, -1.9f };
		vec2 = { -6.1f, 15.5f, -1.9f };
		vec3 = { -5.8f, 15.5f, -1.9f };
		vec4 = { -5.8f, 16.0f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//bottom
		vec1 = { -6.1f, 15.5f, -1.9f };
		vec2 = { -6.1f, 15.5f, -1.6f };
		vec3 = { -5.8f, 15.5f, -1.6f };
		vec4 = { -5.8f, 15.5f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		//top
		vec1 = { -6.1f, 16.0f, -1.9f };
		vec2 = { -6.1f, 16.0f, -1.6f };
		vec3 = { -5.8f, 16.0f, -1.6f };
		vec4 = { -5.8f, 16.0f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec4.getx(), vec4.gety(), vec4.getz());
		glEnd();

		
		glTranslatef(-1.7, 0, 0);

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		
		//hand
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-5.1f, 14.5f, -1.2f);
		glVertex3f(-5.1f, 13.5f, -1.2f);
		glVertex3f(-4.7f, 13.5f, -1.2f);
		glVertex3f(-4.7f, 14.5f, -1.2f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-5.1f, 14.5f, -2.2f);
		glVertex3f(-5.1f, 13.5f, -2.2f);
		glVertex3f(-4.7f, 13.5f, -2.2f);
		glVertex3f(-4.7f, 14.5f, -2.2f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-5.1f, 14.5f, -2.2f);
		glVertex3f(-5.1f, 13.5f, -2.2f);
		glVertex3f(-5.1f, 13.5f, -1.2f);
		glVertex3f(-5.1f, 14.5f, -1.2f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, -1);
		glVertex3f(-4.7f, 14.5f, -2.2f);
		glVertex3f(-4.7f, 13.5f, -2.2f);
		glVertex3f(-4.7f, 13.5f, -1.2f);
		glVertex3f(-4.7f, 14.5f, -1.2f);
		glEnd();

		//4finger
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-5.4f, 13.5f, -1.2f);
		glVertex3f(-5.4f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -1.2f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-5.4f, 13.5f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -2.2f);
		glVertex3f(-4.8f, 13.1f, -2.2f);
		glVertex3f(-4.8f, 13.5f, -2.2f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-5.4f, 13.5f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -1.2f);
		glVertex3f(-5.4f, 13.5f, -1.2f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-4.8f, 13.5f, -2.2f);
		glVertex3f(-4.8f, 13.1f, -2.2f);
		glVertex3f(-4.8f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -1.2f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-5.4f, 13.1f, -2.2f);
		glVertex3f(-5.4f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.1f, -1.2f);
		glVertex3f(-4.8f, 13.1f, -2.2f);
		glEnd();

		//top
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(-5.4f, 13.5f, -2.2f);
		glVertex3f(-5.4f, 13.5f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -1.2f);
		glVertex3f(-4.8f, 13.5f, -2.2f);
		glEnd();

		//thumb
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(-5.5f, 14.5f, -1.1f);
		glVertex3f(-5.5f, 13.8f, -1.1f);
		glVertex3f(-5.2f, 13.8f, -1.1f);
		glVertex3f(-5.2f, 14.5f, -1.1f);
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-5.5f, 14.5f, -1.5f);
		glVertex3f(-5.5f, 13.8f, -1.5f);
		glVertex3f(-5.2f, 13.8f, -1.5f);
		glVertex3f(-5.2f, 14.5f, -1.5f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-5.5f, 14.5f, -1.5f);
		glVertex3f(-5.5f, 13.8f, -1.5f);
		glVertex3f(-5.5f, 13.8f, -1.1f);
		glVertex3f(-5.5f, 14.5f, -1.1f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-5.2f, 14.5f, -1.5f);
		glVertex3f(-5.2f, 13.8f, -1.5f);
		glVertex3f(-5.2f, 13.8f, -1.1f);
		glVertex3f(-5.2f, 14.5f, -1.1f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(-5.5f, 13.8f, -1.5f);
		glVertex3f(-5.5f, 13.8f, -1.1f);
		glVertex3f(-5.2f, 13.8f, -1.1f);
		glVertex3f(-5.2f, 13.8f, -1.5f);
		glEnd();

		//End movepoint
		/////////////
		glPopMatrix();
		////////////
		

		
		// HEAD
		//movepoint
		//////////////////////////////////////
		//////////////////////////////////////
		//////move head
		glTranslatef(-2.0, 21.0, -1.70);
		glRotatef(rotateX0, 1, 0, 0);
		glRotatef(rotateY0, 0, 1, 0);
		glRotatef(rotateZ0, 0, 0, 1);
		glTranslatef(2.0, -21.0, 1.70);
		/////////////////////////////////////////

		//mask
		glBindTexture(GL_TEXTURE_2D, tex_mask);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_mask.bmWidth, BMP_mask.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_mask.bmBits);


		vec1 = { -2.6f, 21.8f, -1.6f };
		vec2 = { -2.6f, 21.0f, -1.6f };
		vec3 = { -2.0f, 21.0f, -1.0f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, 22.2f, -1.2f);
		glEnd();
		//mask right

		vec1 = { -2.0f, 22.2f, -1.2f };
		vec2 = { -2.0f, 21.0f, -1.0f };
		vec3 = { -1.4f, 21.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.4f, 21.8f, -1.6f); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz()); 
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glEnd();
		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//bottom
		vec1 = { -2.6f, 21.0f, -1.6f };
		vec2 = { -2.0f, 21.0f, -1.0f };
		vec3 = { -1.4f, 21.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), -vnormal.gety(), vnormal.getz());
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glTexCoord2f(1.0f, 0.0f); glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glTexCoord2f(0.0f, 0.0f); glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//forehead left
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -2.6f, 23.0f, -1.2f };
		vec2 = { -2.6f, 22.2f, -1.2f };
		vec3 = { -2.0f, 22.2f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 23.0f, -1.2f };
		vec2 = { -2.0f, 22.2f, -1.2f };
		vec3 = { -2.0f, 23.2f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -2.6f, 23.0f, -2.2f };
		vec2 = { -2.6f, 22.2f, -2.2f };
		vec3 = { -2.0f, 22.2f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 23.0f, -2.2f };
		vec2 = { -2.0f, 22.2f, -2.2f };
		vec3 = { -2.0f, 23.2f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -2.6f, 23.0f, -2.2f };
		vec2 = { -2.6f, 23.0f, -1.2f };
		vec3 = { -2.0f, 23.2f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 23.0f, -2.2f };
		vec2 = { -2.0f, 23.2f, -1.2f };
		vec3 = { -2.0f, 23.2f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//bottom
		glBegin(GL_TRIANGLES);
		vec1 = { -2.6f, 22.2f, -1.6f };
		vec2 = { -2.6f, 22.2f, -1.2f };
		vec3 = { -2.0f, 22.2f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 22.2f, -1.6f };
		vec2 = { -2.0f, 22.2f, -1.2f };
		vec3 = { -2.0f, 22.2f, -1.6f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -2.6f, 23.0f, -2.2f };
		vec2 = { -2.6f, 22.2f, -2.2f };
		vec3 = { -2.6f, 22.2f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.6f, 23.0f, -2.2f };
		vec2 = { -2.6f, 22.2f, -1.2f };
		vec3 = { -2.6f, 23.0f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		

		//forehead right
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -2.0f, 23.2f, -1.2f };
		vec2 = { -2.0f, 22.2f, -1.2f };
		vec3 = { -1.4f, 22.2f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.0f, 23.2f, -1.2f };
		vec2 = { -1.4f, 22.2f, -1.2f };
		vec3 = { -1.4f, 23.0f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -2.0f, 23.2f, -2.2f };
		vec2 = { -2.0f, 22.2f, -2.2f };
		vec3 = { -1.4f, 22.2f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.0f, 23.2f, -2.2f };
		vec2 = { -1.4f, 22.2f, -2.2f };
		vec3 = { -1.4f, 23.0f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -2.0f, 23.2f, -2.2f };
		vec2 = { -2.0f, 23.2f, -1.2f };
		vec3 = { -1.4f, 23.0f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.0f, 23.2f, -2.2f };
		vec2 = { -1.4f, 23.0f, -1.2f };
		vec3 = { -1.4f, 23.0f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//bottom
		glBegin(GL_TRIANGLES);
		vec1 = { -2.0f, 22.2f, -1.6f };
		vec2 = { -2.0f, 22.2f, -1.2f };
		vec3 = { -1.4f, 22.2f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.0f, 22.2f, -1.6f };
		vec2 = { -1.4f, 22.2f, -1.2f };
		vec3 = { -1.4f, 22.2f, -1.6f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -1.4f, 23.0f, -2.2f };
		vec2 = { -1.4f, 22.2f, -2.2f };
		vec3 = { -1.4f, 22.2f, -1.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.4f, 23.0f, -2.2f };
		vec2 = { -1.4f, 22.2f, -1.2f };
		vec3 = { -1.4f, 23.0f, -1.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//forehead gem
		glBindTexture(GL_TEXTURE_2D, tex_lightgrey);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_lightgrey.bmWidth, BMP_lightgrey.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_lightgrey.bmBits);


		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(-2.1f, 23.5f, -1.19f);
		glVertex3f(-2.2f, 23.0f, -1.19f);
		glVertex3f(-2.1f, 22.2f, -1.19f);
		glVertex3f(-1.9f, 22.2f, -1.19f);
		glVertex3f(-1.8f, 23.0f, -1.19f);
		glVertex3f(-1.9f, 23.5f, -1.19f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//back
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-2.1f, 23.5f, -1.195f);
		glVertex3f(-2.2f, 23.0f, -1.195f);
		glVertex3f(-2.1f, 22.2f, -1.195f);
		glVertex3f(-1.9f, 22.2f, -1.195f);
		glVertex3f(-1.8f, 23.0f, -1.195f);
		glVertex3f(-1.9f, 23.5f, -1.195f);
		glEnd();
		
		//handsome 
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, tex_handsome);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_handsome.bmWidth, BMP_handsome.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_handsome.bmBits);
		//front
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( -2.6, 22.2f , -1.6f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.6, 21.0f, -1.6f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.4, 21.0f, -1.6f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.4, 22.2f, -1.6f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, tex_blue);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP_blue.bmWidth, BMP_blue.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP_blue.bmBits);

		//16
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		if (lightswitch == 0) {
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		}
		//circle 1
		//top
		glBegin(GL_QUADS);
		glNormal3f( 0, 1, 0);
		glVertex3f(-2.9, 22.8f, -2.4f);
		glVertex3f(-2.9, 22.8f, -1.6f);
		glVertex3f(-1.1, 22.8f, -1.6f);
		glVertex3f(-1.1, 22.8f, -2.4f);
		glEnd();

		//back
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-2.9, 22.8f, -2.4f);
		glVertex3f(-2.9, 21.5f, -2.4f);
		glVertex3f(-2.6, 21.0f, -2.4f);
		glVertex3f(-1.4, 21.0f, -2.4f);
		glVertex3f(-1.1, 21.5f, -2.4f);
		glVertex3f(-1.1, 22.8f, -2.4f);
		glEnd();

		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -2.9f, 22.8f, -1.6f };
		vec2 = { -2.9f, 21.5f, -1.6f };
		vec3 = { -2.6f, 21.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.9f, 22.8f, -1.6f };
		vec2 = { -2.6f, 21.0f, -1.6f };
		vec3 = { -2.6f, 22.8f, -1.6f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-2.9, 22.8f, -2.4f);
		glVertex3f(-2.9, 21.5f, -2.4f);
		glVertex3f(-2.9, 21.5f, -1.6f);
		glVertex3f(-2.9, 22.8f, -1.6f);
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -2.9f, 21.5f, -2.4f };
		vec2 = { -2.6f, 21.0f, -2.4f };
		vec3 = { -2.6f, 21.0f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -2.9f, 21.5f, -2.4f };
		vec2 = { -2.6f, 21.0f, -1.6f };
		vec3 = { -2.9f, 21.5f, -1.6f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//circle 2
		glBegin(GL_TRIANGLES);
		vec1 = { -1.4f, 22.8f, -1.6f };
		vec2 = { -1.4f, 21.0f, -1.6f };
		vec3 = { -1.1f, 21.5f, -1.6f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.4f, 22.8f, -1.6f };
		vec2 = { -1.1f, 21.5f, -1.6f };
		vec3 = { -1.1f, 22.8f, -1.6f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-1.1, 22.8f, -2.4f);
		glVertex3f(-1.1, 21.5f, -2.4f);
		glVertex3f(-1.1, 21.5f, -1.6f);
		glVertex3f(-1.1, 22.8f, -1.6f);
		glEnd();

		//left 2
		glBegin(GL_TRIANGLES);
		vec1 = { -1.1f, 21.5f, -1.6f };
		vec2 = { -1.4f, 21.0f, -1.6f };
		vec3 = { -1.4f, 21.0f, -2.4f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.1f, 21.5f, -1.6f };
		vec2 = { -1.4f, 21.0f, -2.4f };
		vec3 = { -1.1f, 21.5f, -2.4f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//ear 1
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -3.1f, 22.5f, -1.8f };
		vec2 = { -3.1f, 21.9f, -1.8f };
		vec3 = { -2.9f, 21.8f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.1f, 22.5f, -1.8f };
		vec2 = { -2.9f, 21.8f, -1.8f };
		vec3 = { -2.9f, 22.5f, -1.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -3.1f, 22.5f, -2.2f };
		vec2 = { -3.1f, 21.9f, -2.2f };
		vec3 = { -2.9f, 21.8f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.1f, 22.5f, -2.2f };
		vec2 = { -2.9f, 21.8f, -2.2f };
		vec3 = { -2.9f, 22.5f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//left
		glBegin(GL_TRIANGLES);
		vec1 = { -3.1f, 22.5f, -2.2f };
		vec2 = { -3.1f, 21.9f, -2.2f };
		vec3 = { -3.1f, 21.9f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.1f, 22.5f, -2.2f };
		vec2 = { -3.1f, 21.9f, -1.8f };
		vec3 = { -3.1f, 22.5f, -1.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//bottom
		glBegin(GL_TRIANGLES);
		vec1 = { -3.1f, 21.9f, -2.2f };
		vec2 = { -3.1f, 21.9f, -1.8f };
		vec3 = { -2.9f, 21.8f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.1f, 21.9f, -2.2f };
		vec2 = { -2.9f, 21.8f, -1.8f };
		vec3 = { -2.9f, 21.8f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -3.1f, 22.5f, -2.2f };
		vec2 = { -3.1f, 22.5f, -1.8f };
		vec3 = { -2.9f, 22.5f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.1f, 22.5f, -2.2f };
		vec2 = { -2.9f, 22.5f, -1.8f };
		vec3 = { -2.9f, 22.5f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//ear 1 up
		glBegin(GL_TRIANGLES);
		vec1 = { -3.0f, 23.8f, -1.9f };
		vec2 = { -3.0f, 22.5f, -1.9f };
		vec3 = { -2.9f, 22.5f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.0f, 23.8f, -1.9f };
		vec2 = { -2.9f, 22.5f, -1.9f };
		vec3 = { -2.9f, 23.8f, -1.9f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-3.0f, 23.5f, -2.1f);
		glVertex3f(-3.0f, 22.5f, -2.1f);
		glVertex3f(-2.9f, 22.5f, -2.1f);
		glVertex3f(-2.9f, 23.5f, -2.1f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-3.0f, 23.5f, -2.1f);
		glVertex3f(-3.0f, 22.5f, -2.1f);
		glVertex3f(-3.0f, 22.5f, -1.9f);
		glVertex3f(-3.0f, 23.8f, -1.9f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-2.9f, 23.5f, -2.1f);
		glVertex3f(-2.9f, 22.5f, -2.1f);
		glVertex3f(-2.9f, 22.5f, -1.9f);
		glVertex3f(-2.9f, 23.8f, -1.9f);
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -3.0f, 23.5f, -2.1f };
		vec2 = { -3.0f, 23.8f, -1.9f };
		vec3 = { -2.9f, 23.8f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -3.0f, 23.5f, -2.1f };
		vec2 = { -2.9f, 23.8f, -1.9f };
		vec3 = { -2.9f, 23.5f, -2.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//ear 2
		//front
		glBegin(GL_TRIANGLES);
		vec1 = { -1.1f, 22.5f, -1.8f };
		vec2 = { -1.1f, 21.8f, -1.8f };
		vec3 = { -0.9f, 21.9f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.1f, 22.5f, -1.8f };
		vec2 = { -0.9f, 21.9f, -1.8f };
		vec3 = { -0.9f, 22.5f, -1.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_TRIANGLES);
		vec1 = { -1.1f, 22.5f, -2.2f };
		vec2 = { -1.1f, 21.8f, -2.2f };
		vec3 = { -0.9f, 21.9f, -2.2f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.1f, 22.5f, -2.2f };
		vec2 = { -0.9f, 21.9f, -2.2f };
		vec3 = { -0.9f, 22.5f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//right
		glBegin(GL_TRIANGLES);
		vec1 = { -0.9f, 22.5f, -2.2f };
		vec2 = { -0.9f, 21.9f, -2.2f };
		vec3 = { -0.9f, 21.9f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -0.9f, 22.5f, -2.2f };
		vec2 = { -0.9f, 21.9f, -1.8f };
		vec3 = { -0.9f, 22.5f, -1.8f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//bottom
		glBegin(GL_TRIANGLES);
		vec1 = { -1.1f, 21.8f, -2.2f };
		vec2 = { -1.1f, 21.8f, -1.8f };
		vec3 = { -0.9f, 21.9f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), -vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.1f, 21.8f, -2.2f };
		vec2 = { -0.9f, 21.9f, -1.8f };
		vec3 = { -0.9f, 21.9f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -1.1f, 22.5f, -2.2f };
		vec2 = { -1.1f, 22.5f, -1.8f };
		vec3 = { -0.9f, 22.5f, -1.8f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(-vnormal.getx(), vnormal.gety(), -vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.1f, 22.5f, -2.2f };
		vec2 = { -0.9f, 22.5f, -1.8f };
		vec3 = { -0.9f, 22.5f, -2.2f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//ear 2 up
		glBegin(GL_TRIANGLES);
		vec1 = { -1.1f, 23.8f, -1.9f };
		vec2 = { -1.1f, 22.5f, -1.9f };
		vec3 = { -1.0f, 22.5f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.1f, 23.8f, -1.9f };
		vec2 = { -1.0f, 22.5f, -1.9f };
		vec3 = { -1.0f, 23.8f, -1.9f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		//back
		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.1f, 23.5f, -2.1f);
		glVertex3f(-1.1f, 22.5f, -2.1f);
		glVertex3f(-1.0f, 22.5f, -2.1f);
		glVertex3f(-1.0f, 23.5f, -2.1f);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.1f, 23.5f, -2.1f);
		glVertex3f(-1.1f, 22.5f, -2.1f);
		glVertex3f(-1.1f, 22.5f, -1.9f);
		glVertex3f(-1.1f, 23.8f, -1.9f);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(-1.0f, 23.5f, -2.1f);
		glVertex3f(-1.0f, 22.5f, -2.1f);
		glVertex3f(-1.0f, 22.5f, -1.9f);
		glVertex3f(-1.0f, 23.8f, -1.9f);
		glEnd();

		//top
		glBegin(GL_TRIANGLES);
		vec1 = { -1.1f, 23.5f, -2.1f };
		vec2 = { -1.1f, 23.8f, -1.9f };
		vec3 = { -1.0f, 23.8f, -1.9f };
		vnormal = getSurfaceNormal(vec1, vec2, vec3);
		glNormal3f(vnormal.getx(), vnormal.gety(), vnormal.getz());
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		vec1 = { -1.1f, 23.5f, -2.1f };
		vec2 = { -1.0f, 23.8f, -1.9f };
		vec3 = { -1.0f, 23.5f, -2.1f };
		glVertex3f(vec1.getx(), vec1.gety(), vec1.getz());
		glVertex3f(vec2.getx(), vec2.gety(), vec2.getz());
		glVertex3f(vec3.getx(), vec3.gety(), vec3.getz());
		glEnd();

		if (lightswitch == 0) {
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		}

		//End movepoint
		/////////////
		glPopMatrix();
		////////////


		glPopMatrix();
		glPopMatrix();
		break;
	}

	}
	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------

Vector3 crossProduct(Vector3 v1, Vector3 v2) {

	Vector3 cross = { v1.gety() * v2.getz() - v1.getz() * v2.gety(),
		v1.getz() * v2.getx() - v1.getx() * v2.getz(),
		v1.getx() * v2.gety() - v1.gety() * v2.getx() };

	return cross;

}

Vector3 getSurfaceNormal(Vector3 v1, Vector3 v2, Vector3 v3) {

	/*
	* obtain vectors between the coordinates of
	* triangle.
	*/
	Vector3 polyVector1 = { v2.getx() - v1.getx(), v2.gety() - v1.gety(), v2.getz() - v1.getz() };
	Vector3 polyVector2 = { v3.getx() - v1.getx(), v3.gety() - v1.gety(), v3.getz() - v1.getz() };

	Vector3 cross = crossProduct(polyVector1, polyVector2);

	float length = sqrt(pow(cross.getx(), 2) + pow(cross.gety(), 2) + pow(cross.getz(), 2));
	cross = { cross.getx() / length ,cross.gety() / length ,cross.getz() / length };

	return cross;

}

void resetAnimation() {
	animation = 999;
	animationSwitch=1;
	animationMoveX = 0;
	animationMoveY = 0;
	animationMoveZ = 0;
	rotateX1 = 0;
	rotateY1 = 0;
	rotateZ1 = 0;
	rotateX2 = 0;
	rotateY2 = 0;
	rotateZ2 = 0;
	rotateX3 = 0;
	rotateY3 = 0;
	rotateZ3 = 0;
	rotateX4 = 0;
	rotateY4 = 0;
	rotateZ4 = 0;
	rotateX5 = 0;
	rotateY5 = 0;
	rotateZ5 = 0;
	rotateX6 = 0;
	rotateY6 = 0;
	rotateZ6 = 0;
	rotateX7 = 0;
	rotateY7 = 0;
	rotateZ7 = 0;
	rotateX8 = 0;
	rotateY8 = 0;
	rotateZ8 = 0;
	rotateX9 = 0;
	rotateY9 = 0;
	rotateZ9 = 0;
	rotateX10 = 0;
	rotateY10 = 0;
	rotateZ10 = 0;
}

void walkAnimation() {
	if (walk1 > 0) {
		if (rotateX1 >= 30) {
			walk1 = -1.2;
		}
		else {
			rotateX1 += walk1;
		}
	}
	else {
		if (rotateX1 <= 0) {
			walk1 = 1.2;
		}
		else {
			rotateX1 += walk1;
		}
	}

	if (walk3 > 0) {
		if (rotateX3 >= 30) {
			walk3 = -1.2;
		}
		else {
			rotateX3 += walk3;
		}
	}
	else {
		if (rotateX3 <= -30) {
			walk3 = 1.2;
		}
		else {
			rotateX3 += walk3;
		}
	}

	if (walk2 > 0) {
		if (rotateX2 >= 30) {
			walk2 = -1.2;
		}
		else {
			rotateX2 += walk2;
		}
	}
	else {
		if (rotateX2 <= 0) {
			walk2 = 1.2;
		}
		else {
			rotateX2 += walk2;
		}
	}

	if (walk4 > 0) {
		if (rotateX4 >= 30) {
			walk4 = -1.2;
		}
		else {
			rotateX4 += walk4;
		}
	}
	else {
		if (rotateX4 <= -30) {
			walk4 = 1.2;
		}
		else {
			rotateX4 += walk4;
		}
	}

	if (walk6 > 0) {
		if (rotateX6 >= 15) {
			walk6 = -0.6;
		}
		else {
			rotateX6 += walk6;
		}
	}
	else {
		if (rotateX6 <= -15) {
			walk6 = 0.6;
		}
		else {
			rotateX6 += walk6;
		}
	}

	if (walk8 > 0) {
		if (rotateX8 >= 15) {
			walk8 = -0.6;
		}
		else {
			rotateX8 += walk8;
		}
	}
	else {
		if (rotateX8 <= -15) {
			walk8 = 0.6;
		}
		else {
			rotateX8 += walk8;
		}
	}
}



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	gluPerspective(45, 1, 0.1, 300);

	
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	
	glEnable(GL_TEXTURE_2D);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "blank.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_blank), &BMP_blank);

	glGenTextures(1, &tex_blank);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "blue.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_blue), &BMP_blue);

	glGenTextures(1, &tex_blue);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chest.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_chest), &BMP_chest);

	glGenTextures(1, &tex_chest);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chest1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_chest1), &BMP_chest1);

	glGenTextures(1, &tex_chest1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chestback.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_chestback), &BMP_chestback);

	glGenTextures(1, &tex_chestback);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chestback1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_chestback1), &BMP_chestback1);

	glGenTextures(1, &tex_chestback1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "foot.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_foot), &BMP_foot);

	glGenTextures(1, &tex_foot);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "footback.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_footback), &BMP_footback);

	glGenTextures(1, &tex_footback);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "forehand.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_forehand), &BMP_forehand);

	glGenTextures(1, &tex_forehand);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "forehand1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_forehand1), &BMP_forehand1);

	glGenTextures(1, &tex_forehand1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "forehandside.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_forehandside), &BMP_forehandside);

	glGenTextures(1, &tex_forehandside);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "forehandside1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_forehandside1), &BMP_forehandside1);

	glGenTextures(1, &tex_forehandside1);
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "handsome.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_handsome), &BMP_handsome);

	glGenTextures(1, &tex_handsome);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "knee.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_knee), &BMP_knee);

	glGenTextures(1, &tex_knee);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "knee2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_knee2), &BMP_knee2);

	glGenTextures(1, &tex_knee2);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "knee2back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_knee2back), &BMP_knee2back);

	glGenTextures(1, &tex_knee2back);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "knee3.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_knee3), &BMP_knee3);

	glGenTextures(1, &tex_knee3);
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "lightgrey.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_lightgrey), &BMP_lightgrey);

	glGenTextures(1, &tex_lightgrey);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "red.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_red), &BMP_red);

	glGenTextures(1, &tex_red);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "orange.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_orange), &BMP_orange);

	glGenTextures(1, &tex_orange);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "yellow.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_yellow), &BMP_yellow);

	glGenTextures(1, &tex_yellow);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "shoulder.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_shoulder), &BMP_shoulder);

	glGenTextures(1, &tex_shoulder);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "shoulder1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_shoulder1), &BMP_shoulder1);

	glGenTextures(1, &tex_shoulder1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "shoulderback.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_shoulderback), &BMP_shoulderback);

	glGenTextures(1, &tex_shoulderback);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "shoulderback1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_shoulderback1), &BMP_shoulderback1);

	glGenTextures(1, &tex_shoulderback1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "somach.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_stomach), &BMP_stomach);

	glGenTextures(1, &tex_stomach);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "somach1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_stomach1), &BMP_stomach1);

	glGenTextures(1, &tex_stomach1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "somachback.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_stomachback), &BMP_stomachback);

	glGenTextures(1, &tex_stomachback);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "somachback1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_stomachback1), &BMP_stomachback1);

	glGenTextures(1, &tex_stomachback1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "thigh.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_thigh), &BMP_thigh);

	glGenTextures(1, &tex_thigh);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "toe.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_toe), &BMP_toe);

	glGenTextures(1, &tex_toe);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "tyre.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_tyre), &BMP_tyre);

	glGenTextures(1, &tex_tyre);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "tyrestrip.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_tyrestrip), &BMP_tyrestrip);

	glGenTextures(1, &tex_tyrestrip);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "wraist.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_wraist), &BMP_wraist);

	glGenTextures(1, &tex_wraist);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "darkgrey.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_darkgrey), &BMP_darkgrey);

	glGenTextures(1, &tex_darkgrey);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "mask.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_mask), &BMP_mask);

	glGenTextures(1, &tex_mask);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "gem.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_gem), &BMP_gem);

	glGenTextures(1, &tex_gem);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chestbackdeco1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_chestbackdeco1), &BMP_chestbackdeco1);

	glGenTextures(1, &tex_chestbackdeco1);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chestbackdeco2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_chestbackdeco2), &BMP_chestbackdeco2);

	glGenTextures(1, &tex_chestbackdeco2);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "sixpack.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_sixpack), &BMP_sixpack);

	glGenTextures(1, &tex_sixpack);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "sky.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_sky), &BMP_sky);

	glGenTextures(1, &tex_sky);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "grass.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_grass), &BMP_grass);

	glGenTextures(1, &tex_grass);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "swordcolour.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_swordcolour), &BMP_swordcolour);

	glGenTextures(1, &tex_swordcolour);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "housecolour.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_housecolour), &BMP_housecolour);

	glGenTextures(1, &tex_housecolour);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "housewindow.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_housewindow), &BMP_housewindow);

	glGenTextures(1, &tex_housewindow);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "riverflow.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_riverflow), &BMP_riverflow);

	glGenTextures(1, &tex_riverflow);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "riverflow2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_riverflow2), &BMP_riverflow2);

	glGenTextures(1, &tex_riverflow2);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "riverflow3.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_riverflow3), &BMP_riverflow3);

	glGenTextures(1, &tex_riverflow3);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "treecolour.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_treecolour), &BMP_treecolour);

	glGenTextures(1, &tex_treecolour);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "treetrunk.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_treetrunk), &BMP_treetrunk);

	glGenTextures(1, &tex_treetrunk);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "clockbuilding.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_clockbuilding), &BMP_clockbuilding);

	glGenTextures(1, &tex_clockbuilding);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "clock.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_clock), &BMP_clock);

	glGenTextures(1, &tex_clock);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "mountain.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_mountain), &BMP_mountain);

	glGenTextures(1, &tex_mountain);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "yellowstar.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_yellowstar), &BMP_yellowstar);

	glGenTextures(1, &tex_yellowstar);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "pyramid.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_pyramid), &BMP_pyramid);

	glGenTextures(1, &tex_pyramid);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "lightsky.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP_lightsky), &BMP_lightsky);

	glGenTextures(1, &tex_lightsky);

	PlaySound("BackgroundMusic.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	//glOrtho(-2, 2, -2, 2, 0, 1);

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);



	return true;
}
//--------------------------------------------------------------------

