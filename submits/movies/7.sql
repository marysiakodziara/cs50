SELECT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id
ORDER BY
( CASE
    WHEN ratings.rating HAVING COUNT(ratings.rating) > 1 THEN movies.title
    ELSE DESC
)