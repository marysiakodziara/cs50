SELECT people.name
FROM people
INNER JOIN
stars as s
ON people.id = s.person_id
INNER JOIN
movies as m
ON s.movie_id = m.id
WHERE m.id > (SELECT movies.id
              FROM movies
              JOIN stars, people
              ON movies.id = stars.movie_id AND stars.person_id = people.id
              WHERE people.name = "Kevin Bacon" AND people.birth = 1958);