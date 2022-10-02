SELECT movies.title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE people.name = "Johnny Depp" AND people.name = "Helena Bonham Carter";

SELECT movies.title, people.name FROM movies JOIN stars, people
ON movies.title

people.name = "Helena"
people.name = "Johnny"

\\duplicat with changes

select movies where johnny depp was
select movies where helena bonham carter was
select movies.title that have count > 1

SELECT movies.title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE people.name = "Johnny Depp" OR people.name = "Helena Bonham Carter"
HAVING COUNT(movies.title) > 1;
