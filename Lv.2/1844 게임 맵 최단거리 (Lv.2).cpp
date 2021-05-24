// https://programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N = 0, M = 0;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

bool check(int y, int x, const vector<vector<int>>& maps)
{
    if ((0 <= y) && (y < N) && (0 <= x) && (x < M))
    {
        if (maps[y][x] == 1)
            return true;
    }
    
    return false;
}

int solution(vector<vector<int>> maps)
{   
    N = (int)maps.size();
    M = (int)maps[0].size();
    
    int ny = 0, nx = 0;
    
    queue<pair<int, int>> q;
    
    q.push(make_pair(0, 0));
    maps[0][0] = 2;
    
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        
        int val = maps[pos.first][pos.second];
        
        if ((pos.first == (N - 1)) && (pos.second == (M - 1)))
        {
            return val - 1;
        }
        
        for (int i = 0; i < 4; i++)
        {
            ny = pos.first + dy[i];
            nx = pos.second + dx[i];
            
            if (check(ny, nx, maps))
            {
                q.push(make_pair(ny, nx));
                maps[ny][nx] = val + 1;
            }
        }
    }
    
    return -1;
}