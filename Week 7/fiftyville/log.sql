-- Keep a log of any SQL queries you execute as you solve the mystery.

--theft of cs50 took place at 10:15 am and transcript uses "%bakery%"
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28;

--to find the suspect from interviewing 3 people
SELECT transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- thief suspects name
SELECT name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25
AND activity = "exit";

-- OLD SUSPECTS
-- Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey

SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";

--NEW SUSPECTS BASED ON 2ND TRANSCRIPT
--Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista

--- COMMON SUSPECTS ARE:
--- Bruce, Diana, Iman, Luca

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = (
SELECT id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29
AND origin_airport_id = (
SELECT id FROM airports
WHERE city = "Fiftyville")
ORDER BY hour, minute
LIMIT 1);

-- SUSPECTS FROM 3rd TRANSCRIPT
--- Doris, Sofia, Bruce, Edward,Kelsey,Taylor,Kenny,Luca

--NARROWED DOWN COMMON SUSPECTS
----Bruce,Luca

--Now, dealing with the phone calls
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60;

-- COMMON suspects
-- BRUCE

-- Ultimately needed thing is "DESTINATION"
--have airport_id that matches with flight_destination_id

SELECT destination_airport_id
FROM flights
JOIN passengers ON passengers.flight_id = flights.id
WHERE passengers.passport_number = 5773159633;
--gives out destination_airport_id = 4

SELECT city FROM airports
WHERE id = 4;
--gives out "New York City"

SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE phone_calls.caller =
(SELECT phone_number FROM people
WHERE name LIKE "Bruce")
AND year = 2021 AND month = 7 AND day = 28 AND phone_calls.duration < 60;
-- the accomplice is Robin
