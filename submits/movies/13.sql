people.name
where kevin bacon starred

SELECT people.name FROM people JOIN stars, movies ON movies.id = stars.movie_id AND stars.person_id = people.id
GROUP BY people.name