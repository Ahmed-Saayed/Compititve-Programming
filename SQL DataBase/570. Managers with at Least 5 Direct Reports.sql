select 
    a.name 
from
    employee a
join 
    employee b
on 
    a.id = b.managerid
group by 
    a.id
having
    count(b.managerid) > 4 