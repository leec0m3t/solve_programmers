// https://programmers.co.kr/learn/courses/30/lessons/72412

#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

const int BIT_LANG = 0b1000;
const int BIT_JOB = 0b0100;
const int BIT_EXP = 0b0010;
const int BIT_FOOD = 0b0001;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    unordered_map<string, vector<int>> m;
    
    for (int i = 0; i < (int)info.size(); ++i)
    {
        stringstream ss(info[i]);
        
        string lang, job, exp, food;
        int score;
        
        ss >> lang >> job >> exp >> food >> score;
        
        for (int n = 0; n < 16; ++n)
        {
            string key = "";
            
            key += (n & BIT_LANG) ? lang : "-";
            key += (n & BIT_JOB) ? job : "-";
            key += (n & BIT_EXP) ? exp : "-";
            key += (n & BIT_FOOD) ? food : "-";
            
            m[key].emplace_back(score);
        }
    }
    
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        sort(it->second.begin(), it->second.end());
    }
    
    for (int i = 0; i < (int)query.size(); ++i)
    {
        stringstream ss(query[i]);
        
        string _, __, ___;
        string lang, job, exp, food;
        int score;
        
        int count = 0;
        
        ss >> lang >> _ >> job >> __ >> exp >> ___ >> food >> score;
        
        string key = lang + job + exp + food;
        
        auto it = lower_bound(m[key].begin(), m[key].end(), score);
        count = m[key].size() - distance(m[key].begin(), it);
        
        answer.emplace_back(count);
    }
    
    return answer;
}