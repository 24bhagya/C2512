-- display emp name, salary and total salary(salary + bonus)
select name,
       job_title,
       salary,
       salary + bonus as total_salary
  from employees;

-- display emp name, salary, bonus, incentive percentage.
--    calc incentive, tot salary (salary+bonus+incentive)
--    incentive=salary+10%salary
select name,
       job_title,
       salary,
       salary + bonus + ( salary + ( salary *.1 ) ) as total_salary
  from employees;


-- display emp name whose salary is in between

-- country name then city name based total salary then sort the coutry name, city name based on A-Z
select countries.name as country_name,
       employees.salary as total_salary
  from employees
 inner join cities
on ( employees.city_id = cities.id )
 inner join countries
on ( cities.country_id = countries.id )
 group by employee.salary;
