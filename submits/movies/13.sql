SELECT people.name
FROM people
JOIN stars, movies
ON movies.id = stars.movie_id AND stars.person_id = people.id
GROUP BY stars.person_id = (SELECT people.id FROM people )
AND people.name != "Kevin Bacon";