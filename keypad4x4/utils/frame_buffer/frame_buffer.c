/** @addtogroup frame_buffer_MODULE
*
* @{
* @file frame_buffer.c
* @brief La implementacion de las funciones del frame buffer
*
* @version v2.0
* @date   	2012-11-23
*
* @note gpl2 license  2012, joseba.alza
*
* @par VERSION HISTORY
* @note Version : 1
* @note Date : 2011-11-22
* @note Revised by : 	joseba.alza@alumni.eps.mondragon.edu
* @note Description : version inicial sin comentarios y sin estructura de carpetas adecuadas.
*
* @}
*/

/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/

#include "frame_buffer.h"

/*********************************************************************
** 																	**
** GLOBAL VARIABLES 												**
** 																	**
**********************************************************************/

// Array en el que se guarda la informacion de la pantalla
static DISPLAY_ELEMENT displayElements[MAX_ELEMS];

// Contador que nos da el numero de elementos insertados en el array
static int display_elements_counter = 0;

static unsigned char EMPTY_PIXEL[60]  =  {
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00
 };

/*********************************************************************
** 																	**
** EXPORTED FUNCTIONS 												**
** 																	**
**********************************************************************/

/**
 * @brief  Inicializa tanto al array temporal usado como la pantalla física usada segun la plataforma
 * @param void
 * @return void
 *
 */

void FRAME_BUFFER_init() {
	int i;

	for (i = 0; i < MAX_ELEMS; i++) {
		displayElements[i].id = i;
		displayElements[i].x = 0;
		displayElements[i].y = 0;
		displayElements[i].width = 0;
		displayElements[i].height = 0;
		displayElements[i].text = 0;
		displayElements[i].picture = 0;
		displayElements[i].what = NONE;
	}
	GENERIC_DISPLAY_init();

}

/**
 * @brief  Inserta la imagen en el buffer.
 * @param picture La imagen a mostrar en pantalla, será un array.
 * @param x posicion horizontal donde estara en pantalla
 * @param y posicion vertical donde estara en pantalla
 * @param w ancho que ocupara en pantalla
 * @param h altura que ocupara en pantalla
 * @return el identificador donde se ha insertado la imagen en el array
 *
 */

int FRAME_BUFFER_insertImage(unsigned char * picture, int x, int y, int w, int h) {

	if (display_elements_counter < MAX_ELEMS) {
		displayElements[display_elements_counter].id = display_elements_counter;
		displayElements[display_elements_counter].x = x;
		displayElements[display_elements_counter].y = y;
		displayElements[display_elements_counter].width = w;
		displayElements[display_elements_counter].height = h;
		displayElements[display_elements_counter].picture = picture;
		displayElements[display_elements_counter].what = IMAGE;
		display_elements_counter++;
	}
	return display_elements_counter - 1;
}


/**
 * @brief  Inserta el texto en el buffer.
 * @param text El texto a mostrar en pantalla, un puntero a caracter.
 * @param x posicion horizontal donde estara en pantalla
 * @param y posicion vertical donde estara en pantalla
 * @return el identificador donde se ha insertado el texto
 *
 */

int FRAME_BUFFER_insertText(char * text, int x, int y) {

	if (display_elements_counter < MAX_ELEMS) {
		displayElements[display_elements_counter].id = display_elements_counter;
		displayElements[display_elements_counter].x = x;
		displayElements[display_elements_counter].y = y;
		displayElements[display_elements_counter].text = text;
		displayElements[display_elements_counter].what = TEXT;
		display_elements_counter++;
	}
	return display_elements_counter - 1;
}

/**
 * @brief  Se elimina del array el elemento que responda al id pasado
 * @param id Identificador del texto a eliminar
 * @return void
 *
 */

void FRAME_BUFFER_deleteElement(int id) {
	if(displayElements[id].what != NONE){
		displayElements[id].x = 0;
		displayElements[id].y = 0;
		displayElements[id].width = 0;
		displayElements[id].height = 0;
		displayElements[id].text = 0;
		displayElements[id].picture = 0;
		displayElements[id].what = NONE;
	}
}

/**
 * @brief  Se mueve el elemento en el array, guardando de la posicion que venia
 * @param id Identificador del texto a mover
 * @param x posicion horizontal donde estara en pantalla
 * @param y posicion vertical donde estara en pantalla
 * @return el identificador donde se ha insertado el texto
 *
 */

void FRAME_BUFFER_moveElement(int id, int x, int y) {
	displayElements[id].xOld = displayElements[id].x;
	displayElements[id].yOld = displayElements[id].y;
	displayElements[id].x = x;
	displayElements[id].y = y;
}

/**
 * @brief  Se vuelca la informacion presente en el array a la pantalla física que tenga la placa.
 * @param void
 * @return void
 * @details Se utiliza un GENERIC_DISPLAY para que se abstraiga de la placa usada.
 */

void FRAME_BUFFER_updateDisplay(void) {
	int i = 0;
	int size = 0;
	int index = 0;
	char str[30];
	for(i = 0; i < display_elements_counter; i++ ) {
		if((displayElements[i].xOld != displayElements[i].x) || ( displayElements[i].yOld != displayElements[i].y )) {
			if (displayElements[i].what == TEXT) {
				size = strlen((char*)displayElements[i].text);
				for (index = 0; index < size; index++){
					str[index]=' ';
				}
				str[index] = '\0';
				GENERIC_DISPLAY_stringDraw(str, displayElements[i].xOld , displayElements[i].yOld, 15);
				GENERIC_DISPLAY_stringDraw(displayElements[i].text, displayElements[i].x, displayElements[i].y, 15 );

			} else if(displayElements[i].what == IMAGE) {
				GENERIC_DISPLAY_imageDraw(EMPTY_PIXEL, displayElements[i].xOld, displayElements[i].yOld, displayElements[i].width, displayElements[i].height);
				GENERIC_DISPLAY_imageDraw(displayElements[i].picture, displayElements[i].x, displayElements[i].y, displayElements[i].width, displayElements[i].height);
			}
		}
	}

 }
