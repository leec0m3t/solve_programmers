// https://programmers.co.kr/learn/courses/30/lessons/12952

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N = 0;

bool check(const vector<int>& list)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                continue;

            if (abs(i - j) == abs(list[i] - list[j]))
                return false;
        }
    }
    return true;
}

int solution(int n)
{
    int answer = 0;
    N = n;

    vector<int> list;

    for (int i = 0; i < n; ++i)
        list.emplace_back(i);

    do
    {
        answer += check(list) ? 1 : 0;
    } while (next_permutation(list.begin(), list.end()));

    return answer;
}