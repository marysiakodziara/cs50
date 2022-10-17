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
  \\checking the owners
SELECT people.name
FROM people
JOIN bank_accounts as b
ON b.person_id = people.id
WHERE b.account_number IN (SELECT account_number
                           FROM atm_transactions
                           WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw");

SELECT caller
FROM phone_calls
JOIN people
ON people.id = phone_calls.id
WHERE people.name IN (SELECT people.name
FROM people
JOIN bank_accounts as b
ON b.person_id = people.id
WHERE b.account_number IN (SELECT account_number
                           FROM atm_transactions
                           WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"));

\\*3 didnt use it
SELECT caller, receiver, duration
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
AND (caller = "(367) 555-5533" OR caller = "(770) 555-1861" OR caller = "(122) 555-4581" OR caller = "(826) 555-1652"
OR caller = "(829) 555-5269" OR caller = "(389) 555-5198" OR caller = "(286) 555-6063" OR caller = "(338) 555-6650");
//caller
SELECT name
FROM people
WHERE phone_number = "(367) 555-5533" OR phone_number = "(286) 555-6063"
OR phone_number = "(770) 555-1861" OR phone_number = "(826) 555-1652" OR phone_number = "(338) 555-6650";
//receiver
SELECT name
FROM people
JOIN phone_calls
ON phone_calls.id = people.id
WHERE phone_number = "(375) 555-8161" OR phone_number = "(676) 555-6554" OR phone_number = "(725) 555-3243" OR phone_number = "(066) 555-9701" OR phone_number = "(704) 555-2131";



\\*4
SELECT id, destination_airport_id
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville"); // 18, 23, 36, 43, 53

SELECT name FROM people
JOIN passengers
ON passengers.passport_number = people.passport_number
WHERE flight_id = 18;

\\destination - BOSTON
SELECT city
FROM airports
WHERE id = 6;

\\acomplice - im gonna go through phone_calls once again, this time looking who Diana called to that day
SELECT caller, receiver, duration
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND caller = "(770) 555-1861";


\\now checking the owner of receivers phone number
SELECT name
FROM people
WHERE phone_number = "(725) 555-3243";

\\*1
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 25;

SELECT name
FROM people
WHERE license_plate = "1106N58" OR license_plate = "NRYN856" OR license_plate = "WD5M8I6" OR license_plate = "V47T75I";

\\checking for Taylor
SELECT caller, receiver, duration
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND caller = "(286) 555-6063";

SELECT name
FROM people
WHERE phone_number = "(676) 555-6554" OR phone_number = "(310) 555-8568";