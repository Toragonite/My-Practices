CREATE TABLE customer (
    customer_id INT NOT NULL,
    customer_name VARCHAR(20) NOT NULL,
    customer_address varchar(40) NOT NULL,
    customer_phonenumber VARCHAR(20) NOT NULL,
    customer_email varchar(40) NOT NULL,
    PRIMARY KEY (customer_id)
);

CREATE TABLE location (
    location_id INT NOT NULL,
    pickup_location VARCHAR(20) NOT NULL,
    delivery_location VARCHAR(20) NOT NULL,
    PRIMARY KEY (location_id)
);

CREATE TABLE package (
    package_id INT NOT NULL,
    package_type VARCHAR(20) NOT NULL,
    package_value INT NOT NULL,
    package_content VARCHAR(20) NOT NULL,
    location_id INT NULL,
    PRIMARY KEY (package_id),
    FOREIGN KEY (location_id) REFERENCES location (location_id)
);

CREATE TABLE service (
    service_id INT NOT NULL,
    timeliness INT NOT NULL,
    cost INT NOT NULL,
    weight INT NOT NULL,
    distance INT NOT NULL,
    delivery_method VARCHAR(20) NOT NULL,
    PRIMARY KEY (service_id)
);

CREATE TABLE payment (
    payment_id INT NOT NULL,
    customer_id INT NULL,
    payment_type VARCHAR(20) NOT NULL,
    PRIMARY KEY (payment_id),
    FOREIGN KEY (customer_id) REFERENCES customer (customer_id)
);

CREATE TABLE shipment (
    shipment_id INT NOT NULL,
    customer_id INT NOT NULL,
    package_id INT NOT NULL,
    service_id INT NOT NULL,
    shipment_year NUMERIC(4,0) NOT NULL,
    PRIMARY KEY (shipment_id),
    FOREIGN KEY (customer_id) REFERENCES customer (customer_id),
    FOREIGN KEY (package_id) REFERENCES package (package_id),
    FOREIGN KEY (service_id) REFERENCES service (service_id)
);

CREATE TABLE timeline (
    package_id INT NOT NULL,
    register_time DATETIME NOT NULL,
    departure_time DATETIME NOT NULL,
    arrival_time DATETIME NOT NULL,
    PRIMARY KEY (package_id),
    FOREIGN KEY (package_id) REFERENCES package (package_id)
);

CREATE TABLE current_delivery (
    current_delivery_id INT NOT NULL,
    shipment_id INT NULL,
    current_location VARCHAR(20) NOT NULL,
    current_t DATETIME NOT NULL,
    heading_location VARCHAR(20) NOT NULL,
    PRIMARY KEY (current_delivery_id),
    FOREIGN KEY (shipment_id) REFERENCES shipment (shipment_id)
);

CREATE TABLE delivery_method (
    vehicle_id VARCHAR(20) NOT NULL,
    vehicle_type VARCHAR(20) NOT NULL,
    PRIMARY KEY (vehicle_id)
);

CREATE TABLE delivery (
    current_delivery_id INT NOT NULL,
    delivery_status VARCHAR(20) NOT NULL,
    vehicle_id VARCHAR(20) NULL,
    PRIMARY KEY (current_delivery_id),
    FOREIGN KEY (current_delivery_id) REFERENCES current_delivery (current_delivery_id),
    FOREIGN KEY (vehicle_id) REFERENCES delivery_method (vehicle_id)
);

CREATE TABLE account_payment (
    account_number VARCHAR(20) NOT NULL,
    payment_id INT NOT NULL,
    PRIMARY KEY (payment_id),
    FOREIGN KEY (payment_id) REFERENCES payment (payment_id)
);

CREATE TABLE card_payment (
    payment_id INT NOT NULL,
    card_number VARCHAR(20) NOT NULL,
    PRIMARY KEY (payment_id),
    FOREIGN KEY (payment_id) REFERENCES payment (payment_id)
);
