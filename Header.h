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
#include <cstdlib>
#include <string>
#include <fstream>
#include <filesystem>
#include <iomanip>




#define MENU_TYPE1 '1'
#define MENU_TYPE2 '2'
#define MENU_TYPE3 '3'
#define MENU_TYPE4 '4'
#define MENU_TYPE5 '5'
#define MENU_TYPE0 '0'

#define VEHICLE_NUM_LEN 20
#define MAX_CHAR 256

MYSQL* connection = NULL;
MYSQL conn;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;

int state = 0;

string filename_1 = "createtable.sql";
string filename_2 = "input_file.sql";
string filename_3 = "drop_table.sql";

const char* query_TYPE1_1 = "SELECT DISTINCT c.customer_id, c.customer_name, c.customer_address, c.customer_phonenumber, c.customer_email"
"FROM customer c"
"JOIN shipment s ON c.customer_id = s.customer_id"
"JOIN package p ON s.package_id = p.package_id"
"JOIN current_delivery cd ON s.shipment_id = cd.shipment_id"
"JOIN delivery d ON cd.current_delivery_id = d.current_delivery_id"
"JOIN delivery_method dm ON d.vehicle_id = dm.vehicle_id"
"WHERE dm.vehicle_id = 'TruckNumber' "
"AND d.delivery_status = 'CRASH';";//confirmed

const char* query_TYPE1_2 = "SELECT distinct c.customer_id, c.customer_name"
"FROM customer c"
"JOIN location l ON c.customer_address = l.delivery_location"
"JOIN package p ON l.location_id = p.location_id"
"JOIN shipment s ON p.package_id = s.package_id"
"JOIN current_delivery cd ON s.shipment_id = cd.shipment_id"
"JOIN delivery d ON cd.current_delivery_id = d.current_delivery_id"
"WHERE d.delivery_status ='CRASH'"
"AND d.vehicle_id = 'TruckNumber';";//confirmed

const char* query_TYPE1_3 = "SELECT s.shipment_id, s.customer_id, s.package_id, s.service_id, s.shipment_year"
"FROM shipment s"
"JOIN delivery d ON s.shipment_id = d.current_delivery_id"
"JOIN delivery_method dm ON d.vehicle_id = dm.vehicle_id"
"WHERE dm.vehicle_id = 'TruckNumber'"
"ORDER BY s.shipment_year DESC"
"LIMIT 1;";//

const char* query_TYPE2 = "SELECT c.customer_id, c.customer_name, c.customer_address, c.customer_phonenumber, c.customer_email, COUNT(*) AS total_shipments"
"FROM customer c"
"JOIN shipment s ON c.customer_id = s.customer_id"
"WHERE s.shipment_year = 'c_Year'"
"GROUP BY c.customer_id"
"ORDER BY total_shipments DESC"
"LIMIT 1;";//confirmed

const char* query_TYPE3 = "SELECT c.customer_id, c.customer_name, c.customer_address, c.customer_phonenumber, c.customer_email, COUNT(*) AS total_shipments"
"FROM customer c"
"JOIN shipment s ON c.customer_id = s.customer_id"
"WHERE s.shipment_year = 'c_Year'"
"GROUP BY c.customer_id"
"ORDER BY total_shipments DESC"
"LIMIT 1;";//aggregate cost

const char* query_TYPE4 = "SELECT p.package_id, c.customer_name"
"FROM package p"
"JOIN shipment s ON p.package_id = s.package_id"
"JOIN customer c ON s.customer_id = c.customer_id"
"JOIN current_delivery cd ON s.shipment_id = cd.shipment_id"
"JOIN delivery d ON cd.current_delivery_id = d.current_delivery_id"
"JOIN timeline t ON p.package_id = t.package_id"
"WHERE d.delivery_status = 'DELIVERED'"
 " AND TIMESTAMPDIFF(MINUTE, t.register_time, cd.current_t) > (SELECT timeliness FROM service WHERE service.service_id = s.service_id);";


const char* query_TYPE5 = "SELECT c.customer_id, c.customer_name, c.customer_address, c.customer_phonenumber, c.customer_email, SUM(s.cost) AS total_cost"
"FROM customer c"
"JOIN shipment s ON c.customer_id = s.customer_id"
"WHERE YEAR(s.shipment_year) = i_Year AND MONTH(s.shipment_year) = i_Month"
"GROUP BY c.customer_id;";
/*SELECT c.customer_id, c.customer_name, c.customer_address, c.customer_phonenumber, c.customer_email, SUM(se.cost) AS total_cost
FROM customer c
JOIN shipment s ON c.customer_id = s.customer_id
JOIN service se ON s.service_id = se.service_id
WHERE YEAR(s.shipment_year) = 2021 AND MONTH(s.shipment_year) = 01
GROUP BY c.customer_id;*///month year fix


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
