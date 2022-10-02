SELECT movies.title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE (people.name = "Johnny Depp" OR people.name = "Helena Bonham Carter")
GROUP BY stars.movie_id HAVING COUNT(stars.movie_id) > 1


