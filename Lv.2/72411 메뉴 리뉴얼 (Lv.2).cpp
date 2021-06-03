// https://programmers.co.kr/learn/courses/30/lessons/72411

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

map<string, int> m;

void perm_str(const string& from, const string& to, int length)
{
    if ((int)to.size() == length)
    {
        m[to]++;
    }
    
    else
    {
        for (int i = 0; i < (int)from.size(); ++i)
        {   
            int n = (int)to.size();
            
            if (n == 0 || to[n - 1] <= from[i])
            {
                string u = from.substr(0, i) + from.substr(i + 1);
                string v = to + from[i];
            
                perm_str(u, v, length);
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    
    for (int i = 0; i < (int)orders.size(); ++i)
        sort(orders[i].begin(), orders[i].end());
    
    for (int i = 0; i < (int)course.size(); ++i)
    {
        m.clear();
        
        for (int j = 0; j < (int)orders.size(); ++j)
        {
            perm_str(orders[j], "", course[i]);
        }
        
        vector<vector<string>> v(21, vector<string>());
        
        for (const auto& val : m)
        {
            if (val.second >= 2)
            {
                v[val.second].emplace_back(val.first);
            }
        }
        
        for (int j = 20; j >= 0; --j)
        {
            if ((int)v[j].size() != 0)
            {
                for (int k = 0; k < (int)v[j].size(); ++k)
                {
                    answer.emplace_back(v[j][k]);
                }
                
                break;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}