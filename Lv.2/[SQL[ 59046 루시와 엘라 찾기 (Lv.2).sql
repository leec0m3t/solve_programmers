-- https://programmers.co.kr/learn/courses/30/lessons/59046
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE (NAME="Lucy" OR Name="Ella" OR Name="Pickle" OR Name="Sabrina" OR Name="Mitty")
ORDER BY ANIMAL_ID