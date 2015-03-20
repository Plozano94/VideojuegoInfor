#include <math.h>
#include <stdlib.h>

#include "Elemento.h"
#include "glut.h"

void Elemento::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Elemento::setRad(float r) {
	if (r<0.1F) r = 0.1F;
	rad = r;
}

void Elemento::setPosition(float xx, float yy)
{
	x = xx;
	y = yy;
}

void Elemento::setVel(float nvel)
{
	vel = nvel;
}

void Elemento::doMove()
{
	//mover en eje X
	x -= vel;
	//funcion para definir el eje Y (PRUEBAS)
	y = 10 * sin((float)x / 3);
	//Cuando una esfera sale de la pantalla por la izquierda, devolverla a la derecha, y reiniciar su par�metro de oscilacion
	if (x<-50){
		x = 50;
	}
}

void Elemento::doDraw()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(x, y, 0);
	glutSolidSphere(rad, 20, 20);
	glTranslatef(-x, -y, 0);
}
