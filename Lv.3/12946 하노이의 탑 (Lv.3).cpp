// https://programmers.co.kr/learn/courses/30/lessons/12946

#include <vector>

using namespace std;

vector<vector<int>> answer;

void recursive(int n, int src, int via, int dest)
{
    vector<int> t(2, 0);
    t[0] = src; t[1] = dest;
    
    if (n == 1)
        answer.emplace_back(t);
    
    else
    {
        recursive(n - 1, src, dest, via);
        answer.emplace_back(t);
        recursive(n - 1, via, src, dest);
    }
}

vector<vector<int>> solution(int n)
{
    recursive(n, 1, 2, 3);
    
    return answer;
}