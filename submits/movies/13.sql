SELECT people.name
FROM people
JOIN stars, movies
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE movies.id = (SELECT stars.movie_id FROM stars JOIN people
ON people.id = stars.person_id WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
AND people.name != "Kevin Bacon";