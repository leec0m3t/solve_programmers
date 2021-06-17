// https://programmers.co.kr/learn/courses/30/lessons/12938

#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;
    answer.reserve(10000);
    
    while (n >= 1)
    {
        answer.emplace_back(s / n);
        
        s -= (s / n);
        n--;
    }
    
    if (answer[0] == 0)
        return { -1 };
    
    return answer;
}