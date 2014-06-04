#include "ViewerParser.hpp"

// A modifier !
Squelette *squel;
Parser *parser;
Mesh *m_pMesh;

static bool InitMesh(){

	m_pMesh = new Mesh();

	return m_pMesh->LoadMesh("Modele/Scotty3ds.3ds");

}

ViewerParser::ViewerParser(){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	parser = new Parser();
}

static void sleep2(unsigned int ms){
	clock_t goal = ms + clock();
	while(goal>clock());
}

static void RenderSceneCB()
{
    sleep2(100000);
    glClear(GL_COLOR_BUFFER_BIT);
// lights and color
		glEnable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		GLfloat const white[] = {1.0f,1.0f,1.0f, 1.f};
		glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
		GLfloat position[] = {1.0f, 1.0f, 0.5f}; 
		glLightfv(GL_LIGHT1, GL_POSITION, position);
    glColor3f(0.4, 0.6, 0.0);
    squel->draw();
		glColor3f(0.4f, 0.0f, 0.6f); 
    m_pMesh->Render();
    glFlush();
	//animation
     parser->parse(squel);
    glutPostRedisplay();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

void ViewerParser::launch(string nomFichier){
	glutCreateWindow("Tutorial 01");
	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	}


	if(! InitMesh()){
		fprintf(stderr, "Error: '%s'\n", "error while loading the mesh");
	}
	squel = new Squelette(&(m_pMesh->Vertices));
	//squel = new Squelette();

	parser->openFichier(nomFichier);

	InitializeGlutCallbacks();
	glutMainLoop();
	parser->close();
}


ViewerParser::~ViewerParser(){
	delete m_pMesh;
	delete squel;
}
