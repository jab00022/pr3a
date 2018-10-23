#ifndef __IGVMALLATRIANGULOS
#define __IGVMALLATRIANGULOS

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include <string>

typedef enum{
	_X,
	_Y,
	_Z
} ejes;

class igvMallaTriangulos {
	protected:
		// Atributos

		long int num_vertices; // n�mero de v�rtices de la malla de tri�ngulos
		float *vertices; // array con las (num_vertices * 3) coordenadas de los v�rtices
		float *normales; // array con las (num_vertices * 3) coordenadas de la normal a cada v�rtice (s�lo para la generaci�n de la esfera)

		long int num_triangulos; // n�mero de tri�ngulos de la malla de tri�ngulos
		unsigned int *triangulos; // array con los (num_triangulos * 3) �ndices a los v�rtices de cada tri�ngulo

		// Apartado C: A�adir aqu� los atributos con los �ngulos de rotaci�n en X, Y y Z.
		float angulos[3];

		bool apartadoA;
		bool apartadoD;

	public:
		// Constructor y destructor
		// Apartado A: constructor de la malla de tri�ngulos
		igvMallaTriangulos(long int _num_vertices, float *_vertices, long int _num_triangulos, unsigned int *_triangulos);

		~igvMallaTriangulos();

		// M�todos
		// m�todo con las llamadas OpenGL para visualizar la malla de tri�ngulos
		void visualizar();

		bool getApartadoA() { return apartadoA; }
		void setApartadoA(bool _apartadoA) { apartadoA = _apartadoA; }

		bool getApartadoD() { return apartadoD; }
		void setApartadoD(bool _apartadoD) { apartadoD = _apartadoD; }

		// Apartado C: m�todos para incrementar los �ngulos en X, y Z
		void rotaX(float angulo) { angulos[0] += angulo; }
		void rotaY(float angulo) { angulos[1] += angulo; }
		void rotaZ(float angulo) { angulos[2] += angulo; }

		void rota(ejes eje, float angulo) { angulos[eje] += angulo; }

		// Apartado C: m�todos para obtener los valores de los �ngulos en X, y y Z
		float getAnguloX() { return angulos[0]; }
		float getAnguloY() { return angulos[1]; }
		float getAnguloZ() { return angulos[2]; }

		float getAngulos(ejes eje) { return angulos[eje]; }
};

#endif
