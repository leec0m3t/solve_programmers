-- https://programmers.co.kr/learn/courses/30/lessons/59047
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE (ANIMAL_TYPE="Dog") AND (LOWER(NAME) LIKE LOWER("%el%"))
ORDER BY NAME