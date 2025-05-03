SELECT 
Department.name AS Department , 
Employee.name AS Employee ,
Employee.salary AS Salary

FROM Department

JOIN Employee ON Department.id = Employee.departmentId

WHERE(Department.id, Employee.salary) IN (
    SELECT departmentId, MAX(salary) 
    FROM Employee 
    GROUP BY departmentId
)