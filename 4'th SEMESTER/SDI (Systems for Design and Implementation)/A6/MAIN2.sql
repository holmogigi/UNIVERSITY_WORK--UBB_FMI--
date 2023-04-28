USE BodyBuildersDatabases
GO

ALTER TABLE Contests DROP CONSTRAINT FK_Contests_Bodybuilders_BodybuilderId;
ALTER TABLE Contests DROP CONSTRAINT FK_Contests_Coaches_CoachId;
GO

TRUNCATE TABLE Bodybuilders
TRUNCATE TABLE Coaches
TRUNCATE TABLE Contests
TRUNCATE TABLE Gyms
GO

BULK INSERT Bodybuilders
FROM 'D:\UBB FMI\SEM 4\SDI\csv_generator\bodybuilder.csv' 
WITH (FORMAT = 'CSV', FIRSTROW = 1, FIELDTERMINATOR = ',', ROWTERMINATOR = '\n');
GO

BULK INSERT Gyms
FROM 'D:\UBB FMI\SEM 4\SDI\csv_generator\gyms.csv' 
WITH (FORMAT = 'CSV', FIRSTROW = 1, FIELDTERMINATOR = ',', ROWTERMINATOR = '\n');
GO

BULK INSERT Coaches
FROM 'D:\UBB FMI\SEM 4\SDI\csv_generator\coaches.csv' 
WITH (FORMAT = 'CSV', FIRSTROW = 1, FIELDTERMINATOR = ',', ROWTERMINATOR = '\n');
GO

BULK INSERT Contests
FROM 'D:\UBB FMI\SEM 4\SDI\csv_generator\contests.csv' 
WITH (FORMAT = 'CSV', FIRSTROW = 1, FIELDTERMINATOR = ',', ROWTERMINATOR = '\n');
GO


ALTER TABLE Contests
ADD CONSTRAINT FK_Contests_Bodybuilders_BodybuilderId FOREIGN KEY (BodybuilderId) REFERENCES Bodybuilders (Id),
    CONSTRAINT FK_Contests_Coaches_CoachId FOREIGN KEY (CoachId) REFERENCES Coaches(Id);
GO


SELECT COUNT(*) FROM Bodybuilders
SELECT COUNT(*) FROM Gyms
SELECT COUNT(*) FROM Coaches
SELECT COUNT(*) FROM Contests


