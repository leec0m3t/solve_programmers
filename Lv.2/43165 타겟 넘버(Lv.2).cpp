// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int index, int total)
{
    index += 1;
    
    if ((int)numbers.size() == index)
    {
        if (total == target)
            answer++;
    }
    
    else
    {
        dfs(numbers, target, index, total + numbers[index]);
        dfs(numbers, target, index, total - numbers[index]);
    }
}

int solution(vector<int> numbers, int target)
{
    dfs(numbers, target, -1, 0);
    
    return answer;
}