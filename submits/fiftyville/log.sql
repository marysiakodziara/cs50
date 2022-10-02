 -- Keep a log of any SQL queries you execute as you solve the mystery.
\\ Im starting with looking through table crime_scene _reports as suggestedd in hints
SELECT description
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

\\description states that three witnesses were interviewed, im gonna use this clue and check interviews table
SELECT transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;

\\next hint, from interviews:
\\1.camera footage (hour: around 10:15am as scripted in record above),
\\2.atm machine from Leggett Street,
\\3.phone call to the acomplice and probably acomplices phone call to airport
\\4.flight from fiftyville day after the theft

\\*2
SELECT amount, account_number
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

\\comparing account numbers to their owners
SELECT name, phone_number
FROM people
JOIN bank_accounts
ON bank_accounts.person_id = people.id
WHERE account_number = 28500762 OR account_number = 28296815 OR account_number = 76054385 OR account_number = 49610011
OR account_number = 16153065 OR account_number = 25506511 OR account_number = 81061156 OR account_number = 26013199;

\\people who used atm at that street: Bruce (367) 555-5533, Diana (770) 555-1861, Brooke (122) 555-4581, Kenny (826) 555-1652, Iman (829) 555-5269, Luca (389) 555-5198, Taylor (286) 555-6063, Benista (338) 555-6650

\\*3
SELECT caller, receiver, duration
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND (caller = "(367) 555-5533" OR caller = "(770) 555-1861" OR caller = "(122) 555-4581" OR caller = "(826) 555-1652"
OR caller = "(829) 555-5269" OR caller = "(389) 555-5198" OR caller = "(286) 555-6063" OR caller = "(338) 555-6650");

\\*4
SELECT id
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville"); // 18, 23, 36, 43, 53

SELECT name FROM people JOIN flights on 
