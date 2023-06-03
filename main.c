//
//  main.c
//  DBS_PJ2
//
//  Created by 한종경 on 2023/06/03.
//

#include "Header.h"

int main(void) {
    int exit = 0;
    
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    
    while(!exit){
        clear();
        noecho();
        
        switch(menu()){
            case MENU_TYPE1: TYPE_ONE(); break;
            case MENU_TYPE2: TYPE_TWO(); break;
            case MENU_TYPE3: TYPE_THREE(); break;
            case MENU_TYPE4: TYPE_FOUR(); break;
            case MENU_TYPE5: TYPE_FIVE(); break;
            case MENU_TYPE0: exit = 1; break;
            default: break;
        }
    }
    
    endwin();
    system("clear");
    return 0;
}

char menu(void){
    printw("------- SELECT QUERY TYPES -------\n");
    printw("        1. TYPE I\n");
    printw("        2. TYPE II\n");
    printw("        3. TYPE III\n");
    printw("        4. TYPE IV\n");
    printw("        5. TYPE V\n");
    printw("        0. QUIT\n");
    return wgetch(stdscr);
}

char sub_menu(void){
    clear();
    printw("----- Subtypes in TYPE I -----\n");
    printw("   1. TYPE I-1.\n");
    printw("   2. TYPE I-2.\n");
    printw("   3. TYPE I-3.\n");
    return wgetch(stdscr);
}

void TYPE_ONE(void){
    int exit = 0;
    
    
    while(!exit){
        clear();
        noecho();
        switch(sub_menu()){
            case MENU_TYPE1: TYPE_ONE_ONE(); break;
            case MENU_TYPE2: TYPE_ONE_TWO(); break;
            case MENU_TYPE3: TYPE_ONE_THREE(); break;
            case MENU_TYPE0: exit = 1; break;
            default: break;
        }
    }
}

void TYPE_ONE_ONE(void){
    char TruckNumber[VEHICLE_NUM_LEN];
    int TruckNum;
    
    clear();
    
    
    while(1){
        printw("---- TYPE I-1 ----\n");
        printw("**Assume truckX is destroyed in a crash.**\n");
        printw("*Find all customers who had a package on the truck at the time of the crash.*\n");
        
        getch();
        
        printw(" TRUCK NUMBER ? : ");
        
        echo();
        wgetstr(stdscr, TruckNumber);
        TruckNum = atoi(TruckNumber);
        if(TruckNum == 0) return;
        noecho();
        
        printw("Truck Number is %d\n", TruckNum);
        getch();
        clear();
    }
}


void TYPE_ONE_TWO(void){
    char TruckNumber[VEHICLE_NUM_LEN];
    int TruckNum;
    
    clear();
   
    
    while(1){
        printw("---- TYPE I-2 ----\n");
        printw("**Assume truckX is destroyed in a crash.**\n");
        printw("*Find all recipients who had a package on that truck at the time of the crash.*\n");
        
        getch();

        printw(" TRUCK NUMBER ? : ");
        
        echo();
        wgetstr(stdscr, TruckNumber);
        TruckNum = atoi(TruckNumber);
        if(TruckNum == 0) return;
        noecho();
        
        printw("Truck Number is %d\n", TruckNum);
        getch();
        clear();
    }
}


void TYPE_ONE_THREE(void){
    char TruckNumber[VEHICLE_NUM_LEN];
    int TruckNum;
    
    clear();
    
    
    while(1){
        printw("---- TYPE I-3 ----\n");
        printw("**Assume truckX is destroyed in a crash.**\n");
        printw("*Find the last successful delivery by that truck prior to the crash.*\n");
        
        getch();
        
        printw(" TRUCK NUMBER ? : ");
        
        echo();
        wgetstr(stdscr, TruckNumber);
        TruckNum = atoi(TruckNumber);
        if(TruckNum == 0) return;
        noecho();
        
        printw("Truck Number is %d\n", TruckNum);
        getch();
        clear();
    }
}


void TYPE_TWO(void){
    char c_Year[5];
    int i_Year;
    
    clear();
    
    
    while(1){
        
        printw("---- TYPE II ----\n");
        printw("**Find the customer who has shipped the most packages in the past year.**\n");
        
        getch();
        
        printw(" Which Year ? :");
        
        echo();
        wgetstr(stdscr, c_Year);
        i_Year = atoi(c_Year);
        noecho();
        
        if(i_Year == 0) return;
        
        printw("TYPE_TWO %d\n", i_Year);
        getch();
        clear();
    }
   
}

void TYPE_THREE(void){
    
    char c_Year[5];
    int i_Year;
    
    clear();
    
    while(1){
        printw("---- TYPE III ----\n");
        printw("**Find the customer who has shipped the most packages in the past year.**\n");
        
        getch();
        
        printw(" Which Year ? :");
        
        echo();
        wgetstr(stdscr, c_Year);
        i_Year = atoi(c_Year);
        noecho();
        
        if(i_Year == 0) return;
        
        printw("TYPE_THREE %d\n", i_Year);
        getch();
        clear();
    }
    
    
}

void TYPE_FOUR(void){
    clear();
    
    printw("---- TYPE IV ----\n");
    printw("**Find the packages that were not delivered within the promised time.**\n");
    
    printw("TYPE_FOUR\n");
    noecho();
    
    while(1){
        if(wgetch(stdscr) == '0') break;
    }
}

void TYPE_FIVE(void){
    char c_Year[5];
    char c_Month[5];
    int i_Year;
    int i_Month;
    
    clear();
    
    while(1){
        
        printw("---- TYPE V ----\n");
        printw("**Generate the bill for each customer for the past month.\n");
        printw("  Consider creating several types of bills.**\n");
        
        getch();
        
        printw(" Which Year ? : ");
        
        echo();
        wgetstr(stdscr, c_Year);
        i_Year = atoi(c_Year);
        noecho();
        
        if(i_Year == 0) return;
        
        printw(" Which Month ? : ");
        wgetstr(stdscr, c_Month);
        i_Month = atoi(c_Month);
        
        if(i_Month == 0) return;
        printw("TYPE_FIVE %d %d\n", i_Year, i_Month);
        getch();
        clear();
        
    }
   
        getch();
}
