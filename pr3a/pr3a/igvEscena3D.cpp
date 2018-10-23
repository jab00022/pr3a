#include <cstdlib>
#include <stdio.h>
#include <cmath>

#include "igvEscena3D.h"
#include "igvMallaTriangulos.h"


// Metodos constructores 

igvEscena3D::igvEscena3D() {
	ejes = true;

	// Apartado A: insertar aquí el código para crear la malla asociada a la escena equivalente a un cubo
	float dist = 0.5;
	float vert[] = {-dist, dist, dist,
					-dist, -dist, dist,
					dist, -dist, dist,
					dist, dist, dist,
					-dist, dist, -dist,
					dist, dist, -dist,
					dist, -dist, -dist,
					-dist, -dist, -dist};

	unsigned int indices[] = {0,1,2,
							  0,2,3,
							  0,3,4,
							  3,4,5,
							  3,5,6,
							  3,6,2,
							  1,2,7,
							  7,2,6,
							  1,0,7,
							  0,4,7,
							  4,5,7,
							  5,7,6};

	malla = new igvMallaTriangulos(24, vert, 36, indices);
}

igvEscena3D::~igvEscena3D() {
	if (malla)
		delete malla;
}


// Metodos publicos 

void pintar_ejes(void) {
	GLfloat rojo[] = { 1,0,0,1.0 };
	GLfloat verde[] = { 0,1,0,1.0 };
	GLfloat azul[] = { 0,0,1,1.0 };

	glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
	glBegin(GL_LINES);
	glVertex3f(1000, 0, 0);
	glVertex3f(-1000, 0, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, verde);
	glBegin(GL_LINES);
	glVertex3f(0, 1000, 0);
	glVertex3f(0, -1000, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, azul);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 1000);
	glVertex3f(0, 0, -1000);
	glEnd();
}

void igvEscena3D::visualizar(void) {
	GLfloat color_malla[] = { 0,0,0 };
	if (malla->getApartadoA() == true) {
		color_malla[1] = 0.25;
	}
	else {
		color_malla[1] = 0.25;
		color_malla[2] = 0.25;
	}
	// crear luces
	GLfloat luz0[4] = { 2.0,2.5,3.0,1 }; // luz puntual para visualizar el cubo

	glLightfv(GL_LIGHT0, GL_POSITION, luz0); // la luz se coloca aquí si permanece fija y no se mueve con la escena
	glEnable(GL_LIGHT0);

	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	  // se pintan los ejes
	if (ejes) pintar_ejes();


	//glLightfv(GL_LIGHT0,GL_POSITION,luz0); // la luz se coloca aquí si se mueve junto con la escena
	glMaterialfv(GL_FRONT, GL_EMISSION, color_malla);

	// Apartado A: la siguiente llamada hay que sustituirla por la llamada al método visualizar de la malla
	//glutSolidCube(1);
	glRotatef(malla->getAnguloX(), 1, 0, 0);
	glRotatef(malla->getAnguloY(), 0, 1, 0);
	glRotatef(malla->getAnguloZ(), 0, 0, 1);
	malla->visualizar();

	glPopMatrix(); // restaura la matriz de modelado
}

