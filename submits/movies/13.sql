SELECT people.name
FROM people
JOIN stars, movies
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE EXISTS(SELECT stars.movie_id FROM stars JOIN people on stars.person_id = people.id WHERE people.name = "Kevin Bacon");