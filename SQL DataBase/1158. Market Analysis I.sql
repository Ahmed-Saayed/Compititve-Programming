select 
    user_id as buyer_id , join_date, count(Orders.order_id) as orders_in_2019 
from 
    users
left join 
    Orders on users.user_id = Orders.buyer_id and year(Orders.order_date) = '2019'
group by 
    user_id