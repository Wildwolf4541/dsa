CREATE DATABASE practice;
USE practice;

CREATE TABLE student(
	id INT PRIMARY KEY,
    sname VARCHAR(255) NOT NULL,
    branch VARCHAR(255) NOT NULL,
    department VARCHAR(255) NOT NULL,
    salary INT
);
CREATE TABLE company(
	cid INT PRIMARY KEY,
	cname VARCHAR(255) NOT NULL,
    location VARCHAR(255) NOT NULL,
    sid INT,
    FOREIGN KEY(sid) REFERENCES student(id) -- ON DELETE CASCADE, ON DELETE SET NULL
);

CREATE TABLE account(
	aname VARCHAR(255) UNIQUE,
    balance INT NOT NULL,
    saving INT NOT NULL DEFAULT 0,
    CONSTRAINT acc_balance_chk CHECK(balance > 1000)
);

INSERT INTO student(id,sname,branch,department,salary) VALUES
(1,'Akhil','ENC','ECED',150000),
(2,'Divyam','COE','CSED',140000),
(3,'Navya','COE','CSED',130000),
(4,'Ritvik','ENC','ECED',120000),
(5,'Abhinav','COE','CSED',140000);

INSERT INTO company(cid,cname,location,sid) VALUES
(1,'Google','Bangalore',1),
(2,'Microsoft','Hyderabad',2),
(3,'Amazon','Bangalore',3),
(4,'Adobe','Noida',4),
(5,'Apple','Bangalore',5);

DROP TABLE IF EXISTS company;
DROP DATABASE IF EXISTS practice1;
-- VARCHAR is variable allocation. CHAR is fixed allocation.


SELECT * FROM student WHERE branch='ENC';
SELECT * FROM student WHERE salary BETWEEN 130000 AND 150000;
SELECT * FROM student WHERE branch IN ('ENC','COE'); 
-- NOT IN, AND, OR, NOT, is NULL

UPDATE student SET branch='ENC', department='ECED' WHERE id=5;
-- SET SQL_SAFE_UPDATES=0

DELETE FROM student WHERE id=5;
DELETE FROM student; -- delete all rows.

REPLACE INTO student(id,sname) VALUES (5,'Abhinav Dhir'); -- use of primary key imp.

-- WILDCARDS (%,_), % is any number of characters, _ is only one character.
SELECT DISTINCT department FROM student WHERE department LIKE '%E%';

-- ORDERING
SELECT sname,salary FROM student ORDER BY salary;
SELECT sname,salary FROM student ORDER BY salary DESC;


-- DATA GROUPING
SELECT department,COUNT(*) FROM student GROUP BY department;
SELECT department,AVG(salary) FROM student GROUP BY department;
-- MIN, MAX, SUM

-- HAVING( used for filtering in GROUP BY)
SELECT department,SUM(salary) FROM student GROUP BY department HAVING COUNT(*)>2;


ALTER TABLE account ADD interest FLOAT NOT NULL DEFAULT 0; -- ADD NEW COLUMN
ALTER TABLE account MODIFY interest DOUBLE NOT NULL DEFAULT 0; -- MODIFY
ALTER TABLE account CHANGE COLUMN interest saving_interest FLOAT NOT NULL DEFAULT 0; -- RENAME COLUMN
ALTER TABLE account DROP COLUMN saving_interest; -- DROP COLUMN
ALTER TABLE account RENAME TO account_renamed; -- RENAME TABLE

-- Describe table
DESC account;

SELECT e1.*,e2.* FROM employee1 AS e1 INNER JOIN employee2 AS e2 ON e1.id=e2.id;
-- LEFT JOIN, RIGHT JOIN
-- FULL JOIN-> LEFT JOIN UNION RIGHT JOIN
-- SELF JOIN-> use INNER JOIN

SELECT * FROM employee1 UNION SELECT * FROM employee2; -- UNION
SELECT DISTINCT * FROM employee1 INNER JOIN employee2 using (id); -- INTERSECTION
SELECT id FROM employee1 LEFT JOIN employee2 USING(id) WHERE employee2.ID IS NULL; -- MINUS


-- VIEW (virtual table)
SELECT * FROM student;

CREATE VIEW custom_view AS SELECT sname,id FROM student;
SELECT * FROM custom_view;
ALTER VIEW cusom_view AS SELECT sname,ID FROM student;
DROP VIEW IF EXISTS custom_view;