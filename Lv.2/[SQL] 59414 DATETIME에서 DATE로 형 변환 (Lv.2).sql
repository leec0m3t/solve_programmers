-- https://programmers.co.kr/learn/courses/30/lessons/59414
SELECT ANIMAL_ID, NAME, SUBSTR(DATETIME, 1, 10) "날짜"
FROM ANIMAL_INS
ORDER BY ANIMAL_ID