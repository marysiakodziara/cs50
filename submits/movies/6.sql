SELECT movies.id, movies.title, movies.year, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id LIMIT 10;
SELECT AVG(rating) FROM ratings WHERE year = 2012;