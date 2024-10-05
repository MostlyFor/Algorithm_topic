# Write your MySQL query statement below

select score, (select count(distinct Score) from Scores where Score >= s.Score) as 'rank'
from scores s
order by score desc
