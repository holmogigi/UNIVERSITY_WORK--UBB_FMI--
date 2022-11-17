USE GymEquipSuppStore


CREATE TABLE Addresses
(
	A_id INT PRIMARY KEY NOT NULL,
	street VARCHAR(30) NOT NULL,
	number TINYINT,
	city VARCHAR(30) NOT NULL,
	country VARCHAR(30) NOT NULL
)

CREATE TABLE Stores 
(
	S_id INT PRIMARY KEY NOT NULL,
	a_id INT FOREIGN KEY REFERENCES Addresses(A_id) NOT NULL,
	name VARCHAR(50) NOT NULL
)

CREATE TABLE Jobs
(
	J_id INT PRIMARY KEY NOT NULL,
	name VARCHAR(50) NOT NULL,
	salary FLOAT NOT NULL
)

CREATE TABLE Employees 
(
	E_id INT NOT NULL,
	S_id INT FOREIGN KEY REFERENCES Stores(S_id) NOT NULL,
	J_id INT FOREIGN KEY REFERENCES Jobs(J_id) NOT NULL,
	name VARCHAR(50) NOT NULL
)

CREATE TABLE ProteinShakes
(
	PS_id INT PRIMARY KEY NOT NULL,
	name VARCHAR(50) NOT NULL,
	quantity INT NOT NULL,
	profit FLOAT NOT NULL
	)

CREATE TABLE ShakesRecipes
(
	SR_id INT foreign KEY references ProteinShakes(PS_id) NOT NULL,
	ingredients VARCHAR(70) NOT NULL,
	price FLOAT NOT NULL,
	primary key (SR_id)
)

CREATE TABLE Supplements
(
	SUP_id INT PRIMARY KEY NOT NULL,
	name VARCHAR(50) NOT NULL,
	price FLOAT NOT NULL
)

CREATE TABLE Equipments
(
	EQU_id INT PRIMARY KEY NOT NULL,
	name VARCHAR(50) NOT NULL,
	price FLOAT NOT NULL
)

CREATE TABLE Manufacturers
(
	M_id INT PRIMARY KEY NOT NULL,
	name VARCHAR(50) NOT NULL,
	profit FLOAT NOT NULL
)

CREATE TABLE SupplementsManufacturers
(
	SM_id INT FOREIGN KEY REFERENCES Supplements(SUP_id) NOT NULL,
	MAN_id INT FOREIGN KEY REFERENCES Manufacturers(M_id) NOT NULL,
	PRIMARY KEY(SM_id, MAN_id),
    quantity INT NOT NULL,
    buyingPrice FLOAT NOT NULL,
    sellingPrice FLOAT NOT NULL
)

CREATE TABLE EquipmentsManufacturers
(
	EQ_id INT FOREIGN KEY REFERENCES Equipments(EQU_id) NOT NULL,
	MAN_id INT FOREIGN KEY REFERENCES Manufacturers(M_id) NOT NULL,
	PRIMARY KEY(EQ_id, MAN_id),
    quantity INT NOT NULL,
    buyingPrice FLOAT NOT NULL,
    sellingPrice FLOAT NOT NULL
)

CREATE TABLE Earnings 
(
	E_id INT PRIMARY KEY NOT NULL,
	value FLOAT NOT NULL,
	ST_id INT FOREIGN KEY REFERENCES Stores(S_id) NOT NULL,
	SM_id INT,
	EQ_id INT,
	MAN_id INT,
	PS_id INT FOREIGN KEY REFERENCES ProteinShakes(PS_id),
	FOREIGN KEY (SM_id,MAN_id) REFERENCES SupplementsManufacturers(SM_id,MAN_id),
	FOREIGN KEY (EQ_id, MAN_id) REFERENCES EquipmentsManufacturers(EQ_id, MAN_id)
)