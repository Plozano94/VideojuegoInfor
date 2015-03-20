#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "glut.h"
#include "Asteroide.h"

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);

Asteroide e1, e2, e3;

//Secuencia de inicializacion
void inicializa(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT 
	//y crear la ventana 
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150); //Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//25 ms 
	glutKeyboardFunc(OnKeyboardDown);
	srand(time(NULL));
}

//Definicion del motor gráfico
void motor(){
	e1.doDraw();
	e2.doDraw();
	e3.doDraw();
}


int main(int argc,char* argv[])
{ 
	inicializa(argc, argv);
	
	e1.setVel(1.5F);
	e1.setColor(255, 0, 0);
	e2.setVel(2.0F);
	e2.setColor(0, 255, 0);
	e3.setVel(2.5F);
	e3.setColor(0, 0, 255);


	//pasarle el control a GLUT,que llamara a los callbacks 
	glutMainLoop(); 

	return 0; 
} 

void OnDraw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	gluLookAt(0.0, 0,100, // posicion del ojo
			  0.0, 0, 0.0, // hacia que punto mira (0,0,0) 
			  0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

	//aqui es donde hay que poner el código de dibujo
	motor();
 
	glutSwapBuffers(); //Cambia los buffer de dibujo, no borrar esta linea ni poner nada despues
}

void OnTimer(int value) //poner aqui el codigo de animacion
{

	e1.doMove();
	e2.doMove();
	e3.doMove();

	glutTimerFunc(30,OnTimer,0); //Temporizador de actulizacion
	glutPostRedisplay(); //Actualizacion de pantalla
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

}