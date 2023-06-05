#include "Header.h"

#pragma comment(lib, "libmysql.lib")

using namespace std;

const char* host = "127.0.0.1";
const char* user = "root";
const char* pw = "!Ehfk171818";
const char* db = "PJ2";

int main(void) {

	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	if (mysql_init(&conn) == NULL)
		//printf("mysql_init() error!");
        cout << "mysql_init() error!" << endl;

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL)
	{   
		cout << mysql_errno(&conn) << "ERROR :" << mysql_error(&conn) << endl;
		return 1;
	}

	else
	{
		printf("Connection Succeed\n");

		if (mysql_select_db(&conn, db))
		{
			printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			return 1;
		}

        int exit = 0;

        while(!exit){
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
        //sql query serach lines

        /* SAMPLE CODE */
        /*
        state = mysql_query(connection, query);
		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
			{
				printf("%s %s %s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
			}
			mysql_free_result(sql_result);
		}
        
        */

       mysql_close(connection);
    }
    return 0;
}

char menu(void){
    system("clear");

    char sel;
    cout << "------- SELECT QUERY TYPES -------" << endl;
    cout << "        1. TYPE I" << endl;
    cout << "        2. TYPE II" << endl;
    cout << "        3. TYPE III" << endl;
    cout << "        4. TYPE IV" << endl;
    cout << "        5. TYPE V" << endl;
    cout << "        0. QUIT" << endl;
    
    cin >> sel;

    return sel;
}

char sub_menu(void){
    system("clear");

    char sel;
    cout << "----- Subtypes in TYPE I -----" << endl;
    cout << "   1. TYPE I-1." << endl;
    cout << "   2. TYPE I-2." << endl;
    cout << "   3. TYPE I-3." << endl;
    cin >> sel;

    return sel;
}

void TYPE_ONE(void){
    int _exit = 0;
    
    while(!_exit){
        system("clear");
        
        switch(sub_menu()){
            case MENU_TYPE1: TYPE_ONE_ONE(); break;
            case MENU_TYPE2: TYPE_ONE_TWO(); break;
            case MENU_TYPE3: TYPE_ONE_THREE(); break;
            case MENU_TYPE0: _exit = 1; break;
            default: break;
        }
    }
}

void TYPE_ONE_ONE(void){
    char TruckNumber[VEHICLE_NUM_LEN];
    int TruckNum;
    
    system("clear");
    
    while(1){
        cout << "---- TYPE I-1 ----" << endl;
        cout << "**Assume truckX is destroyed in a crash.**" << endl;
        cout << "*Find all customers who had a package on the truck at the time of the crash.*" << endl;
        
        cout << " TRUCK NUMBER ? : " << endl;
        
        cin >> TruckNumber;

        TruckNum = atoi(TruckNumber);

        if(TruckNum == 0) return;
        
        cout << "Truck Number is "<< TruckNum << endl;

        system("clear");
    }
}

void TYPE_ONE_TWO(void){
    char TruckNumber[VEHICLE_NUM_LEN];
    int TruckNum;
    
    system("clear");

    while(1){
        cout << "---- TYPE I-2 ----" << endl;
        cout << "**Assume truckX is destroyed in a crash.**" << endl;
        cout << "*Find all recipients who had a package on that truck at the time of the crash.*" << endl;
        
        cout <<" TRUCK NUMBER ? : ";
        cin >> TruckNumber;
        TruckNum = atoi(TruckNumber);
        if(TruckNum == 0) return;
        
        cout << "Truck Number is" << TruckNum << endl;
    }
}


void TYPE_ONE_THREE(void){
    char TruckNumber[VEHICLE_NUM_LEN];
    int TruckNum;
    
    system("clear");
    
    while(1){
        cout << "---- TYPE I-3 ----" << endl;
        cout << "**Assume truckX is destroyed in a crash.**" << endl;
        cout << "*Find the last successful delivery by that truck prior to the crash.*" << endl;
        
        cout << " TRUCK NUMBER ? : ";
        
        cin >> TruckNumber;
        TruckNum = atoi(TruckNumber);
        if(TruckNum == 0) return;
        
        cout << "Truck Number is" << TruckNum << endl;
    }
}


void TYPE_TWO(void){
    char c_Year[5];
    int i_Year;
    
    while(1){
        
        cout << "---- TYPE II ----" << endl;
        cout << "**Find the customer who has shipped the most packages in the past year.**" << endl;
        
        cout << " Which Year ? :";
    
        cin >> c_Year;
        i_Year = atoi(c_Year);
        if(i_Year == 0) return;
        
        cout << "TYPE_TWO" << i_Year << endl;
    }
}

void TYPE_THREE(void){
    
    char c_Year[5];
    int i_Year;
    
    system("clear");
    
    while(1){
        cout << "---- TYPE III ----" << endl;
        cout << "**Find the customer who has shipped the most packages in the past year.**" << endl;
        
        cout << " Which Year ? :";
        cin >> c_Year;
        i_Year = atoi(c_Year);
        if(i_Year == 0) return;
        
        cout << "TYPE_THREE " << i_Year << endl;
        system("clear");
    }
    
    
}

void TYPE_FOUR(void){
    system("clear");
    
    cout << "---- TYPE IV ----" << endl;
    cout << "**Find the packages that were not delivered within the promised time.**" << endl;
    
    cout << "TYPE_FOUR" << endl;
    char q;

    while(1){
        cin >> q;
        if(q == '0') break;
    }
}

void TYPE_FIVE(void){
    char c_Year[5];
    char c_Month[5];
    int i_Year;
    int i_Month;
    
    system("clear");
    
    while(1){
        
        cout << "---- TYPE V ----" << endl;
        cout << "**Generate the bill for each customer for the past month." << endl;
        cout << "  Consider creating several types of bills.**" << endl;
        
        cout << " Which Year ? : ";
        
        cin >> c_Year;
        i_Year = atoi(c_Year);
        if(i_Year == 0) return;
        
        cout << " Which Month ? : ";
        cin >> c_Month;
        i_Month = atoi(c_Month);
        
        if(i_Month == 0) return;
        
        cout <<"TYPE_FIVE" << i_Year << i_Month << endl;

        system("clear");
    }
}
