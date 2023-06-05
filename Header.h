//
//  Header.h
//  DBS_PJ2
//
//  Created by 한종경 on 2023/06/03.
//

#ifndef Header_h
#define Header_h

#include "mysql.h"
#include <iostream>
//#include <stdio.h>
#include <cstdlib>
//#include <string.h>
#include <string>


#define MENU_TYPE1 '1'
#define MENU_TYPE2 '2'
#define MENU_TYPE3 '3'
#define MENU_TYPE4 '4'
#define MENU_TYPE5 '5'
#define MENU_TYPE0 '0'

#define VEHICLE_NUM_LEN 20

int state = 0;

const char* query_TYPE1_1 = "";
const char* query_TYPE1_2 = "";
const char* query_TYPE1_3 = "";
const char* query_TYPE2 = "";
const char* query_TYPE3 = "";
const char* query_TYPE4 = "";
const char* query_TYPE5 = "";
const char* query_TYPE6 = "";


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
