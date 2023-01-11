USE A5

CREATE TABLE Ta (
	aid INT PRIMARY KEY,
	a2 INT UNIQUE,
	a3 INT
)
DELETE FROM Ta

CREATE TABLE Tb (
	bid INT PRIMARY KEY,
	b2 INT
)

CREATE TABLE Tc (
	cid INT PRIMARY KEY,
	aid INT FOREIGN KEY REFERENCES Ta(aid),
	bid INT FOREIGN KEY REFERENCES Tb(bid)
)


GO
CREATE OR ALTER PROCEDURE insertIntoTa(@rows INT) AS
BEGIN
	DECLARE @max INT
	SET @max = @rows*2 + 100
	WHILE @rows > 0
	BEGIN
		INSERT INTO Ta VALUES (@rows, @max, @max%210)
		SET @rows = @rows - 1
		SET @max = @max - 2
	END
END


GO
CREATE OR ALTER PROCEDURE insertIntoTb(@rows INT) AS
BEGIN
	WHILE @rows > 0 
	BEGIN
		INSERT INTO Tb VALUES(@rows, @rows%542)
		SET @rows = @rows - 1
	END
END


GO
CREATE OR ALTER PROCEDURE insertIntoTc(@rows INT) AS
BEGIN
	DECLARE @aid INT
	DECLARE @bid INT
	WHILE @rows > 0
	BEGIN
		SET @aid = (SELECT TOP 1 aid FROM Ta ORDER BY NEWID())
		SET @bid = (SELECT TOP 1 bid FROM Tb ORDER BY NEWID())
		INSERT INTO Tc VALUES(@rows, @aid, @bid)
		SET @rows = @rows - 1
	END
END


-- a)
SELECT * FROM Ta -- Clustered Index Scan | cost = 0.0176709
SELECT * FROM Ta WHERE aid < 200 -- Clustered Index Seek | cost = 0.0035009
SELECT a3 FROM Ta ORDER BY a3 -- Nonclustered Index Scan | cost = 0.0184116
SELECT a2 FROM Ta WHERE a2 = 1 -- Nonclustered Index Seek | cost = 0.0032831
SELECT a3 FROM Ta WHERE a2 BETWEEN 1000 AND 2000 -- Key Lookup | cost = 0.0176709

--b)
SELECT * FROM Tb WHERE b2 = 269 -- Nonclustered index scan | cost = 0.0226431

-- Clustered index scan | cost = 0.0032974 (after creating)
CREATE NONCLUSTERED INDEX Tb_b2_index ON Tb(b2)
DROP INDEX Tb_b2_index ON Tb


--c)
GO
CREATE OR ALTER VIEW View1 AS
	SELECT A.aid, B.bid, C.cid
	FROM Tc C
	INNER JOIN Ta A ON A.aid = C.aid
	INNER JOIN Tb B ON B.bid = C.bid
	WHERE B.b2 > 500 AND A.a3 < 150

GO

SELECT * FROM View1 -- cost = 0.0138647 (without) 0.0117672 (with index scan)