-- https://programmers.co.kr/learn/courses/30/lessons/59409
SELECT ANIMAL_ID, NAME, IF (SEX_UPON_INTAKE LIKE "Neutered%" OR SEX_UPON_INTAKE LIKE "Spayed%", "O", "X") "중성화"
FROM ANIMAL_INS
ORDER BY ANIMAL_ID