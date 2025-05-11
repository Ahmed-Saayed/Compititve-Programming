with tmp as(
    select product_id, order_date, unit
    from orders o
    WHERE YEAR(o.order_date)='2020' AND MONTH(o.order_date)='02'
)

select
    b.product_name, sum(a.unit) as unit
from
    tmp a
join
    products b
on a.product_id = b.product_id
group by
    b.product_id
having
    sum(a.unit) >= 100