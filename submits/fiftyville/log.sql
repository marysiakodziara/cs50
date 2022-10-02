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
SELECT name
FROM people
JOIN bank_accounts
ON bank_accounts.person_id = people.id
WHERE account_number = 28500762 OR account_number = 28296815 OR account_number = 76054385 OR account_number = 49610011
OR account_number = 16153065 OR account_number = 25506511 OR account_number = 81061156 OR account_number = 26013199;

\\people who used atm at that street: Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista

\\*3
SELECT caller, receiver, duration
FROM phone_calls
WHERE 
