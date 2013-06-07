#ifndef CONSOLE_H
#define CONSOLE_H

/*********************************************************************
 ** 																**
 ** DEFINITIONS AND MACROS 											**
 ** 																**
 **********************************************************************/

#define CHAR_WIDTH 6
#define LINE_HEIGHT 8
#define MAX_COLUMNS 31
#define MAX_LINES 24

//*****************************************************************************
//
// EXPORTED FUNCTIONS
//
//*****************************************************************************

void Init_Console(void);
void Refresh_Console(void);
void Console_PrintStr(int x, int y, char* str);
void Refresh_Console_Line(int y);
void Erase_Console_Line(int y);


#endif
/*****************************************************************************
** 																			**
** EOF 																		**
** 																			**
******************************************************************************/
