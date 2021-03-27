// https://programmers.co.kr/learn/courses/30/lessons/68645

#include <vector>

using namespace std;

int space[1002][1002] = {0, };

const int dx[3] = {0, 1, -1};
const int dy[3] = {1, 0, -1};

vector<int> solution(int n)
{
    int cx = 0, cy = 0;
    int idx = 1;

    for (int t = n; t >= 1; t -= 3)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < t - 1; ++j)
            {
                space[cy][cx] = idx;

                cy += dy[i];
                cx += dx[i];

                ++idx;
            }

            if (t == 0 || i == 0)
                space[cy][cx] = idx;
        }

        cy += 2;
        cx += 1;
    }
    
    vector<int> answer;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
            answer.emplace_back(space[i][j]);
    }
    
    return answer;
}