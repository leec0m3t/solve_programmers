// https://programmers.co.kr/learn/courses/30/lessons/64065

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return (int)a.size() <= (int)b.size() ? true : false;
}

vector<int> solution(string s)
{
    s = s.substr(1, (int)s.size() - 2);
    
    vector<vector<int>> vv;
    bool flag = false;
    
    vector<int> v;
    string temp = "";
    
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == '{')
        {
            flag = true;
            v.clear();
        }
        
        else if (s[i] == '}')
        {
            flag = false;
            
            v.emplace_back(stoi(temp));
            temp = "";
            
            vv.emplace_back(v);
        }
        
        else if (s[i] == ',')
        {
            if (flag == true)
            {
                v.emplace_back(stoi(temp));
                temp = "";
            }
        }
        
        else
        {
            temp += s[i];
        }
    }
    
    sort(vv.begin(), vv.end(), compare);
    
    vector<int> answer;
    
    int value = vv[0][0];
    answer.emplace_back(value);
    
    for (int i = 1; i < (int)vv.size(); ++i)   
    {
        for (int j = i; j < (int)vv.size(); ++j)
        {
            auto it = find(vv[j].begin(), vv[j].end(), value);
            vv[j].erase(it);
        }
        
        value = vv[i][0];
        answer.emplace_back(value);
    }
    
    return answer;
}