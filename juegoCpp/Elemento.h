#pragma once
class Elemento
{
public:
	//Parametros del objeto base
	float x = 50;
	float y = 0;
	float vel = 0;
	float rad = 5;
	unsigned char rojo = 1;
	unsigned char verde = 100;
	unsigned char azul = 200;
	//Metodos del objeto base
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPosition(float xx, float yy);
	void setRad(float r);
	void setVel(float vel);
	void doMove();
	void doDraw();
};

