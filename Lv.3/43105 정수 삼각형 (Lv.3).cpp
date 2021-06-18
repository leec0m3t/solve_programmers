// https://programmers.co.kr/learn/courses/30/lessons/43105

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    vector<int> result(1, triangle[0][0]);

    for (int i = 1; i < (int)triangle.size(); ++i)
    {
        vector<int> v = result;

        result.emplace_back(*(result.rbegin()));

        for (int j = 0; j < (int)result.size(); ++j)
        {
            if ((j == 0) || (j == (int)result.size() - 1))
                result[j] += triangle[i][j];

            else
                result[j] = max(v[j - 1] + triangle[i][j], v[j] + triangle[i][j]);
        }
    }

    return *max_element(result.begin(), result.end());
}