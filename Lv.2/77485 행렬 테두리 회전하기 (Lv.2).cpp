// https://programmers.co.kr/learn/courses/30/lessons/77485

#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<vector<int>> matrix;

    for (int i = 1; i <= rows; ++i)
    {
        vector<int> v;

        for (int j = 1; j <= columns; ++j)
            v.emplace_back((i - 1) * columns + j);

        matrix.emplace_back(v);
    }

    vector<int> answer;

    for (int i = 0; i < (int)queries.size(); ++i)
    {
        vector<vector<int>> prev(matrix);

        int y1 = queries[i][0] - 1;
        int x1 = queries[i][1] - 1;
        int y2 = queries[i][2] - 1;
        int x2 = queries[i][3] - 1;

        int m = matrix[y1][x1];

        for (int j = x1 + 1; j <= x2; ++j)
        {
            matrix[y1][j] = prev[y1][j - 1];

            m = matrix[y1][j] < m ? matrix[y1][j] : m;
        }

        for (int j = y1 + 1; j <= y2; ++j)
        {
            matrix[j][x2] = prev[j - 1][x2];

            m = matrix[j][x2] < m ? matrix[j][x2] : m;
        }

        for (int j = x2 - 1; j >= x1; --j)
        {
            matrix[y2][j] = prev[y2][j + 1];

            m = matrix[y2][j] < m ? matrix[y2][j] : m;
        }

        for (int j = y2 - 1; j >= y1; --j)
        {
            matrix[j][x1] = prev[j + 1][x1] ;

            m = matrix[j][x1] < m ? matrix[j][x1] : m;
        }

        answer.emplace_back(m);
    }

    return answer;
}