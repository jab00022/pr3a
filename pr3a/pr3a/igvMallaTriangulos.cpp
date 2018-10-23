#include <cstdlib>
#include <stdio.h>
#include <math.h>

#include "igvMallaTriangulos.h"

// Metodos constructores 

igvMallaTriangulos::igvMallaTriangulos(long int _num_vertices, float *_vertices, long int _num_triangulos, unsigned int *_triangulos) {
	/* Apartado A: construir la malla de triángulos: vértices y triángulos */
	apartadoA = true;
	//apartadoD = false;
	num_vertices = _num_vertices;
	vertices = new float[num_vertices];
	num_triangulos = _num_triangulos;
	triangulos = new unsigned int[num_triangulos];
	normales = 0;

	for (int i = 0; i < num_vertices; ++i) {
		vertices[i] = _vertices[i];
	}
	for (int j = 0; j < num_triangulos; ++j) {
		triangulos[j] = _triangulos[j];
	}

	angulos[_X] = 0;
	angulos[_Y] = 0;
	angulos[_Z] = 0;
	/* Apartado D: añadir el cálculo de las normales */
	normales = new float[num_vertices];
	float v[3], w[3], normal[3];
	for (int i = 0; i < num_triangulos; i += 3) {
		//Donde 0 es X, 1 es Y, y 2 es Z
		//Y v = Q - P, donde Q y P son dos puntos  P •-------->• Q
		v[0] = vertices[3 * triangulos[i + 2]] - vertices[3 * triangulos[i]];
		v[1] = vertices[3 * triangulos[i + 2] + 1] - vertices[3 * triangulos[i] + 1];
		v[2] = vertices[3 * triangulos[i + 2] + 2] - vertices[3 * triangulos[i] + 2];

		w[0] = vertices[3 * triangulos[i + 1]] - vertices[3 * triangulos[i]];
		w[1] = vertices[3 * triangulos[i + 1] + 1] - vertices[3 * triangulos[i] + 1];
		w[2] = vertices[3 * triangulos[i + 1] + 2] - vertices[3 * triangulos[i] + 2];

		/*Ecuaciones para hacer la normal -> v x w / ||v x w|| (esta es de un triángulo)

		 De donde v x w sale una matriz: |X  Y  Z | cuyo resultado para cada coordenada sería: X = |vy vz|  Y = -|vx vz|   Z = |vx vy|
										 |vx vy vz|												   |wy wz|	     |wx wz|	   |wx wy|
							             |wx wy wz|				 Cuyo determinante sería:		v[1] * w[2]... v[0] * w[2]...  v[0] * w[1]...
			NOTA: vx = v[0], vy = v[1], vz = v[2] 
								y 
		  		  wx = w[0], wy = w[1], wz = w[2]

		La norma de v: ||v|| = sqrt(x^2+y^2+z^2)
		*/
		normal[0] = (v[1] * w[2] - v[2] * w[1]) / sqrt(pow(normal[0], 2) + pow(normal[1], 2) + pow(normal[2], 2));
		normal[1] = (-(v[0] * w[2] - v[2] * w[0])) / sqrt(pow(normal[0], 2) + pow(normal[1], 2) + pow(normal[2], 2));
		normal[2] = (v[0] * w[1] - v[1] * w[0]) / sqrt(pow(normal[0], 2) + pow(normal[1], 2) + pow(normal[2], 2));

		for (int j = i, k = i + 3; j < k; ++j) {
			normales[3 * triangulos[j]] = normal[0];
			normales[3 * triangulos[j] + 1] = normal[1];
			normales[3 * triangulos[j] + 2] = normal[2];
		}
	}
}

igvMallaTriangulos::~igvMallaTriangulos() {
	/* Apartado A: destruir la malla de triángulos */
	if (vertices) {
		delete[] vertices;
	}
	if (triangulos) {
		delete[] triangulos;
	}
	if (normales) {
		delete[] normales;
	}
}


// Metodos publicos 

void igvMallaTriangulos::visualizar(void) {
	/* Apartado A: visualización triángulo a triángulo */
	glPushMatrix();

	if (getApartadoA() == true) {
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < num_triangulos; ++i) {
			if (normales && getApartadoD() == true) {
				glNormal3fv(normales + (3 * triangulos[i]));
			}
			else {
				glNormal3f(0,0,1);
			}
			glVertex3fv(vertices + (3 * triangulos[i]));
		}
		glEnd();
	}
	else {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		if (normales && getApartadoD() == true) {
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, 0, normales);
		}
		else {
			glNormal3f(0, 0, 1);
		}
		glDrawElements(GL_TRIANGLES, num_triangulos, GL_UNSIGNED_INT, triangulos);
		if (normales)
			glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	glPopMatrix();

	/* Apartado B: Visualización con array de vértices y en apartado D añadir array de normales */

}

