// https://programmers.co.kr/learn/courses/30/lessons/1829

#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

int M = 0;
int N = 0;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

bool check(int cy, int cx, const vector<vector<int>>& v)
{
    if (0 <= cy && cy < M && 0 <= cx && cx < N)
    {
        if (v[cy][cx] > 0)
            return true;
    }
        
    return false;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int max_size = 0;
    M = m; N = n;
    
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (check(i, j, picture))
            {
                q.push(make_pair(i, j));
                
                int currval = picture[i][j];
                int count = 0;
                
                picture[i][j] *= -1;
                
                while (!q.empty())
                {
                    pair<int, int> pos = q.front();
                    q.pop();
                    
                    ++count;
                    
                    for (int i = 0; i < 4; i++)
                    {
                        int ny = pos.first + dy[i];
                        int nx = pos.second + dx[i];
            
                        if (check(ny, nx, picture))
                        {
                            if (picture[ny][nx] == currval)
                            {
                                q.push(make_pair(ny, nx));
                                picture[ny][nx] *= -1;
                            }
                            
                        }
                    }
                }
                
                v.emplace_back(make_pair(currval, count));
                max_size = max_size > count ? max_size : count;
            }
        }
    }
    
    vector<int> answer(2);
    
    answer[0] = (int)v.size();
    answer[1] = max_size;
    
    return answer;
}