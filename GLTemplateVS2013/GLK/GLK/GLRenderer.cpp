#include "StdAfx.h"
#include "GLRenderer.h"
#include "GL\gl.h"
#include "GL\glu.h"
#include "GL\glaux.h"
#include "GL\glut.h"
#include "math.h"
//#pragma comment(lib, "GL\\glut32.lib")

CGLRenderer::CGLRenderer(void)
{
}

CGLRenderer::~CGLRenderer(void)
{
}

bool CGLRenderer::CreateGLContext(CDC* pDC)
{
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int nPixelFormat = ChoosePixelFormat(pDC->m_hDC, &pfd);

	if (nPixelFormat == 0)	return false;

	BOOL bResult = SetPixelFormat(pDC->m_hDC, nPixelFormat, &pfd);

	if (!bResult)	return false;

	m_hrc = wglCreateContext(pDC->m_hDC);

	if (!m_hrc)	return false;

	return true;
}

void CGLRenderer::PrepareScene(CDC* pDC)
{
	wglMakeCurrent(pDC->m_hDC, m_hrc);

	glClearColor(0.5,0.7, 1, 0.0);

	wglMakeCurrent(NULL, NULL);
}

void CGLRenderer::DestroyScene(CDC* pDC)
{
	wglMakeCurrent(pDC->m_hDC, m_hrc);
	//...
	wglMakeCurrent(NULL, NULL);
	if (m_hrc)
	{
		wglDeleteContext(m_hrc);
		m_hrc = NULL;
	}
}

void CGLRenderer::DrawSphere(double r, int nSegAlpha, int nSegBeta)
{
	double** vertices = new double* [nSegAlpha + 1];
	for (int i = 0; i <= nSegAlpha; i++)
		vertices[i] = new double[(nSegBeta + 1) * 3];

	double alphaInc = 2 * M_PI / nSegAlpha;
	double betaInc = 2 * M_PI / nSegBeta;
	double fullAlpha = 0.0;
	double fullBeta = 0.0;

	for (int i = 0; i <= nSegAlpha; i++)
	{
		for (int j = 0; j <= nSegBeta * 3; j += 3)
		{
			vertices[i][j] = r * cos(fullAlpha) * cos(fullBeta);
			vertices[i][j + 1] = r * sin(fullAlpha);
			vertices[i][j + 2] = r * cos(fullAlpha) * sin(fullBeta);
			fullBeta += betaInc;
		}
		fullAlpha += alphaInc;
	}

	glBegin(GL_QUAD_STRIP);
	//glColor3f(0.5, 0.75, 1.0);
	for (int i = 0; i < nSegAlpha; i++)
	{
		for (int j = 0; j <= nSegBeta * 3; j += 3)
		{
			glVertex3f(vertices[i][j], vertices[i][j + 1], vertices[i][j + 2]);
			glVertex3f(vertices[i + 1][j], vertices[i + 1][j + 1], vertices[i + 1][j + 2]);
		}
	}
	glEnd();

	for (int i = 0; i <= nSegAlpha; i++)
		delete[] vertices[i];
	delete[] vertices;
		
}

void CGLRenderer::DrawCylinder(double h, double r1, double r2, int nSeg)
{
	double angle = 2 * M_PI / nSeg;
	double fullAngle = 0.0;

	double* verticesBottom = new double[(nSeg + 1) * 2];
	double* verticesTop = new double[(nSeg + 1) * 2];
	for (int i = 0; i <= nSeg * 2; i += 2)
	{
		verticesBottom[i] = r1 * cos(fullAngle);
		verticesBottom[i + 1] = r1 * sin(fullAngle);
		verticesTop[i] = r2 * cos(fullAngle);
		verticesTop[i + 1] = r2 * sin(fullAngle);
		fullAngle += angle;
	}
	glBegin(GL_TRIANGLE_FAN); //crtanje donje osnove
	glVertex3f(0, 0, 0);
	for (int i = 0; i <= nSeg * 2; i += 2)
	{
		glVertex3f(verticesBottom[i], 0, verticesBottom[i + 1]);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN); //crtanje gornje osnove
	glVertex3f(0, h, 0);
	for (int i = 0; i <= nSeg * 2; i += 2)
	{
		glVertex3f(verticesBottom[i], h, verticesBottom[i + 1]);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= nSeg * 2; i += 2)
	{
		glVertex3f(verticesBottom[i], 0, verticesBottom[i + 1]);
		glVertex3f(verticesTop[i], h, verticesBottom[i + 1]);
	}
	glEnd();

	delete[] verticesBottom;
	delete[] verticesTop;
}

void CGLRenderer::DrawCone(double h, double r, int nSeg)
{
	double angle = 2 * M_PI / nSeg;

	//osnova
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, 0.0);
	for (int i = 0; i <= nSeg; i ++)
		glVertex3f((float)r*cos(angle*i), 0.0, (float)r*sin(angle*i));
	glEnd();

	//omotac
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, h, 0.0);
	for (int i = 0; i <= nSeg; i ++)
		glVertex3f((float)r * cos(angle * i), 0.0, (float)r * sin(angle * i));
	glEnd();
}

void CGLRenderer::DrawAxis(double width)
{
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(width, 0);
	glColor3f(0, 1, 0);
	glVertex2f(0,0);
	glVertex2f(0, width);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, width);
	glEnd();
}

void CGLRenderer::DrawGrid(double width, double height, int nSegW, int nSegH)
{
	glBegin(GL_LINES);
	glColor3f(0.9, 0.9, 0.9);
	for (int i = 0; i < nSegW + 1; i++)
	{
		glVertex3f(-width / 2 + i * width / nSegW, 0.0, -width / 2);
		glVertex3f(-width / 2 + i * width / nSegW, 0.0, width / 2);
	}
	for (int i = 0; i < nSegH + 1; i++)
	{
		glVertex3f(-height / 2, 0.0, -height / 2 + i * height / nSegH);
		glVertex3f(height / 2, 0.0, -height / 2 + i * height / nSegH);
	}
	glEnd();
}

void CGLRenderer::DrawPot(double r1, double r2, double h1, double r3, double h2)
{
	glColor3f(0.47, 0, 0);
	DrawCylinder(h1,r1,r2,50);
	glPushMatrix();
	glTranslatef(0, h1, 0);
	DrawCylinder(h2, r3, r3, 50);
	glPopMatrix();
}

void CGLRenderer::DrawFigure(double angle)
{
	DrawPot(1.0, 1.5, 1.5, 1.8, 0.5);

	glPushMatrix();

	/*glTranslatef(0, 2, 0);
	glRotatef(angle, 1, 0, 0);
	glColor3f(1, 1, 0);
	DrawCone(1.5, 1, 30);
	glTranslatef(0, 1.5 + 0.7 / 2, 0);*/

	glTranslatef(0, 2, 0);
	glColor3f(0, 1, 0);
	DrawCylinder(1.5, 0.5, 0.5, 30); //prvi cilindar
	glTranslatef(0, 1.9, 0);
	glColor3f(0.08,0.8,0.04);
	DrawSphere(0.7 / 2, 30, 30); //prva sfera


	//crtanje grana
	glPushMatrix();
	glTranslatef(0, 0.4, 0);
	glColor3f(0, 1, 0);
	DrawCylinder(1.5, 0.5, 0.5, 30); //cilindar u sredini
	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30);

	glPushMatrix();

	glRotatef(angle, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	glColor3f(1, 1, 0);
	DrawCylinder(1.5, 0.5, 0.5, 30); //zuti cilindar

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30); //sfera iznad njega

	glTranslatef(0, 0.4, 0);
	glColor3f(0, 1, 0);
	DrawCone(1.5, 0.4, 30); //sfera iznad 

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30); //sfera iznad
	glPopMatrix();

	glPushMatrix();

	glRotatef(-45, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	glColor3f(0, 1, 0);
	DrawCylinder(1.5, 0.5, 0.5, 30); //zeleni cilindar iznad onog u sredini

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30); //sfera iznad njega

	glTranslatef(0, 0.4, 0);
	glColor3f(0, 1, 0);
	DrawCone(1.5, 0.4, 30); //sfera iznad 

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30); //sfera iznad
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	//glTranslatef(0, 0, 0);
	glRotatef(45,1,0,0);
	glTranslatef(0,0.5,0);
	glColor3f(0, 1, 0);
	DrawCylinder(1.5, 0.5, 0.5, 30); //cilindar levo

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30); //sfera iznad levog cilinda

	glTranslatef(0, 0.4, 0);
	glColor3f(0, 1, 0);
	DrawCone(1.5, 0.4, 30); //kupa iznad levog cilindra

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30);
	glPopMatrix();
	glPushMatrix();
	//glPopMatrix();

	glRotatef(-45, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	glColor3f(0, 1, 0);
	DrawCylinder(1.5, 0.5, 0.5, 30); //cilindar desno

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30);  //sfera iznad desnog cilindra

	glTranslatef(0, 0.4, 0);
	glColor3f(0, 1, 0);
	DrawCone(1.5, 0.4, 30); //kupa iznad desnog cilindra

	glTranslatef(0, 1.9, 0);
	glColor3f(0.08, 0.8, 0.04);
	DrawSphere(0.7 / 2, 30, 30);
	glPopMatrix();


	glPopMatrix();


}

void CGLRenderer::RotateBranch(double alfa)
{
	angle += alfa;
}

void CGLRenderer::RotateCamera(double angle, bool isAlpha)
{
	angle /= M_PI;
	if (isAlpha)
	{
		alpha += angle;
	}
	else
	{
		beta += angle;
	}
}

void CGLRenderer::Reshape(CDC* pDC, int w, int h)
{
	wglMakeCurrent(pDC->m_hDC, m_hrc);

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, (double)w / (double)h, 1, 100);
	glMatrixMode(GL_MODELVIEW);

	wglMakeCurrent(NULL, NULL);
}

void CGLRenderer::DrawScene(CDC* pDC)
{

	wglMakeCurrent(pDC->m_hDC, m_hrc);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//---------------------------------------------------------------------------------

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float cam_x = distance * cos(alpha) * cos(beta);
	float cam_y = distance * sin(alpha);
	float cam_z = distance * cos(alpha) * sin(beta);

	gluLookAt(cam_x, cam_y, cam_z, 0.0, 3.0, 0.0, 0.0, 1.0, 0.0);
	DrawAxis(50);
	DrawGrid(20, 20, 30, 30);
	DrawFigure(angle);

	glFlush();

	SwapBuffers(pDC->m_hDC);
	wglMakeCurrent(NULL, NULL);
}
