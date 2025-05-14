select
    name, sum(amount) as balance
from
    users a
join
    transactions b
on
    a.account = b.account
group by
    a.account
having
    sum(amount) > 10000