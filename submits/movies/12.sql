SELECT movies.title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id AND stars.person_id = people.id
HAVING COUNT(movies.title) > 1
ON people.name = "Johnny Depp" OR people.name = "Helena Bonham Carter";

