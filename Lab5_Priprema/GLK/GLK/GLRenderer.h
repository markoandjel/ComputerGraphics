#pragma once
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
	
	void RotateView(CPoint* newPoint);
	inline void SetCurrentPt(CPoint* pt)
	{
		currentPt->x = pt->x;
		currentPt->y = pt->y;
	}
	inline void ToggleRed()
	{
		redOn = !redOn;
	}
	inline void ToggleGreen()
	{
		greenOn = !greenOn;
	}
	inline void ToggleBlue()
	{
		blueOn = !blueOn;
	}
	inline void ToggleNormals()
	{
		normalsOn = !normalsOn;
	}

	void SetMemAngles();
	void DrawHalfSphere(int horizontalPrecision, int verticalPrecision, double radius, double* color);
	void DrawSphere(int horizontalPrecision, int verticalHalfPrecision, double radius, double* color);
	void DrawPrismC(int numOfSides, double height, double radius, double* color);
	void DrawPrism(int numOfSides, double height, double radius, double* color);
	void DrawCylinder(int precision, double height, double radius, double* color);
	void DrawConePart(int precision, double angle, double partLen, double radius);
	void DrawWall(double height, double width, double heightPrecision, double widthPrecision);
	void DrawWallPart(double quadHeight, double quadWidth, double quadNum, double startingHeight);
	void DrawTry(int numOfSides, double height, double radius, double* color);

protected:
	HGLRC	 m_hrc; //OpenGL Rendering Context 
	double xRotationAngle;
	double yRotationAngle;
	double memXRotationAngle;
	double memYRotationAngle;
	double yOffset;
	CPoint* currentPt;

	bool redOn, greenOn, blueOn, normalsOn;
};
