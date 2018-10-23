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

		long int num_vertices; // número de vértices de la malla de triángulos
		float *vertices; // array con las (num_vertices * 3) coordenadas de los vértices
		float *normales; // array con las (num_vertices * 3) coordenadas de la normal a cada vértice (sólo para la generación de la esfera)

		long int num_triangulos; // número de triángulos de la malla de triángulos
		unsigned int *triangulos; // array con los (num_triangulos * 3) índices a los vértices de cada triángulo

		// Apartado C: Añadir aquí los atributos con los ángulos de rotación en X, Y y Z.
		float angulos[3];

		bool apartadoA;
		bool apartadoD;

	public:
		// Constructor y destructor
		// Apartado A: constructor de la malla de triángulos
		igvMallaTriangulos(long int _num_vertices, float *_vertices, long int _num_triangulos, unsigned int *_triangulos);

		~igvMallaTriangulos();

		// Métodos
		// método con las llamadas OpenGL para visualizar la malla de triángulos
		void visualizar();

		bool getApartadoA() { return apartadoA; }
		void setApartadoA(bool _apartadoA) { apartadoA = _apartadoA; }

		bool getApartadoD() { return apartadoD; }
		void setApartadoD(bool _apartadoD) { apartadoD = _apartadoD; }

		// Apartado C: métodos para incrementar los ángulos en X, y Z
		void rotaX(float angulo) { angulos[0] += angulo; }
		void rotaY(float angulo) { angulos[1] += angulo; }
		void rotaZ(float angulo) { angulos[2] += angulo; }

		void rota(ejes eje, float angulo) { angulos[eje] += angulo; }

		// Apartado C: métodos para obtener los valores de los ángulos en X, y y Z
		float getAnguloX() { return angulos[0]; }
		float getAnguloY() { return angulos[1]; }
		float getAnguloZ() { return angulos[2]; }

		float getAngulos(ejes eje) { return angulos[eje]; }
};

#endif
