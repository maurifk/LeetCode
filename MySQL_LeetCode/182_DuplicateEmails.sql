Create table If Not Exists Person (id int, email varchar(255))
Truncate table Person
insert into Person (id, email) values ('1', 'a@b.com')
insert into Person (id, email) values ('2', 'c@d.com')
insert into Person (id, email) values ('3', 'a@b.com');

SELECT DISTINCT p1.email
FROM Person p1, Person p2
WHERE p1.email = p2.email AND NOT p1.id = p2.id;
