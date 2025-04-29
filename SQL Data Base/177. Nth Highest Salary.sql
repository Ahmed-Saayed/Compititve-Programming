CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
        DECLARE M INT;
        SET M = N - 1;
  RETURN (
      # Write your MySQL query statement below.
    SELECT (
        SELECT DISTINCT salary
        FROM Employee
        order by salary desc
        LIMIT 1 OFFSET M
    )
  );
END