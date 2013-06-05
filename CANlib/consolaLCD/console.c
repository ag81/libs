/*********************************************************************
 ** 																**
 ** project : MiniPiano 											**
 ** filename : console_display.c 											**
 ** version : 1 .0													**
 ** date : October 25, 2012											**
 ** Description :Librería usada para implementar el patrón facade	**
 ** 			en el que abstraemos un nível el uso del display 	**
 ** 			de la consola y usamos un buffer temporal.			**
 ** 																**
 ** 																**
 **********************************************************************

 *********************************************************************
 **																	**
 ** EXTERNAL LIBRARIES USED 										**
 ** 																**
 **********************************************************************/

#include "console.h"
#include <stdio.h>
#include <string.h>
#include "drivers/rit128x96x4.h"



/*********************************************************************
 //																	**
 // GLOBAL VARIABLES 												**
 // 																**
 **********************************************************************/

//
// el buffer usado, es una matriz con los parametros señalados en console_display.h
//

char ac_consoleImage[MAX_LINES][MAX_COLUMNS+1];

/*********************************************************************
 ** 																**
 ** LOCAL FUNCTIONS 												**
 ** 																**
 **********************************************************************/

//
// se introduce el String pasado en el buffer temporal
//

void consolePrintStr(int x, int y, char* str)
{
  int n;

  n=strlen(str);
  if(n>(MAX_COLUMNS-x))
	  n=MAX_COLUMNS-x;
  strncpy(ac_consoleImage[y]+x,str,n);
}

//
// volcamos a la pantalla el buffer temporal de una vez
//

void refreshConsole(void)
{
  int y;

  for(y=0;y<MAX_LINES;y++)							  
	  RIT128x96x4StringDraw(ac_consoleImage[y], 0, y*LINE_HEIGHT, 15);
}

//
// volcamos a la pantalla solamente una única línea nuestro buffer
//

void Refresh_Console_Line(int y)
{
  RIT128x96x4StringDraw(ac_consoleImage[y], 0, y*LINE_HEIGHT, 15);
}

//
// inicializamos el display y el buffer
//

void initConsole(void)
{
  int i,j;

  RIT128x96x4Init(1000000);
  for(i=0;i<MAX_LINES;i++)
  {
    for(j=0;j<MAX_COLUMNS;j++) ac_consoleImage[i][j]=' ';
    ac_consoleImage[i][MAX_COLUMNS]='\0';
  }
}

//
// borramos una línea de nuestro buffer
//

void eraseConsoleLine(int y)
{
  int j;

  for(j=0;j<MAX_COLUMNS;j++) ac_consoleImage[y][j]=' ';
}


