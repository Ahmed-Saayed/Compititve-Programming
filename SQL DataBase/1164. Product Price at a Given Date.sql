select
     p.product_id, coalesce(tmp.new_price,10) as price
from
    (select distinct product_id from products)p
left join
    (
        select product_id, new_price
        from products
        where(product_id, change_date)in(
            select product_id, max(change_date)
            from products

            where change_date <= '2019-08-16'

            group by product_id
        )
    )tmp
on p.product_id = tmp.product_id