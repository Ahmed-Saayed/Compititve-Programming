SELECT 
    Customers.name AS Customers
FROM 
    Customers
LEFT JOIN 
    Orders ON Customers.id = Orders.Customerid
WHERE
    Orders.Customerid is NULL
