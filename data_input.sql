INSERT INTO customer(customer_id, customer_name, customer_address, customer_phonenumber, customer_email)
VALUES (1, "Jongkyoung Han","seoul gwangin-gu achasan-ro", "010-4127-2473", "doraemon9800@gmail.com"),
(2, "Jimin Park", "seoul seongbuk-gu samseongyo-ro", "010-4391-4351", "7654582@naver.com"),
(3,"Adrian", "CA torrance", "100-4151-2422", "adrian1212@gmail.com"),
(4,"Benjamin", "CA sanfrancisco", " 110-1241-1433", "Obiwan124@gmail.com"),
(5,"Catherin", "CA malibu", "110-2342-1242", "catcat124@gmail.com"),
(6,"Derick", "CA compton", "112-1241-6766", "OG9498@gmail.com"),
(7,"Ethan", "NY soho", "124-3439-9334", "MI12994@gmail.com"),
(8,"Fredrick", "NY harlem", "102-7894-4523", "perry14@gmail.com"),
(9,"George","FL floridacity","112-3349-8975","georgejungle@gmail.com"),
(10,"Henry", "OH oklahoma city", "112-5446-7785", "oxhenry120@gmail.com");


INSERT INTO location(location_id, pickup_location, delivery_location)
VALUES (1, "seoul gwangin-gu achasan-ro", "seoul seongbuk-gu samseongyo-ro"),
(2,"seoul seongbuk-gu samseongyo-ro", "seoul gwangin-gu achasan-ro"),
(3,"CA torrance", "seoul gwangin-gu achasan-ro"),
(4,"CA sanfrancisco", "seoul gwangin-gu achasan-ro"),
(5,"CA malibu", "seoul seongbuk-gu samseongyo-ro"),
(6,"CA compton", "CA malibu"),
(7,"NY soho", "CA sanfrancisco"),
(8,"NY harlem", "NY soho"),
(9,"FL floridacity","CA compton"),
(10,"OH oklahoma city", "FL floridacity");

INSERT INTO package(package_id, package_type, package_value, package_content, location_id)
VALUES (1,"envelope", 0, "NORMAL",1),
(2,"small box", 0, "HAZARDOUS", 2),
(3, "large box", 10000, "NORMAL", 3),
(4,"small box", 5000, "NORMAL", 4),
(5,"envelope", 14000, "HAZARDOUS", 5),
(6,"large box", 0, "HAZARDOUS", 6),
(7,"small box", 0, "NORMAL", 7),
(8,"small box", 0, "NORMAL", 8),
(9,"large box", 0, "NORMAL", 9),
(10, "envelope", 0, "NORMAL", 10);

INSERT INTO service(service_id, timeliness, cost, weight, distance, delivery_method )
VALUES (1, 0, 100, 30, 1000, "TRUCK"),
(2, 1, 50, 30, 1000, "TRUCK"),
(3, 2, 35, 30, 1000, "TRUCK"),
(4, 2, 250, 50, 10000, "AIR_CARGO"),
(5, 3, 180, 50, 10000, "AIR_CARGO"),
(6, 4, 100, 300, 10000, "SHIP_CARGO"),
(7, 7, 70, 300, 10000, "SHIP_CARGO"),
(8, 1, 150, 100, 1000, "TRUCK"),
(9, 2, 120, 100, 1000, "TRUCK"),
(10, 0, 180, 100, 1000, "TRUCK");

INSERT INTO payment(payment_id, payment_type, customer_id)
VALUES (1, "CARD", 1),
(2, "ACCOUNT", 1),
(3,"CARD", 2),
(4, "CARD", 3),
(5, "ACCOUNT", 4),
(6, "CARD", 4),
(7, "ACCOUNT", 5),
(8, "CARD", 5),
(9, "ACCOUNT", 6),
(10, "CARD", 7),
(11, "CARD", 8),
(12, "ACCOUNT",9),
(13, "CARD", 9),
(14, "ACCOUNT", 10);

INSERT INTO account_payment(account_number, payment_id)
VALUES ("110-381-411722", 2),
("110-441-497820", 5),
("3333-09-2342898", 7),
("3333-08-112312", 9),
("010-1141-1242", 12),
("99-9991-9939", 14);


INSERT INTO card_payment(card_number, payment_id)
VALUES ("1234-1234-1234-1234", 1),
("2345-2345-2345-2345", 3),
("3456-3456-3456-3456", 4),
("4567-4567-4567-4567", 6),
("5678-5678-5678-5678", 8),
("4321-4321-4321-4312", 10),
("5423-5432-5423-5423", 11),
("6543-6543-6543-6543", 13);




INSERT INTO shipment(shipment_id, customer_id, package_id, service_id, shipment_year)
VALUES (),
(),
(),
(),
(),
(),
(),
(),
(),
();

INSERT INTO timeline(package_id, register_time, departure_time, arrival_time)
VALUES (),
(),
(),
(),
(),
(),
(),
(),
(),
();

INSERT INTO current_delivery(current_delivery_id, shipment_id, current_location, current_t, heading_location)
VALUES (),
(),
(),
(),
(),
(),
(),
(),
(),
();

INSERT INTO delivery_method(vehicle_id, vehicle_type)
VALUES (),
(),
(),
(),
(),
(),
(),
(),
(),
();

INSERT INTO delivery(current_delivery_id, delivery_status, vehicle_id)
VALUES (),
(),
(),
(),
(),
(),
(),
(),
(),
();


