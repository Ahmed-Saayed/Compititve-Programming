select 
    id, movie, description, rating
from 
    Cinema
where
    id % 2 = 1 and description != 'boring' and rating >= 0 and rating <=10
order by 
    rating desc