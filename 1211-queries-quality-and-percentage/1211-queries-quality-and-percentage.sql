# Write your MySQL query statement below
select query_name, round(
    (sum(rating / position)) / count(query_name), 
    2) as quality,
   ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) 
          * 100.0 / COUNT(*), 2) AS poor_query_percentage
from queries 
group by query_name;