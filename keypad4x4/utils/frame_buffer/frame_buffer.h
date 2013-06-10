/** @addtogroup frame_buffer_MODULE
*
* @{
* @file frame_buffer.h
* @brief La definicion de las funciones del frame buffer.
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

/*****************************************************************************
** 																			**
** MODULES USED 															**
** 																			**
****************************************************************************/

#include "string.h"
#include "platformAbstraction/display/generic_display.h"


/*****************************************************************************
** 																			**
** DEFINITIONS AND MACROS 													**
** 																			**
******************************************************************************/
#define MAX_ROWS 11
#define MAX_LINES 12

#define MAX_WIDTH 128
#define MAX_HEIGHT 96

//Maximo de elementos usados en el frame buffer. Se podra modificar a gusto.

#define MAX_ELEMS 5


enum TYPE{NONE, TEXT, IMAGE};

/*********************************************************************
** 																	**
** TYPEDEFS AND STRUCTURES 											**
** 																	**
**********************************************************************/

typedef struct tDISPLAY_ELEMENT DISPLAY_ELEMENT;

//estructura usada en el frame buffer
struct tDISPLAY_ELEMENT {
	int id;
	int x;
	int y;
	int xOld;
	int yOld;
	int width;
	int height;
	char * text;
	unsigned char * picture;
	int what;
};

/*****************************************************************************
**								 											**
** EXPORTED VARIABLES 														**
** 																			**
******************************************************************************/

/*****************************************************************************
**					 														**
** EXPORTED FUNCTIONS 														**
** 																			**
******************************************************************************/

 void FRAME_BUFFER_init(void);
 int FRAME_BUFFER_insertImage(unsigned char * picture, int x, int y, int w, int h);
 int FRAME_BUFFER_insertText(char * text, int x, int y);
 void FRAME_BUFFER_deleteElement(int id);
 void FRAME_BUFFER_moveElement(int id, int x, int y);
 void FRAME_BUFFER_updateDisplay(void);

 /*****************************************************************************
 ** 																			**
 ** EOF 																		**
 ** 																			**
 ******************************************************************************/
