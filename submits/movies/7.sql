movies realsid in 2010, their ratings (desc),

SELECT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id
ORDER BY
( CASE
    WHEN 

)