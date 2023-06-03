//
//  Header.h
//  DBS_PJ2
//
//  Created by 한종경 on 2023/06/03.
//

#ifndef Header_h
#define Header_h

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU_TYPE1 '1'
#define MENU_TYPE2 '2'
#define MENU_TYPE3 '3'
#define MENU_TYPE4 '4'
#define MENU_TYPE5 '5'
#define MENU_TYPE0 '0'

#define VEHICLE_NUM_LEN 100

void TYPE_ONE(void);
void TYPE_ONE_ONE(void);
void TYPE_ONE_TWO(void);
void TYPE_ONE_THREE(void);
void TYPE_TWO(void);
void TYPE_THREE(void);
void TYPE_FOUR(void);
void TYPE_FIVE(void);

char menu(void);
char sub_menu(void);

#endif /* Header_h */
