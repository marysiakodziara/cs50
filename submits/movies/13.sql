SELECT movies.id
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE movies.id = (SELECT stars.movie_id FROM stars JOIN people on stars.person_id = people.id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958);