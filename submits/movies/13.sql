SELECT people.name
FROM people
INNER JOIN
stars as s
ON people.id = s.person_id
INNER JOIN
movies as m
ON s.movie_id = m.id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958;