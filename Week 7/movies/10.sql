SELECT name from people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings on movies.id = ratings.movie_id
WHERE ratings.rating >= 9;
