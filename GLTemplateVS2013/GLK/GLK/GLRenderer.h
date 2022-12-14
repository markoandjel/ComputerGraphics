#pragma once
#include "math.h"
#define _USE_MATH_DEFINES
class CGLRenderer
{
public:
	CGLRenderer(void);
	virtual ~CGLRenderer(void);
		
	bool CreateGLContext(CDC* pDC);			// kreira OpenGL Rendering Context
	void PrepareScene(CDC* pDC);			// inicijalizuje scenu,
	void Reshape(CDC* pDC, int w, int h);	// kod koji treba da se izvrsi svaki put kada se promeni velicina prozora ili pogleda i
	void DrawScene(CDC* pDC);				// iscrtava scenu
	void DestroyScene(CDC* pDC);			// dealocira resurse alocirane u drugim funkcijama ove klase,

	void DrawSphere(double r, int nSegAlpha, int nSegBeta);
	void DrawCylinder(double h, double r1, double r2, int nSeg);
	void DrawCone(double h, double r, int nSeg);
	void DrawAxis(double width);
	void DrawGrid(double width, double height, int nSegW, int nSegH);
	void DrawPot(double r1, double r2, double h1, double r3, double h2);
	void DrawFigure(double angle);
	void RotateBranch(double angle);
	void RotateCamera(double angle, bool isAlpha);
protected:
	HGLRC	 m_hrc; //OpenGL Rendering Context 
	double angle = 45.0;
	double alpha = -45;
	double beta = 0;
	double distance = 30;
};
