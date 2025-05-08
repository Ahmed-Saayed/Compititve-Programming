select  
    op1.name, op2.bonus
from
    employee op1
left join
    bonus op2
on 
    op1.empid = op2.empid
where
    op2.bonus < 1000 or op2.bonus is null