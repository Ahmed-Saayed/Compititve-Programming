SELECT
     p.product_id,p.product_name 
FROM 
    Product p
JOIN
    Sales s ON s.product_id = p.product_id
group by
    p.product_id,
    p.product_name

having 
   min(sale_date) >='2019-01-01' and max(sale_date) <= '2019-03-31' 