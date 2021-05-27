// https://programmers.co.kr/learn/courses/30/lessons/12985

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    int min = a < b ? a : b;
    int max = a < b ? b : a;
    
    while ((min % 2 == 0) || (max != min + 1))
    {
        ++answer;
        
        min = (min % 2 == 0) ? min / 2 : (min + 1) / 2;
        max = (max % 2 == 0) ? max / 2 : (max + 1) / 2;
    }

    return answer;
}