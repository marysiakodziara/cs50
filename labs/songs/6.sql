INNER JOIN songs ON songs.id = artists.id;
SELECT name FROM songs WHERE artists.name = "Post Malone"