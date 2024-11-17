-- Train Reservation System

--Tables:
    -- 1. Passenger Table
    -- 2. Train Table
    -- 3. Seat Table
    -- 4. Food Table
    -- 5. Booking Table
    -- 6. Booking Food Table
    -- 7. Booking Seat Table

--Creating tables

    -- 1. Passenger Table
    CREATE TABLE passenger (
        passenger_id NUMBER PRIMARY KEY,
        passenger_name VARCHAR2(100) NOT NULL,
        passenger_age NUMBER NOT NULL
    );

    -- 2. Train Table
    CREATE TABLE train (
        train_id NUMBER PRIMARY KEY,
        train_name VARCHAR2(100) NOT NULL,
        route VARCHAR2(255) NOT NULL
    );

    -- 3. Seat Table
    CREATE TABLE train_seat (
        seat_id NUMBER PRIMARY KEY,
        seat_number VARCHAR2(10) NOT NULL,
        class VARCHAR2(50) NOT NULL,
        seat_price NUMBER NOT NULL
    );

    -- 4. Food Table
    CREATE TABLE train_food (
        item_id NUMBER PRIMARY KEY,
        item_name VARCHAR2(100) NOT NULL,
        price NUMBER NOT NULL
    );

    -- 5. Booking Table
    CREATE TABLE train_booking (
        booking_id NUMBER PRIMARY KEY,
        booking_number VARCHAR2(20) NOT NULL,
        journey_date DATE NOT NULL,
        train_id NUMBER NOT NULL,
        passenger_id NUMBER NOT NULL,
        number_of_tickets NUMBER NOT NULL,
        ticket_amount NUMBER NOT NULL,
        food_amount NUMBER NOT NULL,
        total_amount NUMBER NOT NULL,
        payment_mode VARCHAR2(50) NOT NULL,
        FOREIGN KEY (train_id) REFERENCES train(train_id),
        FOREIGN KEY (passenger_id) REFERENCES passenger(passenger_id)
    );

    -- 6. Booking Food Table
    CREATE TABLE train_booking_food (
        booking_id NUMBER NOT NULL,
        item_id NUMBER NOT NULL,
        quantity NUMBER NOT NULL,
        amount NUMBER NOT NULL,
        PRIMARY KEY (booking_id, item_id),
        FOREIGN KEY (booking_id) REFERENCES train_booking(booking_id),
        FOREIGN KEY (item_id) REFERENCES train_food(item_id)
    );

    -- 7. Booking Seat Table
    CREATE TABLE train_booking_seat (
        booking_id NUMBER NOT NULL,
        seat_id NUMBER NOT NULL,
        price NUMBER NOT NULL,
        PRIMARY KEY (booking_id, seat_id),
        FOREIGN KEY (booking_id) REFERENCES train_booking(booking_id),
        FOREIGN KEY (seat_id) REFERENCES train_seat(seat_id)
    );



--Inserting Data to tables:
    -- 1. Passenger Table
        INSERT INTO passenger VALUES (1, 'Maheswaran', 40);
        INSERT INTO passenger VALUES (2, 'Josh', 60);
        INSERT INTO passenger VALUES (3, 'Dhaheen', 80);
        INSERT INTO passenger VALUES (4, 'Pitchumani', 55);
        INSERT INTO passenger VALUES (5, 'Bhagya', 95);
        INSERT INTO passenger VALUES (6, 'Nayana', 82);

        commit;

    -- 2. Train Table
        INSERT INTO train VALUES (1, 'Rockfort Exp', 'Chennai-Trichy');
        INSERT INTO train VALUES (2, 'Pandian Exp', 'Chennai-Madurai');
        INSERT INTO train VALUES (3, 'Mangalore Exp', 'Chennai-Mangalore');

        commit;

    -- 3. Seat Table
        INSERT INTO train_seat VALUES (1, 'S1-01', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (2, 'S1-02', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (3, 'S1-03', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (4, 'A1-01', 'AC', 1000);
        INSERT INTO train_seat VALUES (5, 'A1-02', 'AC', 1000);
        INSERT INTO train_seat VALUES (6, 'A1-03', 'AC', 1000);
        INSERT INTO train_seat VALUES (7, 'S2-01', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (8, 'S2-02', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (9, 'S2-03', 'Sleeper', 500);

        commit;

    -- 4. Food Table
        INSERT INTO train_food VALUES (1, 'Samosa', 60);
        INSERT INTO train_food VALUES (2, 'Coffee', 40);
        INSERT INTO train_food VALUES (3, 'Popcorn', 100);
        INSERT INTO train_food VALUES (4, 'Veg Meal', 150);
        INSERT INTO train_food VALUES (5, 'Non-Veg Meal', 200);

    -- 5. Booking Table
        INSERT INTO train_booking VALUES (1, 'B001', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 1, 1, 3, 1500, 300, 1800, 'UPI');
        INSERT INTO train_booking VALUES (2, 'B002', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 2, 2, 2, 2000, 300, 2300, 'Card');
        INSERT INTO train_booking VALUES (3, 'B003', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 3, 3, 1, 1000, 200, 1200, 'Cash');
        INSERT INTO train_booking VALUES (4, 'B004', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 1, 4, 1, 500, 100, 600, 'UPI');
        INSERT INTO train_booking VALUES (5, 'B005', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 2, 5, 2, 2000, 400, 2400, 'UPI');
        INSERT INTO train_booking VALUES (6, 'B006', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 3, 6, 1, 1000, 200, 1200, 'Card');

    -- 6. Booking Food Table
        INSERT INTO train_booking_seat VALUES (1, 1, 500);
        INSERT INTO train_booking_seat VALUES (1, 2, 500);
        INSERT INTO train_booking_seat VALUES (1, 3, 500);
        INSERT INTO train_booking_seat VALUES (2, 4, 1000);
        INSERT INTO train_booking_seat VALUES (2, 5, 1000);
        INSERT INTO train_booking_seat VALUES (3, 6, 1000);

    -- 7. Booking Seat Table
        INSERT INTO train_booking_food VALUES (1, 1, 2, 120);
        INSERT INTO train_booking_food VALUES (1, 2, 2, 80);
        INSERT INTO train_booking_food VALUES (2, 4, 2, 300);
        INSERT INTO train_booking_food VALUES (3, 3, 2, 200);

        commit;

--Queries
    -- Update query
        -- 1. Increase the price of all AC seats by 20%.
        UPDATE train_seat
        SET seat_price = seat_price * 1.2
        WHERE class = 'AC';

        -- 2. Update the total amount for all bookings to reflect a 5% discount.
        UPDATE train_booking
        SET total_amount = total_amount * 0.95;

        -- 3. Change the name of the train "Rockfort Exp" to "Rockfort Express".
        UPDATE train
        SET train_name = 'Rockfort Express'
        WHERE train_name = 'Rockfort Exp';

        -- 4. Assign a NULL payment mode to all bookings where the amount exceeds ₹2000.
        UPDATE train_booking
        SET payment_mode = NULL
        WHERE total_amount > 2000;

        -- 5. Add ₹50 to the price of every food item costing less than ₹100.
        UPDATE train_food
        SET price = price + 50
        WHERE price < 100;

    -- Sub query
        -- 1. Find the names of passengers who booked more than 2 tickets.
        SELECT passenger_name
        FROM passenger
        WHERE passenger_id IN (
            SELECT passenger_id
            FROM train_booking
            WHERE number_of_tickets > 2
        );

        -- 2. List all trains that have bookings with total amounts exceeding ₹2000.
        SELECT train_name
        FROM train
        WHERE train_id IN (
            SELECT train_id
            FROM train_booking
            WHERE total_amount > 2000
        );

        -- 3. Find the booking IDs where at least one AC seat was booked.
        SELECT booking_id
        FROM train_booking_seat
        WHERE seat_id IN (
            SELECT seat_id
            FROM train_seat
            WHERE class = 'AC'
        );

        -- 4. Identify the food items ordered in bookings for the train "Pandian Exp".
        SELECT item_name
        FROM train_food
        WHERE item_id IN (
            SELECT item_id
            FROM train_booking_food
            WHERE booking_id IN (
                SELECT booking_id
                FROM train_booking
                WHERE train_id = (SELECT train_id FROM train WHERE train_name = 'Pandian Exp')
            )
        );

        -- 5. Retrieve the passenger names who booked tickets for the "Sleeper" class.
        SELECT passenger_name
        FROM passenger
        WHERE passenger_id IN (
            SELECT passenger_id
            FROM train_booking
            WHERE booking_id IN (
                SELECT booking_id
                FROM train_booking_seat
                WHERE seat_id IN (
                    SELECT seat_id
                    FROM train_seat
                    WHERE class = 'Sleeper'
                )
            )
        );


    -- Correlated query 
        -- 1. Find the bookings where the ticket amount exceeds the combined price of the seats booked.
        SELECT b.booking_id, b.ticket_amount
        FROM train_booking b
        WHERE b.ticket_amount > (
            SELECT SUM(ts.seat_price)
            FROM train_booking_seat tbs
            JOIN train_seat ts ON tbs.seat_id = ts.seat_id
            WHERE tbs.booking_id = b.booking_id
        );

        -- 2. List passenger names who have ordered food costing more than ₹200 in total.
        SELECT p.passenger_name
        FROM passenger p
        WHERE EXISTS (
            SELECT 1
            FROM train_booking_food bf
            JOIN train_booking b ON bf.booking_id = b.booking_id
            WHERE b.passenger_id = p.passenger_id AND bf.amount > 200
        );

        -- 3. Identify bookings where the number of tickets is greater than the number of seats booked.
        SELECT b.booking_id, b.number_of_tickets
        FROM train_booking b
        WHERE b.number_of_tickets > (
            SELECT COUNT(*)
            FROM train_booking_seat
            WHERE booking_id = b.booking_id
        );

        -- 4. Retrieve all trains where the average seat price is greater than ₹800.
        SELECT t.train_name
        FROM train t
        WHERE (
            SELECT AVG(ts.seat_price)
            FROM train_seat ts
            WHERE ts.seat_id IN (
                SELECT seat_id
                FROM train_booking_seat
                WHERE booking_id IN (
                    SELECT booking_id
                    FROM train_booking
                    WHERE train_id = t.train_id
                )
            )
        ) > 800;

        -- 5. List passengers who booked tickets but did not order any food.
        SELECT p.passenger_name
        FROM passenger p
        WHERE NOT EXISTS (
            SELECT 1
            FROM train_booking_food bf
            WHERE bf.booking_id IN (
                SELECT booking_id
                FROM train_booking
                WHERE passenger_id = p.passenger_id
            )
        );

    -- Join query
        -- 1. List all passengers, their train names, and the total amounts they paid.
        SELECT p.passenger_name, t.train_name, b.total_amount
        FROM train_booking b
        JOIN passenger p ON b.passenger_id = p.passenger_id
        JOIN train t ON b.train_id = t.train_id;

        -- 2. Find the seat numbers booked by "Maheswaran".
        SELECT ts.seat_number
        FROM passenger p
        JOIN train_booking b ON p.passenger_id = b.passenger_id
        JOIN train_booking_seat tbs ON b.booking_id = tbs.booking_id
        JOIN train_seat ts ON tbs.seat_id = ts.seat_id
        WHERE p.passenger_name = 'Maheswaran';

        -- 3. Retrieve all food items ordered for the train "Mangalore Exp".
        SELECT tf.item_name, bf.quantity, bf.amount
        FROM train_food tf
        JOIN train_booking_food bf ON tf.item_id = bf.item_id
        JOIN train_booking b ON bf.booking_id = b.booking_id
        JOIN train t ON b.train_id = t.train_id
        WHERE t.train_name = 'Mangalore Exp';

        -- 4. Get the total ticket amount collected for each train.
        SELECT t.train_name, SUM(b.ticket_amount) AS total_ticket_amount
        FROM train t
        JOIN train_booking b ON t.train_id = b.train_id
        GROUP BY t.train_name;

        -- 5. List passengers who booked tickets in the AC class.
        SELECT DISTINCT p.passenger_name
        FROM passenger p
        JOIN train_booking b ON p.passenger_id = b.passenger_id
        JOIN train_booking_seat tbs ON b.booking_id = tbs.booking_id
        JOIN train_seat ts ON tbs.seat_id = ts.seat_id
        WHERE ts.class = 'AC';


    -- Delete query

        -- 1. Delete all bookings made for the train "Pandian Exp".
        DELETE FROM train_booking
        WHERE train_id = (SELECT train_id FROM train WHERE train_name = 'Pandian Exp');

        -- 2. Remove all food orders where the item name is "Popcorn".
        DELETE FROM train_booking_food
        WHERE item_id = (SELECT item_id FROM train_food WHERE item_name = 'Popcorn');

        -- 3. Delete all seat records where the price is less than ₹500.
        DELETE FROM train_seat
        WHERE seat_price < 500;

        -- 4. Remove all bookings where no food was ordered.
        DELETE FROM train_booking
        WHERE booking_id NOT IN (
            SELECT DISTINCT booking_id
            FROM train_booking_food
        );

        -- 5. Delete all train records where no bookings have been made.
        DELETE FROM train
        WHERE train_id NOT IN (
            SELECT DISTINCT train_id
            FROM train_booking
        );
