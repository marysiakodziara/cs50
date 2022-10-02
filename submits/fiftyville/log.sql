 -- Keep a log of any SQL queries you execute as you solve the mystery.
\\ Im starting with looking through table crime_scene _reports as suggestedd in hints
SELECT description
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

\\