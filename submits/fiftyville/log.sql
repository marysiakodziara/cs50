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

\\*1

SELECT 