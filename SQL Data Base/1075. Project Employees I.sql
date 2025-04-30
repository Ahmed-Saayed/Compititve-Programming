select 
    Project.project_id  , ROUND(AVG(Employee.experience_years),2) as average_years 
from
     Project
join
    Employee
on
    Project.employee_id = Employee.employee_id
Group by
    project_id