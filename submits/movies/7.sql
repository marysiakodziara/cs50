SELECT movies.title, ratings.rating
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY
    CASE
        WHEN EXISTS (SELECT ratings.rating FROM ratings GROUP BY ratings.rating HAVING COUNT(ratings.rating) > 1) movies.title
        ELSE ratings.rating
    END;

