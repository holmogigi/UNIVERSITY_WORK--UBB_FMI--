USE GymEquipSuppStore

INSERT INTO Addresses VALUES (1, 'Teodor Mihali', 58, 'Cluj-Napoca', 'Romania')
INSERT INTO Addresses VALUES (2, 'Munctiorilor', 16, 'Cluj-Napoca', 'Romania')
INSERT INTO Addresses VALUES (3, 'Independentei', 102, 'Baia Mare', 'Romania')
INSERT INTO Addresses VALUES (4, 'Freedom', 5, 'New York', 'USA')

INSERT INTO Stores VALUES (1, 1, 'Get Big')
INSERT INTO Stores VALUES (2, 2, 'Bench Press Super')
INSERT INTO Stores VALUES (3, 3, 'Golds')
INSERT INTO Stores VALUES (4, 4, 'Jacked')

INSERT INTO Jobs VALUES (1, 'Cashier', 2500)
INSERT INTO Jobs VALUES (2, 'Cleaner', 2000)
INSERT INTO Jobs VALUES (3, 'Manager', 8000)
INSERT INTO Jobs VALUES (4, 'Shake Expert', 3500)
INSERT INTO Jobs VALUES (5, 'Customer Helper', 5000)

INSERT INTO Employees VALUES (1, 1, 1, 'Stefan')
INSERT INTO Employees VALUES (2, 1, 2, 'Aurel')
INSERT INTO Employees VALUES (3, 1, 3, 'Alex')
INSERT INTO Employees VALUES (4, 1, 4, 'Andrei')
INSERT INTO Employees VALUES (5, 1, 5, 'Marc')
INSERT INTO Employees VALUES (6, 2, 1, 'Mark')
INSERT INTO Employees VALUES (7, 2, 2, 'Dragos')
INSERT INTO Employees VALUES (8, 2, 3, 'Muri')
INSERT INTO Employees VALUES (9, 2, 4, 'Nico')
INSERT INTO Employees VALUES (10, 2, 5, 'Nicholas')
INSERT INTO Employees VALUES (11, 3, 1, 'Patrick')
INSERT INTO Employees VALUES (12, 3, 2, 'Pap')
INSERT INTO Employees VALUES (13, 3, 3, 'Laura')
INSERT INTO Employees VALUES (14, 3, 4, 'Adelian')
INSERT INTO Employees VALUES (15, 3, 5, 'Laura')
INSERT INTO Employees VALUES (16, 4, 1, 'Mariana')
INSERT INTO Employees VALUES (17, 4, 2, 'Mirela')
INSERT INTO Employees VALUES (18, 4, 3, 'Robert')
INSERT INTO Employees VALUES (19, 4, 4, 'Gabi')
INSERT INTO Employees VALUES (20, 4, 5, 'Alen')

INSERT INTO ProteinShakes VALUES (1, 'Vanilla Blueberry', 12, 0)
INSERT INTO ProteinShakes VALUES (2, 'Vanilla Raspberry', 142, 0)
INSERT INTO ProteinShakes VALUES (3, 'Chocoalate Blueberry', 98, 0)
INSERT INTO ProteinShakes VALUES (4, 'Chocoalate Raspberry', 56, 0)

INSERT INTO ShakesRecipes VALUES (1, 'vanilla protein powder + frozen blueberrys + water + milk', 8.60)
INSERT INTO ShakesRecipes VALUES (2, 'vanilla protein powder + frozen raspberrys + water + milk', 9.80)
INSERT INTO ShakesRecipes VALUES (3, 'chocolate protein powder + frozen blueberrys + water + milk', 5.60)
INSERT INTO ShakesRecipes VALUES (4, 'chocolate protein powder + frozen raspberrys + water + milk', 6.70)

INSERT INTO Equipments VALUES (1, 'Barbell', 250)
INSERT INTO Equipments VALUES (2, 'Squat Rack', 500)
INSERT INTO Equipments VALUES (3, 'Full Rack', 1000)
INSERT INTO Equipments VALUES (4, 'Plates', 180)

INSERT INTO Supplements VALUES (1, 'Creatine', 110)
INSERT INTO Supplements VALUES (2, 'Protein Powder', 190)
INSERT INTO Supplements VALUES (3, 'Trenbelone', 330)
INSERT INTO Supplements VALUES (4, 'Clenbuterol', 250)

INSERT INTO Manufacturers VALUES (1, 'Eleiko', 0)
INSERT INTO Manufacturers VALUES (2, 'Rogue', 0)
INSERT INTO Manufacturers VALUES (3, 'Gymbeam', 0)
INSERT INTO Manufacturers VALUES (4, 'MyProtein', 0)

INSERT INTO EquipmentsManufacturers VALUES (1, 1, 168, 178, 250)
INSERT INTO EquipmentsManufacturers VALUES (2, 1, 18, 389, 500)
INSERT INTO EquipmentsManufacturers VALUES (3, 2, 85, 730, 1000)
INSERT INTO EquipmentsManufacturers VALUES (4, 2, 847, 90, 180)

INSERT INTO SupplementsManufacturers VALUES (1, 4, 6950, 68, 110)
INSERT INTO SupplementsManufacturers VALUES (2, 4, 695, 120, 190)
INSERT INTO SupplementsManufacturers VALUES (3, 3, 890, 80, 330)
INSERT INTO SupplementsManufacturers VALUES (4, 3, 12, 58, 250)


INSERT INTO Earnings VALUES (1, 4859, 1,1,1,1,1)
INSERT INTO Earnings VALUES (2, 590, 2,2,2,2,2)
INSERT INTO Earnings VALUES (3, 1942, 3,3,3,3,3)
INSERT INTO Earnings VALUES (4, 8374, 4,4,4,4,4)

SELECT * FROM Addresses
SELECT * FROM Stores
SELECT * FROM Jobs
SELECT * FROM Employees
SELECT * FROM ProteinShakes
SELECT * FROM ShakesRecipes
SELECT * FROM Equipments
SELECT * FROM Supplements
SELECT * FROM Manufacturers
SELECT * FROM EquipmentsManufacturers
SELECT * FROM SupplementsManufacturers
SELECT * FROM Earnings

--update
INSERT INTO Addresses VALUES (5, 'Freedom2', null, 'New York2', 'USA2')

UPDATE Jobs SET salary=1200 WHERE name = 'Cleaner'
UPDATE ShakesRecipes SET ingredients = 'ZERO' where SR_id=3 AND ingredients = '%raspberrys%'
UPDATE SupplementsManufacturers SET quantity=250 WHERE MAN_id IN (2,3)
UPDATE Addresses SET number = 1 WHERE number IS null

SELECT * FROM Addresses


--delete
SELECT * FROM Addresses
DELETE FROM Addresses WHERE number BETWEEN 1 AND 5
SELECT * FROM Addresses

DELETE FROM Employees WHERE name LIKE '%La%'



--a)
--Make table with Trenbelone and Clenbuterol supps
SELECT name FROM Supplements WHERE name LIKE 'Clenbuterol'
UNION
SELECT name FROM Supplements WHERE name LIKE 'Trenbelone'

--Make table with employes that work in store 2 and 3
SELECT E.S_id, E.E_id, E.name from Employees E WHERE S_id=2 OR S_ID=3



--b)
--Make table with employyes that work in both second and first shop
SELECT E.name FROM Employees E where E.S_id=1
INTERSECT 
SELECT E.name FROM Employees E where E.S_id=2
--All employees that are customers helpers and work in the 1'st shop
SELECT E.name FROM Employees E WHERE E.J_id=5 AND E.S_id IN (SELECT S.S_id FROM Stores S WHERE S.S_id=1)


--c)
--Get protein shakes except the have a bigger quantitiy than 97
SELECT quantity FROM ProteinShakes
EXCEPT
SELECT PS.quantity FROM 
ProteinShakes PS 
WHERE PS.quantity > 97

SELECT PS.quantity 
FROM ProteinShakes PS
WHERE PS.quantity NOT IN (SELECT PS.quantity FROM ProteinShakes PS WHERE PS.quantity > 97)



--d)
--Get all employees from all stores with thir job and salary
SELECT E.name, S.name, J.name, J.salary
FROM Employees E
	INNER JOIN Stores S ON E.S_id= S.S_id
	INNER JOIN Jobs J ON E.J_id = J.J_id
ORDER BY S.name

--Get all shops and their address
SELECT S.name, A.street, A.number, A.city, A.country
FROM Stores S LEFT JOIN Addresses A ON S.S_id = A.A_id

--Get all Protein Shakes and their recipies
SELECT PSR.ingredients, PS.name
FROM ShakesRecipes PSR RIGHT JOIN ProteinShakes PS ON PSR.SR_id = PS.PS_id

--Get all eqquipment with manufactaurer, sell price, buy price, stock
SELECT EQ.name, MAN.name, EQM.buyingPrice,  EQM.sellingPrice, EQM.quantity
FROM EquipmentsManufacturers EQM
FULL JOIN Manufacturers MAN ON EQM.EQ_id = MAN.M_id
FULL JOIN Equipments EQ ON EQM.EQ_id = EQ.EQU_id



--e)
--Get employyes that have a higher than average salary
SELECT DISTINCT E.name
FROM Employees E
WHERE E.E_id IN 
	(
		SELECT E1.E_ID
		FROM Employees E1
		INNER JOIN Stores S ON E1.S_id = S.S_id
		INNER JOIN Jobs J ON E1.J_id = J.J_id
		WHERE J.salary > (SELECT AVG(salary) FROM Jobs)
	)

--Get the earning that come from protein shakes
SELECT E.value, S.name
FROM Earnings E
INNER JOIN Stores S ON E.ST_id = S.S_id
WHERE E.E_id IN
	(
		SELECT E.E_id
		FROM Earnings E
		INNER JOIN ProteinShakes PS ON E.PS_id=PS.PS_id
	)


--f)
--Select protein shakes that have recipies
SELECT PS.name
FROM ProteinShakes PS 
WHERE EXISTS
	(
		SELECT *
		FROM ShakesRecipes SR
		WHERE PS.PS_id = SR.SR_id
	)

--Select manaufactaureers that have at least 1 earning
SELECT MAN.name
FROM Manufacturers MAN
WHERE EXISTS
	(
		SELECT *
		FROM Earnings E
		WHERE MAN.M_id = E_id
	)


--g)
--Get employyes and increase their salary by 300 if < 3000
SELECT J.name, J.salary + 303 as inreasedSalary
FROM
	(
		SELECT E.E_id, E.name, JB.salary
		FROM Employees E INNER JOIN Jobs JB ON E.E_id = JB.J_id
		WHERE NOT JB.salary > 3000
	)J where J.E_id in 
	(
		SELECT DISTINCT E1.E_id
		FROM Employees E1
	)
ORDER BY inreasedSalary DESC

--Get total profit of selling Shakes in the 3'rd store
SELECT sum(T.value)
FROM
	(
	SELECT E.ST_id, E.value, S.name
	FROM Earnings E
	INNER JOIN Stores S ON E.ST_id = S.S_id
	WHERE E.E_id IN
		(
			SELECT E.E_id
			FROM Earnings E
			INNER JOIN ProteinShakes PS ON E.PS_id = PS.PS_id
		)
	)T
WHERE T.ST_id=3


--h)
--Get stores that have at least 6 employyes
SELECT S.name, count(*) AS employees
FROM Stores S INNER JOIN Employees E ON S.S_id = E.S_id
GROUP BY S.name
HAVING count(*) > 15

--Get store with max employyes
SELECT S.name, count(*) AS employees
FROM Stores S INNER JOIN Employees E ON S.S_id = E.S_id
GROUP BY S.name
HAVING count(*) = 
	(
		SELECT max(T.C)
		FROM (SELECT count(*) C
			FROM Stores S INNER JOIN Employees E ON S.S_id = E.S_id
			GROUP BY S.name
		)T
)

--Get shop with highest AVG salary
SELECT TOP 1 T.name, avg(T.salary) as salaries
FROM (
		SELECT S.name, J.salary
		FROM Employees E
		INNER JOIN Stores S ON E.S_id = S.S_id
		INNER JOIN Jobs J ON E.E_id = J.J_id
	 )T
GROUP BY T.name

--Get manaufacteurer with least sales
SELECT M.name, count(*) AS sells
FROM Earnings E INNER JOIN Manufacturers M ON E.MAN_id = M.M_id
GROUP BY M.name 
having count(*) =
				(
					SELECT min(T.C)
					FROM 
					(
						SELECT count(M1.M_id) as C
						FROM Earnings E1 INNER JOIN Manufacturers M1 ON E1.MAN_id = M1.M_id
						GROUP BY M1.M_id)T
					)


--i)
--Get position that have lower salary than customer helper (all)
SELECT J.name, J.salary
FROM Jobs J
WHERE J.salary < all (
						SELECT J.salary
						FROM Jobs J
						WHERE J.name = 'Customer Helper'
					 )

--Get all stores and addresses (any)
SELECT S.name, A.street, A.number, A.city, A.country
FROM Stores S LEFT JOIN Addresses A ON S.a_id =	A.A_id
WHERE S.a_id = any(
					SELECT A.A_id
					FROM Addresses A
				  )

--Get all stored and addresses (in)
SELECT S.name, A.street, A.number, A.city, A.country
FROM Stores S LEFT JOIN Addresses A ON S.a_id =	A.A_id
WHERE S.a_id  in(
					SELECT A.A_id
					FROM Addresses A
				  )

--Get all employess that are not in first store (all)
SELECT E.name
FROM Employees E
WHERE E.S_id <> all(
					SELECT S.S_id
					FROM Stores S
					WHERE S.S_id =1
				   )

--Get all employees that are not in the second store (not in)
SELECT E.name
FROM Employees E
WHERE E.S_id not in(
					SELECT S.S_id
					FROM Stores S
					WHERE S.S_id =1
				   )