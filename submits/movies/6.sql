SELECT movies.id, movies.title, movies.year, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id LIMIT 10
SELECT AVG(ratings.rating) FROM ratings WHERE movies.year = 2012;