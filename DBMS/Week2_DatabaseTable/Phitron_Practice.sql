USE first_database;
CREATE TABLE User(
	username VARCHAR(8),
    email VARCHAR(20),
    first_name VARCHAR(11),
    last_name VARCHAR(11),
    phone_number INT(11),
    addresss VARCHAR(32),
    HSC_result INT(5),
    Date_of_Birth DATE,
    password VARCHAR(6)
);
CREATE DATABASE Assingment;
USE Assingment;
CREATE TABLE Student(
	Name VARCHAR(11),
    Roll INT,
    Class INT,
    Blood_Group VARCHAR(5),
    Contact_No INT,
    Result FLOAT,
    Date_of_birth DATE,
    Age INT
);
RENAME TABLE Student to Student_Table;
DROP TABLE Student_table;
USE first_database;
CREATE TABLE Customer(
	Cust_id VARCHAR(12) NOT NULL,
    Cust_name VARCHAR(20),
    Cust_dob DATE,
    Cust_street VARCHAR(12),
    Cust_city VARCHAR(10) DEFAULT 'DHAKA'
);
INSERT INTO Customer
(Cust_id,Cust_name,Cust_dob,Cust_street,Cust_city) VALUES
('C00001','C_A','1952-12-23','c_street_006','c_city_001');
INSERT INTO Customer
(Cust_id,Cust_name,Cust_city) VALUES
('C00002','C_B','c_city_002');
