//Declaracion de directivas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

//Macro para usar en los arreglos
#define TAM 150

//Prototipos de las funciones
void dibujarCirculo(int x, int y, int r);
void burbujas();

int main(){
	int gd = DETECT, gm;
	
	initgraph(&gd, &gm, (char *)"C:\\Turboc3\\BGI");
	
	while(1){
		burbujas();
		delay(1000);
		cleardevice();
	}
	
	closegraph();
	
	return 0;
}

void dibujarCirculo(int x, int y, int r){
	circle(x,y,r);
}

void burbujas(){
	short colors[TAM];
	short i;
	short pos_x[TAM], pos_y[TAM];
	short radius[TAM];
	
	memset(colors, 0, sizeof(colors));
	memset(pos_x, 0, sizeof(pos_x));
	memset(pos_y, 0, sizeof(pos_y));
	memset(radius, 0, sizeof(radius));
	
	srand(time(NULL));
	
	for(i=0; i<TAM; i++){
		pos_x[i] = 15 + rand() % 1500;
	}
	
	for(i=0; i<TAM; i++){
		pos_y[i] = 15 + rand() % 700;
	}
	
	for(i=0; i<TAM; i++){
		radius[i] = 7 + rand() % 40;
	}
	
	for(i=0; i<TAM; i++){
		colors[i] = 1 + rand() % 14;
	}
	
	for(i=0; i<TAM; i++){
		setcolor(colors[i]);
		dibujarCirculo(pos_x[i], pos_y[i], radius[i]);
		setfillstyle(SOLID_FILL, colors[i]);
		floodfill(pos_x[i], pos_y[i], colors[i]);
	}
	
}
