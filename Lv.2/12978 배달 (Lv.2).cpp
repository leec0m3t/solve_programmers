// https://programmers.co.kr/learn/courses/30/lessons/12978

#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

const int INF = 987654321;

int solution(int n, vector<vector<int>> road, int k)
{
    vector<vector<int>> adj(n, vector<int>(n, INF));
    vector<int> dist(n, INF);

    for (const auto& i : road)
    {
        if (adj[i[0] - 1][i[1] - 1] > i[2])
        {
            adj[i[0] - 1][i[1] - 1] = i[2];
            adj[i[1] - 1][i[0] - 1] = i[2];
        }
    }
    
    for (int i = 0; i < n; ++i)
        adj[i][i] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < n; ++i)
    {
        dist[i] = adj[0][i];
        pq.push(make_pair(dist[i], i));
    }
    
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        
        for (int i = 0; i < n; ++i)
        {
            if (dist[i] > dist[p.second] + adj[p.second][i])
            {
                dist[i] = dist[p.second] + adj[p.second][i];
                pq.push(make_pair(adj[p.second][i], i));
            }
        }
    }
    
    int answer = 0;
    
    for (const auto& i : dist)
    {
        if (i <= k) answer++;
    }

    return answer;
}