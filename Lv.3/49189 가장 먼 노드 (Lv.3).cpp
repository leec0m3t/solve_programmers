// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <queue>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    map<int, int> distance;
    
    vector<vector<int>> adj(n, vector<int>(n, 0));
    
    for (int i = 0; i < (int)edge.size(); ++i)
    {
        adj[edge[i][0] - 1][edge[i][1] - 1] = 1;
        adj[edge[i][1] - 1][edge[i][0] - 1] = 1;
    }
    
    queue<pair<int, int>> q;
    int num = -1;
    
    vector<bool> check(20001, true);
    
    for (int i = 0; i < (int)adj[0].size(); ++i)
    {
        if (adj[0][i] == 1)
        {
            q.push(make_pair(i, -1));
            check[i] = false;
            
            adj[i][0] = -1;
            adj[0][i] = -1;
            
            distance[1]++;
        }
    }
    
    while(!q.empty())
    {
        pair<int, int> val = q.front();
        int num = val.second - 1;
        
        q.pop();
        
        for (int i = 0; i < (int)adj[val.first].size(); ++i)
        {
            if (adj[val.first][i] == 1 && check[i] == true)
            {
                q.push(make_pair(i, num));
                check[i] = false;
                
                //cout << val.first + 1 << " to " << i + 1 << " : " << -1 * num << endl;
                
                adj[val.first][i] = num;
                adj[i][val.first] = num;

                distance[-1 * num]++;
                
                answer = distance[-1 * num];
            }
        }
    }
    
    return answer;
}