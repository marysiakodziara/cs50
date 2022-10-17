SELECT movies.id
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id, stars.person_id = people.id
WHERE people.name = "Kevin Bacon", people.birth = 1958;
