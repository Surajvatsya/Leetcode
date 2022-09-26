# Write your MySQL query statement below

select user_id, concat(upper(substr(name, 1, 1)),  LOWER(substr(name, 2, length(name)-1))  ) as name
from users 
order by user_id ASC
;