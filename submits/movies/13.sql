SELECT people.name FROM people JOIN stars, movies ON movies.id = stars.movie_id AND stars.person_id = people.id
GROUP BY movies.title HAVING people.name = "Kevin Bacon" AND people.birth = 1958;