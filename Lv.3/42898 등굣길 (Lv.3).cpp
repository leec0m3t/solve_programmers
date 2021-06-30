// https://programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<long long>> cost(n, vector<long long>(m, 0));
    vector<vector<int>> space(n, vector<int>(m, 1));
    
    for (const auto& i : puddles)
        space[i[1] - 1][i[0] - 1] = 0;
    
    bool flag = true;
    
    for (int i = 0; i < n; ++i)
    {
        if (space[i][0] == 0)
            flag = false;
        
        cost[i][0] = flag ? 1 : 0;
    }
    
    flag = true;
    
    for (int i = 0; i < m; ++i)
    {
        if (space[0][i] == 0)
            flag = false;
        
        cost[0][i] = flag ? 1 : 0;
    }
    
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (space[i][j] == 0)
                cost[i][j] = 0;
                
            else
                cost[i][j] = (cost[i - 1][j] + cost[i][j - 1]) % mod;
        }
    }
    
    return cost[n - 1][m - 1];
}