USE GymEquipSuppStore

--a) change type of column
GO
CREATE OR ALTER PROCEDURE setPriceToFloat AS
	ALTER TABLE Equipments ALTER COLUMN price FLOAT
	SELECT '!SUCCESS! Changed price to float!'

GO
CREATE OR ALTER PROCEDURE setPriceToVarchar AS
	ALTER TABLE Equipments ALTER COLUMN price VARCHAR(10)
	SELECT '!SUCCESS! Changed price to varchar!'



--b) add/remove column
GO
CREATE OR ALTER PROCEDURE addAgeToEmployees AS
	ALTER TABLE Employees ADD age INT
	SELECT '!SUCCESS! Added age to employees!'

GO 
CREATE OR ALTER PROCEDURE removeAGEFromEmployees AS
	ALTER TABLE Employees DROP COLUMN age
	SELECT '!SUCCESS! Removed age from employees!'


--c) add/remove default constraint
GO 
CREATE OR ALTER PROCEDURE addDefaultSupplementsPrice AS
	ALTER TABLE Supplements ADD CONSTRAINT default_price DEFAULT(0) FOR price
	SELECT '!SUCCESS! Added default constraint to price!'

GO 
CREATE OR ALTER PROCEDURE removeDefaultSupplementsPrice AS
	ALTER TABLE Supplements DROP CONSTRAINT default_price 
	SELECT '!SUCCESS! Removed default constraint from price!'


--g) create/drop table
GO
CREATE OR ALTER PROCEDURE addVouchers AS
	CREATE TABLE Vouchers (
			voucher_id INT NOT NULL,
			voucher_code VARCHAR(50) NOT NULL,
			voucher_effect VARCHAR(50) NOT NULL,
			CONSTRAINT VOUCHERS_PRIMARY_KEY PRIMARY KEY(voucher_id)
			)
	SELECT '!SUCCESS! Created table Vouchers!'

GO
CREATE OR ALTER PROCEDURE dropVuchersTable AS
	DROP TABLE Vouchers
	SELECT '!SUCCESS! Dropeed table Vouchers!'


--d) add/remove primary key
GO
CREATE OR ALTER PROCEDURE addVoucherCodeAndEffectPrimaryKeyVouchers AS
	ALTER TABLE Vouchers
		DROP CONSTRAINT VOUCHERS_PRIMARY_KEY
	ALTER TABLE Vouchers
		ADD CONSTRAINT VOUCHERS_PRIMARY_KEY PRIMARY KEY(voucher_code, voucher_effect)

GO
CREATE OR ALTER PROCEDURE removeVoucherCodeAndEffectPrimaryKeyVouchers AS
	ALTER TABLE Vouchers
		DROP CONSTRAINT VOUCHERS_PRIMARY_KEY
	ALTER TABLE Vouchers
		ADD CONSTRAINT VOUCHERS_PRIMARY_KEY PRIMARY KEY(voucher_id)


--e) add/remove candidate key
GO
CREATE OR ALTER PROCEDURE addEquipmentsCandidateKey AS
	ALTER TABLE Equipments
		ADD CONSTRAINT EQUIPMENTS_CANDIDATE_KEY UNIQUE(EQU_id, name, price)

GO 
CREATE OR ALTER PROCEDURE removeEquipmentsCandidateKey AS
	ALTER TABLE Equipments
		DROP CONSTRAINT EQUIPMENTS_CANDIDATE_KEY

--f) add/remove foreign key
GO
CREATE OR ALTER PROCEDURE addForeignKeyEmployee AS
	ALTER TABLE Equipments
		ADD CONSTRAINT EQUIPMENTS_FOREIGN_KEY FOREIGN KEY (EQU_id) REFERENCES Equipments(EQU_id)

GO 
CREATE OR ALTER PROCEDURE removeForeignKeyEmployee AS
	ALTER TABLE Equipments
		DROP CONSTRAINT EQUIPMENTS_FOREIGN_KEY


-- table that contains current version of database 
CREATE TABLE versionTable (
	version INT	
)

INSERT INTO versionTable 
VALUES (1) --init version

-- table that constaint init verison, version after exec and procedure that changes table
CREATE TABLE procedureTable (
	init_version INT,
	last_version INT,
	procedure_name VARCHAR(MAX),
	PRIMARY KEY(init_version, last_version)
)

INSERT INTO procedureTable VALUES
	(1,2, 'setPriceToFloat'),
	(2,1, 'setPriceToVarchar'),
	(2,3, 'addAgeToEmployees'),
	(3,2, 'removeAGEFromEmployees'),
	(3,4, 'addDefaultSupplementsPrice'),
	(4,3, 'removeDefaultSupplementsPrice'),
	(4,5, 'addVouchers'),
	(5,4, 'dropVuchersTable'),
	(5, 6, 'addVoucherCodeAndEffectPrimaryKeyVouchers'),
	(6, 5, 'removeVoucherCodeAndEffectPrimaryKeyVouchers'),
	(6, 7, 'addEquipmentsCandidateKey'),
	(7, 6, 'removeEquipmentsCandidateKey'),
	(7, 8, 'addForeignKeyEmployee'),
	(8, 7, 'removeForeignKeyEmployee')

GO
CREATE OR ALTER PROCEDURE resotreVersion(@new_version INT) AS
	DECLARE @cur INT
	DECLARE @proc_name VARCHAR(MAX)
	SELECT @cur=version FROM versionTable

	IF (@new_version > (SELECT MAX(last_version) FROM procedureTable) OR @new_version < 1)
		RAISERROR ('!ERROR! Bad version!', 10, 1)
	ELSE
	BEGIN
		WHILE @cur > @new_version BEGIN
			SELECT @proc_name=procedure_name FROM procedureTable WHERE init_version=@cur AND last_version=@cur-1
			PRINT ('Exec ' + @proc_name)
			EXEC (@proc_name)
			SET @cur=@cur-1
		END
		UPDATE versionTable SET version=@new_version
	END

