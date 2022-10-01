SELECT AVG(rating) FROM ratings WHERE movie_id = (SELECT id FROM movies WHERE year = 2012);

SELECT movies.id, movies.title, movies.year FROM movies JOIN ratings ON movies.id = ratings.movie_id;