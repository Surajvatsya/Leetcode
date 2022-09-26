# Write your MySQL query statement below

select u.user_id, concat(upper(substr(u.name, 1, 1)),  LOWER(substr(u.name, 2, length(name)-1))  ) as name
from users u
order by u.user_id 
;