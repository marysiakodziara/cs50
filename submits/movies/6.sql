SELECT movies.id, movies.title, movies.year, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id
UNION
SELECT AVG(rating) WHERE year = 2012;