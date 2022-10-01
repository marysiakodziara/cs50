SELECT movies.title FROM movies
JOIN people, ratings, stars
ON movies.id = stars.movie_id AND stars.person_id = people.id AND movies.id = ratings.movie_id
ORDER BY ratings.rating
WHERE people.name = "Chadwick Boseman"
LIMIT 5;

