#include <stdlib.h>
#include "glut.h"
#include "time.h"
#include "math.h"

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);
//Definici�n de clase esfera
class Esfera {
public:
	int var;
	float radio; 
	float x; 
	float y;
	float vel;
	unsigned char rojo; 
	unsigned char verde; 
	unsigned char azul; //tras los atributos, escribimos nuestros m�todos 
	void inicializa(int y);
	void SetColor( unsigned char r,unsigned char v, unsigned char a); 
	void SetRadio(float r); 
	void SetPos(float ix,float iy); 
	void Dibuja();
	void Mueve(); 
};
Esfera e1,e2,e3;
//metodos de clase esfera
//establecer color
void Esfera::SetColor(unsigned char r,unsigned char v,unsigned char a) { 
	rojo=r; 
	verde=v; 
	azul=a;
} 
//establecer radio
void Esfera::SetRadio(float r) {
	if(r<0.1F) r=0.1F; 
	radio=r; 
}
//establecer posicion
void Esfera::SetPos(float ix,float iy) {
	x=ix; 
	y=iy; 
} 
//dibujar esfera
void Esfera::Dibuja() {
	glColor3ub(rojo,verde,azul);
	glTranslatef(x,y,0);
	glutSolidSphere(radio,20,20);
	glTranslatef(-x,-y,0);
}
//Mover esfera
void Esfera::Mueve() {
	//mover en eje X
	x-=vel;
	//funcion para definir el eje Y (PRUEBAS)
	y=10*sin((float)x/3)+var;
	//Cuando una esfera sale de la pantalla por la izquierda, devolverla a la derecha, y reiniciar su par�metro de oscilacion
	if (x<-50){
		x=50;
		var=rand()%5;
	}
}
//inicializar los valores de la esfera
void Esfera::inicializa(int y){
	float r;
	SetPos(50, y);	//posicion a la derecha de la pantalla
	r=rand()%4+1;	//radio aleatorio
	SetRadio(r);	//definir radio
	SetColor(5,100,200);	//definir color
	var=rand()%5+1;	//definir variable para trayectoria
	vel=rand()%3+1;	//definir velocidad del 1 al 3

}

//Definicion del motor gr�fico	
void motor(){
	e1.Dibuja();
	e2.Dibuja();
	e3.Dibuja();
}


int main(int argc,char* argv[]) { 
	//Inicializar el gestor de ventanas GLUT 
	//y crear la ventana 
	glutInit(&argc, argv); 
	glutInitWindowSize(800,600); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva 
	glEnable(GL_LIGHT0); 
	glEnable(GL_LIGHTING); 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150); //Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//25 ms 
	glutKeyboardFunc(OnKeyboardDown);
	srand(time(NULL)); 
	//inicializacion de las 3 esferas
	e1.inicializa(0);
	e2.inicializa(-10);
	e3.inicializa(10);
	
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
	//en este caso dibujamos solo un cubo de alambre
	//aqui es donde hay que poner el c�digo de dibujo
	motor();
	//glTranslatef( 20,  20,  20);
	
	//Al final, cambiar el buffer (redibujar) 
	//no borrar esta linea ni poner nada despues 
	glutSwapBuffers();
} 
void OnTimer(int value) {
	//poner aqui el c�digo de animacion
	float m;
	e1.Mueve();
	e2.Mueve();
	//m= ((double) rand() / (RAND_MAX)) ;
	e3.Mueve();
 
glutTimerFunc(25,OnTimer,0); 
glutPostRedisplay();
} 
void OnKeyboardDown(unsigned char key, int x_t, int y_t) { }