SELECT people.name
FROM people
JOIN stars, movies
ON people.id = stars.person_id AND stars.movie_id = movies.id
WHERE movies.id IN (SELECT movies.id
                    FROM movies
                    JOIN stars, people
                    ON movies.id = stars.movie_id AND stars.person_id = people.id
                    WHERE people.name = "Kevin Bacon" AND people.birth = 1958);
