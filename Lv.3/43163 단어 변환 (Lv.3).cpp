// https://programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int solution(string begin, string target, vector<string> words)
{
    words.emplace_back(begin);
       
    int n = (int)words.size();
    
    vector<vector<int>> adj(n, vector<int>(n, 0));
    unordered_map<int, string> umap;
    
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    for (int i = 0; i < (int)words.size(); ++i)
    {
        umap[i] = words[i];
        
        for (int j = 0; j < (int)words.size(); ++j)
        {
            if (adj[i][j] == 1)
                continue;
            
            int diff = 0;
            
            for (int k = 0; k < (int)words[i].size(); ++k)
            {
                if (words[i][k] != words[j][k])
                    diff++;
            }
            
            if (diff == 1)
            {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }
    
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; ++i)
    {
        if (adj[n - 1][i] == 1)
        {
            q.push(make_pair(i, 1));
            
            adj[n - 1][i] = -1;
            adj[i][n - 1] = -1;
        }
    }
    
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        if (umap[p.first] == target)
            return p.second;
        
        for (int i = 0; i < n; ++i)
        {
            if (adj[p.first][i] == 1)
            {
                q.push(make_pair(i, p.second + 1));
                
                adj[p.first][i] = -1;
                adj[i][p.first] = -1;
                
            }
        }
    }
    
    int answer = 0;
    
    return answer;
}