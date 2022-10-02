SELECT movies.title, ratings.rating
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY ratings.rating
    (CASE
        WHEN COUNT(ratings.rating) > 1 THEN movies.title
        ELSE DESC);

