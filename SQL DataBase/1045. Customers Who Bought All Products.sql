select 
    a.customer_id
from
    customer a
group by
    a.customer_id
having
    count(distinct a.product_key) = (select count(product_key) from product)