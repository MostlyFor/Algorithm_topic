# Write your MySQL query statement below
select unique_id, name from employees
left join Employeeuni on employees.id = employeeuni.id