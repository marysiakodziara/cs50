SELECT movies.id, people.name FROM movies
JOIN stars, people ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958;