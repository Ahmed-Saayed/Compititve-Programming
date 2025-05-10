with tmp1 as(
    select requester_id id from RequestAccepted
    union
    select accepter_id id from RequestAccepted
),
 tmp2 as(
    select requester_id id from RequestAccepted
    union all
    select accepter_id id from RequestAccepted
)

select tmp1.id id, count(tmp2.id) num
from tmp1
join tmp2
on tmp1.id = tmp2.id
group by id
order by num desc
limit 1