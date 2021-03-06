-- https://programmers.co.kr/learn/courses/30/lessons/59413

WITH RECURSIVE WHOLE AS (
    SELECT 0 AS HOUR
    UNION ALL
    SELECT HOUR + 1 FROM WHOLE WHERE HOUR < 23
)

SELECT W.HOUR, COUNT(HOUR(OUTS.DATETIME)) AS "COUNT"
FROM WHOLE AS W
LEFT JOIN ANIMAL_OUTS AS OUTS
ON W.HOUR = HOUR(OUTS.DATETIME)
GROUP BY W.HOUR
ORDER BY W.HOUR