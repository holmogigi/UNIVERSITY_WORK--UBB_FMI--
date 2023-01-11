USE GymEquipSuppStore


-- 1 (a view with a SELECT statement operating on one table)
EXEC addToTables 'PriceCheck'

GO
CREATE OR ALTER VIEW getEQPrice AS
	SELECT price, count(*) AS nr_of_prices
	FROM Equipments
	GROUP BY price
GO

EXEC addToViews 'getEQPrice'
EXEC addToTests 'test1'
EXEC connectTableToTest 'PriceCheck', 'test1', 996, 1
EXEC connectViewToTest 'getEQPrice', 'test1'

GO
CREATE OR ALTER PROCEDURE populateEquipments (@rows INT) AS
	WHILE @rows > 0 begin
	INSERT INTO Equipments(EQU_id, name, price) VALUES (@rows, 'test', floor(rand()*1000))
	SET @rows = @rows-1
	END
GO

EXECUTE runTest 'test1'


-- 2 (a view with a SELECT statement that operates on at least 2 different tables and contains at least one JOIN operator)
EXEC addToTables 'StoreAdresses'

GO
CREATE OR ALTER VIEW GetStoreAdresses AS
	SELECT A.street, A.A_id
	FROM Addresses A INNER JOIN Stores S ON S.a_id = A.A_id
	WHERE A.number >= 50
GO

EXEC addToViews 'GetStoreAdresses'
EXEC addToTests 'test2'
EXEC connectTableToTest 'StoreAdresses', 'test2', 996, 1
EXEC connectViewToTest 'GetStoreAdresses', 'test2'

GO
CREATE OR ALTER PROCEDURE populateAdressesTable (@rows INT)AS
	WHILE @rows>0 BEGIN
	INSERT INTO Addresses(A_id, street, number, city, country) VALUES (@rows, 'testing_street', floor(rand()*102), 'testing_city', 'testing_country')
	SET @rows = @rows-1
	END
GO

GO
CREATE OR ALTER PROCEDURE populateStoreTable (@rows INT)AS
	WHILE @rows>0 BEGIN
	INSERT INTO Stores(S_id, a_id, name) VALUES (@rows, @rows, 'testing_name')
	SET @rows = @rows-1
	END
GO

EXECUTE runTest 'test2'


-- 3 (a view with a SELECT statement that has a GROUP BY clause, operates on at least 2 different tables and contains at least one JOIN operator)
EXEC addToTables 'groupManAndSupps'

GO
CREATE OR ALTER VIEW GetgroupManAndSupps AS
	SELECT MAN.M_id, MAN.name, COUNT(*) AS manu
	FROM Manufacturers MAN
	INNER JOIN EquipmentsManufacturers EQM ON MAN.M_id = EQM.MAN_id
	GROUP BY MAN.M_id, MAN.name
GO

EXEC addToViews 'GetgroupManAndSupps'
EXEC addToTests 'test3'
EXEC connectTableToTest 'groupManAndSupps', 'test3', 996, 1
EXEC connectViewToTest 'GetgroupManAndSupps', 'test3'

GO
CREATE OR ALTER PROCEDURE populateManuTable (@rows INT)AS
	WHILE @rows>0 BEGIN
	INSERT INTO Manufacturers(M_id, name, profit) VALUES (@rows, 'testing_name', floor(rand()*1002))
	SET @rows = @rows-1
	END
GO

GO
CREATE OR ALTER PROCEDURE populateEquManuTable (@rows INT)AS
	WHILE @rows>0 BEGIN
	INSERT INTO EquipmentsManufacturers(EQ_id, MAN_id, quantity, buyingPrice, sellingPrice) VALUES (@rows, @rows, floor(rand()*1002),floor(rand()*1002), floor(rand()*1002))
	SET @rows = @rows-1
	END
GO


EXECUTE runTest 'test3'


SELECT * FROM [Views]
SELECT * FROM [TestViews]
SELECT * FROM [TestRuns]
SELECT * FROM [TestRunViews]


