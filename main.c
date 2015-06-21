/*************************************************************
* *
* Name: Skate or dice *
* Author: Skatox *
* Web-Site:  http://skatox.com/ *
* *
*************************************************************/
 
// Libreria a Incluir Necesarias
#include <pspsdk.h>
#include <pspkernel.h>
#include <psppower.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <pspgu.h>
#include <png.h>
#include <stdio.h>
#include "graphics.h" 
#include "functions.h"
#include "callbacks.h"

PSP_MODULE_INFO("Skate or Dice", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
SceCtrlData currentPad, lastPad;
int opcion = 1; //variable para conocer en que opción estamos

//Imprime el menu principal
void Menu_A(int clear) {
	opcion = 1;
	if(clear==1) clearScreen(0xffffff);
	printTextScreen(10,230,"SKATE OR DICE por Skatox",0x0000ff);
	printTextScreen(10,240,"Seleccione una Opcion:",0xffffff);
	printTextScreen(10,250," -> Lanzar combinacion",0xff0000);
	printTextScreen(10,260,"-> Salir",0xffffff);
	if(clear==1) flipScreen();
}
 
void Menu_B(){
	opcion = 2;
	clearScreen(0xffffff);
	printTextScreen(10,230,"SKATE OR DICE por Skatox",0x0000ff);
	printTextScreen(10,240,"Seleccione una Opcion:",0xffffff);
	printTextScreen(10,250,"-> Lanzar combinacion",0xffffff);
	printTextScreen(10,260," -> Salir",0xff0000);
	flipScreen();
}
//Funcion que se llama al seleccionar "Lanzar Combinacion"
void Opcion_A() {
	clearScreen(0xffffff);
	pspDebugScreenSetTextColor(0x00FF00);
	Menu_A(1);
	getTrick();
	flipScreen();
	sceKernelDelayThread(2*1000*1000);

}
 //Funcion para salir del juego
void Opcion_B() {
	clearScreen(0xffffff);
	printTextScreen(0,0,"Saliendo... Espere...",0x00ff00);
	flipScreen();
	sceKernelExitGame();
}
 
int main() {
	srand(time(NULL)); //crea una nueva semilla a partir de la hora actual
	sceCtrlReadBufferPositive(&lastPad, 1);
	pspDebugScreenInit();
    SetupCallbacks();
    initGraphics(); 
	Menu_A(1);

	while(1) {
 		sceCtrlReadBufferPositive(&currentPad, 1);
 		if( currentPad.Buttons != lastPad.Buttons )
		{
			lastPad = currentPad;
			if((currentPad.Buttons & PSP_CTRL_DOWN)||(currentPad.Buttons & PSP_CTRL_UP))
				switch(opcion) {
					case 1: Menu_B(); break;
					case 2: Menu_A(1);break;
				}
			
		}
		if(currentPad.Buttons & PSP_CTRL_CROSS)
			switch(opcion)	{
				case 1: Opcion_A();	break;
				case 2: Opcion_B(); break;
			}	

	}//fin del while
} 