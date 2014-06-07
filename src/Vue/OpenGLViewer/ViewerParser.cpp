#include "ViewerParser.hpp"

// A modifier !
Squelette *squel;
Scene *decorBehind;
Scene *decorBefore;
Parser *parser;

bool ViewerParser::InitMesh(){

	aBrasD = new Mesh();
	aBrasG = new Mesh();
	brasD = new Mesh();
	brasG = new Mesh();
	torse = new Mesh();
	tete = new Mesh();
	bassin = new Mesh();
	jambeD = new Mesh();
	jambeG = new Mesh();
	molletD = new Mesh();
	molletG = new Mesh();

	scene = new Mesh();
	alambic = new Mesh();
	table = new Mesh();
	chaise1 = new Mesh();
	chaise2 = new Mesh();
	etageres = new Mesh();
	fiole1 = new Mesh();
	fiole2 = new Mesh();
	fiole3 = new Mesh();
	fiole4 = new Mesh();

	if(!aBrasD->LoadMesh("Modele/avant_brasD.3ds"))
		return false;
	if(!aBrasG->LoadMesh("Modele/avant_brasG.3ds"))
		return false;
	if(!brasD->LoadMesh("Modele/brasD.3ds"))
		return false;
	if(!brasG->LoadMesh("Modele/brasG.3ds"))
		return false;
	if(!jambeD->LoadMesh("Modele/jambe.3ds"))
		return false;
	if(!jambeG->LoadMesh("Modele/jambe.3ds"))
		return false;
	if(!molletG->LoadMesh("Modele/mollet.3ds"))
		return false;
	if(!molletD->LoadMesh("Modele/mollet.3ds"))
		return false;
	if(!tete->LoadMesh("Modele/tete.3ds"))
		return false;
	if(!torse->LoadMesh("Modele/torse.3ds"))
		return false;
	if(!bassin->LoadMesh("Modele/bassin.3ds"))
		return false;


	if(!scene->LoadMesh("Modele/scene.3ds"))
		return false;
	if(!alambic->LoadMesh("Modele/alambic.3ds"))
		return false;
	if(!table->LoadMesh("Modele/table.3ds"))
		return false;
	if(!chaise1->LoadMesh("Modele/chaise1.3ds"))
		return false;
	if(!chaise2->LoadMesh("Modele/chaise2.3ds"))
		return false;
	if(!etageres->LoadMesh("Modele/etageres.3ds"))
		return false;
	if(!fiole1->LoadMesh("Modele/fiole1.3ds"))
		return false;
	if(!fiole2->LoadMesh("Modele/fiole2.3ds"))
		return false;
	if(!fiole3->LoadMesh("Modele/fiole3.3ds"))
		return false;
	if(!fiole4->LoadMesh("Modele/fiole4.3ds"))
		return false;

	return true;
}

ViewerParser::ViewerParser(){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
	glEnable(GL_DEPTH_TEST);

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
	// lights
	glEnable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	GLfloat const white[] = {1.0f,1.0f,1.0f, 1.f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	GLfloat position[] = {1.0f, 1.0f, 0.5f}; 
	glLightfv(GL_LIGHT1, GL_POSITION, position);
	//Meshes
	decorBehind->draw();
	squel->draw();
	decorBefore->draw();
	//animation
	glFlush();
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
		return;
	}


	if(! InitMesh()){
		fprintf(stderr, "Error: '%s'\n", "error while loading the mesh");
		return;
	}
	squel = new Squelette(aBrasD, aBrasG, brasD, brasG, torse, tete, bassin, jambeD, jambeG, molletD, molletG);
	decorBehind = new Scene(scene);
	decorBehind->add(fiole4);
	decorBehind->add(fiole3);
	decorBehind->add(fiole2);
	decorBehind->add(fiole1);
	decorBefore = new Scene(chaise1);
	decorBefore->add(alambic);
	decorBefore->add(table);
	decorBefore->add(chaise2);

	parser->openFichier(nomFichier);

	InitializeGlutCallbacks();
	glutMainLoop();
	parser->close();
}


ViewerParser::~ViewerParser(){
	delete aBrasD;
	delete aBrasG;
	delete brasD;
	delete brasG;
	delete torse;
	delete tete;
	delete bassin;
	delete jambeD;
	delete jambeG;
	delete molletD;
	delete molletG;
	delete squel;
}
