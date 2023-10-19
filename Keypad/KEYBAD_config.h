/********* 	 Layer: HCL 		*********/
/*********	Author: Ahmed 		*********/
/********* Version: 01			*********/
/*********    Date: 23/8/2023	*********/

#ifndef KEYBAD_CONFIG_H_
#define KEYBAD_CONFIG_H_

// Control connected port to port
#define KPD_PORT  PORTC_REG

// Macro to keypad values since they don't change
#define KPD_VALUES {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

// Control columns
#define COL_INIT 0
#define COL_FIN  4

// Control Rows
#define ROW_INIT 0
#define ROW_FIN  4

// Control Keypad Max rows and columns
#define MAX_ROW  4
#define MAX_COL  4




#endif
