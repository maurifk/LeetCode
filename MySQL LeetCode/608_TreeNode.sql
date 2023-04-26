Create table If Not Exists Tree (id int, p_id int)
Truncate table Tree
insert into Tree (id, p_id) values ('1', 'None')
insert into Tree (id, p_id) values ('2', '1')
insert into Tree (id, p_id) values ('3', '1')
insert into Tree (id, p_id) values ('4', '2')
insert into Tree (id, p_id) values ('5', '2');

SELECT id, 'Root' as type
FROM Tree
WHERE p_id IS NULL

UNION ALL

SELECT id, 'Inner' as type
FROM Tree t
WHERE p_id IS NOT NULL
  AND EXISTS (SELECT p_id FROM Tree WHERE p_id = t.id)

UNION ALL

SELECT id, 'Leaf' as type
FROM Tree t
WHERE p_id IS NOT NULL
  AND NOT EXISTS (SELECT p_id FROM Tree WHERE p_id = t.id)