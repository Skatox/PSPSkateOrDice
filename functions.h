Image *p;

//Funcion para generar un numero al azar
int getRandomNum(const int hi){
	int number=  rand()%hi;
	srand(rand());
	return number;
}
//_Funcion que dibuja los dados
void dibujar(char *path,int x_offset,int x) {    
	char buffer[200];
    Image* ourImage; 
	sprintf(buffer, path);
    ourImage = loadImage(buffer); 
	if (!ourImage) {
		//Bug que ocurre al rato donde no se cargan las imagenes
		printTextScreen(0,0,"\n\n MEMORIA LLENA..SALIENDO",0x0000ff);
		flipScreen();
		sceKernelExitGame();
	} else { 
			sceDisplayWaitVblankStart(); 
			blitAlphaImageToScreen(x_offset ,0 ,80,80, ourImage, x, 80);		
	} 
}
//Retorna la posicion del skater:  "Ollie ","Nollie ","Switch ","Fackie ","X "
void getStance(){
	int randomNum = getRandomNum(5);
	dibujar("stance.png",80*randomNum,81);
}

//Retorna cuantos grados debe ejecutar: "180","Shove it","360","Bigspin","360 Shoveit","X"
void getDegrees(){
	int randomNum = getRandomNum(10);

	if(randomNum < 2)
		dibujar("degrees.png",80*0,243);
	else if((randomNum >= 2) && (randomNum < 4))
		dibujar("degrees.png",80*1,243);
	else if(randomNum == 4) 
		dibujar("degrees.png",80*2,243);
	else if(randomNum == 5) 
		dibujar("degrees.png",80*3,243);
	else if((randomNum >= 6) && (randomNum < 8))
		dibujar("degrees.png",80*4,243);
	else if((randomNum >= 8) && (randomNum < 10))
		dibujar("degrees.png",80*5,243);
}

//Retorna el lado donde debe ir: "FS ","BS ","X "
void getSide(){
	int randomNum = getRandomNum(3);
	dibujar("side.png",80*randomNum,162);
}
//Retorna el giro que debe realizar la tabla: "Kickflip ","Heelflip ","X "
void getFlip(){
	int randomNum = getRandomNum(3);
	dibujar("flip.png",80*randomNum,324);
}

//Devuelve la combinación de los trucos
void getTrick(){
	getStance();
	getSide();
	getDegrees();
	getFlip();
}

