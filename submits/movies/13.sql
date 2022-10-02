SELECT people.name FROM people
JOIN stars
ON people.id = stars.person_id
GROUP BY stars.movie_id HAVING COUNT
(SELECT movies.id, people.name FROM movies
JOIN stars, people ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958) = 1;