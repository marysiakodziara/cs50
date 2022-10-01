SELECT movies.id, movies.title, movies.year, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id LIMIT 10
COUNT AVG(ratings.rating) WHERE movies.year = 2012;