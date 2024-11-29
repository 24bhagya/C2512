-- emp_db 
    select * from employees WHERE name like '_y%';

    -- find all the names starting with "a"
    -- it is case sensitive
    select * from EMPLOYEES where name like 'A%';


    select * from employees WHERE name like '__n%';



    select * from cities where admin like '%mani';
    
    select * from cities where admin like '%i%i%';
    
    'a' as second character
    select * from cities where admin like '_a%';

    -- display employess name, salary and total salary (salary + bonus)
    -- display employees name, salary, bonus, incentive percentage, 
        caculated incentive, total salary (salary + bonus + incetive) 
        Note: incentive = 10% of salary = salary / 100 * 10
            (salary + bonus + ((salary / 100) * 10))
    -- display employees whose salary between

    select name, salary, salary+bonus+(salary*0.1) as total_salary from employees;

    --salary/100*10= salary+bonus+(salary*0.1)

    select 12567 / 100, 12567 / 100 * 10 from dual;

    select * from employees;

    -- display employees name, department name, city name, 
    -- country name, city admin, country ruler, salary, bonus, total salary (salary + bonus)
    -- country name, city admin, country ruler, salary, bonus
        --   for the salary between 10,000 and 12,000 
                -- WHERE (salary >= 10000) AND (salary <= 12000)
                -- WHERE (salary BETWEEN 10000 AND 12000)
                -- WHERE (salary NOT BETWEEN 10000 AND 12000)
        select name, department_id, SALARY from employees where (salary NOT BETWEEN 10000 AND 12000);
        
    -- country name, city admin, country ruler, salary, bonus
        -- where name ends with letter 'a'                  '%a'
        --       name starts with letter 'A'                'A%'
        --       name contains letter 'y'                   '%y%'
        --       name's scond character to be e             '_e%'
        --       name's third character to be n             '__n%'
        --       name's contains any where two 'e's         '%e%e%'
            -- WHERE (name LIKE '%a')

        
    -- select employees whose salary is company's second max salary

    -- first find max salary
    select * from employees where salary = (select max(salary) from employees);

        select * from employees where salary =
            (select max(salary) from employees where salary <
                (select max(salary) from employees));

        select * from employees where salary =
            (select max(salary) from employees where salary <
                13000);


        select * 
        from employees 
        where salary = (select max(salary) as second_max_salary
                        from employees
                        where salary < (select max(salary) as first_max_salary
                                        from employees));


    -- select employees whose salary is less than company's average salary 

    select * from employees where salary < (
    select avg(salary) from employees);

    -- country id based total salary 
    select countries.id, countries.name, sum(salary) from 
    employees   inner join cities on (employees.city_id=cities.id) 
                inner join countries on (cities.country_id=countries.id) 
    group by countries.id,countries.name;

    -- country nanme based total salary 

    -- city name based total salary 
    select cities.name, sum(salary) from employees 
        inner join cities on (employees.city_id=cities.id)
        group by cities.name;

    -- country name then city name based total salary sort by country A-Z then by city name Z-A order 
        
        (group by, join, having)
        for example, ;
        
        
        select * from employees where salary<25000;

        -- display the cities having salary less than 25000
        select cities.name, sum(salary) from employees 
                        inner join cities on (employees.city_id=cities.id)
                        group by cities.name
                        having sum(salary)<25000
                        order by cities.name asc
                        ;

        select countries.name, cities.name, sum(salary) from employees 
                        inner join cities on (employees.city_id=cities.id)
                        inner join countries on (cities.country_id=countries.id)
                        group by cities.name, countries.name
                        having sum(salary)<25000
                        order by countries.name asc, cities.name desc

                        ;


            select cities.country_id, cities.name, sum(salary) 
            from employees 
                inner join cities on employees.city_id = cities.id
            group by cities.country_id, cities.name
            having sum(salary) < 25000;

    -- display employees who are all getting second max salary from the company [using sub query]
        select * from employees where salary =
            (select max(salary) from employees where salary <
                (select max(salary) from employees));


    -- display employees whose salary matching their department's max salary [correlated sub query]

        select name, SALARY, department_id from employees where salary in (select max(salary)
            from employees group by department_id); --wrong
            

        select name, SALARY, department_id from employees e where salary = (select max(salary)
            from employees where department_id=e.department_id);

        insert into employees (
                                id,
                                name,
                                job_title,
                                department_id,
                                address,
                                city_id, salary,bonus
                                ) values ( 7,
                                        'Bhagya',
                                        'Tester',
                                        20,
                                        '----',
                                        101,
                                        12000, 
                                        5000);

select * from employees;
        --#1
            select department_id, max(salary)
            from employees 
            group by department_id;

            10 15000 [athira, not minhaj]
            20 13000 [dhaheen, not ayisha]
            30 10000 [nayana, not venkatesh]
        --#2
        select parent.name, parent.department_id, parent.salary
        from employees parent
        where parent.salary = (select max(child.salary) 
                            from employees child 
                            where child.department_id = parent.department_id);

    -- display employees whose salary matching their department's second max salary [correlated sub query]
        select parent.* 
        from employees parent 
        where salary = (select max(salary) as second_max_salary
                        from employees 
                        where (department_id = parent.department_id)
                            and (salary < (select max(salary) as first_max_salary
                                        from employees
                                        where (department_id = parent.department_id)
                                        )
                            ) 
                        );

            select * from employees;
    -- display employees whose salary less than their department's average salary [correlated sub query]


        -- select name, SALARY, department_id from employees where salary in (select avg(salary)
        --             from employees group by department_id); 


            SELECT name, salary, department_id 
                FROM employees; e 
                WHERE salary < (SELECT AVG(salary) 
                                FROM employees 
                                WHERE department_id = e.department_id); 


            select name, department_id, salary
                from employees e
                where salary = (select max(salary) 
                                    from employees 
                                    where department_id = e.department_id);


            
