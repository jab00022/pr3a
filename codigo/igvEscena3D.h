#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvMallaTriangulos.h"

class igvEscena3D {
	protected:
		// Atributos

		bool ejes;

	public:
		// atributos p�blicos
		igvMallaTriangulos *malla; // malla de tri�ngulos asociada a la escena

		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Metodos est�ticos

		// M�todos
		// m�todo con las llamadas OpenGL para visualizar la escena
    void visualizar();

		bool get_ejes() {return ejes;};
		void set_ejes(bool _ejes){ejes = _ejes;};
};

#endif
