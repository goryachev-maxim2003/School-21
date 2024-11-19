INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)
VALUES (
(SELECT MAX(id)+1 FROM person_visits),
(SELECT id FROM person WHERE name = 'Dmitriy'),
(SELECT pizzeria_id FROM menu m
JOIN pizzeria pz ON m.pizzeria_id = pz.id
WHERE m.price < 800 AND pz.name != 'Papa Johns' LIMIT 1),
'2022-01-08');