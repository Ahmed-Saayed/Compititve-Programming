SELECT Person.email AS Email
FROM Person
GROUP BY Email
HAVING COUNT(email) > 1