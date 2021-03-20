-- https://programmers.co.kr/learn/courses/30/lessons/59410
SELECT ANIMAL_TYPE, IF (NAME IS NULL, "No name", NAME) "NAME", SEX_UPON_INTAKE
FROM ANIMAL_INS
ORDER BY ANIMAL_ID