INSERT INTO menu VALUES (19, 2, 'greek pizza', 800);
INSERT INTO menu VALUES 
((SELECT MAX(id)+1 FROM menu), (SELECT id FROM pizzeria WHERE name = 'Dominos'), 'sicilian pizza', 900);
INSERT INTO person_visits 
VALUES(
	(SELECT max(id) + 1 FROM person_visits),
	(SELECT id FROM person WHERE name = 'Denis'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'), 
	'2022-02-24'
);

INSERT INTO person_visits 
VALUES(
	(SELECT max(id) + 1 FROM person_visits),
	(SELECT id FROM person WHERE name = 'Irina'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'), 
	'2022-02-24'
);
INSERT INTO person_order VALUES(
	(SELECT max(id)+1 FROM person_order),
	(SELECT id FROM person WHERE name = 'Denis'),
	(SELECT id FROM menu WHERE pizza_name = 'sicilian pizza'),
	'2022-02-24'
);
INSERT INTO person_order VALUES(
	(SELECT max(id)+1 FROM person_order),
	(SELECT id FROM person WHERE name = 'Irina'),
	(SELECT id FROM menu WHERE pizza_name = 'sicilian pizza'),
	'2022-02-24'
);
UPDATE menu
SET price = 0.9 * price
WHERE pizza_name = 'greek pizza';
INSERT INTO person_order
SElECT 
	(SELECT max(id)+p.id FROM person_order) AS id,
	p.id AS person_id,
	(SELECT id FROM menu WHERE pizza_name = 'greek pizza') AS menu_id,
	'2022-02-25' AS order_date
FROM (SELECT id FROM person) AS p;
DELETE FROM person_order
WHERE order_date = '2022-02-25';

DELETE FROM menu
WHERE pizza_name = 'greek pizza';