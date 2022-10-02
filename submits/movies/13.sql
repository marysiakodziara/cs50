SELECT movies.id FROM movies
JOIN stars, people ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE people.name = "Kavin Bacon" AND people.birth = 1958;